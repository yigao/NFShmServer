// -------------------------------------------------------------------------
//    @FileName         :    NFZookeeperNaming.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFZookeeperNaming.cpp
//
// -------------------------------------------------------------------------

#include "NFZookeeperNaming.h"
#include "NFZookeeperClient.h"
#include "NFZookeeperCache.h"
#include "NFNamingHandle.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

extern int32_t IsPathMatched(const std::string& match_name, const std::string& name_expanded);

#define NODE_PATH_LEN 512           // 节点路径长度
#define NODE_DATA_LEN 1024          // 节点数据长度
#define MAX_NAME_LEN 128            // 名字最大长度
#define MAX_VALUE_LEN 1000          // 值信息的最大长度
#define DIGEST_IP_ACL 1         // DIGEST_IP_ACL代表ACL设置既有IP的ALl权限又有digest的Read权限;
#define DIGEST_ACL 2            // DIGEST_ACL代表只设置了digest权限
#define DIGEST_IP_ALL_ACL 3     // DIGEST_IP_ALL_ACL代表ACL设置既有IP的ALl权限又有digest的ALL权限;

static const std::string WildcardName("*");

// 格式化名字字符串，以'/'开头，以非'/'结尾，"//"转为"/"，只有一级认为错误
int32_t FormatName(const std::string& src_name, std::string* dst_name) {
    if (src_name.empty()) {
        return -1;
    }

    std::ostringstream out_stream;
    if (src_name[0] != '/') {
        out_stream << "/";
    }
    out_stream << src_name;

    dst_name->assign(out_stream.str());
    for (size_t p = dst_name->find("//"); p != std::string::npos; p = dst_name->find("//", p)) {
        dst_name->erase(p, 1);
    }

    if ('/' == (*dst_name)[dst_name->size() - 1]) {
        dst_name->erase(dst_name->size() - 1, 1);
    }

    size_t pos = dst_name->find_last_of('/');
    return pos > 1 ? 0 : -1;
}

struct SyncWaitAdaptor
{
    SyncWaitAdaptor() : _rc(999) {}
    virtual ~SyncWaitAdaptor() {}

    int32_t _rc;

    virtual void WaitRsp() { assert(false); }
};

struct BlockWaitAdaptor : public SyncWaitAdaptor
{
    explicit BlockWaitAdaptor(NFZookeeperClient* zk_client)
            : SyncWaitAdaptor(), _zk_client(zk_client), _urls(NULL) {}

    BlockWaitAdaptor(NFZookeeperClient* zk_client, std::vector<std::string>* urls)
            : SyncWaitAdaptor(), _zk_client(zk_client), _urls(urls) {}

    virtual ~BlockWaitAdaptor() {}

    NFZookeeperClient* _zk_client;
    std::vector<std::string>* _urls;

    virtual void WaitRsp()
    {
        while (_rc == 999)
        {
            _zk_client->Update(true);
        }
    }

    void OnCodeRsp(int32_t rc)
    {
        _rc = rc;
    }

    void OnRsp(int32_t rc, const std::vector<std::string>& urls)
    {
        _rc = rc;
        *_urls = urls;
    }
};

struct CoroutineWaitAdaptor : public SyncWaitAdaptor
{
    explicit CoroutineWaitAdaptor()
            : SyncWaitAdaptor(), _cor_id(-1), _urls(NULL) {}

    CoroutineWaitAdaptor(std::vector<std::string>* urls)
            : SyncWaitAdaptor(), _cor_id(-1), _urls(urls) {}

    virtual ~CoroutineWaitAdaptor() {}

    int64_t            _cor_id;
    std::vector<std::string>* _urls;

    virtual void WaitRsp()
    {
        _cor_id = NFCoMgr::Instance()->CurrentTaskId();
        NFCoMgr::Instance()->Yield();
    }

    void OnCodeRsp(int32_t rc)
    {
        _rc = rc;
        NFCoMgr::Instance()->Resume(_cor_id);
    }

    void OnRsp(int32_t rc, const std::vector<std::string>& urls)
    {
        _rc = rc;
        *_urls = urls;
        NFCoMgr::Instance()->Resume(_cor_id);
    }
};


NFZookeeperNaming::NFZookeeperNaming() {
    m_zk_path = "/";
    m_use_cache = true;
    m_zk_client = NF_NEW NFZookeeperClient();
    m_zk_cache = NF_NEW NFZookeeperCache(m_zk_client);
    m_initApp = false;
}

NFZookeeperNaming::~NFZookeeperNaming() {
    Fini();
    NF_SAFE_DELETE(m_zk_client);
    NF_SAFE_DELETE(m_zk_cache);
}

int32_t NFZookeeperNaming::Init(const string &host, int32_t time_out_ms) {
    m_zk_client->Init(host, time_out_ms, m_zk_path);
    int32_t ret = m_zk_client->Connect();
    CHECK_EXPR(ret == proto_ff::ERR_CODE_SVR_OK, -1, "zookeeper connect failed ret:{}", ret);

    m_zk_client->SetWatchCallback(std::bind(&NFZookeeperNaming::WatcherFunc, this, std::placeholders::_1, std::placeholders::_2));
    m_zk_cache->SetWatchFunc(std::bind(&NFZookeeperNaming::OnNodeChanged, this, std::placeholders::_1, std::placeholders::_2));
    return ret;
}

int32_t NFZookeeperNaming::Fini() {
    m_zk_client->Close(true);
    m_zk_cache->Clear();
    m_app_infos.clear();
    m_inst_names_map.clear();
    return 0;
}

int32_t NFZookeeperNaming::SetAppInfo(const string &app_id, const string &app_key) {
    if (app_id.empty() || app_key.empty()) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "param error : {},{}", app_id, app_key);
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string game_id_tmp = NF_FORMAT("{}:{}", app_id, app_key);
    int32_t ret = m_zk_client->AddDigestAuth(game_id_tmp);
    if (proto_ff::ERR_CODE_SVR_OK != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "zoo_add_auth error!ret:{}", ret);
    } else {
        m_app_infos[app_id] = m_zk_client->DigestEncrypt(game_id_tmp);
    }
    return ret;
}

int32_t NFZookeeperNaming::SetCache(bool use_cache, int32_t refresh_time_ms, int32_t invaild_time_ms)
{
    if (refresh_time_ms < 5000 ||
        invaild_time_ms < 10000 ||
        invaild_time_ms <= refresh_time_ms)
    {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    m_use_cache = use_cache;
    m_zk_cache->SetConfig(refresh_time_ms, invaild_time_ms);
    return 0;
}

int32_t NFZookeeperNaming::Register(const string &name, const string &url, int64_t instance_id) {
    std::vector<std::string> urls;
    urls.push_back(url);
    return Register(name, urls, instance_id);
}

int32_t NFZookeeperNaming::Register(const string &name, const vector<std::string> &urls, int64_t instance_id) {
    SyncWaitAdaptor *sync_adaptor = NULL;
    NFNamingCbReturnCode cb;
    if (NFCoMgr::Instance()->CurrentTaskId() >= 0)
    {
        CoroutineWaitAdaptor *coroutine_adaptor = new CoroutineWaitAdaptor();
        cb = std::bind(&CoroutineWaitAdaptor::OnCodeRsp, coroutine_adaptor, std::placeholders::_1);
        sync_adaptor = coroutine_adaptor;
    }
    else
    {
        BlockWaitAdaptor *block_adaptor = new BlockWaitAdaptor(m_zk_client);
        cb = std::bind(&BlockWaitAdaptor::OnCodeRsp, block_adaptor, std::placeholders::_1);
        sync_adaptor = block_adaptor;
    }

    int32_t ret = RegisterAsync(name, urls, cb, instance_id);
    if (0 == ret) {
        sync_adaptor->WaitRsp();
        ret = sync_adaptor->_rc;
    }
    NF_SAFE_DELETE(sync_adaptor);
    return ret;
}

int32_t NFZookeeperNaming::RegisterAsync(const string &name, const string &url, const NFNamingCbReturnCode &cb,
                                         int64_t instance_id) {
    std::vector<std::string> urls;
    urls.push_back(url);
    return RegisterAsync(name, urls, cb, instance_id);
}

int32_t
NFZookeeperNaming::RegisterAsync(const string &name, const vector<std::string> &urls, const NFNamingCbReturnCode &cb,
                                 int64_t instance_id) {
    if (name.empty() || urls.empty() || !cb) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    for (std::vector<std::string>::const_iterator it = urls.begin();
         it != urls.end(); ++it) {
        if ((*it).empty()) {
            return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
        }
    }

    if (std::string::npos != name.find(WildcardName)) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    if (false == m_inst_names_map[real_name].empty()) {
        return proto_ff::ERR_CODE_ZK_NODEEXISTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    CreateInstHandle* op_handle = new CreateInstHandle(m_zk_client, &m_inst_names_map);
    return op_handle->Start(real_name, urls, pwd, cb);
}

int32_t NFZookeeperNaming::UnRegister(const string &name, int64_t instance_id) {
    SyncWaitAdaptor *sync_adaptor = NULL;
    NFNamingCbReturnCode cb = NULL;
    if (NFCoMgr::Instance()->CurrentTaskId() >= 0)
    {
        CoroutineWaitAdaptor *coroutine_adaptor = new CoroutineWaitAdaptor();
        cb = std::bind(&CoroutineWaitAdaptor::OnCodeRsp, coroutine_adaptor, std::placeholders::_1);
        sync_adaptor = coroutine_adaptor;
    }
    else
    {
        BlockWaitAdaptor *block_adaptor = new BlockWaitAdaptor(m_zk_client);
        cb = std::bind(&BlockWaitAdaptor::OnCodeRsp, block_adaptor, std::placeholders::_1);
        sync_adaptor = block_adaptor;
    }
    int32_t ret = UnRegisterAsync(name, cb, instance_id);
    if (0 == ret) {
        sync_adaptor->WaitRsp();
        ret = sync_adaptor->_rc;
    }
    delete sync_adaptor;
    return ret;
}

int32_t NFZookeeperNaming::ForceDelete(const std::string& name, const std::string& url, int64_t instance_id)
{
    SyncWaitAdaptor *sync_adaptor = NULL;
    NFNamingCbReturnCode cb = NULL;
    if (NFCoMgr::Instance()->CurrentTaskId() >= 0)
    {
        CoroutineWaitAdaptor *coroutine_adaptor = new CoroutineWaitAdaptor();
        cb = std::bind(&CoroutineWaitAdaptor::OnCodeRsp, coroutine_adaptor, std::placeholders::_1);
        sync_adaptor = coroutine_adaptor;
    }
    else
    {
        BlockWaitAdaptor *block_adaptor = new BlockWaitAdaptor(m_zk_client);
        cb = std::bind(&BlockWaitAdaptor::OnCodeRsp, block_adaptor, std::placeholders::_1);
        sync_adaptor = block_adaptor;
    }
    int32_t ret = ForceDeleteAsync(name, url, cb, instance_id);
    if (0 == ret) {
        sync_adaptor->WaitRsp();
        ret = sync_adaptor->_rc;
    }
    delete sync_adaptor;
    return ret;
}

int32_t NFZookeeperNaming::ForceDeleteAsync(const std::string& name,
                                 const std::string& url,
                                 const NFNamingCbReturnCode& cb,
                                 int64_t instance_id)
{
    std::vector<std::string> urls;
    urls.push_back(url);
    return ForceDeleteAsync(name, urls, cb, instance_id);
}

int32_t NFZookeeperNaming::ForceDeleteAsync(const std::string& name,
                                 const std::vector<std::string>& urls,
                                 const NFNamingCbReturnCode& cb,
                                 int64_t instance_id)
{
    if (name.empty() || urls.empty() || !cb) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    for (std::vector<std::string>::const_iterator it = urls.begin();
         it != urls.end(); ++it) {
        if ((*it).empty()) {
            return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
        }
    }

    if (std::string::npos != name.find(WildcardName)) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    if (false == m_inst_names_map[real_name].empty()) {
        return proto_ff::ERR_CODE_ZK_NODEEXISTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    DelInstHandle* op_handle = new DelInstHandle(m_zk_client, &m_inst_names_map);
    return op_handle->ForceStart(real_name, urls, cb);
}

int32_t NFZookeeperNaming::UnRegisterAsync(const string &name, const NFNamingCbReturnCode &cb, int64_t instance_id) {
    if (name.empty() || !cb) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    if (std::string::npos != name.find(WildcardName)) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    DelInstHandle* op_handle = new DelInstHandle(m_zk_client, &m_inst_names_map);
    return op_handle->Start(real_name, cb);
}

int32_t NFZookeeperNaming::GetUrlsByName(const string &name, std::vector<std::string> *urls) {
    if (name.empty() || !urls) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    if (true == m_use_cache && 0 == m_zk_cache->Get(real_name, urls)) {
        return 0;
    }

    SyncWaitAdaptor *sync_adaptor = NULL;
    NFNamingCbReturnValue ret_cob = NULL;
    if (NFCoMgr::Instance()->CurrentTaskId() >= 0) {
        CoroutineWaitAdaptor *coroutine_adaptor = new CoroutineWaitAdaptor(urls);
        ret_cob = std::bind(&CoroutineWaitAdaptor::OnRsp, coroutine_adaptor, std::placeholders::_1, std::placeholders::_2);
        sync_adaptor = coroutine_adaptor;
    } else {
        BlockWaitAdaptor *block_adaptor = new BlockWaitAdaptor(m_zk_client, urls);
        ret_cob = std::bind(&BlockWaitAdaptor::OnRsp, block_adaptor, std::placeholders::_1, std::placeholders::_2);
        sync_adaptor = block_adaptor;
    }
    int32_t ret = GetAsyncRaw(real_name, ret_cob);
    if (0 == ret) {
        sync_adaptor->WaitRsp();
        ret = sync_adaptor->_rc;
    }

    delete sync_adaptor;
    return ret;
}

int32_t NFZookeeperNaming::GetUrlsByNameAsync(const string &name, const NFNamingCbReturnValue &cb) {
    if (name.empty() || !cb) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    std::vector<std::string> urls;
    if (true == m_use_cache && cb != NULL
        && 0 == m_zk_cache->Get(real_name, &urls)) {
        cb(0, urls);
        return 0;
    }
    return GetAsyncRaw(real_name, cb);
}

int32_t NFZookeeperNaming::WatchName(const string &name, const NFNamingWatchFunc &wc) {
    SyncWaitAdaptor *sync_adaptor = NULL;
    NFNamingCbReturnCode ret_cob = NULL;
    if (NFCoMgr::Instance()->CurrentTaskId() >= 0) {
        CoroutineWaitAdaptor *coroutine_adaptor = new CoroutineWaitAdaptor();
        ret_cob = std::bind(&CoroutineWaitAdaptor::OnCodeRsp, coroutine_adaptor, std::placeholders::_1);
        sync_adaptor = coroutine_adaptor;
    } else {
        BlockWaitAdaptor *block_adaptor = new BlockWaitAdaptor(m_zk_client);
        ret_cob = std::bind(&BlockWaitAdaptor::OnCodeRsp, block_adaptor, std::placeholders::_1);
        sync_adaptor = block_adaptor;
    }
    int32_t ret = WatchNameAsync(name, wc, ret_cob);
    if (0 == ret) {
        sync_adaptor->WaitRsp();
        ret = sync_adaptor->_rc;
    }

    delete sync_adaptor;
    return ret;
}

int32_t
NFZookeeperNaming::WatchNameAsync(const string &name, const NFNamingWatchFunc &wc, const NFNamingCbReturnCode &cb) {
    if (name.empty() || !cb) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string real_name;
    if (FormatName(name, &real_name) != 0) {
        return proto_ff::ERR_CODE_ZK_BADARGUMENTS;
    }

    std::string pwd;
    if (GetDigestPassword(real_name, &pwd) < 0) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    NFNamingCbReturnCode on_watch_return = std::bind(&NFZookeeperNaming::OnWatchNameReturn, this,
                                            std::placeholders::_1, real_name, wc, cb);

    CbGetAllReturn get_cb = std::bind(&NFZookeeperCache::OnWatchCb,
                                      m_zk_cache, real_name, std::placeholders::_1, std::placeholders::_2, on_watch_return);
    GetExpandedValueHandle* op_handle = new GetExpandedValueHandle(m_zk_client);
    return op_handle->Start(real_name, get_cb, true);
}

int32_t NFZookeeperNaming::Update() {
    int32_t num = 0;
    if (NULL != m_zk_client) {
        num += m_zk_client->Update(false);
        m_zk_cache->Update();
    }
    return num;
}

/*
    1. ZOO_CHILD_EVENT: 下面路径孩子节点发生变化(变多、变少)
    /path               service_name增减
    /path/name  service_name实例节点变化

    2. ZOO_DELETED_EVENT/ZOO_CHANGED_EVENT: 下面路径节点发生变化(修改、删除)
    /path/name 路由策略信息变化 或 节点删除
*/
void NFZookeeperNaming::WatcherFunc(int32_t type, const char *path) {
    if (!path) {
        return;
    }

//    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ZookeeperNaming Watcher : path[{}] type[{}]", path, type);

    if (ZOO_DELETED_EVENT != type && ZOO_CHANGED_EVENT != type && ZOO_CHILD_EVENT != type) {
        return;
    }

    std::string change_path(path);
    size_t split_pos = change_path.find_last_of('/');
    if (split_pos == std::string::npos || split_pos == change_path.size()) {
        return;
    }

    // /path service_name增减
    if (ZOO_CHILD_EVENT == type && false == m_zk_cache->IsFullPath(change_path)) {
        change_path.append("/");
        change_path.append(WildcardName);
        GetAsyncRaw(change_path, NULL);
    } else { // /path/name 节点变化
        if (ZOO_DELETED_EVENT == type) {
            m_zk_cache->OnDelete(change_path);
        } else {
            GetAsyncRaw(change_path, NULL);
        }
    }
}

int32_t NFZookeeperNaming::GetAsyncRaw(const string &name, const NFNamingCbReturnValue &cb) {
    GetExpandedValueHandle* op_handle = new GetExpandedValueHandle(m_zk_client);
    if (false == m_use_cache && cb != NULL) {
        CbGetAllReturn get_cb = std::bind(&NFZookeeperCache::OnGetCb,
                                          m_zk_cache, std::placeholders::_1, std::placeholders::_2, cb);
        return op_handle->Start(name, get_cb, false);
    }
    CbGetAllReturn get_cb = std::bind(&NFZookeeperCache::OnUpdateCb,
                                      m_zk_cache, name, false, std::placeholders::_1, std::placeholders::_2, cb);
    return op_handle->Start(name, get_cb, true);
}

int32_t NFZookeeperNaming::GetDigestPassword(const string &name, std::string *pwd) {
    size_t app_pos = name.find_first_of('/', 1);
    if (app_pos < 1) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }
    std::string appid = name.substr(1, app_pos - 1);
    std::map<std::string, std::string>::iterator it = m_app_infos.find(appid);
    if (it == m_app_infos.end()) {
        return proto_ff::ERR_CODE_ZK_NOT_SET_APPKEY;
    }

    pwd->assign(it->second);
    return 0;
}

void NFZookeeperNaming::OnNodeChanged(const string &name, const vector<std::string> &urls) {
//    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ZookeeperNaming OnNodeChanged : name[{}] urls.size[{}]", name.c_str(), urls.size());
    std::map<std::string, std::vector<NFNamingWatchFunc> >::iterator it = m_watch_callbacks.find(name);
    if (it != m_watch_callbacks.end()) {
        for (std::vector<NFNamingWatchFunc>::iterator fit = it->second.begin();
             fit != it->second.end(); ++fit) {
            (*fit)(name, urls);
        }
    }

    // 对通配部分进行匹配处理
    int32_t match = 0;
    for (std::map<std::string, std::vector<NFNamingWatchFunc> >::iterator wit = m_watch_wildcard_callbacks.begin();
         wit != m_watch_wildcard_callbacks.end(); ++wit) {
        match = IsPathMatched(wit->first, name);
        if (match == 0) {
            for (std::vector<NFNamingWatchFunc>::iterator fit = wit->second.begin();
                 fit != wit->second.end(); ++fit) {
                (*fit)(name, urls);
            }
        } else if (match < 0) {
            continue;
        }
    }
}

void NFZookeeperNaming::OnWatchNameReturn(int rc, const string &name, const NFNamingWatchFunc &wc,
                                          const NFNamingCbReturnCode &cb) {
        // watch 成功才记录
        if (rc == 0) {
            if (std::string::npos != name.find(WildcardName)) {
                m_watch_wildcard_callbacks[name].push_back(wc);
            } else {
                m_watch_callbacks[name].push_back(wc);
            }
        }

        cb(rc);
}
// -------------------------------------------------------------------------
//    @FileName         :    NFNamingHandle.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFNamingHandle.cpp
//
// -------------------------------------------------------------------------

#include "NFNamingHandle.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#define NODE_PATH_LEN 512           // 节点路径长度
#define NODE_DATA_LEN 1024          // 节点数据长度
#define MAX_NAME_LEN  128           // 名字最大长度
#define MAX_VALUE_LEN 1000          // 名字值的最大长度

static const char digest_scheme[8] = "digest";



#define INIT_ACLV(aclv, digestpwd) \
    struct ACL __acl;\
    __acl.perms = ZOO_PERM_ALL;\
    __acl.id.scheme = const_cast<char*>(digest_scheme);\
    __acl.id.id = digestpwd;\
    aclv.count = 1;\
    aclv.data = &__acl

int32_t NamingHandle::ValueVec2String(const std::vector<std::string>& urls, std::string* out_str)
{
    std::ostringstream o;
    for (std::vector<std::string>::const_iterator it = urls.begin() ; it != urls.end() ; ++it) {
        if (it != urls.begin()) {
            o << ",";
        }
        o << *it;
    }
    out_str->assign(o.str());
    return 0;
}

int32_t NamingHandle::String2ValueVec(const std::string& in_str, std::vector<std::string>* urls)
{
    NFStringUtility::Split(in_str, ",", urls);
    return 0;
}

int32_t NamingHandle::MakeInstNodeNameAndVal(const std::vector<std::string>& urls,
                                             std::string* inst_name,
                                             std::string* inst_val)
{
    ValueVec2String(urls, inst_val);
    std::string encode_val;
    NFStringUtility::UrlEncode(*inst_val, &encode_val);
    inst_name->append(encode_val);
    return 0;
}


CreateInstHandle::CreateInstHandle(NFZookeeperClient* zk_client, CreatedInstsNameMap* insts)
        :   NamingHandle(zk_client, insts)
{
}

int32_t CreateInstHandle::Start(const std::string& name,
                                const std::vector<std::string>& urls,
                                const std::string& digestpwd,
                                NFNamingCbReturnCode cb)
{
    MakeInstNodeNameAndVal(urls, &m_inst_name, &m_inst_value);
    if (name.size() > NODE_PATH_LEN ||
        m_inst_name.empty() ||
        m_inst_value.empty() ||
        m_inst_value.size() > MAX_VALUE_LEN)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "invaild param");
        return Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
    }

    m_name = name;
    m_inst_node = m_name + "/" + m_inst_name;
    m_digestpwd = digestpwd;
    m_return_callback = cb;

    CheckNamingNode();
    return 0;
}

int32_t CreateInstHandle::Exit(int32_t rc)
{
    if (m_return_callback != NULL) {
        m_return_callback(rc);
    }
    delete this;
    return rc;
}

void CreateInstHandle::CheckNamingNode()
{
    ZkDataCompletionCb cb = std::bind(&CreateInstHandle::CbCheckNamingNode, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
    int32_t ret = m_zk_client->AGet(m_name.c_str(), 0, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] aget failed ret[{}]", m_name.c_str(), ret);
        Exit(ret);
    }
}

void CreateInstHandle::CbCheckNamingNode(int rc, const char *value, int value_len,
                                         const Stat *stat)
{
    switch (rc) {
        case 0:
            // naming_node 存在
            CreateInstNode();
            break;
        case proto_ff::ERR_CODE_ZK_NONODE:
            // naming_node 不存在
        {
            static const std::string kGaiaEnvName("GAIA_CONTAINER_ID");
            uint64_t offset = m_name.find_first_of('/', 1);
            if (std::string::npos == offset) {
                Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
            } else if (NULL != getenv(kGaiaEnvName.c_str())) {
                // gaia环境，不创建第一层path
                CreateNamingNode(offset + 1);
            } else {
                // 非gaia环境，从第一层path开始尝试创建
                CreateNamingNode(1);
            }
        }
            break;
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "naming_node[{}] check failed ret[{}]", m_name.c_str(), rc);
            Exit(rc);
            break;
    }
}

void CreateInstHandle::CreateNamingNode(uint64_t offset)
{
    uint64_t next_offset = m_name.find_first_of('/', offset);
    std::string node_name = m_name.substr(0, next_offset);

    struct ACL_vector aclv;
    INIT_ACLV(aclv, const_cast<char*>(m_digestpwd.c_str()));
    ZkStringCompletionCb cb = std::bind(&CreateInstHandle::CbCreateNamingNode,
                                        this, next_offset, std::placeholders::_1, std::placeholders::_2);
    int32_t ret = m_zk_client->ACreate(node_name.c_str(), "", 0, &aclv, 0, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] acreate failed ret[{}]", node_name.c_str(), ret);
        Exit(ret);
    }
}

void CreateInstHandle::CbCreateNamingNode(uint64_t offset, int rc, const char *value)
{
    switch (rc) {
        case 0:
        case proto_ff::ERR_CODE_ZK_NOAUTH:
            // 考虑兼容性，旧版本对中间路径没有权限，将没有权限也当做成功继续处理，直到其它失败
        case proto_ff::ERR_CODE_ZK_NODEEXISTS:
            // 创建成功或已存在
            if (std::string::npos == offset) {
                // 创建service_inst节点
                CreateInstNode();
            } else {
                // 继续尝试创建下一级
                CreateNamingNode(offset + 1);
            }
            break;
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] create failed ret[{}] offset[{}]", m_name.c_str(), rc, offset);
            Exit(rc);
            break;
    }
}

void CreateInstHandle::CreateInstNode()
{
    struct ACL_vector aclv;
    INIT_ACLV(aclv, const_cast<char*>(m_digestpwd.c_str()));
    ZkStringCompletionCb cb = std::bind(&CreateInstHandle::CbCreateInstNode, this, std::placeholders::_1, std::placeholders::_2);
    int32_t ret = m_zk_client->ACreate(m_inst_node.c_str(), "", 0, &aclv, ZOO_EPHEMERAL, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] acreate failed ret[{}]", m_inst_node.c_str(), ret);
        Exit(ret);
    }
}

void CreateInstHandle::CbCreateInstNode(int rc, const char *value)
{
    if (0 != rc) {
        //NFLogError(NF_LOG_SYSTEMLOG, 0, "create service_inst_node[{}] failed ret[{}]", m_inst_node.c_str(), rc);
        Exit(rc);
    } else {
        // 检查通过，返回成功
        (*m_insts_map)[m_name] = m_inst_name;
        Exit(0);
    }
}

DelInstHandle::DelInstHandle(NFZookeeperClient* zk_client, CreatedInstsNameMap* insts)
        :   NamingHandle(zk_client, insts)
{
}

int32_t DelInstHandle::Start(const std::string& name,
                             NFNamingCbReturnCode cb)
{
    CreatedInstsNameMap::iterator path_it = m_insts_map->find(name);
    if (path_it == m_insts_map->end()) {
        return Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
    }

    m_name = name;
    m_inst_node_name = m_name + "/" + path_it->second;
    m_cb = cb;
    return DeleteInstNode();
}

int32_t DelInstHandle::ForceStart(const std::string& name, const std::vector<std::string>& urls,
                   NFNamingCbReturnCode cb)
{
    MakeInstNodeNameAndVal(urls, &m_inst_name, &m_inst_value);
    if (name.size() > NODE_PATH_LEN ||
        m_inst_name.empty() ||
        m_inst_value.empty() ||
        m_inst_value.size() > MAX_VALUE_LEN)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "invaild param");
        return Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
    }

    m_name = name;
    m_inst_node_name = m_name + "/" + m_inst_name;
    m_cb = cb;
    return ForceDeleteInstNode();
}

int32_t DelInstHandle::Exit(int32_t rc)
{
    if (NULL != m_cb) {
        m_cb(rc);
    }
    delete this;
    return rc;
}

int32_t DelInstHandle::DeleteInstNode()
{
    ZkVoidCompletionCb cb = std::bind(&DelInstHandle::CbDeleteInstNode,
                                      this, std::placeholders::_1);
    int32_t ret = m_zk_client->ADelete(m_inst_node_name.c_str(), -1, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "adelete node[{}] failed in {}", m_inst_node_name.c_str(), ret);
        return Exit(ret);
    }
    return 0;
}

int32_t DelInstHandle::ForceDeleteInstNode()
{
    ZkVoidCompletionCb cb = std::bind(&DelInstHandle::CbForceDeleteInstNode,
                                      this, std::placeholders::_1);
    int32_t ret = m_zk_client->ADelete(m_inst_node_name.c_str(), -1, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "adelete node[{}] failed in {}", m_inst_node_name.c_str(), ret);
        return Exit(ret);
    }
    return 0;
}

void DelInstHandle::CbDeleteInstNode(int rc)
{
    // 删除成功，尝试递归删除空了的节点
    if (0 == rc) {
        m_insts_map->erase(m_name);
        // 在程序中主动删除父节点会导致其父节点的监控信息丢失，节点再次创建时监控者将感知不到
        // 建议垃圾节点的判断与清理通过运维手段搞定
        // DeleteNamingNode(std::string::npos);
        Exit(0);
        return;
    }
    // 删除失败则直接返回
    NFLogError(NF_LOG_SYSTEMLOG, 0, "del service_inst_node[{}] failed in {}",
               m_inst_node_name.c_str(), rc);
    Exit(rc);
}

void DelInstHandle::CbForceDeleteInstNode(int rc)
{
    // 删除成功，尝试递归删除空了的节点
    if (0 == rc) {
        m_insts_map->erase(m_name);
        // 在程序中主动删除父节点会导致其父节点的监控信息丢失，节点再次创建时监控者将感知不到
        // 建议垃圾节点的判断与清理通过运维手段搞定
        //DeleteNamingNode(std::string::npos);
        Exit(0);
        return;
    }
    // 删除失败则直接返回
    NFLogError(NF_LOG_SYSTEMLOG, 0, "del service_inst_node[{}] failed in {}",
               m_inst_node_name.c_str(), rc);
    Exit(rc);
}

void DelInstHandle::DeleteNamingNode(uint64_t offset)
{
    if (std::string::npos != offset) {
        m_name[(offset--)] = 0;
    }
    uint64_t next_offset = m_name.find_last_of('/', offset);
    if (std::string::npos == next_offset || 0 == next_offset) {
        Exit(0);
        return;
    }

    ZkVoidCompletionCb cb = std::bind(&DelInstHandle::CbDeleteNamingNode, this, next_offset, std::placeholders::_1);
    int32_t ret = m_zk_client->ADelete(m_name.c_str(), -1, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "adelete node[{}] failed in {}", m_name.c_str(), ret);
        Exit(0);
    }
}

void DelInstHandle::CbDeleteNamingNode(uint64_t offset, int rc)
{
    if (0 == rc) {
        DeleteNamingNode(offset);
    } else {
        Exit(0);
    }
}

GetValueHandle::GetValueHandle(NFZookeeperClient* zk_client)
        :   NamingHandle(zk_client), m_has_cb(true), m_is_watch(0), m_wait_num(0)
{
}

int32_t GetValueHandle::Start(const std::string& name,
                              CbGetReturn cb, bool is_watch)
{
    m_get_name_result.first = name;
    m_return_callback = cb;
    m_is_watch = (is_watch ? 1 : 0);

    GetInst();
    m_has_cb = false;
    return 0;
}

int32_t GetValueHandle::Exit(int32_t rc)
{
    // children下每个都可以失败触发，保证只回调一次
    if (false == m_has_cb) {
        m_has_cb = true;
        m_return_callback(rc, m_get_name_result);
    }
    if (0 == m_wait_num) {
        delete this;
    }
    return rc;
}

void GetValueHandle::GetInst()
{
    ZkStringsCompletionCb cb = std::bind(&GetValueHandle::CbGetInst, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    int32_t ret = m_zk_client->AGetChildren(m_get_name_result.first.c_str(), m_is_watch, cb);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] aget_children failed ret[{}]", m_get_name_result.first.c_str(), ret);
        Exit(ret);
    }
}

void GetValueHandle::CbGetInst(int rc, const String_vector *strings, const Stat *stat)
{
    if (0 != rc) {
        //NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] get children failed ret[{}]", m_get_name_result.first.c_str(), rc);
        Exit(rc);
        return;
    }

    m_get_name_result.second._version = (static_cast<int64_t>(stat->cversion) << 32);
    m_get_name_result.second._version += stat->version;

    if (0 == strings->count) {
//        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "path[{}] get children empty", m_get_name_result.first.c_str());
        Exit(0);
        return;
    }
    for (int32_t idx = 0; idx < strings->count; ++idx) {
        // 直接从名字取内容
        std::string val_str(strings->data[idx]);
        std::string addr_str;
        NFStringUtility::UrlDecode(val_str, &addr_str);
        String2ValueVec(addr_str, &m_get_name_result.second._urls);
    }
    // 全部都直接从节点名上取得了数据
    // 返回去重地址信息
    std::vector<std::string>& unique_addr = m_get_name_result.second._urls;
    std::sort(unique_addr.begin(), unique_addr.end());
    std::vector<std::string>::iterator end_unique =
            std::unique(unique_addr.begin(), unique_addr.end());
    unique_addr.erase(end_unique, unique_addr.end());

    Exit(0);
}

GetExpandedValueHandle::GetExpandedValueHandle(NFZookeeperClient* zk_client)
        :   NamingHandle(zk_client), m_has_cb(true), m_is_watch(0), m_wait_num(0)
{
}

int32_t GetExpandedValueHandle::Start(const std::string& name,
                                      CbGetAllReturn cb, bool is_watch)
{
    m_path_remain = name;
    m_is_watch = (is_watch ? 1 : 0);
    m_return_callback = cb;

    int32_t ret = SplitPathWildcard();
    if (ret < 0) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "naming_node[%s] invaild param", name.c_str());
        return Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
    }
    if (0 == ret) {
        ExpandedPath();
    } else {
        GetNamingValue(name);
    }
    if (0 == m_wait_num) {
        return Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
    }
    // 只有成功的有请求了才能有回调
    m_has_cb = false;
    return 0;
}

int32_t GetExpandedValueHandle::Exit(int32_t rc)
{
    if (false == m_has_cb) {
        m_has_cb = true;
        m_return_callback(rc, m_get_all_name_result);
    }
    if (0 == m_wait_num) {
        delete this;
    }
    return rc;
}

void GetExpandedValueHandle::ExpandedPath()
{
    int32_t ret = 0, is_watch = (m_path_remain.empty() ? 1 : 0);
    std::list<std::string>::iterator it = m_all_paths.begin();
    for ( ; it != m_all_paths.end() ; ++it) {
        ZkStringsCompletionCb cb = std::bind(&GetExpandedValueHandle::CbExpandedPath,
                                             this, *it, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        ret = m_zk_client->AGetChildren(it->c_str(), is_watch, cb);
        if (0 != ret) {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] aget_children failed ret[{}]", it->c_str(), ret);
            break;
        } else {
            m_wait_num++;
        }
    }
    m_all_paths.clear();
}

void GetExpandedValueHandle::CbExpandedPath(std::string name, int rc,
                                            const String_vector *strings, const Stat *stat)
{
    if (0 != rc) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "path[{}] get children failed ret[{}]", name.c_str(), rc);
        if (proto_ff::ERR_CODE_ZK_NONODE != rc) {
            Exit(rc);
        }
    } else {
        for (int32_t idx = 0 ; idx < strings->count ; ++idx) {
            // 检查长度
            uint64_t len = strlen(strings->data[idx]);
            if (len + 1 < m_path_prefix.size() + m_path_subfix.size()
                || 0 == m_path_prefix.size()) {
                continue;
            }
            // 比较前缀和后缀
            uint64_t pre_len = m_path_prefix.size() - 1;
            uint64_t sub_off = len - m_path_subfix.size();
            if (strncmp(strings->data[idx] + sub_off, m_path_subfix.c_str(), m_path_subfix.size())
                || 0 != strncmp(strings->data[idx], m_path_prefix.c_str() + 1, pre_len)) {
                continue;
            }
            m_all_paths.push_back(name);
            m_all_paths.back().append(1, '/');
            m_all_paths.back().append(strings->data[idx]);
        }
    }
    m_wait_num--;
    if (0 == m_wait_num) {
        // 已返回错误
        if (true == m_has_cb) {
            Exit(0);
            return;
        }
        // 已经找不到任何匹配的路径了
        if (0 == m_all_paths.size()) {
            Exit(0);
            return;
        }
        // 继续执行通配符的分解
        int32_t ret = SplitPathWildcard();
        if (ret < 0) {
            Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
        } else if (0 == ret) {
            ExpandedPath();
        } else {
            std::list<std::string>::iterator it = m_all_paths.begin();
            for ( ; it != m_all_paths.end() ; ++it) {
                GetNamingValue(*it);
            }
        }
        if (0 == m_wait_num) {
            Exit(proto_ff::ERR_CODE_ZK_BADARGUMENTS);
        }
    }
}

void GetExpandedValueHandle::GetNamingValue(const std::string& name)
{
    GetValueHandle* handle = new GetValueHandle(m_zk_client);
    CbGetReturn cb = std::bind(&GetExpandedValueHandle::CbGetNamingValue,
                               this, std::placeholders::_1, std::placeholders::_2);
    int32_t ret = handle->Start(name, cb, m_is_watch);
    if (0 != ret) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "get naming_node[{}] failed ret[{}]", name.c_str(), ret);
    } else {
        m_wait_num++;
    }
}

void GetExpandedValueHandle::CbGetNamingValue(int rc, GetNameResult& get_name_return) // NOLINT
{
    --m_wait_num;
    if (0 == rc) {
        m_get_all_name_result.insert(get_name_return);
    } else if (proto_ff::ERR_CODE_ZK_NONODE == rc) {
        rc = 0;
    } else {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "naming_node[{}] get values ret[{}]", get_name_return.first.c_str(), rc);
    }

    // get_children获取到，但实际查询为不存在，则跳过
    if (0 == m_wait_num || (0 != rc && proto_ff::ERR_CODE_ZK_NONODE != rc)) {
        Exit(rc);
    }
}

int32_t GetExpandedValueHandle::SplitPathWildcard()
{
    uint64_t wpos = m_path_remain.find_first_of('*');
    if (std::string::npos == wpos) {
        std::list<std::string>::iterator it = m_all_paths.begin();
        for ( ; it != m_all_paths.end() ; ++it) {
            it->append(m_path_remain);
        }
        return 1;
    }
    uint64_t pre_pos = m_path_remain.find_last_of('/', wpos);
    if (std::string::npos == pre_pos) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "splict str[{}] unexpect error", m_path_remain.c_str());
        return -1;
    }
    uint64_t sub_pos = m_path_remain.find_first_of('/', wpos);

    // 有*跳过的部分，则append到所有已展开的path上
    std::string append_str = m_path_remain.substr(0, pre_pos);
    if (0 != pre_pos) {
        std::list<std::string>::iterator it = m_all_paths.begin();
        for ( ; it != m_all_paths.end() ; ++it) {
            it->append(append_str);
        }
    }
    if (0 == m_all_paths.size()) {
        m_all_paths.push_back(append_str);
    }
    m_path_prefix = m_path_remain.substr(pre_pos, wpos - pre_pos);
    if (std::string::npos == sub_pos) {
        m_path_subfix = m_path_remain.substr(wpos + 1, sub_pos);
    } else {
        m_path_subfix = m_path_remain.substr(wpos + 1, sub_pos - wpos - 1);
    }
    if (std::string::npos != m_path_subfix.find_first_of('*')) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "dir fragment[{}] has more then one '*'", m_path_remain.c_str());
        return -1;
    }
    m_path_remain = m_path_remain.erase(0, sub_pos);
    return 0;
}
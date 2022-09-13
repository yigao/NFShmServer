// -------------------------------------------------------------------------
//    @FileName         :    NFCNamingModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCNamingModule.cpp
//
// -------------------------------------------------------------------------

#include "NFCNamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFBusppNaming.h"
#include "NFZookeeperNaming.h"

NFCNamingModule::NFCNamingModule(NFIPluginManager *p) : NFINamingModule(p)
{
    m_namingList.resize(NF_ST_MAX);
    for(int i = 0; i < (int)m_namingList.size(); i++)
    {
        m_namingList[i] = NULL;
    }
}

NFCNamingModule::~NFCNamingModule()
{

}

bool NFCNamingModule::BeforeShut()
{
    return NFIModule::BeforeShut();
}

bool NFCNamingModule::Shut()
{
    for(int i = 0; i < (int)m_namingList.size(); i++)
    {
        if (m_namingList[i])
        {
            NF_SAFE_DELETE(m_namingList[i]);
        }
    }
    return true;
}

bool NFCNamingModule::Execute()
{
    for(int i = 0; i < (int)m_namingList.size(); i++)
    {
        if (m_namingList[i])
        {
            m_namingList[i]->Update();
        }
    }
    return true;
}

bool NFCNamingModule::OnReloadPlugin()
{
    return NFIModule::OnReloadPlugin();
}

proto_ff::ServerInfoReport NFCNamingModule::GetDefaultMasterInfo(NF_SERVER_TYPES eServerType)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    if (pConfig)
    {
        proto_ff::ServerInfoReport xData;
        xData.set_server_type(NF_ST_MASTER_SERVER);
        xData.set_bus_id(NFServerIDUtil::GetBusID("1.1.1.1"));
        xData.set_bus_name("1.1.1.1");
        xData.set_server_name("MasterServer_1.1.1.1");
        xData.set_link_mode("tcp");
        std::string url = NF_FORMAT("tcp://{}:{}", pConfig->mMasterIp, pConfig->mMasterPort);
        xData.set_url(url);
        xData.set_server_ip(pConfig->mMasterIp);
        xData.set_server_port(pConfig->mMasterPort);
        return xData;
    }
    else {
        proto_ff::ServerInfoReport xData;
        xData.set_server_type(NF_ST_MASTER_SERVER);
        xData.set_bus_id(NFServerIDUtil::GetBusID("1.1.1.1"));
        xData.set_bus_name("1.1.1.1");
        xData.set_server_name("MasterServer_1.1.1.1");
        xData.set_link_mode("tcp");
        xData.set_url("tcp://127.0.0.1:6011");
        xData.set_server_ip("127.0.0.1");
        xData.set_server_port(6011);
        return xData;
    }
}

int32_t NFCNamingModule::InitAppInfo(NF_SERVER_TYPES eServerType, int time_out_ms)
{
    int32_t ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    if (m_pPluginManager->IsLoadAllServer())
    {
        ret = Init(eServerType, pConfig->mNamingHost, time_out_ms * 2);
        CHECK_RET(ret, "Init Failed, serverType:{} namingHost:{}", eServerType, pConfig->mNamingHost);
    }
    else
    {
        ret = Init(eServerType, pConfig->mNamingHost, time_out_ms);
        CHECK_RET(ret, "Init Failed, serverType:{} namingHost:{}", eServerType, pConfig->mNamingHost);
    }

    ret = SetAppInfo(eServerType, pConfig->mNamingPath, pConfig->mNamingPath);
    CHECK_RET(ret, "SetAppInfo Failed, eServerType:{} busId:{} name:{}", pConfig->mNamingPath, pConfig->mNamingPath);

    return 0;
}

bool NFCNamingModule::IsInitApp(NF_SERVER_TYPES eServerType)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), false, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], false, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->IsInitApp();
}

void NFCNamingModule::FinishInitApp(NF_SERVER_TYPES eServerType)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), , "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], , "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->FinishInitApp();
}

int32_t NFCNamingModule::RegisterAppInfo(NF_SERVER_TYPES eServerType)
{
    if (IsInitApp(eServerType))
    {
        return 0;
    }

    int32_t ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string busPath = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/busUrl/"+NFCommon::tostr(pConfig->mBusId);
    std::string busUrl = NF_FORMAT("bus://{}:{}", pConfig->mBusName, pConfig->mBusLength);
    std::string tcpPath = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/tcpUrl/"+NFCommon::tostr(pConfig->mBusId);
    std::string tcpUrl = NF_FORMAT("tcp://{}:{}", pConfig->mServerIp, pConfig->mServerPort);
    std::string routeAgentPath = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/routeAgent/"+NFCommon::tostr(pConfig->mBusId);
    std::string routeAgent = pConfig->mRouteAgent;
    std::string externServerIpPath = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/externalServerIp/"+NFCommon::tostr(pConfig->mBusId);
    std::string externServerIp = pConfig->mExternalServerIp;
    std::string externServerPortPath = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/externalServerPort/"+NFCommon::tostr(pConfig->mBusId);
    std::string externServerPort = "";
    if (pConfig->mExternalServerPort > 0)
    {
        externServerPort = NFCommon::tostr(pConfig->mExternalServerPort);
    }

    int count = 0;
    bool flag = false;
    while(count++ <= 10) {
        ret = Register(eServerType, busPath, busUrl);
        if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS) {
            ret = ForceDelete(eServerType, busPath, busUrl);
            CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} name:{} busurl:{}", ret,
                                eServerType, busPath, busUrl);
            ret = Register(eServerType, busPath, busUrl);
        }
        CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} name:{} busurl:{}", eServerType, busPath,
                            busUrl);
        flag = true;
        break;
    }

    NF_ASSERT(flag);
    CHECK_EXPR(flag, -1, "Register busurl Failed");

    count = 0;
    flag = false;
    while(count++ <= 10) {
        ret = Register(eServerType, tcpPath, tcpUrl);
        if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS)
        {
            ret = ForceDelete(eServerType, tcpPath, tcpUrl);
            CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} name:{} tcpurl:{}", ret, eServerType, tcpPath, tcpUrl);
            ret = Register(eServerType, tcpPath, tcpUrl);
        }
        CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} name:{} tcpurl:{}", eServerType, tcpPath, tcpUrl);
        flag = true;
        break;
    }

    NF_ASSERT(flag);
    CHECK_EXPR(flag, -1, "Register tcpurl Failed");

    if (!routeAgent.empty()) {
        count = 0;
        flag = false;
        while(count++ <= 10) {
            ret = Register(eServerType, routeAgentPath, routeAgent);
            if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS)
            {
                ret = ForceDelete(eServerType, routeAgentPath, routeAgent);
                CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} routeAgent:{} routeAgent:{}", ret, eServerType, routeAgentPath, routeAgent);
                ret = Register(eServerType, routeAgentPath, routeAgent);
            }
            CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} routeAgent:{} routeAgent:{}", eServerType, routeAgentPath, routeAgent);
            flag = true;
            break;
        }

        NF_ASSERT(flag);
        CHECK_EXPR(flag, -1, "Register routeAgent Failed");
    }

    if (!externServerIp.empty())
    {
        count = 0;
        flag = false;
        while(count++ <= 10) {
            ret = Register(eServerType, externServerIpPath, externServerIp);
            if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS)
            {
                ret = ForceDelete(eServerType, externServerIpPath, externServerIp);
                CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} externServerIpPath:{} externServerIp:{}", ret, eServerType, externServerIpPath, externServerIp);
                ret = Register(eServerType, externServerIpPath, externServerIp);
            }
            CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} externServerIpPath:{} externServerIp:{}", eServerType, externServerIpPath, externServerIp);
            flag = true;
            break;
        }

        NF_ASSERT(flag);
        CHECK_EXPR(flag, -1, "Register externServerIp Failed");
    }

    if (!externServerPort.empty())
    {
        count = 0;
        flag = false;
        while(count++ <= 10) {
            ret = Register(eServerType, externServerPortPath, externServerPort);
            if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS)
            {
                ret = ForceDelete(eServerType, externServerPortPath, externServerPort);
                CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} externServerPortPath:{} externServerPort:{}", ret, eServerType, externServerPortPath, externServerPort);
                ret = Register(eServerType, externServerPortPath, externServerPort);
            }
            CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} externServerPortPath:{} externServerPort:{}", eServerType, externServerPortPath, externServerPort);
            flag = true;
            break;
        }

        NF_ASSERT(flag);
        CHECK_EXPR(flag, -1, "Register externServerPort Failed");
    }

    FinishInitApp(eServerType);

    return 0;
}

int32_t NFCNamingModule::ClearDBInfo(NF_SERVER_TYPES eServerType)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::vector<std::string> vec;
    GetDBInfoByName(eServerType, vec);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        int count = 0;
        while(count++ <= 10)
        {
            std::string path = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/DBNames/" +NFCommon::tostr(pConfig->mBusId) + "/" + vec[i];
            int ret = ForceDelete(eServerType, path, vec[i]);
            if (ret == 0 || ret == proto_ff::ERR_CODE_ZK_NONODE)
                break;
        }
    }

    return 0;
}

int32_t NFCNamingModule::GetDBInfoByName(NF_SERVER_TYPES eServerType, std::vector<std::string>& tcpUrlVec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string path = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/DBNames/" +NFCommon::tostr(pConfig->mBusId);

    ret = GetUrlsByName(eServerType, path, &tcpUrlVec);
    CHECK_RET(ret, "GetUrlsByName Failed! eServerType:{} name:{}", eServerType, path);

    return 0;
}

int32_t NFCNamingModule::RegisterDBInfo(NF_SERVER_TYPES eServerType, const std::string& content)
{
    int32_t ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string path = pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/DBNames/" +NFCommon::tostr(pConfig->mBusId) + "/" + content + "/";

    int count = 0;
    while(count++ <= 10)
    {
        ret = Register(eServerType, path, content);
        if (ret == proto_ff::ERR_CODE_ZK_NODEEXISTS)
        {
            ret = ForceDelete(eServerType, path, content);
            CHECK_EXPR_CONTINUE(ret == 0, "iRet:{} ForceDelete Failed, eServerType:{} title:{} content:{}", ret, eServerType, path, content);
            ret = Register(eServerType, path, content);
        }
        CHECK_EXPR_CONTINUE(ret == 0, "Register Failed, eServerType:{} title:{} content:{}", ret, eServerType, path, content);

        break;
    }

    return 0;
}

int32_t NFCNamingModule::UnInitAppInfo(NF_SERVER_TYPES eServerType)
{
    int32_t ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);
    ret = UnRegister(eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/busUrl/"+NFCommon::tostr(pConfig->mBusId));
    CHECK_RET(ret, "UnRegister Failed, eServerType:{} name:{}", eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType));
    ret = UnRegister(eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/tcpUrl/"+NFCommon::tostr(pConfig->mBusId));
    CHECK_RET(ret, "UnRegister Failed, eServerType:{} name:{}", eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType));
    ret = UnRegister(eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/routeAgent/"+NFCommon::tostr(pConfig->mBusId));
    CHECK_RET(ret, "UnRegister Failed, eServerType:{} name:{}", eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType));
    ret = UnRegister(eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/externalServerIp/"+NFCommon::tostr(pConfig->mBusId));
    CHECK_RET(ret, "UnRegister Failed, eServerType:{} name:{}", eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType));
    ret = UnRegister(eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType)+"/externalServerPort/"+NFCommon::tostr(pConfig->mBusId));
    CHECK_RET(ret, "UnRegister Failed, eServerType:{} name:{}", eServerType, pConfig->mNamingPath+"/"+GetServerName(eServerType));
    return 0;
}

int32_t NFCNamingModule::GetTcpUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& tcpUrlVec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/tcpUrl/*";

    ret = GetUrlsByName(eServerType, name, &tcpUrlVec);
    CHECK_RET(ret, "GetTcpUrlsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetTcpUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& tcpUrlVec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/tcpUrl/" + NFCommon::tostr(busId);

    ret = GetUrlsByName(eServerType, name, &tcpUrlVec);
    CHECK_RET(ret, "GetTcpUrlsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetBusUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrlVec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/busUrl/*";

    ret = GetUrlsByName(eServerType, name, &busUrlVec);
    CHECK_RET(ret, "GetBusUrlsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetBusUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& busUrlVec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/busUrl/" + NFCommon::tostr(busId);;

    ret = GetUrlsByName(eServerType, name, &busUrlVec);
    CHECK_RET(ret, "GetBusUrlsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetRouteAgentsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& routeAgent)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/routeAgent/*";

    ret = GetUrlsByName(eServerType, name, &routeAgent);
    CHECK_RET(ret, "GetRouteAgentsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetRouteAgentsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& routeAgent)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/routeAgent/" + NFCommon::tostr(busId);;

    ret = GetUrlsByName(eServerType, name, &routeAgent);
    CHECK_RET(ret, "GetRouteAgentsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetExternalServerIpsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& vec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/externalServerIp/*";

    ret = GetUrlsByName(eServerType, name, &vec);
    CHECK_RET(ret, "GetExternalServerIpsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetExternalServerIpsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& vec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/externalServerIp/" + NFCommon::tostr(busId);;

    ret = GetUrlsByName(eServerType, name, &vec);
    CHECK_RET(ret, "GetExternalServerIpsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetExternalServerPortsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& vec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/externalServerPort/*";

    ret = GetUrlsByName(eServerType, name, &vec);
    CHECK_RET(ret, "GetExternalServerPortsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}

int32_t NFCNamingModule::GetExternalServerPortsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& vec)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/externalServerPort/" + NFCommon::tostr(busId);;

    ret = GetUrlsByName(eServerType, name, &vec);
    CHECK_RET(ret, "GetExternalServerPortsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}


int32_t NFCNamingModule::GetDBNameByServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t destBusId, std::vector<std::string>& dbName)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/DBNames/" + NFCommon::tostr(destBusId) + "/*";

    ret = GetUrlsByName(eServerType, name, &dbName);
    CHECK_RET(ret, "GetUrlsByName Failed! eServerType:{} name:{}", destServerType, name);

    return 0;
}


int32_t NFCNamingModule::WatchTcpUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    Register(eServerType, pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/tcpUrl/0", "0");

    std::string tcpUrl = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/tcpUrl";
    ret = WatchName(eServerType, tcpUrl, [this,eServerType, destServerType, wc](const string &name, const std::vector<std::string>& urls){
        int errCode = 0;
        if (urls.empty()) return;

        for(int i = 0; i < (int)urls.size(); i++)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WatchName name:{} url:{}", name, urls[i]);
            std::string busId = NFFileUtility::GetFileNameWithoutExt(urls[i]);
            if (busId.empty() || busId == "0") continue;

            proto_ff::ServerInfoReport xData;
            xData.set_server_type(destServerType);
            xData.set_bus_id(NFCommon::strto<uint32_t>(busId));
            xData.set_bus_name(NFServerIDUtil::GetBusNameFromBusID(xData.bus_id()));
            xData.set_server_name(GetServerName(destServerType)+"_"+NFCommon::tostr(NFServerIDUtil::GetInstID(xData.bus_id())));

            std::vector<std::string> vecTcpUrl;
            errCode = GetTcpUrlsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecTcpUrl);
            if (errCode != 0) continue;

            for(int j = 0; j < (int)vecTcpUrl.size(); j++)
            {
                NFChannelAddress addr;
                NFServerIDUtil::MakeAddress(vecTcpUrl[j], addr);
                xData.set_link_mode(addr.mScheme);
                xData.set_url(vecTcpUrl[j]);

                std::vector<std::string> vecRouteAgent;
                errCode = GetRouteAgentsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecRouteAgent);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecRouteAgent.size(); x++)
                    {
                        if (!vecRouteAgent[x].empty())
                        {
                            xData.set_route_svr(vecRouteAgent[x]);
                        }
                    }
                }

                std::vector<std::string> vecExternalServerIp;
                errCode = GetExternalServerIpsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerIp);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecExternalServerIp.size(); x++)
                    {
                        if (!vecExternalServerIp[x].empty())
                        {
                            xData.set_external_server_ip(vecExternalServerIp[x]);
                        }
                    }
                }

                std::vector<std::string> vecExternalServerPort;
                errCode = GetExternalServerPortsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerPort);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecExternalServerPort.size(); x++)
                    {
                        if (!vecExternalServerPort[x].empty())
                        {
                            xData.set_external_server_port(NFCommon::strto<uint32_t>(vecExternalServerPort[x]));
                        }
                    }
                }

                if (addr.mScheme == "tcp" || addr.mScheme == "udp" || addr.mScheme == "http")
                {
                    xData.set_server_ip(addr.mHost);
                    xData.set_server_port(addr.mPort);

                    if (destServerType == NF_ST_STORE_SERVER)
                    {
                        std::vector<std::string> dbNames;
                        GetDBNameByServer(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), dbNames);
                        for(int i = 0; i < (int)dbNames.size(); i++)
                        {
                            xData.add_db_name_list(dbNames[i]);
                        }
                    }

                    wc(busId, xData, errCode);
                }
                else
                {
                    errCode = -1;
                    wc(busId, xData, errCode);
                }
            }

            if (vecTcpUrl.empty())
            {
                errCode = -1;
                wc(busId, xData, errCode);
            }
        }
    });
    CHECK_RET(ret, "WatchName Failed! eServerType:{} name:{}", destServerType, tcpUrl);

    tcpUrl = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/tcpUrl/*";
    ret = WatchName(eServerType, tcpUrl, [this,eServerType, destServerType, wc](const string &name, const std::vector<std::string>& urls){
        int errCode = 0;
        std::string busId = NFFileUtility::GetFileNameWithoutExt(name);
        if (busId.empty() || busId == "0") return;

        proto_ff::ServerInfoReport xData;
        xData.set_server_type(destServerType);
        xData.set_bus_id(NFCommon::strto<uint32_t>(busId));
        xData.set_bus_name(NFServerIDUtil::GetBusNameFromBusID(xData.bus_id()));
        xData.set_server_name(GetServerName(destServerType)+"_"+NFCommon::tostr(NFServerIDUtil::GetInstID(xData.bus_id())));
        for (int i = 0; i < (int)urls.size(); i++)
        {
            NFChannelAddress addr;
            NFServerIDUtil::MakeAddress(urls[i], addr);
            xData.set_link_mode(addr.mScheme);
            xData.set_url(urls[i]);

            std::vector<std::string> vecRouteAgent;
            errCode = GetRouteAgentsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecRouteAgent);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecRouteAgent.size(); x++)
                {
                    if (!vecRouteAgent[x].empty())
                    {
                        xData.set_route_svr(vecRouteAgent[x]);
                    }
                }
            }

            std::vector<std::string> vecExternalServerIp;
            errCode = GetExternalServerIpsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerIp);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecExternalServerIp.size(); x++)
                {
                    if (!vecExternalServerIp[x].empty())
                    {
                        xData.set_external_server_ip(vecExternalServerIp[x]);
                    }
                }
            }

            std::vector<std::string> vecExternalServerPort;
            errCode = GetExternalServerPortsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerPort);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecExternalServerPort.size(); x++)
                {
                    if (!vecExternalServerPort[x].empty())
                    {
                        xData.set_external_server_port(NFCommon::strto<uint32_t>(vecExternalServerPort[x]));
                    }
                }
            }

            if (addr.mScheme == "tcp" || addr.mScheme == "udp" || addr.mScheme == "http")
            {
                xData.set_server_ip(addr.mHost);
                xData.set_server_port(addr.mPort);

                if (destServerType == NF_ST_STORE_SERVER)
                {
                    std::vector<std::string> dbNames;
                    GetDBNameByServer(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), dbNames);
                    for(int i = 0; i < (int)dbNames.size(); i++)
                    {
                        xData.add_db_name_list(dbNames[i]);
                    }
                }

                wc(busId, xData, errCode);
            }
            else
            {
                errCode = -1;
                wc(busId, xData, errCode);
            }
        }

        if (urls.empty())
        {
            errCode = -1;
            wc(busId, xData, errCode);
        }
    });
    CHECK_RET(ret, "WatchName Failed! eServerType:{} name:{}", destServerType, tcpUrl);
    return 0;
}

int32_t NFCNamingModule::WatchBusUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc)
{
    int ret = 0;
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(eServerType);
    CHECK_EXPR(pConfig, -1, "pConfig null, eServerType:{}", eServerType);

    Register(eServerType, pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/busUrl/0", "0");

    std::string name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/busUrl";
    ret = WatchName(eServerType, name, [this,eServerType, destServerType, wc](const string &name, const std::vector<std::string>& urls){
        int errCode = 0;
        if (urls.empty()) return;

        for(int i = 0; i < (int)urls.size(); i++)
        {
            std::string busId = NFFileUtility::GetFileNameWithoutExt(urls[i]);
            if (busId.empty() || busId == "0") continue;

            proto_ff::ServerInfoReport xData;
            xData.set_server_type(destServerType);
            xData.set_bus_id(NFCommon::strto<uint32_t>(busId));
            xData.set_bus_name(NFServerIDUtil::GetBusNameFromBusID(xData.bus_id()));
            xData.set_server_name(GetServerName(destServerType)+"_"+NFCommon::tostr(NFServerIDUtil::GetInstID(xData.bus_id())));

            std::vector<std::string> vecBusUrl;
            errCode = GetBusUrlsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecBusUrl);
            if (errCode != 0) continue;

            for(int j = 0; j < (int)vecBusUrl.size(); j++)
            {
                NFChannelAddress addr;
                NFServerIDUtil::MakeAddress(vecBusUrl[j], addr);
                xData.set_link_mode(addr.mScheme);
                xData.set_url(vecBusUrl[j]);

                std::vector<std::string> vecRouteAgent;
                errCode = GetRouteAgentsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecRouteAgent);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecRouteAgent.size(); x++)
                    {
                        if (!vecRouteAgent[x].empty())
                        {
                            xData.set_route_svr(vecRouteAgent[x]);
                        }
                    }
                }

                std::vector<std::string> vecExternalServerIp;
                errCode = GetExternalServerIpsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerIp);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecExternalServerIp.size(); x++)
                    {
                        if (!vecExternalServerIp[x].empty())
                        {
                            xData.set_external_server_ip(vecExternalServerIp[x]);
                        }
                    }
                }

                std::vector<std::string> vecExternalServerPort;
                errCode = GetExternalServerPortsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerPort);
                if (errCode == 0)
                {
                    for(int x = 0; x < (int)vecExternalServerPort.size(); x++)
                    {
                        if (!vecExternalServerPort[x].empty())
                        {
                            xData.set_external_server_port(NFCommon::strto<uint32_t>(vecExternalServerPort[x]));
                        }
                    }
                }

                if (addr.mScheme == "bus")
                {
                    uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
                    CHECK_EXPR(busid == xData.bus_id(), , "busid error");
                    xData.set_bus_length(addr.mPort);

                    if (destServerType == NF_ST_STORE_SERVER)
                    {
                        std::vector<std::string> dbNames;
                        GetDBNameByServer(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), dbNames);
                        for(int i = 0; i < (int)dbNames.size(); i++)
                        {
                            xData.add_db_name_list(dbNames[i]);
                        }
                    }

                    wc(busId, xData, errCode);
                }
                else
                {
                    errCode = -1;
                    wc(busId, xData, errCode);
                }
            }

            if (vecBusUrl.empty())
            {
                errCode = -1;
                wc(busId, xData, errCode);
            }
        }
    });
    CHECK_RET(ret, "WatchName Failed! eServerType:{} name:{}", destServerType, name);

    name = pConfig->mNamingPath+"/"+GetServerName(destServerType)+"/busUrl/*";
    ret = WatchName(eServerType, name, [this,eServerType, destServerType, wc](const string &name, const std::vector<std::string>& urls){
        int errCode = 0;
        std::string busId = NFFileUtility::GetFileNameWithoutExt(name);
        if (busId.empty() || busId == "0") return;

        proto_ff::ServerInfoReport xData;
        xData.set_server_type(destServerType);
        xData.set_bus_id(NFCommon::strto<uint32_t>(busId));
        xData.set_bus_name(NFServerIDUtil::GetBusNameFromBusID(xData.bus_id()));
        xData.set_server_name(GetServerName(destServerType)+"_"+NFCommon::tostr(NFServerIDUtil::GetInstID(xData.bus_id())));
        for(int i = 0; i < (int)urls.size(); i++)
        {
            NFChannelAddress addr;
            NFServerIDUtil::MakeAddress(urls[i], addr);
            xData.set_link_mode(addr.mScheme);
            xData.set_url(urls[i]);

            std::vector<std::string> vecRouteAgent;
            errCode = GetRouteAgentsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecRouteAgent);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecRouteAgent.size(); x++)
                {
                    if (!vecRouteAgent[x].empty())
                    {
                        xData.set_route_svr(vecRouteAgent[x]);
                    }
                }
            }

            std::vector<std::string> vecExternalServerIp;
            errCode = GetExternalServerIpsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerIp);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecExternalServerIp.size(); x++)
                {
                    if (!vecExternalServerIp[x].empty())
                    {
                        xData.set_external_server_ip(vecExternalServerIp[x]);
                    }
                }
            }

            std::vector<std::string> vecExternalServerPort;
            errCode = GetExternalServerPortsByName(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), vecExternalServerPort);
            if (errCode == 0)
            {
                for(int x = 0; x < (int)vecExternalServerPort.size(); x++)
                {
                    if (!vecExternalServerPort[x].empty())
                    {
                        xData.set_external_server_port(NFCommon::strto<uint32_t>(vecExternalServerPort[x]));
                    }
                }
            }

            if (addr.mScheme == "bus")
            {
                uint32_t busid = NFServerIDUtil::GetBusID(addr.mHost);
                CHECK_EXPR(busid == xData.bus_id(), , "busid error");
                xData.set_bus_length(addr.mPort);

                if (errCode == 0 && destServerType == NF_ST_STORE_SERVER)
                {
                    std::vector<std::string> dbNames;
                    GetDBNameByServer(eServerType, destServerType, NFCommon::strto<uint32_t>(busId), dbNames);
                    for(int i = 0; i < (int)dbNames.size(); i++)
                    {
                        xData.add_db_name_list(dbNames[i]);
                    }
                }

                wc(busId, xData, errCode);
            }
            else
            {
                errCode = -1;
                wc(busId, xData, errCode);
            }
        }

        if (urls.empty())
        {
            errCode = -1;
            wc(busId, xData, errCode);
        }
    });
    CHECK_RET(ret, "WatchName Failed! eServerType:{} name:{}", destServerType, name);
    return 0;
}

int32_t NFCNamingModule::Init(NF_SERVER_TYPES eServerType, const string &host, int32_t time_out_ms)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    if (m_namingList[eServerType] == NULL)
    {
#if NF_PLATFORM == NF_PLATFORM_WIN
		m_namingList[eServerType] = NF_NEW NFBusppNaming();
#else
        if (host.empty())
        {
            m_namingList[eServerType] = NF_NEW NFBusppNaming();
        }
        else {
            m_namingList[eServerType] = NF_NEW NFZookeeperNaming();
        }
#endif
    }
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);

    return m_namingList[eServerType]->Init(host, time_out_ms);
}

int32_t NFCNamingModule::SetCache(NF_SERVER_TYPES eServerType, bool use_cache, int32_t refresh_time_ms, int32_t invaild_time_ms)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->SetCache(use_cache, refresh_time_ms, invaild_time_ms);
}

int32_t NFCNamingModule::SetAppInfo(NF_SERVER_TYPES eServerType, const string &app_id, const string &app_key)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->SetAppInfo(app_id, app_key);
}

int32_t NFCNamingModule::Register(NF_SERVER_TYPES eServerType, const string &name, const string &url, int64_t instance_id)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->Register(name, url, instance_id);
}

int32_t NFCNamingModule::UnRegister(NF_SERVER_TYPES eServerType, const string &name, int64_t instance_id)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->UnRegister(name, instance_id);
}

int32_t NFCNamingModule::ForceDelete(NF_SERVER_TYPES eServerType, const std::string& name, const std::string& url, int64_t instance_id)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->ForceDelete(name, url, instance_id);
}

int32_t NFCNamingModule::GetUrlsByName(NF_SERVER_TYPES eServerType, const string &name, std::vector<std::string> *urls)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->GetUrlsByName(name, urls);
}

int32_t NFCNamingModule::WatchName(NF_SERVER_TYPES eServerType, const string &name, const NFNamingWatchFunc &wc)
{
    CHECK_EXPR(eServerType >= 0 && eServerType < m_namingList.size(), -1, "eServerType:{} error", eServerType);
    CHECK_EXPR(m_namingList[eServerType], -1, "eServerType:{} null", eServerType);
    return m_namingList[eServerType]->WatchName(name, wc);
}

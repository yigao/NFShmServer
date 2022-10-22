// -------------------------------------------------------------------------
//    @FileName         :    NFCWebServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCWebServerModule.cpp
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFCWebServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

#define WEB_SERVER_CONNECT_MASTER_SERVER "WebServer Connect MasterServer"
#define WEB_SERVER_CONNECT_ROUTE_AGENT_SERVER "WebServer Connect RouteAgentServer"

NFCWebServerModule::NFCWebServerModule(NFIPluginManager* p):NFIWebServerModule(p)
{
}

NFCWebServerModule::~NFCWebServerModule()
{
}

bool NFCWebServerModule::Awake() {
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_WEB_SERVER);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WEB_SERVER,
                                                       proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFCWebServerModule::OnHandleServerReport);

    /////////////////route agent msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCWebServerModule::OnRegisterRouteAgentRspProcess);
    ////////////////test other server msg///////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WEB_SERVER, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ, this, &NFCWebServerModule::OnHandleTestWorldServerMsg);


    //注册要完成的服务器启动任务
    m_pObjPluginManager->RegisterAppTask(NF_ST_WEB_SERVER, APP_INIT_CONNECT_MASTER, WEB_SERVER_CONNECT_MASTER_SERVER);
    m_pObjPluginManager->RegisterAppTask(NF_ST_WEB_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, WEB_SERVER_CONNECT_ROUTE_AGENT_SERVER);


    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig) {
        std::string httpUrl = NF_FORMAT("http://{}:{}", pConfig->ServerIp, pConfig->HttpPort);
        int ret = FindModule<NFIMessageModule>()->BindServer(NF_ST_WEB_SERVER, httpUrl, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (ret < 0)
        {
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "web server listen http failed!, serverId:{}, ip:{}, httpport:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->HttpPort);
            return false;
        }

        int64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_WEB_SERVER, pConfig->Url, 1, 100, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            /*
                注册客户端事件
            */
            uint64_t loginServerLinkId = (uint64_t) unlinkId;
            FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_WEB_SERVER, loginServerLinkId);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WEB_SERVER, loginServerLinkId, this, &NFCWebServerModule::OnWebSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WEB_SERVER, loginServerLinkId, this, &NFCWebServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "web server listen success, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "web server listen failed, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
            return false;
        }

        if (pConfig->LinkMode == "bus")
        {
            int iRet = FindModule<NFIMessageModule>()->ResumeConnect(NF_ST_WEB_SERVER);
            if (iRet == 0)
            {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(
                        NF_ST_WEB_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++)
                {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0)
                    {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER)
                        {
                            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WEB_SERVER, pServerData->mUnlinkId, this, &NFCWebServerModule::OnRouteAgentServerSocketEvent);
                            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WEB_SERVER, pServerData->mUnlinkId, this, &NFCWebServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_WEB_SERVER);
                            pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                            pRouteServer->mServerInfo = pServerData->mServerInfo;
                        }
                    }
                }
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_WEB_SERVER_PLUGIN, 0, "I Can't get the web Server config!");
        return false;
    }

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, NF_ST_WEB_SERVER, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    return true;
}

int NFCWebServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(10000, 10000, 0);
        }
        else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }
    }

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    return 0;
}

void NFCWebServerModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCWebServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_WEB_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WEB_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WEB_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCWebServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WEB_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCWebServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_WEB_SERVER_PLUGIN, 0, "I Can't get the web Server config!");
        return -1;
    }

    return 0;
}

bool NFCWebServerModule::Init()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    NF_ASSERT(pConfig);
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_WEB_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->RouteConfig.NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_WEB_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WEB_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "WebServer Watch, MasterServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WebServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    if (pConfig->LinkMode == "bus")
    {
        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_WEB_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WebServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WebServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }
    else
    {
        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WEB_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WebServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WebServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }

    return true;
}

bool NFCWebServerModule::Execute()
{
    ServerReport();
    TestOtherServerToWorldServer();
    return true;
}

bool NFCWebServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_WEB_SERVER);
    return true;
}

/*
	处理Master服务器链接事件
*/
int NFCWebServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");

    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        NFLogDebug(NF_LOG_WEB_SERVER_PLUGIN, 0, "web server connect master success!");
        if (!m_pObjPluginManager->IsInited())
        {
            RegisterMasterServer(proto_ff::EST_INIT);
        }
        else {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }

        //完成服务器启动任务
        if (!m_pObjPluginManager->IsInited())
        {
            m_pObjPluginManager->FinishAppTask(NF_ST_WEB_SERVER, APP_INIT_CONNECT_MASTER);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        NFLogError(NF_LOG_WEB_SERVER_PLUGIN, 0, "store server disconnect master success");
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCWebServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
    NFLogWarning(NF_LOG_WEB_SERVER_PLUGIN, 0, "master server other message not handled:msg:{},ip:{}", packet.ToString(), ip);
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::RegisterMasterServer(uint32_t serverState)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(serverState);

        FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_WEB_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::ServerReport()
{
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        return 0;
    }

    static uint64_t mLastReportTime = m_pObjPluginManager->GetNowTime();
    if (mLastReportTime + 100000 > m_pObjPluginManager->GetNowTime())
    {
        return 0;
    }

    mLastReportTime = m_pObjPluginManager->GetNowTime();

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(proto_ff::EST_NARMAL);

        NFIMonitorModule* pMonitorModule = m_pObjPluginManager->FindModule<NFIMonitorModule>();
        if (pMonitorModule)
        {
            const NFSystemInfo& systemInfo = pMonitorModule->GetSystemInfo();
            NFServerCommon::WriteServerInfo(pData, systemInfo);
        }

        if (pData->proc_cpu() > 0 && pData->proc_mem() > 0)
        {
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_WEB_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
        }
    }
    return 0;
}

int NFCWebServerModule::OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);


    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_ROUTE_AGENT_SERVER:
            {
                OnHandleRouteAgentReport(xData);
            }
                break;
            default:
                break;
        }
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    CHECK_NULL(pConfig);

    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        if (pConfig->RouteConfig.RouteAgent != xData.server_id())
        {
            return 0;
        }
    }

    auto pRouteAgentServerData = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_WEB_SERVER);
    CHECK_NULL(pRouteAgentServerData);

    if (pRouteAgentServerData->mUnlinkId == 0)
    {
        pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WEB_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

        FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WEB_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWebServerModule::OnRouteAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WEB_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWebServerModule::OnHandleRouteAgentOtherMessage);
    }
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WEB_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WEB_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWebServerModule::OnRouteAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WEB_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWebServerModule::OnHandleRouteAgentOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_WEB_SERVER_PLUGIN, 0, "web server connect route server success!");

        RegisterRouteAgentServer(unLinkId);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_WEB_SERVER_PLUGIN, 0, "web server disconnect route server success");
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    NFLogWarning(NF_LOG_WEB_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnWebSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    NFLogWarning(NF_LOG_WEB_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_WEB_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_WEB_SERVER_PLUGIN, 0, "the server disconnect from web server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(NF_ST_WEB_SERVER, unLinkId);
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet) {
    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- begin --");

    //完成服务器启动任务
    if (!m_pObjPluginManager->IsInited())
    {
        m_pObjPluginManager->FinishAppTask(NF_ST_WEB_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
    }

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_WEB_SERVER);

    NFLogTrace(NF_LOG_WEB_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWebServerModule::TestOtherServerToWorldServer()
{
#ifdef TEST_SERVER_SEND_MSG
    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

    static int req = 0;
    for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
    {
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
        CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

        proto_ff::Proto_TestOtherServerToWorldServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        xData.set_seq(++req);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_WEB_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, xData, 1, 2);
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    }
#endif

    return 0;
}

int NFCWebServerModule::OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    static int last_seq = -1;

    proto_ff::Proto_TestSendWorldMsgToOtherServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    if (last_seq < 0)
    {
        last_seq = xMsg.seq();
    }
    else {
        NFLogErrorIf(last_seq + 1 != xMsg.seq(), NF_LOG_SYSTEMLOG, 0, "world server send seq error, last_seq:{} seq:{}", last_seq, xMsg.seq());
        last_seq = xMsg.seq();
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
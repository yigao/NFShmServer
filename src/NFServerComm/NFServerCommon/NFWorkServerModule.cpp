// -------------------------------------------------------------------------
//    @FileName         :    NFWorkServerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorkServerModule
//
// -------------------------------------------------------------------------

#include "NFWorkServerModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerCommonDefine.h"
#include "NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#define SERVER_CONNECT_MASTER_SERVER "Server Connect MasterServer"
#define SERVER_CONNECT_ROUTEAGENT_SERVER "Server Connect RouteAgentServer"
#define SERVER_CHECK_STORE_SERVER "Server Check Store Server"
#define SERVER_CHECK_WORLD_SERVER "Server Check World Server"
#define SERVER_CHECK_CENTER_SERVER "Server Check Center Server"

#define SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID 101
#define SERVER_SERVER_DEAD_TIMER_ID 102

bool NFWorkServerModule::IsConnectMasterServer() const
{
    return m_connectMasterServer;
}

void NFWorkServerModule::SetConnectMasterServer(bool connectMasterServer)
{
    m_connectMasterServer = connectMasterServer;
    if (connectMasterServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_MASTER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_CONNECT_MASTER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CONNECT_MASTER_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}

bool NFWorkServerModule::IsConnectRouteAgentServer() const
{
    return m_connectRouteAgentServer;
}

void NFWorkServerModule::SetConnectRouteAgentServer(bool connectRouteAgentServer)
{
    m_connectRouteAgentServer = connectRouteAgentServer;
    if (connectRouteAgentServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_ROUTE_AGENT_SERVER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_CONNECT_ROUTE_AGENT_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CONNECT_ROUTEAGENT_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}

bool NFWorkServerModule::IsConnectProxyAgentServer() const
{
    return m_connectProxyAgentServer;
}

void NFWorkServerModule::SetConnectProxyAgentServer(bool connectProxyAgentServer)
{
    m_connectProxyAgentServer = connectProxyAgentServer;
    if (connectProxyAgentServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_PROXY_AGENT_SERVER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_CONNECT_PROXY_AGENT_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, APP_INIT_CONNECT_PROXY_AGENT_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}

bool NFWorkServerModule::IsCheckStoreServer() const
{
    return m_checkStoreServer;
}

void NFWorkServerModule::SetCheckStoreServer(bool checkStoreServer)
{
    m_checkStoreServer = checkStoreServer;
    if (checkStoreServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_STORE_SERVER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_NEED_STORE_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_STORE_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}


bool NFWorkServerModule::IsCheckWorldServer() const
{
    return m_checkWorldServer;
}

void NFWorkServerModule::SetCheckWorldServer(bool checkWorldServer)
{
    m_checkWorldServer = checkWorldServer;
    if (checkWorldServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_CENTER_SERVER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_NEED_CENTER_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_WORLD_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}

bool NFWorkServerModule::IsCheckCenterServer() const
{
    return m_checkCenterServer;
}

void NFWorkServerModule::SetCheckCenterServer(bool checkCenterServer)
{
    m_checkCenterServer = checkCenterServer;
    if (checkCenterServer && m_serverType != NF_ST_CENTER_SERVER && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_CENTER_SERVER))
    {
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
        CHECK_EXPR_ASSERT(pConfig, , "GetAppConfig Failed, server type:{}", m_serverType);

        RegisterAppTask(m_serverType, APP_INIT_NEED_CENTER_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_CENTER_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }
}

NF_SERVER_TYPES NFWorkServerModule::GetServerType() const
{
    return m_serverType;
}

void NFWorkServerModule::SetServerType(NF_SERVER_TYPES serverType)
{
    m_serverType = serverType;
}

int NFWorkServerModule::BindServer()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, -1, "GetAppConfig Failed, server type:{}", m_serverType);

    //////////////////////master msg//////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFWorkServerModule::OnHandleServerReportFromMasterServer);

    /////////////////route agent msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this,
                                                       &NFWorkServerModule::OnRegisterRouteAgentServerRspProcess);

    //////////////////////proxy server msg//////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this,
                                                       &NFWorkServerModule::OnServerRegisterProcessFromProxyServer);

    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        CHECK_EXPR_ASSERT(pConfig->ServerType == m_serverType, -1, "server config error, server id not match the server type!:{}", m_serverType);
    }

    //注册要完成的服务器启动任务
    if (m_connectMasterServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_MASTER))
    {
        RegisterAppTask(m_serverType, APP_INIT_CONNECT_MASTER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CONNECT_MASTER_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    if (m_connectRouteAgentServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_ROUTE_AGENT_SERVER))
    {
        RegisterAppTask(m_serverType, APP_INIT_CONNECT_ROUTE_AGENT_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CONNECT_ROUTEAGENT_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    if (m_connectProxyAgentServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_CONNECT_PROXY_AGENT_SERVER))
    {
        RegisterAppTask(m_serverType, APP_INIT_CONNECT_PROXY_AGENT_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, APP_INIT_CONNECT_PROXY_AGENT_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    if (m_checkStoreServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_STORE_SERVER))
    {
        RegisterAppTask(m_serverType, APP_INIT_NEED_STORE_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_STORE_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    if (m_checkWorldServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_WORLD_SERVER))
    {
        RegisterAppTask(m_serverType, APP_INIT_NEED_WORLD_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_WORLD_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    if (m_checkCenterServer && !IsHasAppTask(m_serverType, APP_INIT_TASK_GROUP_SERVER_CONNECT, APP_INIT_NEED_CENTER_SERVER))
    {
        RegisterAppTask(m_serverType, APP_INIT_NEED_CENTER_SERVER,
                        NF_FORMAT("{} {}", pConfig->ServerName, SERVER_CHECK_CENTER_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    uint64_t serverLinkId = FindModule<NFIMessageModule>()->BindServer(m_serverType, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum,
                                                                       PACKET_PARSE_TYPE_INTERNAL);
    CHECK_EXPR_ASSERT(serverLinkId > 0, -1, "Server:{} Listen Failed, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId,
                      pConfig->ServerIp, pConfig->ServerPort);

    FindModule<NFIMessageModule>()->SetServerLinkId(m_serverType, serverLinkId);
    FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, serverLinkId, this, &NFWorkServerModule::OnServerSocketEvent);
    FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, serverLinkId, this,
                                                     &NFWorkServerModule::OnHandleServerOtherMessage);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{} Listen Success, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId, pConfig->ServerIp,
              pConfig->ServerPort);

    Subscribe(m_serverType, proto_ff::NF_EVENT_SERVER_DEAD_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    Subscribe(m_serverType, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);

    SetTimer(SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID, 10000);
    return 0;
}

int NFWorkServerModule::InitLoadLua()
{
    return 0;
}

int NFWorkServerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    CHECK_NULL(serverType == m_serverType);
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(SERVER_SERVER_DEAD_TIMER_ID, 10000, 0);
        } else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }
    }

    return 0;
}

int NFWorkServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID)
    {
        ServerReportToMasterServer();
    } else if (nTimerID == SERVER_SERVER_DEAD_TIMER_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
    return 0;
}

int NFWorkServerModule::ConnectMasterServer()
{
    if (m_connectMasterServer == false)
    {
        return 0;
    }


    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, -1, "GetAppConfig Failed, server type:{}", m_serverType);

#if NF_PLATFORM == NF_PLATFORM_WIN
    proto_ff::ServerInfoReport masterData = FindModule<NFIConfigModule>()->GetDefaultMasterInfo(m_serverType);
    int32_t ret = ConnectMasterServer(masterData);
    CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->RouteConfig.NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFIConfigModule>()->GetDefaultMasterInfo(m_serverType);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, -1, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    return 0;
}

int NFWorkServerModule::OnServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    if (nEvent == eMsgType_CONNECTED)
    {

    } else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFWorkServerModule::OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(m_serverType, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_SYSTEMLOG, 0, "the server:{} disconnect from server:{}, serverName:{}, busid:{}, serverIp:{}, serverPort:{}",
                   pServerData->mServerInfo.server_name(), pConfig->ServerName, pServerData->mServerInfo.server_name(),
                   pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(m_serverType, unLinkId);
    return 0;
}

int NFWorkServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport &xData)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);
    auto pMsterServerData = FindModule<NFIMessageModule>()->GetMasterData(m_serverType);
    if (pMsterServerData->mUnlinkId <= 0)
    {
        pMsterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pMsterServerData->mUnlinkId, this, &NFWorkServerModule::OnMasterSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pMsterServerData->mUnlinkId, this,
                                                         &NFWorkServerModule::OnHandleMasterOtherMessage);
    }

    pMsterServerData->mServerInfo = xData;

    return 0;
}

int NFWorkServerModule::RegisterMasterServer(uint32_t serverState)
{
    if (m_connectMasterServer == false)
    {
        return 0;
    }


    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport *pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);

        pData->set_server_state(serverState);
        FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_SERVER_TO_SERVER_REGISTER>(m_serverType, NF_ST_MASTER_SERVER, 0, xMsg, [this](int rpcRetCode, proto_ff::ServerInfoReportListRespne &respone)
        {
            if (rpcRetCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Register Master Failed......, kill the exe");
                proto_ff::NFEventNoneData event;
                FireExecute(m_serverType, proto_ff::NF_EVENT_SERVER_DEAD_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                return;
            }

            //完成服务器启动任务
            if (!m_pObjPluginManager->IsInited(m_serverType))
            {
                FinishAppTask(m_serverType, APP_INIT_CONNECT_MASTER, APP_INIT_TASK_GROUP_SERVER_CONNECT);
            }
        });
    }
    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFWorkServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect master success!", pConfig->ServerName);

        if (!m_pObjPluginManager->IsInited(m_serverType))
        {
            RegisterMasterServer(proto_ff::EST_INIT);
        } else
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }
    } else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect master success", pConfig->ServerName);
    }
    return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFWorkServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "master server other message not handled:msgId:{}", packet.ToString());
    return 0;
}

int NFWorkServerModule::OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_ROUTE_AGENT_SERVER:
            {
                OnHandleRouteAgentServerReport(xData);
            }
                break;
            case NF_SERVER_TYPES::NF_ST_STORE_SERVER:
            {
                OnHandleStoreServerReport(xData);
            }
                break;
            case NF_SERVER_TYPES::NF_ST_WORLD_SERVER:
            {
                OnHandleWorldServerReport(xData);
                break;
            }
            case NF_SERVER_TYPES::NF_ST_CENTER_SERVER:
            {
                OnHandleCenterServerReport(xData);
                break;
            }
            case NF_SERVER_TYPES::NF_ST_PROXY_AGENT_SERVER:
            {
                OnHandleProxyAgentServerReport(xData);
            }
                break;
            default:
            {
                OnHandleOtherServerReportFromMasterServer(xData);
            }
                break;
        }
    }
    return 0;
}

int NFWorkServerModule::OnHandleOtherServerReportFromMasterServer(const proto_ff::ServerInfoReport &xData)
{
    return 0;
}

int NFWorkServerModule::ServerReportToMasterServer()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport *pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(proto_ff::EST_NARMAL);

        NFIMonitorModule *pMonitorModule = m_pObjPluginManager->FindModule<NFIMonitorModule>();
        if (pMonitorModule)
        {
            const NFSystemInfo &systemInfo = pMonitorModule->GetSystemInfo();
            NFServerCommon::WriteServerInfo(pData, systemInfo);
        }

        if (pData->proc_cpu() > 0 && pData->proc_mem() > 0)
        {
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(m_serverType, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
        }
    }
    return 0;
}

int NFWorkServerModule::OnHandleProxyAgentServerReport(const proto_ff::ServerInfoReport &xData)
{
    if (m_connectProxyAgentServer == false)
    {
        return 0;
    }


    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.route_svr())
    {
        return 0;
    }

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(m_serverType, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);

        pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->CreateLinkToServer(m_serverType, xData.bus_id(), pServerData->mUnlinkId);

        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                         &NFWorkServerModule::OnProxyAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                         &NFWorkServerModule::OnHandleProxyAgentServerOtherMessage);
    } else
    {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(),
                         pServerData->mServerInfo.url(), xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pServerData->mUnlinkId);

            pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->CreateLinkToServer(m_serverType, xData.bus_id(), pServerData->mUnlinkId);

            FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                             &NFWorkServerModule::OnProxyAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                             &NFWorkServerModule::OnHandleProxyAgentServerOtherMessage);
        }
    }


    pServerData->mServerInfo = xData;

    return 0;
}

int NFWorkServerModule::OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect proxy agent server success!", pConfig->ServerName);
        RegisterProxyAgentServer(unLinkId);
    } else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect proxy agent server", pConfig->ServerName);
    }
    return 0;
}

int NFWorkServerModule::OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport *pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);

        std::set<uint32_t> allMsg = FindModule<NFIMessageModule>()->GetAllMsg(m_serverType, NF_MODULE_CLIENT);
        for (auto iter = allMsg.begin(); iter != allMsg.end(); ++iter)
        {
            pData->add_msg_id(*iter);
        }
        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
    }

    return 0;
}

int NFWorkServerModule::OnServerRegisterProcessFromProxyServer(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_PROXY_SERVER:
            {
                OnHandleProxyServerRegister(xData, unLinkId);
            }
                break;
            default:
                break;
        }
    }
    return 0;
}


int NFWorkServerModule::OnHandleProxyServerRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_SERVER, -1, "xData.server_type() == NF_ST_PROXY_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(m_serverType, xData.bus_id());
    if (!pServerData)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_PROXY_SERVER, xData);
    }

    pServerData->mUnlinkId = unlinkId;
    pServerData->mServerInfo = xData;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Proxy Server Register Server:{} Success, serverName:{}, busid:{}, ip:{}, port:{}", pConfig->ServerName,
              pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.external_server_ip(),
              pServerData->mServerInfo.external_server_port());

    //完成服务器启动任务
    if (!m_pObjPluginManager->IsInited(m_serverType))
    {
        FinishAppTask(m_serverType, APP_INIT_CONNECT_PROXY_AGENT_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    return 0;
}

int NFWorkServerModule::OnHandleStoreServerReport(const proto_ff::ServerInfoReport &xData)
{
    if (m_checkStoreServer == false)
    {
        return 0;
    }

    FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_STORE_SERVER, xData);

    FinishAppTask(m_serverType, APP_INIT_NEED_STORE_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT);

    return 0;
}

int NFWorkServerModule::OnHandleWorldServerReport(const proto_ff::ServerInfoReport &xData)
{
    if (m_checkWorldServer == false)
    {
        return 0;
    }

    FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_WORLD_SERVER, xData);

    FinishAppTask(m_serverType, APP_INIT_NEED_WORLD_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT);

    return 0;
}

int NFWorkServerModule::OnHandleCenterServerReport(const proto_ff::ServerInfoReport &xData)
{
    if (m_checkCenterServer == false)
    {
        return 0;
    }

    FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_CENTER_SERVER, xData);

    if (m_serverType != NF_ST_CENTER_SERVER)
    {
        FinishAppTask(m_serverType, APP_INIT_NEED_CENTER_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    return 0;
}

int NFWorkServerModule::OnHandleRouteAgentServerReport(const proto_ff::ServerInfoReport &xData)
{
    if (m_connectRouteAgentServer == false)
    {
        return 0;
    }

    CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.server_id())
    {
        return 0;
    }

    auto pRouteAgentServerData = FindModule<NFIMessageModule>()->GetRouteData(m_serverType);

    if (pRouteAgentServerData->mUnlinkId == 0)
    {
        pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                         &NFWorkServerModule::OnRouteAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                         &NFWorkServerModule::OnHandleRouteAgentServerOtherMessage);
    } else
    {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                             &NFWorkServerModule::OnRouteAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                             &NFWorkServerModule::OnHandleRouteAgentServerOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;

    return 0;
}

int NFWorkServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect route agent server success!", pConfig->ServerName);

        RegisterRouteAgentServer(unLinkId);
    } else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect route agent server success", pConfig->ServerName);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFWorkServerModule::OnHandleRouteAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport *pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);

        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
    }
    return 0;
}

int NFWorkServerModule::OnRegisterRouteAgentServerRspProcess(uint64_t unLinkId, NFDataPackage &packet)
{
    //完成服务器启动任务
    if (!m_pObjPluginManager->IsInited(m_serverType))
    {
        FinishAppTask(m_serverType, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    return 0;
}





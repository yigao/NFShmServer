// -------------------------------------------------------------------------
//    @FileName         :    NFTransMsgServerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransMsgServerModule
//
// -------------------------------------------------------------------------
#include "NFTransMsgServerModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerCommonDefine.h"
#include "NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#define SERVER_CONNECT_MASTER_SERVER "Server Connect MasterServer"

#define SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID 101
#define SERVER_SERVER_DEAD_TIMER_ID 102

bool NFTransMsgServerModule::IsConnectMasterServer() const
{
    return m_connectMasterServer;
}

void NFTransMsgServerModule::SetConnectMasterServer(bool connectMasterServer)
{
    m_connectMasterServer = connectMasterServer;
}

int NFTransMsgServerModule::BindServer()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, -1, "GetAppConfig Failed, server type:{}", m_serverType);

    //////////////////////master msg//////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFTransMsgServerModule::OnHandleServerReportFromMasterServer);

    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        CHECK_EXPR_ASSERT(pConfig->ServerType == m_serverType, -1, "server config error, server id not match the server type!:{}", m_serverType);
    }

    //注册要完成的服务器启动任务
    if (m_connectMasterServer)
    {
        RegisterAppTask(m_serverType, APP_INIT_CONNECT_MASTER,
                                             NF_FORMAT("{}_{}", pConfig->ServerName, SERVER_CONNECT_MASTER_SERVER), APP_INIT_TASK_GROUP_SERVER_CONNECT);
    }

    uint64_t serverLinkId = FindModule<NFIMessageModule>()->BindServer(m_serverType, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum,
                                                                       PACKET_PARSE_TYPE_INTERNAL);
    CHECK_EXPR_ASSERT(serverLinkId > 0, -1, "Server:{} Listen Failed, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId,
                      pConfig->ServerIp, pConfig->ServerPort);

    FindModule<NFIMessageModule>()->SetServerLinkId(m_serverType, serverLinkId);
    FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, serverLinkId, this, &NFTransMsgServerModule::OnServerSocketEvent);
    FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, serverLinkId, this,
                                                     &NFTransMsgServerModule::OnHandleServerOtherMessage);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{} Listen Success, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId, pConfig->ServerIp,
              pConfig->ServerPort);

    Subscribe(m_serverType, proto_ff::NF_EVENT_SERVER_DEAD_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    Subscribe(m_serverType, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);

    SetTimer(SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID, 10000);
    return 0;
}

int NFTransMsgServerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                      const google::protobuf::Message *pMessage)
{
    CHECK_NULL(serverType == m_serverType);
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(SERVER_SERVER_DEAD_TIMER_ID, 10000, 0);
        }
        else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }
    }

    return 0;
}

int NFTransMsgServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID)
    {
        ServerReportToMasterServer();
    }
    else if (nTimerID == SERVER_SERVER_DEAD_TIMER_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
    return 0;
}

int NFTransMsgServerModule::ConnectMasterServer()
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

int NFTransMsgServerModule::OnServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTransMsgServerModule::OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFTransMsgServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
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

int NFTransMsgServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport &xData)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);
    auto pMsterServerData = FindModule<NFIMessageModule>()->GetMasterData(m_serverType);
    if (pMsterServerData->mUnlinkId <= 0)
    {
        pMsterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pMsterServerData->mUnlinkId, this,
                                                         &NFTransMsgServerModule::OnMasterSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pMsterServerData->mUnlinkId, this,
                                                         &NFTransMsgServerModule::OnHandleMasterOtherMessage);
    }

    pMsterServerData->mServerInfo = xData;

    return 0;
}

int NFTransMsgServerModule::RegisterMasterServer(uint32_t serverState)
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
        FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
    }
    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFTransMsgServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
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
        }
        else
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }

        //完成服务器启动任务
        if (!m_pObjPluginManager->IsInited(m_serverType))
        {
            FinishAppTask(m_serverType, APP_INIT_CONNECT_MASTER, APP_INIT_TASK_GROUP_SERVER_CONNECT);
        }
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect master success", pConfig->ServerName);
    }
    return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFTransMsgServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "master server other message not handled:msgId:{}", packet.ToString());
    return 0;
}

int NFTransMsgServerModule::OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage &packet)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            default:
            {
                OnHandleOtherServerReportFromMasterServer(xData);
            }
                break;
        }
    }
    return 0;
}

int NFTransMsgServerModule::OnHandleOtherServerReportFromMasterServer(const proto_ff::ServerInfoReport &xData)
{
    return 0;
}

int NFTransMsgServerModule::ServerReportToMasterServer()
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
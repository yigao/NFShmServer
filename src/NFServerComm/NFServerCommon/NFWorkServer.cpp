// -------------------------------------------------------------------------
//    @FileName         :    NFWorkServer.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorkServer
//
// -------------------------------------------------------------------------

#include "NFWorkServer.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerCommonDefine.h"
#include "NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"

bool NFWorkServer::IsConnectMasterServer() const
{
    return m_connectMasterServer;
}

void NFWorkServer::SetConnectMasterServer(bool connectMasterServer)
{
    m_connectMasterServer = connectMasterServer;
}

bool NFWorkServer::IsConnectRouteAgentServer() const
{
    return m_connectRouteAgentServer;
}

void NFWorkServer::SetConnectRouteAgentServer(bool connectRouteAgentServer)
{
    m_connectRouteAgentServer = connectRouteAgentServer;
}

bool NFWorkServer::IsConnectProxyAgentServer() const
{
    return m_connectProxyAgentServer;
}

void NFWorkServer::SetConnectProxyAgentServer(bool connectProxyAgentServer)
{
    m_connectProxyAgentServer = connectProxyAgentServer;
}

bool NFWorkServer::IsCheckStoreServer() const
{
    return m_checkStoreServer;
}

void NFWorkServer::SetCheckStoreServer(bool checkStoreServer)
{
    m_checkStoreServer = checkStoreServer;
}

NF_SERVER_TYPES NFWorkServer::GetServerType() const
{
    return m_serverType;
}

void NFWorkServer::SetServerType(NF_SERVER_TYPES serverType)
{
    m_serverType = serverType;
}

bool NFWorkServer::BindServer()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        CHECK_EXPR_ASSERT(pConfig->ServerType == m_serverType, false, "server config error, server id not match the server type!:{}", m_serverType);
    }

    int64_t serverLinkId = FindModule<NFIMessageModule>()->BindServer(m_serverType, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
    CHECK_EXPR_ASSERT(serverLinkId >= 0, false, "Server:{} Listen Failed, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);

    FindModule<NFIMessageModule>()->SetServerLinkId(m_serverType, serverLinkId);
    FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, serverLinkId, this, &NFWorkServer::OnServerSocketEvent);
    FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, serverLinkId, this,
                                                     &NFWorkServer::OnHandleServerOtherMessage);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{} Listen Success, ServerId:{}, Ip:{}, Port:{}", pConfig->ServerName, pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);

    if (pConfig->LinkMode == "bus") {
        int iRet = FindModule<NFIMessageModule>()->ResumeConnect(m_serverType);
        if (iRet == 0) {
            std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(
                    m_serverType);
            for (int i = 0; i < (int) vecServer.size(); i++) {
                NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                if (pServerData && pServerData->mUnlinkId > 0) {
                    if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER) {
                        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this, &NFWorkServer::OnRouteAgentServerSocketEvent);
                        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                                         &NFWorkServer::OnHandleRouteAgentServerOtherMessage);

                        auto pRouteServer = FindModule<NFIMessageModule>()->GetRouteData(m_serverType);
                        pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                        pRouteServer->mServerInfo = pServerData->mServerInfo;
                    }
                    else if (pServerData->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER) {
                        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                                         &NFWorkServer::OnProxyAgentServerSocketEvent);
                        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                                         &NFWorkServer::OnHandleProxyAgentServerOtherMessage);
                    }
                }
            }
        }
    }

    return true;
}

bool NFWorkServer::ConnectMasterServer()
{
    if (m_connectMasterServer == false)
    {
        return true;
    }

    //////////////////////master msg//////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFWorkServer::OnHandleServerReportFromMasterServer);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

#if NF_PLATFORM == NF_PLATFORM_WIN
    proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(m_serverType);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->RouteConfig.NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(m_serverType);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    return true;
}

int NFWorkServer::OnServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFWorkServer::OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServer::OnHandleServerDisconnect(uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(m_serverType, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_SYSTEMLOG, 0, "the server:{} disconnect from server:{}, serverName:{}, busid:{}, serverIp:{}, serverPort:{}", pServerData->mServerInfo.server_name(), pConfig->ServerName
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(m_serverType, unLinkId);
    return 0;
}

int NFWorkServer::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);
    auto pMsterServerData = FindModule<NFIMessageModule>()->GetMasterData(m_serverType);
    if (pMsterServerData->mUnlinkId <= 0)
    {
        pMsterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pMsterServerData->mUnlinkId, this, &NFWorkServer::OnMasterSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pMsterServerData->mUnlinkId, this, &NFWorkServer::OnHandleMasterOtherMessage);
    }

    pMsterServerData->mServerInfo = xData;

    return 0;
}

int NFWorkServer::RegisterMasterServer(uint32_t serverState)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);

        pData->set_server_state(serverState);
        FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
    }
    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFWorkServer::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect master success!", pConfig->ServerName);

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
            m_pObjPluginManager->FinishAppTask(m_serverType, APP_INIT_CONNECT_MASTER);
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
int NFWorkServer::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "master server other message not handled:msgId:{}", packet.ToString());
    return 0;
}

int NFWorkServer::OnHandleServerReportFromMasterServer(uint64_t unLinkId, NFDataPackage& packet)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
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
            case NF_SERVER_TYPES::NF_ST_PROXY_AGENT_SERVER:
            {
                OnHandleProxyAgentServerReport(xData);
            }
                break;
            default:
                break;
        }
    }
    return 0;
}

int NFWorkServer::ServerReportToMasterServer()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
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
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(m_serverType, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
        }
    }
    return 0;
}

int NFWorkServer::OnHandleProxyAgentServerReport(const proto_ff::ServerInfoReport& xData)
{
    if (m_connectProxyAgentServer == false)
    {
        return 0;
    }

    //////////////////////proxy server msg//////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFWorkServer::OnServerRegisterProcessFromProxyServer);
    
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
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

        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this, &NFWorkServer::OnProxyAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                         &NFWorkServer::OnHandleProxyAgentServerOtherMessage);
    }
    else {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.url(), xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pServerData->mUnlinkId);

            pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->CreateLinkToServer(m_serverType, xData.bus_id(), pServerData->mUnlinkId);

            FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pServerData->mUnlinkId, this, &NFWorkServer::OnProxyAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pServerData->mUnlinkId, this,
                                                             &NFWorkServer::OnHandleProxyAgentServerOtherMessage);
        }
    }


    pServerData->mServerInfo = xData;
    return 0;
}

int NFWorkServer::OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect proxy agent server success!", pConfig->ServerName);
        RegisterProxyAgentServer(unLinkId);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect proxy agent server", pConfig->ServerName);
    }
    return 0;
}

int NFWorkServer::OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServer::RegisterProxyAgentServer(uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
    }

    return 0;
}

int NFWorkServer::OnServerRegisterProcessFromProxyServer(uint64_t unLinkId, NFDataPackage& packet)
{
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
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


int NFWorkServer::OnHandleProxyServerRegister(const proto_ff::ServerInfoReport& xData, uint64_t unlinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_SERVER, -1, "xData.server_type() == NF_ST_PROXY_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(m_serverType, xData.bus_id());
    if (!pServerData)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_PROXY_SERVER, xData);
    }

    pServerData->mUnlinkId = unlinkId;
    pServerData->mServerInfo = xData;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Proxy Server Register Server:{} Success, serverName:{}, busid:{}, ip:{}, port:{}", pConfig->ServerName, pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.external_server_ip(), pServerData->mServerInfo.external_server_port());
    return 0;
}

int NFWorkServer::OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData)
{
    if (m_checkStoreServer == false)
    {
        return 0;
    }

    FindModule<NFIMessageModule>()->CreateServerByServerId(m_serverType, xData.bus_id(), NF_ST_STORE_SERVER, xData);

    m_pObjPluginManager->FinishAppTask(m_serverType, APP_INIT_NEED_STORE_SERVER);
    return 0;
}

int NFWorkServer::OnHandleRouteAgentServerReport(const proto_ff::ServerInfoReport& xData)
{
    if (m_connectRouteAgentServer == false)
    {
        return 0;
    }

    /////////////////route agent msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(m_serverType, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFWorkServer::OnRegisterRouteAgentServerRspProcess);

    CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.server_id())
    {
        return 0;
    }

    auto pRouteAgentServerData = FindModule<NFIMessageModule>()->GetRouteData(m_serverType);

    if (pRouteAgentServerData->mUnlinkId == 0)
    {
        pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

        FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this, &NFWorkServer::OnRouteAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                         &NFWorkServer::OnHandleRouteAgentServerOtherMessage);
    }
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(m_serverType, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this, &NFWorkServer::OnRouteAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(m_serverType, pRouteAgentServerData->mUnlinkId, this,
                                                             &NFWorkServer::OnHandleRouteAgentServerOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
    return 0;
}

int NFWorkServer::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", m_serverType);

    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, 0, "server:{} connect route agent server success!", pConfig->ServerName);

        RegisterRouteAgentServer(unLinkId);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} disconnect route agent server success", pConfig->ServerName);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFWorkServer::OnHandleRouteAgentServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogWarning(NF_LOG_SYSTEMLOG, 0, "msg:{} not handled!", packet.ToString());
    return 0;
}

int NFWorkServer::RegisterRouteAgentServer(uint64_t unLinkId)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);

        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
    }
    return 0;
}

int NFWorkServer::OnRegisterRouteAgentServerRspProcess(uint64_t unLinkId, NFDataPackage& packet) {
    //完成服务器启动任务
    if (!m_pObjPluginManager->IsInited())
    {
        m_pObjPluginManager->FinishAppTask(m_serverType, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
    }

    FindModule<NFINamingModule>()->RegisterAppInfo(m_serverType);
    return 0;
}




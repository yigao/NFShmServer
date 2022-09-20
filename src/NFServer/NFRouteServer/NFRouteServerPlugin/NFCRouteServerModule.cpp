// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFCRouteServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

#define ROUTE_SERVER_CONNECT_MASTER_SERVER "RouteServer Connect MasterServer"

NFCRouteServerModule::NFCRouteServerModule(NFIPluginManager* p):NFIRouteServerModule(p)
{
}

NFCRouteServerModule::~NFCRouteServerModule()
{
}

bool NFCRouteServerModule::Awake()
{
    //不需要固定帧，需要尽可能跑得快
    m_pObjPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_ROUTE_SERVER);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_ROUTE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this,
                                                       &NFCRouteServerModule::OnServerRegisterProcess);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_ROUTE_SERVER,
                                                       proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFCRouteServerModule::OnHandleServerReport);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_ROUTE_SERVER,
                                                       proto_ff::NF_ROUTER_CMD_INTERNAL_C2R_REG_RAASSOCAPPSVS, this,
                                                       &NFCRouteServerModule::OnHandleServerRegisterRouteAgent);

	//注册要完成的服务器启动任务
	m_pObjPluginManager->RegisterAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_MASTER, ROUTE_SERVER_CONNECT_MASTER_SERVER);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
    if (pConfig) {
        m_pObjPluginManager->SetIdelSleepUs(pConfig->IdleSleepUs);
        int64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_ROUTE_SERVER, pConfig->Url,
                                                                pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0) {
            /*
                注册客户端事件
            */
            uint64_t routeServerLinkId = (uint64_t) unlinkId;
            FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_ROUTE_SERVER, routeServerLinkId);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_SERVER, routeServerLinkId, this,
                                                             &NFCRouteServerModule::OnRouteSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_SERVER, routeServerLinkId, this,
                                                             &NFCRouteServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "route server listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
        } else {
            NFLogInfo(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "route server listen failed, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
            return false;
        }
    }
	else
	{
		NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "I Can't get the Game Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);

	return true;
}

int NFCRouteServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(10000, 10000, 0);
        }
    }

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    return 0;
}

void NFCRouteServerModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}


int NFCRouteServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_ROUTE_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_ROUTE_SERVER, xData.url(),
                                                                     PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCRouteServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCRouteServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "I Can't get the route Server config!");
        return -1;
    }

    return 0;
}

bool NFCRouteServerModule::Init()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_ROUTE_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
    if (pConfig && pConfig->NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_ROUTE_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_ROUTE_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "RouteServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "RouteServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    return true;
}

bool NFCRouteServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCRouteServerModule::OnDynamicPlugin() {
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_ROUTE_SERVER);
    return true;
}

int NFCRouteServerModule::OnRouteSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{

	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		OnHandleServerDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteServerModule::OnHandleServerDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_ROUTE_SERVER,
                                                                                                 unLinkId);
    if (pServerData) {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0,
                   "the server disconnect from route server, serverName:{}, busid:{}, busname:{}. serverIp:{}, serverPort:{}",
                   pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(),
                   pServerData->mServerInfo.server_id(), pServerData->mServerInfo.server_ip(),
                   pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(NF_ST_ROUTE_SERVER, unLinkId);
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteServerModule::OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet) {
    uint32_t fromBusId = GetServerIndexFromUnlinkId(packet.nSrcId);
    uint32_t fromServerType = GetServerTypeFromUnlinkId(packet.nSrcId);

    uint32_t serverType = GetServerTypeFromUnlinkId(packet.nDstId);
    uint32_t destBusId = GetServerIndexFromUnlinkId(packet.nDstId);

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
    CHECK_EXPR(pConfig != NULL, NULL, "pConfig == NULL");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_ROUTE_SERVER, unLinkId);
    CHECK_EXPR(pServerData != NULL, -1, "pServer == NULL");

    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0,
               "--{}:{} trans route agent server({}:{}) msg from {}:{} to {}:{}, packet:{} --", pConfig->ServerName, pConfig->ServerId, pServerData->mServerInfo.server_name(),pServerData->mServerInfo.server_id(),
               GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId), packet.ToString());

    if (destBusId == 0) {
        NF_SHARE_PTR<NFServerData> pRegServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(
                NF_ST_ROUTE_SERVER, (NF_SERVER_TYPES) serverType);
        if (pRegServerData) {
            NF_SHARE_PTR<NFServerData> pRouteAgent = FindModule<NFIMessageModule>()->GetServerByServerId(
                    NF_ST_ROUTE_SERVER, pRegServerData->mRouteAgentBusId);
            if (pRouteAgent) {
                FindModule<NFIMessageModule>()->Send(pRouteAgent->mUnlinkId, packet);
            } else {
                NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "packet:{} trans failed, fromServer:{}:{} to destServer:{}:{}",
                           packet.ToString(), GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId));
            }
        }
    } else {
        NF_SHARE_PTR<NFServerData> pRegServerData = FindModule<NFIMessageModule>()->GetServerByServerId(
                NF_ST_ROUTE_SERVER, destBusId);
        if (pRegServerData) {
            NF_SHARE_PTR<NFServerData> pRouteAgent = FindModule<NFIMessageModule>()->GetServerByServerId(
                    NF_ST_ROUTE_SERVER,
                    pRegServerData->mRouteAgentBusId);
            if (pRouteAgent) {
                FindModule<NFIMessageModule>()->Send(pRouteAgent->mUnlinkId, packet);
            } else {
                NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "packet:{} trans failed, fromServer:{}:{} to destServer:{}:{}",
                           packet.ToString(), GetServerName((NF_SERVER_TYPES) fromServerType),
                           NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId));
            }
        } else {
            NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "can't find destBusId, packet:{} trans failed, fromServer:{}:{} to destServer:{}:{}",
                       packet.ToString(), GetServerName((NF_SERVER_TYPES) fromServerType),
                       NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId));
        }
    }

	return 0;
}

/*
	处理Master服务器链接事件
*/
int NFCRouteServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "route server connect master success!");
		RegisterMasterServer();

		//完成服务器启动任务
		if (!m_pObjPluginManager->IsInited())
		{
			m_pObjPluginManager->FinishAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_MASTER);
		}

        FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_ROUTE_SERVER);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "route server disconnect master success");
	}
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCRouteServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "master server other message not handled:packet:{},ip:{}", packet.ToString(), ip);
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
		pData->set_bus_id(pConfig->BusId);
        pData->set_server_id(pConfig->ServerId);
		pData->set_server_type(pConfig->ServerType);
		pData->set_server_name(pConfig->ServerName);

        pData->set_bus_length(pConfig->BusLength);
        pData->set_link_mode(pConfig->LinkMode);
        pData->set_url(pConfig->Url);
		pData->set_server_ip(pConfig->ServerIp);
		pData->set_server_port(pConfig->ServerPort);
        pData->set_route_svr(pConfig->RouteAgent);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_ROUTE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteServerModule::ServerReport()
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

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
		pData->set_bus_id(pConfig->BusId);
        pData->set_server_id(pConfig->ServerId);
		pData->set_server_type(pConfig->ServerType);
		pData->set_server_name(pConfig->ServerName);

        pData->set_bus_length(pConfig->BusLength);
        pData->set_link_mode(pConfig->LinkMode);
        pData->set_url(pConfig->Url);
		pData->set_server_ip(pConfig->ServerIp);
		pData->set_server_port(pConfig->ServerPort);
        pData->set_route_svr(pConfig->RouteAgent);
		pData->set_server_state(proto_ff::EST_NARMAL);

		NFIMonitorModule* pMonitorModule = m_pObjPluginManager->FindModule<NFIMonitorModule>();
		if (pMonitorModule)
		{
			const NFSystemInfo& systemInfo = pMonitorModule->GetSystemInfo();

			pData->set_system_info(systemInfo.GetOsInfo().mOsDescription);
			pData->set_total_mem(systemInfo.GetMemInfo().mTotalMem);
			pData->set_free_mem(systemInfo.GetMemInfo().mFreeMem);
			pData->set_used_mem(systemInfo.GetMemInfo().mUsedMem);

			pData->set_proc_cpu(systemInfo.GetProcessInfo().mCpuUsed);
			pData->set_proc_mem(systemInfo.GetProcessInfo().mMemUsed);
			pData->set_proc_thread(systemInfo.GetProcessInfo().mThreads);
			pData->set_proc_name(systemInfo.GetProcessInfo().mName);
			pData->set_proc_cwd(systemInfo.GetProcessInfo().mCwd);
			pData->set_proc_pid(systemInfo.GetProcessInfo().mPid);
			pData->set_server_cur_online(systemInfo.GetUserCount());
		}

		if (pData->proc_cpu() > 0 && pData->proc_mem() > 0)
		{
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_ROUTE_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int
NFCRouteServerModule::OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet) {
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        switch (xData.server_type()) {
            case NF_SERVER_TYPES::NF_ST_ROUTE_AGENT_SERVER: {
                OnHandleRouteAgentRegister(xData, unLinkId);
            }
                break;
            default:
                break;
        }
    }
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCRouteServerModule::OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet) {
    return 0;
}

int NFCRouteServerModule::OnHandleServerRegisterRouteAgent(uint64_t unLinkId, NFDataPackage& packet) {
//    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_ROUTE_SERVER, unLinkId);
    CHECK_EXPR(pServerData != NULL, -1, "pServerData == NULL");
    CHECK_EXPR(pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "pServerData server type error");

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pRegServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_ROUTE_SERVER, xData.bus_id());
        if (pRegServerData) {
            if (pRegServerData->mRouteAgentBusId == pServerData->mServerInfo.bus_id()) {
                pRegServerData->mServerInfo = xData;
            } else {
                NF_SHARE_PTR<NFServerData> pOldServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_ROUTE_SERVER,
                                                                                pRegServerData->mRouteAgentBusId);
                if (pOldServerData) {
                    NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "{}({}) has register {}({}), now register {}({})",
                               xData.server_name(), xData.bus_id(),
                               pOldServerData->mServerInfo.server_name(), pOldServerData->mServerInfo.bus_id(),
                               pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id());
                } else {
                    NFLogError(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "{}({}) has register {}(can't find), now register {}({})",
                               xData.server_name(), xData.bus_id(),
                               pRegServerData->mRouteAgentBusId,
                               pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id());
                }

                pRegServerData->mRouteAgentBusId = pServerData->mServerInfo.bus_id();
                pRegServerData->mServerInfo = xData;
            }
        } else {
            pRegServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_ROUTE_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
            pRegServerData->mRouteAgentBusId = pServerData->mServerInfo.bus_id();
            pRegServerData->mServerInfo = xData;

            NFLogInfo(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "{}({}) register route agent:{}({}) trans to route svr success",
                       pRegServerData->mServerInfo.server_name(), pRegServerData->mServerInfo.server_id(),
                       pServerData->mServerInfo.server_name(), pServerData->mServerInfo.server_id());
        }
    }

//    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

//游戏服务器注册协议回调
int NFCRouteServerModule::OnHandleRouteAgentRegister(const proto_ff::ServerInfoReport &xData, uint64_t unlinkId) {
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_ROUTE_SERVER, xData.bus_id());
    if (!pServerData) {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_ROUTE_SERVER, xData.bus_id(), NF_ST_ROUTE_AGENT_SERVER, xData);
    }

    pServerData->mUnlinkId = unlinkId;
    pServerData->mServerInfo = xData;

    FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_ROUTE_SERVER, xData.bus_id(), pServerData->mUnlinkId);

    NFLogInfo(NF_LOG_ROUTE_SERVER_PLUGIN, 0,
              "Route Agent Server Register Route Server Success, serverName:{}, busid:{}, busname:{}, ip:{}, port:{}",
              pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(),
              pServerData->mServerInfo.server_id(), pServerData->mServerInfo.server_ip(),
              pServerData->mServerInfo.server_port());
    NFLogTrace(NF_LOG_ROUTE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}




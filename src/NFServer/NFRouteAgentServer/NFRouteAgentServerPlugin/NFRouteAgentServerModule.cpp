// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFRouteAgentServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"

#define ROUTEAGENT_SERVER_CONNECT_MASTER_SERVER "RouteAgentServer Connect MasterServer"
#define ROUTEAGENT_SERVER_CONNECT_ROUTE_SERVER "RouteAgentServer Connect RouteServer"

NFCRouteAgentServerModule::NFCRouteAgentServerModule(NFIPluginManager* p):NFIRouteAgentServerModule(p)
{
}

NFCRouteAgentServerModule::~NFCRouteAgentServerModule()
{
}

bool NFCRouteAgentServerModule::Awake()
{
    //不需要固定帧，需要尽可能跑得快
    m_pPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_ROUTE_AGENT_SERVER);

    /////////////master msg/////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER,
                                                       this, &NFCRouteAgentServerModule::OnServerRegisterProcess);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_ROUTE_AGENT_SERVER,
                                                       proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFCRouteAgentServerModule::OnHandleServerReport);

	//注册要完成的服务器启动任务
	m_pPluginManager->RegisterAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_MASTER, ROUTEAGENT_SERVER_CONNECT_MASTER_SERVER);
	m_pPluginManager->RegisterAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_ROUTE_SERVER, ROUTEAGENT_SERVER_CONNECT_ROUTE_SERVER);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig) {
        m_pPluginManager->SetIdelSleepUs(pConfig->mIdleSleepUs);
		int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_ROUTE_AGENT_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
		if (unlinkId >= 0)
		{
			/*
				注册客户端事件
			*/
			uint64_t routeAgentServerLinkId = (uint64_t)unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId);
			NFMessageMgr::Instance()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId, this,
                                                             &NFCRouteAgentServerModule::OnRouteAgentSocketEvent);
			NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId, this, &NFCRouteAgentServerModule::OnHandleOtherMessage);
			NFLogInfo(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
		}
		else
		{
			NFLogInfo(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent listen failed, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
			return false;
		}

        if (pConfig->mLinkMode == "bus") {
            NFMessageMgr::Instance()->ResumeConnect(NF_ST_ROUTE_AGENT_SERVER);
        }
	}
	else
	{
		NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "I Can't get the Game Server config!");
		return false;
	}

	SetTimer(1, 60000);
    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCRouteAgentServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_ROUTE_AGENT_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pMasterServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pMasterServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "I Can't get the Route Agent Server config!");
        return -1;
    }

    return 0;
}

bool NFCRouteAgentServerModule::Init()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_ROUTE_AGENT_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig && pConfig->mNamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_ROUTE_AGENT_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_ROUTE_AGENT_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "RouteAgentServer Watch MasterServer name:{} serverInfo:{} errCode:{}", name, xData.DebugString(), errCode);

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "RouteAgentServer Watch MasterServer name:{} serverInfo:{} errCode:{}", name, xData.DebugString(), errCode);

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "RouteAgentServer Watch RouteServer name:{} serverInfo:{} errCode:{}", name, xData.DebugString(), errCode);
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "RouteAgentServer Watch RouteServer name:{} serverInfo:{} errCode:{}", name, xData.DebugString(), errCode);

        OnHandleRouteServerReport(xData);
    });

    return true;
}

bool NFCRouteAgentServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCRouteAgentServerModule::OnDynamicPlugin()
{
	NFMessageMgr::Instance()->CloseAllLink(NF_ST_ROUTE_AGENT_SERVER);
	return true;
}

void NFCRouteAgentServerModule::OnTimer(uint32_t nTimerID) {
    RegisterAllServerInfoToRouteSvr();

    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCRouteAgentServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(10000, 10000, 0);
        }
    }
    return 0;
}

int NFCRouteAgentServerModule::OnRouteAgentSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{

	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		OnHandleServerDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int
NFCRouteAgentServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t sendLinkId, uint64_t destLinkId,
                                                uint32_t nMsgId, const char *msg,
                                                uint32_t nLen) {
    uint32_t fromBusId = GetServerIndexFromUnlinkId(sendLinkId);
    uint32_t fromServerType = GetServerTypeFromUnlinkId(sendLinkId);

    uint32_t serverType = GetServerTypeFromUnlinkId(destLinkId);
    uint32_t destBusId = GetServerIndexFromUnlinkId(destLinkId);

    NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0,
               "-- trans msg from {}:{} to {}:{}, msgId:{} --",
               GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId), nMsgId);

    if (destBusId == 0) {
        NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetRandomServerByServerType(
                NF_ST_ROUTE_AGENT_SERVER, (NF_SERVER_TYPES) serverType);
        if (pServerData) {
            NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId,
                                  0);
        } else {
            auto pRouteServerData = NFMessageMgr::Instance()->GetRandomServerByServerType(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);
            CHECK_NULL(pRouteServerData);
            NFMessageMgr::Instance()->Send(pRouteServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId,
                                                 destLinkId);
        }
    } else {
        NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(
                NF_ST_ROUTE_AGENT_SERVER, destBusId);
        if (pServerData) {
            NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId, 0);
        } else {
            auto pRouteServerData = NFMessageMgr::Instance()->GetRandomServerByServerType(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);
            CHECK_NULL(pRouteServerData);
            NFMessageMgr::Instance()->Send(pRouteServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId,
                                                 destLinkId);
        }
    }

    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFCRouteAgentServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent server connect master success!");
		RegisterMasterServer();

		//完成服务器启动任务
		if (!m_pPluginManager->IsInited())
		{
			m_pPluginManager->FinishAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent server disconnect master success");
	}
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCRouteAgentServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteAgentServerModule::RegisterMasterServer()
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
		pData->set_bus_id(pConfig->mBusId);
		pData->set_bus_name(pConfig->mBusName);
		pData->set_server_type(pConfig->mServerType);
		pData->set_server_name(pConfig->mServerName);

        pData->set_bus_length(pConfig->mBusLength);
        pData->set_link_mode(pConfig->mLinkMode);
        pData->set_url(pConfig->mUrl);
		pData->set_server_ip(pConfig->mServerIp);
		pData->set_server_port(pConfig->mServerPort);
        pData->set_route_svr(pConfig->mRouteAgent);
		pData->set_server_state(proto_ff::EST_NARMAL);

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	return 0;
}

int NFCRouteAgentServerModule::ServerReport()
{
	if (m_pPluginManager->IsLoadAllServer())
	{
		return 0;
	}

	static uint64_t mLastReportTime = m_pPluginManager->GetNowTime();
	if (mLastReportTime + 100000 > m_pPluginManager->GetNowTime())
	{
		return 0;
	}

	mLastReportTime = m_pPluginManager->GetNowTime();

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
		pData->set_bus_id(pConfig->mBusId);
		pData->set_bus_name(pConfig->mBusName);
		pData->set_server_type(pConfig->mServerType);
		pData->set_server_name(pConfig->mServerName);

        pData->set_bus_length(pConfig->mBusLength);
        pData->set_link_mode(pConfig->mLinkMode);
        pData->set_url(pConfig->mUrl);
		pData->set_server_ip(pConfig->mServerIp);
		pData->set_server_port(pConfig->mServerPort);
        pData->set_route_svr(pConfig->mRouteAgent);
		pData->set_server_state(proto_ff::EST_NARMAL);

		NFIMonitorModule* pMonitorModule = m_pPluginManager->FindModule<NFIMonitorModule>();
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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCRouteAgentServerModule::OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen) {
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(
                NF_ST_ROUTE_AGENT_SERVER, xData.bus_id());
        if (pServerData == nullptr) {
            pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_ROUTE_AGENT_SERVER,
                                                                                 xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
        }

        pServerData->mUnlinkId = unLinkId;
        pServerData->mServerInfo = xData;
        NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(),
                                                           pServerData->mUnlinkId);
        NFLogDebug(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "Server:{} Register Route Agent Server Success",
                   xData.server_name());

        proto_ff::ServerInfoReportList rsp;
        NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, rsp,
                                             0);

        ::proto_ff::ServerInfoReport *pReport = rsp.add_server_list();
        *pReport = xData;
        RegisterServerInfoToRouteSvr(rsp);
    }
    return 0;
}

int NFCRouteAgentServerModule::OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);


	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		switch (xData.server_type())
		{
		case NF_SERVER_TYPES::NF_ST_ROUTE_SERVER:
		{
			OnHandleRouteServerReport(xData);
		}
		break;
		default:
			break;
		}
	}
	return 0;
}

int NFCRouteAgentServerModule::OnHandleRouteServerReport(const proto_ff::ServerInfoReport& xData)
{
	CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_SERVER");

	auto pRouteServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id());

	if (pRouteServerData == NULL)
	{
        pRouteServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), NF_ST_ROUTE_SERVER, xData);

        pRouteServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), pRouteServerData->mUnlinkId);

		NFMessageMgr::Instance()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnRouteServerSocketEvent);
		NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleRouteOtherMessage);
	}
	else {
        if (pRouteServerData->mUnlinkId > 0 && pRouteServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pRouteServerData->mServerInfo.server_name(), pRouteServerData->mServerInfo.url(), xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pRouteServerData->mUnlinkId);

            pRouteServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), pRouteServerData->mUnlinkId);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnRouteServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleRouteOtherMessage);
        }
	}

    pRouteServerData->mServerInfo = xData;
	return 0;
}

int NFCRouteAgentServerModule::OnRouteServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent server connect route server success!");

		RegisterRouteServer(unLinkId);

		//完成服务器启动任务
		if (!m_pPluginManager->IsInited())
		{
			m_pPluginManager->FinishAppTask(NF_ST_MASTER_SERVER, APP_INIT_CONNECT_ROUTE_SERVER);
		}

        FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_ROUTE_AGENT_SERVER);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "route agent server disconnect route server success");
	}
	return 0;
}

int NFCRouteAgentServerModule::OnHandleRouteOtherMessage(uint64_t unLinkId, uint64_t sendLinkId, uint64_t destLinkId, uint32_t nMsgId, const char* msg, uint32_t nLen) {
    uint32_t fromBusId = GetServerIndexFromUnlinkId(sendLinkId);
    uint32_t fromServerType = GetServerTypeFromUnlinkId(sendLinkId);

    uint32_t serverType = GetServerTypeFromUnlinkId(destLinkId);
    uint32_t destBusId = GetServerIndexFromUnlinkId(destLinkId);

    NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0,
               "-- trans msg from {}:{} to {}:{}, msgId:{} --",
               GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId), nMsgId);

    if (destBusId == 0) {
        NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetRandomServerByServerType(
                NF_ST_ROUTE_AGENT_SERVER, (NF_SERVER_TYPES) serverType);
        if (pServerData) {
            NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId,
                                  0);
        } else {
            NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0,
                       "the route agent can't find the server, busid:{}, server:{} trans msg:{} failed", destBusId,
                       GetServerName((NF_SERVER_TYPES) serverType), nMsgId);
        }
    } else {
        NF_SHARE_PTR<NFServerData> pServerData  = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_ROUTE_AGENT_SERVER, destBusId);
        if (pServerData)
        {
            NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, sendLinkId, 0);
        } else {
            NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0,
                       "the route agent can't find the server, busid:{}, server:{} trans msg:{} failed", destBusId,
                       GetServerName((NF_SERVER_TYPES) serverType), nMsgId);
        }
    }
	return 0;
}

int NFCRouteAgentServerModule::RegisterRouteServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
		pData->set_bus_id(pConfig->mBusId);
		pData->set_bus_name(pConfig->mBusName);
		pData->set_server_type(pConfig->mServerType);
		pData->set_server_name(pConfig->mServerName);

        pData->set_bus_length(pConfig->mBusLength);
        pData->set_link_mode(pConfig->mLinkMode);
        pData->set_url(pConfig->mUrl);
		pData->set_server_ip(pConfig->mServerIp);
		pData->set_server_port(pConfig->mServerPort);
        pData->set_route_svr(pConfig->mRouteAgent);
		pData->set_server_state(proto_ff::EST_NARMAL);

		NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);

        RegisterAllServerInfoToRouteSvr();
	}
	NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCRouteAgentServerModule::RegisterServerInfoToRouteSvr(const proto_ff::ServerInfoReportList& xData)
{
    //NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");
    std::vector<NF_SHARE_PTR<NFServerData>> vec = NFMessageMgr::Instance()->GetAllServer(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);//GetRouteData(NF_ST_ROUTE_AGENT_SERVER);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pRouteServerData = vec[i];
        if (pRouteServerData && pRouteServerData->mUnlinkId > 0)
        {
            NFMessageMgr::Instance()->Send(pRouteServerData->mUnlinkId, proto_ff::NF_ROUTER_CMD_INTERNAL_C2R_REG_RAASSOCAPPSVS, xData, 0);
        }
    }

    //NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCRouteAgentServerModule::RegisterAllServerInfoToRouteSvr() {
    proto_ff::ServerInfoReportList xData;
    std::vector<NF_SHARE_PTR<NFServerData>> vec = NFMessageMgr::Instance()->GetAllServer(NF_ST_ROUTE_AGENT_SERVER);
    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pRouteServerData = vec[i];
        if (pRouteServerData)
        {
            if (pRouteServerData->mServerInfo.server_type() != NF_ST_MASTER_SERVER &&
                    pRouteServerData->mServerInfo.server_type() != NF_ST_ROUTE_SERVER &&
                    pRouteServerData->mServerInfo.server_type() != NF_ST_ROUTE_AGENT_SERVER)
            {
                auto pData = xData.add_server_list();
                *pData = pRouteServerData->mServerInfo;
            }
        }
    }
    RegisterServerInfoToRouteSvr(xData);
    return 0;
}

int NFCRouteAgentServerModule::OnHandleServerDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(
            NF_ST_ROUTE_AGENT_SERVER, unLinkId);
    if (pServerData) {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0,
                   "the {0} disconnect from route agent server, serverName:{0}, busid:{1}, serverIp:{2}, serverPort:{3}",
                   pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(),
                   pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    NFMessageMgr::Instance()->DelServerLink(NF_ST_ROUTE_AGENT_SERVER, unLinkId);
    NFLogTrace(NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


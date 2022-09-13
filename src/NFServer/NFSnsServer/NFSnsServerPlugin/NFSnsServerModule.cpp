// -------------------------------------------------------------------------
//    @FileName         :    NFCSnsServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFSnsServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"

#define SNS_SERVER_CONNECT_MASTER_SERVER "SnsServer Connect MasterServer"
#define SNS_SERVER_CONNECT_ROUTEAGENT_SERVER "SnsServer Connect RouteAgentServer"
#define SNS_SERVER_CHECK_STORE_SERVER "SnsServer CHECK StoreServer"

NFCSnsServerModule::NFCSnsServerModule(NFIPluginManager* p):NFISnsServerModule(p)
{
}

NFCSnsServerModule::~NFCSnsServerModule()
{
}

bool NFCSnsServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_SNS_SERVER);
	///////////////////////////master msg//////////////////////////////
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFCSnsServerModule::OnHandleServerReport);

    /////////////////route agent msg///////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_SNS_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCSnsServerModule::OnRegisterRouteAgentRspProcess);

	//注册要完成的服务器启动任务
	m_pPluginManager->RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_CONNECT_MASTER, SNS_SERVER_CONNECT_MASTER_SERVER);
	m_pPluginManager->RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, SNS_SERVER_CONNECT_ROUTEAGENT_SERVER);
    m_pPluginManager->RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_NEED_STORE_SERVER, SNS_SERVER_CHECK_STORE_SERVER);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
	if (pConfig)
	{
		if (!m_pPluginManager->IsLoadAllServer())
		{
			if (pConfig->mServerType != NF_ST_SNS_SERVER)
			{
				NFLogError(NF_LOG_SNS_SERVER_PLUGIN, 0, "server config error, server id not match the server type!");
				exit(0);
			}
		}

        int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_SNS_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            /*
                注册客户端事件
            */
            uint64_t logicServerLinkId = (uint64_t)unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_SNS_SERVER, logicServerLinkId);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_SNS_SERVER, logicServerLinkId, this, &NFCSnsServerModule::OnSnsSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_SNS_SERVER, logicServerLinkId, this, &NFCSnsServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_SNS_SERVER_PLUGIN, 0, "sns server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_SNS_SERVER_PLUGIN, 0, "sns server listen failed, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }

        if (pConfig->mLinkMode == "bus") {
            int iRet = NFMessageMgr::Instance()->ResumeConnect(NF_ST_SNS_SERVER);
            if (iRet == 0) {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(
                        NF_ST_SNS_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++) {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0) {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER) {
                            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_SNS_SERVER, pServerData->mUnlinkId, this, &NFCSnsServerModule::OnRouteAgentServerSocketEvent);
                            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_SNS_SERVER, pServerData->mUnlinkId, this, &NFCSnsServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = NFMessageMgr::Instance()->GetRouteData(NF_ST_SNS_SERVER);
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
		NFLogError(NF_LOG_SNS_SERVER_PLUGIN, 0, "I Can't get the Sns Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);

	return true;
}

int NFCSnsServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

void NFCSnsServerModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCSnsServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
    if (pConfig)
    {
        auto pMsterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_SNS_SERVER);
        if (pMsterServerData->mUnlinkId <= 0)
        {
            pMsterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_SNS_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_SNS_SERVER, pMsterServerData->mUnlinkId, this, &NFCSnsServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_SNS_SERVER, pMsterServerData->mUnlinkId, this, &NFCSnsServerModule::OnHandleMasterOtherMessage);
        }

        pMsterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_SNS_SERVER_PLUGIN, 0, "I Can't get the Sns Server config!");
        return -1;
    }

    return 0;
}

bool NFCSnsServerModule::Init()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_SNS_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->mNamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_SNS_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_SNS_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "SnServer Watch, MasterServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SnServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });


    if (pConfig->mLinkMode == "bus")
    {
        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_SNS_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "SnServer Watch AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SnServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }
    else
    {
        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_SNS_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "SnServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SnServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_SNS_SERVER, NF_ST_STORE_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "SnServer Watch, StoreServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            auto pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_SNS_SERVER, xData.bus_id());
            if (pServerData)
            {
                NFMessageMgr::Instance()->CloseServer(NF_ST_SNS_SERVER, NF_ST_STORE_SERVER, xData.bus_id(), 0);
            }
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SnServer Watch StoreServer name:{} serverInfo:{}", name, xData.DebugString());

		OnHandleStoreServerReport(xData);
    });
    return true;
}

bool NFCSnsServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCSnsServerModule::OnDynamicPlugin()
{
    NFMessageMgr::Instance()->CloseAllLink(NF_ST_SNS_SERVER);
	return true;
}

/*
	处理Master服务器链接事件
*/
int NFCSnsServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_SNS_SERVER_PLUGIN, 0, "sns server connect master success!");
		RegisterMasterServer();

		//完成服务器启动任务
		if (!m_pPluginManager->IsInited())
		{
			m_pPluginManager->FinishAppTask(NF_ST_SNS_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_SNS_SERVER_PLUGIN, 0, "sns server disconnect master success");
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCSnsServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_SNS_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

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
		case NF_SERVER_TYPES::NF_ST_STORE_SERVER:
		{
			OnHandleStoreServerReport(xData);
		}
		break;
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
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

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_SNS_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::ServerReport()
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

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_SNS_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCSnsServerModule::OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData)
{
    NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_SNS_SERVER, xData.bus_id(), NF_ST_STORE_SERVER, xData);

	m_pPluginManager->FinishAppTask(NF_ST_SNS_SERVER, APP_INIT_NEED_STORE_SERVER);
	return 0;
}

int NFCSnsServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_NULL(pConfig);

    if (!m_pPluginManager->IsLoadAllServer())
    {
        if (pConfig->mRouteAgent != xData.bus_name())
        {
            return 0;
        }
    }

	auto pRouteAgentServerData = NFMessageMgr::Instance()->GetRouteData(NF_ST_SNS_SERVER);

	if (pRouteAgentServerData->mUnlinkId == 0)
	{
        pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_SNS_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

		NFMessageMgr::Instance()->AddEventCallBack(NF_ST_SNS_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCSnsServerModule::OnRouteAgentServerSocketEvent);
		NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_SNS_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCSnsServerModule::OnHandleRouteAgentOtherMessage);
	}
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_SNS_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_SNS_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCSnsServerModule::OnRouteAgentServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_SNS_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCSnsServerModule::OnHandleRouteAgentOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_SNS_SERVER_PLUGIN, 0, "login server connect route agent server success!");

		RegisterRouteAgentServer(unLinkId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_SNS_SERVER_PLUGIN, 0, "login server disconnect route agent server success");
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_SNS_SERVER_PLUGIN, playerId, "msg:{} not handled!", nMsgId);
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCSnsServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
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
	}
	NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCSnsServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId,
                                                         const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
	//完成服务器启动任务
	if (!m_pPluginManager->IsInited())
	{
		m_pPluginManager->FinishAppTask(NF_ST_SNS_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
	}

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_SNS_SERVER);
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCSnsServerModule::OnSnsSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {

    }
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCSnsServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


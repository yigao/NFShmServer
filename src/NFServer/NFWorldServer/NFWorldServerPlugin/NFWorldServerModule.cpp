// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFWorldServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFServer/NFCommHead/NFIWorldPlayerModule.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"

#define WORLD_SERVER_CONNECT_MASTER_SERVER "WorldServer Connect MasterServer"
#define WORLD_SERVER_CONNECT_ROUTEAGENT_SERVER "WorldServer Connect RouteAgentServer"
#define WORLD_SERVER_CHECK_STORE_SERVER "WorldServer CHECK StoreServer"

NFCWorldServerModule::NFCWorldServerModule(NFIPluginManager* p):NFIWorldServerModule(p)
{
}

NFCWorldServerModule::~NFCWorldServerModule()
{
}

bool NFCWorldServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_WORLD_SERVER);
    ///////////////////master server msg//////////////////////////////////
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCWorldServerModule::OnServerRegisterProcess);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFCWorldServerModule::OnHandleServerReport);

	/////////////////route agent msg///////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCWorldServerModule::OnRegisterRouteAgentRspProcess);

	/////////////////route agent msg///////////////////////////////////////

	//注册要完成的服务器启动任务
	m_pPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_MASTER, WORLD_SERVER_CONNECT_MASTER_SERVER);
	m_pPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, WORLD_SERVER_CONNECT_ROUTEAGENT_SERVER);
	m_pPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_NEED_STORE_SERVER, WORLD_SERVER_CHECK_STORE_SERVER);

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
	if (pConfig)
	{
        int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_WORLD_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            /*
                注册客户端事件
            */
            uint64_t worldServerLinkId = (uint64_t)unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_WORLD_SERVER, worldServerLinkId);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, worldServerLinkId, this, &NFCWorldServerModule::OnProxySocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, worldServerLinkId, this, &NFCWorldServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server listen failed, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }


        if (pConfig->mLinkMode == "bus") {
            int iRet = NFMessageMgr::Instance()->ResumeConnect(NF_ST_WORLD_SERVER);
            if (iRet == 0) {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(
                        NF_ST_WORLD_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++) {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0) {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER) {
                            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
                            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = NFMessageMgr::Instance()->GetRouteData(NF_ST_WORLD_SERVER);
                            pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                            pRouteServer->mServerInfo = pServerData->mServerInfo;
                        }
                        else if (pServerData->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER) {
                            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this,
                                                                       &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
                            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this,
                                                                       &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
                        }
                    }
                }
            }
        }
	}
	else
	{
		NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "I Can't get the world Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCWorldServerModule::OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, playerId, "msgId:{} not handle", nMsgId);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_WORLD_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "the server disconnect from world server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    NFMessageMgr::Instance()->DelServerLink(NF_ST_WORLD_SERVER, unLinkId);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

void NFCWorldServerModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCWorldServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_WORLD_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pMasterServerData->mUnlinkId, this, &NFCWorldServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pMasterServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "I Can't get the world Server config!");
        return -1;
    }

    return 0;
}

bool NFCWorldServerModule::Init()
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
	NF_ASSERT(pConfig);
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_WORLD_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
	if (pConfig->mNamingHost.empty())
	{
		proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_WORLD_SERVER);
		int32_t ret = ConnectMasterServer(masterData);
		CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
	}
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch, MasterServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t retCode = ConnectMasterServer(xData);
        CHECK_EXPR(retCode == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    if (pConfig->mLinkMode == "bus")
    {
        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_WORLD_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });

        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_WORLD_SERVER, NF_ST_PROXY_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch ProxyAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch ProxyAgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleProxyAgentReport(xData);
        });
    }
    else
    {
        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });

        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_PROXY_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch, ProxyAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch ProxyAgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleProxyAgentReport(xData);
        });
    }

	FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_STORE_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode) {
		if (errCode != 0)
		{
			NFLogError(NF_LOG_SYSTEMLOG, 0, "World Server Watch, StoreServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
			return;
		}
		NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch StoreServer name:{} serverInfo:{}", name, xData.DebugString());

		OnHandleStoreServerReport(xData);
	});

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_GAME_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode) {
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "World Server Watch, GameServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            FireExecute(proto_ff::NF_EVENT_GAME_SERVER_DUMP_EVENT, xData.bus_id(), proto_ff::NF_EVENT_SERVER_TYPE, xData);
            return;
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch GameServer name:{} serverInfo:{}", name, xData.DebugString());
    });

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode) {
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "World Server Watch, LogicServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            FireExecute(proto_ff::NF_EVENT_LOGIC_SERVER_DUMP_EVENT, xData.bus_id(), proto_ff::NF_EVENT_SERVER_TYPE, xData);
            return;
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "WorldServer Watch LogicServer name:{} serverInfo:{}", name, xData.DebugString());

        OnHandleLogicReport(xData);
    });

    return true;
}

int NFCWorldServerModule::OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData)
{
	NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_STORE_SERVER, xData);

	m_pPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_NEED_STORE_SERVER);
	return 0;
}

bool NFCWorldServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCWorldServerModule::OnDynamicPlugin()
{
    NFMessageMgr::Instance()->CloseAllLink(NF_ST_WORLD_SERVER);
	return true;
}

/*
	处理Master服务器链接事件
*/
int NFCWorldServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server connect master success!");
		RegisterMasterServer();

		//完成服务器启动任务
		if (!m_pPluginManager->IsInited())
		{
			m_pPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server disconnect master success");
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCWorldServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
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

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::ServerReport()
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

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
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
		pData->set_server_state(proto_ff::EST_NARMAL);
        pData->set_route_svr(pConfig->mRouteAgent);
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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCWorldServerModule::OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		switch (xData.server_type())
		{
		case NF_SERVER_TYPES::NF_ST_PROXY_SERVER:
		{
			OnHandleProxyRegister(xData, unLinkId);
		}
		break;
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

//游戏服务器注册协议回调
int NFCWorldServerModule::OnHandleProxyRegister(const proto_ff::ServerInfoReport& xData, uint64_t unlinkId)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_PROXY_SERVER, -1, "xData.server_type() == NF_ST_PROXY_SERVER");

	NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
	if (!pServerData)
	{
		pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_PROXY_SERVER, xData);
	}

	pServerData->mUnlinkId = unlinkId;
	pServerData->mServerInfo = xData;

	NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "Proxy Server Register World Server Success, serverName:{}, busname:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_name(), pServerData->mServerInfo.external_server_ip(), pServerData->mServerInfo.external_server_port());
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

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
        case NF_SERVER_TYPES::NF_ST_LOGIC_SERVER:
        {
            OnHandleLogicReport(xData);
        }
        break;
		case NF_SERVER_TYPES::NF_ST_STORE_SERVER:
		{
			OnHandleStoreServerReport(xData);
		}
		break;
        case NF_SERVER_TYPES::NF_ST_PROXY_AGENT_SERVER:
        {
            OnHandleProxyAgentReport(xData);
        }
        break;
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnHandleLogicReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_LOGIC_SERVER, -1, "xData.server_type() == NF_ST_LOGIC_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (!pServerData)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_LOGIC_SERVER, xData);
    }

    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pConfig);

    if (pConfig->mRouteAgent != xData.bus_name())
    {
        return 0;
    }

    auto pRouteAgentServerData = NFMessageMgr::Instance()->GetRouteData(NF_ST_WORLD_SERVER);

	if (pRouteAgentServerData->mUnlinkId == 0)
	{
        pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

		NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
		NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);
	}
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);;
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server connect route agent server success!");

		RegisterRouteAgentServer(unLinkId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server disconnect route agent server success");
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, playerId, "msg:{} not handled!", nMsgId);
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
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
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	//完成服务器启动任务
	if (!m_pPluginManager->IsInited())
	{
		m_pPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
	}

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_WORLD_SERVER);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


int NFCWorldServerModule::OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pConfig);

    if (pConfig->mRouteAgent != xData.route_svr())
    {
        return 0;
    }

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);

        pServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_WORLD_SERVER, xData.bus_id(), pServerData->mUnlinkId);

        NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
        NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
    }
    else {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.url(), xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pServerData->mUnlinkId);

            pServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_WORLD_SERVER, xData.bus_id(), pServerData->mUnlinkId);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
        }
    }


    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
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

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server connect proxy agent server success!");
        RegisterProxyAgentServer(unLinkId);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server disconnect proxy agent server");
    }
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleProxyAgentOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t busId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, playerId, "msg:{} not handled!", nMsgId);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

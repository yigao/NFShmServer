// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFWorldServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

#define WORLD_SERVER_CONNECT_MASTER_SERVER "WorldServer Connect MasterServer"
#define WORLD_SERVER_CONNECT_ROUTEAGENT_SERVER "WorldServer Connect RouteAgentServer"
#define WORLD_SERVER_CHECK_STORE_SERVER "WorldServer CHECK StoreServer"

NFCWorldServerModule::NFCWorldServerModule(NFIPluginManager* p):NFIWorldServerModule(p)
{
    m_allMsgCheckFunc= NULL;
}

NFCWorldServerModule::~NFCWorldServerModule()
{
}

bool NFCWorldServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_WORLD_SERVER);
    ///////////////////master server msg//////////////////////////////////
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCWorldServerModule::OnServerRegisterProcess);
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFCWorldServerModule::OnHandleServerReport);

	/////////////////route agent msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCWorldServerModule::OnRegisterRouteAgentRspProcess);

	/////////////////test other server msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, this, &NFCWorldServerModule::OnHandleTestOtherServerMsg);

	//注册要完成的服务器启动任务
	m_pObjPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_MASTER, WORLD_SERVER_CONNECT_MASTER_SERVER);
	m_pObjPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, WORLD_SERVER_CONNECT_ROUTEAGENT_SERVER);
	m_pObjPluginManager->RegisterAppTask(NF_ST_WORLD_SERVER, APP_INIT_NEED_STORE_SERVER, WORLD_SERVER_CHECK_STORE_SERVER);

    FindModule<NFIMessageModule>()->AddAllMsgCallBack(NF_ST_WORLD_SERVER, this, &NFCWorldServerModule::OnCheckWorldServerAllMessage);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
	if (pConfig)
	{
        int64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_WORLD_SERVER, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            /*
                注册客户端事件
            */
            uint64_t worldServerLinkId = (uint64_t)unlinkId;
            FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_WORLD_SERVER, worldServerLinkId);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, worldServerLinkId, this, &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, worldServerLinkId, this, &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
            NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server listen success, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server listen failed, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
            return false;
        }


        if (pConfig->LinkMode == "bus") {
            int iRet = FindModule<NFIMessageModule>()->ResumeConnect(NF_ST_WORLD_SERVER);
            if (iRet == 0) {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(
                        NF_ST_WORLD_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++) {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0) {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER) {
                            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
                            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_WORLD_SERVER);
                            pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                            pRouteServer->mServerInfo = pServerData->mServerInfo;
                        }
                        else if (pServerData->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER) {
                            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this,
                                                                       &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
                            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this,
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
    Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, NF_ST_WORLD_SERVER, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCWorldServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

bool NFCWorldServerModule::AddProxyMsgCheckCallBack(const NET_RECEIVE_FUNCTOR &functor)
{
    m_allMsgCheckFunc = functor;
    return true;
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
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_WORLD_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pMasterServerData->mUnlinkId, this, &NFCWorldServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pMasterServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleMasterOtherMessage);
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
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
	NF_ASSERT(pConfig);
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_WORLD_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
	if (pConfig->RouteConfig.NamingHost.empty())
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

    if (pConfig->LinkMode == "bus")
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
	FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_STORE_SERVER, xData);

	m_pObjPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_NEED_STORE_SERVER);
	return 0;
}

bool NFCWorldServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCWorldServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_WORLD_SERVER);
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
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server connect master success!");
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
			m_pObjPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_WORLD_SERVER_PLUGIN, 0, "world server disconnect master success");
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCWorldServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "master server other message not handled:msgId:{},ip:{}", packet.ToString(), ip);
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::RegisterMasterServer(uint32_t serverState)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(serverState);

		FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::ServerReport()
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

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
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
			FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_WORLD_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCWorldServerModule::OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

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

	NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
	if (!pServerData)
	{
		pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_PROXY_SERVER, xData);
	}

	pServerData->mUnlinkId = unlinkId;
	pServerData->mServerInfo = xData;

	NFLogInfo(NF_LOG_WORLD_SERVER_PLUGIN, 0, "Proxy Server Register World Server Success, serverName:{}, ServerId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.server_id(), pServerData->mServerInfo.external_server_ip(), pServerData->mServerInfo.external_server_port());
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

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

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (!pServerData)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_LOGIC_SERVER, xData);
    }

    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.server_id())
    {
        return 0;
    }

    auto pRouteAgentServerData = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_WORLD_SERVER);

	if (pRouteAgentServerData->mUnlinkId == 0)
	{
        pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

		FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
		FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);
	}
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnRouteAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleRouteAgentOtherMessage);;
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

int NFCWorldServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
	}
	NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCWorldServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
	//完成服务器启动任务
	if (!m_pObjPluginManager->IsInited())
	{
		m_pObjPluginManager->FinishAppTask(NF_ST_WORLD_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
	}

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_WORLD_SERVER);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


int NFCWorldServerModule::OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.route_svr())
    {
        return 0;
    }

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);

        pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_WORLD_SERVER, xData.bus_id(), pServerData->mUnlinkId);

        FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
        FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
    }
    else {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.url(), xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pServerData->mUnlinkId);

            pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_WORLD_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_WORLD_SERVER, xData.bus_id(), pServerData->mUnlinkId);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnProxyAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_WORLD_SERVER, pServerData->mUnlinkId, this, &NFCWorldServerModule::OnHandleProxyAgentOtherMessage);
        }
    }


    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
        pData->set_server_state(proto_ff::EST_NARMAL);

        FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
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

int NFCWorldServerModule::OnHandleProxyAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnCheckWorldServerAllMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    if (packet.nMsgId == proto_ff::NF_SERVER_TO_SERVER_REGISTER ||
        packet.nMsgId == proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER ||
        packet.nMsgId == proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP)
    {
        return 0;
    }

    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_allMsgCheckFunc)
    {
        return m_allMsgCheckFunc(unLinkId, packet);
    }
    return 0;
}

int NFCWorldServerModule::OnHandleTestOtherServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_TestOtherServerToWorldServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    if (pConfig)
    {
        proto_ff::Proto_TestSendWorldMsgToOtherServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        FindModule<NFIMessageModule>()->SendMsgToServer(NF_ST_WORLD_SERVER, NF_ST_NONE, 0, packet.nSrcId, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ, xData, 3, 4);
    }

    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

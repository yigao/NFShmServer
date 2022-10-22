// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFLoginServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

#define LOGIN_SERVER_CONNECT_MASTER_SERVER "LoginServer Connect MasterServer"
#define LOGIN_SERVER_CONNECT_ROUTEAGENT_SERVER "LoginServer Connect RouteAgentServer"
#define LOGIN_SERVER_CHECK_STORE_SERVER "LoginServer Check Store Server"

NFCLoginServerModule::NFCLoginServerModule(NFIPluginManager* p):NFILoginServerModule(p)
{
}

NFCLoginServerModule::~NFCLoginServerModule()
{
}

bool NFCLoginServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_LOGIN_SERVER);
	///////////////////////////master msg//////////////////////////////
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCLoginServerModule::OnServerRegisterProcess);
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFCLoginServerModule::OnHandleServerReport);

    /////////////////route agent msg///////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCLoginServerModule::OnRegisterRouteAgentRspProcess);
    ////////////////test other server msg///////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_LOGIN_SERVER, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ, this, &NFCLoginServerModule::OnHandleTestWorldServerMsg);


    //注册要完成的服务器启动任务
	m_pObjPluginManager->RegisterAppTask(NF_ST_LOGIN_SERVER, APP_INIT_CONNECT_MASTER, LOGIN_SERVER_CONNECT_MASTER_SERVER);
	m_pObjPluginManager->RegisterAppTask(NF_ST_LOGIN_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, LOGIN_SERVER_CONNECT_ROUTEAGENT_SERVER);
    m_pObjPluginManager->RegisterAppTask(NF_ST_LOGIN_SERVER, APP_INIT_NEED_STORE_SERVER, LOGIN_SERVER_CHECK_STORE_SERVER);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	if (pConfig)
	{
		int64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_LOGIN_SERVER, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
		if (unlinkId >= 0)
		{
			/*
				注册客户端事件
			*/
			uint64_t loginServerLinkId = (uint64_t)unlinkId;
			FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_LOGIN_SERVER, loginServerLinkId);
			FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, loginServerLinkId, this, &NFCLoginServerModule::OnLoginSocketEvent);
			FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, loginServerLinkId, this, &NFCLoginServerModule::OnHandleOtherMessage);
			NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server listen success, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
		}
		else
		{
			NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server listen failed, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
			return false;
		}

        if (pConfig->LinkMode == "bus") {
            int iRet = FindModule<NFIMessageModule>()->ResumeConnect(NF_ST_LOGIN_SERVER);
            if (iRet == 0) {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(
                        NF_ST_LOGIN_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++) {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0) {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER) {
                            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnRouteAgentServerSocketEvent);
                            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_LOGIN_SERVER);
                            pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                            pRouteServer->mServerInfo = pServerData->mServerInfo;
                        }
                        else if (pServerData->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER) {
                            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this,
                                                                       &NFCLoginServerModule::OnProxyAgentServerSocketEvent);
                            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this,
                                                                       &NFCLoginServerModule::OnHandleProxyAgentOtherMessage);
                        }
                    }
                }
            }
        }
	}
	else
	{
		NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "I Can't get the Game Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, NF_ST_LOGIN_SERVER, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCLoginServerModule::OnLoginSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		//uint32_t fromBusId = GetServerIndexFromUnlinkId(unLinkId);
		//NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "server:{} connect login server success", NFServerIDUtil::GetBusNameFromBusID(fromBusId));
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		OnHandleServerDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_LOGIN_SERVER, unLinkId);
	if (pServerData)
	{
		pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
		pServerData->mUnlinkId = 0;

		NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "the server disconnect from login server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
		, pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
	}

	FindModule<NFIMessageModule>()->DelServerLink(NF_ST_LOGIN_SERVER, unLinkId);
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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
    return 0;
}

void NFCLoginServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCLoginServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
    if (pConfig)
    {
        auto pMsterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_LOGIN_SERVER);
        if (pMsterServerData->mUnlinkId <= 0)
        {
            pMsterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_LOGIN_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pMsterServerData->mUnlinkId, this, &NFCLoginServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pMsterServerData->mUnlinkId, this, &NFCLoginServerModule::OnHandleMasterOtherMessage);
        }

        pMsterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "I Can't get the Login Server config!");
        return -1;
    }

    return 0;
}

bool NFCLoginServerModule::Init()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
    NF_ASSERT(pConfig);

#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_LOGIN_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->RouteConfig.NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_LOGIN_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_LOGIN_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch, MasterServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    if (pConfig->LinkMode == "bus")
    {
        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_LOGIN_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch RouteAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch RouteAgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });

        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_LOGIN_SERVER, NF_ST_PROXY_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch ProxyAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch ProxyAgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleProxyAgentReport(xData);
        });
    }
    else
    {
        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_LOGIN_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch, RouteAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch RouteAgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });

		FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_LOGIN_SERVER, NF_ST_PROXY_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
			if (errCode != 0)
			{
				NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch, ProxyAgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
				return;
			}
			NFLogInfo(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch ProxyAgentServer name:{} serverInfo:{}", name, xData.DebugString());

			OnHandleProxyAgentReport(xData);
		});
    }

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_LOGIN_SERVER, NF_ST_STORE_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "LoginServer Watch, StoreServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id());
            if (pServerData)
            {
                FindModule<NFIMessageModule>()->CloseServer(NF_ST_LOGIN_SERVER, NF_ST_STORE_SERVER, xData.bus_id(), 0);
            }
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NF_ST_LOGIN_SERVER Watch StoreServer name:{} serverInfo:{}", name, xData.DebugString());

		OnHandleStoreServerReport(xData);
    });
    return true;
}

int NFCLoginServerModule::OnHandleStoreServerReport(const proto_ff::ServerInfoReport& xData)
{
	FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id(), NF_ST_STORE_SERVER, xData);

	m_pObjPluginManager->FinishAppTask(NF_ST_LOGIN_SERVER, APP_INIT_NEED_STORE_SERVER);

	return 0;
}

bool NFCLoginServerModule::Execute()
{
	ServerReport();
    TestOtherServerToWorldServer();
	return true;
}

bool NFCLoginServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_LOGIN_SERVER);
	return true;
}

/*
	处理Master服务器链接事件
*/
int NFCLoginServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server connect master success!");
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
			m_pObjPluginManager->FinishAppTask(NF_ST_LOGIN_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server disconnect master success");
	}
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCLoginServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "master server other message not handled:,msg:{},ip:{}", packet.ToString(), ip);
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");

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
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
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
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

//游戏服务器注册协议回调
int NFCLoginServerModule::OnHandleProxyRegister(const proto_ff::ServerInfoReport& xData, uint64_t unlinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_PROXY_SERVER, -1, "xData.server_type() == NF_ST_PROXY_SERVER");

	NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id());
	if (!pServerData)
	{
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id(), NF_ST_PROXY_SERVER, xData);
	}

	pServerData->mUnlinkId = unlinkId;
	pServerData->mServerInfo = xData;

	NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "Proxy Server Register Login Server Success, serverName:{}, ServerId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.server_id(), pServerData->mServerInfo.external_server_ip(), pServerData->mServerInfo.external_server_port());
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::RegisterMasterServer(uint32_t serverState)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(serverState);

		FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_LOGIN_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::ServerReport()
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

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
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
			FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_LOGIN_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCLoginServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
    CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.server_id())
    {
        return 0;
    }

	auto pRouteAgentServerData = FindModule<NFIMessageModule>()->GetRouteData(NF_ST_LOGIN_SERVER);

	if (pRouteAgentServerData->mUnlinkId == 0)
	{
        pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_LOGIN_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

		FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCLoginServerModule::OnRouteAgentServerSocketEvent);
		FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCLoginServerModule::OnHandleRouteAgentOtherMessage);
	}
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_LOGIN_SERVER, xData.url(),
                                                                                       PACKET_PARSE_TYPE_INTERNAL);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pRouteAgentServerData->mUnlinkId, this,
                                                       &NFCLoginServerModule::OnRouteAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pRouteAgentServerData->mUnlinkId, this,
                                                       &NFCLoginServerModule::OnHandleRouteAgentOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	CHECK_NULL(pConfig);

    if (pConfig->RouteConfig.RouteAgent != xData.route_svr())
    {
        return 0;
    }

	NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id());
	if (pServerData == nullptr)
	{
		pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_LOGIN_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);

		pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_LOGIN_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
		FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_LOGIN_SERVER, xData.bus_id(), pServerData->mUnlinkId);

		FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnProxyAgentServerSocketEvent);
		FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnHandleProxyAgentOtherMessage);
	}
    else {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.url(), xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pServerData->mUnlinkId);

            pServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_LOGIN_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_LOGIN_SERVER, xData.bus_id(), pServerData->mUnlinkId);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnProxyAgentServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_LOGIN_SERVER, pServerData->mUnlinkId, this, &NFCLoginServerModule::OnHandleProxyAgentOtherMessage);
        }
    }

	pServerData->mServerInfo = xData;
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_PROXY_SERVER_PLUGIN, 0, "login server connect proxy agent server success!");
		RegisterProxyAgentServer(unLinkId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "login server disconnect proxy agent server");
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
	}

	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleProxyAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server connect route agent server success!");

		RegisterRouteAgentServer(unLinkId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "login server disconnect route agent server success");
	}
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "msg:{} not handled!", packet.ToString());
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCLoginServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
	}
	NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCLoginServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, NFDataPackage& packet) {
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- begin --");
	//完成服务器启动任务
	if (!m_pObjPluginManager->IsInited())
	{
		m_pObjPluginManager->FinishAppTask(NF_ST_LOGIN_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
	}

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_LOGIN_SERVER);
    NFLogTrace(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCLoginServerModule::TestOtherServerToWorldServer()
{
#ifdef TEST_SERVER_SEND_MSG
    for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
    {
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIN_SERVER);
        CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

        proto_ff::Proto_TestOtherServerToWorldServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIN_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, xData, 1, 2);
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    }
#endif

    return 0;
}

int NFCLoginServerModule::OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_TestSendWorldMsgToOtherServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

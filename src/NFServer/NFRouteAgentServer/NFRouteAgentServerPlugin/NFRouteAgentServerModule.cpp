// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFRouteAgentServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

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
    m_pObjPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_ROUTE_AGENT_SERVER);

    /////////////master msg/////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER,
                                                       this, &NFCRouteAgentServerModule::OnServerRegisterProcess);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_ROUTE_AGENT_SERVER,
                                                       proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFCRouteAgentServerModule::OnHandleServerReport);

	//注册要完成的服务器启动任务
	m_pObjPluginManager->RegisterAppTask(NF_ST_ROUTE_AGENT_SERVER, APP_INIT_CONNECT_MASTER, ROUTEAGENT_SERVER_CONNECT_MASTER_SERVER);
	m_pObjPluginManager->RegisterAppTask(NF_ST_ROUTE_AGENT_SERVER, APP_INIT_CONNECT_ROUTE_SERVER, ROUTEAGENT_SERVER_CONNECT_ROUTE_SERVER);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig) {
        m_pObjPluginManager->SetIdelSleepUs(pConfig->IdleSleepUS);
        uint64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_ROUTE_AGENT_SERVER, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
		if (unlinkId > 0)
		{
			/*
				注册客户端事件
			*/
			uint64_t routeAgentServerLinkId = unlinkId;
            FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId);
			FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId, this,
                                                             &NFCRouteAgentServerModule::OnRouteAgentSocketEvent);
			FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, routeAgentServerLinkId, this, &NFCRouteAgentServerModule::OnHandleOtherMessage);
			NFLogInfo(NF_LOG_SYSTEMLOG, 0, "route agent server listen success, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
		}
		else
		{
			NFLogInfo(NF_LOG_SYSTEMLOG, 0, "route agent listen failed, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
			return false;
		}
	}
	else
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the Game Server config!");
		return false;
	}

	SetTimer(1, 60000);
    Subscribe(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_EVENT_SERVER_DEAD_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
    Subscribe(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, __FUNCTION__);
	return true;
}

int NFCRouteAgentServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_ROUTE_AGENT_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pMasterServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pMasterServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the Route Agent Server config!");
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
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    if (pConfig && pConfig->RouteConfig.NamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_ROUTE_AGENT_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    return true;
}

bool NFCRouteAgentServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCRouteAgentServerModule::OnDynamicPlugin()
{
	FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_ROUTE_AGENT_SERVER);
	return true;
}

int NFCRouteAgentServerModule::OnTimer(uint32_t nTimerID) {
    RegisterAllServerInfoToRouteSvr();

    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
    return 0;
}

int NFCRouteAgentServerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    CHECK_NULL(serverType == NF_ST_ROUTE_AGENT_SERVER);
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

int NFCRouteAgentServerModule::OnRouteAgentSocketEvent(eMsgType nEvent, uint64_t unLinkId)
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

int
NFCRouteAgentServerModule::OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet) {
    uint32_t fromBusId = GetBusIdFromUnlinkId(packet.nSrcId);
    uint32_t fromServerType = GetServerTypeFromUnlinkId(packet.nSrcId);

    uint32_t serverType = GetServerTypeFromUnlinkId(packet.nDstId);
    uint32_t destBusId = GetBusIdFromUnlinkId(packet.nDstId);

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    CHECK_EXPR(pConfig != NULL, -1, "pConfig == NULL");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0,
               "--{}:{} trans msg from {}:{} to {}:{}, packet:{} --", pConfig->ServerName, pConfig->ServerId,
               GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId), packet.ToString());

    if (destBusId == 0) {
        NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(
                NF_ST_ROUTE_AGENT_SERVER, (NF_SERVER_TYPES) serverType);
        if (pServerData) {
            packet.nSrcId = fromBusId;
            packet.nDstId = destBusId;
            FindModule<NFIMessageModule>()->TransPackage(pServerData->mUnlinkId, packet);
        } else {
            auto pRouteServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);
            CHECK_NULL(pRouteServerData);
            FindModule<NFIMessageModule>()->TransPackage(pRouteServerData->mUnlinkId, packet);
        }
    } else {
        NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(
                NF_ST_ROUTE_AGENT_SERVER, destBusId);
        if (pServerData) {
            packet.nSrcId = fromBusId;
            packet.nDstId = destBusId;
            FindModule<NFIMessageModule>()->TransPackage(pServerData->mUnlinkId, packet);
        } else {
            auto pRouteServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);
            CHECK_NULL(pRouteServerData);
            FindModule<NFIMessageModule>()->TransPackage(pRouteServerData->mUnlinkId, packet);
        }
    }

    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFCRouteAgentServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_SYSTEMLOG, 0, "route agent server connect master success!");
        if (!m_pObjPluginManager->IsInited(NF_ST_ROUTE_AGENT_SERVER))
        {
            RegisterMasterServer(proto_ff::EST_INIT);
        }
        else {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }

		//完成服务器启动任务
		if (!m_pObjPluginManager->IsInited(NF_ST_ROUTE_AGENT_SERVER))
		{
			m_pObjPluginManager->FinishAppTask(NF_ST_ROUTE_AGENT_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_SYSTEMLOG, 0, "route agent server disconnect master success");
	}
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCRouteAgentServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "master server other message not handled:packet:{},ip:{}", packet.ToString(), ip);
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

int NFCRouteAgentServerModule::RegisterMasterServer(uint32_t serverState)
{
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(serverState);

		FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	return 0;
}

int NFCRouteAgentServerModule::ServerReport()
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

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
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
			FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_ROUTE_AGENT_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCRouteAgentServerModule::OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet) {
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(
                NF_ST_ROUTE_AGENT_SERVER, xData.bus_id());
        if (pServerData == nullptr) {
            pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_ROUTE_AGENT_SERVER,
                                                                                 xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
        }

        pServerData->mUnlinkId = unLinkId;
        pServerData->mServerInfo = xData;
        FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(),
                                                           pServerData->mUnlinkId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{} Register Route Agent Server Success",
                  xData.server_name());

        proto_ff::ServerInfoReportList rsp;
        FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, rsp,
                                             0);

        ::proto_ff::ServerInfoReport *pReport = rsp.add_server_list();
        *pReport = xData;
        RegisterServerInfoToRouteSvr(rsp);
    }
    return 0;
}

int NFCRouteAgentServerModule::OnHandleServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);


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

	auto pRouteServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id());

	if (pRouteServerData == NULL)
	{
        pRouteServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), NF_ST_ROUTE_SERVER, xData);

        pRouteServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), pRouteServerData->mUnlinkId);

		FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnRouteServerSocketEvent);
		FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleRouteOtherMessage);
	}
	else {
        if (pRouteServerData->mUnlinkId > 0 && pRouteServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pRouteServerData->mServerInfo.server_name(), pRouteServerData->mServerInfo.url(), xData.url());
            FindModule<NFIMessageModule>()->CloseLinkId(pRouteServerData->mUnlinkId);

            pRouteServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_ROUTE_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_ROUTE_AGENT_SERVER, xData.bus_id(), pRouteServerData->mUnlinkId);

            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnRouteServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_ROUTE_AGENT_SERVER, pRouteServerData->mUnlinkId, this, &NFCRouteAgentServerModule::OnHandleRouteOtherMessage);
        }
	}

    pRouteServerData->mServerInfo = xData;
	return 0;
}

int NFCRouteAgentServerModule::OnRouteServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_SYSTEMLOG, 0, "route agent server connect route server success!");

		RegisterRouteServer(unLinkId);

		//完成服务器启动任务
		if (!m_pObjPluginManager->IsInited(NF_ST_ROUTE_AGENT_SERVER))
		{
			m_pObjPluginManager->FinishAppTask(NF_ST_ROUTE_AGENT_SERVER, APP_INIT_CONNECT_ROUTE_SERVER);
		}

        FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_ROUTE_AGENT_SERVER);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "route agent server disconnect route server success");
	}
	return 0;
}

int NFCRouteAgentServerModule::OnHandleRouteOtherMessage(uint64_t unLinkId, NFDataPackage& packet) {
    uint32_t fromBusId = GetBusIdFromUnlinkId(packet.nSrcId);
    uint32_t fromServerType = GetServerTypeFromUnlinkId(packet.nSrcId);

    uint32_t serverType = GetServerTypeFromUnlinkId(packet.nDstId);
    uint32_t destBusId = GetBusIdFromUnlinkId(packet.nDstId);

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
    CHECK_EXPR(pConfig != NULL, -1, "pConfig == NULL");

    auto pRouteSvrServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_ROUTE_AGENT_SERVER, unLinkId);
    CHECK_EXPR(pRouteSvrServerData != NULL, -1, "pRouteSvrServerData == NULL");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0,
               "--{}:{} trans routesvr({}:{}) msg from {}:{} to {}:{}, packet:{} --", pConfig->ServerName, pConfig->ServerId, pRouteSvrServerData->mServerInfo.server_name(), pRouteSvrServerData->mServerInfo.server_id(),
               GetServerName((NF_SERVER_TYPES) fromServerType), NFServerIDUtil::GetBusNameFromBusID(fromBusId), GetServerName((NF_SERVER_TYPES) serverType), NFServerIDUtil::GetBusNameFromBusID(destBusId), packet.ToString());

    if (destBusId == 0) {
        NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(
                NF_ST_ROUTE_AGENT_SERVER, (NF_SERVER_TYPES) serverType);
        if (pServerData) {
            packet.nSrcId = fromBusId;
            packet.nDstId = destBusId;
            FindModule<NFIMessageModule>()->TransPackage(pServerData->mUnlinkId, packet);
        } else {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "the route agent can't find the server, busid:{}, server:{} trans packet:{} failed", destBusId,
                       GetServerName((NF_SERVER_TYPES) serverType), packet.ToString());
        }
    } else {
        NF_SHARE_PTR<NFServerData> pServerData  = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_ROUTE_AGENT_SERVER, destBusId);
        if (pServerData)
        {
            packet.nSrcId = fromBusId;
            packet.nDstId = destBusId;
            FindModule<NFIMessageModule>()->TransPackage(pServerData->mUnlinkId, packet);
        } else {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "the route agent can't find the server, busid:{}, server:{} trans packet:{} failed", destBusId,
                       GetServerName((NF_SERVER_TYPES) serverType), packet.ToString());
        }
    }
	return 0;
}

int NFCRouteAgentServerModule::RegisterRouteServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_ROUTE_AGENT_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);

        RegisterAllServerInfoToRouteSvr();
	}
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
	return 0;
}

int NFCRouteAgentServerModule::RegisterServerInfoToRouteSvr(const proto_ff::ServerInfoReportList& xData)
{
    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_ROUTE_AGENT_SERVER, NF_ST_ROUTE_SERVER);//GetRouteData(NF_ST_ROUTE_AGENT_SERVER);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pRouteServerData = vec[i];
        if (pRouteServerData && pRouteServerData->mUnlinkId > 0)
        {
            FindModule<NFIMessageModule>()->Send(pRouteServerData->mUnlinkId, proto_ff::NF_ROUTER_CMD_INTERNAL_C2R_REG_RAASSOCAPPSVS, xData, 0);
        }
    }

    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCRouteAgentServerModule::RegisterAllServerInfoToRouteSvr() {
    proto_ff::ServerInfoReportList xData;
    std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_ROUTE_AGENT_SERVER);
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(
            NF_ST_ROUTE_AGENT_SERVER, unLinkId);
    if (pServerData) {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "the {0} disconnect from route agent server, serverName:{0}, busid:{1}, serverIp:{2}, serverPort:{3}",
                   pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(),
                   pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(NF_ST_ROUTE_AGENT_SERVER, unLinkId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


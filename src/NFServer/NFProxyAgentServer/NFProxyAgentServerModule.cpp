// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyAgentServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCProxyAgentServerModule
//
// -------------------------------------------------------------------------

#include "NFProxyAgentServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <NFComm/NFPluginModule/NFConfigMgr.h>
#include <NFComm/NFPluginModule/NFEventDefine.h>
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServer/NFCommHead/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

#define PROXY_SERVER_CONNECT_MASTER_SERVER "ProxyServer Connect MasterServer"

NFCProxyAgentServerModule::NFCProxyAgentServerModule(NFIPluginManager* p):NFIDynamicModule(p)
{
}

NFCProxyAgentServerModule::~NFCProxyAgentServerModule()
{
}

bool NFCProxyAgentServerModule::Awake()
{
    //不需要固定帧，需要尽可能跑得快
    m_pPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_PROXY_AGENT_SERVER);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCProxyAgentServerModule::OnServerRegisterProcess);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_AGENT_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this, &NFCProxyAgentServerModule::OnHandleServerReport);

    //注册要完成的服务器启动任务
    m_pPluginManager->RegisterAppTask(NF_ST_PROXY_AGENT_SERVER, APP_INIT_CONNECT_MASTER, PROXY_SERVER_CONNECT_MASTER_SERVER);

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
	if (pConfig)
	{
        m_pPluginManager->SetIdelSleepUs(pConfig->mIdleSleepUs);

        int64_t extern_unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_PROXY_AGENT_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum,
                                                                       PACKET_PARSE_TYPE_INTERNAL);
        if (extern_unlinkId >= 0) {
            /*
            注册服务器事件
            */
            uint64_t proxyServerLinkId = (uint64_t) extern_unlinkId;
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_AGENT_SERVER, proxyServerLinkId, this,
                                                       &NFCProxyAgentServerModule::OnProxyAgentServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_AGENT_SERVER, proxyServerLinkId, this,
                                                       &NFCProxyAgentServerModule::OnHandleProxyAgentServerOtherMessage);
            NFLogInfo(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        } else {
            NFLogInfo(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }

        if (pConfig->mLinkMode == "bus") {
            NFMessageMgr::Instance()->ResumeConnect(NF_ST_PROXY_AGENT_SERVER);
        }
	}
	else
	{
		NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "I Can't get the Proxy Agent Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCProxyAgentServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

void NFCProxyAgentServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCProxyAgentServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
    if (pConfig)
    {
        auto pMsterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_PROXY_AGENT_SERVER);
        if (pMsterServerData->mUnlinkId <= 0)
        {
            pMsterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_PROXY_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_AGENT_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_AGENT_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnHandleMasterOtherMessage);
        }

        pMsterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "I Can't get the Proxy Agent Server config!");
        return -1;
    }

    return 0;
}

bool NFCProxyAgentServerModule::Init()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
    NF_ASSERT(pConfig);
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_PROXY_AGENT_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->mNamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_PROXY_AGENT_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_PROXY_AGENT_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ProxyAgentServer Watch, MasterServer Dump, errCdde:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ProxyAgentServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_PROXY_AGENT_SERVER, NF_ST_PROXY_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ProxyAgentServer Watch, ProxyServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ProxyAgentServer Watch ProxyServer name:{} serverInfo:{}", name, xData.DebugString());

        OnHandleProxyReport(xData);
    });

    return true;
}

bool NFCProxyAgentServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCProxyAgentServerModule::OnDynamicPlugin()
{
	NFMessageMgr::Instance()->CloseAllLink(NF_ST_PROXY_AGENT_SERVER);

	return true;
}

/*
	处理Master服务器链接事件
*/
int NFCProxyAgentServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server connect master success!");
		RegisterMasterServer();

        //完成服务器启动任务
        if (!m_pPluginManager->IsInited())
        {
            m_pPluginManager->FinishAppTask(NF_ST_PROXY_AGENT_SERVER, APP_INIT_CONNECT_MASTER);
        }

        FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_PROXY_AGENT_SERVER);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server disconnect master success");
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCProxyAgentServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_PROXY_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyAgentServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
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
        pData->set_external_server_ip(pConfig->mExternalServerIp);
        pData->set_external_server_port(pConfig->mExternalServerPort);
		pData->set_server_state(proto_ff::EST_NARMAL);

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_PROXY_AGENT_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}

	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyAgentServerModule::ServerReport()
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

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_PROXY_AGENT_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCProxyAgentServerModule::OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
    CHECK_NULL(pConfig);

	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		if (!m_pPluginManager->IsLoadAllServer() && xData.server_type() != NF_SERVER_TYPES::NF_ST_PROXY_SERVER)
        {
            if (pConfig->mRouteAgent != xData.route_svr()) continue;
        }

		switch (xData.server_type())
		{
        case NF_SERVER_TYPES::NF_ST_PROXY_SERVER:
        {
            OnHandleProxyReport(xData);
        }
        break;
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");

	return 0;
}

int NFCProxyAgentServerModule::OnOtherServerRegisterProcess(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX, -1, "xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX");

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_AGENT_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_PROXY_AGENT_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;
    NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_PROXY_AGENT_SERVER, xData.bus_id(), pServerData->mUnlinkId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{} Register Proxy Agent Server, serverName:{} busName:{}", xData.server_name(), xData.server_name(), xData.bus_name());

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_PROXY_AGENT_SERVER, NF_ST_PROXY_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        auto pProxyServerData = vecServer[i];
        if (pProxyServerData)
        {
            proto_ff::ServerInfoReportList xMsg;
            proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
            *pData = pProxyServerData->mServerInfo;
            NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);

            auto pOtherData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_AGENT_SERVER, unLinkId);
            if (pOtherData)
            {
                proto_ff::ServerInfoReportList reportMsg;
                proto_ff::ServerInfoReport* pReportData = reportMsg.add_server_list();
                *pReportData = pOtherData->mServerInfo;
                NFMessageMgr::Instance()->Send(pProxyServerData->mUnlinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, reportMsg, 0);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "GetServerByUnlinkId Failed!");
            }
        }
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnHandleProxyReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_SERVER, -1, "xData.server_type() == NF_ST_PROXY_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_AGENT_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_PROXY_AGENT_SERVER, xData.bus_id(), NF_ST_PROXY_SERVER, xData);

        pServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_PROXY_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
        NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_PROXY_AGENT_SERVER, xData.bus_id(), pServerData->mUnlinkId);

        NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_AGENT_SERVER, pServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnProxyServerSocketEvent);
        NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_AGENT_SERVER, pServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnHandleProxyOtherMessage);
    }
    else {
        if (pServerData->mUnlinkId > 0 && pServerData->mServerInfo.url() != xData.url())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.url(), xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pServerData->mUnlinkId);
            pServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_PROXY_AGENT_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_PROXY_AGENT_SERVER, xData.bus_id(), pServerData->mUnlinkId);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_AGENT_SERVER, pServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnProxyServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_AGENT_SERVER, pServerData->mUnlinkId, this, &NFCProxyAgentServerModule::OnHandleProxyOtherMessage);
        }
    }

    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogDebug(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server connect proxy server success!");
        RegisterProxyServer(unLinkId);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy agent server disconnect proxy server");
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnHandleProxyOtherMessage(uint64_t unLinkId, uint64_t valueId, uint64_t busId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pProxyServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_AGENT_SERVER, unLinkId);
    if (pProxyServerData && pProxyServerData->mServerInfo.server_type() == NF_ST_PROXY_SERVER)
    {
        auto pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_AGENT_SERVER, busId);
        if (pServerData)
        {
            NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "Trans ProxyServer:{} msg:{} to OtherServer:{},{}", pProxyServerData->mServerInfo.bus_name(), nMsgId, pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_name());
            NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, valueId, pProxyServerData->mServerInfo.bus_id());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find the busId:{} busName:{} nMsgId:{}", busId, NFServerIDUtil::GetBusNameFromBusID(busId), nMsgId);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "unLinkId:{} can't find proxy! nMsgId:{}", unLinkId, nMsgId);
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::RegisterProxyServer(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_AGENT_SERVER);
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

    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}


int NFCProxyAgentServerModule::OnProxyAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId) {
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleProxyServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnHandleProxyAgentServerOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t busId,
                                                               uint32_t nMsgId, const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_AGENT_SERVER, unLinkId);
    if (pServerData)
    {
        auto pProxyServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_AGENT_SERVER, busId);
        if (pProxyServerData && pProxyServerData->mServerInfo.server_type() == NF_ST_PROXY_SERVER)
        {
            NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "Trans Server:{} msg:{} to ProxyServer:{}", pServerData->mServerInfo.bus_name(), nMsgId, pProxyServerData->mServerInfo.bus_name());
            NFMessageMgr::Instance()->Send(pProxyServerData->mUnlinkId, nMsgId, msg, nLen, playerId, pServerData->mServerInfo.bus_id());
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find the busId:{} busName:{} nMsgId:{}", busId, NFServerIDUtil::GetBusNameFromBusID(busId), nMsgId);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "unLinkId:{} can't find server! nMsgId:{}", unLinkId, nMsgId);
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnHandleProxyServerDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_AGENT_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "the server disconnect from proxy agent server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    NFMessageMgr::Instance()->DelServerLink(NF_ST_PROXY_AGENT_SERVER, unLinkId);
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyAgentServerModule::OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2,
                                                       uint32_t nMsgId, const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_PROXY_SERVER:
            {
                NF_SHARE_PTR<NFServerData> pProxyServer = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_AGENT_SERVER, xData.bus_id());
                if (pProxyServer)
                {
                    pProxyServer->mServerInfo = xData;
                }

                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_PROXY_AGENT_SERVER);
                for(int j = 0; j < (int)vecServer.size(); j++)
                {
                    auto pServerData = vecServer[j];
                    if (pServerData->mServerInfo.server_type() == NF_ST_WORLD_SERVER
                        || pServerData->mServerInfo.server_type() == NF_ST_GAME_SERVER
                        || pServerData->mServerInfo.server_type() == NF_ST_LOGIC_SERVER
                        || pServerData->mServerInfo.server_type() == NF_ST_LOGIN_SERVER)
                    {
                        NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);

                        proto_ff::ServerInfoReportList reportMsg;
                        proto_ff::ServerInfoReport* pData = reportMsg.add_server_list();
                        *pData = pServerData->mServerInfo;
                        NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, reportMsg, 0);
                    }
                }
            }
            break;
            default:
            {
                OnOtherServerRegisterProcess(xData, unLinkId);
            }
            break;
        }
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
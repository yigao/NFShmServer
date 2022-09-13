// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyServerModule.h"
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

NFCProxyServerModule::NFCProxyServerModule(NFIPluginManager* p):NFIProxyServerModule(p)
{
    m_proxyServerLinkId = 0;
}

NFCProxyServerModule::~NFCProxyServerModule()
{
}

bool NFCProxyServerModule::Awake()
{
    //不需要固定帧，需要尽可能跑得快
    m_pPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_PROXY_SERVER);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                 &NFCProxyServerModule::OnHandleMasterServerReport);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this,
                                                 &NFCProxyServerModule::OnHandleProxyAgentServerReport);

    //注册要完成的服务器启动任务
    m_pPluginManager->RegisterAppTask(NF_ST_PROXY_SERVER, APP_INIT_CONNECT_MASTER, PROXY_SERVER_CONNECT_MASTER_SERVER);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig) {
        m_pPluginManager->SetIdelSleepUs(pConfig->mIdleSleepUs);

        if (!m_pPluginManager->IsLoadAllServer()) {
            if (pConfig->mServerType != NF_ST_PROXY_SERVER) {
                NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->mServerIp, pConfig->mServerPort);
        int64_t extern_unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_PROXY_SERVER, externUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum,
                                                                       PACKET_PARSE_TYPE_INTERNAL);
        if (extern_unlinkId >= 0) {
            /*
            注册服务器事件
            */
            m_proxyServerLinkId = (uint64_t) extern_unlinkId;
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_SERVER, m_proxyServerLinkId, this,
                                                       &NFCProxyServerModule::OnProxyServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_SERVER, m_proxyServerLinkId, this,
                                                       &NFCProxyServerModule::OnHandleProxyServerOtherMessage);
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy server listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        } else {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy server listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }
    }
    else
    {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "I Can't get the Proxy Server config!");
        return false;
    }

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCProxyServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

void NFCProxyServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCProxyServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        auto pMsterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_PROXY_SERVER);
        if (pMsterServerData->mUnlinkId <= 0)
        {
            pMsterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_PROXY_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_PROXY_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_PROXY_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyServerModule::OnHandleMasterOtherMessage);
        }

        pMsterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "I Can't get the Proxy Server config!");
        return -1;
    }

    return 0;
}

bool NFCProxyServerModule::Init()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_PROXY_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig && pConfig->mNamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_PROXY_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_PROXY_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ProxyServer Watch, MasterServer Dump, errCdde:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "ProxyServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    return true;
}

int NFCProxyServerModule::OnHandleOtherReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX, -1, "xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX");
    auto pProxyAgentServer = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_SERVER, unLinkId);
    CHECK_EXPR(pProxyAgentServer && pProxyAgentServer->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "Not From NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{} Register Proxy Server, serverName:{} busName:{}", xData.server_name(), xData.server_name(), xData.bus_name());
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;
    NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_PROXY_SERVER, xData.bus_id(), pServerData->mUnlinkId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Proxy Agent Server:{} Register Proxy Server, serverName:{} busName:{}", xData.server_name(), xData.server_name(), xData.bus_name());

    RegisterProxyAgentServer(unLinkId);

    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
bool NFCProxyServerModule::Execute()
{
	ServerReport();
	return true;
}

bool NFCProxyServerModule::OnDynamicPlugin()
{
	NFMessageMgr::Instance()->CloseAllLink(NF_ST_PROXY_SERVER);

	return true;
}

/*
	处理Master服务器链接事件
*/
int NFCProxyServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy server connect master success!");
		RegisterMasterServer();

        //完成服务器启动任务
        if (!m_pPluginManager->IsInited())
        {
            m_pPluginManager->FinishAppTask(NF_ST_PROXY_SERVER, APP_INIT_CONNECT_MASTER);
        }

        FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_PROXY_SERVER);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "proxy server disconnect master success");
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCProxyServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_PROXY_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
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

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyServerModule::ServerReport()
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

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCProxyServerModule::OnHandleMasterServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    /*
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_NULL(pConfig);

	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		switch (xData.server_type())
		{
		break;
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    */

    return 0;
}

int NFCProxyServerModule::OnHandleProxyAgentServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_NULL(pConfig);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_PROXY_AGENT_SERVER:
            {
                OnHandleProxyAgentReport(xData, unLinkId);
            }
                break;
            default:
                OnHandleOtherReport(xData, unLinkId);
                break;
        }
    }
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");

    return 0;
}

int NFCProxyServerModule::OnProxyServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
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

int NFCProxyServerModule::OnHandleProxyServerDisconnect(uint64_t unLinkId) {
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_PROXY_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "the server disconnect from proxy server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    NFMessageMgr::Instance()->DelServerLink(NF_ST_PROXY_SERVER, unLinkId);
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleProxyServerOtherMessage(uint64_t unLinkId, uint64_t valueId, uint64_t busId, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    auto pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_PROXY_SERVER, busId);
    if (pServerData && FindModule<NFIProxyClientModule>())
    {
        FindModule<NFIProxyClientModule>()->OnHandleOtherServerOtherMessage(unLinkId, valueId, busId, nMsgId, msg, nLen);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find busId:{} busName:{} nMsgId:{}", busId, NFServerIDUtil::GetBusNameFromBusID(busId), nMsgId);
    }

    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_PROXY_SERVER);
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

		NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}
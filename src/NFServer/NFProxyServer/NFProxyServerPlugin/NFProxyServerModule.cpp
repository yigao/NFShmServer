﻿// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"
#include "NFServerComm/NFServerMessage/proto_svr_common.pb.h"

#define PROXY_SERVER_CONNECT_MASTER_SERVER "ProxyServer Connect MasterServer"

NFCProxyServerModule::NFCProxyServerModule(NFIPluginManager* p):NFIProxyServerModule(p)
{
    m_proxyServerLinkId = 0;
    m_otherServerMsgHandle = NULL;
}

NFCProxyServerModule::~NFCProxyServerModule()
{
}

bool NFCProxyServerModule::Awake()
{
    //不需要固定帧，需要尽可能跑得快
    //m_pObjPluginManager->SetFixedFrame(false);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_PROXY_SERVER);
	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                 &NFCProxyServerModule::OnHandleMasterServerReport);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this,
                                                 &NFCProxyServerModule::OnHandleProxyAgentServerReport);

    ///////////////////test other server send msg to proxy server////////////////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_TEST_OTHER_SERVER_SEND_MSG_TO_PROXY_SERVER, this,
                                                       &NFCProxyServerModule::OnHandleTestOtherSendMsg);


    //注册要完成的服务器启动任务
    m_pObjPluginManager->RegisterAppTask(NF_ST_PROXY_SERVER, APP_INIT_CONNECT_MASTER, PROXY_SERVER_CONNECT_MASTER_SERVER);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig) {
        m_pObjPluginManager->SetIdelSleepUs(pConfig->IdleSleepUS);

        if (!m_pObjPluginManager->IsLoadAllServer()) {
            if (pConfig->ServerType != NF_ST_PROXY_SERVER) {
                NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->ServerIp, pConfig->ServerPort);
        int64_t extern_unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_PROXY_SERVER, externUrl, pConfig->NetThreadNum, pConfig->MaxConnectNum,
                                                                       PACKET_PARSE_TYPE_INTERNAL);
        if (extern_unlinkId >= 0) {
            /*
            注册服务器事件
            */
            m_proxyServerLinkId = (uint64_t) extern_unlinkId;
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, m_proxyServerLinkId, this,
                                                       &NFCProxyServerModule::OnProxyServerSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, m_proxyServerLinkId, this,
                                                       &NFCProxyServerModule::OnHandleProxyServerOtherMessage);
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy server listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
        } else {
            NFLogInfo(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "proxy server listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
            return false;
        }
    }
    else
    {
        NFLogError(NF_LOG_PROXY_CLIENT_PLUGIN, 0, "I Can't get the Proxy Server config!");
        return false;
    }

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, NF_ST_PROXY_SERVER, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
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
        else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
            RegisterMasterServer(proto_ff::EST_NARMAL);
        }
    }

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
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        auto pMsterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_PROXY_SERVER);
        if (pMsterServerData->mUnlinkId <= 0)
        {
            pMsterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_PROXY_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_PROXY_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyServerModule::OnMasterSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_PROXY_SERVER, pMsterServerData->mUnlinkId, this, &NFCProxyServerModule::OnHandleMasterOtherMessage);
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
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig && pConfig->RouteConfig.NamingHost.empty())
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
    auto pProxyAgentServer = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_PROXY_SERVER, unLinkId);
    CHECK_EXPR(pProxyAgentServer && pProxyAgentServer->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "Not From NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{} Register Proxy Server, serverName:{} busName:{}", xData.server_name(), xData.server_name(),
              xData.server_id());

    //test send msg
    //TestSendProxyMsgToOtherServer(xData.bus_id());
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleProxyAgentReport(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;
    FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_PROXY_SERVER, xData.bus_id(), pServerData->mUnlinkId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Proxy Agent Server:{} Register Proxy Server, serverName:{} serverId:{}", xData.server_name(), xData.server_name(),
              xData.server_id());

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
	FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_PROXY_SERVER);

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
            m_pObjPluginManager->FinishAppTask(NF_ST_PROXY_SERVER, APP_INIT_CONNECT_MASTER);
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
int NFCProxyServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_PROXY_SERVER_PLUGIN, 0, "master server other message not handled, packet:{},ip:{}", packet.ToString(), ip);
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyServerModule::RegisterMasterServer(uint32_t serverState)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(serverState);

        FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCProxyServerModule::ServerReport()
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

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
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
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCProxyServerModule::OnHandleMasterServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
    /*
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

	proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
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

int NFCProxyServerModule::OnHandleProxyAgentServerReport(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
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
    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_PROXY_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_PROXY_SERVER_PLUGIN, 0, "the server disconnect from proxy server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    FindModule<NFIMessageModule>()->DelServerLink(NF_ST_PROXY_SERVER, unLinkId);
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleProxyServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    uint32_t srcBusId = packet.nSrcId;
    auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, srcBusId);
    if (pServerData)
    {
        if (m_otherServerMsgHandle)
        {
            m_otherServerMsgHandle(unLinkId, packet);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find busId:{} busName:{} packet:{}", srcBusId, NFServerIDUtil::GetBusNameFromBusID(srcBusId), packet.ToString());
    }

    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
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

int NFCProxyServerModule::TestSendProxyMsgToOtherServer(uint64_t dstBusId)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

    proto_ff::Proto_TestSendProxyMsgToOtherServer xData;
    xData.set_server_id(pConfig->ServerId);
    xData.set_server_name(pConfig->ServerName);
    FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, dstBusId, proto_ff::NF_TEST_SEND_PROXY_MSG_TO_OTHER_SERVER_REQ, xData, 1, 2);
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleTestOtherSendMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_TestOtherServerSendMsgToProxyServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFLogTrace(NF_LOG_PROXY_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

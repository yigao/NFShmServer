// -------------------------------------------------------------------------
//    @FileName         :    NFCMasterServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCMasterServerModule
//
// -------------------------------------------------------------------------

#include "NFMasterServerModule.h"

#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFDateTime.hpp"

#include <NFComm/NFPluginModule/NFConfigMgr.h>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"

#define NF_MASTER_TIMER_SAVE_SERVER_DATA 0
#define NF_MASTER_TIMER_SAVE_SERVER_DATA_TIME 30000
#define NF_MASTER_TIMER_CLEAR_SERVER_DATA 1
#define NF_MASTER_TIMER_CLEAR_SERVER_DATA_TIME 600000

NFCMasterServerModule::NFCMasterServerModule(NFIPluginManager* p):NFIMasterServerModule(p)
{
}

NFCMasterServerModule::~NFCMasterServerModule()
{
}

bool NFCMasterServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_MASTER_SERVER);
    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_MASTER_SERVER);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCMasterServerModule::OnServerRegisterProcess);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, this, &NFCMasterServerModule::OnServerReportProcess);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_STMaster_SEND_DUMP_INFO_NTF, this, &NFCMasterServerModule::OnServerDumpInfoProcess);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_GTM_KILL_ALL_SERVER_NTF, this, &NFCMasterServerModule::OnServerKillAllServerProcess);
    //////////////////////http send to monitor//////////////////
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "reload", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleReloadServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "reloadall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleReloadAllServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "restart", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleRestartServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "restartall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleRestartAllServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "start", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStartServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "startall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStartAllServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "stop", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStopServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "stopall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStopAllServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "killall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleKillAllServer);
    //////////////////////msg from monitor/////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_STOP_CMD_RSP, this, &NFCMasterServerModule::HandleStopSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, this, &NFCMasterServerModule::HandleRestartSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, this, &NFCMasterServerModule::HandleStartSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_CMD_RSP, this, &NFCMasterServerModule::HandleReloadSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_STOP_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleStopAllSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleRestartAllSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleStartAllSeverRsp);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleReloadAllSeverRsp);

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
	if (pConfig)
	{
		int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_MASTER_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
		if (unlinkId >= 0)
		{
			uint64_t masterServerLinkId = (uint64_t)unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_MASTER_SERVER, masterServerLinkId);
			NFMessageMgr::Instance()->AddEventCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFCMasterServerModule::OnProxySocketEvent);
			NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFCMasterServerModule::OnHandleOtherMessage);
			NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
		}
		else
		{
			NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen failed!, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
			return false;
		}

        std::string httpUrl = NF_FORMAT("http://{}:{}", pConfig->mServerIp, pConfig->mHttpPort);
        int ret = NFMessageMgr::Instance()->BindServer(NF_ST_MASTER_SERVER, httpUrl,  pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (ret < 0)
        {
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen http failed!, serverId:{}, ip:{}, httpport:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mHttpPort);
            return false;
        }
	}
	else
	{
		NFLogError(NF_LOG_MASTER_SERVER_PLUGIN, 0, "I Can't get the Master Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_REG_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCMasterServerModule::OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id());
		if (!pServerData)
		{
			pServerData = NFMessageMgr::Instance()->CreateServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
		}
		else
		{
			if (pServerData->mServerInfo.server_type() != xData.server_type() || pServerData->mUnlinkId != 0)
			{
				//该服务器ID已经注册过, 又被别的服务器使用了
				//服务器连接还在没有崩溃
				NFMessageMgr::Instance()->CloseLinkId(unLinkId);
				return 0;
			}
		}

		pServerData->mUnlinkId = unLinkId;
		pServerData->mServerInfo = xData;
        NFMessageMgr::Instance()->CreateLinkToServer(NF_ST_MASTER_SERVER, xData.bus_id(), pServerData->mUnlinkId);
        if (xData.server_type() != NF_ST_MONITOR_SERVER)
        {
#if NF_PLATFORM == NF_PLATFORM_WIN
            SynServerToOthers(pServerData);
#else
            NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
            if (pConfig && pConfig->mNamingHost.empty())
            {
                SynServerToOthers(pServerData);
            }
#endif
        }

		NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "Server Register Master Server Success, serverName:{}, busId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
	}
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCMasterServerModule::OnServerReportProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id());
        if (pServerData)
        {
            pServerData->mServerInfo.set_system_info(xData.system_info());
            pServerData->mServerInfo.set_total_mem(xData.total_mem());
            pServerData->mServerInfo.set_free_mem(xData.free_mem());
            pServerData->mServerInfo.set_used_mem(xData.used_mem());

            pServerData->mServerInfo.set_proc_cpu(xData.proc_cpu());
            pServerData->mServerInfo.set_proc_mem(xData.proc_mem());
            pServerData->mServerInfo.set_proc_thread(xData.proc_thread());
            pServerData->mServerInfo.set_proc_name(xData.proc_name());
            pServerData->mServerInfo.set_proc_cwd(xData.proc_cwd());
            pServerData->mServerInfo.set_proc_pid(xData.proc_pid());
            pServerData->mServerInfo.set_server_cur_online(xData.server_cur_online());
        }
    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::OnServerDumpInfoProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_STMasterServerDumpInfoNtf xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
    CHECK_NULL(pConfig);

    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByServerId(NF_ST_MASTER_SERVER, xMsg.bus_id());
    CHECK_EXPR(pServerData, -1, "can't find the serverID:{}..............................\n{}",xMsg.bus_id(), xMsg.dump_info());

    NFLogError(NF_LOG_SYSTEMLOG, 0, "ServerName:{} serverID:{} Dump...............................\n{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_name(), xMsg.dump_info());

    std::string url = pConfig->mWwwUrl+"/index.php/api/emsdump/send";
    proto_ff::emailSender sender;
    sender.set_email(pConfig->mEmail);
    sender.set_title(pServerData->mServerInfo.server_name() + "_" + pServerData->mServerInfo.bus_name() + " 服务器崩溃信息");
    sender.set_msg(xMsg.dump_info());
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(sender, &json);

    std::map<std::string, std::string> xHeaders;
    xHeaders.emplace("Accept", "application/json");
    xHeaders.emplace("Content-Type", "application/json;charset=utf-8");

    NFMessageMgr::Instance()->HttpPost(NF_ST_MASTER_SERVER, url, json, [](int code, const std::string& resp){
        NFLogError(NF_LOG_SYSTEMLOG, 0, "send dump mail, code:{} rsp:{}", code, resp);
    }, xHeaders);

    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::OnServerKillAllServerProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    proto_ff::Proto_KillAllServerNtf xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
    std::vector<NF_SHARE_PTR<NFServerData>> vec = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER);

    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pCurServer)
        {
            NFMessageMgr::Instance()->Send(pCurServer->mUnlinkId, proto_ff::NF_STS_KILL_ALL_SERVER_NTF, xMsg, 0);
        }
    }
    return 0;
}

int NFCMasterServerModule::OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "ip:{} connect master server success", ip);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "ip:{} disconnect master server success", ip);
		OnClientDisconnect(unLinkId);
	}
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCMasterServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_MASTER_SERVER_PLUGIN, 0, "other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

bool NFCMasterServerModule::Execute()
{
    ServerReport();
	return true;
}

bool NFCMasterServerModule::OnDynamicPlugin()
{
	NFMessageMgr::Instance()->CloseAllLink(NF_ST_MASTER_SERVER);

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCMasterServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
            SetTimer(10000, 10000, 0);
        }
        else if (nEventID == proto_ff::NF_EVENT_SERVER_REG_EVENT)
        {
            SetTimer(10001, 10000, 1);
        }
    }
    return 0;
}

void NFCMasterServerModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
    else if (nTimerID == 10001)
    {
        ConnectGlobalServer();
    }
}


int NFCMasterServerModule::OnClientDisconnect(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_MASTER_SERVER, unLinkId);
	if (pServerData)
	{
		NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "Server Disconnect Master Server, serverName:{}, busId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
		pServerData->mUnlinkId = 0;
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
	}
    NFMessageMgr::Instance()->DelServerLink(NF_ST_MASTER_SERVER, unLinkId);
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCMasterServerModule::SynServerToOthers(NF_SHARE_PTR<NFServerData> pServerData)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xData;

	proto_ff::ServerInfoReportList xSelfData;
	proto_ff::ServerInfoReport* pSelfData = xSelfData.add_server_list();
	*pSelfData = pServerData->mServerInfo;

	std::vector<NF_SHARE_PTR<NFServerData>> vec = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER);

	for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pServerData->mServerInfo.bus_id() != pCurServer->mServerInfo.bus_id())
        {
            if (NFServerIDUtil::GetWorldID(pServerData->mServerInfo.bus_id()) == NFServerIDUtil::GetWorldID(pCurServer->mServerInfo.bus_id()))
            {
                if (pCurServer->mServerInfo.server_state() != proto_ff::EST_CRASH)
                {
                    proto_ff::ServerInfoReport* pData = xData.add_server_list();
                    *pData = pCurServer->mServerInfo;

                    NFMessageMgr::Instance()->Send(pCurServer->mUnlinkId, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, xSelfData, 0);
                }
            }
        }
    }

	NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, xData, 0);
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

bool NFCMasterServerModule::HandleReloadServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::string serverName = req.GetQuery("Server");
    std::string serverID = req.GetQuery("ID");

    if (serverID.empty() || serverName.empty())
    {
        return false;
    }

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorReloadReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RELOAD_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleReloadAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorReloadReq reqMsg;
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RELOAD_ALL_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleRestartServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::string serverName = req.GetQuery("Server");
    std::string serverID = req.GetQuery("ID");

    if (serverID.empty() || serverName.empty())
    {
        return false;
    }

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorRestartReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RESTART_CMD_REQ, reqMsg, req.GetRequestId());
    }

    return true;
}

bool NFCMasterServerModule::HandleRestartAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorRestartReq reqMsg;
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RESTART_ALL_CMD_REQ, reqMsg, req.GetRequestId());
    }

    return true;
}

bool NFCMasterServerModule::HandleStartServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::string serverName = req.GetQuery("Server");
    std::string serverID = req.GetQuery("ID");

    if (serverID.empty() || serverName.empty())
    {
        return false;
    }

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStartReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_START_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleStartAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStartReq reqMsg;
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_START_ALL_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleStopServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::string serverName = req.GetQuery("Server");
    std::string serverID = req.GetQuery("ID");

    if (serverID.empty() || serverName.empty())
    {
        return false;
    }

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStopReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_STOP_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleStopAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStopReq reqMsg;
        NFMessageMgr::Instance()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_STOP_ALL_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleKillAllServer(uint32_t, const NFIHttpHandle &req)
{
    proto_ff::Proto_KillAllServerNtf xMsg;
    std::vector<NF_SHARE_PTR<NFServerData>> vec = NFMessageMgr::Instance()->GetAllServer(NF_ST_MASTER_SERVER);

    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pCurServer)
        {
            NFMessageMgr::Instance()->Send(pCurServer->mUnlinkId, proto_ff::NF_STS_KILL_ALL_SERVER_NTF, xMsg, 0);
        }
    }

    return true;
}

int NFCMasterServerModule::HandleStopSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStopRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStopAllSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStopRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStartSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStartAllSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleRestartSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterRestartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleRestartAllSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterRestartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleReloadSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterReloadRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleReloadAllSeverRsp(uint64_t unLinkId, uint64_t httpReqId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterReloadRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, httpReqId, msg, nLen, xMsg);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

bool NFCMasterServerModule::Init() {
    return true;
}

int NFCMasterServerModule::ConnectGlobalServer() {
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_MASTER_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_MASTER_SERVER, "tcp://www.shmnframe.com:6100", PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_MASTER_SERVER, pMasterServerData->mUnlinkId, this, &NFCMasterServerModule::OnGlobalSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_MASTER_SERVER, pMasterServerData->mUnlinkId, this, &NFCMasterServerModule::OnHandleGlobalOtherMessage);
        }
    }
    else
    {
        NFLogError(NF_LOG_MASTER_SERVER_PLUGIN, 0, "I Can't get the global Server config!");
        return -1;
    }

    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFCMasterServerModule::OnGlobalSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");

    if (nEvent == eMsgType_CONNECTED)
    {
        RegisterGlobalServer();
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {

    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::RegisterGlobalServer()
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
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
        pData->set_machine_addr(m_pPluginManager->GetMachineAddrMD5());

        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCMasterServerModule::OnHandleGlobalOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "global server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::ServerReport()
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

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
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
            pData->set_machine_addr(m_pPluginManager->GetMachineAddrMD5());
        }

        if (pData->proc_cpu() > 0 && pData->proc_mem() > 0)
        {
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
        }
    }
    return 0;
}
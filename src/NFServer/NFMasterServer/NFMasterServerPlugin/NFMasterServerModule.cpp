// -------------------------------------------------------------------------
//    @FileName         :    NFCMasterServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCMasterServerModule
//
// -------------------------------------------------------------------------

#include "NFMasterServerModule.h"

#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFDateTime.hpp"

#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"
#include "NFServerComm/NFServerMessage/proto_svr_common.pb.h"


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

	FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFCMasterServerModule::OnServerRegisterProcess);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, this, &NFCMasterServerModule::OnServerReportProcess);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_STS_SEND_DUMP_INFO_NTF, this, &NFCMasterServerModule::OnServerDumpInfoProcess);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_GTM_KILL_ALL_SERVER_NTF, this, &NFCMasterServerModule::OnServerKillAllServerProcess);
    //////////////////////http send to monitor//////////////////
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "reload", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleReloadServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "reloadall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleReloadAllServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "restart", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleRestartServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "restartall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleRestartAllServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "start", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStartServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "startall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStartAllServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "stop", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStopServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "stopall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleStopAllServer);
    FindModule<NFIMessageModule>()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "killall", NF_HTTP_REQ_GET, this, &NFCMasterServerModule::HandleKillAllServer);
    //////////////////////msg from monitor/////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_STOP_CMD_RSP, this, &NFCMasterServerModule::HandleStopSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, this, &NFCMasterServerModule::HandleRestartSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, this, &NFCMasterServerModule::HandleStartSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_CMD_RSP, this, &NFCMasterServerModule::HandleReloadSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_STOP_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleStopAllSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleRestartAllSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleStartAllSeverRsp);
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_ALL_CMD_RSP, this, &NFCMasterServerModule::HandleReloadAllSeverRsp);

	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
	if (pConfig)
	{
		int64_t unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_MASTER_SERVER, pConfig->Url, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
		if (unlinkId >= 0)
		{
			uint64_t masterServerLinkId = (uint64_t)unlinkId;
            FindModule<NFIMessageModule>()->SetServerLinkId(NF_ST_MASTER_SERVER, masterServerLinkId);
			FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFCMasterServerModule::OnProxySocketEvent);
			FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFCMasterServerModule::OnHandleOtherMessage);
			NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen success, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
		}
		else
		{
			NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen failed!, serverId:{}, ip:{}, port:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->ServerPort);
			return false;
		}

        std::string httpUrl = NF_FORMAT("http://{}:{}", pConfig->ServerIp, pConfig->HttpPort);
        int ret = FindModule<NFIMessageModule>()->BindServer(NF_ST_MASTER_SERVER, httpUrl, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (ret < 0)
        {
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "master server listen http failed!, serverId:{}, ip:{}, httpport:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->HttpPort);
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

int NFCMasterServerModule::OnServerRegisterProcess(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

	for (int i = 0; i < xMsg.server_list_size(); ++i)
	{
		const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
		NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id());
		if (!pServerData)
		{
			pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
		}
		else
		{
			if (pServerData->mServerInfo.server_type() != xData.server_type() || pServerData->mUnlinkId != unLinkId)
			{
				//该服务器ID已经注册过, 又被别的服务器使用了
				//服务器连接还在没有崩溃
				NFLogError(NF_LOG_SYSTEMLOG, 0, "server:{} connect some wrong, old server:{}", xData.server_name(), pServerData->mServerInfo.server_name());
				FindModule<NFIMessageModule>()->CloseLinkId(pServerData->mUnlinkId);
			}
		}

		pServerData->mUnlinkId = unLinkId;
		pServerData->mServerInfo = xData;
        FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_MASTER_SERVER, xData.bus_id(), pServerData->mUnlinkId);
        if (xData.server_state() == proto_ff::EST_INIT)
        {
#if NF_PLATFORM == NF_PLATFORM_WIN
            SynOtherServerToServer(pServerData);
#else
            NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
            if (pConfig && pConfig->NamingHost.empty())
            {
                SynOtherServerToServer(pServerData);
            }
#endif
        }
        else {
#if NF_PLATFORM == NF_PLATFORM_WIN
            SynServerToOthers(pServerData);
            SynOtherServerToServer(pServerData);
#else
            NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
            if (pConfig && pConfig->NamingHost.empty())
            {
                SynServerToOthers(pServerData);
                SynOtherServerToServer(pServerData);
            }
#endif
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "{} Server Register Master Server Success,  busId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
        }
	}
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCMasterServerModule::OnServerReportProcess(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_MASTER_SERVER, xData.bus_id());
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

int NFCMasterServerModule::OnServerDumpInfoProcess(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_ServerDumpInfoNtf xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    CHECK_NULL(pConfig);

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_MASTER_SERVER, xMsg.bus_id());
    CHECK_EXPR(pServerData, -1, "can't find the serverID:{}..............................\n{}",xMsg.bus_id(), xMsg.dump_info());
    pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
    SynServerToOthers(pServerData);

    NFLogError(NF_LOG_SYSTEMLOG, 0, "ServerName:{} serverID:{} Dump...............................\n{}", pServerData->mServerInfo.server_name(),
               pServerData->mServerInfo.server_id(), xMsg.dump_info());

    std::string url = pConfig->WwwUrl + "/index.php/api/emsdump/send";
    proto_ff::emailSender sender;
    sender.set_email(pConfig->Email);
    sender.set_title(pServerData->mServerInfo.server_name() + "_" + pServerData->mServerInfo.server_id() + " 服务器崩溃信息");
    sender.set_msg(xMsg.dump_info());
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(sender, &json);

    std::map<std::string, std::string> xHeaders;
    xHeaders.emplace("Accept", "application/json");
    xHeaders.emplace("Content-Type", "application/json;charset=utf-8");

    FindModule<NFIMessageModule>()->HttpPost(NF_ST_MASTER_SERVER, url, json, [](int code, const std::string& resp){
        NFLogError(NF_LOG_SYSTEMLOG, 0, "send dump mail, code:{} rsp:{}", code, resp);
    }, xHeaders);

    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::OnServerKillAllServerProcess(uint64_t unLinkId, NFDataPackage& packet)
{
    proto_ff::Proto_KillAllServerNtf xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);
    std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER);

    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pCurServer)
        {
            FindModule<NFIMessageModule>()->Send(pCurServer->mUnlinkId, NF_MODULE_NONE, proto_ff::NF_STS_KILL_ALL_SERVER_NTF, xMsg);
        }
    }
    return 0;
}

int NFCMasterServerModule::OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
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

int NFCMasterServerModule::OnHandleOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_MASTER_SERVER_PLUGIN, 0, "other message not handled:packet:{},ip:{}", packet.ToString(), ip);
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
	FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_MASTER_SERVER);

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
	NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_MASTER_SERVER, unLinkId);
	if (pServerData)
	{
		NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "Server Disconnect Master Server, serverName:{}, busId:{}, ip:{}, port:{}", pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
		pServerData->mUnlinkId = 0;
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
	}
    FindModule<NFIMessageModule>()->DelServerLink(NF_ST_MASTER_SERVER, unLinkId);
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCMasterServerModule::SynOtherServerToServer(NF_SHARE_PTR<NFServerData> pServerData)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xData;

    std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER);

    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pCurServer->mServerInfo.bus_id() != pServerData->mServerInfo.bus_id())
        {
            if (pCurServer->mServerInfo.server_state() > proto_ff::EST_INIT)
            {
                if (NFServerIDUtil::GetWorldID(pCurServer->mServerInfo.bus_id()) == NFServerIDUtil::GetWorldID(pServerData->mServerInfo.bus_id()))
                {
                    if (NFServerIDUtil::GetZoneID(pCurServer->mServerInfo.bus_id()) == NFServerIDUtil::GetZoneID(pServerData->mServerInfo.bus_id()))
                    {
                        proto_ff::ServerInfoReport* pData = xData.add_server_list();
                        *pData = pCurServer->mServerInfo;
                    }
                }
            }
        }
    }

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, xData, 0);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::SynServerToOthers(NF_SHARE_PTR<NFServerData> pServerData)
{
	NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
	proto_ff::ServerInfoReportList xSelfData;
	proto_ff::ServerInfoReport* pSelfData = xSelfData.add_server_list();
	*pSelfData = pServerData->mServerInfo;

	std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER);

	for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pServerData->mServerInfo.bus_id() != pCurServer->mServerInfo.bus_id())
        {
            if (NFServerIDUtil::GetWorldID(pServerData->mServerInfo.bus_id()) == NFServerIDUtil::GetWorldID(pCurServer->mServerInfo.bus_id()))
            {
                FindModule<NFIMessageModule>()->Send(pCurServer->mUnlinkId, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, xSelfData, 0);
            }
        }
    }

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

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorReloadReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RELOAD_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleReloadAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorReloadReq reqMsg;
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RELOAD_ALL_CMD_REQ, reqMsg, req.GetRequestId());
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

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorRestartReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RESTART_CMD_REQ, reqMsg, req.GetRequestId());
    }

    return true;
}

bool NFCMasterServerModule::HandleRestartAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorRestartReq reqMsg;
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_RESTART_ALL_CMD_REQ, reqMsg, req.GetRequestId());
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

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStartReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_START_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleStartAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStartReq reqMsg;
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_START_ALL_CMD_REQ, reqMsg, req.GetRequestId());
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

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStopReq reqMsg;
        reqMsg.set_server_name(serverName);
        reqMsg.set_server_id(serverID);
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_STOP_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleStopAllServer(uint32_t, const NFIHttpHandle &req)
{
    std::string uri = req.GetOriginalUri();
    std::string remote = req.GetRemoteHost();
    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, " remote:{} send url:{}", remote, uri);

    std::vector<NF_SHARE_PTR<NFServerData>> vecServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER, NF_ST_MONITOR_SERVER);
    for(int i = 0; i < (int)vecServer.size(); i++)
    {
        proto_ff::Proto_MasterTMonitorStopReq reqMsg;
        FindModule<NFIMessageModule>()->Send(vecServer[i]->mUnlinkId, proto_ff::NF_MasterTMonitor_STOP_ALL_CMD_REQ, reqMsg, req.GetRequestId());
    }
    return true;
}

bool NFCMasterServerModule::HandleKillAllServer(uint32_t, const NFIHttpHandle &req)
{
    proto_ff::Proto_KillAllServerNtf xMsg;
    std::vector<NF_SHARE_PTR<NFServerData>> vec = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_MASTER_SERVER);

    for(size_t i = 0; i < vec.size(); i++)
    {
        NF_SHARE_PTR<NFServerData> pCurServer = vec[i];
        if (pCurServer)
        {
            FindModule<NFIMessageModule>()->Send(pCurServer->mUnlinkId, proto_ff::NF_STS_KILL_ALL_SERVER_NTF, xMsg, 0);
        }
    }

    return true;
}

int NFCMasterServerModule::HandleStopSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStopRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStopAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStopRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStartSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleStartAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterStartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleRestartSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterRestartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleRestartAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterRestartRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleReloadSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterReloadRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::HandleReloadAllSeverRsp(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_MonitorTMasterReloadRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t httpReqId = packet.nParam1;
    std::string json;
    NFProtobufCommon::ProtoMessageToJson(xMsg, &json);
    FindModule<NFIMessageModule>()->ResponseHttpMsg(NF_ST_MASTER_SERVER, httpReqId, json);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

bool NFCMasterServerModule::Init() {
    return true;
}

int NFCMasterServerModule::ConnectGlobalServer() {
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = FindModule<NFIMessageModule>()->GetMasterData(NF_ST_MASTER_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = FindModule<NFIMessageModule>()->ConnectServer(NF_ST_MASTER_SERVER, "tcp://www.shmnframe.com:6100", PACKET_PARSE_TYPE_INTERNAL);
            FindModule<NFIMessageModule>()->AddEventCallBack(NF_ST_MASTER_SERVER, pMasterServerData->mUnlinkId, this, &NFCMasterServerModule::OnGlobalSocketEvent);
            FindModule<NFIMessageModule>()->AddOtherCallBack(NF_ST_MASTER_SERVER, pMasterServerData->mUnlinkId, this, &NFCMasterServerModule::OnHandleGlobalOtherMessage);
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
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        pData->set_bus_id(pConfig->BusId);
        pData->set_server_id(pConfig->ServerId);
        pData->set_server_type(pConfig->ServerType);
        pData->set_server_name(pConfig->ServerName);

        pData->set_bus_length(pConfig->BusLength);
        pData->set_link_mode(pConfig->LinkMode);
        pData->set_url(pConfig->Url);
        pData->set_server_ip(pConfig->ServerIp);
        pData->set_server_port(pConfig->ServerPort);
        pData->set_route_svr(pConfig->RouteAgent);
        pData->set_server_state(proto_ff::EST_NARMAL);
        pData->set_machine_addr(m_pObjPluginManager->GetMachineAddrMD5());

        FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCMasterServerModule::OnHandleGlobalOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- begin --");
    std::string ip = FindModule<NFIMessageModule>()->GetLinkIp(unLinkId);
    NFLogWarning(NF_LOG_WORLD_SERVER_PLUGIN, 0, "global server other message not handled:packet:{},ip:{}", packet.ToString(), ip);
    NFLogTrace(NF_LOG_WORLD_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCMasterServerModule::ServerReport()
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

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_MASTER_SERVER);
    if (pConfig)
    {
        proto_ff::ServerInfoReportList xMsg;
        proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        pData->set_bus_id(pConfig->BusId);
        pData->set_server_id(pConfig->ServerId);
        pData->set_server_type(pConfig->ServerType);
        pData->set_server_name(pConfig->ServerName);

        pData->set_bus_length(pConfig->BusLength);
        pData->set_link_mode(pConfig->LinkMode);
        pData->set_url(pConfig->Url);
        pData->set_server_ip(pConfig->ServerIp);
        pData->set_server_port(pConfig->ServerPort);
        pData->set_server_state(proto_ff::EST_NARMAL);
        pData->set_route_svr(pConfig->RouteAgent);
        NFIMonitorModule* pMonitorModule = m_pObjPluginManager->FindModule<NFIMonitorModule>();
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
            pData->set_machine_addr(m_pObjPluginManager->GetMachineAddrMD5());
        }

        if (pData->proc_cpu() > 0 && pData->proc_mem() > 0)
        {
            FindModule<NFIServerMessageModule>()->SendMsgToMasterServer(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
        }
    }
    return 0;
}
// -------------------------------------------------------------------------
//    @FileName         :    NFGlobalServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGlobalServerModule
//
// -------------------------------------------------------------------------

#include "NFGlobalServerModule.h"

#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFDateTime.hpp"

#include <NFComm/NFPluginModule/NFConfigMgr.h>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_web.pb.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"

NFGlobalServerModule::NFGlobalServerModule(NFIPluginManager* p):NFIDynamicModule(p)
{
}

NFGlobalServerModule::~NFGlobalServerModule()
{
}

bool NFGlobalServerModule::Awake()
{
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this, &NFGlobalServerModule::OnServerRegisterProcess);
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_MASTER_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, this, &NFGlobalServerModule::OnServerReportProcess);

    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "stopserver", NF_HTTP_REQ_GET, this, &NFGlobalServerModule::HandleKillServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "killserver", NF_HTTP_REQ_GET, this, &NFGlobalServerModule::HandleKillServer);
    NFMessageMgr::Instance()->AddHttpRequestHandler(NF_ST_MASTER_SERVER, "killserver", NF_HTTP_REQ_POST, this, &NFGlobalServerModule::HandleKillServer);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_MASTER_SERVER);
    if (pConfig)
    {
        int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_MASTER_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            uint64_t masterServerLinkId = (uint64_t)unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_MASTER_SERVER, masterServerLinkId);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFGlobalServerModule::OnProxySocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_MASTER_SERVER, masterServerLinkId, this, &NFGlobalServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "global server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "global server listen failed!, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }

        std::string httpUrl = NF_FORMAT("http://{}:{}", pConfig->mServerIp, pConfig->mHttpPort);
        int ret = NFMessageMgr::Instance()->BindServer(NF_ST_MASTER_SERVER, httpUrl,  pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (ret < 0)
        {
            NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "global server listen http failed!, serverId:{}, ip:{}, httpport:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mHttpPort);
            return false;
        }

        int iRet = FindModule<NFIAsyMysqlModule>()->AddMysqlServer(pConfig->mMysqlDbName, pConfig->mMysqlIp,
                                                                   pConfig->mMysqlPort, pConfig->mMysqlDbName,
                                                                   pConfig->mMysqlUser, pConfig->mMysqlPassword);
        if (iRet != 0) {
            NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, -1, "global server connect mysql failed");
            return false;
        }

        GetServerMgrFromDB();
    }
    else
    {
        NFLogError(NF_LOG_MASTER_SERVER_PLUGIN, 0, "I Can't get the Global Server config!");
        return false;
    }

    return true;
}

int NFGlobalServerModule::OnProxySocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    if (nEvent == eMsgType_CONNECTED)
    {
        NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "ip:{} connect global server success", ip);
    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "ip:{} disconnect global server success", ip);
        OnClientDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGlobalServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    NFLogWarning(NF_LOG_MASTER_SERVER_PLUGIN, 0, "other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

bool NFGlobalServerModule::Execute()
{
    return true;
}

bool NFGlobalServerModule::OnDynamicPlugin()
{
    NFMessageMgr::Instance()->CloseAllLink(NF_ST_MASTER_SERVER);

    return true;
}

void NFGlobalServerModule::OnTimer(uint32_t nTimerID)
{

}

int NFGlobalServerModule::OnClientDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    NFMessageMgr::Instance()->DelServerLink(NF_ST_MASTER_SERVER, unLinkId);
    for(auto iter = m_contractServerData.begin(); iter != m_contractServerData.end(); iter++)
    {
        auto pListServerData = iter->second.First();
        while (pListServerData)
        {
            for(int i = 0; i < (int)pListServerData->size(); i++)
            {
                auto pServerData = (*pListServerData)[i];
                if (pServerData && pServerData->mUnlinkId == unLinkId)
                {
                    pServerData->mUnlinkId = 0;
                    pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
                    NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "Constract Server Disconnect Global Server Success, Constract Info:{}, Machine Addr:{} Ip:{}", pServerData->mServerInfo.contract_info(), pServerData->mServerInfo.machine_addr(), pServerData->mServerInfo.server_ip());

                    proto_ff::tbServerMgr* pServerMgr = GetServerDataByContractInfoFromDB(pServerData->mServerInfo.contract_info(), pServerData->mServerInfo.machine_addr(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.bus_name());
                    if (pServerMgr)
                    {
                        pServerMgr->set_last_logout_time(NFTime::Now().UnixSec());
                        pServerMgr->set_server_desc("掉线");
                        SaveServerMgr(pServerMgr);
                    }

                }
            }
            pListServerData = iter->second.Next();
        }
    }

    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGlobalServerModule::OnServerRegisterProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = GetServerDataByContractInfo(xData.contract_info(), xData.machine_addr(), ip, xData.bus_name());
        if (!pServerData)
        {
            pServerData = CreateServerData(xData.contract_info(), xData.machine_addr(), ip, xData.bus_name());
        }

        pServerData->mUnlinkId = unLinkId;
        pServerData->mServerInfo = xData;
        pServerData->mServerInfo.set_server_ip(ip);

        proto_ff::tbServerMgr* pServerMgr = GetServerDataByContractInfoFromDB(pServerData->mServerInfo.contract_info(), pServerData->mServerInfo.machine_addr(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.bus_name());
        if (pServerMgr)
        {
            pServerMgr->set_last_login_time(NFTime::Now().UnixSec());
            pServerMgr->set_server_desc("在线");
            pServerMgr->set_cur_count(pServerMgr->cur_count() + 1);
            SaveServerMgr(pServerMgr);
        }

        NFLogInfo(NF_LOG_MASTER_SERVER_PLUGIN, 0, "Constract Server Register Global Server Success, Constract Info:{}, Machine Addr:{} Ip:{}", xData.contract_info(), xData.machine_addr(), ip);
    }
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGlobalServerModule::OnServerReportProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_MASTER_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
    for (int i = 0; i < xMsg.server_list_size(); ++i) {
        const proto_ff::ServerInfoReport &xData = xMsg.server_list(i);
        NF_SHARE_PTR<NFServerData> pServerData = GetServerDataByContractInfo(xData.contract_info(), xData.machine_addr(), ip, xData.bus_name());
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

NF_SHARE_PTR<NFServerData> NFGlobalServerModule::GetServerDataByContractInfo(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id){
    auto pListServerData = m_contractServerData[contractInfo].GetElement(machineAddr);
    if (pListServerData)
    {
        for(int i = 0; i < (int)pListServerData->size(); i++)
        {
            auto pServerData = (*pListServerData)[i];
            if (pServerData && pServerData->mServerInfo.server_ip() == ip && pServerData->mServerInfo.bus_name() == server_id)
            {
                proto_ff::tbServerMgr* pServerMgr = GetServerDataByContractInfoFromDB(contractInfo, machineAddr, ip, server_id);
                if (pServerMgr == NULL)
                {
                    pServerMgr = CreateServerDataFromDB(contractInfo, machineAddr, ip, server_id);
                }

                pServerMgr->set_last_login_time(NFTime::Now().UnixSec());

                SaveServerMgr(pServerMgr);

                return pServerData;
            }
        }
    }

    return NULL;
}

NF_SHARE_PTR<NFServerData> NFGlobalServerModule::CreateServerData(const string & contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id){
    auto pListServerData = m_contractServerData[contractInfo].GetElement(machineAddr);
    if (!pListServerData)
    {
        pListServerData = NF_SHARE_PTR<std::vector<NF_SHARE_PTR<NFServerData>>>(NF_NEW std::vector<NF_SHARE_PTR<NFServerData>>());
        m_contractServerData[contractInfo].AddElement(machineAddr, pListServerData);
    }

    auto pServerData = NF_SHARE_PTR<NFServerData>(NF_NEW NFServerData());
    if (pServerData)
    {
        proto_ff::tbServerMgr* pServerMgr = GetServerDataByContractInfoFromDB(contractInfo, machineAddr, ip, server_id);
        if (pServerMgr == NULL)
        {
            pServerMgr = CreateServerDataFromDB(contractInfo, machineAddr, ip, server_id);
        }

        pServerMgr->set_last_login_time(NFTime::Now().UnixSec());

        SaveServerMgr(pServerMgr);

        pListServerData->push_back(pServerData);
        return pServerData;
    }

    return NULL;
}

bool NFGlobalServerModule::HandleKillServer(uint32_t, const NFIHttpHandle &req)
{
    proto_ff::Proto_Web_KillServer data;
    WEB_MSG_PROCESS_WITH_PRINTF(data, req);

    NF_SHARE_PTR<NFServerData> pServerData = GetServerDataByContractInfo(data.contract(), data.machine_addr(), data.ip(), data.bus_name());
    if (pServerData)
    {
        proto_ff::Proto_KillAllServerNtf reqMsg;
        NFMessageMgr::Instance()->Send(pServerData->mUnlinkId, proto_ff::NF_GTM_KILL_ALL_SERVER_NTF, reqMsg);
    }
    else
    {
        proto_ff::Proto_Web_CommonRspNotify rspNotify;
        rspNotify.set_result(-1);

        std::string json;
        NFProtobufCommon::ProtoMessageToJson(rspNotify, &json);

        NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, data.request_id(), json, NFWebStatus::WEB_OK);
        return 0;
    }

    proto_ff::Proto_Web_CommonRspNotify rspNotify;
    rspNotify.set_result(0);

    std::string json;
    NFProtobufCommon::ProtoMessageToJson(rspNotify, &json);

    NFMessageMgr::Instance()->ResponseHttpMsg(NF_ST_MASTER_SERVER, data.request_id(), json, NFWebStatus::WEB_OK);

    return true;
}

bool NFGlobalServerModule::HandleStopServer(uint32_t, const NFIHttpHandle &req)
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

int NFGlobalServerModule::GetServerMgrFromDB()
{
    std::vector<NF_SHARE_PTR<proto_ff::tbServerMgr>> vec;

    std::vector<storesvr_sqldata::storesvr_vk> vk_list;

    storesvr_sqldata::storesvr_sel select;
    select.mutable_baseinfo()->set_dbname(NF_DEFAULT_MYSQL_DB_NAME);
    select.mutable_baseinfo()->set_tbname("tbServerMgr");
    select.mutable_baseinfo()->set_clname("tbServerMgr");

    select.mutable_sel_cond()->set_mod_key(0);

    select.mutable_sel_cond()->set_where_additional_conds("");
    for (size_t i = 0; i < vk_list.size(); i++) {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_sel_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    storesvr_sqldata::storesvr_sel_res select_res;
    FindModule<NFIAsyMysqlModule>()->SelectByCond(select.baseinfo().dbname(), select,
        [=] (int iRet, storesvr_sqldata::storesvr_sel_res& select_res) mutable {
        if (iRet != 0) {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetServerMgrFromDB Failed, error:{}", iRet);
        } else {
            for(int i = 0; i < (int)select_res.sel_records_size(); i++)
            {
                proto_ff::tbServerMgr msgData;
                msgData.ParseFromString(select_res.sel_records(i));
                msgData.set_cur_count(0);

                std::vector<proto_ff::tbServerMgr>& vec = this->m_contractServerMgr[msgData.contract()][msgData.machine_addr()];
                vec.push_back(msgData);
            }
        }
    });
    return 0;
}

proto_ff::tbServerMgr* NFGlobalServerModule::GetServerDataByContractInfoFromDB(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id)
{
    std::vector<proto_ff::tbServerMgr>& vec = this->m_contractServerMgr[contractInfo][machineAddr];
    for(int i = 0; i < (int)vec.size(); i++)
    {
        if (vec[i].contract() == contractInfo &&
            vec[i].machine_addr() == machineAddr &&
            vec[i].ip() == ip &&
            vec[i].bus_name() == server_id)
            return &vec[i];
    }
    return NULL;
}

proto_ff::tbServerMgr* NFGlobalServerModule::CreateServerDataFromDB(const std::string& contractInfo, const std::string& machineAddr, const std::string &ip, const std::string &server_id)
{
    std::vector<proto_ff::tbServerMgr>& vec = this->m_contractServerMgr[contractInfo][machineAddr];
    proto_ff::tbServerMgr data;
    data.set_id(FindModule<NFIKernelModule>()->Get64UUID());
    data.set_contract(contractInfo);
    data.set_machine_addr(machineAddr);
    data.set_ip(ip);
    data.set_bus_name(server_id);
    data.set_create_time(NFTime::Now().UnixSec());
    vec.push_back(data);

    return &vec.back();
}

int NFGlobalServerModule::SaveServerMgr(const proto_ff::tbServerMgr* pMgr)
{
    storesvr_sqldata::storesvr_modinsobj select;
    select.mutable_baseinfo()->set_dbname(NF_DEFAULT_MYSQL_DB_NAME);
    select.mutable_baseinfo()->set_tbname("tbServerMgr");
    select.mutable_baseinfo()->set_clname("tbServerMgr");
    select.set_mod_key(0);

    select.set_modins_record(pMgr->SerializeAsString());

    FindModule<NFIAsyMysqlModule>()->UpdateObj(select.baseinfo().dbname(), select,
    [=](int iRet, storesvr_sqldata::storesvr_modinsobj_res& select_res) mutable {
      if (iRet != 0) {
          NFLogError(NF_LOG_SYSTEMLOG, 0, "SaveServerMgr error:{}", iRet);
      } else {
          NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SaveServerMgr success:{}", iRet);
      }
    });

    return 0;
}
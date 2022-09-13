// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFCStoreServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"

#define STORE_SERVER_CONNECT_MASTER_SERVER "StoreServer Connect MasterServer"
#define STORE_SERVER_CONNECT_ROUTE_AGENT_SERVER "StoreServer Connect RouteAgentServer"

NFCStoreServerModule::NFCStoreServerModule(NFIPluginManager* p):NFIStoreServerModule(p)
{
}

NFCStoreServerModule::~NFCStoreServerModule()
{
}

bool NFCStoreServerModule::Awake() {
    //不需要固定帧，需要尽可能跑得快
    m_pPluginManager->SetFixedFrame(false);

    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_STORE_SERVER);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_STORE_SERVER,
                                                       proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER, this,
                                                       &NFCStoreServerModule::OnHandleServerReport);

    //////other server///////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_STORE_SERVER, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD,
                                                       this,
                                                       &NFCStoreServerModule::OnHandleStoreReq);

    /////////////////route agent msg///////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_STORE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP, this, &NFCStoreServerModule::OnRegisterRouteAgentRspProcess);


    //注册要完成的服务器启动任务
	m_pPluginManager->RegisterAppTask(NF_ST_STORE_SERVER, APP_INIT_CONNECT_MASTER, STORE_SERVER_CONNECT_MASTER_SERVER);
	m_pPluginManager->RegisterAppTask(NF_ST_STORE_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER, STORE_SERVER_CONNECT_ROUTE_AGENT_SERVER);

    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
    if (pConfig) {
        m_pPluginManager->SetIdelSleepUs(pConfig->mIdleSleepUs);

        FindModule<NFINamingModule>()->ClearDBInfo(NF_ST_STORE_SERVER);
		for (int i = 0; i < (int)pConfig->mVecMysqlDbName.size(); i++)
		{
			int iRet = FindModule<NFIAsyMysqlModule>()->AddMysqlServer(pConfig->mVecMysqlDbName[i], pConfig->mMysqlIp,
				pConfig->mMysqlPort, pConfig->mVecMysqlDbName[i],
				pConfig->mMysqlUser, pConfig->mMysqlPassword);
			if (iRet != 0) {
				NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, -1, "store server connect mysql failed");
				return false;
			}

            FindModule<NFINamingModule>()->RegisterDBInfo(NF_ST_STORE_SERVER, pConfig->mVecMysqlDbName[i]);
		}

        int64_t unlinkId = NFMessageMgr::Instance()->BindServer(NF_ST_STORE_SERVER, pConfig->mUrl, pConfig->mNetThreadNum, pConfig->mMaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (unlinkId >= 0)
        {
            /*
                注册客户端事件
            */
            uint64_t loginServerLinkId = (uint64_t) unlinkId;
            NFMessageMgr::Instance()->SetServerLinkId(NF_ST_STORE_SERVER, loginServerLinkId);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_STORE_SERVER, loginServerLinkId, this, &NFCStoreServerModule::OnStoreSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_STORE_SERVER, loginServerLinkId, this, &NFCStoreServerModule::OnHandleOtherMessage);
            NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "store server listen success, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_LOGIN_SERVER_PLUGIN, 0, "store server listen failed, serverId:{}, ip:{}, port:{}", pConfig->mBusName, pConfig->mServerIp, pConfig->mServerPort);
            return false;
        }

        if (pConfig->mLinkMode == "bus")
        {
            int iRet = NFMessageMgr::Instance()->ResumeConnect(NF_ST_STORE_SERVER);
            if (iRet == 0)
            {
                std::vector<NF_SHARE_PTR<NFServerData>> vecServer = NFMessageMgr::Instance()->GetAllServer(
                        NF_ST_STORE_SERVER);
                for (int i = 0; i < (int) vecServer.size(); i++)
                {
                    NF_SHARE_PTR<NFServerData> pServerData = vecServer[i];
                    if (pServerData && pServerData->mUnlinkId > 0)
                    {
                        if (pServerData->mServerInfo.server_type() == NF_ST_ROUTE_AGENT_SERVER)
                        {
                            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_STORE_SERVER, pServerData->mUnlinkId, this, &NFCStoreServerModule::OnRouteAgentServerSocketEvent);
                            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_STORE_SERVER, pServerData->mUnlinkId, this, &NFCStoreServerModule::OnHandleRouteAgentOtherMessage);

                            auto pRouteServer = NFMessageMgr::Instance()->GetRouteData(NF_ST_STORE_SERVER);
                            pRouteServer->mUnlinkId = pServerData->mUnlinkId;
                            pRouteServer->mServerInfo = pServerData->mServerInfo;
                        }
                    }
                }
            }
        }
	}
	else
	{
		NFLogError(NF_LOG_STORE_SERVER_PLUGIN, 0, "I Can't get the store Server config!");
		return false;
	}

    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	return true;
}

int NFCStoreServerModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
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

void NFCStoreServerModule::OnTimer(uint32_t nTimerID) {
    if (nTimerID == 10000) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCStoreServerModule::ConnectMasterServer(const proto_ff::ServerInfoReport& xData)
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
    if (pConfig)
    {
        auto pMasterServerData = NFMessageMgr::Instance()->GetMasterData(NF_ST_STORE_SERVER);
        if (pMasterServerData->mUnlinkId <= 0)
        {
            pMasterServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_STORE_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);
            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_STORE_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCStoreServerModule::OnMasterSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_STORE_SERVER, pMasterServerData->mUnlinkId, this,
                                                       &NFCStoreServerModule::OnHandleMasterOtherMessage);
        }

        pMasterServerData->mServerInfo = xData;
    }
    else
    {
        NFLogError(NF_LOG_STORE_SERVER_PLUGIN, 0, "I Can't get the store Server config!");
        return -1;
    }

    return 0;
}

bool NFCStoreServerModule::Init()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
    NF_ASSERT(pConfig);

#if NF_PLATFORM == NF_PLATFORM_WIN
	proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_STORE_SERVER);
	int32_t ret = ConnectMasterServer(masterData);
	CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
#else
    if (pConfig->mNamingHost.empty())
    {
        proto_ff::ServerInfoReport masterData = FindModule<NFINamingModule>()->GetDefaultMasterInfo(NF_ST_STORE_SERVER);
        int32_t ret = ConnectMasterServer(masterData);
        CHECK_EXPR(ret == 0, false, "ConnectMasterServer Failed, url:{}", masterData.DebugString());
    }
#endif

    FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_STORE_SERVER, NF_ST_MASTER_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
        if (errCode != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch, MasterServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());

            return;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch MasterServer name:{} serverInfo:{}", name, xData.DebugString());

        int32_t ret = ConnectMasterServer(xData);
        CHECK_EXPR(ret == 0, , "ConnectMasterServer Failed, url:{}", xData.DebugString());
    });

    if (pConfig->mLinkMode == "bus")
    {
        FindModule<NFINamingModule>()->WatchBusUrls(NF_ST_STORE_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }
    else
    {
        FindModule<NFINamingModule>()->WatchTcpUrls(NF_ST_STORE_SERVER, NF_ST_ROUTE_AGENT_SERVER, [this](const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode){
            if (errCode != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch, AgentServer Dump, errCode:{} name:{} serverInfo:{}", errCode, name, xData.DebugString());
                return;
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "StoreServer Watch AgentServer name:{} serverInfo:{}", name, xData.DebugString());

            OnHandleRouteAgentReport(xData);
        });
    }

    return true;
}

bool NFCStoreServerModule::Execute()
{
    ServerReport();
	return true;
}

bool NFCStoreServerModule::OnDynamicPlugin()
{
	NFMessageMgr::Instance()->CloseAllLink(NF_ST_STORE_SERVER);
	return true;
}

int
NFCStoreServerModule::OnHandleStoreReq(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId,
                                       const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
    NF_ASSERT(pConfig);

    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NET, NF_ST_STORE_SERVER, 0);

    proto_ff::Proto_SvrPkg retMsg;
    retMsg.set_msg_id(xMsg.msg_id());
    *retMsg.mutable_store_info()->mutable_cb_data() = xMsg.store_info().cb_data();

    switch (xMsg.store_info().cmd()) {
        case proto_ff::E_STORESVR_C2S_SELECT: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_SELECT);

            storesvr_sqldata::storesvr_sel select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 0)
                {
                    uint32_t index = select.sel_cond().mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->SelectByCond(select.baseinfo().dbname(), select,
                    [=] (int iRet, storesvr_sqldata::storesvr_sel_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_BUSY);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_SELECTOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_SELECTOBJ);

            storesvr_sqldata::storesvr_selobj select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 0)
                {
                    uint32_t index = select.mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->SelectObj(select.baseinfo().dbname(), select,
                    [=](int iRet, storesvr_sqldata::storesvr_selobj_res& select_res) mutable {
                if (iRet != 0) {
                    if (iRet == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY && select_res.sel_opres().zdb_errmsg().empty()) {
                        retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY);
                    } else {
                        retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UNKNOWN);
                    }
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_INSERT: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_INSERT);

            storesvr_sqldata::storesvr_ins select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 0)
                {
                    uint32_t index = select.mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->InsertObj(select.baseinfo().dbname(), select,
                    [=](int iRet, storesvr_sqldata::storesvr_ins_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_INSERTFAILED);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETE: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_DELETE);

            storesvr_sqldata::storesvr_del select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 0)
                {
                    uint32_t index = select.del_cond().mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->DeleteByCond(select.baseinfo().dbname(), select,
                    [=](int iRet, storesvr_sqldata::storesvr_del_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UNKNOWN);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETEOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_DELETEOBJ);

            storesvr_sqldata::storesvr_delobj select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 0)
                {
                    uint32_t index = select.mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->DeleteObj(select.baseinfo().dbname(), select,
                    [=](int iRet, storesvr_sqldata::storesvr_delobj_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_DELETEFAILED);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODIFY: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODIFY);

            storesvr_sqldata::storesvr_mod select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 0) {
                    uint32_t index = select.mod_cond().mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->ModifyByCond(select.baseinfo().dbname(), select,
           [=] (int iRet, storesvr_sqldata::storesvr_mod_res& select_res) mutable {
               if (iRet != 0) {
                   retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEFAILED);
               } else {
                   retMsg.set_msg_data(select_res.SerializeAsString());
               }

               NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
               if (retMsg.store_info().cb_data().id() > 0)
                   NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
           });
        }
        break;
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODIFYOBJ);

            storesvr_sqldata::storesvr_modobj select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 0) {
                    uint32_t index = select.mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->ModifyObj(select.baseinfo().dbname(), select,
                    [=] (int iRet, storesvr_sqldata::storesvr_modobj_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEFAILED);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODINS: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODINS);

            storesvr_sqldata::storesvr_modins select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 0) {
                    uint32_t index = select.mod_cond().mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->UpdateByCond(select.baseinfo().dbname(), select,
                   [=](int iRet, storesvr_sqldata::storesvr_modins_res& select_res) mutable {
                       if (iRet != 0) {
                           retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEINSERTFAILED);
                       } else {
                           retMsg.set_msg_data(select_res.SerializeAsString());
                       }

                       NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                       if (retMsg.store_info().cb_data().id() > 0)
                           NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
                   });
        }
        break;
        case proto_ff::E_STORESVR_C2S_MODINSOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODINSOBJ);

            storesvr_sqldata::storesvr_modinsobj select;
            select.ParseFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 0) {
                    uint32_t index = select.mod_key() % count;
                    std::string newTableName = select.baseinfo().tbname() + "_" + NFCommon::tostr(index);
                    select.mutable_baseinfo()->set_tbname(newTableName);
                }
            }

            FindModule<NFIAsyMysqlModule>()->UpdateObj(select.baseinfo().dbname(), select,
                    [=](int iRet, storesvr_sqldata::storesvr_modinsobj_res& select_res) mutable {
                if (iRet != 0) {
                    retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEINSERTFAILED);
                } else {
                    retMsg.set_msg_data(select_res.SerializeAsString());
                }

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                if (retMsg.store_info().cb_data().id() > 0)
                    NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_EXECUTE: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_EXECUTE);

            storesvr_sqldata::storesvr_execute select;
            select.ParseFromString(xMsg.msg_data());

            FindModule<NFIAsyMysqlModule>()->Execute(select.baseinfo().dbname(), select,
               [=] (int iRet, storesvr_sqldata::storesvr_execute_res& select_res) mutable {
                   if (iRet != 0) {
                       retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEFAILED);
                   } else {
                       retMsg.set_msg_data(select_res.SerializeAsString());
                   }

                   NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                   if (retMsg.store_info().cb_data().id() > 0)
                       NFMessageMgr::Instance()->Send(unLinkId, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, sendLinkId, destLinkId);
               });
        }
            break;
        default: {

        }
            break;
    }

    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

/*
	处理Master服务器链接事件
*/
int NFCStoreServerModule::OnMasterSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");

	if (nEvent == eMsgType_CONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogDebug(NF_LOG_STORE_SERVER_PLUGIN, 0, "store server connect master success!");
		RegisterMasterServer();

		//完成服务器启动任务
		if (!m_pPluginManager->IsInited())
		{
			m_pPluginManager->FinishAppTask(NF_ST_STORE_SERVER, APP_INIT_CONNECT_MASTER);
		}
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
		NFLogError(NF_LOG_STORE_SERVER_PLUGIN, 0, "store server disconnect master success");
	}
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

/*
	处理Master服务器未注册协议
*/
int NFCStoreServerModule::OnHandleMasterOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
	std::string ip = NFMessageMgr::Instance()->GetLinkIp(unLinkId);
	NFLogWarning(NF_LOG_STORE_SERVER_PLUGIN, 0, "master server other message not handled:playerId:{},msgId:{},ip:{}", playerId, nMsgId, ip);
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::RegisterMasterServer()
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
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

        for (int i = 0; i < (int)pConfig->mVecMysqlDbName.size(); i++)
        {
            pData->add_db_name_list(pConfig->mVecMysqlDbName[i]);
        }

		NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_STORE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg);
	}
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::ServerReport()
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

	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
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

        for (int i = 0; i < (int)pConfig->mVecMysqlDbName.size(); i++)
        {
            pData->add_db_name_list(pConfig->mVecMysqlDbName[i]);
        }

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
			NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_STORE_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT, xMsg);
		}
	}
	return 0;
}

int NFCStoreServerModule::OnHandleServerReport(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");

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
		default:
			break;
		}
	}
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::OnHandleRouteAgentReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_ROUTE_AGENT_SERVER, -1, "xData.server_type() == NF_ST_ROUTE_AGENT_SERVER");
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
    CHECK_NULL(pConfig);

    if (!m_pPluginManager->IsLoadAllServer())
    {
        if (pConfig->mRouteAgent != xData.bus_name())
        {
            return 0;
        }
    }

    auto pRouteAgentServerData = NFMessageMgr::Instance()->GetRouteData(NF_ST_STORE_SERVER);
    CHECK_NULL(pRouteAgentServerData);

    if (pRouteAgentServerData->mUnlinkId == 0)
    {
        pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_STORE_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

        NFMessageMgr::Instance()->AddEventCallBack(NF_ST_STORE_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCStoreServerModule::OnRouteAgentServerSocketEvent);
        NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_STORE_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCStoreServerModule::OnHandleRouteAgentOtherMessage);
    }
    else {
        if (pRouteAgentServerData->mUnlinkId > 0 && pRouteAgentServerData->mServerInfo.url() != xData.url()) {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the server:{} old url:{} changed, new url:{}",
                         pRouteAgentServerData->mServerInfo.server_name(), pRouteAgentServerData->mServerInfo.url(),
                         xData.url());
            NFMessageMgr::Instance()->CloseLinkId(pRouteAgentServerData->mUnlinkId);

            pRouteAgentServerData->mUnlinkId = NFMessageMgr::Instance()->ConnectServer(NF_ST_STORE_SERVER, xData.url(), PACKET_PARSE_TYPE_INTERNAL);

            NFMessageMgr::Instance()->AddEventCallBack(NF_ST_STORE_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCStoreServerModule::OnRouteAgentServerSocketEvent);
            NFMessageMgr::Instance()->AddOtherCallBack(NF_ST_STORE_SERVER, pRouteAgentServerData->mUnlinkId, this, &NFCStoreServerModule::OnHandleRouteAgentOtherMessage);
        }
    }

    pRouteAgentServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCStoreServerModule::OnRouteAgentServerSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
	if (nEvent == eMsgType_CONNECTED)
	{
		NFLogDebug(NF_LOG_STORE_SERVER_PLUGIN, 0, "store server connect route agent server success!");

        RegisterRouteAgentServer(unLinkId);
	}
	else if (nEvent == eMsgType_DISCONNECTED)
	{
		NFLogError(NF_LOG_STORE_SERVER_PLUGIN, 0, "store server disconnect route agent server success");
	}
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::OnHandleRouteAgentOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
	NFLogWarning(NF_LOG_STORE_SERVER_PLUGIN, playerId, "msg:{} not handled!", nMsgId);
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::RegisterRouteAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_STORE_SERVER);
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
	NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCStoreServerModule::OnStoreSocketEvent(eMsgType nEvent, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
    if (nEvent == eMsgType_CONNECTED)
    {

    }
    else if (nEvent == eMsgType_DISCONNECTED)
    {
        OnHandleServerDisconnect(unLinkId);
    }
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCStoreServerModule::OnHandleOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
    NFLogWarning(NF_LOG_STORE_SERVER_PLUGIN, playerId, "msg:{} not handled!", nMsgId);
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCStoreServerModule::OnHandleServerDisconnect(uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");
    NF_SHARE_PTR<NFServerData> pServerData = NFMessageMgr::Instance()->GetServerByUnlinkId(NF_ST_STORE_SERVER, unLinkId);
    if (pServerData)
    {
        pServerData->mServerInfo.set_server_state(proto_ff::EST_CRASH);
        pServerData->mUnlinkId = 0;

        NFLogError(NF_LOG_STORE_SERVER_PLUGIN, 0, "the server disconnect from store server, serverName:{}, busid:{}, serverIp:{}, serverPort:{}"
        , pServerData->mServerInfo.server_name(), pServerData->mServerInfo.bus_id(), pServerData->mServerInfo.server_ip(), pServerData->mServerInfo.server_port());
    }

    NFMessageMgr::Instance()->DelServerLink(NF_ST_STORE_SERVER, unLinkId);
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCStoreServerModule::OnRegisterRouteAgentRspProcess(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId,
                                                       const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- begin --");

    //完成服务器启动任务
    if (!m_pPluginManager->IsInited())
    {
        m_pPluginManager->FinishAppTask(NF_ST_STORE_SERVER, APP_INIT_CONNECT_ROUTE_AGENT_SERVER);
    }

    FindModule<NFINamingModule>()->RegisterAppInfo(NF_ST_STORE_SERVER);

    NFLogTrace(NF_LOG_STORE_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
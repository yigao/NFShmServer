// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFCStoreServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFIMysqlModule.h"

#define STORE_SERVER_TIMER_CLOSE_MYSQL 200

NFCStoreServerModule::NFCStoreServerModule(NFIPluginManager* p):NFIStoreServerModule(p)
{
}

NFCStoreServerModule::~NFCStoreServerModule()
{
}

bool NFCStoreServerModule::Awake() {
    SetConnectProxyAgentServer(false);
    SetCheckStoreServer(false);

    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_STORE_SERVER);

    //////other server///////////////////////////////////
    RegisterServerMessage(NF_ST_STORE_SERVER, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD);

    if (!LoadPbAndCheckDB())
    {
        return false;
    }

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_STORE_SERVER);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", NF_ST_STORE_SERVER);

    FindModule<NFINamingModule>()->ClearDBInfo(NF_ST_STORE_SERVER);
    int iRet = FindModule<NFIAsyMysqlModule>()->AddMysqlServer(pConfig->MysqlConfig.MysqlDbName, pConfig->MysqlConfig.MysqlIp,
        pConfig->MysqlConfig.MysqlPort, pConfig->MysqlConfig.MysqlDbName,
        pConfig->MysqlConfig.MysqlUser, pConfig->MysqlConfig.MysqlPassword);
    if (iRet != 0) {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "store server connect mysql failed");
        return false;
    }

    FindModule<NFINamingModule>()->RegisterDBInfo(NF_ST_STORE_SERVER, pConfig->MysqlConfig.MysqlDbName);

    BindServer();

	return true;
}

int NFCStoreServerModule::OnTimer(uint32_t nTimerID)
{
    NFIStoreServerModule::OnTimer(nTimerID);
    if (nTimerID == STORE_SERVER_TIMER_CLOSE_MYSQL)
    {
        FindModule<NFIMysqlModule>()->CloseMysql(INFORMATION_SCHEMA);
        KillTimer(STORE_SERVER_TIMER_CLOSE_MYSQL);
    }

    return 0;
}

struct DBTableColCreateInfo
{
    bool bExistTable = false;
    std::map<std::string, DBTableColInfo> primaryKey;
    std::multimap<uint32_t, std::string> needCreateColumn;
};

bool NFCStoreServerModule::LoadPbAndCheckDB()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_STORE_SERVER);
    CHECK_EXPR_ASSERT(pConfig, false, "GetAppConfig Failed, server type:{}", NF_ST_STORE_SERVER);

    int iRet = NFProtobufCommon::Instance()->LoadProtoDsFile(m_pObjPluginManager->GetConfigPath() + "/" + pConfig->LoadProtoDs);
    if (iRet == 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Reload proto ds success:{}", pConfig->LoadProtoDs);
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Reload proto ds fail:{}", pConfig->LoadProtoDs);
        return false;
    }

    KillTimer(STORE_SERVER_TIMER_CLOSE_MYSQL);

    iRet = FindModule<NFIMysqlModule>()->AddMysqlServer(INFORMATION_SCHEMA, pConfig->MysqlConfig.MysqlIp,
                                                        pConfig->MysqlConfig.MysqlPort, INFORMATION_SCHEMA,
                                                        pConfig->MysqlConfig.MysqlUser, pConfig->MysqlConfig.MysqlPassword);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server connect mysql failed");
        return false;
    }

    bool bExistDB;
    iRet = FindModule<NFIMysqlModule>()->ExistsDB(INFORMATION_SCHEMA, pConfig->MysqlConfig.MysqlDbName, bExistDB);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server ExistsDB failed");
        return false;
    }

    if (!bExistDB)
    {
        iRet = FindModule<NFIMysqlModule>()->CreateDB(INFORMATION_SCHEMA, pConfig->MysqlConfig.MysqlDbName);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server CreateDB failed");
            return false;
        }
    }

    std::map<std::string, DBTableColCreateInfo> tbCreateInfo;
    for(int i = 0; i < (int)pConfig->MysqlConfig.TBConfList.size(); i++)
    {
        struct proto_ff_s::pbTableConfig_s& tableConfig = pConfig->MysqlConfig.TBConfList[i];
        if (tableConfig.TableName.empty()) continue;

        DBTableColCreateInfo& createInfo = tbCreateInfo[tableConfig.TableName];

        iRet = FindModule<NFIMysqlModule>()->QueryTableInfo(INFORMATION_SCHEMA, pConfig->MysqlConfig.MysqlDbName, tableConfig.TableName, createInfo.bExistTable, createInfo.primaryKey, createInfo.needCreateColumn);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server CreateDB failed");
            return false;
        }
    }

    iRet = FindModule<NFIMysqlModule>()->SelectDB(INFORMATION_SCHEMA, pConfig->MysqlConfig.MysqlDbName);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server SelectDB failed");
        return false;
    }

    for(auto iter = tbCreateInfo.begin(); iter != tbCreateInfo.end(); iter++)
    {
        std::string tableName = iter->first;
        DBTableColCreateInfo& createInfo = iter->second;
        if (!createInfo.bExistTable)
        {
            iRet = FindModule<NFIMysqlModule>()->CreateTable(INFORMATION_SCHEMA, tableName, createInfo.primaryKey, createInfo.needCreateColumn);
            if (iRet != 0)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server CreateTable failed");
                return false;
            }
        }
        else {
            iRet = FindModule<NFIMysqlModule>()->AddTableRow(INFORMATION_SCHEMA, tableName, createInfo.needCreateColumn);
            if (iRet != 0)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server CreateTable failed");
                return false;
            }
        }
    }

    iRet = FindModule<NFIMysqlModule>()->SelectDB(INFORMATION_SCHEMA, INFORMATION_SCHEMA);
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, -1, "store server SelectDB failed");
        return false;
    }

    SetTimer(STORE_SERVER_TIMER_CLOSE_MYSQL, 60000, 0);
    return true;
}

bool NFCStoreServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCStoreServerModule::Execute()
{
	return true;
}

bool NFCStoreServerModule::OnDynamicPlugin()
{
	FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_STORE_SERVER);
	return true;
}

bool NFCStoreServerModule::OnReloadConfig()
{
    return LoadPbAndCheckDB();
}

int NFCStoreServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    int retCode = 0;
    switch (packet.nMsgId)
    {
        case proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD:
            retCode = OnHandleStoreReq(unLinkId, packet);
            break;
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "msg:({}) not handle", packet.ToString());
            break;
    }

    if (retCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "msg:({}) handle exist error", packet.ToString());
    }
    return 0;
}

int
NFCStoreServerModule::OnHandleStoreReq(uint64_t unLinkId, NFDataPackage& packet) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_STORE_SERVER);
    NF_ASSERT(pConfig);

    proto_ff::Proto_SvrPkg xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, pConfig->BusId, 0);
    uint64_t destLinkId = GetUnLinkId(NF_IS_NONE, 0, packet.nSrcId, 0);

    proto_ff::Proto_SvrPkg retMsg;
    retMsg.set_msg_id(xMsg.msg_id());
    *retMsg.mutable_store_info()->mutable_cb_data() = xMsg.store_info().cb_data();

    switch (xMsg.store_info().cmd()) {
        case proto_ff::E_STORESVR_C2S_SELECT: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_SELECT);

            storesvr_sqldata::storesvr_sel select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 1)
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_SELECTOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_SELECTOBJ);

            storesvr_sqldata::storesvr_selobj select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 1)
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_INSERT: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_INSERT);

            storesvr_sqldata::storesvr_ins select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 1)
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETE: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_DELETE);

            storesvr_sqldata::storesvr_del select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 1)
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETEOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_DELETEOBJ);

            storesvr_sqldata::storesvr_delobj select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end())
            {
                uint32_t count = iter->second;
                if (count > 1)
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODIFY: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODIFY);

            storesvr_sqldata::storesvr_mod select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 1) {
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
                   FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
           });
        }
        break;
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODIFYOBJ);

            storesvr_sqldata::storesvr_modobj select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 1) {
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODINS: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODINS);

            storesvr_sqldata::storesvr_modins select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 1) {
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
                           FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
                   });
        }
        break;
        case proto_ff::E_STORESVR_C2S_MODINSOBJ: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_MODINSOBJ);

            storesvr_sqldata::storesvr_modinsobj select;
            select.ParsePartialFromString(xMsg.msg_data());

            auto iter = pConfig->mTBConfMap.find(select.baseinfo().tbname());
            if (iter != pConfig->mTBConfMap.end()) {
                uint32_t count = iter->second;
                if (count > 1) {
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
                    FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
            });
        }
            break;
        case proto_ff::E_STORESVR_C2S_EXECUTE: {
            retMsg.mutable_store_info()->set_cmd(proto_ff::E_STORESVR_S2C_EXECUTE);

            storesvr_sqldata::storesvr_execute select;
            select.ParsePartialFromString(xMsg.msg_data());

            FindModule<NFIAsyMysqlModule>()->Execute(select.baseinfo().dbname(), select,
               [=] (int iRet, storesvr_sqldata::storesvr_execute_res& select_res) mutable {
                   if (iRet != 0) {
                       retMsg.mutable_store_info()->set_err_code(proto_ff::E_STORESVR_ERRCODE_UPDATEFAILED);
                   } else {
                       retMsg.set_msg_data(select_res.SerializeAsString());
                   }

                   NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ret msg:{}", retMsg.Utf8DebugString());
                   if (retMsg.store_info().cb_data().id() > 0)
                       FindModule<NFIMessageModule>()->Send(unLinkId, NF_MODULE_SERVER, proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD, retMsg, 0, 0, sendLinkId, destLinkId);
               });
        }
            break;
        default: {

        }
            break;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

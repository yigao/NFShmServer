// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFServerMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"

NFServerMessageModule::NFServerMessageModule(NFIPluginManager *pPluginManager) : NFIServerMessageModule(pPluginManager)
{

}

NFServerMessageModule::~NFServerMessageModule()
{

}

int NFServerMessageModule::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1,
                                                 uint64_t nParam2)
{
    auto pServerData = FindModule<NFIMessageModule>()->GetMasterData(eSendType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) eSendType);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nMsgId, xData, nParam1, nParam2);
    return 0;
}

int NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                               uint64_t nParam1, uint64_t nParam2)
{
    return SendProxyMsgByBusId(eType, nDstId, NF_MODULE_SERVER, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId,
                                               const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int
NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t nParam1,
                                           uint64_t nParam2)
{
    return SendProxyMsgByBusId(eType, nDstId, NF_MODULE_SERVER, nMsgId, msg, nLen, nParam1, nParam2);
}

int NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const char *msg,
                                               uint32_t nLen, uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, msg, nLen, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int NFServerMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                                uint64_t nParam1, uint64_t nParam2)
{
    return SendMsgToProxyServer(eType, nDstId, NF_MODULE_SERVER, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId,
                                                const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
        return 0;
    }

    pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);
    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int NFServerMessageModule::SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1,
                                                uint64_t nParam2)
{
    return SendMsgToWorldServer(eType, NF_MODULE_SERVER, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                                uint64_t nParam1, uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_WORLD_SERVER, 0, 0, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                               uint64_t nParam1, uint64_t nParam2)
{
    return SendMsgToGameServer(eType, nDstId, NF_MODULE_SERVER, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId,
                                               const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_GAME_SERVER, 0, nDstId, nModuleId, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                                uint64_t nParam1, uint64_t nParam2)
{
    return SendMsgToLogicServer(eType, nDstId, NF_MODULE_SERVER, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId,
                                                const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_LOGIC_SERVER, 0, nDstId, nModuleId, nMsgId, xData, nParam1, nParam2);
}

std::string storesvr_selectbycond(const std::string &dbname, const std::string &tbname,
                                  uint64_t mod_key, const std::vector<std::string> &fields, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", int maxRecords = 100, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_sel select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    for (int i = 0; i < (int) fields.size(); i++)
    {
        select.mutable_baseinfo()->add_sel_fields(fields[i]);
    }
    select.mutable_baseinfo()->set_max_records(maxRecords);

    select.mutable_sel_cond()->set_mod_key(mod_key);

    select.mutable_sel_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_sel_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}

// select对象查询，返回打包数据，该数据可直接网络发送
std::string storesvr_selectobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_selobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_sel_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// insert对象插入，返回打包数据
std::string storesvr_insert(const std::string &dbname, const std::string &tbname,
                            uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_ins select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_ins_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按条件删除
std::string storesvr_deletebycond(const std::string &dbname, const std::string &tbname,
                                  uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_del select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.mutable_del_cond()->set_mod_key(mod_key);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_del_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}

// 按对象删除
std::string storesvr_delete(const std::string &dbname, const std::string &tbname,
                            uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_delobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_del_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

std::string storesvr_modifybycond(const std::string &dbname, const std::string &tbname,
                                  uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                  const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_mod select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }

    select.mutable_mod_cond()->set_mod_key(mod_key);

    select.mutable_mod_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按对象修改
std::string storesvr_modifyobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_modobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}


std::string storesvr_modinsbycond(const std::string &dbname, const std::string &tbname,
                                  uint64_t mod_key, const ::google::protobuf::Message &msg_obj,
                                  const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_modins select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }

    select.mutable_mod_cond()->set_mod_key(mod_key);

    select.mutable_mod_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++)
    {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 修改插入
std::string storesvr_modinsobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string &cls_name = "")
{
    storesvr_sqldata::storesvr_modinsobj select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_modins_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按对象修改
std::string storesvr_execute(const std::string &dbname, const std::string &tbname,
                             uint64_t mod_key, const std::string &msg, const std::string &cls_name)
{
    storesvr_sqldata::storesvr_execute select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.set_mod_key(mod_key);
    select.set_execute_record(msg + ";");
    return select.SerializeAsString();
}

// 按对象修改
std::string storesvr_execute_more(const std::string &dbname, const std::string &tbname,
                             uint64_t mod_key, const std::string &msg, int max_records, const std::string &cls_name)
{
    storesvr_sqldata::storesvr_execute_more select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    if (cls_name.empty())
    {
        select.mutable_baseinfo()->set_clname(tbname);
    }
    else
    {
        select.mutable_baseinfo()->set_clname(cls_name);
    }
    select.mutable_baseinfo()->set_max_records(max_records);
    select.set_mod_key(mod_key);
    select.set_execute_record(msg + ";");
    return select.SerializeAsString();
}

int
NFServerMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id, const std::string &dbname,
                                              const std::string &table_name, const google::protobuf::Message &xData,
                                              std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                              const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                              uint64_t mod_key, const std::string &cls_name, uint8_t packet_type)
{
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_MODIFY || cmd == proto_ff::E_STORESVR_C2S_MODINS, -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), -1, "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType) packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id(table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    switch (cmd)
    {
        case proto_ff::E_STORESVR_C2S_MODIFY:
        {
            svrPkg.set_msg_data(storesvr_modifybycond(dbname, table_name, mod_key, xData, vk_list, where_addtional_conds, cls_name));
            break;
        }
        case proto_ff::E_STORESVR_C2S_MODINS:
        {
            svrPkg.set_msg_data(storesvr_modinsbycond(dbname, table_name, mod_key, xData, vk_list, where_addtional_conds, cls_name));
            break;
        }
        default:
        {
            break;
        }
    }

    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, 0, dstBusId, NF_MODULE_SERVER,
                                                           proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg);
}

int
NFServerMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id, const std::string &dbname,
                                              const std::string &table_name, const std::vector<std::string>& vecFields,
                                              std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                              const std::string &where_addtional_conds, int max_records, int trans_id, uint32_t seq,
                                              uint64_t mod_key, const std::string &cls_name, uint8_t packet_type)
{
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_SELECT || cmd == proto_ff::E_STORESVR_C2S_DELETE, -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), -1, "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType) packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id(table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    switch (cmd)
    {
        case proto_ff::E_STORESVR_C2S_SELECT:
        {
            svrPkg.set_msg_data(
                    storesvr_selectbycond(dbname, table_name, mod_key, vecFields, vk_list, where_addtional_conds, max_records, cls_name));
            break;
        }
        case proto_ff::E_STORESVR_C2S_DELETE:
        {
            svrPkg.set_msg_data(storesvr_deletebycond(dbname, table_name, mod_key, vk_list, cls_name));
            break;
        }
        default:
        {
            break;
        }
    }
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, 0, dstBusId, NF_MODULE_SERVER,
                                                           proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg);
}

int
NFServerMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                                              const std::string &dbname, const std::string &table_name, const std::string &xData, int max_records,
                                              int trans_id, uint32_t seq,
                                              uint64_t mod_key, const std::string &cls_name, uint8_t packet_type)
{
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_EXECUTE_MORE, -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::STORESVR_CS_COMMAND_IsValid(cmd), -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), -1, "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType) packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id(table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "message:{}", xData.DebugString());
    switch (cmd)
    {
        case proto_ff::E_STORESVR_C2S_EXECUTE_MORE:
        {
            svrPkg.set_msg_data(storesvr_execute_more(dbname, table_name, mod_key, xData, max_records, cls_name));
        }
            break;
        default:
        {

        }
            break;
    }
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, 0, dstBusId, NF_MODULE_SERVER,
                                                           proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg);
}

int
NFServerMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
                                              const std::string &dbname, const std::string &table_name, const std::string &xData,
                                              int trans_id, uint32_t seq,
                                              uint64_t mod_key, const std::string &cls_name, uint8_t packet_type)
{
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_EXECUTE, -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::STORESVR_CS_COMMAND_IsValid(cmd), -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), -1, "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType) packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id(table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "message:{}", xData.DebugString());
    switch (cmd)
    {
        case proto_ff::E_STORESVR_C2S_EXECUTE:
        {
            svrPkg.set_msg_data(storesvr_execute(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        default:
        {

        }
            break;
    }
    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, 0, dstBusId, NF_MODULE_SERVER,
                                                           proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg);
}

int
NFServerMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id, const std::string &dbname,
                                              const std::string &table_name, const google::protobuf::Message &xData, int trans_id,
                                              uint32_t seq,
                                              uint64_t mod_key, const std::string &cls_name, uint8_t packet_type)
{
    CHECK_EXPR(!(cmd == proto_ff::E_STORESVR_C2S_SELECT || cmd == proto_ff::E_STORESVR_C2S_DELETE || cmd == proto_ff::E_STORESVR_C2S_MODIFY ||
                 cmd == proto_ff::E_STORESVR_C2S_MODINS), -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::STORESVR_CS_COMMAND_IsValid(cmd), -1, "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), -1, "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType) packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id(table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "message:{}", xData.DebugString());
    switch (cmd)
    {
        case proto_ff::E_STORESVR_C2S_SELECT:
        {
            std::vector<storesvr_sqldata::storesvr_vk> vk_list;
            svrPkg.set_msg_data(storesvr_selectbycond(dbname, table_name, mod_key, std::vector<std::string>(), vk_list, "", 100, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_SELECTOBJ:
        {
            svrPkg.set_msg_data(storesvr_selectobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_INSERT:
        {
            svrPkg.set_msg_data(storesvr_insert(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETE:
        {
            std::vector<storesvr_sqldata::storesvr_vk> vk_list;
            svrPkg.set_msg_data(storesvr_deletebycond(dbname, table_name, mod_key, vk_list, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETEOBJ:
        {
            svrPkg.set_msg_data(storesvr_delete(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ:
        {
            svrPkg.set_msg_data(storesvr_modifyobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODINSOBJ:
        {
            svrPkg.set_msg_data(storesvr_modinsobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        default:
        {

        }
            break;
    }

    return FindModule<NFIMessageModule>()->SendMsgToServer(eType, NF_ST_STORE_SERVER, 0, dstBusId, NF_MODULE_SERVER,
                                                           proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg);
}


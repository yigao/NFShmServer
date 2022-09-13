// -------------------------------------------------------------------------
//    @FileName         :    NFCMsgModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFStringUtility.h>
#include "NFCMessageModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFShmCore/NFDescStoreTrans.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"

NFCMessageModule::NFCMessageModule(NFIPluginManager *p) : NFIMessageModule(p) {
    NFMessageMgr::Instance()->Init(this);
    m_pPluginManager = p;
    m_driver = NULL;
    mxCallBack.resize(NF_ST_MAX);
    mServerLinkData.resize(NF_ST_MAX);
    for (size_t i = 0; i < mServerLinkData.size(); i++) {
        mServerLinkData[i].mServerType = (NF_SERVER_TYPES) i;
    }
}

NFCMessageModule::~NFCMessageModule()
{
	mxCallBack.clear();
	NFMessageMgr::Instance()->UnInit();
}

bool NFCMessageModule::Awake()
{
    if (m_driver != NULL) {
        return true;
    }

	NFIMessageDriver* pDriver = FindModule<NFIMessageDriver>();
	if (pDriver)
	{
		SetMessageDriver(pDriver);
	}

    return true;
}

bool NFCMessageModule::Finalize()
{
	mxCallBack.clear();
	return true;
}

bool NFCMessageModule::Execute()
{
	return true;
}

bool NFCMessageModule::OnReloadPlugin()
{
	return true;
}

void NFCMessageModule::SetMessageDriver(NFIMessageDriver* driver)
{
	m_driver = driver;
	m_driver->SetRecvCB(this, &NFCMessageModule::OnReceiveNetPack);
	m_driver->SetEventCB(this, &NFCMessageModule::OnSocketNetEvent);
    m_driver->SetHttpRecvCB(this, &NFCMessageModule::OnHttpReceiveNetPack);
    m_driver->SetHttpFilterCB(this, &NFCMessageModule::OnHttpFilterPack);
}

int64_t NFCMessageModule::BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nNetThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType)
{
	if (m_driver)
	{
		return m_driver->BindServer(eServerType, url, nNetThreadNum, nMaxConnectNum, nPacketParseType);
	}
	return -1;
}

int64_t NFCMessageModule::ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType)
{
	if (m_driver)
	{
		return m_driver->ConnectServer(eServerType, url, nPacketParseType);
	}
	return -1;
}

int NFCMessageModule::ResumeConnect(NF_SERVER_TYPES eServerType)
{
    if (m_driver)
    {
        return m_driver->ResumeConnect(eServerType);
    }
    return -1;
}

std::string NFCMessageModule::GetLinkIp(uint64_t usLinkId)
{
	if (m_driver)
	{
		return m_driver->GetLinkIp(usLinkId);
	}
	return std::string();
}

void NFCMessageModule::CloseLinkId(uint64_t usLinkId)
{
	if (m_driver)
	{
		m_driver->CloseLinkId(usLinkId);
	}

    uint32_t serverType = GetServerTypeFromUnlinkId(usLinkId);

    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        DelAllCallBack((NF_SERVER_TYPES)serverType, usLinkId);
        DelServerLink((NF_SERVER_TYPES)serverType, usLinkId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId)
{
    if (m_driver)
    {
        m_driver->Send(usLinkId, nMsgID, strData, nSendValue, nSendId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    if (m_driver)
    {
        m_driver->Send(usLinkId, nMsgID, msg, nLen, nSendValue, nSendId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue, uint64_t nSendId)
{
    if (m_driver)
    {
        m_driver->Send(usLinkId, nMsgID, xData, nSendValue, nSendId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue, uint64_t nSendId)
{
    if (m_driver)
    {
        m_driver->Send(usLinkId, nMainMsgID, nSubMsgID, strData, nSendValue, nSendId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    if (m_driver)
    {
        m_driver->Send(usLinkId, nMainMsgID, nSubMsgID, msg, nLen, nSendValue, nSendId);
    }
}

void NFCMessageModule::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID,
                            const google::protobuf::Message &xData, uint64_t nSendValue, uint64_t nSendId) {
    if (m_driver) {
        m_driver->Send(usLinkId, nMainMsgID, nSubMsgID, xData, nSendValue, nSendId);
    }
}

void NFCMessageModule::SendTrans(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData,
                                 uint64_t nSendValue, uint64_t nSendId, uint32_t req_trans_id, uint32_t rsp_trans_id) {
    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(nMsgID);
    svrPkg.mutable_disp_info()->set_req_trans_id(req_trans_id);
    svrPkg.mutable_disp_info()->set_rsp_trans_id(rsp_trans_id);
    svrPkg.set_msg_data(xData.SerializeAsString());

    Send(usLinkId, proto_ff::NF_SERVER_TO_SERVER_TRANS_CMD, svrPkg, nSendValue, nSendId);
}

std::string storesvr_selectbycond(const std::string &dbname, const std::string &tbname,
                                  uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", const std::string& cls_name = "") {
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

    select.mutable_sel_cond()->set_mod_key(mod_key);

    select.mutable_sel_cond()->set_where_additional_conds(additional_conds);
    for (size_t i = 0; i < vk_list.size(); i++) {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_sel_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}

// select对象查询，返回打包数据，该数据可直接网络发送
std::string storesvr_selectobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string& cls_name = "") {
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
                            uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string& cls_name = "") {
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
                                  uint64_t mod_key, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list, const std::string& cls_name = "") {
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
    for (size_t i = 0; i < vk_list.size(); i++) {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_del_cond()->add_where_conds();
        *pvk = vk_list[i];
    }
    return select.SerializeAsString();
}

// 按对象删除
std::string storesvr_delete(const std::string &dbname, const std::string &tbname,
                            uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string& cls_name = "") {
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
                                  uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", const std::string& cls_name = "") {
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
    for (size_t i = 0; i < vk_list.size(); i++) {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 按对象修改
std::string storesvr_modifyobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string& cls_name = "") {
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
                                  uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::vector<storesvr_sqldata::storesvr_vk> &vk_list,
                                  const std::string &additional_conds = "", const std::string& cls_name = "") {
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
    for (size_t i = 0; i < vk_list.size(); i++) {
        ::storesvr_sqldata::storesvr_vk *pvk = select.mutable_mod_cond()->add_where_conds();
        *pvk = vk_list[i];
    }

    select.set_mod_record(msg_obj.SerializeAsString());
    return select.SerializeAsString();
}

// 修改插入
std::string storesvr_modinsobj(const std::string &dbname, const std::string &tbname,
                               uint64_t mod_key, const ::google::protobuf::Message &msg_obj, const std::string& cls_name = "") {
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
                            uint64_t mod_key, const std::string &msg) {
    storesvr_sqldata::storesvr_execute select;
    select.mutable_baseinfo()->set_dbname(dbname);
    select.mutable_baseinfo()->set_tbname(tbname);
    select.set_mod_key(mod_key);
    select.set_execute_record(msg+";");
    return select.SerializeAsString();
}

void NFCMessageModule::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId,
                                 uint64_t destLinkId, const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                 std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                 const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                 uint64_t mod_key, uint8_t packet_type, const std::string& cls_name) {
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_MODIFY || cmd == proto_ff::E_STORESVR_C2S_MODINS, , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::TableID_IsValid(table_id), , "error table_id:{}", table_id);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), , "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType)packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id((proto_ff::TableID) table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    switch (cmd) {
        case proto_ff::E_STORESVR_C2S_MODIFY: {
            svrPkg.set_msg_data(storesvr_modifybycond(dbname, table_name, mod_key, xData, vk_list, where_addtional_conds, cls_name));
            break;
        }
        case proto_ff::E_STORESVR_C2S_MODINS: {
            svrPkg.set_msg_data(storesvr_modinsbycond(dbname, table_name, mod_key, xData, vk_list, where_addtional_conds, cls_name));
            break;
        }
        default: {
            break;
        }
    }

    Send(usLinkId, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg, sendLinkId, destLinkId);
}

void NFCMessageModule::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId,
                                 uint64_t destLinkId, const std::string &dbname, const std::string &table_name,
                                 std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                 const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                 uint64_t mod_key, uint8_t packet_type, const std::string& cls_name) {
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_SELECT || cmd == proto_ff::E_STORESVR_C2S_DELETE, , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::TableID_IsValid(table_id), , "error table_id:{}", table_id);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), , "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND) cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType)packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id((proto_ff::TableID) table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    switch (cmd) {
        case proto_ff::E_STORESVR_C2S_SELECT: {
            svrPkg.set_msg_data(storesvr_selectbycond(dbname, table_name, mod_key, vk_list, where_addtional_conds, cls_name));
            break;
        }
        case proto_ff::E_STORESVR_C2S_DELETE: {
            svrPkg.set_msg_data(storesvr_deletebycond(dbname, table_name, mod_key, vk_list, cls_name));
            break;
        }
        default: {
            break;
        }
    }

    Send(usLinkId, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg, sendLinkId, destLinkId);
}

void
NFCMessageModule::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
          const std::string &dbname, const std::string &table_name, const std::string &xData, int trans_id, uint32_t seq,
          uint64_t mod_key, uint8_t packet_type)
{
    CHECK_EXPR(cmd == proto_ff::E_STORESVR_C2S_EXECUTE, , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::STORESVR_CS_COMMAND_IsValid(cmd), , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::TableID_IsValid(table_id), , "error table_id:{}", table_id);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), , "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND)cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType)packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id((proto_ff::TableID) table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    //NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "message:{}", xData.DebugString());
    switch (cmd) {
        case proto_ff::E_STORESVR_C2S_EXECUTE: {
            svrPkg.set_msg_data(storesvr_execute(dbname, table_name, mod_key, xData));
        }
            break;
        default: {

        }
            break;
    }

    Send(usLinkId, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg, sendLinkId, destLinkId);
}

void NFCMessageModule::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId,
                                 uint64_t destLinkId, const std::string &dbname,
                                 const std::string &table_name, const google::protobuf::Message &xData, int trans_id,
                                 uint32_t seq,
                                 uint64_t mod_key, uint8_t packet_type, const std::string& cls_name) {
    CHECK_EXPR(!(cmd == proto_ff::E_STORESVR_C2S_SELECT || cmd == proto_ff::E_STORESVR_C2S_DELETE || cmd == proto_ff::E_STORESVR_C2S_MODIFY || cmd == proto_ff::E_STORESVR_C2S_MODINS), , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::STORESVR_CS_COMMAND_IsValid(cmd), , "error cmd:{}", cmd);
    CHECK_EXPR(proto_ff::TableID_IsValid(table_id), , "error table_id:{}", table_id);
    CHECK_EXPR(proto_ff::PacketDispType_IsValid(packet_type), , "error msg_type:{}", packet_type);

    proto_ff::Proto_SvrPkg svrPkg;
    svrPkg.set_msg_id(0);
    svrPkg.mutable_store_info()->set_cmd((proto_ff::STORESVR_CS_COMMAND)cmd);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_type((proto_ff::PacketDispType)packet_type);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_table_id((proto_ff::TableID) table_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_id(trans_id);
    svrPkg.mutable_store_info()->mutable_cb_data()->set_seq(seq);

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "cmd:{} table_id:{} table_name:{} trans_id:{} seq:{} mod_key:{}",
               cmd, table_id, table_name, trans_id, seq, mod_key);

    //NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "message:{}", xData.DebugString());
    switch (cmd) {
        case proto_ff::E_STORESVR_C2S_SELECT: {
            std::vector<storesvr_sqldata::storesvr_vk> vk_list;
            svrPkg.set_msg_data(storesvr_selectbycond(dbname, table_name, mod_key, vk_list, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_SELECTOBJ: {
            svrPkg.set_msg_data(storesvr_selectobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_INSERT: {
            svrPkg.set_msg_data(storesvr_insert(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETE: {
            std::vector<storesvr_sqldata::storesvr_vk> vk_list;
            svrPkg.set_msg_data(storesvr_deletebycond(dbname, table_name, mod_key, vk_list, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_DELETEOBJ: {
            svrPkg.set_msg_data(storesvr_delete(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ: {
            svrPkg.set_msg_data(storesvr_modifyobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        case proto_ff::E_STORESVR_C2S_MODINSOBJ: {
            svrPkg.set_msg_data(storesvr_modinsobj(dbname, table_name, mod_key, xData, cls_name));
        }
            break;
        default: {

        }
            break;
    }

    Send(usLinkId, proto_ff::NF_SERVER_TO_STORE_SERVER_DB_CMD, svrPkg, sendLinkId, destLinkId);
}

bool NFCMessageModule::DelAllCallBack(NF_SERVER_TYPES eType, uint64_t unLinkId)
{
    if (eType < mxCallBack.size() && unLinkId > 0) {
        mxCallBack[eType].mxEventCallBack.erase(unLinkId);
        mxCallBack[eType].mxCallBackList.erase(unLinkId);
        return true;
    }

    return true;
}

bool NFCMessageModule::DelAllCallBack(void *pTarget) {
    for (size_t i = 0; i < mxCallBack.size(); i++) {
        for (auto iter = mxCallBack[i].mxReceiveCallBack.begin(); iter != mxCallBack[i].mxReceiveCallBack.end();) {
            if (iter->second.m_pTarget == pTarget) {
                iter = mxCallBack[i].mxReceiveCallBack.erase(iter);
            } else {
                iter++;
            }
        }

		for (auto iter = mxCallBack[i].mxEventCallBack.begin(); iter != mxCallBack[i].mxEventCallBack.end();)
		{
			if (iter->second.m_pTarget == pTarget)
			{
				iter = mxCallBack[i].mxEventCallBack.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		for (auto iter = mxCallBack[i].mxCallBackList.begin(); iter != mxCallBack[i].mxCallBackList.end();)
		{
			if (iter->second.m_pTarget == pTarget)
			{
				iter = mxCallBack[i].mxCallBackList.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}
	return true;
}

bool NFCMessageModule::AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTarget,
                                          const NET_RECEIVE_FUNCTOR &cb) {
    if (eType < mxCallBack.size()) {
        mxCallBack[eType].mxReceiveCallBack[nMsgID] = NetReceiveFunctor(pTarget, cb);
        return true;
    }
    return false;
}

bool NFCMessageModule::AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTarget,
                                        const NET_RECEIVE_FUNCTOR &cb) {
    if (eType < mxCallBack.size()) {
        mxCallBack[eType].mxCallBackList[linkId] = NetReceiveFunctor(pTarget, cb);
        return true;
    }
    return false;
}

bool NFCMessageModule::AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void* pTarget, const NET_EVENT_FUNCTOR& cb)
{
	if (eType < mxCallBack.size())
	{
		mxCallBack[eType].mxEventCallBack[linkId] = NetEventFunctor(pTarget, cb);
		return true;
	}
	return false;
}

int NFCMessageModule::OnHandleReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, uint64_t nSendValue, uint64_t nOtherValue,
	uint32_t nMsgId, const char *msg, uint32_t nLen)
{
	uint32_t eServerType = GetServerTypeFromUnlinkId(objectLinkId);
	if (eServerType < mxCallBack.size()) {
		uint64_t startTime = NFGetMicroSecondTime();
        auto it2 = mxCallBack[eServerType].mxReceiveCallBack.find(nMsgId);
        if (it2 != mxCallBack[eServerType].mxReceiveCallBack.end()) {
            NET_RECEIVE_FUNCTOR &pFun = it2->second.m_pFunctor;
            if (pFun)
            {
                int iRet = pFun(objectLinkId, nSendValue, nOtherValue, nMsgId, msg, nLen);
                it2->second.m_iCount++;
                uint64_t useTime = NFGetMicroSecondTime() - startTime;
                it2->second.m_iAllUseTime += useTime;
                if (useTime > it2->second.m_iMaxTime)
                {
                    it2->second.m_iMaxTime = useTime;
                }
                if (useTime < it2->second.m_iMinTime)
                {
                    it2->second.m_iMinTime = useTime;
                }
                if (useTime/1000 > 33)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "nMsgId:{} use time:{} ms, too long", nMsgId, useTime/1000);
                }
                //1009 1010 heartbeat
                if (nMsgId != 1009 && nMsgId != 1010 && nMsgId != 1 && nMsgId != 2)
                    NFLogTrace(NF_LOG_RECV_MSG, 0, "nMsgId:{} value1:{} value2:{} use time:{} us, count:{} allTime:{} perTime:{} minTime:{} maxTime:{}",
                               nMsgId, nSendValue, nOtherValue, useTime, it2->second.m_iCount, it2->second.m_iAllUseTime, it2->second.m_iAllUseTime/it2->second.m_iCount, it2->second.m_iMinTime, it2->second.m_iMaxTime);
                CHECK_RET(iRet, "nSendValue:{} nOtherValue:{} nMsgId = {}", nSendValue, nOtherValue, nMsgId);
            }

            return 0;
        }

        auto iterator2 = mxCallBack[eServerType].mxCallBackList.find(connectionLink);
        if (iterator2 != mxCallBack[eServerType].mxCallBackList.end()) {
            NET_RECEIVE_FUNCTOR &pFun = iterator2->second.m_pFunctor;
            if (pFun)
            {
                int iRet = pFun(objectLinkId, nSendValue, nOtherValue, nMsgId, msg, nLen);
                iterator2->second.m_iCount++;
                uint64_t useTime = NFGetMicroSecondTime() - startTime;
                iterator2->second.m_iAllUseTime += useTime;
                if (useTime > iterator2->second.m_iMaxTime)
                {
                    iterator2->second.m_iMaxTime = useTime;
                }
                if (useTime < iterator2->second.m_iMinTime)
                {
                    iterator2->second.m_iMinTime = useTime;
                }
                if (useTime/1000 > 33)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "connectionLink:{} use time:{} ms, too long", connectionLink, useTime/1000);
                }
                //1009 1010 heartbeat
                if (nMsgId != 1009 && nMsgId != 1010 && nMsgId != 1 && nMsgId != 2)
                    NFLogTrace(NF_LOG_RECV_MSG, 0, "connectionLink:{} value1:{} value2:{} use time:{} us, count:{} allTime:{} perTime:{} minTime:{} maxTime:{}",
                               connectionLink, nSendValue, nOtherValue, useTime, iterator2->second.m_iCount, iterator2->second.m_iAllUseTime,
                               iterator2->second.m_iAllUseTime/iterator2->second.m_iCount, iterator2->second.m_iMinTime, iterator2->second.m_iMaxTime);
                CHECK_RET(iRet, "nSendValue:{} nOtherValue:{} nMsgId = {}", nSendValue, nOtherValue, nMsgId);
            }
        }

        return 0;
	}
	return 0;
}

int NFCMessageModule::OnReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, uint64_t nSendValue,
                                       uint64_t nOtherValue, uint32_t nMsgId, const char *msg, uint32_t nLen) {
    uint32_t eServerType = GetServerTypeFromUnlinkId(objectLinkId);
    if (eServerType < mxCallBack.size()) {
        uint64_t startTime = NFGetMicroSecondTime();
        if (eServerType != NF_ST_ROUTE_AGENT_SERVER && eServerType != NF_ST_ROUTE_SERVER && eServerType != NF_ST_PROXY_AGENT_SERVER) {
            if (nMsgId == proto_ff::NF_SERVER_TO_SERVER_TRANS_CMD) {
                proto_ff::Proto_SvrPkg svrPkg;
                CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, 0, msg, nLen, svrPkg);

                if (svrPkg.disp_info().rsp_trans_id() > 0 && NFShmMgr::Instance()->IsInited()) {
                    NFTransBase *pTrans = NFShmMgr::Instance()->GetTrans(svrPkg.disp_info().rsp_trans_id());
                    if (pTrans && !pTrans->IsFinished()) {
                        pTrans->ProcessDispSvrRes(objectLinkId, nSendValue, svrPkg.disp_info().req_trans_id(), svrPkg.msg_id(), svrPkg.msg_data().c_str(), svrPkg.msg_data().length());
                        uint64_t useTime = NFGetMicroSecondTime() - startTime;
                        if (useTime/1000 > 33)
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "Trans:{} ProcessDispSvrRes nMsgId:{} use time:{} ms, too long", pTrans->ClassTypeInfo(), svrPkg.msg_id(), useTime/1000);
                        }
                        NFLogTrace(NF_LOG_RECV_MSG, 0, "Trans:{} ProcessDispSvrRes nMsgId:{} value1:{} value2:{} use time:{} us", pTrans->ClassTypeInfo(), svrPkg.msg_id(), nSendValue, nOtherValue, useTime);
                    } else {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "can't find trans, trans maybe timeout, msgId:{} req_transid:{} rsp_transid:{}",
                                   svrPkg.msg_id(), svrPkg.disp_info().req_trans_id(), svrPkg.disp_info().rsp_trans_id());
                    }
                    return 0;
                }
				else
				{
					OnHandleReceiveNetPack(connectionLink, objectLinkId, nSendValue, svrPkg.disp_info().req_trans_id(), svrPkg.msg_id(), svrPkg.msg_data().c_str(), svrPkg.msg_data().length());
				}

				return 0;
            } else if (nMsgId == proto_ff::NF_STORE_SERVER_TO_SERVER_DB_CMD) {
                proto_ff::Proto_SvrPkg svrPkg;
                CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, 0, msg, nLen, svrPkg);

                if (svrPkg.store_info().cb_data().type() == proto_ff::E_DISP_TYPE_BY_TRANSACTION)
                {
                    if (svrPkg.store_info().cb_data().id() > 0 && NFShmMgr::Instance()->IsInited()) {
                        NFTransBase *pTrans = NFShmMgr::Instance()->GetTrans(svrPkg.store_info().cb_data().id());
                        if (pTrans && !pTrans->IsFinished()) {
                            pTrans->ProcessDBMsgRes(svrPkg);
                            uint64_t useTime = NFGetMicroSecondTime() - startTime;
                            if (useTime/1000 > 33)
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "Trans:{} ProcessDispSvrRes nMsgId:{} use time:{} ms, too long", pTrans->ClassTypeInfo(), svrPkg.store_info().cmd(), useTime/1000);
                            }
                            NFLogTrace(NF_LOG_RECV_MSG, 0, "Trans:{} ProcessDispSvrRes nMsgId:{}  use time:{} us", pTrans->ClassTypeInfo(), svrPkg.store_info().cmd(), useTime);
                        } else {
                            NFLogError(NF_LOG_SYSTEMLOG, 0,
                                       "can't find trans, trans maybe timeout, transid:{} ",
                                       svrPkg.store_info().cb_data().id());
                        }
                        return 0;
                    }
                    else
                    {
                        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "the store server rsp not handle, no transid, msg:{}", svrPkg.DebugString());
                        return 0;
                    }
                }
            }
            else if (nMsgId == proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY)
            {
                proto_ff::Proto_STSBroadPlayerMsgNotify xMsg;
                CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, 0, msg, nLen, xMsg);

                for(int i = 0; i < (int)xMsg.user_id_size(); i++)
                {
                    uint64_t userId = xMsg.user_id(i);
                    OnHandleReceiveNetPack(connectionLink, objectLinkId, userId, nOtherValue, xMsg.msg_id(), xMsg.msg_data().data(), xMsg.msg_data().length());
                }

                uint64_t useTime = NFGetMicroSecondTime() - startTime;
                if (useTime/1000 > 33)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "BroadPlayerMsgNotify nMsgId:{} use time:{} ms, too long", xMsg.msg_id(), useTime/1000);
                }
                NFLogTrace(NF_LOG_RECV_MSG, 0, "BroadPlayerMsgNotify nMsgId:{} value1:{} value2:{} use time:{} us", xMsg.msg_id(), nSendValue, nOtherValue, useTime);

                return 0;
            }
        }

		OnHandleReceiveNetPack(connectionLink, objectLinkId, nSendValue, nOtherValue, nMsgId, msg, nLen);
	}
	return 0;
}

int NFCMessageModule::OnSocketNetEvent(eMsgType nEvent, uint64_t connectionLink, uint64_t objectLinkId) {
    uint32_t eServerType = GetServerTypeFromUnlinkId(objectLinkId);
    if (eServerType < mxCallBack.size()) {
        auto iter = mxCallBack[eServerType].mxEventCallBack.find(connectionLink);
        if (iter != mxCallBack[eServerType].mxEventCallBack.end()) {
            NET_EVENT_FUNCTOR &pFun = iter->second.m_pFunctor;
            if (pFun)
            {
                int iRet = pFun(nEvent, objectLinkId);
                CHECK_RET(iRet, "nEvent:{}", nEvent);
            }
        }
    }
    return 0;
}

int NFCMessageModule::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId,
                                     const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgByBusId(this, busId, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                 const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgByBusId(this, busId, nMainMsgId, nSubMsgId, xData, valueId);
    return 0;
}

int NFCMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId,
                                     const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendProxyMsgByBusId(this, busId, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                 const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendProxyMsgByBusId(this, busId, nMainMsgId, nSubMsgId, xData, valueId);
    return 0;
}

int NFCMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId,
                                     const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    auto pServerData = GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        Send(pServerData->mUnlinkId, nMsgId, xData, valueId, busId);
        return 0;
    }

    pServerData = GetServerByServerId(eType, busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);
    Send(pServerData->mUnlinkId, nMsgId, xData, valueId, busId);
    return 0;
}

int
NFCMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                 const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    auto pServerData = GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, xData, valueId, busId);
        return 0;
    }

    pServerData = GetServerByServerId(eType, busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);
    Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, xData, valueId, busId);
    return 0;
}

int
NFCMessageModule::SendMsgToWebServer(NF_SERVER_TYPES eType, uint64_t requestId, int32_t result, const std::string& err_msg)
{
    proto_ff::Proto_STWebMsgRspNotify xMsg;
    xMsg.set_request_id(requestId);
    xMsg.set_result(result);
    xMsg.set_err_msg(err_msg);
    return SendMsgToWebServer(eType, proto_ff::NF_SEVER_TO_WEB_SERVER_RSP_NOTIFY, xMsg);
}

int
NFCMessageModule::SendMsgToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgToWebServer(this, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgToWorldServer(this, nMsgId, xData, valueId);
    return 0;
}

int NFCMessageModule::SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgToGameServer(this, busId, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
    mServerLinkData[eType].SendMsgToLoginServer(this, busId, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
	uint64_t valueId) {
	CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
	mServerLinkData[eType].SendMsgToLogicServer(this, busId, nMsgId, xData, valueId);
	return 0;
}

int
NFCMessageModule::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char* msg, int nLen,
                                       uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
    mServerLinkData[eType].SendMsgToLogicServer(this, busId, nMsgId, msg, nLen, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToSuitLogicServer(NF_SERVER_TYPES eType, uint64_t userId, uint32_t nMsgId, const google::protobuf::Message &xData, bool online) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
    mServerLinkData[eType].SendMsgToSuitLogicServer(this, userId, nMsgId, xData, online);
    return 0;
}

int
NFCMessageModule::SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
	uint64_t valueId) {
	CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
	mServerLinkData[eType].SendMsgToSnsServer(this, nMsgId, xData, valueId);
	return 0;
}

int
NFCMessageModule::SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                         uint32_t req_trans_id, uint32_t rsp_trans_id) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToWorldServer(this, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int
NFCMessageModule::SendTransToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                         uint32_t req_trans_id, uint32_t rsp_trans_id) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToWebServer(this, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int
NFCMessageModule::SendTransToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                         uint32_t req_trans_id, uint32_t rsp_trans_id) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
    mServerLinkData[eType].SendTransToLoginServer(this, busId, nMsgId, xData, req_trans_id, rsp_trans_id);
    return 0;
}

int
NFCMessageModule::SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
	uint32_t req_trans_id, uint32_t rsp_trans_id) {
	CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
	mServerLinkData[eType].SendTransToLogicServer(this, busId, nMsgId, xData, req_trans_id, rsp_trans_id);
	return 0;
}

int
NFCMessageModule::SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
	uint32_t req_trans_id, uint32_t rsp_trans_id) {
	CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
	mServerLinkData[eType].SendTransToSnsServer(this, nMsgId, xData, req_trans_id, rsp_trans_id);
	return 0;
}

int NFCMessageModule::SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData,
	uint32_t req_trans_id, uint32_t rsp_trans_id)
{
	CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int)eType);
	mServerLinkData[eType].SendTransToGameServer(this, nMsgId, gameBusId, xData, req_trans_id, rsp_trans_id);
	return 0;
}

int NFCMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                             const std::string &dbname, const std::string &table_name, const std::string &xData,
                                             int trans_id, uint32_t seq,
                                             uint64_t mod_key)
{
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToStoreServer(this, cmd, table_id, dbname, table_name, xData, trans_id, seq, mod_key);
    return 0;
}

int NFCMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
											 const std::string &dbname, const string &table_name, const google::protobuf::Message &xData,
                                             int trans_id, uint32_t seq, uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToStoreServer(this, cmd, table_id, dbname, table_name, xData, trans_id, seq, mod_key, cls_name);
    return 0;
}

int NFCMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
											 const std::string &dbname, const std::string &table_name,
                                             std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                             const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                             uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToStoreServer(this, cmd, table_id, dbname, table_name, vk_list, where_addtional_conds,
                                                  trans_id, seq, mod_key, cls_name);
    return 0;
}

int NFCMessageModule::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                             const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                             std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                             const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                             uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendTransToStoreServer(this, cmd, table_id, dbname, table_name, xData, vk_list, where_addtional_conds,
                                                  trans_id, seq, mod_key, cls_name);
    return 0;
}

int NFCMessageModule::SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const google::protobuf::Message *pMessage, const QueryDescStore_CB& cb) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    CHECK_EXPR(NFShmMgr::Instance()->IsInited(), -1, "eType error:{}", (int) eType);
    NFDescStoreTrans* pTrans = dynamic_cast<NFDescStoreTrans*>(NFShmMgr::Instance()->CreateTrans(EOT_RPC_TRANS_ID));
    CHECK_EXPR(pTrans, -1, "Create NFDescStoreTrans Failed, use count:{}", NFDescStoreTrans::GetUsedCount());

    int64_t coId = NFCoMgr::Instance()->CurrentTaskId();
    if (coId >= 0)
    {
        pTrans->Init(coId, pMessage);
    }

    pTrans->SendGetDescStoreReq(eType, dbName, table_name, cb);
    return 0;
}

int NFCMessageModule::SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t nMsgId,
                                      const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), -1, "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].SendMsgToServer(this, recvType, nMsgId, xData, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nMsgId,
                                  const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), -1, "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].SendMsgToServer(this, recvType, busId, nMsgId, xData, valueId);
    return 0;
}

int NFCMessageModule::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), -1, "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].SendMsgToMasterServer(this, nMsgId, xData, valueId);
    return 0;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                                   const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMsgId, xData, valueId);
    return 0;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId,
                                   uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, xData, valueId);
    return 0;
}

int ServerLinkData::SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                                   const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMsgId, xData, valueId, busId);
    return 0;
}

int ServerLinkData::SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId,
                                   uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, xData, valueId, busId);
    return 0;
}

int ServerLinkData::SendMsgToWorldServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
                                         const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_WORLD_SERVER, 0);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                         destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToWebServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
                                         const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_WEB_SERVER, 0);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                         destServerLinkId);
    return 0;
}

int
ServerLinkData::SendMsgToGameServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                    uint64_t valueId)
{
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_GAME_SERVER, busId);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                         destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToLoginServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                                         const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_LOGIN_SERVER, busId);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                         destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
	const google::protobuf::Message &xData, uint64_t valueId) {
	CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
	NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
	CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

	uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_LOGIC_SERVER, busId);
	uint64_t sendLinkId = valueId;
	if (sendLinkId == 0) {
		sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
	}

	pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
		destServerLinkId);
	return 0;
}

int ServerLinkData::SendMsgToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                                         const char* msg, int msgLen, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_LOGIC_SERVER, busId);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, msg, msgLen, sendLinkId,
                         destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToSuitLogicServer(NFIMessageModule *pMessageModule, uint64_t userId, uint32_t nMsgId,
                                         const google::protobuf::Message &xData, bool online) {
    CHECK_EXPR(userId > 0, -1, "userid:{} error", userId);

    if (online)
    {
        proto_ff::Proto_SvrPkg req;
        req.set_msg_id(nMsgId);
        req.set_msg_data(xData.SerializeAsString());
        req.mutable_disp_info()->set_user_id(userId);
        return SendMsgToSnsServer(pMessageModule, proto_ff::NF_SNS_ROUTER_CMD_TO_SUIT_LOGIC, req, 0);
    }
    else
    {
        proto_ff::Proto_SvrPkg req;
        req.set_msg_id(nMsgId);
        req.set_msg_data(xData.SerializeAsString());
        req.mutable_disp_info()->set_user_id(userId);
        return SendMsgToWorldServer(pMessageModule, proto_ff::NF_WORLD_ROUTER_CMD_TO_SUIT_LOGIC, req, 0);
    }
}

int ServerLinkData::SendMsgToSnsServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
	const google::protobuf::Message &xData, uint64_t valueId) {
	CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
	NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
	CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

	uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_SNS_SERVER, 0);
	uint64_t sendLinkId = valueId;
	if (sendLinkId == 0) {
		sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
	}

	pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
		destServerLinkId);
	return 0;
}

int ServerLinkData::SendTransToWebServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
                                           const google::protobuf::Message &xData, uint32_t req_trans_id,
                                           uint32_t rsp_trans_id) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_WEB_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                              destServerLinkId, req_trans_id, rsp_trans_id);
    return 0;
}

int ServerLinkData::SendTransToWorldServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
                                           const google::protobuf::Message &xData, uint32_t req_trans_id,
                                           uint32_t rsp_trans_id) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_WORLD_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                              destServerLinkId, req_trans_id, rsp_trans_id);
    return 0;
}

int ServerLinkData::SendTransToLoginServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                                           const google::protobuf::Message &xData, uint32_t req_trans_id,
                                           uint32_t rsp_trans_id) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_LOGIN_SERVER, busId);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
                              destServerLinkId, req_trans_id, rsp_trans_id);
    return 0;
}

int ServerLinkData::SendTransToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
	const google::protobuf::Message &xData, uint32_t req_trans_id,
	uint32_t rsp_trans_id) {
	CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
	NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
	CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

	uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_LOGIC_SERVER, busId);
	uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

	pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
		destServerLinkId, req_trans_id, rsp_trans_id);
	return 0;
}

int ServerLinkData::SendTransToSnsServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
	const google::protobuf::Message &xData, uint32_t req_trans_id,
	uint32_t rsp_trans_id) {
	CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
	NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
	CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

	uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_SNS_SERVER, 0);
	uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

	pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
		destServerLinkId, req_trans_id, rsp_trans_id);
	return 0;
}

int ServerLinkData::SendTransToGameServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData,
	uint32_t req_trans_id , uint32_t rsp_trans_id)
{
	CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
	NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
	CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

	uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_GAME_SERVER, gameBusId);
	uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

	pMessageModule->SendTrans(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId,
		destServerLinkId, req_trans_id, rsp_trans_id);
	return 0;
}

int ServerLinkData::SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
                                           const std::string &dbname, const std::string &table_name, const std::string &xData,
                                           int trans_id, uint32_t seq,
                                           uint64_t mod_key)
{
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    auto pServerVector = mDBStoreServerMap.GetElement(dbname);
    if (pServerVector)
    {
        NF_SHARE_PTR<NFServerData> pServerTmp = NULL;
        if (mod_key > 0)
        {
            pServerTmp = pServerVector->GetElementBySuit(mod_key);
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuit mod_key:{} result:{}", mod_key, pServerTmp->mServerInfo.server_name());
            }
        }
        else
        {
            pServerTmp = pServerVector->GetElementBySuitRandom();
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuitRandom  result:{}", pServerTmp->mServerInfo.server_name());
            }
        }

        if (pServerTmp)
        {
            uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, pServerTmp->mServerInfo.bus_id());
            uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

            pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                                      destServerLinkId, dbname, table_name,
                                      xData, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION);

            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "can't find the dbserver of db:{} random one dbserver", dbname);

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                              destServerLinkId, dbname, table_name,
                              xData, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION);

    return 0;
}

int ServerLinkData::SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
										   const std::string &dbname, const string &table_name, const google::protobuf::Message &xData,
                                           int trans_id, uint32_t seq, uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    auto pServerVector = mDBStoreServerMap.GetElement(dbname);
    if (pServerVector)
    {
        NF_SHARE_PTR<NFServerData> pServerTmp = NULL;
        if (mod_key > 0)
        {
            pServerTmp = pServerVector->GetElementBySuit(mod_key);
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuit mod_key:{} result:{}", mod_key, pServerTmp->mServerInfo.server_name());
            }
        }
        else
        {
            pServerTmp = pServerVector->GetElementBySuitRandom();
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuitRandom  result:{}", pServerTmp->mServerInfo.server_name());
            }
        }

        if (pServerTmp)
        {
            uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, pServerTmp->mServerInfo.bus_id());
            uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

            pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                                      destServerLinkId, dbname, table_name,
                                      xData, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);

            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "can't find the dbserver of db:{} random one dbserver", dbname);

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                              destServerLinkId, dbname, table_name,
                              xData, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);
    return 0;
}

int ServerLinkData::SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
											const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                           std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                           const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                           uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    auto pServerVector = mDBStoreServerMap.GetElement(dbname);
    if (pServerVector)
    {
        NF_SHARE_PTR<NFServerData> pServerTmp = NULL;
        if (mod_key > 0)
        {
            pServerTmp = pServerVector->GetElementBySuit(mod_key);
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuit mod_key:{} result:{}", mod_key, pServerTmp->mServerInfo.server_name());
            }
        }
        else
        {
            pServerTmp = pServerVector->GetElementBySuitRandom();
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuitRandom  result:{}", pServerTmp->mServerInfo.server_name());
            }
        }

        if (pServerTmp)
        {
            uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, pServerTmp->mServerInfo.bus_id());
            uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

            pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                                      destServerLinkId, dbname, table_name, xData,
                                      vk_list, where_addtional_conds, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);

            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "can't find the dbserver of db:{} random one dbserver", dbname);

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                              destServerLinkId, dbname, table_name, xData,
                              vk_list, where_addtional_conds, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);
    return 0;
}

int ServerLinkData::SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
                                           const std::string &dbname, const std::string &table_name,
                                           std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                           const std::string &where_addtional_conds, int trans_id, uint32_t seq,
                                           uint64_t mod_key, const std::string& cls_name) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    auto pServerVector = mDBStoreServerMap.GetElement(dbname);
    if (pServerVector)
    {
        NF_SHARE_PTR<NFServerData> pServerTmp = NULL;
        if (mod_key > 0)
        {
            pServerTmp = pServerVector->GetElementBySuit(mod_key);
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuit mod_key:{} result:{}", mod_key, pServerTmp->mServerInfo.server_name());
            }
        }
        else
        {
            pServerTmp = pServerVector->GetElementBySuitRandom();
            if (pServerTmp)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetElementBySuitRandom  result:{}", pServerTmp->mServerInfo.server_name());
            }
        }

        if (pServerTmp)
        {
            uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, pServerTmp->mServerInfo.bus_id());
            uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

            pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                                      destServerLinkId, dbname, table_name,
                                      vk_list, where_addtional_conds, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);

            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "can't find the dbserver of db:{} random one dbserver", dbname);

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, NF_ST_STORE_SERVER, 0);
    uint64_t sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);

    pMessageModule->SendStore(m_routeData.mUnlinkId, cmd, table_id, sendLinkId,
                              destServerLinkId, dbname, table_name,
                              vk_list, where_addtional_conds, trans_id, seq, mod_key, proto_ff::E_DISP_TYPE_BY_TRANSACTION, cls_name);
    return 0;
}

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint16_t nMainMsgId,
                                    uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, 0);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMainMsgId, nSubMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t busId,
                                    uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, busId);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t busId,
                                    uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData,
                                    uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, busId);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMainMsgId, nSubMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t nMsgId,
                                    const google::protobuf::Message &xData, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, 0);
    uint64_t sendLinkId = valueId;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

void ServerLinkData::CloseAllLink(NFIMessageModule *pMessageModule) {
    if (pMessageModule == NULL) return;

    pMessageModule->CloseLinkId(m_masterServerData.mUnlinkId);
    pMessageModule->CloseLinkId(m_routeData.mUnlinkId);
    pMessageModule->CloseLinkId(m_serverLinkId);
    for(auto iter = mLinkIdToBusIdMap.begin(); iter != mLinkIdToBusIdMap.end(); iter++)
    {
        pMessageModule->CloseLinkId(iter->first);
    }
}

int ServerLinkData::SendMsgToMasterServer(NFIMessageModule *pMessageModule, uint32_t nMsgId,
                                          const google::protobuf::Message &xData, uint64_t valueId) {
    //NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");

    pMessageModule->Send(m_masterServerData.mUnlinkId, nMsgId, xData, valueId);
    //NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
    return 0;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByServerId(uint32_t busId) {
    return mServerMap.GetElement(busId);
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByUnlinkId(uint64_t unlinkId) {
    auto iter = mLinkIdToBusIdMap.find(unlinkId);
    if (iter != mLinkIdToBusIdMap.end()) {
        return GetServerByServerId(iter->second);
    }
    return NULL;
}

uint64_t ServerLinkData::GetServerLinkId() const { return m_serverLinkId; }

NF_SHARE_PTR<NFServerData>
ServerLinkData::CreateServerByServerId(uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data) {
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    if (pServerData == NULL) {
        pServerData = NF_SHARE_PTR<NFServerData>(NF_NEW NFServerData());
        mServerMap.AddElement(busId, pServerData);
        if (busServerType > 0 && busServerType < NF_ST_MAX)
        {
            mServerList[busServerType].push_back(pServerData);
            mServerListMap[busServerType].AddElement(busId, pServerData);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateServerByServerId Error, servertype:{}", busServerType);
        }
    }

    pServerData->mServerInfo = data;

    if (busServerType == NF_ST_STORE_SERVER)
    {
        for(int i = 0; i < (int)pServerData->mServerInfo.db_name_list_size(); i++)
        {
            std::string dbName = pServerData->mServerInfo.db_name_list(i);
            auto pServerMap = mDBStoreServerMap.GetElement(dbName);
            if (!pServerMap)
            {
                pServerMap = NF_SHARE_PTR<NFConsistentHashMapEx<uint32_t, NFServerData>>(NF_NEW NFConsistentHashMapEx<uint32_t, NFServerData>());
                mDBStoreServerMap.AddElement(dbName, pServerMap);
            }

            if (pServerMap->GetElement(busId) == NULL)
            {
                pServerMap->AddElement(busId, pServerData);
            }
        }
    }

    return pServerData;
}

void ServerLinkData::CloseServer(NF_SERVER_TYPES busServerType, uint32_t busId, uint64_t usLinkId)
{
    DelServerLink(usLinkId);
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    if (pServerData)
    {
        if (busServerType > 0 && busServerType < NF_ST_MAX)
        {
            for(auto iter = mServerList[busServerType].begin(); iter != mServerList[busServerType].end(); iter++)
            {
                if (*iter == pServerData)
                {
                    mServerList[busServerType].erase(iter);
                    break;
                }
            }
            mServerListMap[busServerType].RemoveElement(busId);
        }

        if (pServerData->mServerInfo.server_type() == NF_ST_STORE_SERVER)
        {
            auto pServerMap = mDBStoreServerMap.First();
            while(pServerMap)
            {
                pServerMap->RemoveElement(busId);
                pServerMap = mDBStoreServerMap.Next();
            }
        }

        mServerMap.RemoveElement(busId);
    }
}

void ServerLinkData::CreateLinkToServer(uint32_t busId, uint64_t linkId) {
    mLinkIdToBusIdMap.emplace(linkId, busId);
}

void ServerLinkData::DelServerLink(uint64_t linkId) {
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByUnlinkId(linkId);
    if (pServerData)
    {
        pServerData->mUnlinkId = 0;
    }
    mLinkIdToBusIdMap.erase(linkId);
}

void ServerLinkData::SetServerLinkId(uint64_t linkId) { m_serverLinkId = linkId; }

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetServerByServerType(NF_SERVER_TYPES serverTypes) {
    return mServerList[serverTypes];
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetFirstServerByServerType(NF_SERVER_TYPES serverTypes)
{
    if (!mServerList[serverTypes].empty())
    {
        return mServerList[serverTypes][0];
    }

    return NULL;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetRandomServerByServerType(NF_SERVER_TYPES serverTypes)
{
    auto pServer =   mServerListMap[serverTypes].GetElementBySuitRandom();
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType result:{}", pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, uint64_t value)
{
    auto pServer =  mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, const std::string& value)
{
    auto pServer = mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer() {
    std::vector<NF_SHARE_PTR<NFServerData>> vec;
    for(int i = 0; i < (int)mServerList.size(); i++)
    {
        for(int j = 0; j < (int)mServerList[i].size(); j++)
        {
            vec.push_back(mServerList[i][j]);
        }
    }
    return vec;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer(NF_SERVER_TYPES serverTypes) {
    return mServerList[serverTypes];
}

std::vector<std::string> ServerLinkData::GetDBNames()
{
    std::vector<std::string> vec;
    for(auto iter = mDBStoreServerMap.Begin(); iter != mDBStoreServerMap.End(); iter++)
    {
        vec.push_back(iter->first);
    }

    return vec;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const char *msg,
                                   uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, valueId);
    return 0;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId,
                                   uint16_t nSubMsgId, const char *msg, uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
    return 0;
}

int ServerLinkData::SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const char *msg,
                                   uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMsgId, msg, nLen, valueId, busId);
    return 0;
}

int ServerLinkData::SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId,
                                   uint16_t nSubMsgId, const char *msg, uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, msg, nLen, valueId, busId);
    return 0;
}


NF_SHARE_PTR<NFServerData> NFCMessageModule::GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetServerByServerId(busId);
}

NF_SHARE_PTR<NFServerData> NFCMessageModule::GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetServerByUnlinkId(unlinkId);
}

void NFCMessageModule::CloseServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), , "eType error:{}", (int) eSendType);
    CloseLinkId(usLinkId);
    return mServerLinkData[eSendType].CloseServer(destServer, busId, usLinkId);
}


NF_SHARE_PTR<NFServerData> NFCMessageModule::CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType,
                                                                    const proto_ff::ServerInfoReport &data) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].CreateServerByServerId(busId, busServerType, data);
}

void NFCMessageModule::DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), , "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].DelServerLink(linkId);
}

NFServerData* NFCMessageModule::GetRouteData(NF_SERVER_TYPES eSendType)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetRouteData();
}

const NFServerData* NFCMessageModule::GetRouteData(NF_SERVER_TYPES eSendType) const
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetRouteData();
}

NFServerData *NFCMessageModule::GetMasterData(NF_SERVER_TYPES eSendType) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetMasterData();
}

const NFServerData *NFCMessageModule::GetMasterData(NF_SERVER_TYPES eSendType) const {
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetMasterData();
}

void NFCMessageModule::CloseAllLink(NF_SERVER_TYPES eSendType) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), , "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].CloseAllLink(this);
}

void NFCMessageModule::CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId, uint64_t linkId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), , "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].CreateLinkToServer(busId, linkId);
}

void NFCMessageModule::SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId) {
    CHECK_EXPR(eSendType < mServerLinkData.size(), , "eType error:{}", (int) eSendType);
    mServerLinkData[eSendType].SetServerLinkId(linkId);
}

uint64_t NFCMessageModule::GetServerLinkId(NF_SERVER_TYPES eSendType) const {
    CHECK_EXPR(eSendType < mServerLinkData.size(), 0, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetServerLinkId();
}

std::vector<NF_SHARE_PTR<NFServerData>> NFCMessageModule::GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), std::vector<NF_SHARE_PTR<NFServerData>>(), "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetServerByServerType(serverTypes);
}

NF_SHARE_PTR<NFServerData> NFCMessageModule::GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetFirstServerByServerType(serverTypes);
}

NF_SHARE_PTR<NFServerData>
NFCMessageModule::GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetRandomServerByServerType(serverTypes);
}

NF_SHARE_PTR<NFServerData>
NFCMessageModule::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetSuitServerByServerType(serverTypes, value);
}

NF_SHARE_PTR<NFServerData>
NFCMessageModule::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string& value)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), NULL, "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetSuitServerByServerType(serverTypes, value);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFCMessageModule::GetAllServer(NF_SERVER_TYPES eSendType)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), std::vector<NF_SHARE_PTR<NFServerData>>(), "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetAllServer();
}

std::vector<NF_SHARE_PTR<NFServerData>> NFCMessageModule::GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), std::vector<NF_SHARE_PTR<NFServerData>>(), "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetAllServer(serverTypes);
}

std::vector<std::string> NFCMessageModule::GetDBNames(NF_SERVER_TYPES eSendType)
{
    CHECK_EXPR(eSendType < mServerLinkData.size(), std::vector<std::string>(), "eType error:{}", (int) eSendType);
    return mServerLinkData[eSendType].GetDBNames();
}

int
NFCMessageModule::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                                 uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgByBusId(this, busId, nMsgId, msg, nLen, valueId);
    return 0;
}

int NFCMessageModule::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendMsgByBusId(this, busId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
    return 0;
}

int
NFCMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                                 uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendProxyMsgByBusId(this, busId, nMsgId, msg, nLen, valueId);
    return 0;
}

int NFCMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    mServerLinkData[eType].SendProxyMsgByBusId(this, busId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
    return 0;
}

int
NFCMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                                 uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    auto pServerData = GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        Send(pServerData->mUnlinkId, nMsgId, msg, nLen, valueId, busId);
        return 0;
    }

    pServerData = GetServerByServerId(eType, busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);
    Send(pServerData->mUnlinkId, nMsgId, msg, nLen, valueId, busId);
    return 0;
}

int NFCMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, uint64_t valueId) {
    CHECK_EXPR(eType < mServerLinkData.size(), -1, "eType error:{}", (int) eType);
    auto pServerData = GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, msg, nLen, valueId, busId);
        return 0;
    }

    pServerData = GetServerByServerId(eType, busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);
    Send(pServerData->mUnlinkId, nMainMsgId, nSubMsgId, msg, nLen, valueId, busId);
    return 0;
}

bool NFCMessageModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const string &strMsg,
                                       NFWebStatus code, const string &reason) {
    if (m_driver)
    {
        return m_driver->ResponseHttpMsg(serverType, req, strMsg, code, reason);
    }
    return false;
}

bool NFCMessageModule::ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const string &strMsg,
                                       NFWebStatus code, const string &reason) {
    if (m_driver)
    {
        return m_driver->ResponseHttpMsg(serverType, requestId, strMsg, code, reason);
    }
    return false;
}

bool NFCMessageModule::AddHttpMsgCB(NF_SERVER_TYPES serverType, const string &strCommand, NFHttpType eRequestType,
                                    const HTTP_RECEIVE_FUNCTOR &cb) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        std::string lowerCmd = NFStringUtility::ToLower(strCommand);
        mxCallBack[serverType].mxHttpMsgCBMap[eRequestType].emplace(lowerCmd, cb);
        return true;
    }

    return false;
}

bool NFCMessageModule::AddHttpOtherMsgCB(NF_SERVER_TYPES serverType, NFHttpType eRequestType,
                                         const HTTP_RECEIVE_FUNCTOR &cb) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        mxCallBack[serverType].mxHttpOtherMsgCBMap[eRequestType].push_back(cb);
        return true;
    }

    return false;
}

bool
NFCMessageModule::AddHttpFilterCB(NF_SERVER_TYPES serverType, const string &strCommand, const HTTP_FILTER_FUNCTOR &cb) {
    if (serverType > NF_ST_NONE && serverType < NF_ST_MAX)
    {
        std::string lowerCmd = NFStringUtility::ToLower(strCommand);
        mxCallBack[serverType].mxHttpMsgFliterMap.emplace(lowerCmd, cb);
        return true;
    }

    return true;
}

bool NFCMessageModule::OnHttpReceiveNetPack(uint32_t serverType, const NFIHttpHandle &req) {
    if (serverType <= NF_ST_NONE || serverType >= NF_ST_MAX) return false;

    auto iter = mxCallBack[serverType].mxHttpMsgCBMap.find((NFHttpType)req.GetType());
    if (iter != mxCallBack[serverType].mxHttpMsgCBMap.end())
    {
        std::string lowerPath = NFStringUtility::ToLower(req.GetPath());
        NFStringUtility::TrimLeft(lowerPath, '/');
        auto itPath = iter->second.find(lowerPath);
        if (itPath != iter->second.end())
        {
            HTTP_RECEIVE_FUNCTOR& pFunPtr = itPath->second;
            try
            {
                pFunPtr(serverType,req);
            }
            catch (const std::exception&)
            {
                ResponseHttpMsg((NF_SERVER_TYPES)serverType, req, "unknow error", NFWebStatus::WEB_INTER_ERROR);
            }
            return true;
        }
        else
        {
            for (int i = 0; i < (int)mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()].size(); ++i)
            {
                HTTP_RECEIVE_FUNCTOR& pFunPtr = mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()][i];
                try
                {
                    pFunPtr(serverType, req);
                }
                catch (const std::exception&)
                {
                    ResponseHttpMsg((NF_SERVER_TYPES)serverType, req, "unknow error", NFWebStatus::WEB_INTER_ERROR);
                    return true;
                }
            }
            if (mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()].size() > 0)
            {
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < (int)mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()].size(); ++i)
        {
            HTTP_RECEIVE_FUNCTOR& pFunPtr = mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()][i];
            try
            {
                pFunPtr(serverType, req);
            }
            catch (const std::exception&)
            {
                ResponseHttpMsg((NF_SERVER_TYPES)serverType, req, "unknow error", NFWebStatus::WEB_INTER_ERROR);
                return true;
            }
        }
        if (mxCallBack[serverType].mxHttpOtherMsgCBMap[(NFHttpType)req.GetType()].size() > 0)
        {
            return true;
        }
    }

    return ResponseHttpMsg((NF_SERVER_TYPES)serverType, req, "", NFWebStatus::WEB_ERROR);
}

NFWebStatus NFCMessageModule::OnHttpFilterPack(uint32_t serverType, const NFIHttpHandle &req) {
    if (serverType <= NF_ST_NONE || serverType >= NF_ST_MAX) return NFWebStatus::WEB_ERROR;

    std::string lowerPath = NFStringUtility::ToLower(req.GetPath());
    NFStringUtility::TrimLeft(lowerPath, '/');
    auto itPath = mxCallBack[serverType].mxHttpMsgFliterMap.find(lowerPath);
    if (itPath != mxCallBack[serverType].mxHttpMsgFliterMap.end())
    {
        HTTP_FILTER_FUNCTOR& pFunPtr = itPath->second;
        return pFunPtr(serverType, req);
    }

    return NFWebStatus::WEB_OK;
}

int NFCMessageModule::HttpGet(NF_SERVER_TYPES serverType, const string &strUri, const HTTP_CLIENT_RESPONE &respone,
                              const map<std::string, std::string> &xHeaders, int timeout) {
    if (m_driver)
    {
        return m_driver->HttpGet(serverType, strUri, respone, xHeaders, timeout);
    }
    return -1;
}

int NFCMessageModule::HttpPost(NF_SERVER_TYPES serverType, const string &strUri, const string &strPostData,
                               const HTTP_CLIENT_RESPONE &respone, const map<std::string, std::string> &xHeaders,
                               int timeout) {
    if (m_driver)
    {
        return m_driver->HttpPost(serverType, strUri, strPostData, respone, xHeaders, timeout);
    }
    return -1;
}



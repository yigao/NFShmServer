// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMessageMgr.h
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "common/spdlog/fmt/fmt.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"


class NFServerMessageModule : public NFIServerMessageModule
{
public:
    NFServerMessageModule(NFIPluginManager* pPluginManager);
    virtual ~NFServerMessageModule();
public:
    virtual int SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
public:
    ////////////////////////////send proxy msg to other serer//////////////////////////////////
    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2) override;
    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t nParam1, uint64_t nParam2) override;
    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
public:
    ///////////////////////////other server send msg to proxy msg/////////////////////////////
    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    ///////////////////////////other server send msg to world msg/////////////////////////////
    virtual int SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    virtual int SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    ///////////////////////////other server send msg to game msg/////////////////////////////
    virtual int SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    virtual int SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    ///////////////////////////other server send msg to logic server/////////////////////////////
    virtual int SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
    virtual int SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0) override;
public:
    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
              const std::string &dbname, const std::string &table_name, const std::string &xData, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) override;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
              const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, const std::string& cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) override;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
              const std::string &dbname, const std::string &table_name, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
              const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, const std::string& cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) override;

    virtual int
    SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t dstBusId, uint32_t cmd, uint32_t table_id,
              const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
              const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, const std::string& cls_name = "", uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) override;
};

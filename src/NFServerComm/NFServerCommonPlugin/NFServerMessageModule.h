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
};

// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.h
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "common/spdlog/fmt/fmt.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"

class NFServerMessageMgr : public NFSingleton<NFServerMessageMgr>
{
public:
    NFServerMessageMgr();
    virtual ~NFServerMessageMgr();
public:
    virtual int SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1 = 0, uint64_t nParam2 = 0);
};

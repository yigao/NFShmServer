// -------------------------------------------------------------------------
//    @FileName         :    NFGameLogHandle.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameLogHandle.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFCore/NFSingleton.hpp"

class NFGameLogHandle : public NFSingleton<NFGameLogHandle>
{
public:
    NFGameLogHandle();
    virtual ~NFGameLogHandle();

public:
    int LogGameRecord(uint64_t recordId, uint64_t playerId, const std::string& nickName, uint32_t gameId, uint32_t roomId, const google::protobuf::Message& betInfo, const google::protobuf::Message& resultInfo);
public:
    int GameLogCallBack(uint64_t userId, const google::protobuf::Message* message);
};

// -------------------------------------------------------------------------
//    @FileName         :    NFMoneyLogHandle.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMoneyLogHandle.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFCore/NFSingleton.hpp"

class NFUserDetail;
class NFMoneyLogHandle : public NFSingleton<NFMoneyLogHandle>
{
public:
    NFMoneyLogHandle();
    virtual ~NFMoneyLogHandle();

public:
    int UserMoneyChange(NFUserDetail* pUserDetail, uint32_t gameId, uint32_t roomId, uint32_t deskId, uint32_t chairId, uint32_t accountType, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason);
    int WebZhuangZhangRecharge(NFUserDetail* pUserDetail, int64_t amount, uint32_t status);
    int WebGiveMoney(NFUserDetail* pUserDetail, uint32_t reason, uint64_t amount, uint32_t status);
    int WebRedeemCodeRecharge(NFUserDetail* pUserDetail, uint64_t amount, uint32_t status);
public:
    int MoneyLogCallBack(uint64_t userId, const google::protobuf::Message* message);
};

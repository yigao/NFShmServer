// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDesk.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDesk
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFIGameDesk : public NFShmObj
{
public:
    NFIGameDesk();

    virtual ~NFIGameDesk();

    int CreateInit();

    int ResumeInit();
public:
    virtual int UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange) = 0;
    virtual int DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false) = 0;
    virtual int AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false) = 0;
    virtual int ProcUserSettlement(uint64_t playerId) = 0;
    virtual uint64_t GetPlayerCurMoney(uint64_t playerId) = 0;
    virtual int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win) = 0;
    virtual int64_t CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton) = 0;
    virtual int AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee) = 0;
public:
    virtual int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId) = 0;
    virtual int BroadCastMsgToDesk(uint32_t nMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID) = 0;
    virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0) = 0;
    virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId) = 0;
    virtual int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0) = 0;
};
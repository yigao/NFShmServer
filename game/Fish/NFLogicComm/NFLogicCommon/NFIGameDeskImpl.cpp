// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDeskImpl.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDeskImpl
//
// -------------------------------------------------------------------------

#include "NFIGameDeskImpl.h"
#include "NFLogicShmTypeDefines.h"
#include "NFIGameDesk.h"

NFIGameDeskImpl::NFIGameDeskImpl()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFIGameDeskImpl::~NFIGameDeskImpl()
{
}

int NFIGameDeskImpl::CreateInit()
{
    return 0;
}

int NFIGameDeskImpl::ResumeInit()
{
    return 0;
}

int NFIGameDeskImpl::Init(NFIGameDesk* pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum)
{
    m_deskHandle = pGameHandle;
    m_gameId = gameId;
    m_roomId = roomId;
    m_deskId = deskId;
    m_siteNum = sitNum;
    m_maxUserNum = maxUserNum;
    return 0;
}

int NFIGameDeskImpl::UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
    return m_deskHandle->UpdateUserMoney(playerId, changeType, moneyChange);
}

int NFIGameDeskImpl::DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    return m_deskHandle->DeduceGameMoney(playerId, moneyChange, procUserSettlement);
}

int NFIGameDeskImpl::AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    return m_deskHandle->AddGameMoney(playerId, moneyChange, procUserSettlement);
}

int NFIGameDeskImpl::ProcUserSettlement(uint64_t playerId)
{
    return m_deskHandle->ProcUserSettlement(playerId);
}

uint64_t NFIGameDeskImpl::GetPlayerCurMoney(uint64_t playerId)
{
    return m_deskHandle->GetPlayerCurMoney(playerId);
}

int NFIGameDeskImpl::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    return m_deskHandle->GameDataCommit(cur_fee, cur_pour, cur_win);
}

int64_t NFIGameDeskImpl::CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton)
{
    return m_deskHandle->CommissionCount(userid, CountByFee, pourJetton);
}

int NFIGameDeskImpl::AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee)
{
    return m_deskHandle->AchievementCount(userid, Count, fee);
}

int NFIGameDeskImpl::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    return m_deskHandle->SendMsgToClient(nMsgId, xData, playerId);
}

int NFIGameDeskImpl::BroadCastMsgToDesk(uint32_t nMsgId, const google::protobuf::Message &xData, int32_t chairId)
{
    return m_deskHandle->BroadCastMsgToDesk(nMsgId, xData, chairId);
}

int NFIGameDeskImpl::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    return m_deskHandle->SendMsgToWorldServer(nMsgId, xData, playerId);
}

int NFIGameDeskImpl::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    return m_deskHandle->SendMsgToLogicServer(nMsgId, xData, playerId);
}

int NFIGameDeskImpl::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    return m_deskHandle->SendMsgToSnsServer(nMsgId, xData, playerId);
}

// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoom.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameRoom
//
// -------------------------------------------------------------------------

#include "NFGameRoom.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRoom, EOT_NFGameRoom_ID, NFShmObj)

NFGameRoom::NFGameRoom()
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

NFGameRoom::~NFGameRoom()
{
}

int NFGameRoom::CreateInit()
{
    m_gameId = 0;
    m_roomId = 0;
    m_statTimer = INVALID_ID;
    m_lastSendTime = 0;

    return 0;
}

int NFGameRoom::ResumeInit()
{
    return 0;
}

int NFGameRoom::OnGameBegin(int iDeskId)
{
    return 0;
}

int NFGameRoom::OnGameFinish(int iDeskId)
{
    return 0;
}

bool NFGameRoom::IsPlayGame(int iDeskId, int iDeskStation)
{
    return false;
}

bool NFGameRoom::IsPlayGameCanLeave(int iDeskId, int iDeskStation)
{
    return false;
}

int NFGameRoom::ClearIdleUser(uint64_t playerId)
{
    return ClearDirtyData(playerId);
}

int NFGameRoom::ClearDirtyData(uint64_t playerId)
{
    return 0;
}

int NFGameRoom::ClearTimeOutUser(uint64_t playerId)
{
    return 0;
}

int NFGameRoom::ClearOfflineUser(uint64_t playerId)
{
    return 0;
}

void NFGameRoom::KickUser(uint64_t playerId, int nReasonCode)
{

}

int NFGameRoom::OnTimer(int timeId, int callcount)
{
    return 0;
}

int NFGameRoom::ClearJiangChi()
{
    return 0;
}

int NFGameRoom::ChangeJiangChi(int64_t jiangchi)
{
    return 0;
}

int NFGameRoom::GameDataCommit(uint64_t cur_fee, uint64_t cur_ach, int64_t cur_win)
{
    return 0;
}

const proto_ff_s::E_RoomRoom_s *NFGameRoom::GetRoomConfig()
{
    return nullptr;
}

int NFGameRoom::UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
    return 0;
}

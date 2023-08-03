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
#include "Desk/NFGameDesk.h"
#include "NFComm/NFCore/NFTime.h"
#include "Player/NFGamePlayerMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "DescStoreEx/GameRoomDescEx.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRoom, EOT_NFGameRoom_ID, NFShmObj)

//桌子与座位对应节点
typedef struct stDeskStationNode
{
    int m_nDeskIndex;     //桌子索引
    int m_nDeskStation;   //位置信息

} TDeskStationNode;

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
    m_tickTimer = INVALID_ID;
}

int NFGameRoom::CreateInit()
{
    m_gameId = 0;
    m_roomId = 0;
    m_tickTimer = INVALID_ID;
    return 0;
}

int NFGameRoom::ResumeInit()
{
    return 0;
}

int NFGameRoom::Init(uint32_t gameId, const std::string &gameName, uint32_t roomId, const std::string &roomName, uint32_t deskCount, uint32_t sitNum,
                     uint32_t maxUserNum)
{
    m_gameId = gameId;
    m_roomId = roomId;
    m_gameName = gameName;
    m_roomName = roomName;

    m_tickTimer = SetTimer(1000, 0, 0, 0, 10, 0);
    int iRet = InitDesks(deskCount, sitNum, maxUserNum);
    CHECK_EXPR(iRet == 0, -1, "InitGameDesk failed, gameId:{}, roomId:{} deskCount:{}", gameId, roomId, deskCount);
    return 0;
}

int NFGameRoom::InitDesks(uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum)
{
    CHECK_EXPR(deskCount > 0 && deskCount <= ONE_GAME_ROOM_MAX_DESK_COUNT && sitNum > 0 && maxUserNum >= sitNum && sitNum <= MAX_GAME_DESK_CHAIR_NUM, -1, "param error, deskCount:{} sitNum:{} maxUserNum:{}",
               deskCount, sitNum, maxUserNum);

    m_AryDesks.resize(deskCount);

    for (uint32_t iDeskIndex = 0; iDeskIndex < (uint32_t)m_AryDesks.size(); iDeskIndex++)
    {
        NFGameDesk *pDesk = NFGameDesk::CreateObj(m_pObjPluginManager);
        CHECK_EXPR_CONTINUE(pDesk, "Create Desk Obj Failed!!!!!");

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "InitGameDesk() deskId = {}", iDeskIndex);

        int retCode = pDesk->Init(m_gameId, m_roomId, iDeskIndex, sitNum, maxUserNum, this);
        CHECK_EXPR_CONTINUE(retCode == 0, "Desk Init Failed!");

        m_AryDesks[iDeskIndex] = pDesk->GetGlobalId();
    }
    return 0;
}

int NFGameRoom::OnGameBegin(int iDeskId)
{
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->OnGameBegin();
}

int NFGameRoom::OnGameFinish(int iDeskId)
{
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->OnGameFinish();
}

bool NFGameRoom::IsPlayGame(int iDeskId, int iDeskStation)
{
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, false, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->IsPlayGame(iDeskStation);
}

bool NFGameRoom::IsPlayGameCanLeave(int iDeskId, int iDeskStation)
{
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, true, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->IsPlayGameCanLeave(iDeskStation);
}

int NFGameRoom::ClearIdleUser(uint64_t playerId)
{
    return ClearDirtyData(playerId);
}

int NFGameRoom::ClearDirtyData(uint64_t playerId)
{
    for (int i = 0; i < (int) GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ClearDirtyData(playerId);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }

    return 0;
}

int NFGameRoom::ClearTimeOutUser(uint64_t playerId)
{
    for (int i = 0; i < (int) GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            if (pDesk->IsInDesk(playerId))
            {
                int iRet = pDesk->ClearTimeOutUser(playerId);
                if (iRet != 0)
                {
                    return iRet;
                }
            }
        }
    }

    return 0;
}

int NFGameRoom::ClearOfflineUser(uint64_t playerId)
{
    for (int i = 0; i < (int) GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            if (pDesk->IsInDesk(playerId))
            {
                int iRet = pDesk->ClearOfflineUser(playerId);
                if (iRet != 0)
                {
                    return iRet;
                }
            }
        }
    }
    return 0;
}

void NFGameRoom::KickUser(uint64_t playerId, int nReasonCode)
{

}

int NFGameRoom::OnTimer(int timeId, int callcount)
{
    if (m_tickTimer == timeId)
    {
        Tick();
    }
    return 0;
}

int NFGameRoom::Tick()
{
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            pDesk->Tick();
        }
    }
    return 0;
}

NFGameDesk *NFGameRoom::GetGameDesk(int32_t iDeskId)
{
    CHECK_EXPR(iDeskId >= 0 && (int) iDeskId < (int) m_AryDesks.size(), NULL, "iDeskId error, iDeskId:{} , iDeskId:{}, GetDeskCount() = {}", iDeskId,
               iDeskId, GetDeskCount());
    return NFGameDesk::GetObjByGlobalId(m_pObjPluginManager, m_AryDesks[iDeskId]);
}

int NFGameRoom::GetDeskCount()
{
    return m_AryDesks.size();
}

int NFGameRoom::UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
    NFGameDesk *pDesk = GetGameDesk(deskId);
    CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} changeType:{}, moneyChange:{}", deskId, playerId, changeType, moneyChange);

    int iRetCode = pDesk->UpdateUserMoney(playerId, changeType, moneyChange);
    return iRetCode;
}

int NFGameRoom::UpdateUserInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail)
{
    auto roomConfig = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(m_gameId, m_roomId);
    CHECK_NULL(roomConfig);

    if (roomConfig->m_is_exp_scene > 0)
    {
        return 0;
    }

    NFGameDesk *pDesk = GetGameDesk(deskId);
    CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} ", deskId, playerId);

    int iRetCode = pDesk->UpdateUserInfo(playerId, pPlayerDetail);
    return iRetCode;
}


int NFGameRoom::OnHandleReqDeskList(uint64_t playerId, uint32_t autoChairId, proto_ff::DeskListRsp &deskListRsp)
{
    deskListRsp.set_result(0);
    if (autoChairId == 1)//return deskList
    {
        for (int i = 0; i < GetDeskCount(); i++)
        {
            NFGameDesk *pDesk = GetGameDesk(i);
            if (pDesk != NULL)
            {
                int deskId = pDesk->m_deskId + 1;//actally the same as i+1;

                proto_ff::GameDeskInfo *pDeskInfo = deskListRsp.add_desks();
                pDeskInfo->set_desk_id(deskId);
                pDeskInfo->set_desk_name("deskName");
                pDeskInfo->set_desk_status(0);
                pDeskInfo->set_chair_count(pDesk->m_chairCount);

                for (int j = 0; j < (int) pDesk->m_arrDeskStationId.size(); j++)
                {
                    NFGameDeskStation *destStation = pDesk->GetDeskStation(j);

                    proto_ff::GameChairInfo *pChairInfo = pDeskInfo->add_chairs();
                    if (pChairInfo != NULL)
                    {
                        int chairId = j + 1;

                        pChairInfo->set_chair_id(chairId);

                        if (destStation->m_playerId == 0)
                        {
                            pChairInfo->set_chair_status(0);//idle
                        }
                        else
                        {
                            pChairInfo->set_chair_status(1);//有人
                        }
                    }
                }
            }
        }
    }
    else //autoChairId=0  //auto sel chair
    {
        int iDeskIndex = -1;
        int iDeskStaion = -1;
        if (LookingSuitSeatForPlayer(playerId, iDeskIndex, iDeskStaion) == 0)
        {
            NFGamePlayer *pPlayer = NFGamePlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
            if (pPlayer)
            {
                pPlayer->m_reservedTime = NFTime::Now().UnixSec();
                pPlayer->m_reservedDeskId = iDeskIndex;
                pPlayer->m_reservedChairId = iDeskStaion;
            }

            int iDeskId = iDeskIndex + 1;
            int iChairId = iDeskStaion + 1;

            proto_ff::GameDeskInfo *pDeskInfo = deskListRsp.add_desks();
            pDeskInfo->set_desk_id(iDeskId);
            pDeskInfo->set_desk_name("deskName");
            pDeskInfo->set_desk_status(0);
            pDeskInfo->set_chair_count(1);

            //自动选一个座位并保留 todo

            proto_ff::GameChairInfo *pChairInfo = pDeskInfo->add_chairs();
            pChairInfo->set_chair_id(iChairId);
            pChairInfo->set_chair_status(0);

            NFLogTrace(NF_LOG_SYSTEMLOG, playerId, "playerId:{} desk list req, auto desk ! iDeskId = {}, iChairId = {}", playerId, iDeskId, iChairId);
        }
    }

    return 0;
}

int NFGameRoom::LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskIndex, int &iDeskStation)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    uint64_t ulNowTime = NFTime::Now().UnixSec();
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer && ulNowTime - pPlayer->m_reservedTime <= 15)
    {
        NFGameDesk *pDesk = GetGameDesk(pPlayer->m_reservedDeskId);
        if (pDesk)
        {
            auto pDeskStation = pDesk->GetDeskStation(pPlayer->m_reservedChairId);
            if (pDeskStation && pDeskStation->m_playerId <= 0)
            {
                iDeskIndex = pPlayer->m_reservedDeskId;
                iDeskStation = pPlayer->m_reservedChairId;

                NFLogInfo(NF_LOG_SYSTEMLOG, playerId,
                          "GameRoom::LookingSuitSeatForPlayer PlayerId:{} find a seat in desk. DeskIndex:{}, DeskStation:{}.",
                          playerId, iDeskIndex, iDeskStation);

                ReserveSeat(playerId, iDeskIndex, iDeskStation);
                return 0;
            }
        }
    }

    std::vector<TDeskStationNode> vtSeatsList;
    for (int i = 0; i < GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            if (pDesk->LookingSuitSeatForPlayer(playerId, iDeskStation) == 0)
            {
                iDeskIndex = pDesk->m_deskId;
                TDeskStationNode tmpDeskStationNode;
                tmpDeskStationNode.m_nDeskIndex = iDeskIndex;
                tmpDeskStationNode.m_nDeskStation = iDeskStation;
                vtSeatsList.push_back(tmpDeskStationNode);
                //从性能考虑，找到10个桌子，就可以了
                if (vtSeatsList.size() >= 10)
                {
                    break;
                }
            }
        }
    }

    //找到对应位置，做一次随机取值
    if (vtSeatsList.size() > 0)
    {
        int unIndex = NFRandInt(0, (int) vtSeatsList.size());
        iDeskIndex = vtSeatsList[unIndex].m_nDeskIndex;
        iDeskStation = vtSeatsList[unIndex].m_nDeskStation;
        NFLogInfo(NF_LOG_SYSTEMLOG, playerId,
                  "GameRoom::LookingSuitSeatForPlayer PlayerId:{} find a seat in desk. DeskIndex:{}, DeskStation:{}.",
                  playerId, iDeskIndex, iDeskStation);
        //预定该位置
        ReserveSeat(playerId, iDeskIndex, iDeskStation);
        return 0;
    }

    //顺序找一个位置
    for (int iDeskId = 0; iDeskId < GetDeskCount(); iDeskId++)
    {
        NFGameDesk *pDesk = GetGameDesk(iDeskId);
        if (pDesk == NULL) continue;

        if (pDesk->Looking4SeatBySequence(playerId, iDeskStation) == 0)
        {
            iDeskIndex = pDesk->m_deskId;
            NFLogInfo(NF_LOG_SYSTEMLOG, playerId,
                      "CGameRoom::LookingSuitSeatForPlayer() playerId:{} find a seat 4 sequence. DeskIndex:{}, DeskStation:{}.",
                      playerId, iDeskIndex, iDeskStation);
            //预定该位置
            ReserveSeat(playerId, iDeskIndex, iDeskStation);
            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return -1;
}

int NFGameRoom::ReserveSeat(uint64_t playerId, int iDeskId, int iDeskStation)
{
    CHECK_EXPR(iDeskId >= 0 && iDeskId < GetDeskCount(), -1, "iDeskId error:{}", iDeskId);

    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->ReserveSeat(playerId, iDeskStation);
}

int NFGameRoom::ClearGameRoomStatInfo()
{
    m_roomStatInfo.cur_pour = 0;
    m_roomStatInfo.cur_fee = 0;
    m_roomStatInfo.cur_win = 0;
    return 0;
}

int NFGameRoom::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    m_roomStatInfo.cur_pour += cur_pour;
    m_roomStatInfo.cur_fee += cur_fee;
    m_roomStatInfo.cur_win += cur_win;
    m_roomStatInfo.MarkDirty();

    return 0;
}

int NFGameRoom::ClearJiangChi()
{
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ClearJiangChi();
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    return 0;
}

int NFGameRoom::ChangeJiangChi(int64_t jiangchi)
{
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ChangeJiangChi(jiangchi);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    return 0;
}

int NFGameRoom::EnterGame(uint64_t playerId, int deskId, int chairId, proto_ff_s::GamePlayerDetailData_s& playerDetail)
{
    auto roomConfig = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(m_gameId, m_roomId);
    CHECK_NULL(roomConfig);

    if (roomConfig->m_enter_min > 0)
    {
        if (playerDetail.cur_money < roomConfig->m_enter_min)
        {
            return proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH;
        }
    }

    if (roomConfig->m_enter_max > 0)
    {
        if (playerDetail.cur_money > roomConfig->m_enter_max)
        {
            return proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH;
        }
    }

    if (roomConfig->m_is_exp_scene > 0)
    {
        playerDetail.cur_money = roomConfig->m_exp_scene_gold;
    }

    NFGameDesk *pDesk = GetGameDesk(deskId);
    if (!pDesk)
    {
        return proto_ff::ERR_CODE_DESK_NOT_EXIST;
    }

    return pDesk->LoginDesk(playerId, chairId, playerDetail);
}
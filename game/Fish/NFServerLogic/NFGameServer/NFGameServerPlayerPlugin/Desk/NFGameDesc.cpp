// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesc.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameDesc
//
// -------------------------------------------------------------------------

#include "NFGameDesk.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFLogicCommon/NFIGameDeskImpl.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Player/NFGamePlayerMgr.h"
#include "DescStore/ConstantConstantDesc.h"
#include "Room/NFGameRoom.h"
#include "Room/NFGameRoomMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicCommon/NFIGameRoomModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameDesk, EOT_NFGameDesc_ID, NFIGameDesk)

NFGameDesk::NFGameDesk()
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

NFGameDesk::~NFGameDesk()
{
}

int NFGameDesk::CreateInit()
{
    m_deskHandle = NULL;
    m_roomHandle = NULL;
    m_deskId = INVALID_ID;
    m_gameId = 0;
    m_roomId = 0;
    m_chairCount = 0;
    m_maxUserNum = 0;

    m_arrDeskStationId.resize(m_chairCount);

    m_bTableLocked = false; //锁定标志
    m_bGameStarted = false; //开始标志
    m_bGameStatus = GAMES_FREE;                        //游戏状态
    m_dwTimeStart = 0;                        //开始时间
    return 0;
}

int NFGameDesk::ResumeInit()
{
    return 0;
}

int NFGameDesk::Init(uint32_t gameId, uint32_t roomId, int32_t deskIndex, uint32_t sitNum,
                     uint32_t maxUserNum, NFGameRoom *pRoomHandle)
{
    m_roomHandle = pRoomHandle;
    m_gameId = gameId;
    m_roomId = roomId;
    m_deskId = deskIndex;//index first is 0
    m_chairCount = sitNum;
    m_maxUserNum = maxUserNum;
    m_arrDeskStationId.resize(m_chairCount);
    m_bGameStarted = true;
    m_bGameStatus = GAMES_PLAYING;
    m_dwTimeStart = NFTime::Now().UnixSec();
    m_deskHandle = FindModule<NFIGameRoomModule>()->CreateDesk(gameId);
    CHECK_EXPR(m_deskHandle, -1, "Create Game Desk Handle Failed, gameId:{}, roomId:{}, deskIndex:{}", gameId, roomId, deskIndex);
    if (m_deskHandle)
    {
        m_deskHandle->Init(this, m_gameId, m_roomId, m_deskId, m_chairCount, m_maxUserNum);
    }
    return 0;
}

int NFGameDesk::Tick()
{
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId > 0) {
            pDeskStation->Tick();
        }
    }
    return 0;
}

NFGameDeskStation *NFGameDesk::GetDeskStation(int iDeskStation)
{
    CHECK_EXPR(iDeskStation >= 0 && iDeskStation < (int) m_arrDeskStationId.size(), NULL, "iDestStation:{} param error", iDeskStation);
    return &m_arrDeskStationId[iDeskStation];
}

NFGameDeskStation *NFGameDesk::GetDeskStationByPlayerId(uint64_t playerId)
{
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++)
    {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId)
        {
            return pDeskStation;
        }
    }
    return NULL;
}

int NFGameDesk::OnGameBegin()
{
    return 0;
}

int NFGameDesk::OnGameFinish()
{
    return 0;
}

bool NFGameDesk::IsInDesk(uint64_t playerId)
{
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++)
    {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId)
        {
            return true;
        }
    }
    return false;
}

bool NFGameDesk::IsPlayGame(int iChairIndex)
{
    if (!m_deskHandle)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFGameDesk::IsUserPlaying Error, m_deskHandle == NULL, iChairIndex:{}", iChairIndex);
        return false;
    }
    return m_deskHandle->IsPlayGame(iChairIndex);
}

bool NFGameDesk::IsPlayGameCanLeave(int iChairIndex)
{
    if (!m_deskHandle)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFGameDesk::IsPlayGameCanLeave Error, m_deskHandle == NULL, iChairIndex:{}", iChairIndex);
        return false;
    }
    return m_deskHandle->IsPlayGameCanLeave(iChairIndex);
}

int NFGameDesk::LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskStation)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    //计算出当前座位已坐总人数(包括机器人)
    int iTotalCount = 0;
    int iRobotCount = 0;
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++)
    {
        //统计所有人
        if (m_arrDeskStationId[i].m_playerId > 0)
        {
            iTotalCount++;
        }

        //统计机器人
        if (m_arrDeskStationId[i].m_isRobot == true)
        {
            iRobotCount++;
        }
    }

    //计算剩余位置数
    int iLeftCount = m_arrDeskStationId.size() - iTotalCount;
    if (iLeftCount <= 0)
    {
        //没有位置了，直接返回false
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "CGameDesk::Looking4SeatInRobotsForBrand This RoomID:{} DeskID:{} has not any seat for player:{}!",
                   m_roomId, m_deskId, playerId);
        return -1;
    }

    //如果该桌子坐的没有机器人,直接返回false
    //if (iRobotCount <= 0) {
    //    NFLogError(NF_LOG_SYSTEMLOG, 0,
    //               "CGameDesk::Looking4SeatInRobotsForBrand This desk RoomID:{} DeskID:{} has no robots! persons:{} MaxUserNum:{}, so ignore it!",
    //               m_roomId, m_deskId, iTotalCount, m_maxUserNum);
    //    //return -1;
    //}

    uint32_t ulNowTime = NFTime::Now().UnixSec();

    //如果该桌子有真人，则顺序找一个位置坐下
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++)
    {
        //没有人在坐，则认为该位置时可用的
        if ((m_arrDeskStationId[i].m_playerId <= 0) &&
            ((ulNowTime - m_arrDeskStationId[i].m_reservedTime) > 15 || m_arrDeskStationId[i].m_reservedPlayerId == playerId))
        {
            //先得到对应新的位置
            iDeskStation = i;
            NFLogTrace(NF_LOG_SYSTEMLOG, playerId,
                       "CGameDesk::LookingSuitSeatForPlayer() Found a new seat RoomID:{} DeskID:{} Station:{} for playerId:{} MaxUserNum:{}. ",
                       m_roomId, m_deskId, iDeskStation, playerId, m_maxUserNum);
            return 0;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return -1;
}


int NFGameDesk::Looking4SeatBySequence(uint64_t playerId, int &iDeskStation)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    //计算出当前座位已坐总人数(包括机器人)
    int i = 0;
    int iTotalCount = 0;
    for (i = 0; i < (int) m_chairCount && i < (int) m_arrDeskStationId.size(); i++)
    {
        //统计所有人
        if (m_arrDeskStationId[i].m_playerId > 0)
        {
            iTotalCount++;
        }
    }

    //计算剩余位置数
    int iLeftCount = m_chairCount - iTotalCount;
    if (iLeftCount <= 0)
    {
        //没有位置了，直接返回false
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "CGameDesk::Looking4SeatInRobotsForBrand This RoomID:{} DeskID:{} has not any seat for player:{}!",
                   m_roomId, m_deskId, playerId);
        return -1;
    }

    uint32_t ulNowTime = NFTime::Now().UnixSec();

    //如果该桌子有真人，则顺序找一个位置坐下
    int bResult = -1;
    int iRandDeskStation = NFRandInt(1, (int) iLeftCount);
    int iValidSite = 1;
    for (i = 0; i < (int) m_chairCount && i < (int) m_arrDeskStationId.size(); i++)
    {
        //没有人在坐，则认为该位置时可用的
        if ((m_arrDeskStationId[i].m_playerId <= 0) &&
            ((ulNowTime - m_arrDeskStationId[i].m_reservedTime) > 15 || m_arrDeskStationId[i].m_reservedPlayerId == playerId))
        {
            //先得到对应新的位置
            iDeskStation = i;
            bResult = 0;
            if (iValidSite == iRandDeskStation)
            {
                break;
            }
            iValidSite++;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return bResult;
}

int NFGameDesk::ReserveSeat(uint64_t playerId, int iDeskStation)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    CHECK_EXPR(iDeskStation >= 0 && iDeskStation < (int) m_arrDeskStationId.size(), -1,
               "CGameDesk::ReserveSeat()  iDeskStation:{} is invalid!!! PlayerId:{}", iDeskStation, playerId);

    m_arrDeskStationId[iDeskStation].m_reservedPlayerId = playerId;
    m_arrDeskStationId[iDeskStation].m_reservedTime = NFTime::Now().UnixSec();

    NFLogInfo(NF_LOG_SYSTEMLOG, playerId,
              "CGameDesk::ReserveSeat()  playerId:{} reserved the seat: m_nRoomID:{} m_nDeskIndex:{} iDeskStation:{}",
              playerId, m_roomId, m_deskId, iDeskStation);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameDesk::ClearDirtyData(uint64_t playerId)
{
    if (!m_deskHandle)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::ClearDirtyData Error, m_deskHandle == NULL");
        return -1;
    }

    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++)
    {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId)
        {
            if (m_deskHandle->IsPlayGame(i) && !m_deskHandle->IsPlayGameCanLeave(i))
            {
                pDeskStation->m_onlineFlags = 0;
                return -1;
            }

            if (m_deskHandle->IsPlayGame(i) && !m_deskHandle->IsPlayGameCanLeave(i))
            {
                pDeskStation->m_onlineFlags = 0;
                return -1;
            }

            int iRet = m_deskHandle->UserLeftDesk(playerId, pDeskStation->m_chairId, pDeskStation->m_playerDetail);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "UserLeftDesk Failed!");
                return iRet;
            }

            NotifyServerPlayerExitGame(playerId, pDeskStation->m_chairId);

            pDeskStation->ClearData();

            NFGamePlayer* pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
            if (pPlayer)
            {
                pPlayer->ClearGameData();
            }
        }
    }

    return 0;

}

int NFGameDesk::ClearTimeOutUser(uint64_t playerId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId) {
            if (IsPlayGame(i) && !IsPlayGameCanLeave(i)) {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "ClearTimeOutUser() playerId:{} roomId:{} deskId:{} deskStation:{} is still playing!",
                           playerId, m_roomId, m_deskId, i);
                return -1;
            }

            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "ClearTimeOutUser playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                       playerId, m_roomId, m_deskId, i);

            int iRet = UserLeftDesk(playerId, i, pDeskStation->m_playerDetail);
            if (iRet) {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "ClearTimeOutUser, m_deskHandle->UserLeftDesk() Failed! iRet:{}, playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                           iRet, playerId, m_roomId, m_deskId, i);
                return iRet;
            }

            pDeskStation->ClearData();
        }
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");

    return 0;
}

int NFGameDesk::ClearOfflineUser(uint64_t playerId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    for (int i = 0; i < (int) m_arrDeskStationId.size(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId) {
            if (IsPlayGame(i) && !IsPlayGameCanLeave(i)) {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "ClearOfflineUser() playerId:{} roomId:{} deskId:{} deskStation:{} is still playing!",
                           playerId, m_roomId, m_deskId, i);
                return -1;
            }

            NFLogInfo(NF_LOG_SYSTEMLOG, 0,
                      "ClearOfflineUser playerId:{} Left desk! roomId:{} deskId:{} deskStation:{}!",
                      playerId, m_roomId, m_deskId, i);

            int iRet = UserLeftDesk(playerId, i, pDeskStation->m_playerDetail);
            if (iRet) {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "ClearOfflineUser, m_deskHandle->UserLeftDesk() Failed! iRet:{}, playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                           iRet, playerId, m_roomId, m_deskId, i);
                return iRet;
            }

            pDeskStation->ClearData();
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFGameDesk::NotifyServerPlayerExitGame(uint64_t playerId, int32_t chairId)
{
    proto_ff::Proto_NotifyServerPlayerExitGame msg;
    msg.set_player_id(playerId);
    msg.set_game_id(m_gameId);
    msg.set_room_id(m_roomId);
    msg.set_desk_id(chairId);
    SendMsgToWorldServer(proto_ff::NF_STS_GAME_PLAYER_LEAVE_GAME, msg, playerId);
    return 0;
}

int NFGameDesk::UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserReCome Error, m_deskHandle == NULL");
        return -1;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "22222222222222222222222+> iDeskStation = {} , playerId = {}", iDeskStation, playerId);


    return m_deskHandle->UserReCome(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserSitDesk Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserSitDesk(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserLeftDesk Error, m_deskHandle == NULL");
        return -1;
    }

    auto pDeskStation = GetDeskStation(iDeskStation);
    CHECK_NULL(pDeskStation);

    int iRet = m_deskHandle->UserLeftDesk(playerId, iDeskStation, playerDetail);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "UserLeftDesk Failed!");
        return iRet;
    }

    NotifyServerPlayerExitGame(playerId, iDeskStation);
    pDeskStation->ClearData();

    ClearDirtyData(playerId);

    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer) {
        pPlayer->ClearGameData();
    }

    return 0;
}

int NFGameDesk::UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserReconDesk Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserReconDesk(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserAgreeGame Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserAgreeGame(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UserAgreeGame Error, m_deskHandle == NULL");
        return -1;
    }

    return m_deskHandle->UserDisconnect(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
    CHECK_EXPR(moneyChange > 0, -1, "moneyChange error:{}", moneyChange);

    auto roomConfig = FishRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return proto_ff::ERR_CODE_SYSTEM_ERROR;
    }

    if (roomConfig->m_isexpscene > 0)
    {
        return 0;
    }

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "UpdateUserMoney Error, can't find player:{} station, changeType:{} moneyChange:{}", playerId, changeType, moneyChange);

    uint32_t accountType = 0;
    uint32_t optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN;
    uint32_t optReason = 0;

    //根据加币、减币进行操作
    if (changeType == proto_ff::E_CHAGEMONEY_GAME_ADD)
    {
        pDeskStation->m_playerDetail.cur_money += moneyChange;
        pDeskStation->m_wealthData.total_win += moneyChange;
        pDeskStation->m_wealthData.this_game_win += moneyChange;

        accountType = proto_ff::E_ACCOUNT_TYPE_JETTON;
        optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN;
        optReason = proto_ff::E_GAME_BALANCE_REASON_PLAY_GAME_WIN;
    }
    else if (changeType == proto_ff::E_CHAGEMONEY_GAME_REMOVE)
    {
        pDeskStation->m_playerDetail.cur_money -= moneyChange;
        pDeskStation->m_wealthData.total_win -= moneyChange;
        pDeskStation->m_wealthData.this_game_win -= moneyChange;

        accountType = proto_ff::E_ACCOUNT_TYPE_JETTON;
        optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_LOST;
        optReason = proto_ff::E_GAME_BALANCE_REASON_PLAY_GAME_LOST;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::UpdateUserMoney Error! unknown changeType! playerId:{} changeType:{} moneyChange:{}", playerId, changeType, moneyChange);
        return -1;
    }

/*
    proto_ff::Proto_UpdateJettonReq reqMsg;
    if (changeType == proto_ff::E_CHAGEMONEY_GAME_ADD)
    {
        reqMsg.set_add_or_deduce(true);
    }
    else if (changeType == proto_ff::E_CHAGEMONEY_GAME_REMOVE)
    {
        reqMsg.set_add_or_deduce(false);
    }
    else
    {
        return -1;
    }

    reqMsg.set_player_id(playerId);
    reqMsg.set_game_id(m_gameId);
    reqMsg.set_room_id(m_roomId);
    reqMsg.set_desk_id(m_deskId);
    reqMsg.set_chair_id(pDeskStation->m_chairId);
    reqMsg.set_account_type(accountType);
    reqMsg.set_opt_type(optType);
    reqMsg.set_opt_reason(optReason);
    reqMsg.set_change_type(changeType);
    reqMsg.set_money_change(moneyChange);
    reqMsg.set_time(NFTime::Now().UnixSec());

    SendMsgToLogicServer(proto_ff::E_GTL_UPDATE_JETTON_REQ, reqMsg, playerId);
*/

    return 0;
}

int NFGameDesk::UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "NFGameDesk::SetUserManagerInfo Error, m_deskHandle == NULL");
        return -1;
    }

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_SYSTEM_ERROR, "pDeskStation == NULL");

    int64_t moneyChange = pPlayerDetail->cur_money - pDeskStation->m_iEnterUserMoney;
    if (0 != moneyChange)
    {
        pDeskStation->m_iEnterUserMoney += moneyChange;
        pDeskStation->m_iCurUserMoney   += moneyChange;

        ProcUserSettlement(pDeskStation);
    }

    pDeskStation->m_playerDetail.player_id = playerId;
    pDeskStation->m_playerDetail.cur_money = pPlayerDetail->cur_money;
    pDeskStation->m_playerDetail.vip_level = pPlayerDetail->vip_level;
    pDeskStation->m_playerDetail.sex = pPlayerDetail->sex;
    pDeskStation->m_playerDetail.chair_id = pDeskStation->m_chairId;
    pDeskStation->m_playerDetail.nick_name = pPlayerDetail->nick_name;
    pDeskStation->m_playerDetail.face = pPlayerDetail->face;

    pDeskStation->m_wealthData.player_id = playerId;

    return m_deskHandle->UpdateUserInfo(playerId, pPlayerDetail);
}

int NFGameDesk::ProcUserSettlement(NFGameDeskStation* pDeskStation)
{
    CHECK_NULL(pDeskStation);

    int64_t moneyChange = (int64_t)pDeskStation->m_iCurUserMoney - (int64_t)pDeskStation->m_iEnterUserMoney;
    if (moneyChange == 0)
    {
        return 0;
    }

    uint32_t changeType = proto_ff::E_CHAGEMONEY_GAME_ADD;
    if (moneyChange < 0)
    {
        changeType = proto_ff::E_CHAGEMONEY_GAME_REMOVE;
        moneyChange = -moneyChange;

        NFLogInfo(NF_LOG_SYSTEMLOG, pDeskStation->m_playerId, "ProcUserSettlement playerId:{} reduce money:{} curMoney:{} enterMoney:{} gameId:{} roomId:{} deskId:{}",
                  pDeskStation->m_playerId, moneyChange, pDeskStation->m_iCurUserMoney, pDeskStation->m_iEnterUserMoney, m_gameId, m_roomId, m_deskId);
    }
    else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pDeskStation->m_playerId, "ProcUserSettlement playerId:{} add money:{} curMoney:{} enterMoney:{} gameId:{} roomId:{} deskId:{}",
                  pDeskStation->m_playerId, moneyChange, pDeskStation->m_iCurUserMoney, pDeskStation->m_iEnterUserMoney, m_gameId, m_roomId, m_deskId);
    }

    UpdateUserMoney(pDeskStation->m_playerId, changeType, moneyChange);

    pDeskStation->m_iEnterUserMoney = pDeskStation->m_iCurUserMoney;

    return 0;
}

int NFGameDesk::ClearJiangChi()
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFGameDesk::ClearJiangChi Error, m_deskHandle == NULL");
        return -1;
    }

    return m_deskHandle->ClearJiangChi();
}

int NFGameDesk::ChangeJiangChi(int64_t jiangchi)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFGameDesk::ChangeJiangChi Error, m_deskHandle == NULL");
        return -1;
    }

    return m_deskHandle->ChangeJiangChi(jiangchi);
}

int NFGameDesk::ProcUserSettlement(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "ProcUserSettlement Error, can't find player:{} station", playerId);

    return ProcUserSettlement(pDeskStation);
}

int NFGameDesk::DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "DeduceGameMoney Error, can't find player:{} station", playerId);

    if (moneyChange > 0)
    {
        if (pDeskStation->m_iCurUserMoney >= moneyChange)
        {
            pDeskStation->m_iCurUserMoney -= moneyChange;
        }
        else
        {
            pDeskStation->m_iCurUserMoney = 0;
        }
        if (procUserSettlement)
        {
            ProcUserSettlement(pDeskStation);
        }
    }
    return 0;
}

int NFGameDesk::AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "AddGameMoney Error, can't find player:{} station", playerId);

    if (moneyChange > 0)
    {
        pDeskStation->m_iCurUserMoney += moneyChange;
        if (procUserSettlement)
        {
            ProcUserSettlement(pDeskStation);
        }
    }
    return 0;
}

uint64_t NFGameDesk::GetPlayerCurMoney(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, 0, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->m_iCurUserMoney;
}

int NFGameDesk::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    if (m_roomHandle)
    {
        return m_roomHandle->GameDataCommit(cur_fee, cur_pour, cur_win);
    }
    return 0;
}

int64_t NFGameDesk::CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton)
{
    if (CountByFee <= 0)
    {
        return CountByFee;
    }

    auto roomConfig = FishRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return CountByFee;
    }

    uint32_t tax = roomConfig->m_tax;

    uint32_t tax_mode = 0;
    auto pDesc = ConstantConstantDesc::Instance(m_pObjPluginManager)->GetDesc(proto_ff::EN_CONST_USER_FEE_WITH_POUR);
    if (pDesc)
    {
        tax_mode = pDesc->m_constantdata;
    }

    CHECK_EXPR(tax > 0 && tax <= 100, CountByFee, "tax param error,tax:{}", tax);
    int64_t tmpCount = CountByFee;
    //不加本金抽水
    if (tax_mode == 0)
    {
        tmpCount = CountByFee - pourJetton;
        if (tmpCount <= 0)
        {
            return CountByFee;
        }
    }

    uint64_t commission = std::ceil(tmpCount * tax / (double)100);
    uint64_t realCount = CountByFee - commission;

    return realCount;
}

int NFGameDesk::AchievementCount(uint64_t userid, uint64_t ach, uint64_t fee)
{
    if (ach == 0 && fee == 0) return 0;

    auto roomConfig = FishRoomDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return 0;
    }

    if (roomConfig->m_isexpscene > 0)
    {
        return 0;
    }

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(userid);
    CHECK_EXPR(pDeskStation, -1, "AchievementCount Error, can't find player:{} station, Count:{} fee:{}", userid, ach, fee);

    if (ach > 0)
    {
        uint32_t ach_mode = 0;
        auto pDesc = ConstantConstantDesc::Instance(m_pObjPluginManager)->GetDesc(proto_ff::EN_CONST_USER_ACH_WITH_FEE);
        if (pDesc)
        {
            ach_mode = pDesc->m_constantdata;
        }

        if (ach_mode == 0)
        {
            pDeskStation->m_achievementData.cur_ach += ach - (int64_t)fee;
        }
        else
        {
            pDeskStation->m_achievementData.cur_ach += ach;
        }

        pDeskStation->m_achievementData.MarkDirty();
    }

    if (fee > 0)
    {
        pDeskStation->m_achievementData.cur_fee += fee;
        pDeskStation->m_achievementData.MarkDirty();
    }
    return 0;
}

int NFGameDesk::EnterGame(uint64_t playerId, int chairIndex, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    CHECK_EXPR(m_deskHandle, proto_ff::ERR_CODE_SYSTEM_ERROR, "param error, m_deskHandle == NULL");

    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_EXPR(pPlayer, proto_ff::ERR_CODE_PLAYER_NOT_EXIST, "pPlayer == NULL");

    NFGameDeskStation* pDeskStation = GetDeskStation(chairIndex);
    CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_CHAIR_NOT_RIGHT, "pDeskStation == NULL");

    //判断位置上是否有人,如果是自己，则放行，位置被自己占住，说明自己曾经异常退出，要么需要重新入座，要么先清理数据
    if (pDeskStation->m_playerId > 0 && pDeskStation->m_playerId != playerId)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0,
                   "Error:CGameDesk::EnterGame() chairIndex:{} is using! Request sit down's playerID:{}, "
                   "Aleady sit down's playerId:{}. OprInfo: m_nRoomID:{} DeskId:{}.",
                   chairIndex, playerId, pDeskStation->m_playerId, m_roomId, m_deskId);

        return proto_ff::ERR_CODE_CHAIR_HAS_OTHER_PLAYTER;
    }

    playerDetail.chair_id = chairIndex;
    int iSitResult = -1;
    if (pPlayer->IsInGame() && IsPlayGame(chairIndex) == true)
    {
        iSitResult = UserReCome(playerId, chairIndex, playerDetail);
    }
    else
    {
        iSitResult = UserSitDesk(playerId, chairIndex, playerDetail);
    }

    if (iSitResult != 0) //如果没进入成功，则清理
    {
        int iRet = UserLeftDesk(playerId, chairIndex, playerDetail);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "playerId:{} Left Desk Failed!", playerId);
        }

        return iSitResult;
    }

    pDeskStation->m_isRobot = false;
    pDeskStation->m_playerId = playerId;
    pDeskStation->m_onlineFlags = 1;
    pDeskStation->m_reservedPlayerId = 0;
    pDeskStation->m_reservedTime = 0;
    pDeskStation->m_chairId = chairIndex;
    pDeskStation->m_iCurUserMoney = playerDetail.cur_money;
    pDeskStation->m_iEnterUserMoney = playerDetail.cur_money;

    pDeskStation->m_playerDetail.player_id = playerDetail.player_id;
    pDeskStation->m_playerDetail.cur_money = playerDetail.cur_money;
    pDeskStation->m_playerDetail.vip_level = playerDetail.vip_level;
    pDeskStation->m_playerDetail.sex = playerDetail.sex;
    pDeskStation->m_playerDetail.chair_id = chairIndex;
    pDeskStation->m_playerDetail.nick_name = playerDetail.nick_name;
    pDeskStation->m_playerDetail.face = playerDetail.face;

    pDeskStation->m_wealthData.player_id = playerId;
    return 0;
}

int NFGameDesk::ExitGame(uint64_t playerId, bool bOffline)
{
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    if (!pPlayer)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        return 0;
    }

    if (m_gameId != pPlayer->m_gameId || m_roomId != pPlayer->m_roomId || m_deskId != pPlayer->m_deskId)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        return 0;
    }

    NFGameDeskStation* pGameDeskStation = GetDeskStation(pPlayer->m_chairId);
    if (pGameDeskStation == NULL)
    {
        NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
        return 0;
    }
    else
    {
        if (pGameDeskStation->m_playerId != playerId)
        {
            NFGameRoomMgr::GetInstance(m_pObjPluginManager)->ClearDirtyData(playerId);
            return 0;
        }

        //获取当前用户是否在游戏中
        bool bUserIsPaying = IsPlayGame(pPlayer->m_chairId);
        if (bOffline)
        {
            if (bUserIsPaying)
            {
                UserDisconnect(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
                return 0;
            }
            else
            {
                UserLeftDesk(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
            }
        }
        else
        {
            if (bUserIsPaying && !IsPlayGameCanLeave(pPlayer->m_chairId))
            {
                return proto_ff::ERR_CODE_EXIT_NOT_PERMITED_WHILE_PLAYING;
            }
            else
            {
                UserLeftDesk(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
            }
        }

        pGameDeskStation->ClearData();
        pPlayer->ClearGameData();
    }

    return 0;
}

int NFGameDesk::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "player:{} not exist", playerId);
    if (pPlayer->GetProxyId() > 0)
    {
        FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, pPlayer->GetProxyId(), nMsgId, xData, playerId);
    }

    return 0;
}

int NFGameDesk::BroadCastMsgToDesk(uint32_t nMsgId, const google::protobuf::Message &xData, int32_t chairId)
{
    for (int i = 0; i < (int)m_arrDeskStationId.size(); i++) {
        if (m_arrDeskStationId[i].m_playerId == 0 || i == chairId) {
            continue;
        }

        if (m_arrDeskStationId[i].m_isRobot == true) {
            continue;
        }

        if (m_arrDeskStationId[i].m_onlineFlags <= 0) {
            continue;
        }

        SendMsgToClient(nMsgId, xData, m_arrDeskStationId[i].m_playerId);
    }
    return 0;
}

int NFGameDesk::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_GAME_SERVER, nMsgId, xData, playerId);
    return 0;
}

int NFGameDesk::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "player:{} not exist", playerId);
    CHECK_EXPR(pPlayer->GetLogicId() > 0, -1, "player:{} no logic:{}", playerId, pPlayer->GetLogicId());
    FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_GAME_SERVER, pPlayer->GetLogicId(), nMsgId, xData, playerId);
    return 0;
}

int NFGameDesk::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_GAME_SERVER, nMsgId, xData, playerId);
    return 0;
}

int NFGameDesk::OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet)
{
    if (m_deskHandle) {
        return m_deskHandle->OnHandleClientMessage(playerId, packet);
    }
    return -1;
}

int NFGameDesk::OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet)
{
    if (m_deskHandle) {
        return m_deskHandle->OnHandleServerMessage(playerId, packet);
    }
    return -1;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish2004Desk.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish2004Desk
//
// -------------------------------------------------------------------------

#include "NFGameFishDesk.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "CSFish.pb.h"
#include "NFGameFishDefine.h"
#include "Config/NFFishPromptConfig.h"
#include "DescStore/FishGunvalueDesc.h"
#include "DescStore/FishConfigDesc.h"

#define STATUS_NEXT      0
#define STATUS_TIMEDELAY 1
#define STATUS_WAIT_REGULAR_GROUP 2
#define STATUS_WAIT_WAYBILL_FINISH 3
#define STATUS_TIMEDELAY_GROUP 4

enum eWayBillSts
{
    eWayBillSts_NormalNext = 0,
    eWayBillSts_Play,

};

IMPLEMENT_IDCREATE_WITHTYPE(NFGameFishDesk, EOT_NFGameFishDesk_ID, NFShmObj)

NFGameFishDesk::NFGameFishDesk()
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

NFGameFishDesk::~NFGameFishDesk()
{
}

int NFGameFishDesk::CreateInit()
{
    m_playerList.resize(m_playerList.max_size());
    m_FishTypeMgr = NFFishTypeMgr::CreateObj(m_pObjPluginManager);
    m_FishTypeMgr->Init(this);
    m_iCurStatus = STATUS_NEXT;
    m_ullNextTime = 0;
    m_iCurWayBillSts = eWayBillSts_NormalNext;

    m_uSceneCount = 0;
    m_uSceneIndex = -1;

    m_iTimerObjId = SetTimer(100, INVALID_ID, 0, 0, 1, 0);
    m_iTimerPlayerId = SetTimer(1000, INVALID_ID, 0, 0, 1, 0);

    m_pCurWayBill = NULL;
    m_bIsCurRegularWayBill = false;
    m_bForceRegularWayBill = false;

    m_nCurGroupId = 0;
    m_nGroupIdToSend = 0;

    m_llLastTotalShoot = 0;
    m_llTotalShootInCtrlTime = 0;

    m_strLastWayBillName.CreateInit();
    m_bIsLastWayBillPrior = false;
    return 0;
}

int NFGameFishDesk::ResumeInit()
{
    return 0;
}

int NFGameFishDesk::Init(NFIGameDesk *pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum)
{
    NFIGameDeskImpl::Init(pGameHandle, gameId, roomId, deskId, sitNum, maxUserNum);
    auto pFishPromptConfig = GetFishPromptConfig();
    CHECK_NULL(pFishPromptConfig);
    m_uSceneCount = pFishPromptConfig->m_iSceneCount;
    m_uSceneIndex = -1;

    NFFishWayBillConfig *pFishBillConfig = GetFishWayBillConfig();
    CHECK_NULL(pFishBillConfig);
    m_FishWayBillMgr.InitWayBills(pFishBillConfig, true);
    m_FishWayBillMgrExt.InitWayBills(pFishBillConfig, false);
    return 0;
}

NFFishConfigConfig *NFGameFishDesk::GetFishConfigConfig()
{
    return NFFishConfigConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

NFFishGroupConfig *NFGameFishDesk::GetFishGroupConfig()
{
    return NFFishGroupConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

NFFishPromptConfig *NFGameFishDesk::GetFishPromptConfig()
{
    return NFFishPromptConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

NFFishSettingConfig *NFGameFishDesk::GetFishSettingConfig()
{
    return NFFishSettingConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

NFFishTraceConfig *NFGameFishDesk::GetFishTraceConfig()
{
    return NFFishTraceConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

NFFishWayBillConfig *NFGameFishDesk::GetFishWayBillConfig()
{
    return NFFishWayBillConfig::GetObjByHashKey(m_pObjPluginManager, m_roomId);
}

int NFGameFishDesk::UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    CHECK_EXPR(playerId > 0 && iDeskStation >= 0 && iDeskStation < (int) m_playerList.size(), -1,
               "playerId:{} deskStation:{} param error", playerId, iDeskStation);

    if (m_playerList[iDeskStation].m_ullPlayerId > 0 && m_playerList[iDeskStation].m_ullPlayerId != playerId)
    {
        return -1;
    }

    ProcUserSettlement(playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    CHECK_EXPR(playerId > 0 && iDeskStation >= 0 && iDeskStation < (int) m_playerList.size(), -1,
               "playerId:{} deskStation:{} param error", playerId, iDeskStation);

    if (playerDetail.cur_money <= 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "UserSitDesk playerId:{} chairId:{} with not enough money:{}", playerId, iDeskStation, playerDetail.cur_money);
        return -1;
    }

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    if (!pPlayer)
    {
        if (m_playerList[iDeskStation].m_ullPlayerId > 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "DeskId = {} playerId = {} sit desk, there is othre player = {} on the DeskStation = {}",
                       m_deskId, playerId, m_playerList[iDeskStation].m_ullPlayerId, iDeskStation);
            return -1;
        }

        if (playerDetail.cur_money <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "DeskId = {} playerId = {} sit desk, money is not enough:{}",
                       m_deskId, playerId, playerDetail.cur_money);
            return -1;
        }
        pPlayer = CreatePlayer(playerId, iDeskStation);
        CHECK_EXPR(pPlayer, -1, "Create GameFishPlayer Failed, playerId:{}", playerId);
    }
    else
    {
        if (pPlayer->m_uChairId != iDeskStation)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "UserSitDesk() DeskID= {} playerId = {} is already in game, with a different DeskStation = {}, input DeskStation = {}",
                       m_deskId, playerId, pPlayer->m_uChairId, iDeskStation);
            UserQuitGame(playerId);
            return -1;
        }
        else
        {
            ProcUserSettlement(pPlayer->GetPlayerID());
        }
    }

    CHECK_EXPR(pPlayer->GetPlayerID() == playerId, -1, "GameFishDesk playerId error, playerId:{} != playerId:{}",
               pPlayer->GetPlayerID(), playerId);

    pPlayer->SetDeskHandle(this);
    pPlayer->m_uChairId = iDeskStation;
    pPlayer->m_online = true;
    pPlayer->m_isRobot = playerDetail.isRobot;
    pPlayer->m_strUserName = playerDetail.nick_name.GetString();

    UserEnterDesk(pPlayer, playerDetail);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    CHECK_EXPR(playerId > 0 && iDeskStation >= 0 && iDeskStation < (int) m_playerList.size(), -1, "param error, desk station:{}", iDeskStation);

    NFGameFishPlayer *pPlayer = &m_playerList[iDeskStation];
    CHECK_EXPR(pPlayer, -1, "Get GameFishPlayer Failed, playerId:{}", playerId);
    CHECK_EXPR(pPlayer->GetPlayerID() == playerId, -1, "GameFishDesk playerId error, playerId:{} != playerId:{}", pPlayer->GetPlayerID(), playerId);

    if (pPlayer->m_uChairId != iDeskStation)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerID(), "GameFishPlayer chairId Error! chairId:{} deskStation:{}", pPlayer->m_uChairId, iDeskStation);
    }

    pPlayer->m_online = false;
    pPlayer->m_ready = false;

    m_FishTypeMgr->UserLeftDesk(pPlayer);

    UserLeaveDesk(pPlayer);

    if (GetPlayerCount() <= 0)
    {
        GameEnd();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "Create GameFishPlayer Failed, playerId:{}", playerId);

    CHECK_EXPR(pPlayer->GetPlayerID() == playerId, -1, "GameFishDesk playerId error, playerId:{} != playerId:{}",
               pPlayer->GetPlayerID(), playerId);

    if (pPlayer->m_uChairId != iDeskStation)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerID(), "GameFishPlayer chairId Error! chairId:{} deskStation:{}", pPlayer->m_uChairId, iDeskStation);
    }

    pPlayer->m_online = true;
    pPlayer->m_ready = true;

    UserEnterDesk(pPlayer, playerDetail);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    return 0;
}

int NFGameFishDesk::UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "Create GameFishPlayer Failed, playerId:{}", playerId);

    CHECK_EXPR(pPlayer->GetPlayerID() == playerId, -1, "GameFishDesk playerId error, playerId:{} != playerId:{}",
               pPlayer->GetPlayerID(), playerId);

    if (pPlayer->m_uChairId != iDeskStation)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetPlayerID(), "GameFishPlayer chairId Error! chairId:{} deskStation:{}", pPlayer->m_uChairId, iDeskStation);
    };
    pPlayer->m_online = false;
    pPlayer->m_ready = false;
    pPlayer->m_lastDisconnectTime = NFTime::Now().UnixSec();

// 	gamefish::gcUserDisconnectDesk gcMsg;
// 	gcMsg.set_chair_id(pPlayer->GetChairIdForClient());
//
// 	SendMsgToOtherClient(pPlayer->GetPlayerID(), NF_FISH_CMD_USERDISCONNECTDESK_RSP, gcMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s *pPlayerDetail)
{
    return 0;
}

int NFGameFishDesk::ClearJiangChi()
{
    return 0;
}

int NFGameFishDesk::ChangeJiangChi(int64_t jiangchi)
{
    return 0;
}

int NFGameFishDesk::OnHandleClientMessage(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);

    if (m_FishTypeMgr->OnHandleClientMessage(pPlayer, packet) == 1)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_FishTypeMgr.OnHandleClientMsg() return 1 !!!");
        return 1;
    }

    int iRet = 0;
    switch (packet.nMsgId)
    {
        //case NF_FISH_CMD_DESKINFO: {
        //	iRet = OnHandleDeskInfo(playerId, nMsgId, msg, nLen);
        //	CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishMsg_Enter ret:{}", iRet);
        //}
        //	break;
        case proto_ff::NF_CS_MSG_UserStatusReq:
        {
            iRet = OnHandleUserStaus(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleUserInfo ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_GAMESTATUS:
        {
            iRet = OnHandleFishGameStatus(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishReady ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_SHOOTBULLET:
        {
            iRet = OnHandleFishShootBullet(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishShootBullet ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_BULLETSPEED:
        {
            iRet = OnHandleFishBulletSpeed(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishBulletSpeed ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_HITFISH:
        {
            iRet = OnHandleFishHitFish(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishHitFish ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_AUTOSHOOT:
        {
            iRet = OnHandleFishAutoShoot(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishAutoShoot ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_LOCKONOFF:
        {
            iRet = OnHandleFishLockOnOff(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishLockOnOff ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_LOCKFISH:
        {
            iRet = OnHandleFishLockFish(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishLockFish ret:{}", iRet);
        }
            break;
        case NF_FISH_CMD_CHANGECANNON:
        {
            iRet = OnHandleChangeCannon(playerId, packet);
            CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "OnHandleFishLockFish ret:{}", iRet);
        }
            break;

        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "nMsgId:{} not handle in the fishdesk", packet.nMsgId);
        }
            break;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleServerMessage(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

bool NFGameFishDesk::IsPlayGame(int iDeskStation)
{
    return false;
}

bool NFGameFishDesk::IsPlayGameCanLeave(int iDeskStation)
{
    return NFIGameDeskImpl::IsPlayGameCanLeave(iDeskStation);
}

bool NFGameFishDesk::IsGamePlayerReady(uint64_t playerId)
{
    return NFIGameDeskImpl::IsGamePlayerReady(playerId);
}

int NFGameFishDesk::SendMsgToAllClient(uint32_t msgId, const google::protobuf::Message &xData, uint64_t excludePlayerId)
{
    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer)
        {
            if (pPlayer->m_online && pPlayer->m_ready && pPlayer->m_ullPlayerId != 0 && pPlayer->m_ullPlayerId != excludePlayerId)
            {
                SendMsgToClient(msgId, xData, pPlayer->GetPlayerID());
            }
        }
    }

    return 0;
}

int32_t NFGameFishDesk::GetRealPlayerChairIdForRobot()
{
    std::vector<int> vec;

    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer->m_online && !pPlayer->IsRobot())
        {
            vec.push_back(pPlayer->m_uChairId);
        }
    }

    if (vec.size() > 0)
    {
        int index = NFRandInt(0, (int) vec.size());
        return vec[index];
    }
    else
    {
        return -1;
    }
}

NFGameFishPlayer *NFGameFishDesk::GetPlayer(uint64_t playerId)
{
    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer)
        {
            if (pPlayer->GetPlayerID() == playerId)
            {
                return pPlayer;
            }
        }
    }

    return NULL;
}

NFGameFishPlayer *NFGameFishDesk::GetPlayerByChairId(uint32_t chairId)
{
    if (chairId < m_playerList.size())
    {
        NFGameFishPlayer *pPlayer = &m_playerList[chairId];
        if (pPlayer)
        {
            return pPlayer;
        }
    }

    return NULL;
}


NFGameFishPlayer *NFGameFishDesk::CreatePlayer(uint64_t playerId, int32_t iDeskStation)
{
    CHECK_PLAYER_EXPR(playerId, iDeskStation >= 0 && iDeskStation < (int32_t) m_playerList.size(), NULL,
                      "Create Player Failed, playerId:{} deskStation:{} param error", playerId, iDeskStation);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer == NULL, pPlayer, "Create Player Failed, failed exist:{}", playerId);

    NFGameFishPlayer *player = &m_playerList[iDeskStation];
    player->ResetPlayerData();
    player->SetPlayerID(playerId);
    player->m_iGameId = m_gameId;
    player->m_iRoomId = m_roomId;
    player->m_iDeskId = m_deskId;
    player->m_pDesk = this;

    return player;
}

int NFGameFishDesk::DelPlayer(uint64_t playerId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, playerId, "DelPlayer = {}", playerId);
    CHECK_PLAYER_EXPR(playerId, playerId != 0, -1, "pPlayerId = {}", playerId);
    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer)
        {
            if (pPlayer->GetPlayerID() == playerId)
            {
                pPlayer->ResetPlayerData();
                return 0;
            }
        }
    }
    return -1;
}

void NFGameFishDesk::UserEnterDesk(NFGameFishPlayer *pPlayer, proto_ff_s::GamePlayerDetailData_s &playerDetail)
{
    gamefish::gcUserEnterDesk gcUserEnterDesk;

    gamefish::UserInfo *pUserInfo = gcUserEnterDesk.mutable_userinfo();
    pUserInfo->set_chair_id(pPlayer->GetChairIdForClient());
    pUserInfo->set_user_name(pPlayer->m_strUserName.data());
    pUserInfo->set_user_money(playerDetail.cur_money);
    pUserInfo->set_cannon_id(pPlayer->m_nCurBulletLevel);

    SendMsgToAllClient(NF_FISH_CMD_USERENTERDESK_RSP, gcUserEnterDesk, pPlayer->GetPlayerID());
}

void NFGameFishDesk::UserLeaveDesk(NFGameFishPlayer *pPlayer)
{
    gamefish::gcUserLeaveDesk gcUserLeaveDesk;
    gcUserLeaveDesk.set_chair_id(pPlayer->GetChairIdForClient());

    SendMsgToAllClient(NF_FISH_CMD_USERLEAVEDESK_RSP, gcUserLeaveDesk, pPlayer->GetPlayerID());

    UserQuitGame(pPlayer->GetPlayerID());
}

int NFGameFishDesk::UserQuitGame(uint64_t playerId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "GetPlayer(playerId) Failed");

    ProcUserSettlement(playerId);

    NFLogInfo(NF_LOG_SYSTEMLOG, playerId,
              "player quit game, playerId:{} gameId:{} roomId:{} deskId:{} station:{}", playerId, m_gameId, m_roomId,
              m_deskId, pPlayer->m_uChairId);

    DelPlayer(playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

std::list<NFGameFishPlayer *> NFGameFishDesk::GetOnlinePlayers()
{
    std::list<NFGameFishPlayer *> listPlayers;

    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer->m_online)
        {
            listPlayers.push_back(pPlayer);
        }
    }

    return listPlayers;
}

int NFGameFishDesk::GetPlayerCount()
{
    uint32_t count = 0;
    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        if (m_playerList[i].m_ullPlayerId > 0)
        {
            count++;
        }
    }
    return count;
}

int NFGameFishDesk::TickPlayer()
{
    for (int i = 0; i < (int) m_playerList.size(); i++)
    {
        NFGameFishPlayer *pPlayer = &m_playerList[i];
        if (pPlayer)
        {
            pPlayer->Tick();
        }
    }
    return 0;
}

int NFGameFishDesk::GameStart()
{
    return 0;
}

int NFGameFishDesk::GameEnd()
{
    return 0;
}

int NFGameFishDesk::OnTimer(int timeId, int callcount)
{
    if (GetPlayerCount() == 0)
    {
        return 0;
    }

    if (timeId == m_iTimerPlayerId)
    {
        TickPlayer();
    }
    else if (timeId == m_iTimerObjId)//
    {
        if (!IsFreeze())
        {
            FishGroupBaseTimer(callcount);

            CheckFishOverTime();
        }
    }

    return 0;
}

int NFGameFishDesk::GetUserLoginDeskInfoMsg(gamefish::GameStatusRsp &rspMsg)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " 111111111 m_uSceneIndex = {}", m_uSceneIndex);

    m_uSceneIndex = m_uSceneIndex == -1 ? 0 : m_uSceneIndex;

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " m_uSceneIndex = {}", m_uSceneIndex);

    rspMsg.set_background_index(m_uSceneIndex);

    std::vector<const proto_ff_s::E_FishGunvalue_s *> vecGunValue = FishGunvalueDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomid(m_gameId, m_roomId);
    for (auto iter = vecGunValue.begin(); iter != vecGunValue.end(); iter++)
    {
        const proto_ff_s::E_FishGunvalue_s *pGunValue = *iter;
        CHECK_EXPR_CONTINUE(pGunValue, "");
        auto pCannonInfo = rspMsg.add_cannonlist();
        pCannonInfo->set_cannon_id(pGunValue->m_id);
        pCannonInfo->set_cannon_value(pGunValue->m_value);
        pCannonInfo->set_cannon_gun_id(pGunValue->m_gunid);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "iCannonId: {} , iValue : {} , iGunId : {}", pGunValue->m_id, pGunValue->m_value, pGunValue->m_gunid);
    }

    std::list<NFGameFishPlayer *> listPlayers = GetOnlinePlayers();
    for (auto pPlayer: listPlayers)
    {
        gamefish::UserInfo *pUserInfo = rspMsg.add_userlist();
        pUserInfo->set_chair_id(pPlayer->GetChairIdForClient());
        pUserInfo->set_user_name(pPlayer->m_strUserName.data());
        pUserInfo->set_user_money(pPlayer->GetCurMoney());
        pUserInfo->set_cannon_id(pPlayer->m_nCurBulletLevel);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "OnlinePlayer m_ullPlayerId: {} , m_uChairId: {} , m_nCurBulletLevel: {}", pPlayer->m_ullPlayerId, pPlayer->m_uChairId, pPlayer->m_nCurBulletLevel);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");


    if (vecGunValue.size() == 0 || listPlayers.size() == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int NFGameFishDesk::GetCannonValue(int iBulletLevel)
{
    const proto_ff_s::E_FishGunvalue_s *pConfig = FishGunvalueDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomidGunid(m_gameId, m_roomId, iBulletLevel);
    CHECK_EXPR(pConfig, 0, "iBulletLevel", iBulletLevel);
    return pConfig->m_value;
}

int NFGameFishDesk::OnHandleFishGameStatus(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    if (pPlayer != NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "playerId: {} ready !", playerId);

        gamefish::GameStatusRsp gameStatusRsp;
        int ret = GetUserLoginDeskInfoMsg(gameStatusRsp);

        SendMsgToClient(NF_FISH_CMD_GAMESTATUS_RSP, gameStatusRsp, playerId);

        //////////////////////////////////////////////////////////////////////////

        if (ret == 1)
        {
            SyncFishes(playerId);
            SendUserStatus(playerId);

            pPlayer->m_ready = true;

            //NFFishPropSaver::Instance()->UpdateDesk(playerId, this);

            m_FishTypeMgr->SyncFishBomb(pPlayer);
        }
    }
    else
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "pPlayer == NULL");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleUserStaus(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::UserStatusReq userInfoReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, userInfoReq);

    SendUserStatus(playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishShootBullet(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    gamefish::ShootBulletReq shootBulletReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, shootBulletReq);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    NFFishBullet bullet;
    bullet.m_uBulletId = shootBulletReq.usbulletid();
    bullet.m_iAngle = shootBulletReq.sangle();
    bullet.m_iBulletLevel = pPlayer->m_nCurBulletLevel;// shootBulletReq.bycannonlevelindex();//这个值客户传来的一直是0, 这个不对 todo:

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "OnHandleFishShootBullet() -- bullet.m_iBulletLevel = {} , bullet.m_iAngle = {}", bullet.m_iBulletLevel, bullet.m_iAngle);

    pPlayer->ShootBullet(m_pObjPluginManager, bullet);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishBulletSpeed(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::cgBulletSpeed cgBulletSpeed;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgBulletSpeed);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    pPlayer->m_iBulletSpeedLev = cgBulletSpeed.usspeedindex();


    gamefish::gcBulletSpeed gcBulletSpeed;
    gcBulletSpeed.set_uschairid(pPlayer->GetChairIdForClient());
    gcBulletSpeed.set_usspeedindex(cgBulletSpeed.usspeedindex());
    gcBulletSpeed.set_usintervalindex(cgBulletSpeed.usintervalindex());
    gcBulletSpeed.set_userrorcode(0);

    SendMsgToClient(NF_FISH_CMD_BULLETSPEED_RSP, gcBulletSpeed, playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishHitFish(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin -- ");

    gamefish::cgHitfish cgHitFish;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgHitFish);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    int iRobotChairId = cgHitFish.usrobotchairid();
    if (iRobotChairId > 0)
    {
        pPlayer = GetPlayerByChairId(iRobotChairId - 1);
        CHECK_EXPR(pPlayer, -1, "pPlayer == NULL for Robot !");

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "iRobotChairId = {} => ", iRobotChairId, iRobotChairId - 1);
    }

    NFFishBullet *pBullet = pPlayer->m_BulletMgr.GetBullet(cgHitFish.bulletid());
    if (!pBullet)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "pBullet == NULL ! bulletid = {}", cgHitFish.bulletid());
        return 0;
    }

    NFFishBullet bullet = *pBullet;
    pPlayer->m_BulletMgr.DeleteBullet(cgHitFish.bulletid());

    NFGameFish *pFish = GetFish(cgHitFish.fishid());
    if (pFish == NULL)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFCGameFishModule::OnHandleFishHitFish() Can't find fish for fishId = {}", cgHitFish.fishid());
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==================> GetFishCount() = {}", GetFishCount());

        return 0;
    }

    if (pFish->m_uFishId == INVALID_FISHID || pFish->IsKilled())
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0,
                  "CaptureFish() deskId = {} playerId = {} FishKind = {} FishID = {} has been killed!",
                  GetDeskId(), pPlayer->m_ullPlayerId, pFish->m_nFishKind, pFish->m_uFishId);

        return 0;
    }

    if (IsFishCanBeKilledByKillType(pPlayer, pFish, bullet))
    {
        uint64_t ullScoreMoney = m_FishTypeMgr->KillFishByType(pPlayer, pFish, bullet);

        if (ullScoreMoney > 0)
        {
            m_FishTypeMgr->OnAddScore(pPlayer, pFish, ullScoreMoney);

            pPlayer->AddCaptureMoney(ullScoreMoney);
        }

    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishAutoShoot(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::cgAutoShoot cgAutoShoot;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgAutoShoot);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    pPlayer->m_uAutoShootOnOff = cgAutoShoot.onoff();


    //////////////////////////////////////////////////////////////////////////
    gamefish::gcAutoShoot gcAutoShoot;
    gcAutoShoot.set_chairid(pPlayer->GetChairIdForClient());
    gcAutoShoot.set_onoff(cgAutoShoot.onoff());
    gcAutoShoot.set_userrorcode(0);

    SendMsgToClient(NF_FISH_CMD_AUTOSHOOT_RSP, gcAutoShoot, playerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishLockOnOff(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::cgLockOnOff cgLockOnOff;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgLockOnOff);


    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    pPlayer->m_uLockOnOff = cgLockOnOff.onoff();

    if (pPlayer->m_uLockOnOff == 0)
    {
        pPlayer->m_uLockFishId = 0;
    }

    //////////////////////////////////////////////////////////////////////////
    gamefish::gcLockOnOff gcLockOnOff;
    gcLockOnOff.set_chairid(pPlayer->GetChairIdForClient());
    gcLockOnOff.set_onoff(cgLockOnOff.onoff());
    gcLockOnOff.set_userrorcode(0);

    if (pPlayer->IsRobot())
    {
        SendMsgToAllClient(NF_FISH_CMD_LOCKONOFF_RSP, gcLockOnOff, pPlayer->GetPlayerID());
    }
    else
    {
        SendMsgToAllClient(NF_FISH_CMD_LOCKONOFF_RSP, gcLockOnOff);
    }


    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleFishLockFish(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::cgLockFish cgLockFish;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgLockFish);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "gcLockFish.fishid() = {}", cgLockFish.fishid());

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    pPlayer->m_uLockFishId = cgLockFish.fishid();

    gamefish::gcLockFish gcLockFish;
    gcLockFish.set_chairid(pPlayer->GetChairIdForClient());
    gcLockFish.set_fishid(pPlayer->m_uLockFishId);
    gcLockFish.set_userrorcode(0);

    SendMsgToAllClient(NF_FISH_CMD_LOCKFISH_RSP, gcLockFish);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleChangeCannon(uint64_t playerId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    gamefish::cgChangeCannon cgChangeCannon;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, cgChangeCannon);

    NFGameFishPlayer *pPlayer = GetPlayer(playerId);
    CHECK_EXPR(pPlayer, -1, "pPlayer == NULL !");

    int nBulletLevel = cgChangeCannon.cannon_id();//客户端传来的值从1开始
    const proto_ff_s::E_FishGunvalue_s *pConfig = FishGunvalueDesc::Instance(m_pObjPluginManager)->GetDescByGameidRoomidGunid(m_gameId, m_roomId, nBulletLevel);
    CHECK_EXPR(pConfig, 0, "nBulletLevel is not right:{}", nBulletLevel);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "cgChangeCannon.cannon_id() = {} , nBulletLevel = {}", cgChangeCannon.cannon_id(), nBulletLevel);

    if (nBulletLevel < 1)
    {
        return 0;
    }

    pPlayer->m_nCurBulletLevel = nBulletLevel;//本地保存的也从1开始

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "pPlayer->m_nCurBulletLevel = {}", pPlayer->m_nCurBulletLevel);

    gamefish::gcChangeCannon gcChangeCannon;
    gcChangeCannon.set_chair_id(pPlayer->GetChairIdForClient());
    gcChangeCannon.set_cannon_id(cgChangeCannon.cannon_id());

    SendMsgToAllClient(NF_FISH_CMD_CHANGECANNON_RSP, gcChangeCannon);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFGameFishDesk::OnHandleChangeScene(uint64_t playerId, NFDataPackage &packet)
{
    return 0;
}

int NFGameFishDesk::CreateFishEx(NFGameFish& fish, const CFish& fishCfg, uint16_t nDefaultFishKind, int16_t nOffsetPosX, int16_t nOffsetPosY, bool bIsRedFish)
{
    uint16_t usFishKind = nDefaultFishKind == 0 ? fishCfg.m_usFishKind : nDefaultFishKind;

    NFFishConfigConfig* pFishConfigConfig = GetFishConfigConfig();
    CHECK_EXPR(pFishConfigConfig, -1, "");

    FishConfig* pFishConfig = pFishConfigConfig->GetFishBaseInfo(usFishKind);
    CHECK_EXPR(pFishConfig, -1, "NFGameFishMgr::CreateFish() pFishKind == NULL for FishKind = {}", usFishKind);

    fish.m_uFishId = m_maxFishId++;

    fish.m_uBirthTime = NFTime::Now().UnixMSec();
    fish.m_uBirthDelayMS = fishCfg.m_BirthDelay;
    fish.m_nFishKind = usFishKind;
    fish.m_uTraceId = fishCfg.m_usTraceId;
    fish.m_nStartPointIndex = fishCfg.m_usStartPointIndex;
    fish.m_nOffSetPointCount = 0;//TODO: 这个对于普通鱼来说好像没用？
    fish.m_nOffsetPosX = nOffsetPosX;
    fish.m_nOffsetPosY = nOffsetPosY;
    fish.m_uAliveTime = fishCfg.m_unAliveTime;
    fish.m_fishKind = GetFishKind(pFishConfig);

    if (bIsRedFish)
    {
        fish.m_bIsRedFish = true;
        fish.m_fishKind.m_btFishType = NFGAME_FISHTYPE_KINDBOMB;
        fish.m_fishKind.vectSubFishes.push_back(fish.m_nFishKind);
    }
    else
    {
        fish.m_bIsRedFish = false;
    }

    //the first sub fish;
    if (fishCfg.m_byDefaultSubFish != 0)
    {
        fish.m_fishKind.vectSubFishes[0] = fishCfg.m_byDefaultSubFish;
    }

    fish.m_iDemageRadius = pFishConfig->nDamageRadius;

    return 0;
}

NFGameFish *NFGameFishDesk::CreateFish()
{
    return nullptr;
}

NFGameFish *NFGameFishDesk::GetFish(uint32_t uFishId)
{
    auto iter = m_gameFishMap.find(uFishId);
    if (iter != m_gameFishMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

void NFGameFishDesk::ClearFishes()
{
    m_gameFishMap.clear();
}

int NFGameFishDesk::GetFishCount()
{
    return m_gameFishMap.size();
}

std::vector<NFGameFish *> NFGameFishDesk::GetFishesByKind(uint8_t nFishKind)
{
    std::vector<NFGameFish *> vecFishes;
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, vecFishes, "");
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL)
        {
            continue;
        }

        if ((nFishKind == INVALID_FISHKIND || (pGameFish->m_nFishKind == nFishKind))
            && pGameFish->IsAlive()
            && IsPointInScreen(pGameFish->GetMyPoint(pConfig)))
        {
            vecFishes.push_back(pGameFish);
        }
        else
        {
            //if (pGameFish->m_nFishKind == nFishKind)
            //{
            //	int index = pGameFish->GetMyPointIndex();
            //	CHMPoint point = NFIPluginManager::Instance()->FindModule<NFCFishTraceModule>()->GetPointByIndex(pGameFish->m_uTraceId, index);
            //	CHMPoint pt = point.OffSet(pGameFish->m_nOffsetPosX, pGameFish->m_nOffsetPosY);

            //	bool isInScreen = IsPointInScreen(pt);

            //	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishMgr::GetFishesByKind() pGameFish->m_uTraceId = {} , index = {} ,point.m_iPosX = {} , point.m_iPosY = {} , m_nOffsetPosX = {} , m_nOffsetPosY = {}, pt.m_iPosX = {} , pt.m_iPosY = {}", pGameFish->m_uTraceId, index, point.m_iPosX, point.m_iPosY, pGameFish->m_nOffsetPosX, pGameFish->m_nOffsetPosY, pt.m_iPosX, pt.m_iPosY);
            //	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishMgr::GetFishesByKind() pGameFish->m_nFishKind = {} , m_btFishType = {} , pt.x = {} , pt.y = {} , isInScreen = {}", pGameFish->m_nFishKind, pGameFish->m_fishKind.m_btFishType, pGameFish->GetMyPoint().m_iPosX, pGameFish->GetMyPoint().m_iPosY, isInScreen ? "1" : "0");

            //}
        }
    }

    return vecFishes;
}

std::vector<NFGameFish *> NFGameFishDesk::GetFishesByKinds(vector<uint8_t> &vecFishKinds)
{
    std::vector<NFGameFish *> fishes;

    std::vector<uint8_t>::iterator iter = vecFishKinds.begin();
    for (; iter != vecFishKinds.end(); iter++)
    {
        std::vector<NFGameFish *> fishes1 = GetFishesByKind(*iter);

        fishes.insert(fishes.end(), fishes1.begin(), fishes1.end());
    }

    return fishes;
}

std::vector<NFGameFish *> NFGameFishDesk::GetFishes(uint8_t nFishKind, CHMPoint ptCenter, int iRadius)
{
    std::vector<NFGameFish *> vecFishes;
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, vecFishes, "");
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if ((nFishKind == INVALID_FISHKIND || (pGameFish->m_nFishKind == nFishKind)) && pGameFish->IsAlive())
        {
            CHMPoint fishPoint = pGameFish->GetMyPoint(pConfig);
            double distance = HMDistance(ptCenter, fishPoint);

            if (distance < iRadius && IsPointInScreen(fishPoint))
            {
                vecFishes.push_back(pGameFish);
            }
        }
    }

    return vecFishes;
}

std::vector<NFGameFish *> NFGameFishDesk::GetFishes(CHMPoint ptCenter, int iRadius, int iKillPercent)
{
    std::vector<NFGameFish *> vecFishes;
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, vecFishes, "");
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if (pGameFish->IsAlive())
        {
            CHMPoint fishPoint = pGameFish->GetMyPoint(pConfig);
            double distance = HMDistance(ptCenter, fishPoint);

            if (distance < iRadius && IsPointInScreen(fishPoint) && NFRandomInt(0, 100) < iKillPercent)
            {
                vecFishes.push_back(pGameFish);
            }
        }
    }

    return vecFishes;
}

std::vector<NFGameFish *> NFGameFishDesk::GetFishesByType(uint8_t nFishType)
{
    std::vector<NFGameFish *> vecFishes;
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, vecFishes, "");
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if (pGameFish->m_fishKind.m_btFishType == nFishType
            && pGameFish->IsAlive()
            && IsPointInScreen(pGameFish->GetMyPoint(pConfig)))
        {
            vecFishes.push_back(pGameFish);
        }
    }

    return vecFishes;
}

std::vector<NFGameFish *> NFGameFishDesk::GetAllFishes()
{
    std::vector<NFGameFish *> vecFishes;

    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        vecFishes.push_back(pGameFish);
    }

    return vecFishes;
}

uint32_t NFGameFishDesk::GetFishForRobotLock()
{
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, 0, "");
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if (pGameFish->m_nFishKind > 20 && pGameFish->IsAlive()
            && IsPointInCenterScreen(pGameFish->GetMyPoint(pConfig)))
        {
            return pGameFish->m_uFishId;
        }
    }

    return 0;
}

CHMPoint NFGameFishDesk::GetPointByIndex(unsigned int uTraceId, unsigned int uIndex)
{
    NFFishTraceConfig* pConfig = GetFishTraceConfig();
    CHECK_EXPR(pConfig, CHMPoint(), "");
    CHMPoint point = pConfig->GetPointByIndex(uTraceId, uIndex);
    return point;
}

FishKind NFGameFishDesk::GetFishKind(FishConfig *pFishConfig)
{
    CHECK_EXPR(pFishConfig, FishKind(), "pFishConfig == NULL");

    FishKind fishKind;

    fishKind.m_btFishType = pFishConfig->btFishType;
    fishKind.m_nBaseMul = pFishConfig->GetFishRatio();
    fishKind.m_nKilledMul = pFishConfig->nRatioDeath;
    fishKind.m_nDoubleAwardMinRatio = pFishConfig->nDoubleAwardMinRatio;

    std::vector<uint8_t> vecChildFishes;
    for (int i = 0; i < pFishConfig->nChildFishCount && i < (int) pFishConfig->vecVecChildFishes.size(); i++)
    {
        std::vector<uint8_t> vecChildFishSrc(pFishConfig->vecVecChildFishes[i].begin(), pFishConfig->vecVecChildFishes[i].end());

        int iFishKind = 1; //默认
        if (vecChildFishSrc.size() > 0)
        {
            iFishKind = pFishConfig->GetFishExclude(vecChildFishSrc, vecChildFishes);
        }

        vecChildFishes.push_back(iFishKind);
    }

    for (auto iter = vecChildFishes.begin(); iter != vecChildFishes.end(); iter++)
    {
        fishKind.vectSubFishes.push_back(*iter);
    }

    return fishKind;
}

void NFGameFishDesk::CheckFishOverTime()
{
    uint64_t uCurMSecond = NFTime::Now().UnixMSec();

    std::vector<int> vecDel;
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if (pGameFish->IsOverTime(uCurMSecond) || pGameFish->IsKilled())
        {
            if (pGameFish->IsOverTime(uCurMSecond))
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishMgr::CheckFishOverTime() fishId = {} is OverTime !", pGameFish->m_uFishId);
            }

            if (pGameFish->IsKilled())
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishMgr::CheckFishOverTime() fishId = {} is Killed !", pGameFish->m_uFishId);
            }

            vecDel.push_back(iter->first);
        }
    }

    for(int i = 0; i < (int)vecDel.size(); i++)
    {
        m_gameFishMap.erase(vecDel[i]);
    }
}

void NFGameFishDesk::SyncFishes(uint64_t playerId)
{
    gamefish::FishList fishList;

    int fishCount = 0;
    for (auto iter = m_gameFishMap.begin(); iter != m_gameFishMap.end(); iter++)
    {
        NFGameFish *pGameFish = &iter->second;
        if (pGameFish == NULL) continue;

        if (pGameFish->IsAlive() && pGameFish->m_uFishId!=INVALID_FISHID)
        {
            gamefish::FishInfo* pFishInfo = fishList.add_fishes();
            pFishInfo->set_usfishkind(pGameFish->m_nFishKind);
            pFishInfo->set_usfishid(pGameFish->m_uFishId);
            for (int j = 0; j < (int)pGameFish->m_fishKind.vectSubFishes.size(); j++)
            {
                pFishInfo->add_subfishkinds(pGameFish->m_fishKind.vectSubFishes[j]);

                if (pGameFish->m_fishKind.m_btFishType == NFGAME_FISHTYPE_HAIWANGCRAB)
                {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGAME_FISHTYPE_HAIWANGCRAB subFish = {} ", pGameFish->m_fishKind.vectSubFishes[j]);
                }
            }

            pFishInfo->set_ustraceid(pGameFish->m_uTraceId);
            pFishInfo->set_usstartindex(pGameFish->GetMyPointIndex());
            pFishInfo->set_usoffsetindex(pGameFish->m_nOffSetPointCount);
            pFishInfo->set_usoffsetposx(pGameFish->m_nOffsetPosX);
            pFishInfo->set_usoffsetpoxy(pGameFish->m_nOffsetPosY);
            pFishInfo->set_usbirthdelay(pGameFish->GetCurBirthDelay());
            pFishInfo->set_usisredfish(pGameFish->m_bIsRedFish ? 1 : 0);
            pFishInfo->set_usgroupid(-1);

            fishCount++;
        }
    }

    if (fishCount > 0)
    {
        SendMsgToClient(NF_FISH_CMD_FISHES_RSP, fishList, playerId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_tableId = {} , SyncFishes ===> fish count = {} ", m_deskId, fishCount);
}

void NFGameFishDesk::SendUserStatus(uint64_t playerId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    gamefish::UserStatusRsp userStatusRsp;

    std::list<NFGameFishPlayer*> listPlayers = GetOnlinePlayers();
    for (auto pPlayer : listPlayers)
    {
        gamefish::UserStatus* pUserInfo = userStatusRsp.add_userstatuslist();
        pUserInfo->set_chair_id(pPlayer->GetChairIdForClient());
        pUserInfo->set_lockfish_onoff(pPlayer->m_uLockOnOff==1);
        pUserInfo->set_lockfish_uid(pPlayer->m_uLockFishId);
        pUserInfo->set_autoshoot_onoff(pPlayer->m_uAutoShootOnOff==1);
        pUserInfo->set_bullet_speedlev(pPlayer->m_iBulletSpeedLev);
    }

    SendMsgToClient(proto_ff::NF_SC_MSG_UserStatusRsp, userStatusRsp, playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
}

uint32_t NFGameFishDesk::GetSceneChangeInfo(float &fTimeSeconds, int &iChangeType)
{
    NFFishGroupConfig* pFishGroupConfig = GetFishGroupConfig();
    NFFishPromptConfig* pFishPromptConfig = GetFishPromptConfig();
    CHECK_NULL(pFishGroupConfig);
    CHECK_NULL(pFishPromptConfig);

    //正式要通过配置
    fTimeSeconds = pFishPromptConfig->GetChangeSceneSeconds(iChangeType);

    if (iChangeType != eInfoType_FishOutScne)
    {
        if (m_uSceneIndex == -1)
        {
            m_uSceneIndex = 0;
        }
        else
        {
            do
            {
                m_uSceneIndex++;

                if (m_uSceneIndex >= (int32_t)m_uSceneCount)
                {
                    m_uSceneIndex = 0;
                }
            } while (pFishGroupConfig->IsSceneIndexExist(m_uSceneIndex));
        }
    }

    return m_uSceneIndex;
}

int NFGameFishDesk::FishGroupBaseTimer(uint32_t uTimerCount)
{
    NFFishWayBillConfig *pFishWayBillConfig = GetFishWayBillConfig();
    CHECK_NULL(pFishWayBillConfig);
    NFFishSettingConfig* pFishSettingConfig = GetFishSettingConfig();
    CHECK_NULL(pFishSettingConfig);

    if (m_iCurWayBillSts == eWayBillSts_NormalNext && m_bForceRegularWayBill)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishGroupBaseTimer ====> eWayBillSts_Regular ");

        m_bForceRegularWayBill = false;

        CFishWayBill* pWayBillExt = m_FishWayBillMgrExt.GetWayBill();
        if (pWayBillExt != NULL) //如果找不到规则鱼阵，就继续跑下去； 不能把m_pCurWayBill替换掉；
        {
            m_pCurWayBill = pWayBillExt;
            m_pCurWayBill->Reset(pFishWayBillConfig);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishGroupId RegularWayBill m_pCurWayBill ===> {}", m_pCurWayBill->GetFileName());

            m_bIsCurRegularWayBill = true;
            m_iCurWayBillSts = eWayBillSts_Play;
            m_iCurStatus = STATUS_NEXT;

            //Change Sence
            ClearFishes();

            //////////////////////////////////////////////////////////////////////////
            NFFishPromptConfig* pFishPromptConfig = GetFishPromptConfig();
            if (pFishPromptConfig && pFishPromptConfig->m_iYuChaoTipOn == 1)
            {
                SendPromptInfo(eInfoType_YuChao_Come, 0);
            }
        }
    }

    switch (m_iCurWayBillSts)
    {
        case eWayBillSts_NormalNext:
        {
            //////////////////////////////////////////////////////////////////////////
            m_pCurWayBill = m_FishWayBillMgr.GetWayBill();
            //==================

            int count = 0;
            bool bIsPrior = false;
            do
            {
                if (!m_bIsLastWayBillPrior)
                {
                    m_pCurWayBill = m_FishWayBillMgr.GetPirorWayBill(pFishSettingConfig);
                    if (m_pCurWayBill.GetPoint() != NULL)
                    {
                        bIsPrior = true;
                    }
                    else
                    {
                        m_pCurWayBill = m_FishWayBillMgr.GetWayBill();
                        bIsPrior = false;
                    }
                }
                else
                {
                    m_pCurWayBill = m_FishWayBillMgr.GetWayBill();
                    bIsPrior = false;
                }

                if (m_pCurWayBill.GetPoint() == NULL)
                {
                    break;
                }

            } while ((m_pCurWayBill.GetPoint() != NULL && m_pCurWayBill->GetFileName() == m_strLastWayBillName.GetString()) && (count++ < 10));

            if (m_pCurWayBill.GetPoint() == NULL)
            {
                m_pCurWayBill = m_FishWayBillMgr.GetWayBill();
                bIsPrior = false;
            }

            //////////////////////////////////////////////////////////////////////////
            if (m_pCurWayBill.GetPoint() != NULL)
            {
                m_strLastWayBillName  = m_pCurWayBill->GetFileName();
                m_bIsLastWayBillPrior = bIsPrior;

                if (m_bIsLastWayBillPrior)
                {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_bIsLastWayBillPrior ===> true {}", m_pCurWayBill->GetFileName());
                }
                else
                {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_bIsLastWayBillPrior ===> false {}", m_pCurWayBill->GetFileName());
                }

                int iItemCount = m_pCurWayBill->Reset(pFishWayBillConfig);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishGroupId NormalWayBill m_pCurWayBill ===> {} , iItemCount = {}", m_pCurWayBill->GetFileName(), iItemCount);

                m_bIsCurRegularWayBill = false;
                m_iCurWayBillSts = eWayBillSts_Play;
                m_iCurStatus = STATUS_NEXT;
            }
            else//找不到普通录单/没配置
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "FishGroupId !!! Not found Normal WayBill ! m_bForceRegularWayBill => true");

                m_bForceRegularWayBill = true;
            }

            break;
        }
        case eWayBillSts_Play:
        {
            bool bIsFinish = WayBillPlayPolling(uTimerCount, m_pCurWayBill, m_bIsCurRegularWayBill);
            if (bIsFinish)
            {
                if (!m_bIsCurRegularWayBill)
                {
                    m_bForceRegularWayBill = true;
                }

                m_iCurWayBillSts = eWayBillSts_NormalNext;
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "WayBillPlayPolling --> eWayBillSts_NormalNext");
            }
            break;
        }
        default:
            break;
    }
    return 0;
}

bool NFGameFishDesk::WayBillPlayPolling(uint32_t uTimerCount, CFishWayBill* pCurWayBill, bool bIsRegularWayBill /*= false*/)
{
    if (pCurWayBill == NULL)
    {
        return true;//finish
    }

    switch (m_iCurStatus)
    {
        case STATUS_NEXT:
        {
            while (true)//把连续的group一起发出去 //现在不要发了，默认一个timer时间间隔
            {
                FishWayBillItem item;
                int iLeftCount = pCurWayBill->GetOneItem(item);

                if (iLeftCount <= -1)
                {
                    if (bIsRegularWayBill)
                    {
                        m_iCurStatus = STATUS_WAIT_WAYBILL_FINISH;
                    }
                    else
                    {
                        return true;
                    }
                    break;
                }

                if (item.usType == E_FISH_WAY_BILL_ITEM_TYPE_YUZHEN)
                {
                    int iGroupId = item.usValue;
                    CFishGroup* pFishGroup = GetFishGroup(iGroupId);
                    CHECK_EXPR_CONTINUE(pFishGroup, "pFishGroup == NULL ! iGroupId = {}", iGroupId);

                    //////////////////////////////////////////////////////////////////////////
                    float fTimeSeconds = 1;
                    int  iChangeType = pFishGroup->m_bySceneType;
                    if (iChangeType > 0 && iChangeType < 10)
                    {
                        int32_t sceneId = pFishGroup->m_bySceneIndex;

                        if (sceneId == -1)
                        {
                            sceneId = GetSceneChangeInfo(fTimeSeconds, iChangeType);
                        }

                        m_uSceneIndex = sceneId;

                        SendChangScene(sceneId, fTimeSeconds, iChangeType);

                        if (iChangeType != eInfoType_ChangeSceneBG)
                        {
                            ClearFishes();
                        }

                        int iTime = fTimeSeconds * 1000;
                        m_ullNextTime = NFTime::Now().UnixMSec() + iTime;
                        m_iCurStatus = STATUS_TIMEDELAY_GROUP;

                        m_nGroupIdToSend = iGroupId;

                        break;
                    }

                    //if (pFishGroup->Type() == 1)//普通鱼群
                    {//所有Group都按普通鱼阵运行，现在是分普通录单或规则录单

                        SendFishGroup(iGroupId);
                        m_nCurGroupId = iGroupId;

                        //////////////////////////////////////////////////////////////////////////
                        FishWayBillItem item1;
                        bool ret = pCurWayBill->ForcastOneItem(item1);
                        if (ret)
                        {
                            if (item1.usType == E_FISH_WAY_BILL_ITEM_TYPE_YUZHEN)//如果没有延时，给个默认延时
                            {
                                m_ullNextTime = NFTime::Now().UnixMSec() + pCurWayBill->GetDefaultGroupDelay();

                                m_iCurStatus = STATUS_TIMEDELAY;
                                break;
                            }
                        }

                        break;
                        //////////////////////////////////////////////////////////////////////////
                    }
                }
                else//E_FISH_WAY_BILL_ITEM_TYPE_DELAY_TIME
                {
                    m_ullNextTime = NFTime::Now().UnixMSec() + item.usValue;
                    m_iCurStatus = STATUS_TIMEDELAY;

                    break;

                }
            }
        }
            break;

        case STATUS_WAIT_WAYBILL_FINISH:
        {
            int fishCount = GetFishCount();

            if (fishCount <= 0)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_iCurStatus == STATUS_WAIT_WAYBILL_FINISH ! fishCount <= 0");

                return true;//规则录单所有鱼都跑完才算录单跑完,返回0表示结束；
            }

            break;
        }
        case STATUS_TIMEDELAY:
            if (NFTime::Now().UnixMSec() > m_ullNextTime)
            {
                m_iCurStatus = STATUS_NEXT;
            }
            break;

        case STATUS_TIMEDELAY_GROUP:
            if (NFTime::Now().UnixMSec() > m_ullNextTime)
            {
                SendFishGroup(m_nGroupIdToSend);
                m_nCurGroupId = m_nGroupIdToSend;

                m_iCurStatus = STATUS_NEXT;
            }
            break;
        default:
            break;
    }

    return false;
}

int NFGameFishDesk::CreateGroupFishes(vector<NFGameFish> &vecGroupFishes, int iGroupId, uint8_t byDefaultFishKind, bool bIsWithRedFish, uint16_t nDstPosX, uint16_t nDstPoxY)
{
    NFFishGroupConfig* pFishGroupConfig = GetFishGroupConfig();
    CHECK_NULL(pFishGroupConfig);

    CFishGroup* pFishGroup = pFishGroupConfig->GetFishGroup(iGroupId);
    CHECK_EXPR(pFishGroup, -1, "pFishGroup == NULL ! iGroupId = {}", iGroupId);

    int16_t nOffsetPosX = 0;
    int16_t nOffsetPosY = 0;

    if ((nDstPosX > 0 && nDstPoxY > 0) && (pFishGroup->m_usCenterX > 0 && pFishGroup->m_usCenterY > 0))
    {
        nOffsetPosX = nDstPosX - pFishGroup->m_usCenterX;
        nOffsetPosY = nDstPoxY - pFishGroup->m_usCenterY;

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameFishPlayer::GetFishGroupMessage() nDstPosX = {} , nDstPoxY = {}", nDstPosX, nDstPoxY);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameFishPlayer::GetFishGroupMessage() pFishGroup->m_usCenterX = {} , pFishGroup->m_usCenterY = {}", pFishGroup->m_usCenterX, pFishGroup->m_usCenterY);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameFishPlayer::GetFishGroupMessage() nOffsetPosX = {} , nOffsetPosY = {}", nOffsetPosX, nOffsetPosY);
    }

    const FISH_LIST& pFishList = pFishGroup->GetFishList();

    int iRedFishRandIndex = NFRandInt((int)0, (int)pFishList.size());

    for (int i = 0; i < (int)pFishList.size(); i++)
    {
        const CFish* pFish = &pFishList[i];
        if (pFish != NULL)
        {
            vecGroupFishes.push_back(NFGameFish());
            NFGameFish& fish = vecGroupFishes.back();
            int ret = CreateFishEx(fish, *pFish, byDefaultFishKind, nOffsetPosX, nOffsetPosY, (bIsWithRedFish && (i == iRedFishRandIndex)));
            if (ret != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateFishEx Failed, byDefaultFishKind:{} nOffsetPosX:{} nOffsetPosY:{} bIsWithRedFish:{} iRedFishRandIndex:{}",
                           byDefaultFishKind, nOffsetPosX, nOffsetPosY, bIsWithRedFish, iRedFishRandIndex);
                vecGroupFishes.pop_back();
                continue;
            }
            fish.m_iGroupId = iGroupId;
        }
    }

    return vecGroupFishes.size();
}

gamefish::FishList NFGameFishDesk::GetGroupFishList(vector<NFGameFish> &vecGroupFishes)
{
    gamefish::FishList FishList;

    std::vector<NFGameFish>::iterator iter = vecGroupFishes.begin();
    for (; iter!=vecGroupFishes.end(); iter++)
    {
        gamefish::FishInfo* pFishInfo = FishList.add_fishes();
        pFishInfo->set_usfishkind(iter->m_nFishKind);
        pFishInfo->set_usfishid(iter->m_uFishId);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishDeskMgr::GetGroupFishList() m_iGroupId = {} m_nFishKind = {} , m_uFishId = {} , m_uTraceId = {}, m_uAliveTime = {}", iter->m_iGroupId, iter->m_nFishKind, iter->m_uFishId, iter->m_uTraceId, iter->m_uAliveTime);

        for (int i = 0; i < (int)iter->m_fishKind.vectSubFishes.size(); i++)
        {
            pFishInfo->add_subfishkinds(iter->m_fishKind.vectSubFishes[i]);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishDeskMgr::GetGroupFishList() vectSubFishes[{}] = {}", i, iter->m_fishKind.vectSubFishes[i]);

        }

        pFishInfo->set_ustraceid(iter->m_uTraceId);
        pFishInfo->set_usstartindex(iter->m_nStartPointIndex);
        pFishInfo->set_usoffsetindex(iter->m_nOffSetPointCount);
        pFishInfo->set_usoffsetposx(iter->m_nOffsetPosX);
        pFishInfo->set_usoffsetpoxy(iter->m_nOffsetPosY);

        pFishInfo->set_usbirthdelay(iter->m_uBirthDelayMS);
        pFishInfo->set_usisredfish(iter->m_bIsRedFish ? 1 : 0);
        pFishInfo->set_usgroupid(iter->m_iGroupId);
    }

    return FishList;
}

int NFGameFishDesk::SaveGroupFishes(const std::vector<NFGameFish> &vecGroupFishes)
{
    for (auto iter = vecGroupFishes.begin(); iter != vecGroupFishes.end(); iter++)
    {
        CHECK_EXPR(m_gameFishMap.size() < m_gameFishMap.max_size(), -1, "m_gameFishMap space not enough");
        auto ret_iter = m_gameFishMap.emplace_hint(iter->m_uFishId, *iter);
        if (ret_iter == m_gameFishMap.end())
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "game fish map insert failed!");
        }

        //if (m_gameFishMap.Find(iter->m_uFishId) == NULL)
        //{
        //	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_gameFishMap.Find(iter->m_uFishId) == NULL");
        //}
        //else
        //{
        //	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "m_gameFishMap.Find(iter->m_uFishId) == OK iter->m_uFishId = {}", iter->m_uFishId);
        //}
    }
    return 0;
}

CFishGroup *NFGameFishDesk::GetFishGroup(uint16_t nGroupId)
{
    NFFishGroupConfig* pConfig = GetFishGroupConfig();
    CHECK_EXPR(pConfig, NULL, "");
    return pConfig->GetFishGroup(nGroupId);
}

void NFGameFishDesk::SendFishGroup(int iGroupId, uint8_t byDefaultFishKind, bool bIsWithRedFish, uint16_t nDstPosX, uint16_t nDstPoxY)
{
    std::vector<NFGameFish> vecGroupFishes;
    int fishCount = CreateGroupFishes(vecGroupFishes, iGroupId, byDefaultFishKind, bIsWithRedFish, nDstPosX, nDstPoxY);

    if (fishCount > 0)
    {
        gamefish::FishList fishList = GetGroupFishList(vecGroupFishes);

        int count = fishList.fishes_size();
        if (count > 0)
        {
            SendMsgToAllClient(NF_FISH_CMD_FISHES_RSP, fishList);

            SaveGroupFishes(vecGroupFishes);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendFishGroup() iGroupId = {} , count = {}", iGroupId, count);
        }
    }

    //////////////////////////////////////////////////////////////////////////
    CFishGroup* pFishGroup = GetFishGroup(iGroupId);
    if (pFishGroup == NULL)
    {
        return;
    }

    int iPromptFishKind = GetPromptFishKind(pFishGroup);
    if (iPromptFishKind > 0)
    {
        SendPromptInfo(eInfoType_FishTip_Come, iPromptFishKind);
    }
    //////////////////////////////////////////////////////////////////////////
}

int NFGameFishDesk::GetPromptFishKind(CFishGroup *pFishGroup)
{
    CHECK_EXPR(pFishGroup, 0, "pFishGroup == NULL ! ");
    NFFishConfigConfig* pFishConfigConfig = GetFishConfigConfig();
    CHECK_NULL(pFishConfigConfig);

    const FISH_LIST& pFishList = pFishGroup->GetFishList();
    for (int i = 0; i < (int)pFishList.size(); i++)
    {
        const CFish* pFish = &pFishList[i];
        if (pFish != NULL)
        {
            FishConfig* pFishConfig = pFishConfigConfig->GetFishBaseInfo(pFish->m_usFishKind);
            CHECK_EXPR(pFishConfig, 0, "pFishConfig == NULL ! ");

            if (pFishConfig->nFishOutTipsID > 0)
            {
                return pFishConfig->btFishKindId;
            }
        }
    }

    return 0;
}

void NFGameFishDesk::SendPromptInfo(uint32_t uInfoType, uint32_t uFishKind)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendPromptInfo() ==> uInfoType = {} , uFishKind={}", uInfoType, uFishKind);

    gamefish::PromptInfoRsp promptInfoRsp;
    promptInfoRsp.set_infotype(uInfoType);
    promptInfoRsp.set_fishkindid(uFishKind);

    SendMsgToAllClient(NF_FISH_CMD_PROMPTINFO_RSP, promptInfoRsp);
}

void NFGameFishDesk::SendChangScene(uint32_t uSceneId, float fFishGowayTime, int iChangeType)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendChangScene() test Scene ======> uSceneId={} , fFishGowayTime={} , changeType = {}", uSceneId, fFishGowayTime, iChangeType);

    gamefish::ChangeSceneRsp changeSceneRsp;
    changeSceneRsp.set_scene_id(uSceneId);
    changeSceneRsp.set_time_seconds(fFishGowayTime);
    changeSceneRsp.set_scene_change_type(iChangeType);

    SendMsgToAllClient(NF_FISH_CMD_CHANGESCENE_RSP, changeSceneRsp);
}

bool NFGameFishDesk::IsFishCanBeKilledByKillType(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFFishSettingConfig* pFishSettingConfig = GetFishSettingConfig();
    CHECK_EXPR(pFishSettingConfig, false, "");

    return IsFishCanBeKilled(pPlayer, pFish, bullet);
}

bool NFGameFishDesk::GetTypeRandAlgoRate(int iCannonIndex, int nBaseMul, double &dbRate)
{
    if (nBaseMul <= 0)
    {
        return false;
    }

    int iValP = 100; //NFRandomInt(0, 100);

    if (iValP < 1)
    {
        iValP = 1;
    }

    //理论上多少次打死
    //M = nBaseMul/iValP
    double dbValM = nBaseMul * 1.0 / (iValP / 100.0);

    dbRate = 1.0 / dbValM;


    const int CONST_RATE_HIGH = 85;

    if ((dbRate * 100) > CONST_RATE_HIGH)
    {
        dbRate = CONST_RATE_HIGH * 1.0 / 100.0;
    }

    return true;
}

bool NFGameFishDesk::IsFishCanBeKilled(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFFishSettingConfig* pFishSettingConfig = GetFishSettingConfig();
    CHECK_EXPR(pFishSettingConfig, false, "");
    CHECK_EXPR(pPlayer, false, "pPlayer == NULL !");
    CHECK_EXPR(pFish, false, "pFish == NULL !");

    if (pFishSettingConfig->m_iOneCannonKilled == 1)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "m_iOneCannoKilled == 1 !!!");
        return true;
    }

    //获取子弹威力
    double dbBulletHarm = pPlayer->GetBulletHarmData();
    uint8_t byCannonLevelIndex = bullet.m_iBulletLevel;

    //判断是否是概率算法
    //打死的倍率，是要按照总倍率计算？比如要打死炸弹，需要把炸弹炸死的所有鱼的倍率一起算总和？
    //暂时只算打死的鱼本身的倍率，按理也应该这么算，如果要算总的，以后可以考虑优化；

    //int iKilledFishMul = pFish->m_fishKind.m_nBaseMul;
    //int iKilledFishMul = m_FishTypeMgr.GetKilledFishMul(pFish, bullet);
    int iKilledFishMul = m_FishTypeMgr->GetKilledDeathMul(pFish, bullet);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFGameFishDeskMgr::IsFishCanBeKilled() iKilledFishMul = {}", iKilledFishMul);

    if (iKilledFishMul <= 0)
    {
        return false;
    }

    double dbOutRate = 0;
    bool bRandAlgoRes = GetTypeRandAlgoRate(byCannonLevelIndex, iKilledFishMul, dbOutRate);
    if (bRandAlgoRes)
    {
        const int ST_DATA_BILI = 10000;
        int iRateKilled = int(ST_DATA_BILI * dbOutRate * dbBulletHarm);
        int iRandTemp = NFRandomInt(0, ST_DATA_BILI);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "IsFishCanKilled_NewLogic ==> m_nBaseMul = {} , dbBulletHarm = {} , dbOutRate = {} , iRateKilled = {} , iRandTemp = {}", iKilledFishMul, dbBulletHarm, dbOutRate, iRateKilled, iRandTemp);

        if (iRandTemp < iRateKilled)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "IsFishCanKilled_NewLogic ==> true !!!");

            return true;
        }
    }

    return false;
}
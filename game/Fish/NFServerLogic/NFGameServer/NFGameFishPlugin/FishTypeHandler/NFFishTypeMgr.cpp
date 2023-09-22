// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMgr
//
// -------------------------------------------------------------------------

#include "NFFishTypeMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Player/NFGameFishPlayer.h"
#include "Fish/NFFishBulletMgr.h"
#include "CSFish.pb.h"
#include "NFGameFishDefine.h"
#include "NFFishTypeHandler.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Config/NFFishSettingConfig.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeMgr, EOT_NFFishTypeMgr_ID, NFShmObj)

NFFishTypeMgr::NFFishTypeMgr()
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

NFFishTypeMgr::~NFFishTypeMgr()
{
    ClearFishTypes();
    m_mapTimer_Player.clear();
}

int NFFishTypeMgr::CreateInit()
{
    m_bIsFreeze = false;
    return 0;
}

int NFFishTypeMgr::ResumeInit()
{
    return 0;
}

void NFFishTypeMgr::Init(NFGameFishDesk* pDeskHandler)
{
    ClearFishTypes();

    m_pDesk = pDeskHandler;

    AddFishTypeHandler(NFGAME_FISHTYPE_NORMAL);
    AddFishTypeHandler(NFGAME_FISHTYPE_FULLSCREENBOMB);
    AddFishTypeHandler(NFGAME_FISHTYPE_KINDBOMB);
    AddFishTypeHandler(NFGAME_FISHTYPE_LIGHTLINK);
    AddFishTypeHandler(NFGAME_FISHTYPE_FREEZE);
    //AddFishTypeHandler(NFGAME_FISHTYPE_DANAOTIANGONG);
    AddFishTypeHandler(NFGAME_FISHTYPE_DIANCICANNON);
    AddFishTypeHandler(NFGAME_FISHTYPE_ZUANTOU);
    //AddFishTypeHandler(NFGAME_FISHTYPE_SOMEZUANTOU);
    AddFishTypeHandler(NFGAME_FISHTYPE_FIRESTORM);
    AddFishTypeHandler(NFGAME_FISHTYPE_MADCOW);
    AddFishTypeHandler(NFGAME_FISHTYPE_SERIALBOMBCRAB);
    AddFishTypeHandler(NFGAME_FISHTYPE_HAIWANGCRAB);
    AddFishTypeHandler(NFGAME_FISHTYPE_LIGHTNINGJELLYFISH);
    AddFishTypeHandler(NFGAME_FISHTYPE_DELAYBOMB);
}

int NFFishTypeMgr::OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeMgr::OnHandleClientMsg() ===============> nMsgId = {}", packet.nMsgId);

    for (auto iter = m_mapFishTypeHandler.begin(); iter != m_mapFishTypeHandler.end(); iter++)
    {
        int globalId = iter->second;
        NFFishTypeHandler* pFishTypeHandler = (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);

        if (pFishTypeHandler != NULL)
        {
            int ret = pFishTypeHandler->OnHandleClientMessage(pPlayer, packet);
            if (ret == 1)
            {
                return 1;
            }
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeMgr::OnHandleClientMsg() ===============> return 0 !");

    return 0;
}

int NFFishTypeMgr::GetKilledFishMul(NFGameFish* pFish, const NFFishBullet& bullet)
{
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    NFFishTypeHandler* pHandler = FindFishTypeHandler(pFish->m_fishKind.m_btFishType);
    CHECK_EXPR(pHandler, -1, "pHandler == NULL !");

    return pHandler->GetKilledFishMul(pFish, bullet);
}

int NFFishTypeMgr::GetKilledDeathMul(NFGameFish* pFish, const NFFishBullet& bullet)
{
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    NFFishTypeHandler* pHandler = FindFishTypeHandler(pFish->m_fishKind.m_btFishType);
    CHECK_EXPR(pHandler, -1, "pHandler == NULL !");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeMgr::GetKilledDeathMul() !");

    return pHandler->GetKilledDeathMul(pFish, bullet);
}

uint64_t NFFishTypeMgr::KillFishByType(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet)
{
    NFFishTypeHandler* pHandler = FindFishTypeHandler(pFish->m_fishKind.m_btFishType);
    if (pHandler != NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Find pHandler for m_btFishType: {} , fishKind = {}", pFish->m_fishKind.m_btFishType, pFish->m_nFishKind);

        pHandler->OnKilllingFish(pPlayer, pFish, bullet);
        uint64_t ullScoreMoney = pHandler->KillFish(pPlayer, pFish, bullet);
        pHandler->OnKilledFish(pPlayer, pFish, bullet);

        OnKilledFish_AllType(pPlayer, pFish);

        return ullScoreMoney;
    }
    else
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "Can't find fishTypeHandler for m_btFishType: {}", pFish->m_fishKind.m_btFishType);
        return 0;
    }
}

int NFFishTypeMgr::OnKilledFish_AllType(NFGameFishPlayer* pPlayer, NFGameFish* pFish)
{
    DoubleCannonHandler(pPlayer, pFish);

    return 0;
}

int NFFishTypeMgr::OnAddScore(NFGameFishPlayer* pPlayer, NFGameFish* pFish, uint64_t ullScoreMoney)
{
    for (auto iter = m_mapFishTypeHandler.begin(); iter != m_mapFishTypeHandler.end(); iter++)
    {
        int globalId = iter->second;
        NFFishTypeHandler* pFishTypeHandler = (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);

        if (pFishTypeHandler != NULL)
        {
            pFishTypeHandler->OnAddScore(pPlayer, pFish, ullScoreMoney);
        }
    }

    return 0;
}

int NFFishTypeMgr::DoubleCannonHandler(NFGameFishPlayer* pPlayer, NFGameFish* pFish)
{
    auto pFishSettingConfig = NFFishSettingConfig::GetObjByHashKey(m_pObjPluginManager, m_pDesk->GetRoomId());
    CHECK_NULL(pFishSettingConfig);
    if (pFishSettingConfig->m_iDoubleCannonEnable == 0)
    {
        return 0;
    }

    if (!(pFish->m_fishKind.IsCanTriggerDoubleCannon()))
    {
        return 0;
    }

    if (pPlayer->GetDoubeGunValueOn() == 1)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayer->GetDoubeGunValueOn() == 1 return !");
        return 0;
    }

    int iRandValue = NFRandInt(0, 100);
    if (iRandValue > pFishSettingConfig->m_iDoubleCannonRatio)
    {
        return 0;
    }

    pPlayer->SetDoubleGunValueOn(1);

    gamefish::SC_DoubleGunOnOff doubleGunOnOff;
    doubleGunOnOff.set_chairid(pPlayer->GetChairIdForClient());
    doubleGunOnOff.set_onoff(pPlayer->GetDoubeGunValueOn());

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_DOUBLEGUNONOFF_RSP, doubleGunOnOff);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDoubleCannon::OnKilledFish() chairid = {} , onoff = {}", pPlayer->GetChairIdForClient(), pPlayer->GetDoubeGunValueOn());

    int iTimerId = SetTimer(15000, 1, 0, 0, 0, 15000);
    auto iter = m_mapTimer_Player.emplace_hint(iTimerId,pPlayer->GetPlayerID());
    CHECK_EXPR(iter != m_mapTimer_Player.end(), -1, "m_mapTimer_Player.Insert(iTimerId:{},pPlayer->GetPlayerID():{}) Failed", iTimerId, pPlayer->GetPlayerID());
    return 0;
}

void NFFishTypeMgr::SyncFishBomb(NFGameFishPlayer* pPlayer)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeMgr::SyncFishBombs() ==================> ");

    for(auto iter = m_mapFishTypeHandler.begin(); iter != m_mapFishTypeHandler.end(); iter++)
    {
        int globalId = iter->second;
        NFFishTypeHandler* pFishTypeHandler = (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);
        if (pFishTypeHandler != NULL)
        {
            pFishTypeHandler->SyncFishBomb(pPlayer);
        }
    }
}

void NFFishTypeMgr::UserLeftDesk(NFGameFishPlayer* pPlayer)
{
    for(auto iter = m_mapFishTypeHandler.begin(); iter != m_mapFishTypeHandler.end(); iter++)
    {
        int globalId = iter->second;
        NFFishTypeHandler* pFishTypeHandler = (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);
        if (pFishTypeHandler != NULL)
        {
            pFishTypeHandler->UserLeftDesk(pPlayer);
        }
    }
}

NFFishTypeHandler* NFFishTypeMgr::AddFishTypeHandler(int iFishType)
{
    NFFishTypeHandler* pHandler = FindFishTypeHandler(iFishType);
    if (pHandler == NULL)
    {
        CHECK_EXPR(!m_mapFishTypeHandler.full(), NULL, "m_mapFishTypeHandler spcae not enough");

        pHandler = CreateFishTypeHandle(iFishType);
        CHECK_EXPR(pHandler, NULL, "CreateFishTypeHandle Failed, iFishType", iFishType);
        pHandler->Init(m_pDesk.GetPoint());
        m_mapFishTypeHandler.emplace(iFishType, pHandler->GetGlobalId());
        pHandler = FindFishTypeHandler(iFishType);
        CHECK_EXPR(pHandler, NULL, "FindFishTypeHandler Failed, iFishType", iFishType);
    }
    return pHandler;
}

NFFishTypeHandler* NFFishTypeMgr::CreateFishTypeHandle(int iFishType)
{
    return (NFFishTypeHandler*) FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_ID);

    switch (iFishType)
    {
        case NFGAME_FISHTYPE_NORMAL:
        {
            return (NFFishTypeHandler*) FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_ID);
        }
        case NFGAME_FISHTYPE_FULLSCREENBOMB:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_FULLSCRBOMB_ID);
        }
        case NFGAME_FISHTYPE_KINDBOMB:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_KINDBOMB_ID);
        }
        case NFGAME_FISHTYPE_LIGHTLINK:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_LIGHTLINK_ID);
        }
        case NFGAME_FISHTYPE_FREEZE:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_FREEZE_ID);
        }
            break;
            //case NFGAME_FISHTYPE_DANAOTIANGONG:
            //{
            //	return (NFFishTypeHandler*)NFShmMgr::Instance()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_DNTG_ID);
            //}
            //break;
        case NFGAME_FISHTYPE_DIANCICANNON:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_DIANCICANNON_ID);
        }
        case NFGAME_FISHTYPE_ZUANTOU:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_ZUANTOU_ID);
        }
        case NFGAME_FISHTYPE_SOMEZUANTOU:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_SOME_ZUANTOU_ID);
        }
        case NFGAME_FISHTYPE_FIRESTORM:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_FIRESTORM_ID);
        }
        case NFGAME_FISHTYPE_MADCOW:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_MADCOW_ID);
        }
        case NFGAME_FISHTYPE_SERIALBOMBCRAB:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_SERIALBOMBCRAB_ID);
        }
        case NFGAME_FISHTYPE_HAIWANGCRAB:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_HAIWANGCRAB_ID);
        }
        case NFGAME_FISHTYPE_LIGHTNINGJELLYFISH:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_LIGHTNINGJELLYFISH_ID);
        }
        case NFGAME_FISHTYPE_DELAYBOMB:
        {
            return (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->CreateObj(EOT_GAME_FISH_TYPE_HANDLE_DELAYBOMB_ID);
        }
        default:
            return NULL;
    }
    return NULL;
}

NFFishTypeHandler* NFFishTypeMgr::FindFishTypeHandler(int iFishType)
{
    auto iter = m_mapFishTypeHandler.find(iFishType);
    if (iter != m_mapFishTypeHandler.end())
    {
        int globalId = iter->second;
        return (NFFishTypeHandler*) FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);
    }
    return NULL;
}

void NFFishTypeMgr::ClearFishTypes()
{
    for(auto iter = m_mapFishTypeHandler.begin(); iter != m_mapFishTypeHandler.end(); iter++)
    {
        int globalId = iter->second;
        NFFishTypeHandler* pHandler = (NFFishTypeHandler*)FindModule<NFISharedMemModule>()->GetObjByGlobalId(globalId, EOT_GAME_FISH_TYPE_HANDLE_ID, true);
        CHECK_EXPR(pHandler, , "ClearFishTypes error");
        FindModule<NFISharedMemModule>()->DestroyObj(pHandler);
    }

    m_mapFishTypeHandler.clear();
}

int NFFishTypeMgr::OnTimer(int timeId, int callcount)
{
    OnTimerAllType(timeId);
    return 0;
}


void NFFishTypeMgr::OnTimerAllType(int iTimerId)
{
    auto iter = m_mapTimer_Player.find(iTimerId);
    if (iter != m_mapTimer_Player.end())
    {
        DeleteTimer(iTimerId);
        uint64_t playerId = iter->second;
        m_mapTimer_Player.erase(iTimerId);
        NFGameFishPlayer* pPlayer = m_pDesk->GetPlayer(playerId);
        CHECK_EXPR(pPlayer, , "GetPlayer Failed, playerId:{}", playerId);


        pPlayer->SetDoubleGunValueOn(0);

        gamefish::SC_DoubleGunOnOff doubleGunOnOff;
        doubleGunOnOff.set_chairid(pPlayer->GetChairIdForClient());
        doubleGunOnOff.set_onoff(pPlayer->GetDoubeGunValueOn());

        m_pDesk->SendMsgToAllClient(NF_FISH_CMD_DOUBLEGUNONOFF_RSP, doubleGunOnOff);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDoubleCannon::OnTimer() chairid = {} , onoff = {}", pPlayer->GetChairIdForClient(), pPlayer->GetDoubeGunValueOn());
    }
}

bool NFFishTypeMgr::IsFreeze()
{
    return m_bIsFreeze;
}

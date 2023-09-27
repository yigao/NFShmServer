// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFullScrBomb.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFullScrBomb
//
// -------------------------------------------------------------------------

#include "NFFishTypeFullScrBomb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Player/NFGameFishPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeFullScrBomb, EOT_GAME_FISH_TYPE_HANDLE_FULLSCRBOMB_ID, NFFishTypeHandler)

NFFishTypeFullScrBomb::NFFishTypeFullScrBomb()
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

NFFishTypeFullScrBomb::~NFFishTypeFullScrBomb()
{
}

int NFFishTypeFullScrBomb::CreateInit()
{
    return 0;
}

int NFFishTypeFullScrBomb::ResumeInit()
{
    return 0;
}

int NFFishTypeFullScrBomb::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeFullScrBomb::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();

    int32_t iMainMul    = GetKilledFishMul(pFish, bullet);
    int32_t iMainScore  = bullet.GetBulletMoney() * iMainMul;
    int32_t iTotalScore = 0;

    if (iTotalScore + iMainScore > iMaxWinMoney)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! iTotalScore + iMainScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iMainScore, iMaxWinMoney);
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////

    pFish->Kill();
    iTotalScore += iMainScore;

    gamefish::KillFishRsp gcKillFish;
    gcKillFish.set_bulletid(bullet.m_uBulletId);
    gcKillFish.set_bombuid(0);
    gcKillFish.set_mainfishuid(pFish->m_uFishId);
    gcKillFish.set_mainfishid(pFish->m_nFishKind);
    gcKillFish.set_mainfishtype(pFish->m_fishKind.m_btFishType);
    gcKillFish.set_mainmultiple(iMainMul);
    gcKillFish.set_mainscore(iMainScore);//bomb is no scored
    //gcKillFish.set_totalscore(0);//will set below
    //gcKillFish.set_totalratio(0);//will set below
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);
    gcKillFish.set_subfishcount(0);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);


    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFCGameFishModule::OnHandleFishHitFish() ==> set_subfishcount = {}", vecSubFishes.size());

    int iSubFishCount = 0;
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        NFGameFish* pSubFish = *iter;
        if (pSubFish==NULL || pSubFish->IsKilled())
        {
            continue;
        }

        uint32_t iMul   = pSubFish->GetBaseMul() * bullet.GetBulletMul();
        uint32_t iScore = bullet.GetBulletMoney() * iMul;

        if (iTotalScore + (int32_t)iScore > iMaxWinMoney)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! iTotalScore + iScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iScore, iMaxWinMoney);
            break;
        }

        //////////////////////////////////////////////////////////////////////////

        pSubFish->Kill();
        iTotalScore += iScore;

        iSubFishCount++;

        gamefish::KillFishRsp* pKillFish = gcKillFish.add_subfishes();
        pKillFish->set_bombuid(pFish->m_uFishId);
        pKillFish->set_mainfishuid(pSubFish->m_uFishId);
        pKillFish->set_mainfishid(pSubFish->m_nFishKind);
        pKillFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
        pKillFish->set_mainmultiple(iMul);
        pKillFish->set_mainscore(iScore);
        pKillFish->set_chairid(pPlayer->GetChairIdForClient());
        pKillFish->set_userrorcode(0);
        pKillFish->set_bombfishid(pFish->m_nFishKind);

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFCGameFishModule::OnHandleFishHitFish() ==> gcKillSubFish => m_uFishId = {}", (*iter)->m_uFishId);
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "==> iTotalScore = {}", iTotalScore);

    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore/bullet.GetBulletMoney());
    gcKillFish.set_subfishcount(iSubFishCount);

    //SendMsgToClientByPlayerId(playerId, NF_FISH_CMD_KILLFISH, gcKillFish);
    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    return iTotalScore;
}

int NFFishTypeFullScrBomb::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeFullScrBomb::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeFullScrBomb::GetKilledFishMul() ====================> ");
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    int iKilledFishMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        iKilledFishMul += (*iter)->GetBaseMul() * bullet.GetBulletMul();
    }

    return iKilledFishMul;
}

int NFFishTypeFullScrBomb::GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeFullScrBomb::GetKilledDeathMul() ====================> ");
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    int iKilledFishMul = NFFishTypeHandler::GetKilledDeathMul(pFish, bullet);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        iKilledFishMul += (*iter)->GetKilledDeathMul() * bullet.GetBulletMul();
    }

    return iKilledFishMul;
}

std::vector<NFGameFish *> NFFishTypeFullScrBomb::GetKilledSubFishes(NFGameFish *pMainFish)
{
    auto pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_EXPR(pTraceConfig, std::vector<NFGameFish *>(), "");
    return m_pDesk->GetFishes(INVALID_FISHKIND, pMainFish->GetMyPoint(pTraceConfig), pMainFish->m_iDemageRadius);
}

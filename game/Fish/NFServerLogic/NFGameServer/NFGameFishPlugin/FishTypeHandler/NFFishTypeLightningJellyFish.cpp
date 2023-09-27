// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightningJellyFish.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightningJellyFish
//
// -------------------------------------------------------------------------

#include "NFFishTypeLightningJellyFish.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Player/NFGameFishPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeLightningJellyFish, EOT_GAME_FISH_TYPE_HANDLE_LIGHTNINGJELLYFISH_ID, NFFishTypeHandler)

NFFishTypeLightningJellyFish::NFFishTypeLightningJellyFish()
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

NFFishTypeLightningJellyFish::~NFFishTypeLightningJellyFish()
{
}

int NFFishTypeLightningJellyFish::CreateInit()
{
    return 0;
}

int NFFishTypeLightningJellyFish::ResumeInit()
{
    return 0;
}

int NFFishTypeLightningJellyFish::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeLightningJellyFish::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeLightningJellyFish::KillFish() NF_LOG_SYSTEMLOG pFish->m_uFishId = {}", pFish->m_uFishId);

    NFFishConfigConfig *pFishConfigDesc = m_pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfigDesc);

    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();

    int32_t iMainMul    = pFish->GetBaseMul() * bullet.GetBulletMul();
    int32_t iMainScore  = bullet.GetBulletMoney() * iMainMul;
    int32_t iTotalScore = 0;

    if (iTotalScore + iMainScore > iMaxWinMoney)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>JellyFish ! iTotalScore + iMainScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iMainScore, iMaxWinMoney);
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
    gcKillFish.set_mainscore(iMainScore);
    //gcKillFish.set_totalscore(0);//will set below
    //gcKillFish.set_totalratio(0);//will set below
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    std::vector<NFGameFish*> vecFishes = GetKilledSubFishes(pFish);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> vecFishes.size() = {}", vecFishes.size());

    int iSubFishCount = 0;
    std::vector<NFGameFish*>::iterator iterFish = vecFishes.begin();
    for (; iterFish != vecFishes.end(); iterFish++)
    {
        NFGameFish* pSubFish = *iterFish;
        if ((pSubFish != NULL)
            && (pSubFish->m_uFishId!= pFish->m_uFishId)
            && (pSubFish->IsKilled() == false)
            && (pSubFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 : �Ȳ�Ū��������
        {
            uint32_t iMul   = pSubFish->GetBaseMul() * bullet.GetBulletMul();
            uint32_t iScore = bullet.GetBulletMoney() * iMul;
            uint32_t iMyMaxWinMoney = GetFishMaxWinMoney(*pFish, bullet.GetBulletMul(), bullet.GetBulletMoney());

            if (iTotalScore + (int32_t)iScore > iMaxWinMoney
                || iTotalScore + iScore > iMyMaxWinMoney
                || (!pFish->IsCanKill(pFishConfigDesc, pSubFish->m_nFishKind)))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>JellyFish ! iTotalScore + iScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iScore, iMaxWinMoney);
                break;
            }
            //////////////////////////////////////////////////////////////////////////

            pSubFish->Kill();
            iTotalScore += iScore;

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> iTotalScore = {} (+{}) < {}(iMyMaxWinMoney)", iTotalScore, iScore, iMyMaxWinMoney);

            gamefish::KillFishRsp* pKillSubFish = gcKillFish.add_subfishes();
            pKillSubFish->set_bombuid(pFish->m_uFishId);
            pKillSubFish->set_mainfishuid(pSubFish->m_uFishId);
            pKillSubFish->set_mainfishid(pSubFish->m_nFishKind);
            pKillSubFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
            pKillSubFish->set_mainmultiple(iMul);
            pKillSubFish->set_mainscore(iScore);
            pKillSubFish->set_chairid(pPlayer->GetChairIdForClient());
            pKillSubFish->set_userrorcode(0);
            pKillSubFish->set_bombfishid(pFish->m_nFishKind);

            iSubFishCount++;
        }
    }

    gcKillFish.set_subfishcount(iSubFishCount);
    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / bullet.GetBulletMoney());

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeLightningJellyFish::KillFish() NF_LOG_SYSTEMLOG iSubFishCount = {}", iSubFishCount);

    return iTotalScore;
}

int NFFishTypeLightningJellyFish::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeLightningJellyFish::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    int iKilledFishMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        iKilledFishMul += (*iter)->GetBaseMul() * bullet.GetBulletMul();
    }

    return iKilledFishMul;
}

int NFFishTypeLightningJellyFish::GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    int iKilledFishMul = NFFishTypeHandler::GetKilledDeathMul(pFish, bullet);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        iKilledFishMul += (*iter)->GetKilledDeathMul() * bullet.GetBulletMul();
    }

    return iKilledFishMul;
}

std::vector<NFGameFish *> NFFishTypeLightningJellyFish::GetKilledSubFishes(NFGameFish *pMainFish)
{
    NFFishTraceConfig* pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_EXPR(pTraceConfig, std::vector<NFGameFish *>(), "");
    return m_pDesk->GetFishes(pMainFish->GetMyPoint(pTraceConfig), pMainFish->m_iDemageRadius, 30);
}

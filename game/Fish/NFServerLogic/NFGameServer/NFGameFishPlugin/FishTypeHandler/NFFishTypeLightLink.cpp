// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightLink.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightLink
//
// -------------------------------------------------------------------------

#include "NFFishTypeLightLink.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Player/NFGameFishPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeLightLink, EOT_GAME_FISH_TYPE_HANDLE_LIGHTLINK_ID, NFFishTypeHandler)

NFFishTypeLightLink::NFFishTypeLightLink()
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

NFFishTypeLightLink::~NFFishTypeLightLink()
{
}

int NFFishTypeLightLink::CreateInit()
{
    return 0;
}

int NFFishTypeLightLink::ResumeInit()
{
    return 0;
}

int NFFishTypeLightLink::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeLightLink::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");
    CHECK_EXPR(pFish, 0, "pFish == NULL !");

    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();
    auto pFishConfigDesc = m_pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfigDesc);

    int32_t iMainMul   = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int32_t iMainScore = bullet.GetBulletMoney() * iMainMul;
    int32_t iTotalScore = 0;

    if (iTotalScore + iMainScore > iMaxWinMoney)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>LightLink ! iTotalScore + iMainScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iMainScore, iMaxWinMoney);
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
    gcKillFish.set_mainmultiple(pFish->m_fishKind.m_nBaseMul);
    gcKillFish.set_mainscore(iMainScore);//bomb is no scored
    //gcKillFish.set_totalscore(iMainScore);
    //gcKillFish.set_totalratio(iMainMul);
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);
    gcKillFish.set_subfishcount(0);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);


    int iKilledSubFishCount = 0;

    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        if ((*iter)->m_fishKind.vectSubFishes.size() <= 0)
        {
            continue;
        }

        FishConfig* pFishConfig = pFishConfigDesc->GetFishBaseInfo((*iter)->m_fishKind.vectSubFishes[0]);
        if (pFishConfig == NULL)
        {
            continue;
        }

        //uint32_t iMul = (*iter)->GetBaseMul() * bullet.GetBulletMul(); //本鱼的倍率
        uint32_t iMul = pFishConfig->nRatioMin * bullet.GetBulletMul();//子鱼的倍率
        uint32_t iScore = bullet.GetBulletMoney() * iMul;

        if (iTotalScore + (int32_t)iScore > iMaxWinMoney)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>KindBomb ! iTotalScore + iScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iScore, iMaxWinMoney);
            break;
        }
        //////////////////////////////////////////////////////////////////////////

        (*iter)->Kill();
        iTotalScore += iScore;

        iKilledSubFishCount++;

        gamefish::KillFishRsp* pSubFish = gcKillFish.add_subfishes();

        pSubFish->set_bombuid(pFish->m_uFishId);
        pSubFish->set_mainfishuid((*iter)->m_uFishId);
        pSubFish->set_mainfishid((*iter)->m_nFishKind);
        pSubFish->set_mainfishtype((*iter)->m_fishKind.m_btFishType);
        pSubFish->set_mainmultiple(iMul);
        pSubFish->set_mainscore(iScore);
        pSubFish->set_chairid(pPlayer->GetChairIdForClient());
        pSubFish->set_userrorcode(0);
        pSubFish->set_bombfishid(pFish->m_nFishKind);

        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeLightLink::KillFish() ==> gcKillSubFish => m_uFishId = {} , iTotalScore = {} , iScore = {}", (*iter)->m_uFishId, iTotalScore, iScore);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeLightLink::KillFish() ==> iTotalScore = {}", iTotalScore);

    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / bullet.GetBulletMoney());
    gcKillFish.set_subfishcount(iKilledSubFishCount);

    //SendMsgToClientByPlayerId(playerId, NF_FISH_CMD_KILLFISH, gcKillFish);
    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    return iTotalScore;
}

int NFFishTypeLightLink::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeLightLink::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
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

int NFFishTypeLightLink::GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet)
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

std::vector<NFGameFish *> NFFishTypeLightLink::GetKilledSubFishes(NFGameFish *mainFish)
{
    return m_pDesk->GetFishesByKind(mainFish->m_nFishKind);
}

// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeKindBomb.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeKindBomb
//
// -------------------------------------------------------------------------

#include "NFFishTypeKindBomb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Player/NFGameFishPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeKindBomb, EOT_GAME_FISH_TYPE_HANDLE_KINDBOMB_ID, NFFishTypeHandler)

NFFishTypeKindBomb::NFFishTypeKindBomb()
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

NFFishTypeKindBomb::~NFFishTypeKindBomb()
{
}

int NFFishTypeKindBomb::CreateInit()
{
    return 0;
}

int NFFishTypeKindBomb::ResumeInit()
{
    return 0;
}

int NFFishTypeKindBomb::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeKindBomb::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");
    CHECK_EXPR(pFish, 0, "pFish == NULL !");

    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();

    int32_t iMainMul    = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int32_t iMainScore  = bullet.GetBulletMoney() * iMainMul;
    int32_t iTotalScore = 0;

    if (iTotalScore + iMainScore > iMaxWinMoney)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>KindBomb ! iTotalScore + iMainScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iMainScore, iMaxWinMoney);
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
    gcKillFish.set_totalscore(0);//will set value below
    gcKillFish.set_totalratio(0);//will set value below
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    gcKillFish.set_subfishcount(vecSubFishes.size());

    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        uint32_t iMul = (*iter)->GetBaseMul() * bullet.GetBulletMul();
        uint32_t iScore = bullet.GetBulletMoney() * iMul;

        if (iTotalScore + (int32_t)iScore > iMaxWinMoney
            //|| iTotalScore + (int32_t)iScore > GetFishMaxWinMoney(*pFish, bullet.GetBulletMul(), bullet.GetBulletMoney())
            /*|| (!pFish->IsCanKill((*iter)->m_nFishKind))*/)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>KindBomb ! iTotalScore + iScore > iMaxWinMoney ! {} + {} > {} !", iTotalScore, iScore, iMaxWinMoney);
            break;
        }
        //////////////////////////////////////////////////////////////////////////

        (*iter)->Kill();
        iTotalScore += iScore;

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
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "==> iTotalScore = {}", iTotalScore);

    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / bullet.GetBulletMoney());

    //SendMsgToClientByPlayerId(playerId, NF_FISH_CMD_KILLFISH, gcKillFish);
    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    return iTotalScore;
}

int NFFishTypeKindBomb::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeKindBomb::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeKindBomb::GetKilledFishMul() ====================> ");
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

int NFFishTypeKindBomb::GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeKindBomb::GetKilledDeathMul() ====================> ");
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

std::vector<NFGameFish *> NFFishTypeKindBomb::GetKilledSubFishes(NFGameFish *mainFish)
{
    std::vector<uint8_t> vecFishKinds;
    for (int i = 0; i < (int)mainFish->m_fishKind.vectSubFishes.size(); i++)
    {
        vecFishKinds.push_back(mainFish->m_fishKind.vectSubFishes[i]);
    }

    return m_pDesk->GetFishesByKinds(vecFishKinds);
}

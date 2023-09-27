// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHandler.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHandler
//
// -------------------------------------------------------------------------

#include "NFFishTypeHandler.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Fish/NFFishBulletMgr.h"
#include "Player/NFGameFishPlayer.h"
#include "CSFish.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeHandler, EOT_GAME_FISH_TYPE_HANDLE_ID, NFShmObj)

NFFishTypeHandler::NFFishTypeHandler()
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

NFFishTypeHandler::~NFFishTypeHandler()
{
}

int NFFishTypeHandler::CreateInit()
{
    return 0;
}

int NFFishTypeHandler::ResumeInit()
{
    return 0;
}

int NFFishTypeHandler::Init(NFGameFishDesk* pDesk)
{
    CHECK_NULL(pDesk);
    m_pDesk = pDesk;
    return 0;
}

int NFFishTypeHandler::OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet)
{
    return 1;
}

int NFFishTypeHandler::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeHandler::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pFish, 0, "pFish == NULL !");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "KillFish()========>Normal ! fishId = {}", pFish->m_uFishId);

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
    gcKillFish.set_mainscore(iMainScore);
    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore/bullet.GetBulletMoney());
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    gcKillFish.set_subfishcount(0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> iTotalScore = {} , iMainMul = {} , bulletMul = {}", iMainScore, iMainMul, bullet.GetBulletMul());

    //SendMsgToClientByPlayerId(playerId, NF_FISH_CMD_KILLFISH, gcKillFish);
    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    return iMainScore;
}

int NFFishTypeHandler::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeHandler::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    return pFish->GetBaseMul() * bullet.GetBulletMul();
}

int NFFishTypeHandler::GetKilledDeathMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pFish, -1, "pFish == NULL !");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeHandler::GetKilledDeathMul() !");

    int iMyKilledMul = pFish->GetKilledDeathMul();

    return iMyKilledMul * bullet.GetBulletMul();
}

uint32_t NFFishTypeHandler::GetFishMaxWinMoney(NFGameFish fish, uint32_t bulletMul, uint32_t bulletMoney)
{
    int iMyKilledMul = fish.GetKilledDeathMul();

    if (iMyKilledMul == 0)
    {
        return 999999999;
    }
    else
    {
        return iMyKilledMul * bulletMul * bulletMoney * 3;
    }
}

int NFFishTypeHandler::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    return 0;
}

int NFFishTypeHandler::UserLeftDesk(NFGameFishPlayer *pPlayer)
{
    return 0;
}

int NFFishTypeHandler::OnAddScore(NFGameFishPlayer *pPlayer, NFGameFish *pFish, uint64_t ullScoreMoney)
{
    return 0;
}

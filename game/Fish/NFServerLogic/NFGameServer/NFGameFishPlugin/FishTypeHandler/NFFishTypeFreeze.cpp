// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFreeze.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFreeze
//
// -------------------------------------------------------------------------

#include "NFFishTypeFreeze.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Player/NFGameFishPlayer.h"
#include "Desk/NFGameFishDesk.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeFreeze, EOT_GAME_FISH_TYPE_HANDLE_FREEZE_ID, NFFishTypeHandler)

NFFishTypeFreeze::NFFishTypeFreeze()
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

NFFishTypeFreeze::~NFFishTypeFreeze()
{
}

int NFFishTypeFreeze::CreateInit()
{
    return 0;
}

int NFFishTypeFreeze::ResumeInit()
{
    return 0;
}

int NFFishTypeFreeze::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeFreeze::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_NULL(pFish);
    CHECK_NULL(pPlayer);
    CHECK_NULL(m_pDesk);

    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();

    int32_t iMainMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int32_t iMainScore = bullet.GetBulletMoney() * iMainMul;
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
    gcKillFish.set_totalratio(iTotalScore / bullet.GetBulletMoney());
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    return iTotalScore;
}

int NFFishTypeFreeze::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    //////////////////////////////////////////////////////////////////////////
    proto_ff::gcFreezeFishes gcFreezeFishes;

    gcFreezeFishes.set_mainfish_uid(pFish->m_uFishId);
    gcFreezeFishes.set_mainfish_id(pFish->m_nFishKind);
    gcFreezeFishes.set_mainfishtype(pFish->m_fishKind.m_btFishType);
    gcFreezeFishes.set_isfreeze(true);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        proto_ff::FreezeFish *pFreezeFish = gcFreezeFishes.add_fishes();

        pFreezeFish->set_fish_uid((*iter)->m_uFishId);
        pFreezeFish->set_fish_id((*iter)->m_nFishKind);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeFreeze::KillFish() ==> NF_FISH_CMD_FREEZEFISHES_RSP vecSubFishes.size() = {}", vecSubFishes.size());

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_FREEZEFISHES_RSP, gcFreezeFishes);

    ///////////////////////
    //先这么写吧
    m_gcFreezeFishes.read_from_pbmsg(gcFreezeFishes);
    m_iTimerObjId_Freeze = SetTimer(15000, 1, 0, 0, 0, 15000);
    m_pDesk->SetIsFreezs(true);
    m_ullFreezeStartTime = NFTime::Now().UnixMSec();

    return 0;
}

std::vector<NFGameFish *> NFFishTypeFreeze::GetKilledSubFishes(NFGameFish *mainFish)
{
    return m_pDesk->GetAllFishes();
}

int NFFishTypeFreeze::OnTimer(int timeId, int callcount)
{
    if (timeId == m_iTimerObjId_Freeze)
    {
        DeleteTimer(m_iTimerObjId_Freeze);
        m_iTimerObjId_Freeze = INVALID_ID;

        m_gcFreezeFishes.IsFreeze = false;

        proto_ff::gcFreezeFishes gcFreezeFishes;
        m_gcFreezeFishes.write_to_pbmsg(gcFreezeFishes);

        m_pDesk->SendMsgToAllClient(NF_FISH_CMD_FREEZEFISHES_RSP, gcFreezeFishes);

        uint64_t ullTimerNow = NFTime::Now().UnixMSec();
        uint32_t uFreezeTime = ullTimerNow - m_ullFreezeStartTime;

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeFreeze::OnTimer() uFreezeTime = {}", uFreezeTime);

        for (int i = 0; i < (int) m_gcFreezeFishes.fishes.size(); i++)
        {
            proto_ff_s::FreezeFish_s &freezeFish = m_gcFreezeFishes.fishes[i];

            NFGameFish *pGameFish = m_pDesk->GetFish(freezeFish.fish_uid);
            if (pGameFish != NULL)
            {
                pGameFish->AddFreezeTime(uFreezeTime);
            }
        }

        m_pDesk->SetIsFreezs(false);
    }
    return 0;
}

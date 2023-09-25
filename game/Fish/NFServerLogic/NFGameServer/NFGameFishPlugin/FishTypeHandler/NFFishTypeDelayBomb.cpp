// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeDelayBomb.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeDelayBomb
//
// -------------------------------------------------------------------------

#include "NFFishTypeDelayBomb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "Desk/NFGameFishDesk.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeDelayBomb, EOT_GAME_FISH_TYPE_HANDLE_DELAYBOMB_ID, NFFishTypeHandler)

NFFishTypeDelayBomb::NFFishTypeDelayBomb()
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

NFFishTypeDelayBomb::~NFFishTypeDelayBomb()
{
    m_statusTimer = INVALID_ID;
}

int NFFishTypeDelayBomb::CreateInit()
{
    m_statusTimer = SetTimer(100, 0, 0, 0, 0, 0);
    return 0;
}

int NFFishTypeDelayBomb::ResumeInit()
{
    return 0;
}

int NFFishTypeDelayBomb::OnTimer(int timeId, int callcount)
{
    uint64_t nowTime = NFTime::Now().UnixMSec();
    for(auto iter = m_mapDelayBomb.begin(); iter != m_mapDelayBomb.end();)
    {
        if (nowTime >= iter->second.m_uStatusEndTime)
        {
            iter->second.HandleDelayed();
            iter = m_mapDelayBomb.erase(iter);
        }
        else {
            iter++;
        }
    }
    return 0;
}

int NFFishTypeDelayBomb::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeDelayBomb::OnKilllingFish()");
    NFFishTraceConfig* pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_NULL(pTraceConfig);

    NFDelayBomb* pBomb = CreateDelayBomb(pPlayer, pFish, bullet);
    CHECK_EXPR(pBomb, 0, "CreateDelayBomb Failed!");

    int iMainMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int iMainScore = bullet.GetBulletMoney() * bullet.GetBulletMul() * iMainMul;

    pBomb->m_uTotalScore = iMainScore;

    gamefish::CreateDelayBombRsp createDelayBombRsp;
    createDelayBombRsp.set_uschairid(pBomb->m_uChairId);
    createDelayBombRsp.set_usdelaybombid(pBomb->m_uId);
    createDelayBombRsp.set_uskilledfishid(pBomb->m_bombFish.m_uFishId);
    createDelayBombRsp.set_usstatus(pBomb->m_uStatus);
    createDelayBombRsp.set_usstatustime(0);
    createDelayBombRsp.set_usposx(pBomb->m_ptMyPos.m_iPosX);
    createDelayBombRsp.set_uspoxy(pBomb->m_ptMyPos.m_iPosY);
    createDelayBombRsp.set_bombfishid(pBomb->m_bombFish.m_nFishKind);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEDELAYBOMB_RSP, createDelayBombRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeDelayBomb::OnKilllingFish() NF_FISH_CMD_CREATEDELAYBOMB_RSP m_iPosX = {} , m_iPosY = {}", pBomb->m_ptMyPos.m_iPosX, pBomb->m_ptMyPos.m_iPosY);

    CHMPoint pt = pFish->GetMyPoint(pTraceConfig);

    m_pDesk->SendFishGroup(941, 0, false, pt.m_iPosX, pt.m_iPosY);

    return 0;
}

int NFFishTypeDelayBomb::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeDelayBomb::GetKilledFishMul(NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFFishTraceConfig* pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_EXPR(pTraceConfig, 0, "");

    int iKilledFishMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);

    std::vector<NFGameFish *> vecSubFishes = GetKilledSubFishes(pFish->GetMyPoint(pTraceConfig), pFish->m_iDemageRadius);
    std::vector<NFGameFish *>::iterator iter = vecSubFishes.begin();
    for (; iter != vecSubFishes.end(); iter++)
    {
        iKilledFishMul += (*iter)->GetBaseMul() * bullet.GetBulletMul();
    }

    return iKilledFishMul;
}

void NFFishTypeDelayBomb::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDelayBomb::SyncFishBomb() ===============> m_ullPlayerId = {}", pPlayer->m_ullPlayerId);

    for (auto iter = m_mapDelayBomb.begin(); iter != m_mapDelayBomb.end(); iter++)
    {
        NFDelayBomb* pBomb = &iter->second;
        if (pBomb != NULL)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDelayBomb::SyncFishBomb() ===============> pBomb->m_ullPlayerId = {}", pBomb->m_ullPlayerId);

            gamefish::CreateDelayBombRsp createDelayBombRsp;
            createDelayBombRsp.set_uschairid(pBomb->m_uChairId);
            createDelayBombRsp.set_usdelaybombid(pBomb->m_uId);
            createDelayBombRsp.set_uskilledfishid(pBomb->m_bombFish.m_uFishId);
            createDelayBombRsp.set_usstatus(pBomb->m_uStatus);
            createDelayBombRsp.set_usstatustime(0);
            createDelayBombRsp.set_usposx(pBomb->m_ptMyPos.m_iPosX);
            createDelayBombRsp.set_uspoxy(pBomb->m_ptMyPos.m_iPosY);
            createDelayBombRsp.set_bombfishid(pBomb->m_bombFish.m_nFishKind);

            if (pBomb->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                pBomb->m_uChairId = pPlayer->GetChairIdForClient();
                createDelayBombRsp.set_uschairid(pBomb->m_uChairId);

                //m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEDELAYBOMB_RSP, createDelayBombRsp);
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEDELAYBOMB_RSP, createDelayBombRsp, pPlayer->m_ullPlayerId);
            }
            else
            {
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEDELAYBOMB_RSP, createDelayBombRsp, pPlayer->m_ullPlayerId);
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NF_FISH_CMD_CREATEDELAYBOMB_RSP m_iPosX = {} , m_iPosY = {}", pBomb->m_ptMyPos.m_iPosX, pBomb->m_ptMyPos.m_iPosY);

        }
    }
}

NFDelayBomb *NFFishTypeDelayBomb::CreateDelayBomb(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();
    CHECK_EXPR(!m_mapDelayBomb.full(), NULL, "m_mapDelayBomb Space Not Enough");
    CHECK_EXPR(m_mapDelayBomb.find(id) == m_mapDelayBomb.end(), NULL, "id:{} exist", id);
    NFFishTraceConfig* pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_EXPR(pTraceConfig, NULL, "");

    NFDelayBomb* pBomb = &m_mapDelayBomb[id];
    if (pBomb == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->m_ullPlayerId, "CreateDelayBomb Failed!");
        return NULL;
    }

    pBomb->m_uId = id;
    pBomb->m_uChairId = pPlayer->GetChairIdForClient();
    pBomb->m_ullPlayerId = pPlayer->m_ullPlayerId;
    pBomb->m_bombFish = *pBombFish;
    pBomb->m_ptMyPos  = pBombFish->GetMyPoint(pTraceConfig);
    pBomb->m_uStatus  = 1;
    pBomb->m_uStatusEndTime = NFTime::Now().UnixMSec() + 3700;
    pBomb->m_iBulletMul     = bullet.GetBulletMul();
    pBomb->m_iBulletMoney   = bullet.GetBulletMoney();
    pBomb->m_iMaxWinMoney   = pPlayer->GetMaxWinMoney();
    pBomb->m_uTotalScore    = 0;
    pBomb->m_pFishTypeDelayBomb = this;

    return pBomb;
}

std::vector<NFGameFish *> NFFishTypeDelayBomb::GetKilledSubFishes(CHMPoint ptCenter, int iRadius)
{
    return m_pDesk->GetFishes(INVALID_FISHKIND, ptCenter, iRadius);
}

//////////////////////////////////////////////////////////////////////////

//must be virtual
int NFDelayBomb::HandleDelayed()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFDelayBomb::OnTimer()");
    CHECK_NULL(m_pFishTypeDelayBomb);
    CHECK_NULL(m_pFishTypeDelayBomb->m_pDesk);

    NFGameFishPlayer* pPlayerOwner = m_pFishTypeDelayBomb->m_pDesk->GetPlayer(m_ullPlayerId);
    if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
    {
        NFGameFishPlayer* pPlayer = m_pFishTypeDelayBomb->m_pDesk->GetPlayer(m_ullPlayerId);
        CHECK_EXPR(pPlayer, -1, "Check pPlayer Failed! pPlayer == NULL");

        //if (pBomb->uStatus == 1)// only one status now , no need to judge !
        {
            gamefish::KillFishRsp gcKillFish;
            gcKillFish.set_bulletid(0);
            gcKillFish.set_bombuid(0);
            gcKillFish.set_mainfishuid(m_bombFish.m_uFishId);
            gcKillFish.set_mainfishid(m_bombFish.m_nFishKind);
            gcKillFish.set_mainfishtype(m_bombFish.m_fishKind.m_btFishType);
            gcKillFish.set_mainmultiple(0/*m_bombFish.GetBaseMul()*/);
            gcKillFish.set_mainscore(0);//bomb is no scored
            //gcKillFish.set_totalscore(0);//will be set below
            //gcKillFish.set_totalratio(0);//will be set below
            gcKillFish.set_chairid(m_uChairId);
            gcKillFish.set_userrorcode(0);
            gcKillFish.set_bombfishid(0);
            gcKillFish.set_subfishcount(0);

            std::vector<NFGameFish *> vecSubFishes = m_pFishTypeDelayBomb->GetKilledSubFishes(m_ptMyPos, m_bombFish.m_iDemageRadius);


            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "subfishcount = {}", vecSubFishes.size());

            int iSubFishCount = 0;
            std::vector<NFGameFish *>::iterator iter1 = vecSubFishes.begin();
            for (; iter1 != vecSubFishes.end(); iter1++)
            {
                NFGameFish* pSubFish = *iter1;

                if (pSubFish->m_fishKind.m_btFishType != 1)//only kill normal fish;
                {
                    continue;
                }

                int iRand = NFRandomInt(0, 100);
                if (iRand < 60)
                {
                    continue;
                }

                uint32_t iMul = pSubFish->GetBaseMul() * m_iBulletMul;
                uint32_t iScore = m_iBulletMoney * iMul;
                uint32_t iMyMaxWinMoney = MyMaxWinMoney();

                if ((m_uTotalScore + iScore > (uint32_t)m_iMaxWinMoney)
                    || (m_uTotalScore + iScore > iMyMaxWinMoney)
                    || (!m_bombFish.IsCanKill(m_pFishTypeDelayBomb->m_pDesk->GetFishConfigConfig(), pSubFish->m_nFishKind)))
                {
                    if (m_uTotalScore + iScore > (uint32_t)m_iMaxWinMoney)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! m_uTotalScore + iScore > m_iMaxWinMoney ! {} + {} > {} !", m_uTotalScore, iScore, m_iMaxWinMoney);
                    }

                    if (m_uTotalScore + iScore > MyMaxWinMoney())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! m_uTotalScore + iScore > m_iMaxWinMoney ! {} + {} > {} !", m_uTotalScore, iScore, MyMaxWinMoney());
                    }

                    if ((!m_bombFish.IsCanKill(m_pFishTypeDelayBomb->m_pDesk->GetFishConfigConfig(), pSubFish->m_nFishKind)))
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! IsCanKill == false pSubFish->m_nFishKind = {}", pSubFish->m_nFishKind);
                    }

                    break;
                }

                pSubFish->Kill();

                m_uTotalScore += iScore;
                iSubFishCount++;

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> m_uTotalScore = {} (+{}) < {}(iMyMaxWinMoney)", m_uTotalScore, iScore, iMyMaxWinMoney);


                gamefish::KillFishRsp* pSubKillFish = gcKillFish.add_subfishes();
                pSubKillFish->set_bombuid(m_bombFish.m_uFishId);
                pSubKillFish->set_mainfishuid(pSubFish->m_uFishId);
                pSubKillFish->set_mainfishid(pSubFish->m_nFishKind);
                pSubKillFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
                pSubKillFish->set_mainmultiple(iMul);
                pSubKillFish->set_mainscore(iScore);
                pSubKillFish->set_chairid(m_uChairId);
                pSubKillFish->set_userrorcode(0);
                pSubKillFish->set_bombfishid(m_bombFish.m_nFishKind);
            }

            gcKillFish.set_totalscore(m_uTotalScore);
            gcKillFish.set_totalratio(m_uTotalScore / m_iBulletMoney);
            gcKillFish.set_subfishcount(iSubFishCount);

            m_pFishTypeDelayBomb->m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDelayBomb::OnTimer() NF_FISH_CMD_KILLFISH ==> set_subfishcount = {}", vecSubFishes.size());

            pPlayer->AddCaptureMoney(m_uTotalScore);
        }
    }
    else
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "player not ready !!!!!!!!!!!!!!!!!!!!!");
    }
    //////////////////////////////////////////////////////////////////////////

    gamefish::DelayBomb_Bomb_Rsp delayBomb_Bomb_Rsp;
    delayBomb_Bomb_Rsp.set_uschairid(m_uChairId);
    delayBomb_Bomb_Rsp.set_usdelaybombid(m_uId);
    delayBomb_Bomb_Rsp.set_ustotalscore(m_uTotalScore);
    delayBomb_Bomb_Rsp.set_ustotalmul(m_uTotalScore / m_iBulletMoney);

    m_pFishTypeDelayBomb->m_pDesk->SendMsgToAllClient(NF_FISH_CMD_DELAYBOMB_BOMB_RSP, delayBomb_Bomb_Rsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeDelayBomb::OnTimer() NF_FISH_CMD_DELAYBOMB_BOMB_RSP m_uTotalScore = {}", m_uTotalScore);
    return 0;
}

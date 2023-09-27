// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMadCow.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMadCow
//
// -------------------------------------------------------------------------

#include "NFFishTypeMadCow.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"
#include "Player/NFGameFishPlayer.h"
#include "Fish/NFGameFish.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeMadCow, EOT_GAME_FISH_TYPE_HANDLE_MADCOW_ID, NFFishTypeHandler)

NFFishTypeMadCow::NFFishTypeMadCow()
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

NFFishTypeMadCow::~NFFishTypeMadCow()
{
}

int NFFishTypeMadCow::CreateInit()
{
    return 0;
}

int NFFishTypeMadCow::ResumeInit()
{
    return 0;
}

int NFFishTypeMadCow::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFMadCow* pMadCow = CreateMadCow(pPlayer, pFish, bullet);
    CHECK_EXPR(pMadCow, 0, "CreateMadCow Failed");

    int iMainMul   = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int iMainScore = bullet.GetBulletMoney() * iMainMul;

    pMadCow->m_uTotalScore = iMainScore;


    gamefish::CreateMadCowRsp createMadCowRsp;
    createMadCowRsp.set_uschairid(pMadCow->m_uChairId);
    createMadCowRsp.set_usmadcowid(pMadCow->m_uId);
    createMadCowRsp.set_uskilledfishid(pMadCow->m_BombFish.m_uFishId);
    createMadCowRsp.set_usrundirection(pMadCow->m_uDirection);//1-向左/to left  2-向右/to right
    createMadCowRsp.set_usstatus(eMadStatus_Wait);   //1-待机/waitSts  2-发射/shootSts
    createMadCowRsp.set_usstatustime(0);
    createMadCowRsp.set_ustotalscore(0);//no use for client
    createMadCowRsp.set_ustotalmul(0);  //no use for client

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEMADCOW_RSP, createMadCowRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeMadCow::OnKilllingFish() madCow.uId = {}", pMadCow->m_uId);

    return 0;
}

int NFFishTypeMadCow::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeMadCow::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    for (auto iter = m_mapMadCow.begin(); iter != m_mapMadCow.end();iter++)
    {
        NFMadCow* pMadCow = &iter->second;
        if (pMadCow != NULL)
        {
            gamefish::CreateMadCowRsp createMadCowRsp;
            createMadCowRsp.set_uschairid(pMadCow->m_uChairId);
            createMadCowRsp.set_usmadcowid(pMadCow->m_uId);
            createMadCowRsp.set_uskilledfishid(pMadCow->m_BombFish.m_uFishId);
            createMadCowRsp.set_usrundirection(pMadCow->m_uDirection);
            createMadCowRsp.set_usstatus(pMadCow->m_uStatus);
            createMadCowRsp.set_usstatustime(NFGetTime() - pMadCow->m_uStatusTimeStart);
            createMadCowRsp.set_ustotalscore(pMadCow->m_uTotalScore);
            createMadCowRsp.set_ustotalmul(pMadCow->m_uTotalScore / pMadCow->m_iBulletMoney);

            if (pMadCow->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                pMadCow->m_uChairId = pPlayer->GetChairIdForClient();//自己有可能换了座位!!!
                createMadCowRsp.set_uschairid(pMadCow->m_uChairId);

                //如果是炮台上的东西/电磁炮，要发给所有人； 
                //m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEMADCOW_RSP, createMadCowRsp);

                //如果是扔出去的炸弹，发给登陆者自己就好了；
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEMADCOW_RSP, createMadCowRsp, pPlayer->m_ullPlayerId);
            }
            else
            {
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEMADCOW_RSP, createMadCowRsp, pPlayer->m_ullPlayerId);
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeMadCow::SyncFishBomb() ===============> NF_FISH_CMD_CREATEMADCOW_RSP");
        }
    }
    return 0;
}

NFMadCow *NFFishTypeMadCow::CreateMadCow(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();
    CHECK_EXPR(m_mapMadCow.size() < m_mapMadCow.max_size(), NULL, "m_mapMadCow space not enough");

    NFMadCow* pMadCow = &m_mapMadCow[id];
    CHECK_EXPR(pMadCow, NULL, "m_mapMadCow.Insert id:{} Failed!", id);

    pMadCow->InitShmObj(this);
    pMadCow->m_uId = id;
    pMadCow->m_uChairId = pPlayer->GetChairIdForClient();
    pMadCow->m_ullPlayerId = pPlayer->m_ullPlayerId;
    pMadCow->m_BombFish   = *pBombFish;
    pMadCow->m_uBornTime  = NFGetTime();
    pMadCow->m_uDirection = NFRandInt(0, 100) > 50 ? 1 : 2;//这个可以优化成根据牛实际走的方向
    pMadCow->m_uStatus    = eMadStatus_Wait;//待机状态
    pMadCow->m_uStatusTimeStart = NFGetTime();
    pMadCow->m_uStatusTimerId = pMadCow->SetTimer(2100, 1, 0, 0, 0, 2100); //2.1秒后进入发射状态
    pMadCow->m_iBulletMul   = bullet.GetBulletMul();
    pMadCow->m_iBulletMoney = bullet.GetBulletMoney();
    pMadCow->m_iMaxWinMoney = pPlayer->GetMaxWinMoney();
    pMadCow->m_uTotalScore  = 0;

    return pMadCow;
}

int NFFishTypeMadCow::DeleteMadCor(uint32_t id)
{
    auto iter = m_mapMadCow.find(id);
    if (iter != m_mapMadCow.end())
    {
        m_mapMadCow.erase(id);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete MadCow:{} Success", id);
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete MadCow:{} Failed, not exist", id);
    }
    return 0;
}

NFMadCow *NFFishTypeMadCow::GetMadCor(uint32_t id)
{
    auto iter = m_mapMadCow.find(id);
    if (iter != m_mapMadCow.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFMadCow::OnTimer(int timeId, int callcount)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeMadCow::OnTimer() ");
    auto pDesk = GetDesk();
    CHECK_NULL(pDesk);
    NFFishTypeMadCow* pFishTypeHandler = dynamic_cast<NFFishTypeMadCow*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeHandler);
    NFFishConfigConfig* pFishConfig = pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfig);

    if (m_uStatusTimerId == timeId)
    {
        DeleteTimer(m_uStatusTimerId);
        m_uStatusTimerId = INVALID_ID;

        if (m_uStatus == eMadStatus_Wait)
        {
            //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFMadCow::OnTimer() pFireStorm->uStatus == eMadStatus_Wait");
            m_uStatus = eMadStatus_Shoot;
            m_uStatusTimeStart = NFGetTime();
            m_uStatusTimerId   = SetTimer(1000, 1, 0, 0, 0, 1000);

            gamefish::MadCowStatusRsp madCowStatusRsp;
            madCowStatusRsp.set_uschairid(m_uChairId);
            madCowStatusRsp.set_usmadcowid(m_uId);
            madCowStatusRsp.set_usstatus(eMadStatus_Shoot);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_MADCOWSTATUS_RSP, madCowStatusRsp);

            //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFMadCow::OnTimer() NF_FISH_CMD_MADCOWSTATUS_RSP pMadCow->uStatus == 2 pMadCow->uId = {}", m_uId);
        }
        else if (m_uStatus == eMadStatus_Shoot)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFMadCow::OnTimer() uStatus == eMadStatus_Shoot");
            //////////////////////////////////////////////////////////////////////////

            NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(m_ullPlayerId);
            if (pPlayerOwner != NULL /*&& pPlayerOwner->m_ready*/)
            {
                CHMPoint SrcCenterPoint(1560 / 2, 960 / 2);//Screen center
                std::vector<NFGameFish*> vecFishes = pDesk->GetFishes(SrcCenterPoint, 999, 10);

                gamefish::KillFishRsp gcKillFish;
                gcKillFish.set_bulletid(0);
                gcKillFish.set_bombuid(0);
                gcKillFish.set_mainfishuid(m_BombFish.m_uFishId);
                gcKillFish.set_mainfishid(m_BombFish.m_nFishKind);
                gcKillFish.set_mainfishtype(m_BombFish.m_fishKind.m_btFishType);
                gcKillFish.set_mainmultiple(m_BombFish.GetBaseMul());
                gcKillFish.set_mainscore(0); //bomb is no scored
                gcKillFish.set_totalscore(0);//will set below
                gcKillFish.set_totalratio(0);//will set below
                gcKillFish.set_chairid(m_uChairId);
                gcKillFish.set_userrorcode(0);
                gcKillFish.set_subfishcount(0);
                gcKillFish.set_bombfishid(0);

                int iSubFishCount = 0;
                int iTotalScore = 0;
                std::vector<NFGameFish*>::iterator iterFish = vecFishes.begin();
                for (; iterFish != vecFishes.end(); iterFish++)
                {
                    NFGameFish* pSubFish = *iterFish;
                    if ((pSubFish != NULL) && (pSubFish->IsKilled() == false)
                        && (pSubFish->m_fishKind.m_btFishType == 1))//
                    {
                        uint32_t iMul = pSubFish->GetBaseMul() * m_iBulletMul;
                        uint32_t iScore = m_iBulletMoney * iMul;
                        uint32_t iMyMaxWinMoney = MyMaxWinMoney();

                        if (m_uTotalScore + iScore > (uint32_t)m_iMaxWinMoney
                            || m_uTotalScore + iScore > iMyMaxWinMoney
                            || (!m_BombFish.IsCanKill(pFishConfig, pSubFish->m_nFishKind)))
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_uTotalScore + iScore > iMyMaxWinMoney ! {} + {} > {} !", m_uTotalScore, iScore, iMyMaxWinMoney);
                            break;
                        }

                        pSubFish->Kill();
                        iTotalScore += iScore;
                        m_uTotalScore += iScore;

                        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> m_uTotalScore = {} (+{}) < {}(iMyMaxWinMoney)", m_uTotalScore, iScore, iMyMaxWinMoney);


                        gamefish::KillFishRsp* pKillFish = gcKillFish.add_subfishes();
                        pKillFish->set_bombuid(m_BombFish.m_uFishId);
                        pKillFish->set_mainfishuid(pSubFish->m_uFishId);
                        pKillFish->set_mainfishid(pSubFish->m_nFishKind);
                        pKillFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
                        pKillFish->set_mainmultiple(iMul);
                        pKillFish->set_mainscore(iScore);
                        pKillFish->set_chairid(m_uChairId);
                        pKillFish->set_userrorcode(0);
                        pKillFish->set_bombfishid(m_BombFish.m_nFishKind);

                        iSubFishCount++;
                    }
                    else
                    {
                        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeMadCow::OnTimer() Invalid Fish !");
                    }
                }

                gcKillFish.set_subfishcount(iSubFishCount);
                gcKillFish.set_totalscore(iTotalScore);
                gcKillFish.set_totalratio(iTotalScore / m_iBulletMoney);


                if (iSubFishCount > 0)
                {
                    pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeMadCow::OnTimer() NF_FISH_CMD_KILLFISH");

                    NFGameFishPlayer* pPlayer = pDesk->GetPlayer(m_ullPlayerId);
                    if (pPlayer != NULL)//如果玩家对像都没有了，怎么帮他加钱？
                    {
                        pPlayer->AddCaptureMoney(iTotalScore);
                    }
                }

                //////////////////////////////////////////////////////////////////////////
                gamefish::MadCowScoreRsp madCowScoreRsp;
                madCowScoreRsp.set_uschairid(m_uChairId);
                madCowScoreRsp.set_usmadcowid(m_uId);
                madCowScoreRsp.set_ustotalscore(iTotalScore);
                madCowScoreRsp.set_ustotalmul(iTotalScore / m_iBulletMoney);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_MADCOWSCORE_RSP, madCowScoreRsp);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> m_uTotalScore = {} , thisMul = {} , totalMul = {}", iTotalScore, iTotalScore / m_iBulletMoney, m_uTotalScore / m_iBulletMoney);
            }

            //////////////////////////////////////////////////////////////////////////

            m_uShootCount++;

            if (m_uShootCount < 7)//madCow is 8s long
            {
                m_uStatusTimerId = SetTimer(1000, 1, 0, 0, 0, 1000);
            }
            else
            {
                gamefish::DestoryMadCowRsp destoryMadCowRsp;
                destoryMadCowRsp.set_uschairid(m_uChairId);
                destoryMadCowRsp.set_usmadcowid(m_uId);
                destoryMadCowRsp.set_ustotalscore(m_uTotalScore);
                destoryMadCowRsp.set_ustotalmul(m_uTotalScore / m_iBulletMoney);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_DISTORYMADCOW_RSP, destoryMadCowRsp);

                pFishTypeHandler->DeleteMadCor(m_uId);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeMadCow::OnTimer() NF_FISH_CMD_DISTORYMADCOW_RSP m_uTotalScore = {}", m_uTotalScore);
            }
        }
    }
    return 0;
}
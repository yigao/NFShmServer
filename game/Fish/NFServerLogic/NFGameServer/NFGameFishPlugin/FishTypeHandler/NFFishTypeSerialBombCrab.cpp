// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSerialBombCrab.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSerialBombCrab
//
// -------------------------------------------------------------------------

#include "NFFishTypeSerialBombCrab.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"
#include "Player/NFGameFishPlayer.h"
#include "Fish/NFGameFish.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeSerialBombCrab, EOT_GAME_FISH_TYPE_HANDLE_SERIALBOMBCRAB_ID, NFFishTypeHandler)

NFFishTypeSerialBombCrab::NFFishTypeSerialBombCrab()
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

NFFishTypeSerialBombCrab::~NFFishTypeSerialBombCrab()
{
}

int NFFishTypeSerialBombCrab::CreateInit()
{
    return 0;
}

int NFFishTypeSerialBombCrab::ResumeInit()
{
    return 0;
}

int NFFishTypeSerialBombCrab::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFFishTraceConfig* pTraceConfig = m_pDesk->GetFishTraceConfig();
    CHECK_NULL(pTraceConfig);

    NFSerialBombCrab* pSerialBombCrab = CreateSerialBombCrab(pPlayer, pFish, bullet);
    CHECK_EXPR(pSerialBombCrab, 0, "CreateSerialBombCrab Failed!");


    int iMainMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int iMainScore = bullet.GetBulletMoney() * bullet.GetBulletMul() * iMainMul;

    pSerialBombCrab->m_uTotalScore = iMainScore;

    gamefish::CreateSerialBombCrabRsp createSerialBombCrabRsp;
    createSerialBombCrabRsp.set_uschairid(pSerialBombCrab->m_uChairId);
    createSerialBombCrabRsp.set_usserialbombcrabid(pSerialBombCrab->m_uId);
    createSerialBombCrabRsp.set_uskilledfishid(pSerialBombCrab->m_BombFish.m_uFishId);
    createSerialBombCrabRsp.set_usstatus(pSerialBombCrab->m_uStatus);
    createSerialBombCrabRsp.set_usstatustime(0);
    createSerialBombCrabRsp.set_usbombposx(pFish->GetMyPoint(pTraceConfig).m_iPosX);//the first bomb at the fish's pos
    createSerialBombCrabRsp.set_usbombposy(pFish->GetMyPoint(pTraceConfig).m_iPosY);
    createSerialBombCrabRsp.set_usnextbombposx(pSerialBombCrab->m_uLastPosX);
    createSerialBombCrabRsp.set_usnextbombposy(pSerialBombCrab->m_uLastPosY);
    createSerialBombCrabRsp.set_usbombcount(pSerialBombCrab->m_uBombCount);
    createSerialBombCrabRsp.set_bombfishid(pSerialBombCrab->m_BombFish.m_nFishKind);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP, createSerialBombCrabRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnKilllingFish() NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP serialBombCrab.uId = {} , uBombCount = {}", pSerialBombCrab->m_uId, pSerialBombCrab->m_uBombCount);

    return 0;
}

int NFFishTypeSerialBombCrab::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeSerialBombCrab::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeSerialBombCrab::SyncFishBomb() ===============> m_ullPlayerId = {}", pPlayer->m_ullPlayerId);

    for (auto iter = m_mapSerialBombCrab.begin(); iter != m_mapSerialBombCrab.end(); iter++)
    {
        NFSerialBombCrab* pSerialBombCrab = &iter->second;
        if (pSerialBombCrab != NULL)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeSerialBombCrab::SyncFishBomb() ===============> pSerialBombCrab->m_ullPlayerId = {}", pSerialBombCrab->m_ullPlayerId);

            gamefish::CreateSerialBombCrabRsp createSerialBombCrabRsp;
            createSerialBombCrabRsp.set_uschairid(pSerialBombCrab->m_uChairId);
            createSerialBombCrabRsp.set_usserialbombcrabid(pSerialBombCrab->m_uId);
            createSerialBombCrabRsp.set_uskilledfishid(pSerialBombCrab->m_BombFish.m_uFishId);
            createSerialBombCrabRsp.set_usstatus(pSerialBombCrab->m_uStatus);
            createSerialBombCrabRsp.set_usstatustime(NFGetTime() - pSerialBombCrab->m_uStatusTimeStart);
            createSerialBombCrabRsp.set_usbombposx(pSerialBombCrab->m_uLastPosX);
            createSerialBombCrabRsp.set_usbombposy(pSerialBombCrab->m_uLastPosY);
            createSerialBombCrabRsp.set_usnextbombposx(pSerialBombCrab->m_uLastPosX);
            createSerialBombCrabRsp.set_usnextbombposy(pSerialBombCrab->m_uLastPosY);
            createSerialBombCrabRsp.set_usbombcount(pSerialBombCrab->m_uBombCount);
            createSerialBombCrabRsp.set_bombfishid(pSerialBombCrab->m_BombFish.m_nFishKind);

            if (pSerialBombCrab->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                pSerialBombCrab->m_uChairId = pPlayer->GetChairIdForClient();//�Լ��п��ܻ�����λ!!!
                createSerialBombCrabRsp.set_uschairid(pSerialBombCrab->m_uChairId);

                //m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP, createSerialBombCrabRsp);
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP, createSerialBombCrabRsp, pPlayer->m_ullPlayerId);
            }
            else
            {
                m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP, createSerialBombCrabRsp, pPlayer->m_ullPlayerId);
            }
        }
    }
    return 0;
}

NFSerialBombCrab *NFFishTypeSerialBombCrab::CreateSerialBombCrab(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();

    NFSerialBombCrab* pSerialBombCrab = &m_mapSerialBombCrab[id];
    CHECK_EXPR(pSerialBombCrab, NULL, "m_mapSerialBombCrab.Insert id:{} Failed", id);

    pSerialBombCrab->InitShmObj(this);
    pSerialBombCrab->m_uId = id;
    pSerialBombCrab->m_uChairId = pPlayer->GetChairIdForClient();
    pSerialBombCrab->m_ullPlayerId = pPlayer->m_ullPlayerId;
    pSerialBombCrab->m_BombFish = *pBombFish;
    pSerialBombCrab->m_uBornTime = NFGetTime();
    pSerialBombCrab->m_uStatus = eSerialBombCrabStatus_Shoot;//wait status is canceled
    pSerialBombCrab->m_uStatusTimeStart = NFGetTime();
    pSerialBombCrab->m_uStatusTimerId = INVALID_ID;//serialBombCrab->SetTimer(3500, INVALID_ID, 0, 0, 0, 3500);
    pSerialBombCrab->m_uBombTimerId = pSerialBombCrab->SetTimer(3000, 1, 0, 0, 0, 3000);
    pSerialBombCrab->m_uBombCount = 1;
    pSerialBombCrab->m_iBulletMul = bullet.GetBulletMul();
    pSerialBombCrab->m_iBulletMoney = bullet.GetBulletMoney();
    pSerialBombCrab->m_iMaxWinMoney = pPlayer->GetMaxWinMoney();
    pSerialBombCrab->m_uTotalScore = 0;
    pSerialBombCrab->m_uLastPosX = 1560 / 2;//we set SrcCenter pt as the first point
    pSerialBombCrab->m_uLastPosY = 960 / 2;
    pSerialBombCrab->m_uBombCountMax = 4;   //we set the max bomb count as 5

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnTimer() 940940940");

    m_pDesk->SendFishGroup(940, 0, false, pSerialBombCrab->m_uLastPosX, pSerialBombCrab->m_uLastPosY);

    return pSerialBombCrab;
}

int NFFishTypeSerialBombCrab::DeleteBombCrab(uint32_t id)
{
    auto iter = m_mapSerialBombCrab.find(id);
    if (iter != m_mapSerialBombCrab.end())
    {
        m_mapSerialBombCrab.erase(id);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete BombCrab:{} Success", id);
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete BombCrab:{} Failed, not exist", id);
    }
    return 0;
}

NFSerialBombCrab *NFFishTypeSerialBombCrab::GetBombCrab(uint32_t id)
{
    auto iter = m_mapSerialBombCrab.find(id);
    if (iter != m_mapSerialBombCrab.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFSerialBombCrab::OnTimer(int timeId, int callcount)
{
    auto pDesk = GetDesk();
    CHECK_NULL(pDesk);
    NFFishTypeSerialBombCrab* pFishTypeHandler = dynamic_cast<NFFishTypeSerialBombCrab*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeHandler);
    NFFishConfigConfig* pFishConfig = pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfig);

    if (m_uStatus == eSerialBombCrabStatus_Shoot)
    {
        if (m_uBombTimerId == timeId)
        {
            DeleteTimer(m_uBombTimerId);
            m_uBombTimerId = INVALID_ID;

            m_uStatusTimeStart = NFGetTime();

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnTimer() uBombCount = {}",
                       m_uBombCount);

            if (m_uBombCount < (int32_t)m_uBombCountMax)
            {
                m_uBombCount++;
                //----------------------------
                //////////////////////////////////////////////////////////////////////////
                int iSubFishCount = 0;
                int iTotalScore = 0;
                gamefish::KillFishRsp gcKillFish;
                NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(m_ullPlayerId);
                if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
                {
                    CHMPoint point(m_uLastPosX, m_uLastPosY);
                    std::vector<NFGameFish *> vecFishes = pDesk->GetFishes(point, 500, 30);


                    gcKillFish.set_bulletid(0);
                    gcKillFish.set_bombuid(m_BombFish.m_uFishId);
                    gcKillFish.set_mainfishuid(m_BombFish.m_uFishId);
                    gcKillFish.set_mainfishid(m_BombFish.m_nFishKind);
                    gcKillFish.set_mainfishtype(m_BombFish.m_fishKind.m_btFishType);
                    gcKillFish.set_mainmultiple(m_BombFish.m_fishKind.m_nBaseMul);
                    gcKillFish.set_mainscore(0);//bomb is no scored
                    gcKillFish.set_totalscore(0);
                    gcKillFish.set_totalratio(0);
                    gcKillFish.set_chairid(m_uChairId);
                    gcKillFish.set_userrorcode(0);
                    gcKillFish.set_subfishcount(0);
                    gcKillFish.set_bombfishid(0);

                    uint32_t uMyMaxWinMoney = MyMaxWinMoney();

                    std::vector<NFGameFish *>::iterator iterFish = vecFishes.begin();
                    for (; iterFish != vecFishes.end(); iterFish++)
                    {
                        NFGameFish *pSubFish = *iterFish;
                        if ((pSubFish != NULL) && (pSubFish->IsKilled() == false) &&
                            (pSubFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 : we kill normal fishes now
                        {
                            if (NFRandomInt(0, 100) < 70)//30%kill
                            {
                                continue;
                            }

                            uint32_t iMul = pSubFish->GetBaseMul() * m_iBulletMoney;
                            uint32_t iScore = m_iBulletMul * iMul;

                            if (m_uTotalScore + iScore > (uint32_t)m_iMaxWinMoney
                                || m_uTotalScore + iScore > uMyMaxWinMoney
                                || (!m_BombFish.IsCanKill(pFishConfig, pSubFish->m_nFishKind)))
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! iTotalScore + iScore > m_iMaxWinMoney ! {} + {} > {} !", iTotalScore, iScore, m_iMaxWinMoney);
                                break;
                            }

                            pSubFish->Kill();
                            iTotalScore += iScore;
                            m_uTotalScore += iScore;

                            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> m_uTotalScore = {} < {} (uMyMaxWinMoney)", m_uTotalScore, uMyMaxWinMoney);

                            gamefish::KillFishRsp *pKillFish = gcKillFish.add_subfishes();
                            pKillFish->set_bombuid(m_BombFish.m_uFishId);
                            pKillFish->set_mainfishuid(pSubFish->m_uFishId);
                            pKillFish->set_mainfishid(pSubFish->m_nFishKind);
                            pKillFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
                            pKillFish->set_mainmultiple(pSubFish->m_fishKind.m_nBaseMul);
                            pKillFish->set_mainscore(iScore);
                            pKillFish->set_chairid(m_uChairId);
                            pKillFish->set_userrorcode(0);
                            pKillFish->set_bombfishid(m_BombFish.m_nFishKind);

                            iSubFishCount++;
                        }
                    }

                    gcKillFish.set_subfishcount(iSubFishCount);
                    gcKillFish.set_totalscore(iTotalScore);
                    gcKillFish.set_totalratio(iTotalScore / m_iBulletMoney);
                }

                //////////////////////////////////////////////////////////////////////////
                //bomb
                gamefish::SerialBombCrabBombRsp serialBombCrabBombRsp;
                serialBombCrabBombRsp.set_uschairid(m_uChairId);
                serialBombCrabBombRsp.set_usserialbombcrabid(m_uId);
                serialBombCrabBombRsp.set_ustotalscore(m_uTotalScore);
                serialBombCrabBombRsp.set_ustotalmul(m_uTotalScore / m_iBulletMoney);
                serialBombCrabBombRsp.set_usbombposx(m_uLastPosX);
                serialBombCrabBombRsp.set_usbombposy(m_uLastPosY);
                serialBombCrabBombRsp.set_usbombcount(m_uBombCount);

                //uint32_t uBombPosX = m_uLastPosX;
                //uint32_t uBombPoxY = m_uLastPosY;

                //the new bomb pos
                m_uLastPosX = NFRandInt(50, 1510);
                m_uLastPosY = NFRandInt(50, 910);

                if (m_uBombCount < (int32_t)m_uBombCountMax) {
                    m_uBombTimerId = SetTimer(3000, 1, 0, 0, 0, 3000);
                    serialBombCrabBombRsp.set_usnextbombposx(m_uLastPosX);
                    serialBombCrabBombRsp.set_usnextbombposy(m_uLastPosY);
                }
                else {
                    //in this case, it will be destroyed later;
                    serialBombCrabBombRsp.set_usnextbombposx(0);
                    serialBombCrabBombRsp.set_usnextbombposy(0);
                }

                pDesk->SendMsgToAllClient(NF_FISH_CMD_SERIALBOMBCRAB_BOMB_RSP, serialBombCrabBombRsp);
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnTimer() NF_FISH_CMD_SERIALBOMBCRAB_BOMB_RSP");

                //////////////////////////////////////////////////////////////////////////
                if (iSubFishCount > 0)
                {
                    pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnTimer() NF_FISH_CMD_KILLFISH");

                    if (pPlayerOwner)
                    {
                        pPlayerOwner->AddCaptureMoney(iTotalScore);
                    }
                }
            }

            if (m_uBombCount >= (int32_t)m_uBombCountMax)
            {
                gamefish::DestorySerialBombCrabRsp destorySerialBombCrabRsp;
                destorySerialBombCrabRsp.set_uschairid(m_uChairId);
                destorySerialBombCrabRsp.set_usserialbombcrabid(m_uId);
                destorySerialBombCrabRsp.set_ustotalscore(m_uTotalScore);
                destorySerialBombCrabRsp.set_ustotalmul(m_uTotalScore / m_iBulletMoney);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_DESTORYSERIALBOMBCRAB_RSP, destorySerialBombCrabRsp);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NF_FISH_CMD_DESTORYSERIALBOMBCRAB_RSP m_uTotalScore = {}", m_uTotalScore);

                pFishTypeHandler->DeleteBombCrab(m_uId);
            }
            else
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSerialBombCrab::OnTimer() 940940940");
                pDesk->SendFishGroup(940, 0, false, m_uLastPosX, m_uLastPosY);
            }
        }
    }
    return 0;
}

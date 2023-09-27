// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFireStorm.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFireStorm
//
// -------------------------------------------------------------------------

#include "NFFishTypeFireStorm.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeFireStorm, EOT_GAME_FISH_TYPE_HANDLE_FIRESTORM_ID, NFFishTypeHandler)

NFFishTypeFireStorm::NFFishTypeFireStorm()
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

NFFishTypeFireStorm::~NFFishTypeFireStorm()
{
}

int NFFishTypeFireStorm::CreateInit()
{
    return 0;
}

int NFFishTypeFireStorm::ResumeInit()
{
    return 0;
}

int NFFireStorm::OnTimer(int timeId, int callcount)
{
    auto pDesk = GetDesk();
    CHECK_NULL(pDesk);
    auto pFishTypeFireStore = dynamic_cast<NFFishTypeFireStorm*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeFireStore);

    if (m_uStatusTimerId == timeId)
    {
        DeleteTimer(m_uStatusTimerId);
        m_uStatusTimerId = INVALID_ID;

        if (m_uStatus == eFirmStormSts_Wait)
        {
            m_uStatus = eFirmStormSts_Shoot;
            m_uStatusTimeStart = NFGetTime();
            m_uDestroyTimerId  = SetTimer(30000, 1, 0, 0, 0, 30000);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "===============> m_uStatus ==> 2 m_uStatusTimeStart = {}", m_uStatusTimeStart);

            gamefish::FireStormStatusRsp fireStormStatusShootRsp;
            fireStormStatusShootRsp.set_uschairid(m_uChairId);
            fireStormStatusShootRsp.set_usfirestormid(m_uId);
            fireStormStatusShootRsp.set_usstatus(m_uStatus);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_FIRESTORMSTATUS_RSP, fireStormStatusShootRsp);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFireStorm::OnTimer() NF_FISH_CMD_FIRESTORMSTATUS_RSP pFireStorm->uStatus == 2 pFireStorm->uId = {}", m_uId);
        }
    }
    else if (m_uDestroyTimerId == timeId)
    {
        NFFireStorm* pFireStorm = pFishTypeFireStore->GetFireStorm(m_uId);
        if (pFireStorm)
        {
            gamefish::DestoryFireStormRsp destoryFireStormRsp;
            destoryFireStormRsp.set_uschairid(pFireStorm->m_uChairId);
            destoryFireStormRsp.set_usfirestormid(pFireStorm->m_uId);
            destoryFireStormRsp.set_ustotalscore(pFireStorm->m_uTotalScore);
            destoryFireStormRsp.set_ustotalmul(pFireStorm->m_uTotalScore / pFireStorm->m_iBulletMoney);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_DESTORYFIRESTORM_RSP, destoryFireStormRsp);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::DestoryFireStorm() NF_FISH_CMD_DESTORYFIRESTORM_RSP");
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> m_uTotalScore = {} , totalMul = {}", pFireStorm->m_uTotalScore, pFireStorm->m_uTotalScore / pFireStorm->m_iBulletMoney);


            pFishTypeFireStore->DeleteFireStorm(m_uId);
        }
    }
    return 0;
}

int NFFishTypeFireStorm::DeleteFireStorm(uint32_t id)
{
    auto iter = m_mapFireStorm.find(id);
    if (iter != m_mapFireStorm.end())
    {
        m_mapFireStorm.erase(id);
        NFLogError(NF_LOG_SYSTEMLOG, -1, "DeleteFireStorm id:{} success", id);
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, -1, "DeleteFireStorm id:{} fail", id);
    }
    return 0;
}

NFFireStorm* NFFishTypeFireStorm::GetFireStorm(uint32_t id)
{
    auto iter = m_mapFireStorm.find(id);
    if (iter != m_mapFireStorm.end())
    {
        return &iter->second;
    }
    return nullptr;
}

NFFireStorm* NFFishTypeFireStorm::GetFireStormByPlayerId(uint64_t playerId)
{
    for(auto iter = m_mapFireStorm.begin(); iter != m_mapFireStorm.end(); iter++)
    {
        if (iter->second.m_ullPlayerId == playerId)
        {
            return &iter->second;
        }
    }
    return nullptr;
}

int NFFishTypeFireStorm::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_NULL(pFish);
    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);

    NFFireStorm* pFireStorm = GetFireStormByPlayerId(pPlayer->m_ullPlayerId);
    if (pFireStorm != NULL)
    {
        return 0;
    }
    //=======================

    pFireStorm = CreateFireStorm(pPlayer, pFish, bullet);
    CHECK_EXPR(pFireStorm, -1, "CreateFireStorm Failed!");

    gamefish::CreateFireStormRsp createFireStormRsp;
    createFireStormRsp.set_uschairid(pFireStorm->m_uChairId);
    createFireStormRsp.set_usfirestormid(pFireStorm->m_uId);
    createFireStormRsp.set_uskilledfishid(pFireStorm->m_bombFish.m_uFishId);
    createFireStormRsp.set_usstatus(pFireStorm->m_uStatus);
    createFireStormRsp.set_usstatustime(0);
    createFireStormRsp.set_ustotalscore(0);
    createFireStormRsp.set_ustotalmul(0);

    pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEFIRESTORM_RSP, createFireStormRsp);
    return 0;
}

int NFFishTypeFireStorm::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeFireStorm::OnAddScore(NFGameFishPlayer *pPlayer, NFGameFish *pFish, uint64_t ullScoreMoney)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnAddScore() =============> ullScoreMoney = {}", ullScoreMoney);
    CHECK_NULL(pFish);
    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);

    if (pFish->m_fishKind.m_btFishType == NFGAME_FISHTYPE_FIRESTORM)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnAddScore() NFGAME_FISHTYPE_FIRESTORM return 0;");
        return 0;
    }

    NFFireStorm* pFireStorm = GetFireStormByPlayerId(pPlayer->m_ullPlayerId);
    if (pFireStorm == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnAddScores() pFireStorm == NULL");
        return 0;
    }

    if (pFireStorm->m_ullPlayerId != pPlayer->m_ullPlayerId)
    {
        return 0;
    }

    pFireStorm->m_uTotalScore += ullScoreMoney;

    gamefish::FireStormScoreRsp fireStormScoreRsp;
    fireStormScoreRsp.set_uschairid(pFireStorm->m_uChairId);
    fireStormScoreRsp.set_usfirestormid(pFireStorm->m_uId);
    fireStormScoreRsp.set_ustotalscore(ullScoreMoney);
    fireStormScoreRsp.set_ustotalmul(ullScoreMoney / pFireStorm->m_iBulletMoney);

    pDesk->SendMsgToAllClient(NF_FISH_CMD_FIRESTORMSCORE_RSP, fireStormScoreRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> pFireStorm->m_uTotalScore = {} , totalMul = {}", pFireStorm->m_uTotalScore, pFireStorm->m_uTotalScore / pFireStorm->m_iBulletMoney);

    return 0;
}

int NFFishTypeFireStorm::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeFireStorm::SyncFishBomb() ===============> m_ullPlayerId = {}", pPlayer->m_ullPlayerId);

    //////////////////////////////////////////////////////////////////////////
    for (auto iter = m_mapFireStorm.begin(); iter != m_mapFireStorm.end(); iter++)
    {
        NFFireStorm* pFireStorm = &iter->second;
        //////////////////////////////////////////////////////////////////////////
        if (pFireStorm != NULL)
        {
            gamefish::CreateFireStormRsp createFireStormRsp;
            createFireStormRsp.set_uschairid(pFireStorm->m_uChairId);
            createFireStormRsp.set_usfirestormid(pFireStorm->m_uId);
            createFireStormRsp.set_uskilledfishid(pFireStorm->m_bombFish.m_uFishId);
            createFireStormRsp.set_usstatus(pFireStorm->m_uStatus);
            createFireStormRsp.set_usstatustime(NFGetTime() - pFireStorm->m_uStatusTimeStart);
            createFireStormRsp.set_ustotalscore(pFireStorm->m_uTotalScore);
            createFireStormRsp.set_ustotalmul(pFireStorm->m_uTotalScore / pFireStorm->m_iBulletMoney);

            if (pFireStorm->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                pFireStorm->m_uChairId = pPlayer->GetChairIdForClient();//自己有可能换了座位!!!
                createFireStormRsp.set_uschairid(pFireStorm->m_uChairId);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEFIRESTORM_RSP, createFireStormRsp);
                //m_pDesk->SendMsgToClient(pPlayer->m_ullPlayerId, NF_FISH_CMD_CREATEFIRESTORM_RSP, createFireStormRsp);
            }
            else
            {
                NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(pFireStorm->m_ullPlayerId);
                if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
                {
                    pDesk->SendMsgToClient(NF_FISH_CMD_CREATEFIRESTORM_RSP, createFireStormRsp, pPlayer->m_ullPlayerId);
                }
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "===============> NF_FISH_CMD_CREATEFIRESTORM_RSP, m_uStatusTimeStart = {}", pFireStorm->m_uStatusTimeStart);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "===============> NF_FISH_CMD_CREATEFIRESTORM_RSP, NFGetTime() = {}", NFGetTime());
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "===============> NF_FISH_CMD_CREATEFIRESTORM_RSP, usstatustime = {}", createFireStormRsp.usstatustime());
        }
    }
    return 0;
}

int NFFishTypeFireStorm::OnHandleClientMessage(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");

    switch (packet.nMsgId)
    {
        case NF_FISH_CMD_SHOOTBULLET:
            return OnHandleFishShootBullet(pPlayer, packet);

        default:
            return 0;
    }
}

int NFFishTypeFireStorm::OnHandleFishShootBullet(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::ShootBulletReq shootBulletReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, shootBulletReq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnHandleFishShootBullet() =============> ");
    CHECK_NULL(pPlayer);

    NFFireStorm* pFireStorm = GetFireStormByPlayerId(pPlayer->m_ullPlayerId);
    if (pFireStorm == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnHandleFishShootBullet() pFireStorm == NULL");
        return 0;
    }

    if (pFireStorm->m_ullPlayerId != pPlayer->m_ullPlayerId)
    {
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeFirStorm::OnHandleFishShootBullet() pFireStorm->uStatus = {}", pFireStorm->m_uStatus);

    if (pFireStorm->m_uStatus != eFirmStormSts_Shoot)
    {
        return 0;
    }

    NFFishBullet bullet;
    bullet.m_uBulletId   = shootBulletReq.usbulletid();
    bullet.m_iAngle       = shootBulletReq.sangle();
    bullet.m_iBulletLevel = shootBulletReq.bycannonlevelindex();//这个值客户传来的一直是0, 这个
    bullet.m_uBulletType  = eBulletType_Free;

    pPlayer->ShootBullet(bullet);

    return 0;
}

NFFireStorm *NFFishTypeFireStorm::CreateFireStorm(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();

    CHECK_EXPR(m_mapFireStorm.size() < m_mapFireStorm.max_size(), NULL, "m_mapFireStorm space not enough");
    NFFireStorm* fireStorm = &m_mapFireStorm[id];
    CHECK_EXPR(fireStorm, NULL, "CreateProp Insert id:{} Failed!", id);

    fireStorm->InitShmObj(this);
    fireStorm->m_uId = id;
    fireStorm->m_uChairId  = pPlayer->GetChairIdForClient();
    fireStorm-> m_ullPlayerId = pPlayer->m_ullPlayerId;
    fireStorm->m_bombFish  = *pBombFish;
    fireStorm->m_uBornTime = NFGetTime();
    fireStorm->m_uStatus   = eFirmStormSts_Wait;//待机状态/wait status
    fireStorm->m_uStatusTimeStart = NFGetTime();
    fireStorm->m_uStatusTimerId   = fireStorm->SetTimer(7400, 1, 0, 0, 0, 7400); ////几秒之后变成发射状态
    fireStorm->m_uDestroyTimerId  = 0;

    fireStorm->m_uTotalScore  = 0;
    fireStorm->m_iBulletMoney = bullet.GetBulletMoney();

    return fireStorm;
}

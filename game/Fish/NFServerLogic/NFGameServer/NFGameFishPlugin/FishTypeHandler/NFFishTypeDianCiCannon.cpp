// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeDianCiCannon.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeDianCiCannon
//
// -------------------------------------------------------------------------

#include "NFFishTypeDianCiCannon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Player/NFGameFishPlayer.h"
#include "Desk/NFGameFishDesk.h"
#include "CSFish.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeDianCiCannon, EOT_GAME_FISH_TYPE_HANDLE_DIANCICANNON_ID, NFFishTypeHandler)

NFFishTypeDianCiCannon::NFFishTypeDianCiCannon()
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

NFFishTypeDianCiCannon::~NFFishTypeDianCiCannon()
{
}

int NFFishTypeDianCiCannon::CreateInit()
{
    return 0;
}

int NFFishTypeDianCiCannon::ResumeInit()
{
    return 0;
}

int NFDianCiCannon::OnTimer(int timeId, int callcount)
{
    DeleteTimer(timeId);
    NFGameFishDesk* pDesk = GetDesk();
    CHECK_NULL(pDesk);
    NFFishTypeDianCiCannon* pFishTypeHandler = dynamic_cast<NFFishTypeDianCiCannon*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeHandler);

    if (m_uStatus == eDianCiConnonSts_Aim)//32s timer is over time, auto shoot
    {
        NFGameFishPlayer* pPlayerOwner = GetPlayer(m_ullPlayerId);
        if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
        {
            m_uStatus = eDianCiConnonSts_Shoot;
            m_uStatusTimeStart = NFTime::Now().UnixMSec();
            SetTimer(3500, 1, 0, 0, 0, 3500);//3.5s

            //auto shoot
            gamefish::DianCiCannonShootRsp dianCiCannonShootRsp;
            dianCiCannonShootRsp.set_uschairid(m_uChairId);
            dianCiCannonShootRsp.set_usdiancicannonid(m_uId);
            dianCiCannonShootRsp.set_usangle(m_uAngle);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONSHOOT_RSP, dianCiCannonShootRsp);
        }
        else
        {
            pFishTypeHandler->DeleteDianCicannon(m_uId);
        }
    }
    else if (m_uStatus == eDianCiConnonSts_Shoot)//3.5s timer is over time
    {
        gamefish::DianCiCannonDestroyRsp dianCiCannonDestroyRsp;
        dianCiCannonDestroyRsp.set_uschairid(m_uChairId);
        dianCiCannonDestroyRsp.set_usdiancicannonid(m_uId);
        dianCiCannonDestroyRsp.set_ustotalscore(m_uTotalScore);
        dianCiCannonDestroyRsp.set_ustotalmul(m_uTotalScore / m_iBulletMoney);

        pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONDESTORY_RSP, dianCiCannonDestroyRsp);

        pFishTypeHandler->DeleteDianCicannon(m_uId);
    }
    return 0;
}

NFDianCiCannon* NFFishTypeDianCiCannon::GetDianCiCannon(uint32_t id)
{
    auto iter = m_mapDianCiCannon.find(id);
    if (iter != m_mapDianCiCannon.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFFishTypeDianCiCannon::DeleteDianCicannon(uint32_t id)
{
    auto iter = m_mapDianCiCannon.find(id);
    if (iter != m_mapDianCiCannon.end())
    {
        m_mapDianCiCannon.erase(id);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "DeleteDianCicannon id:{} success", id);
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "DeleteDianCicannon id:{} not exit", id);
        return -1;
    }
    return 0;
}

int NFFishTypeDianCiCannon::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " dianCiCannon m_uFishId = {} m_btFishType = {}", pFish->m_uFishId, pFish->m_fishKind.m_btFishType);
    CHECK_NULL(pPlayer);
    CHECK_NULL(pFish);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);

    NFDianCiCannon* dianCiCannon = CreateDianCiCann(pPlayer, pFish, bullet);
    CHECK_EXPR(dianCiCannon, 1, "CreateDianCiCann Failed!");

    int iMainMul = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int iMainScore = bullet.GetBulletMoney() * bullet.GetBulletMul() * iMainMul;
    dianCiCannon->m_uTotalScore = iMainScore;

    gamefish::CreateDianCiCannonRsp createDianCiCannonRsp;
    createDianCiCannonRsp.set_uschairid(pPlayer->GetChairIdForClient());
    createDianCiCannonRsp.set_usdiancicannonid(dianCiCannon->m_uId);
    createDianCiCannonRsp.set_uskilledfishid(pFish->m_uFishId);
    createDianCiCannonRsp.set_usdiancicannonstatus(dianCiCannon->m_uStatus);
    createDianCiCannonRsp.set_usdiancicannonstatustime(0);
    createDianCiCannonRsp.set_uskilledfishkind(dianCiCannon->m_bombFish.m_nFishKind);


    pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEDIANCICANNON_RSP, createDianCiCannonRsp);


    gamefish::DianCiCannonAimRsp dianCiCannonRsp;
    dianCiCannonRsp.set_uschairid(dianCiCannon->m_uChairId);
    dianCiCannonRsp.set_usdiancicannonid(dianCiCannon->m_uId);
    dianCiCannonRsp.set_usangle(dianCiCannon->m_uAngle);

    pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONAIM_RSP, createDianCiCannonRsp);

    return 0;
}

int NFFishTypeDianCiCannon::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeDianCiCannon::OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet)
{
    switch (packet.nMsgId)
    {
        case NF_FISH_CMD_DIANCICANNONAIM_REQ:
            return OnHandleDianCiCannonAim(pPlayer, packet);

        case NF_FISH_CMD_DIANCICANNONSHOOT_REQ:
            return OnHandleDianCiCannonShoot(pPlayer, packet);

        case NF_FISH_CMD_DIANCICANNONHITFISH_REQ:
            return OnHandleDianCiCannonHitFish(pPlayer, packet);


        default:
            return 0;
    }
}

int NFFishTypeDianCiCannon::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDianCiCannon::SyncFishBomb() ===============> m_ullPlayerId = {}", pPlayer->m_ullPlayerId);
    for (auto iter = m_mapDianCiCannon.begin(); iter != m_mapDianCiCannon.end(); iter++)
    {
        NFDianCiCannon* dianCiCannon = &iter->second;

        //////////////////////////////////////////////////////////////////////////
        if (dianCiCannon != NULL)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeDianCiCannon::SyncFishBomb() ===============> dianCiCannon->m_ullPlayerId = {}", dianCiCannon->m_ullPlayerId);

            gamefish::CreateDianCiCannonRsp createDianCiCannonRsp;
            createDianCiCannonRsp.set_uschairid(dianCiCannon->m_uChairId);
            createDianCiCannonRsp.set_usdiancicannonid(dianCiCannon->m_uId);
            createDianCiCannonRsp.set_uskilledfishid(dianCiCannon->m_bombFish.m_uFishId);
            createDianCiCannonRsp.set_usdiancicannonstatus(dianCiCannon->m_uStatus);
            createDianCiCannonRsp.set_usdiancicannonstatustime(NFTime::Now().UnixMSec() - dianCiCannon->m_uStatusTimeStart);
            createDianCiCannonRsp.set_uskilledfishkind(dianCiCannon->m_bombFish.m_nFishKind);

            gamefish::DianCiCannonAimRsp dianCiCannonRsp;
            dianCiCannonRsp.set_uschairid(dianCiCannon->m_uChairId);
            dianCiCannonRsp.set_usdiancicannonid(dianCiCannon->m_uId);
            dianCiCannonRsp.set_usangle(dianCiCannon->m_uAngle);

            if (dianCiCannon->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                dianCiCannon->m_uChairId = pPlayer->GetChairIdForClient();
                createDianCiCannonRsp.set_uschairid(dianCiCannon->m_uChairId);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEDIANCICANNON_RSP, createDianCiCannonRsp);
                pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONAIM_RSP, dianCiCannonRsp);
            }
            else
            {
                NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(dianCiCannon->m_ullPlayerId);
                if (pPlayerOwner !=NULL && pPlayerOwner->m_ready)
                {
                    pDesk->SendMsgToClient(NF_FISH_CMD_CREATEDIANCICANNON_RSP, createDianCiCannonRsp, pPlayer->m_ullPlayerId);
                    pDesk->SendMsgToClient(NF_FISH_CMD_DIANCICANNONAIM_RSP, dianCiCannonRsp, pPlayer->m_ullPlayerId);
                }
                else
                {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendMsgToAllClient() ===============> NF_FISH_CMD_CREATEDIANCICANNON_RSP owner is not ready !!!");
                }
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendMsgToAllClient() ===============> NF_FISH_CMD_CREATEDIANCICANNON_RSP m_uChairId = {}", dianCiCannon->m_uChairId);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SendMsgToAllClient() ===============> NF_FISH_CMD_DIANCICANNONAIM_RSP");
        }
    }
    return 0;
}

NFDianCiCannon *NFFishTypeDianCiCannon::CreateDianCiCann(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    int32_t id = FindModule<NFISharedMemModule>()->Get32UUID();
    CHECK_EXPR(m_mapDianCiCannon.size() < m_mapDianCiCannon.max_size(), NULL, "m_mapDianCiCannon space not enough!");

    NFDianCiCannon* dianCiCannon = &m_mapDianCiCannon[id];
    CHECK_EXPR(dianCiCannon, NULL, "m_mapDianCiCannon Insert id:{} Failed!", id);

    dianCiCannon->InitShmObj(this);
    dianCiCannon->m_uId = id;
    dianCiCannon->m_uChairId = pPlayer->GetChairIdForClient();
    dianCiCannon->m_ullPlayerId = pPlayer->m_ullPlayerId;
    dianCiCannon->m_bombFish = *pBombFish;
    dianCiCannon->m_uAngle   = 0;
    dianCiCannon->m_uStatus  = eDianCiConnonSts_Aim;
    dianCiCannon->m_uStatusTimeStart = NFTime::Now().UnixMSec();
    dianCiCannon->SetTimer(32000, 1, 0, 0, 0, 32000);
    dianCiCannon->m_iBulletMul   = bullet.GetBulletMul();
    dianCiCannon->m_iBulletMoney = bullet.GetBulletMoney();
    dianCiCannon->m_iMaxWinMoney = pPlayer->GetMaxWinMoney();
    dianCiCannon->m_uTotalScore  = 0;

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Create NFDianCiCannon:{} Success...........", id);

    return dianCiCannon;
}

int NFFishTypeDianCiCannon::OnHandleDianCiCannonAim(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::DianCiCannonAimReq dianCiCannonAimReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, dianCiCannonAimReq);

    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);

    NFDianCiCannon* pCiCannon = GetDianCiCannon(dianCiCannonAimReq.usdiancicannonid());
    if (pCiCannon)
    {
        pCiCannon->m_uAngle = dianCiCannonAimReq.usangle();
    }

    gamefish::DianCiCannonAimRsp dianCiCannonRsp;
    dianCiCannonRsp.set_uschairid(pPlayer->GetChairIdForClient());
    dianCiCannonRsp.set_usdiancicannonid(dianCiCannonAimReq.usdiancicannonid());
    dianCiCannonRsp.set_usangle(dianCiCannonAimReq.usangle());

    pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONAIM_RSP, dianCiCannonRsp);

    return 0;
}

int NFFishTypeDianCiCannon::OnHandleDianCiCannonShoot(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::DianCiCannonShootReq dianCiCannonShootReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, dianCiCannonShootReq);

    CHECK_NULL(pPlayer);
    auto pDesk = pPlayer->GetDesk();
    CHECK_NULL(pDesk);

    NFDianCiCannon* pDianCiCannon = GetDianCiCannon(dianCiCannonShootReq.usdiancicannonid());
    if (pDianCiCannon)
    {
        if (pDianCiCannon->m_ullPlayerId != pPlayer->m_ullPlayerId)
        {
            return 1;
        }

        pDianCiCannon->DeleteAllTimer();
        pDianCiCannon->m_uStatus = eDianCiConnonSts_Shoot;
        pDianCiCannon->m_uStatusTimeStart = NFTime::Now().UnixMSec();
        pDianCiCannon->SetTimer(3150, 1, 0, 0, 0, 3150);//3.15s
        //////////////////////////////////////////////////////////////////////////

        gamefish::DianCiCannonShootRsp dianCiCannonShootRsp;
        dianCiCannonShootRsp.set_uschairid(pPlayer->GetChairIdForClient());
        dianCiCannonShootRsp.set_usdiancicannonid(dianCiCannonShootReq.usdiancicannonid());
        dianCiCannonShootRsp.set_usangle(dianCiCannonShootReq.usangle());

        dianCiCannonShootRsp.set_usprocuserchairid(-1);

        pDesk->SendMsgToAllClient(NF_FISH_CMD_DIANCICANNONSHOOT_RSP, dianCiCannonShootRsp);
    }

    return 0;
}

int NFFishTypeDianCiCannon::OnHandleDianCiCannonHitFish(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::DianCiCannonHitFishReq dianCiCannonHitFishReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, dianCiCannonHitFishReq);

    CHECK_NULL(m_pDesk);
    auto pFishConfig = m_pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfig);
    int32_t iDianCiCammonId = dianCiCannonHitFishReq.usdiancicannonid();

    NFDianCiCannon* pDianCiCannon = GetDianCiCannon(iDianCiCammonId);
    if (pDianCiCannon == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> NFFishTypeDianCiCannon::OnHandleDianCiCannonHitFish() can't find dianCiCannon id = {}", iDianCiCammonId);
        return -1;
    }

    int iRobotChairId = dianCiCannonHitFishReq.usrobotchairid();
    if (iRobotChairId > 0)
    {
        pPlayer = m_pDesk->GetPlayerByChairId(iRobotChairId - 1);
        CHECK_EXPR(pPlayer, -1, "pPlayer == NULL for Robot !");
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "iRobotChairId = {} => ", iRobotChairId, iRobotChairId - 1);
    }


    if (pDianCiCannon->m_uChairId != pPlayer->GetChairIdForClient())
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> NFFishTypeDianCiCannon::OnHandleDianCiCannonHitFish() ===============> !!!!!!!!!!!!!!!!!!!!1");
        return -11;
    }

    gamefish::KillFishRsp gcKillFish;
    gcKillFish.set_bulletid(0);
    gcKillFish.set_bombuid(0);
    gcKillFish.set_mainfishuid(pDianCiCannon->m_bombFish.m_uFishId);
    gcKillFish.set_mainfishid(pDianCiCannon->m_bombFish.m_nFishKind);
    gcKillFish.set_mainfishtype(pDianCiCannon->m_bombFish.m_fishKind.m_btFishType);
    gcKillFish.set_mainmultiple(pDianCiCannon->m_bombFish.GetBaseMul());
    gcKillFish.set_mainscore(0);//bomb is no scored
    gcKillFish.set_totalscore(0);//the value will be set below
    gcKillFish.set_totalratio(0);//the value will be set below
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);
    gcKillFish.set_subfishcount(0);

    int subFishCount = dianCiCannonHitFishReq.subfishes_size();
    bool bIsHasSubFish = false;

    int iKilledSubFishCount = 0;
    int32_t iTotalScore = 0;
    for (int i=0; i<subFishCount; i++)
    {
        int32_t fishId = dianCiCannonHitFishReq.subfishes(i);

        NFGameFish* pFish = m_pDesk->GetFish(fishId);
        if ((pFish != NULL) && (pFish->IsKilled()==false) && (pFish->m_fishKind.m_btFishType == 1))
        {
            int iRand = NFRandomInt(0, 100);

            if (iRand < 80)//30%kill
            {
                continue;
            }

            uint32_t iMul = pFish->GetBaseMul() * pDianCiCannon->m_iBulletMul;
            uint32_t iScore = pDianCiCannon->m_iBulletMoney * iMul;
            int iMyMaxWinMoney = pDianCiCannon->MyMaxWinMoney();

            if (pDianCiCannon->m_uTotalScore + iScore > (uint32_t)pDianCiCannon->m_iMaxWinMoney
                || (pDianCiCannon->m_uTotalScore + iScore > (uint32_t)iMyMaxWinMoney)
                || (!pDianCiCannon->m_bombFish.IsCanKill(pFishConfig, pFish->m_nFishKind)))
            {
                break;
            }

            //////////////////////////////////////////////////////////////////////////
            //perhaps we can set a ratio for each fish kill;
            pFish->Kill(); //need to check maxWinMoney
            pDianCiCannon->m_uTotalScore += iScore;
            iTotalScore += iScore;

            iKilledSubFishCount++;

            //////////////////////////////////////////////////////////////////////////

            gamefish::KillFishRsp* pSubFish = gcKillFish.add_subfishes();
            pSubFish->set_bombuid(pDianCiCannon->m_bombFish.m_uFishId);
            pSubFish->set_mainfishuid(pFish->m_uFishId);
            pSubFish->set_mainfishid(pFish->m_nFishKind);
            pSubFish->set_mainfishtype(pFish->m_fishKind.m_btFishType);
            pSubFish->set_mainmultiple(iMul);
            pSubFish->set_mainscore(iScore);
            pSubFish->set_chairid(pPlayer->GetChairIdForClient());
            pSubFish->set_userrorcode(0);
            pSubFish->set_bombfishid(pDianCiCannon->m_bombFish.m_nFishKind);

            bIsHasSubFish = true;
            //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeDianCiCannon::OnHandleDianCiCannonHitFish() add fishId = {}", fishId);
        }
        else
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeDianCiCannon::OnHandleDianCiCannonHitFish() Can't find fishId = {}", fishId);
        }
    }

    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / pDianCiCannon->m_iBulletMoney);
    gcKillFish.set_subfishcount(iKilledSubFishCount);

    if (bIsHasSubFish)
    {
        m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);
        pPlayer->AddCaptureMoney(iTotalScore);
    }

    return 0;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeZuanTou.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeZuanTou
//
// -------------------------------------------------------------------------

#include "NFFishTypeZuanTou.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"
#include "Player/NFGameFishPlayer.h"
#include "Fish/NFGameFish.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeZuanTou, EOT_GAME_FISH_TYPE_HANDLE_ZUANTOU_ID, NFFishTypeHandler)

NFFishTypeZuanTou::NFFishTypeZuanTou()
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

NFFishTypeZuanTou::~NFFishTypeZuanTou()
{
}

int NFFishTypeZuanTou::CreateInit()
{
    return 0;
}

int NFFishTypeZuanTou::ResumeInit()
{
    return 0;
}

int NFFishTypeZuanTou::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    NFZuanTou* pZuanTou = CreateZuanTou(pPlayer, pFish, bullet);
    CHECK_EXPR(pZuanTou, -1, "CreateZuanTou Failed!");

    int iMainMul   = NFFishTypeHandler::GetKilledFishMul(pFish, bullet);
    int iMainScore = bullet.GetBulletMoney() * bullet.GetBulletMul() * iMainMul;

    pZuanTou->m_uTotalScore = iMainScore;

    gamefish::CreateZuanTouRsp createZuanTouRsp;
    createZuanTouRsp.set_uschairid(pZuanTou->m_uChairId);
    createZuanTouRsp.set_uszuantouid(pZuanTou->m_uId);
    createZuanTouRsp.set_uskilledfishid(pFish->m_uFishId);
    createZuanTouRsp.set_ustraceid(0);
    createZuanTouRsp.set_ustracestartpt(0);
    createZuanTouRsp.set_uszuantoustatus(eZuanTouSts_Aim);
    createZuanTouRsp.set_uszuantoustatustime(0);
    createZuanTouRsp.set_bombfishid(pZuanTou->m_bombFish.m_nFishKind);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEZUANTOU_RSP, createZuanTouRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnKilllingFish() zuanTou.uId = {}", pZuanTou->m_uId);

    return 0;
}

int NFFishTypeZuanTou::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeZuanTou::OnHandleClientMessage(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    switch (packet.nMsgId)
    {
        case NF_FISH_CMD_ZUANTOUAIM_REQ:
            OnHandleZuanTouAim(pPlayer, packet);
            return 1;
        case NF_FISH_CMD_ZUANTOUSHOOT_REQ:
            OnHandleZuanTouShoot(pPlayer, packet);
            return 1;
        case NF_FISH_CMD_ZUANTOUHITFISH_REQ:
            OnHandleZuanTouHitFish(pPlayer, packet);
            return 1;
        default:
            return 0;
    }
}

int NFFishTypeZuanTou::SyncFishBomb(NFGameFishPlayer *pPlayer)
{
    for (auto iter = m_mapZuanTou.begin(); iter != m_mapZuanTou.end();iter++)
    {
        NFZuanTou* pZuanTou = &iter->second;
        if (pZuanTou != NULL)
        {
            int64_t statusTime = NFGetTime() - pZuanTou->m_uStatusTimeStart;
            int32_t startPoint = pZuanTou->m_uTraceStartPt + statusTime / 100;

            if (pZuanTou->m_uStatus == eZuanTouSts_Aim)
            {
                startPoint = 0;
            }

            gamefish::CreateZuanTouRsp createZuanTouRsp;
            createZuanTouRsp.set_uschairid(pZuanTou->m_uChairId);
            createZuanTouRsp.set_uszuantouid(pZuanTou->m_uId);
            createZuanTouRsp.set_uskilledfishid(pZuanTou->m_bombFish.m_uFishId);
            createZuanTouRsp.set_ustraceid(pZuanTou->m_uTraceId);
            createZuanTouRsp.set_ustracestartpt(startPoint);
            createZuanTouRsp.set_uszuantoustatus(pZuanTou->m_uStatus);
            createZuanTouRsp.set_uszuantoustatustime(statusTime);
            createZuanTouRsp.set_bombfishid(pZuanTou->m_bombFish.m_nFishKind);

            gamefish::ZuanTouAimRsp zuanTouAimRsp;
            zuanTouAimRsp.set_uschairid(pZuanTou->m_uChairId);
            zuanTouAimRsp.set_uszuantouid(pZuanTou->m_uId);
            zuanTouAimRsp.set_usangle(pZuanTou->m_iAngle);

            if (pZuanTou->m_ullPlayerId == pPlayer->m_ullPlayerId)
            {
                pZuanTou->m_uChairId = pPlayer->GetChairIdForClient();//自己有可能换了座位!!!
                createZuanTouRsp.set_uschairid(pZuanTou->m_uChairId);

                //主人进入，发给所有人
                m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATEZUANTOU_RSP, createZuanTouRsp);
                m_pDesk->SendMsgToAllClient(NF_FISH_CMD_ZUANTOUAIM_RSP, zuanTouAimRsp);
            }
            else
            {
                NFGameFishPlayer* pPlayerOwner = m_pDesk->GetPlayer(pZuanTou->m_ullPlayerId);
                if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
                {//别人进入，主人在线，只发给别人自己
                    m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEZUANTOU_RSP, createZuanTouRsp, pPlayer->m_ullPlayerId);
                    m_pDesk->SendMsgToClient(NF_FISH_CMD_ZUANTOUAIM_RSP, zuanTouAimRsp, pPlayer->m_ullPlayerId);
                }
                else
                {
                    //主人不在线，已经发射,只发给自己
                    if (pZuanTou->m_uStatus > eZuanTouSts_Aim)
                    {
                        m_pDesk->SendMsgToClient(NF_FISH_CMD_CREATEZUANTOU_RSP, createZuanTouRsp, pPlayer->m_ullPlayerId);
                        m_pDesk->SendMsgToClient(NF_FISH_CMD_ZUANTOUAIM_RSP, zuanTouAimRsp, pPlayer->m_ullPlayerId);
                    }
                }
            }

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeZuanTou::SyncFishBomb() ===============> NFGetTime() = {} , m_uStatusTimeStart = {} , statusTime = {} , m_uStatus = {}", NFGetTime(), pZuanTou->m_uStatusTimeStart, statusTime, pZuanTou->m_uStatus);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "NFFishTypeZuanTou::SyncFishBomb() ===============> pZuanTou->m_uChairId = {} , m_uTraceId = {}, startPoint = {}", pZuanTou->m_uChairId, pZuanTou->m_uTraceId , startPoint);
        }
    }
    return 0;
}

NFZuanTou *NFFishTypeZuanTou::CreateZuanTou(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish, const NFFishBullet &bullet)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();
    CHECK_EXPR(m_mapZuanTou.size() < m_mapZuanTou.max_size(), NULL, "m_mapZuanTou space not enough");

    NFZuanTou* pZuanTou = &m_mapZuanTou[id];
    CHECK_EXPR(pZuanTou, NULL, "m_mapZuanTou.Insert id:{} Failed!", id);

    pZuanTou->InitShmObj(this);
    pZuanTou->m_uId = id;
    pZuanTou->m_uChairId = pPlayer->GetChairIdForClient();
    pZuanTou->m_ullPlayerId = pPlayer->m_ullPlayerId;
    pZuanTou->m_bombFish  = *pBombFish;
    pZuanTou->m_uBornTime = NFGetTime();
    //zuanTou.uTraceId = uTraceId;
    pZuanTou->m_uTraceStartPt = 0;
    pZuanTou->m_uStatus = eZuanTouSts_Aim;//瞄准状态
    pZuanTou->m_uStatusTimeStart = NFGetTime();
    pZuanTou->m_uStatusTimerId = pZuanTou->SetTimer(32000, 1, 0, 0, 0, 32000);
    pZuanTou->m_iBulletMul     = bullet.GetBulletMul();
    pZuanTou->m_iBulletMoney   = bullet.GetBulletMoney();
    pZuanTou->m_iMaxWinMoney   = pPlayer->GetMaxWinMoney();
    pZuanTou->m_uTotalScore    = 0;

    return pZuanTou;
}

int NFFishTypeZuanTou::OnHandleZuanTouAim(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::ZuanTouAimReq zuanTouAimReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, zuanTouAimReq);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouAim()");

    NFZuanTou* pZuanTou = GetZuanTou(zuanTouAimReq.uszuantouid());
    if (pZuanTou == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouAim() Can't find zuanTouAimReq.uszuantouid() = {}", zuanTouAimReq.uszuantouid());
        return 0;
    }

    if (pZuanTou->m_ullPlayerId != pPlayer->m_ullPlayerId)
    {
        return -1;
    }

    pZuanTou->m_uChairId = pPlayer->GetChairIdForClient();
    pZuanTou->m_iAngle   = zuanTouAimReq.usangle();

    gamefish::ZuanTouAimRsp zuanTouAimRsp;
    zuanTouAimRsp.set_uschairid(pZuanTou->m_uChairId);
    zuanTouAimRsp.set_uszuantouid(pZuanTou->m_uId);
    zuanTouAimRsp.set_usangle(pZuanTou->m_iAngle);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_ZUANTOUAIM_RSP, zuanTouAimRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouAim() NF_FISH_CMD_ZUANTOUAIM_RSP uszuantouid = {} , pZuanTou->m_iAngle = {}", zuanTouAimReq.uszuantouid(), pZuanTou->m_iAngle);

    return 0;
}

int NFFishTypeZuanTou::OnHandleZuanTouShoot(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouShoot()");

    gamefish::ZuanTouShootReq zuanTouShootReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, zuanTouShootReq);

    NFFishSettingConfig* pSettingConfig = m_pDesk->GetFishSettingConfig();
    CHECK_NULL(pSettingConfig);

    NFZuanTou* pZuanTou = GetZuanTou(zuanTouShootReq.uszuantouid());
    if (pZuanTou == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouShoot() Can't find zuanTouShootReq.uszuantouid() = {}", zuanTouShootReq.uszuantouid());
        return 0;
    }

    if (pZuanTou->m_ullPlayerId != pPlayer->m_ullPlayerId)
    {
        return 1;
    }

    pZuanTou->m_uChairId = pPlayer->GetChairIdForClient();

    pZuanTou->DeleteTimer(pZuanTou->m_uStatusTimerId);
    pZuanTou->m_uStatusTimerId = INVALID_ID;

    //pZuanTou->m_iAngle = zuanTouShootReq.usangle();

    pZuanTou->m_uStatus = eZuanTouSts_Shoot;
    pZuanTou->m_uStatusTimeStart = NFGetTime();
    pZuanTou->m_uStatusTimerId = pZuanTou->SetTimer(12000, 1, 0, 0, 0, 12000);

    //////////////////////////////////////////////////////////////////////////

    int realAngle = pZuanTou->m_iAngle / 10000;

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleZuanTouShoot() realAngle111 = {}", realAngle);

    if (realAngle < 180)
    {
        realAngle += 360;
    }

    realAngle -= 270;

    int angleIndex = realAngle / 15 ;

    if (angleIndex > 10)
    {
        angleIndex = 10;
    }

    pZuanTou->m_uTraceId = pSettingConfig->GetShootTrace(pZuanTou->m_uChairId, angleIndex);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleZuanTouShoot() m_uChairId={} , m_iAngle = {} , realAngle = {} , angleIndex = {} , traceId = {}", pZuanTou->m_uChairId, pZuanTou->m_iAngle, realAngle, angleIndex, pZuanTou->m_uTraceId);
    //////////////////////////////////////////////////////////////////////////

    gamefish::ZuanTouShootRsp zuanTouShootRsp;
    zuanTouShootRsp.set_uschairid(pZuanTou->m_uChairId);
    zuanTouShootRsp.set_uszuantouid(pZuanTou->m_uId);
    zuanTouShootRsp.set_usangle(pZuanTou->m_iAngle);

    zuanTouShootRsp.set_ustraceid(pZuanTou->m_uTraceId);
    zuanTouShootRsp.set_ustracestartpt(pZuanTou->m_uTraceStartPt);

    if (pPlayer->m_isRobot)
    {
        int realPlayerChairId = pPlayer->GetRealPlayerChairIdForRobot();
        zuanTouShootRsp.set_usprocuserchairid(realPlayerChairId+1);
    }
    else
    {
        zuanTouShootRsp.set_usprocuserchairid(-1);
    }

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_ZUANTOUSHOOT_RSP, zuanTouShootRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouShoot()");
    return 0;
}

int NFFishTypeZuanTou::OnHandleZuanTouHitFish(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::ZuanTouHitFishReq zuanTouHitFishReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, zuanTouHitFishReq);

    NFFishConfigConfig *pFishConfigDesc = m_pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfigDesc);

    NFZuanTou* pZuanTou = GetZuanTou(zuanTouHitFishReq.uszuantouid());
    if (pZuanTou == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> NFFishTypeZuanTou::OnHandleZuanTouHitFish() can't find zuanTouHitFishReq.uszuantouid() = {}", zuanTouHitFishReq.uszuantouid());
        return 0;
    }

    int iRobotChairId = zuanTouHitFishReq.usrobotchairid();
    if (iRobotChairId > 0)
    {
        pPlayer = m_pDesk->GetPlayerByChairId(iRobotChairId - 1);
        CHECK_EXPR(pPlayer, -1, "pPlayer == NULL for Robot !");

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "iRobotChairId = {} => ", iRobotChairId, iRobotChairId - 1);
    }


    if (pZuanTou->m_ullPlayerId != pPlayer->m_ullPlayerId)
    {
        return 1;
    }

    pZuanTou->m_uChairId = pPlayer->GetChairIdForClient();

    gamefish::KillFishRsp gcKillFish;
    gcKillFish.set_bulletid(0);
    gcKillFish.set_bombuid(0);
    gcKillFish.set_mainfishuid(pZuanTou->m_bombFish.m_uFishId);
    gcKillFish.set_mainfishid(pZuanTou->m_bombFish.m_nFishKind);
    gcKillFish.set_mainfishtype(pZuanTou->m_bombFish.m_fishKind.m_btFishType);
    gcKillFish.set_mainmultiple(pZuanTou->m_bombFish.GetBaseMul());
    gcKillFish.set_mainscore(0);//bomb is no scored
    gcKillFish.set_totalscore(0);
    gcKillFish.set_totalratio(0);
    gcKillFish.set_chairid(pZuanTou->m_uId); //the same as: pPlayer->GetChairIdForClient();
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    int count = zuanTouHitFishReq.subfishes_size();
    gcKillFish.set_subfishcount(count);

    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==========> NFFishTypeZuanTou::OnHandleZuanTouHitFish() count = {}", count);

    int iSubFishCount = 0;
    int32_t iTotalScore = 0;
    for (int i = 0; i < count; i++)
    {
        int32_t fishId = zuanTouHitFishReq.subfishes(i);

        int iRand = NFRandomInt(0, 100);
        if (iRand < 95)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "iRand = {} => continue !", iRand);
            continue;
        }

        NFGameFish* pSubFish = m_pDesk->GetFish(fishId);
        if ((pSubFish != NULL) && (pSubFish->IsKilled() == false) && (pSubFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 : 先不弄死特殊鱼
        {
            uint32_t iMul   = pSubFish->GetBaseMul() * pZuanTou->m_iBulletMul;
            uint32_t iScore = pZuanTou->m_iBulletMoney * iMul;

            if (pZuanTou->m_uTotalScore + iScore > (uint32_t)pZuanTou->m_iMaxWinMoney
                || pZuanTou->m_uTotalScore + iScore > pZuanTou->MyMaxWinMoney()
                ||(!pZuanTou->m_bombFish.IsCanKill(pFishConfigDesc, pSubFish->m_nFishKind)))
            {
                //if (pZuanTou->m_uTotalScore + iScore > pZuanTou->m_iMaxWinMoney)
                //{
                //	NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! pZuanTou->m_uTotalScore + iScore > pZuanTou->m_iMaxWinMoney ! {} + {} > {} !", pZuanTou->m_uTotalScore, iScore, pZuanTou->m_iMaxWinMoney);
                //}

                //if (pZuanTou->m_uTotalScore + iScore > pZuanTou->MyMaxWinMoney())
                //{
                //	NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! pZuanTou->m_uTotalScore + iScore > pZuanTou->m_iMaxWinMoney ! {} + {} > {} !", pZuanTou->m_uTotalScore, iScore, pZuanTou->MyMaxWinMoney());
                //}

                //if ((!pZuanTou->m_bombFish.IsCanKill(pSubFish->m_nFishKind)))
                //{
                //	NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==>Normal ! IsCanKill == false pSubFish->m_nFishKind = {}", pSubFish->m_nFishKind);
                //}

                break;
            }

            pSubFish->Kill();

            iTotalScore += iScore;
            pZuanTou->m_uTotalScore += iScore;

            gamefish::KillFishRsp* pKillFish = gcKillFish.add_subfishes();
            pKillFish->set_bombuid(pZuanTou->m_bombFish.m_uFishId);
            pKillFish->set_mainfishuid(pSubFish->m_uFishId);
            pKillFish->set_mainfishid(pSubFish->m_nFishKind);
            pKillFish->set_mainfishtype(pSubFish->m_fishKind.m_btFishType);
            pKillFish->set_mainmultiple(pSubFish->GetBaseMul());
            pKillFish->set_mainscore(iScore);
            pKillFish->set_chairid(pPlayer->GetChairIdForClient());
            pKillFish->set_userrorcode(0);
            pKillFish->set_bombfishid(pZuanTou->m_bombFish.m_nFishKind);

            iSubFishCount++;
        }
        else
        {
            //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleZuanTouHitFish() Can't find fishId = {}", fishId);
        }
    }

    gcKillFish.set_subfishcount(iSubFishCount);
    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / pZuanTou->m_iBulletMoney);

    if (iSubFishCount > 0)
    {
        m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleZuanTouHitFish() NF_FISH_CMD_KILLFISH");
        pPlayer->AddCaptureMoney(iTotalScore);
    }

    return 1;
}

int NFFishTypeZuanTou::DeleteZuanTou(uint32_t id)
{
    auto iter = m_mapZuanTou.find(id);
    if (iter != m_mapZuanTou.end())
    {
        m_mapZuanTou.erase(id);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete ZuanTou:{} Success", id);
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete ZuanTou:{} Failed, not exist", id);
    }
    return 0;
}

NFZuanTou *NFFishTypeZuanTou::GetZuanTou(uint32_t id)
{
    auto iter = m_mapZuanTou.find(id);
    if (iter != m_mapZuanTou.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFZuanTou::OnTimer(int timeId, int callcount)
{
    auto pDesk = GetDesk();
    CHECK_NULL(pDesk);
    NFFishTypeZuanTou* pFishTypeHandler = dynamic_cast<NFFishTypeZuanTou*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeHandler);
    NFFishConfigConfig* pFishConfig = pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfig);
    NFFishSettingConfig* pFishSetting = pDesk->GetFishSettingConfig();
    CHECK_NULL(pFishSetting);
    
    if (m_uStatusTimerId == timeId)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() m_uStatus = {}", m_uStatus);

        DeleteTimer(m_uStatusTimerId);
        m_uStatusTimerId = INVALID_ID;

        if (m_uStatus == eZuanTouSts_Aim)
        {
            NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(m_ullPlayerId);

            if (pPlayerOwner != NULL && pPlayerOwner->m_ready)
            {
                //自动发射/Auto shoot
                m_uStatus = eZuanTouSts_Shoot;//发射状态
                m_uStatusTimeStart = NFGetTime();
                m_uStatusTimerId = SetTimer(12000, 1, 0, 0, 0, 12000);

                //////////////////////////////////////////////////////////////////////////
                int angleIndex = (m_iAngle + 90 + 30) / 15;
                uint32_t traceId = pFishSetting->GetShootTrace(m_uChairId, angleIndex);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() m_iAngle = {} , angleIndex = {} , traceId = {}", m_iAngle, angleIndex, traceId);
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() -- SetTimer(12000)");

                //////////////////////////////////////////////////////////////////////////

                gamefish::ZuanTouShootRsp zuanTouShootRsp;
                zuanTouShootRsp.set_uschairid(m_uChairId);//这个创建时已经是ChairIdForClient
                zuanTouShootRsp.set_uszuantouid(m_uId);
                zuanTouShootRsp.set_usangle(0);//这个应该用不着
                zuanTouShootRsp.set_ustraceid(traceId);//根据座位号和角度取一个合适的碰撞轨迹
                zuanTouShootRsp.set_ustracestartpt(0);

                pDesk->SendMsgToAllClient(NF_FISH_CMD_ZUANTOUSHOOT_RSP, zuanTouShootRsp);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() uStatus ==> 2");
            }
            else
            {
                //m_pFishTypeObj->m_mapZuanTou.Erase(m_uId);
                pFishTypeHandler->DeleteZuanTou(m_uId);
            }
        }
        else if (m_uStatus == eZuanTouSts_Shoot)
        {
            //爆炸/bomb
            NFGameFishPlayer* pPlayerOwner = pDesk->GetPlayer(m_ullPlayerId);

            if (pPlayerOwner !=NULL /*&& pPlayerOwner->m_ready*/)
            {
                int index = (NFTime::Now().UnixMSec() - m_uBornTime) / 100;
                CHMPoint point = pDesk->GetPointByIndex(m_uTraceId, index);
                std::vector<NFGameFish*> vecFishes = pDesk->GetFishes(point, 300, 50);

                uint32_t uMyMaxWinMoney = MyMaxWinMoney();
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() uStatus ==> 2 vecFishes.size() = {} , uMyMaxWinMoney = {}", vecFishes.size(), uMyMaxWinMoney);

                gamefish::KillFishRsp gcKillFish;
                gcKillFish.set_bulletid(0);
                gcKillFish.set_bombuid(0);
                gcKillFish.set_mainfishuid(m_bombFish.m_uFishId);
                gcKillFish.set_mainfishid(m_bombFish.m_nFishKind);
                gcKillFish.set_mainfishtype(m_bombFish.m_fishKind.m_btFishType);
                gcKillFish.set_mainmultiple(m_bombFish.m_fishKind.m_nBaseMul);
                gcKillFish.set_mainscore(0);//bomb is no scored
                gcKillFish.set_totalscore(0);
                gcKillFish.set_totalratio(0);
                gcKillFish.set_chairid(m_uChairId);
                gcKillFish.set_userrorcode(0);
                gcKillFish.set_subfishcount(0);
                gcKillFish.set_bombfishid(0);

                int iSubFishCount = 0;
                int iTotalScore = 0;
                std::vector<NFGameFish*>::iterator iterFish = vecFishes.begin();
                for (; iterFish != vecFishes.end(); iterFish++)
                {
                    NFGameFish* pFish = *iterFish;
                    if ((pFish != NULL) && (pFish->IsKilled() == false) && (pFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 : 先不弄死特殊鱼
                    {
                        uint32_t iMul = pFish->GetBaseMul() * m_iBulletMul;
                        uint32_t iScore = m_iBulletMoney * iMul;

                        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> m_uTotalScore + iScore = {} , m_iMaxWinMoney = {} , uMyMaxWinMoney = {}", m_uTotalScore + iScore, m_iMaxWinMoney, uMyMaxWinMoney);

                        if (m_uTotalScore + iScore > (uint32_t)m_iMaxWinMoney
                            || m_uTotalScore + iScore > uMyMaxWinMoney
                            || (!m_bombFish.IsCanKill(pFishConfig, pFish->m_nFishKind)))
                        {
                            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> Break !!!!!!!!!!!!");
                            break;
                        }

                        pFish->Kill();
                        m_uTotalScore += iScore;
                        iTotalScore += iScore;

                        gamefish::KillFishRsp* pSubFish = gcKillFish.add_subfishes();
                        pSubFish->set_bombuid(m_bombFish.m_uFishId);
                        pSubFish->set_mainfishuid(pFish->m_uFishId);
                        pSubFish->set_mainfishid(pFish->m_nFishKind);
                        pSubFish->set_mainfishtype(pFish->m_fishKind.m_btFishType);
                        pSubFish->set_mainmultiple(iMul);
                        pSubFish->set_mainscore(iScore);
                        pSubFish->set_chairid(m_uChairId);
                        pSubFish->set_userrorcode(0);
                        pSubFish->set_bombfishid(m_bombFish.m_nFishKind);

                        iSubFishCount++;

                        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() set_bombuid pZuanTou->bombFish.m_uFishId = {}", m_bombFish.m_uFishId);
                    }
                }

                gcKillFish.set_subfishcount(iSubFishCount);
                gcKillFish.set_totalscore(iTotalScore);
                gcKillFish.set_totalratio(iTotalScore / m_iBulletMoney);

                if (iSubFishCount > 0)
                {
                    pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() zuanTouBomb NF_FISH_CMD_KILLFISH");
                    pPlayerOwner->AddCaptureMoney(iTotalScore);
                }
            }

            //////////////////////////////////////////////////////////////////////////

            //总跑分框里要包括主鱼分数
            //m_uTotalScore -= m_bombFish.GetBaseMul() * m_iBulletMoney * m_iBulletMul;

            gamefish::ZuanTouBombRsp zuanTouBombRsp;
            zuanTouBombRsp.set_uschairid(m_uChairId);
            zuanTouBombRsp.set_uszuantouid(m_uId);
            zuanTouBombRsp.set_ustotalscore(m_uTotalScore);
            zuanTouBombRsp.set_ustotalmul(m_uTotalScore/m_iBulletMoney);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_ZUANTOUBOMB_RSP, zuanTouBombRsp);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnTimer() NF_FISH_CMD_ZUANTOUBOMB_RSP");

            pFishTypeHandler->DeleteZuanTou(m_uId);
        }
    }
    return 0;
}

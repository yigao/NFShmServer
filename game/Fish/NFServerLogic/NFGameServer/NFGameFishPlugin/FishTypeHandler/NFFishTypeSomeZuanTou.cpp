// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSomeZuanTou.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSomeZuanTou
//
// -------------------------------------------------------------------------

#include "NFFishTypeSomeZuanTou.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"
#include "Player/NFGameFishPlayer.h"
#include "Fish/NFGameFish.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeSomeZuanTou, EOT_GAME_FISH_TYPE_HANDLE_SOME_ZUANTOU_ID, NFFishTypeHandler)

NFFishTypeSomeZuanTou::NFFishTypeSomeZuanTou()
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

NFFishTypeSomeZuanTou::~NFFishTypeSomeZuanTou()
{
}

int NFFishTypeSomeZuanTou::CreateInit()
{
    return 0;
}

int NFFishTypeSomeZuanTou::ResumeInit()
{
    return 0;
}

int NFFishTypeSomeZuanTou::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    SomeZuanTouGroup* someZuanTouGroup = CreateSomeZuanTouGroup(pPlayer, pFish);
    CHECK_EXPR(someZuanTouGroup, 1, "CreateSomeZuanTouGroup Failed");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou->CreateSomeZuanTouGroup() someZuanTouGroup.uStatusTimerId = {}", someZuanTouGroup->uStatusTimerId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou->CreateSomeZuanTouGroup() someZuanTouGroup.uId = {}", someZuanTouGroup->uId);


    gamefish::CreateSomeZuanTouRsp createSomeZuanTouRsp;
    createSomeZuanTouRsp.set_uschairid(someZuanTouGroup->uChairId);
    createSomeZuanTouRsp.set_ussomezuantouid(someZuanTouGroup->uId);
    createSomeZuanTouRsp.set_uskilledfishid(someZuanTouGroup->bombFish.m_uFishId);
    createSomeZuanTouRsp.set_uszuantoustatus(1);
    createSomeZuanTouRsp.set_uszuantoustatustime(0);


    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_CREATESOMEZUANTOU_RSP, createSomeZuanTouRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnKilllingFish() NF_FISH_CMD_CREATESOMEZUANTOU_RSP someZuanTouGroup.uId = {}", someZuanTouGroup->uId);

    return 0;
}

int NFFishTypeSomeZuanTou::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeSomeZuanTou::OnHandleClientMessage(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    switch (packet.nMsgId)
    {
        case NF_FISH_CMD_SOMEZUANTOUHITFISH_REQ:
            OnHandleSomeZuanTouHitFish(pPlayer, packet);
            return 1;

        default:
            return 0;
    }
}

SomeZuanTouGroup *NFFishTypeSomeZuanTou::CreateSomeZuanTouGroup(NFGameFishPlayer *pPlayer, NFGameFish *pBombFish)
{
    uint32_t id = FindModule<NFISharedMemModule>()->Get32UUID();
    CHECK_EXPR(m_mapSomeZuanTouGroups.size() < m_mapSomeZuanTouGroups.max_size(), NULL, "m_mapSomeZuanTouGroups space not enough");

    SomeZuanTouGroup* someZuanTouGroup = &m_mapSomeZuanTouGroups[id];
    CHECK_EXPR(someZuanTouGroup, NULL, "m_mapSomeZuanTouGroups Insert Failed! id:{}", id);

    someZuanTouGroup->InitShmObj(this);
    someZuanTouGroup->uId         = id;
    someZuanTouGroup->uChairId    = pPlayer->GetChairIdForClient();
    someZuanTouGroup->ullPlayerId = pPlayer->m_ullPlayerId;
    someZuanTouGroup->bombFish    = *pBombFish;
    someZuanTouGroup->uBornTime   = NFGetTime();
    someZuanTouGroup->uStatus     = 1;
    someZuanTouGroup->uStatusTimeStart = NFGetTime();
    someZuanTouGroup->uStatusTimerId   = someZuanTouGroup->SetTimer(4000, 1, 0, 0, 0, 4000);
    someZuanTouGroup->uShootTimerId    = 0;
    someZuanTouGroup->uShootCount      = 0;
    someZuanTouGroup->uTotalScore      = 0;
    someZuanTouGroup->iBulletMoney     = m_pDesk->GetCannonValue(pPlayer->m_nCurBulletLevel);

    return someZuanTouGroup;
}

int NFFishTypeSomeZuanTou::OnHandleSomeZuanTouHitFish(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    gamefish::SomeZuanTouHitFishReq someZuanTouHitFishReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, someZuanTouHitFishReq);

    SomeZuanTouGroup*  someZuanTouGroup = GetSomeZuanTouGroup(someZuanTouHitFishReq.ussomezuantouid());
    if (someZuanTouGroup == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> NFFishTypeZuanTou::OnHandleSomeZuanTouHitFish() can't find someZuanTouHitFishReq.ussomezuantouid() = {}", someZuanTouHitFishReq.ussomezuantouid());
        return 0;
    }

    SomeZuanTouInfo* zuanTou = someZuanTouGroup->GetZuanTou(someZuanTouHitFishReq.uszuantouid());
    if (zuanTou == NULL || zuanTou->uId <= 0)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "==> NFFishTypeZuanTou::OnHandleSomeZuanTouHitFish() can't find someZuanTouHitFishReq.uszuantouid() = {}", someZuanTouHitFishReq.uszuantouid());
        return 0;
    }

    gamefish::KillFishRsp gcKillFish;
    gcKillFish.set_bulletid(0);
    gcKillFish.set_bombuid(0);
    gcKillFish.set_mainfishuid(someZuanTouGroup->bombFish.m_uFishId);
    gcKillFish.set_mainfishid(someZuanTouGroup->bombFish.m_nFishKind);
    gcKillFish.set_mainfishtype(someZuanTouGroup->bombFish.m_fishKind.m_btFishType);
    gcKillFish.set_mainmultiple(someZuanTouGroup->bombFish.m_fishKind.m_nBaseMul);
    gcKillFish.set_mainscore(0);//bomb is no scored
    gcKillFish.set_totalscore(0);
    gcKillFish.set_totalratio(0);
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_bombfishid(0);

    int count = someZuanTouHitFishReq.subfishes_size();
    gcKillFish.set_subfishcount(count);

    bool bIsHasSubFish = false;

    int32_t iTotalScore = 0;
    for (int i = 0; i < count; i++)
    {
        int32_t fishId = someZuanTouHitFishReq.subfishes(i);

        NFGameFish* pFish = m_pDesk->GetFish(fishId);
        if ((pFish != NULL) && (pFish->IsKilled() == false) && (pFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 先不打死特殊鱼
        {
            pFish->Kill(); //要实现连环死

            uint32_t iScore = someZuanTouGroup->iBulletMoney * pFish->m_fishKind.m_nBaseMul;
            iTotalScore += iScore;

            gamefish::KillFishRsp* pSubFish = gcKillFish.add_subfishes();
            pSubFish->set_bombuid(zuanTou->uId);
            pSubFish->set_mainfishuid(pFish->m_uFishId);
            pSubFish->set_mainfishid(pFish->m_nFishKind);
            pSubFish->set_mainfishtype(pFish->m_fishKind.m_btFishType);
            pSubFish->set_mainmultiple(pFish->m_fishKind.m_nBaseMul);
            pSubFish->set_mainscore(iScore);
            pSubFish->set_chairid(pPlayer->GetChairIdForClient());
            pSubFish->set_userrorcode(0);
            pSubFish->set_bombfishid(someZuanTouGroup->bombFish.m_nFishKind);

            bIsHasSubFish = true;
        }
        else
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleZuanTouHitFish() Can't find fishId = {}", fishId);
        }
    }

    gcKillFish.set_totalscore(iTotalScore);
    gcKillFish.set_totalratio(iTotalScore / someZuanTouGroup->iBulletMoney);

    someZuanTouGroup->uTotalScore += iTotalScore;

    if (bIsHasSubFish)
    {
        m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

        //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeZuanTou::OnHandleSomeZuanTouHitFish() NF_FISH_CMD_KILLFISH");
        pPlayer->AddCaptureMoney(iTotalScore);

    }

    return 0;
}

int NFFishTypeSomeZuanTou::DeleteSomeZuanTouGroup(uint32_t id)
{
    auto iter = m_mapSomeZuanTouGroups.find(id);
    if (iter != m_mapSomeZuanTouGroups.end())
    {
        m_mapSomeZuanTouGroups.erase(id);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete SomeZuanTouGroup:{} Success", id);
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete SomeZuanTouGroup:{} Failed, not exist", id);
    }
    return 0;
}

SomeZuanTouGroup *NFFishTypeSomeZuanTou::GetSomeZuanTouGroup(uint32_t id)
{
    auto iter = m_mapSomeZuanTouGroups.find(id);
    if (iter != m_mapSomeZuanTouGroups.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int SomeZuanTouGroup::OnTimer(int timeId, int callcount)
{
    auto pDesk = GetDesk();
    CHECK_NULL(pDesk);
    NFFishTypeSomeZuanTou* pFishTypeHandler = dynamic_cast<NFFishTypeSomeZuanTou*>(GetFishTypeHandler());
    CHECK_NULL(pFishTypeHandler);
    NFFishConfigConfig* pFishConfig = pDesk->GetFishConfigConfig();
    CHECK_NULL(pFishConfig);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> SomeZuanTouGroup::OnTimer() id = {}", uId);

    if (uStatus == 1)//待机
    {
        if (uStatusTimerId == timeId)//待机时间到
        {
            DeleteTimer(timeId);
            uStatusTimerId = INVALID_ID;

            uStatus = 2;
            uStatusTimeStart = NFGetTime();
            uStatusTimerId   = SetTimer(15000, 1, 0, 0, 0, 15000);

            uShootTimerId    = SetTimer(1000, 1, 0, 0, 0, 1000);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() 4s timer is overtime ! ");
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() uStatusTimerId = {}", uStatusTimerId);
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() uShootTimerId = {}", uShootTimerId);

            return 0;
        }
    }
    else if (uStatus == 2)//发射
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() iter->second.uShootTimerId = {}", uShootTimerId);

        if (uShootTimerId == timeId)//发射时间到
        {
            DeleteTimer(uShootTimerId);
            uShootTimerId = INVALID_ID;

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() uShootTimerId");

            if (uShootCount < 6)
            {
                SomeZuanTouInfo* someZuanTouInfo = ShootZuanTou();
                CHECK_EXPR(someZuanTouInfo, -1, "ShootZuanTou Failed!");

                gamefish::SomeZuanTouShootRsp someZuanTouShootRsp;
                someZuanTouShootRsp.set_uschairid(uChairId);
                someZuanTouShootRsp.set_ussomezuantouid(uId);

                //gamefish::SomeZuanTouInfo* pZuanTouInfo =  someZuanTouShootRsp.mutable_somezuantou();
                //pZuanTouInfo->set_uszuantouid(someZuanTouInfo.uZuanTouId);
                //pZuanTouInfo->set_usangle(someZuanTouInfo.uAngle);
                //pZuanTouInfo->set_ustraceid(someZuanTouInfo.uTraceId);
                //pZuanTouInfo->set_ustracestartpt(0);

                gamefish::SomeZuanTouInfo* pZuanTouInfo = someZuanTouShootRsp.mutable_somezuantou();
                pZuanTouInfo->set_uszuantouid(someZuanTouInfo->uId);
                pZuanTouInfo->set_usangle(someZuanTouInfo->uAngle);
                pZuanTouInfo->set_ustraceid(someZuanTouInfo->uTraceId);
                pZuanTouInfo->set_ustracestartpt(0);


                pDesk->SendMsgToAllClient(NF_FISH_CMD_SOMEZUANTOUSHOOT_RSP, someZuanTouShootRsp);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() liucan NF_FISH_CMD_SOMEZUANTOUSHOOT_RSP someZuanTouInfo.uZuanTouId = {}", uId);
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() liucan iter->second.uId = {} , uShootCount = {}", uId, uShootCount);

                uShootCount++;
            }

            if (uShootCount < 6)
            {
                //重复定时器不起作用，只能每次重新设置
                uShootTimerId = SetTimer(1000, 1, 0, 0, 0, 1000);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeSomeZuanTou::OnTimer() --> uShootTimerId = {}", uShootTimerId);
            }

            return 0;
        }
        else if (uStatusTimerId == timeId)//��ը��ʱ����
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeSomeZuanTou::OnTimer() uStatusTimerId == 15");

            DeleteTimer(uStatusTimerId);
            uStatusTimerId = INVALID_ID;

            //////////////////////////////////////////////////////////////////////////
            //��ը��������
            NFGameFishPlayer* pPlayer = pDesk->GetPlayer(ullPlayerId);
            CHECK_EXPR(pPlayer, -1, "Check pPlayer Failed! pPlayer == NULL");

            CHMPoint point(1560 / 2, 960 / 2);//Screen center
            std::vector<NFGameFish*> vecFishes = pDesk->GetFishes(point, 500, 100);

            gamefish::KillFishRsp gcKillFish;
            gcKillFish.set_bulletid(0);
            gcKillFish.set_bombuid(0);
            gcKillFish.set_mainfishuid(bombFish.m_uFishId);
            gcKillFish.set_mainfishid(bombFish.m_nFishKind);
            gcKillFish.set_mainfishtype(bombFish.m_fishKind.m_btFishType);
            gcKillFish.set_mainmultiple(bombFish.m_fishKind.m_nBaseMul);
            gcKillFish.set_mainscore(0);//bomb is no scored
            gcKillFish.set_totalscore(0);
            gcKillFish.set_totalratio(0);
            gcKillFish.set_chairid(uChairId);
            gcKillFish.set_userrorcode(0);
            gcKillFish.set_subfishcount(0);
            gcKillFish.set_bombfishid(0);

            int iSubFishCount = 0;
            int iTotalScore = 0;
            std::vector<NFGameFish*>::iterator iterFish = vecFishes.begin();
            for (; iterFish != vecFishes.end(); iterFish++)
            {
                NFGameFish* pFish = *iterFish;
                if ((pFish != NULL) && (pFish->IsKilled() == false) && (pFish->m_fishKind.m_btFishType == 1))//m_btFishType==1 : �Ȳ�Ū��������
                {
                    pFish->Kill();

                    uint32_t iScore = iBulletMoney * pFish->m_fishKind.m_nBaseMul;
                    iTotalScore += iScore;

                    gamefish::KillFishRsp* pSubFish = gcKillFish.add_subfishes();
                    pSubFish->set_bombuid(uId);
                    pSubFish->set_mainfishuid(pFish->m_uFishId);
                    pSubFish->set_mainfishid(pFish->m_nFishKind);
                    pSubFish->set_mainfishtype(pFish->m_fishKind.m_btFishType);
                    pSubFish->set_mainmultiple(pFish->m_fishKind.m_nBaseMul);
                    pSubFish->set_mainscore(iScore);
                    pSubFish->set_chairid(uChairId);
                    pSubFish->set_userrorcode(0);
                    pSubFish->set_bombfishid(bombFish.m_nFishKind);

                    iSubFishCount++;
                }
                else
                {
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeSomeZuanTou::OnTimer() 111111111111111111111111111");

                }
            }

            gcKillFish.set_subfishcount(iSubFishCount);
            gcKillFish.set_totalscore(iTotalScore);
            gcKillFish.set_totalratio(iTotalScore / iBulletMoney);

            uTotalScore += iTotalScore;

            //////////////////////////////////////////////////////////////////////////
            //爆炸
            gamefish::SomeZuanTouBombRsp someZuanTouBombRsp;
            someZuanTouBombRsp.set_uschairid(uChairId);
            someZuanTouBombRsp.set_ussomezuantouid(uId);
            someZuanTouBombRsp.set_ustotalscore(uTotalScore);
            someZuanTouBombRsp.set_ustotalmul(uTotalScore / iBulletMoney);

            pDesk->SendMsgToAllClient(NF_FISH_CMD_SOMEZUANTOBOMB_RSP, someZuanTouBombRsp);

            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeSomeZuanTou::OnTimer() NF_FISH_CMD_SOMEZUANTOBOMB_RSP");
            //////////////////////////////////////////////////////////////////////////



            if (iSubFishCount > 0)
            {
                pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeSomeZuanTou::OnTimer() zuanTouBomb NF_FISH_CMD_KILLFISH");
                pPlayer->AddCaptureMoney(iTotalScore);
            }
            else
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> canlan NFFishTypeSomeZuanTou::OnTimer()no sub fishes NF_FISH_CMD_KILLFISH");
            }

            pFishTypeHandler->DeleteTimer(uId);
            return 0;
        }
    }
    return 0;
}
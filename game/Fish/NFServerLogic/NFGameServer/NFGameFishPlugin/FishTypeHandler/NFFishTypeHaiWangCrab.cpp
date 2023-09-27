// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHaiWangCrab.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHaiWangCrab
//
// -------------------------------------------------------------------------

#include "NFFishTypeHaiWangCrab.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "CSFish.pb.h"
#include "Desk/NFGameFishDesk.h"
#include "Fish/NFGameFish.h"
#include "Player/NFGameFishPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFFishTypeHaiWangCrab, EOT_GAME_FISH_TYPE_HANDLE_HAIWANGCRAB_ID, NFFishTypeHandler)

NFFishTypeHaiWangCrab::NFFishTypeHaiWangCrab()
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

NFFishTypeHaiWangCrab::~NFFishTypeHaiWangCrab()
{
}

int NFFishTypeHaiWangCrab::CreateInit()
{
    return 0;
}

int NFFishTypeHaiWangCrab::ResumeInit()
{
    return 0;
}

int NFFishTypeHaiWangCrab::OnKilllingFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

uint64_t NFFishTypeHaiWangCrab::KillFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");
    CHECK_EXPR(pFish, 0, "pFish == NULL !");

    NFGameFish* pFishHaiWangCrab = pFish;
    int32_t haiWangCrabId = pFishHaiWangCrab->m_uFishId;

    pFishHaiWangCrab->Kill();

    int iKilledPartCount = pFishHaiWangCrab->GetKillMyCrabPartCount(pPlayer->m_ullPlayerId);

    int iTotalMul = 0;
    int iPartsMul = 1;
    if (iKilledPartCount == 0)
    {
        iPartsMul = 1;
    }
    else if (iKilledPartCount == 1)
    {
        iPartsMul = 2;
    }
    else if (iKilledPartCount == 2)
    {
        iPartsMul = 3;
    }

    iTotalMul      = pFishHaiWangCrab->GetBaseMul()* iPartsMul * bullet.GetBulletMul();
    int iSelfScore = bullet.GetBulletMoney() * iTotalMul;

    //////////////////////////////////////////////////////////////////////////
    int32_t iMaxWinMoney = pPlayer->GetMaxWinMoney();
    if (iSelfScore > iMaxWinMoney)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "KillFish()==> iSelfScore > iMaxWinMoney ! {} > {} !", iSelfScore, iMaxWinMoney);
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////

    gamefish::KillFishRsp gcKillFish;
    gcKillFish.set_bulletid(bullet.m_uBulletId);
    gcKillFish.set_bombuid(0);
    gcKillFish.set_mainfishuid(pFish->m_uFishId);
    gcKillFish.set_mainfishid(pFish->m_nFishKind);
    gcKillFish.set_mainfishtype(pFish->m_fishKind.m_btFishType);
    gcKillFish.set_mainmultiple(pFish->m_fishKind.m_nBaseMul);
    gcKillFish.set_mainscore(iSelfScore);
    gcKillFish.set_totalscore(iSelfScore);
    gcKillFish.set_totalratio(iSelfScore / bullet.GetBulletMoney());
    gcKillFish.set_chairid(pPlayer->GetChairIdForClient());
    gcKillFish.set_userrorcode(0);
    gcKillFish.set_subfishcount(0);
    gcKillFish.set_bombfishid(0);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_KILLFISH, gcKillFish);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " NFFishTypeHaiWangCrab::KillFish() ======================> NF_FISH_CMD_KILLFISH");
    //////////////////////////////////////////////////////////////////////////

    KilledCrabPartList& aryKilledCrabPart = pFishHaiWangCrab->GetKilledCrabParts();

    int iTotalPartsMul = 0;
    int iTotalPartsScore = 0;
    for (int i = 0; i < (int)aryKilledCrabPart.size(); i++)
    {
        KilledCrabPart* pPart = &aryKilledCrabPart[i];
        if (pPart != NULL)
        {
            if (pPart->m_llPlayerId == pPlayer->m_ullPlayerId)
            {
                iTotalPartsMul += pPart->m_iMul;
                iTotalPartsScore += pPart->m_iScore;

                NFLogTrace(NF_LOG_SYSTEMLOG, 0, " NFFishTypeHaiWangCrab ==> pPart->m_iMul = {} , m_iScore = {}", pPart->m_iMul, pPart->m_iScore);
            }
        }
    }

    int iTotalScore = iSelfScore + iTotalPartsScore;

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " NFFishTypeHaiWangCrab ==> iTotalPartsMul = {} , iTotalPartsScore = {}", iTotalPartsMul, iTotalPartsScore);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " NFFishTypeHaiWangCrab ==> iTotalMul = {} , iSelfScore = {} , iTotalScore = {}", iTotalMul, iSelfScore, iTotalScore);


    gamefish::HaiWangCrabKilledDeadRsp haiWangCrabKilledDeadRsp;
    haiWangCrabKilledDeadRsp.set_uschairid(pPlayer->GetChairIdForClient());
    haiWangCrabKilledDeadRsp.set_ushaiwangcrabid(haiWangCrabId);
    haiWangCrabKilledDeadRsp.set_uspartmul(iPartsMul);
    haiWangCrabKilledDeadRsp.set_usselfscore(iSelfScore);
    haiWangCrabKilledDeadRsp.set_ustotalscore(iTotalScore);
    haiWangCrabKilledDeadRsp.set_ustotalmul(iTotalMul);

    m_pDesk->SendMsgToAllClient(NF_FISH_CMD_HAIWANGCRABKILLEDDEAD_RSP, haiWangCrabKilledDeadRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, " NFFishTypeHaiWangCrab::KillFish() ======================> NF_FISH_CMD_HAIWANGCRABKILLEDDEAD_RSP");

    return iTotalScore;
}

int NFFishTypeHaiWangCrab::OnKilledFish(NFGameFishPlayer *pPlayer, NFGameFish *pFish, const NFFishBullet &bullet)
{
    return 0;
}

int NFFishTypeHaiWangCrab::GetKilledFishMul(NFGameFish *pFish)
{
    CHECK_EXPR(pFish, -1, "pFish == NULL !");

    return pFish->m_fishKind.m_nBaseMul;
}

int NFFishTypeHaiWangCrab::OnHandleClientMessage(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");

    switch (packet.nMsgId)
    {
        case NF_FISH_CMD_HAIWANGCRABHITPART_REQ:
            OnHandleHaiWangCrabHitPart(pPlayer, packet);
            return 1;

        default:
            return 0;
    }
}

int NFFishTypeHaiWangCrab::OnHandleHaiWangCrabHitPart(NFGameFishPlayer *pPlayer, NFDataPackage &packet)
{
    CHECK_EXPR(pPlayer, 0, "pPlayer == NULL !");

    gamefish::HaiWangCrabHitPartReq haiWangCrabHitPartReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, haiWangCrabHitPartReq);

    NFFishSettingConfig* pSettingConfig = m_pDesk->GetFishSettingConfig();
    CHECK_NULL(pSettingConfig);

    int32_t bulletId = haiWangCrabHitPartReq.usbulletid();
    int32_t haiWangCrabId = haiWangCrabHitPartReq.ushaiwangcrabid();
    int32_t partId = haiWangCrabHitPartReq.uspartid(); //0-本鱼、1-左爪、2-右爪

    NFFishBullet *pBullet = pPlayer->m_BulletMgr.GetBullet(bulletId);
    CHECK_EXPR(pBullet, -1, "pBullet == NULL ! bulletid = {}", bulletId);

    NFFishBullet bullet = *pBullet;

    pPlayer->m_BulletMgr.DeleteBullet(bulletId);

    NFGameFish* pFishHaiWangCrab = m_pDesk->GetFish(haiWangCrabId);
    if (pFishHaiWangCrab == NULL)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> OnHandleHaiWangCrabHitPart() Can't find haiWangCrabId = {}", haiWangCrabId);
        return 0;
    }

    //int iKilledPartCount = m_pDesk->GetKillCrabPartCount(pPlayer->m_ullPlayerId);
    int iKilledPartCount = pFishHaiWangCrab->GetKillAllCrabPartCount();

    if (iKilledPartCount >= 2)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> OnHandleHaiWangCrabHitPart()  iKilledPartCount >= 2 return !");
        return 1;
    }

    int rand = NFRandInt(1, 100);

    if (rand < 5 || (pSettingConfig->m_iOneCannonKilled == 1))
    {
        //0-本鱼、1-左爪、2-右爪
        if (partId == 0)//打到本鱼不走这个协议了，走普通打到鱼的协议
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "OnHandleHaiWangCrabHitPart() ======================> 000000000000000000000");
            return 0;
        }
        else//打到爪子
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "OnHandleHaiWangCrabHitPart() ======================> 1111111111111111111111");


            int mul = 0;
            if (iKilledPartCount == 0)
            {
                mul = 2;
            }
            else if (iKilledPartCount == 1)
            {
                mul = 3;
            }

            KilledCrabPart killedCrabPart;
            killedCrabPart.m_llPlayerId = pPlayer->m_ullPlayerId;
            killedCrabPart.m_iChairId = pPlayer->GetChairIdForClient();
            killedCrabPart.m_iPartId = partId;
            killedCrabPart.m_iMul = mul;
            killedCrabPart.m_iScore = bullet.GetBulletMoney() * bullet.GetBulletMul() * mul;

            pFishHaiWangCrab->AddKilledCrabPart(killedCrabPart);

            pPlayer->AddCaptureMoney(killedCrabPart.m_iScore);

            gamefish::HaiWangCrabKilledPartRsp haiwangCrabKillPartRsp;
            haiwangCrabKillPartRsp.set_ushaiwangcrabid(haiWangCrabId);

            KilledCrabPartList& aryKilledCrabPart = pFishHaiWangCrab->GetKilledCrabParts();

            int iTotalMul = 0;
            int iTotalScore = 0;
            for (int i = 0; i < (int)aryKilledCrabPart.size(); i++)
            {
                KilledCrabPart* pPart = &aryKilledCrabPart[i];
                if (pPart != NULL)
                {
                    gamefish::CrabPart* pCrabPart = haiwangCrabKillPartRsp.add_arykilledparts();
                    pCrabPart->set_uschairid(pPart->m_iChairId);
                    pCrabPart->set_uspartid(pPart->m_iPartId);
                    pCrabPart->set_uspartmul(pPart->m_iMul);
                    pCrabPart->set_usscore(pPart->m_iScore);

                    iTotalMul += pPart->m_iMul;
                    iTotalScore += pPart->m_iScore;

                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> OnHandleHaiWangCrabHitPart() aryKilledCrabPart: m_iChairId = {} , m_iPartId = {}", pPart->m_iChairId, pPart->m_iPartId);
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> OnHandleHaiWangCrabHitPart() aryKilledCrabPart: pPart->m_iMul = {} , pPart->m_iScore = {}", pPart->m_iMul, pPart->m_iScore);
                }
            }

            //haiwangCrabKillPartRsp.set_ustotalscore(iTotalScore);
            //haiwangCrabKillPartRsp.set_ustotalmul(iTotalMul);

            m_pDesk->SendMsgToAllClient(NF_FISH_CMD_HAIWANGCRAB_KILLEDPART_RSP, haiwangCrabKillPartRsp);
        }

        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeHaiWangCrab::OnHandleHaiWangCrabHitPart() NF_FISH_CMD_HAIWANGCRABKILLPART_RSP");
    }
    else
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "====> NFFishTypeHaiWangCrab::OnHandleHaiWangCrabHitPart() NF_FISH_CMD_HAIWANGCRABKILLPART_RSP rand = {}", rand);
    }

    return 0;
}

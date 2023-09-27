// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeZuanTou.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeZuanTou
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

#include "NFFishTypeBaseData.h"
#include "Fish/NFGameFish.h"

enum eZuanTouStatus
{
    eZuanTouSts_Aim   = 1,
    eZuanTouSts_Shoot = 2,
    eZuanTouSts_Bomb  = 3,

};

class NFFishTypeZuanTou;
class NFZuanTou : public NFFishTypeBaseData
{
public:
    NFZuanTou()
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

    virtual ~NFZuanTou()
    {

    }

    int CreateInit()
    {
        m_uId = 0;
        m_uChairId = 0;
        m_ullPlayerId = 0;
        m_uBornTime = 0;
        m_uTraceId = 0;
        m_uTraceStartPt = 0;
        m_uStatus = 0;
        m_uStatusTimeStart = 0;
        m_uStatusTimerId = INVALID_ID;
        m_iAngle = 0;
        m_iBulletMul   = 0;
        m_iBulletMoney = 0;
        m_iMaxWinMoney = 0;
        m_uTotalScore = 0;

        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    uint32_t MyMaxWinMoney()
    {
        uint32_t uMyMaxWinMoney = 999999999;

        int iMyKilledMul = m_bombFish.GetKilledDeathMul();

        if (iMyKilledMul > 0)
        {
            uMyMaxWinMoney = iMyKilledMul * m_iBulletMul * m_iBulletMoney * 3;
        }

        return uMyMaxWinMoney;
    }

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_bombFish;
    uint32_t m_uBornTime;
    uint32_t m_uTraceId;
    uint32_t m_uTraceStartPt;
    uint32_t m_uStatus;        //1-��׼״̬/aimStatus 2-����״̬/shootStatus 3-��ը״̬/bombStatus
    uint64_t m_uStatusTimeStart;
    int32_t  m_uStatusTimerId;
    int32_t  m_iAngle;

    int32_t  m_iBulletMul;
    int32_t  m_iBulletMoney;
    int32_t  m_iMaxWinMoney;
    uint32_t m_uTotalScore;
};

class NFFishTypeZuanTou : public NFFishTypeHandler
{
public:
    NFFishTypeZuanTou();

    virtual ~NFFishTypeZuanTou();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    virtual int SyncFishBomb(NFGameFishPlayer* pPlayer);

    NFZuanTou* CreateZuanTou(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
    int OnHandleZuanTouAim(NFGameFishPlayer* pPlayer,  NFDataPackage &packet);
    int OnHandleZuanTouShoot(NFGameFishPlayer* pPlayer,  NFDataPackage &packet);
    int OnHandleZuanTouHitFish(NFGameFishPlayer* pPlayer,  NFDataPackage &packet);
public:
    int DeleteZuanTou(uint32_t id);
    NFZuanTou* GetZuanTou(uint32_t id);
public:
    NFShmHashMap<uint32_t, NFZuanTou, 10> m_mapZuanTou;
private:
DECLARE_IDCREATE(NFFishTypeZuanTou)
};
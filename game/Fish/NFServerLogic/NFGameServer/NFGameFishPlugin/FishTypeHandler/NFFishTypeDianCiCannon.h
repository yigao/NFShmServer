// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeDianCiCannon.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeDianCiCannon
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "Fish/NFGameFish.h"
#include "NFFishTypeBaseData.h"

enum eDianCiCannonStatus
{
    eDianCiConnonSts_Aim   = 1,
    eDianCiConnonSts_Shoot = 2,

};

class NFFishTypeDianCiCannon;
class NFGameFishDeskMgr;
class NFDianCiCannon : public NFFishTypeBaseData
{
public:
    NFDianCiCannon()
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

    virtual ~NFDianCiCannon()
    {

    }

    int CreateInit()
    {
        m_uId = 0;
        m_uChairId = 0;
        m_ullPlayerId = 0;
        m_uAngle = 0;
        m_uStatus = 0;
        m_iBulletMul = 0;
        m_iBulletMoney = 0;
        m_iMaxWinMoney = 0;
        m_uTotalScore = 0;
        m_uStatusTimeStart = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    uint32_t MyMaxWinMoney()
    {
        int iMyKilledMul = m_bombFish.GetKilledDeathMul();

        if (iMyKilledMul == 0)
        {
            return 999999999;
        }
        else
        {
            return iMyKilledMul * m_iBulletMul * m_iBulletMoney * 3;
        }
    }

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_bombFish;
    int32_t  m_uAngle;
    uint32_t m_uStatus;
    int32_t  m_iBulletMul;
    int32_t  m_iBulletMoney;
    int32_t  m_iMaxWinMoney;
    uint32_t m_uTotalScore;
    uint64_t m_uStatusTimeStart;
};

class NFFishTypeDianCiCannon : public NFFishTypeHandler
{
public:
    NFFishTypeDianCiCannon();

    virtual ~NFFishTypeDianCiCannon();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    virtual int SyncFishBomb(NFGameFishPlayer* pPlayer);
    int OnHandleDianCiCannonAim(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    int OnHandleDianCiCannonShoot(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    int OnHandleDianCiCannonHitFish(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
public:
    NFDianCiCannon* CreateDianCiCann(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
    NFDianCiCannon* GetDianCiCannon(uint32_t id);
    int DeleteDianCicannon(uint32_t id);
private:
    NFShmHashMap<uint32_t, NFDianCiCannon, 10> m_mapDianCiCannon;
DECLARE_IDCREATE(NFFishTypeDianCiCannon)
};
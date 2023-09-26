// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFireStorm.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFireStorm
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "Fish/NFGameFish.h"
#include "NFFishTypeBaseData.h"

enum eFirmStormStatus
{
    eFirmStormSts_Wait  = 1,
    eFirmStormSts_Shoot = 2,
};

class NFFishTypeFireStorm;
class NFGameFishDeskMgr;
class NFFireStorm : public NFFishTypeBaseData
{
public:
    NFFireStorm()
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

    virtual ~NFFireStorm()
    {

    }

    int CreateInit()
    {
        m_uId = 0;
        m_uChairId = 0;
        m_ullPlayerId = 0;
        m_uBornTime = 0;
        m_uStatus = 0;
        m_uStatusTimeStart = 0;
        m_uStatusTimerId = INVALID_ID;
        m_uTotalScore  = 0;
        m_iBulletMoney = 0;
        m_uDestroyTimerId = INVALID_ID;

        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_bombFish;
    uint32_t m_uBornTime;
    uint32_t m_uStatus;  //eFirmStormStatus: 1 - wait status/����״̬�� 2 - shoot status/����״̬
    uint64_t m_uStatusTimeStart;
    int32_t  m_uStatusTimerId;
    int32_t  m_uDestroyTimerId;
    uint32_t m_uTotalScore;
    int32_t  m_iBulletMoney;
};

class NFFishTypeFireStorm : public NFFishTypeHandler
{
public:
    NFFishTypeFireStorm();

    virtual ~NFFishTypeFireStorm();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnAddScore(NFGameFishPlayer* pPlayer, NFGameFish* pFish, uint64_t ullScoreMoney);
    virtual int SyncFishBomb(NFGameFishPlayer* pPlayer);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    int OnHandleFishShootBullet(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    NFFireStorm* CreateFireStorm(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
public:
    int DeleteFireStorm(uint32_t id);
    NFFireStorm* GetFireStorm(uint32_t id);
    NFFireStorm* GetFireStormByPlayerId(uint64_t playerId);
private:
    NFShmHashMap<uint32_t, NFFireStorm, 10> m_mapFireStorm;
DECLARE_IDCREATE(NFFishTypeFireStorm)
};
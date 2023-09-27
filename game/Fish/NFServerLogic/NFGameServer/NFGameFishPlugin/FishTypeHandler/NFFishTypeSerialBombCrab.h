// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSerialBombCrab.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSerialBombCrab
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "Fish/NFGameFish.h"
#include "NFFishTypeBaseData.h"

enum eSerialBombCrabStatus
{
    eSerialBombCrabStatus_Wait  = 1,
    eSerialBombCrabStatus_Shoot = 2,
};

class NFFishTypeSerialBombCrab;
class NFSerialBombCrab : public NFFishTypeBaseData
{
public:
    NFSerialBombCrab()
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

    virtual ~NFSerialBombCrab()
    {
        if (m_uStatusTimerId != INVALID_ID)
        {
            DeleteTimer(m_uStatusTimerId);
            m_uStatusTimerId = INVALID_ID;
        }

        if (m_uBombTimerId != INVALID_ID)
        {
            DeleteTimer(m_uBombTimerId);
            m_uBombTimerId = INVALID_ID;
        }
    }

    int CreateInit()
    {
        m_uId = 0;
        m_uChairId = 0;
        m_ullPlayerId = 0;
        m_uBornTime = 0;
        m_uStatus = 1;
        m_uStatusTimeStart = 0;
        m_uStatusTimerId = INVALID_ID;
        m_uBombTimerId = INVALID_ID;
        m_uBombCount = 0;
        m_uTotalScore = 0;
        m_iMaxWinMoney = 0;
        m_iBulletMul = 0;
        m_iBulletMoney = 0;

        m_uLastPosX = 0;
        m_uLastPosY = 0;
        m_uBombCountMax = 0;

        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    uint32_t MyMaxWinMoney()
    {
        int iMyKilledMul = m_BombFish.GetKilledDeathMul();

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

    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_BombFish;
    uint32_t m_uBornTime;
    uint32_t m_uStatus;  //1-�ȴ�״̬/eSerialBombCrabStatus_Wait 2-����״̬/eSerialBombCrabStatus_Shoot
    uint64_t m_uStatusTimeStart;
    int32_t  m_uStatusTimerId;
    int32_t  m_uBombTimerId;
    int32_t  m_uBombCount;


    int32_t  m_iBulletMul;
    int32_t  m_iBulletMoney;
    int32_t  m_iMaxWinMoney;
    uint32_t m_uTotalScore;


    uint32_t m_uLastPosX;
    uint32_t m_uLastPosY;
    uint32_t m_uBombCountMax;
};

class NFFishTypeSerialBombCrab : public NFFishTypeHandler
{
public:
    NFFishTypeSerialBombCrab();

    virtual ~NFFishTypeSerialBombCrab();

    int CreateInit();

    int ResumeInit();
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int SyncFishBomb(NFGameFishPlayer* pPlayer);
    NFSerialBombCrab* CreateSerialBombCrab(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
public:
    int DeleteBombCrab(uint32_t id);
    NFSerialBombCrab* GetBombCrab(uint32_t id);
private:
    NFShmHashMap<uint32_t, NFSerialBombCrab, 10> m_mapSerialBombCrab;
DECLARE_IDCREATE(NFFishTypeSerialBombCrab)
};
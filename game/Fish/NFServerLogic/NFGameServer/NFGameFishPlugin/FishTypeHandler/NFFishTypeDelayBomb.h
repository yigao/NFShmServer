// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeDelayBomb.h
//    @Author           :    gaoyi
//    @Date             :    23-9-22
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeDelayBomb
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFFishTypeHandler.h"
#include "Config/HMPoint.h"
#include "Fish/NFGameFish.h"

class NFFishTypeDelayBomb;
class NFDelayBomb
{
public:
    NFDelayBomb()
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

    virtual ~NFDelayBomb()
    {

    }

    int CreateInit()
    {
        m_uId = 0;
        m_uChairId = 0;
        m_ullPlayerId = 0;
        m_uStatus = 0;
        m_uStatusEndTime = 0;
        m_iBulletMul = 0;
        m_iBulletMoney = 0;
        m_iMaxWinMoney = 0;
        m_uTotalScore  = 0;
        m_pFishTypeDelayBomb = NULL;
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

    int HandleDelayed();
public:
    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_bombFish;
    CHMPoint m_ptMyPos;
    uint32_t m_uStatus;
    uint64_t m_uStatusEndTime;
    int32_t  m_iBulletMul;
    int32_t  m_iBulletMoney;
    int32_t  m_iMaxWinMoney;
    uint32_t m_uTotalScore;
    NFShmPtr<NFFishTypeDelayBomb> m_pFishTypeDelayBomb;
};

#define MAX_FISH_TYPE_DELAY_BOMB_NUM 100

class NFFishTypeDelayBomb : public NFFishTypeHandler
{
public:
    NFFishTypeDelayBomb();

    virtual ~NFFishTypeDelayBomb();

    int CreateInit();

    int ResumeInit();

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int GetKilledFishMul(NFGameFish* pFish, const NFFishBullet& bullet);
    virtual void SyncFishBomb(NFGameFishPlayer* pPlayer);
    NFDelayBomb* CreateDelayBomb(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
    std::vector<NFGameFish*> GetKilledSubFishes(CHMPoint ptCenter, int iRadius);
private:
    NFShmHashMap<uint32_t, NFDelayBomb, MAX_FISH_TYPE_DELAY_BOMB_NUM> m_mapDelayBomb;
    uint32_t m_statusTimer;
DECLARE_IDCREATE(NFFishTypeDelayBomb)
};
// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMadCow.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMadCow
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "NFFishTypeBaseData.h"
#include "Fish/NFGameFish.h"

enum eMadStatus
{
    eMadStatus_Wait  = 1,
    eMadStatus_Shoot = 2,
};

class NFFishTypeMadCow;
class NFMadCow : public NFFishTypeBaseData
{
public:
    NFMadCow()
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

    virtual ~NFMadCow()
    {

    };


    int CreateInit()
    {
        m_uId = 0;
        m_uChairId    = 0;
        m_ullPlayerId = 0;
        m_uBornTime   = 0;
        m_uStatus     = 0;
        m_uStatusTimeStart = 0;
        m_uStatusTimerId   = INVALID_ID;
        m_uShootCount  = 0;
        m_iMaxWinMoney = 0;
        m_uTotalScore  = 0;
        m_iBulletMul   = 0;
        m_iBulletMoney = 0;
        m_uDirection = 0;

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

public:
    uint32_t m_uId;
    uint32_t m_uChairId;
    uint64_t m_ullPlayerId;
    NFGameFish m_BombFish;
    uint32_t m_uBornTime;
    uint32_t m_uDirection; //1-����/to left  2-����/to right
    uint32_t m_uStatus; //eMadStatus 1-����  2-����
    uint64_t m_uStatusTimeStart;
    int32_t  m_uStatusTimerId;
    uint32_t m_uShootCount;

    int32_t  m_iMaxWinMoney;
    int32_t  m_iBulletMul;
    int32_t  m_iBulletMoney;
    uint32_t m_uTotalScore;
};

class NFFishTypeMadCow : public NFFishTypeHandler
{
public:
    NFFishTypeMadCow();

    virtual ~NFFishTypeMadCow();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int SyncFishBomb(NFGameFishPlayer* pPlayer);
    NFMadCow* CreateMadCow(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish, const NFFishBullet& bullet);
public:
    int DeleteMadCor(uint32_t id);
    NFMadCow* GetMadCor(uint32_t id);
private:
    NFShmHashMap<uint32_t, NFMadCow, 10> m_mapMadCow;
DECLARE_IDCREATE(NFFishTypeMadCow)
};
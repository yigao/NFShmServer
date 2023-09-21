// -------------------------------------------------------------------------
//    @FileName         :    NFFishBulletMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishBulletMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include <map>

#define MAX_FISH_BULLET_COUNT 1000

enum eBulletType
{
    eBulletType_Normal = 1, //普通炮
    eBulletType_Double = 2, //双倍炮
    eBulletType_Free   = 3, //免费炮
};

class NFFishBullet
{
public:
    NFFishBullet();
    int CreateInit();
    int ResumeInit();

    bool IsEmpty()
    {
        return m_uBulletId == 0;
    }

    void SetBulletMoney(uint32_t uMoney)
    {
        m_uBulletMoney = uMoney;
    }

    uint32_t GetBulletMoney() const
    {
        return m_uBulletMoney;
    }

    uint32_t GetBulletMul() const;//eg.双倍炮

public:
    uint32_t m_uBulletId;
    uint32_t m_uBulletType;// eBulletType 1-普通 2-双倍炮 3-免费炮
    int32_t m_iAngle;
    int32_t m_iBulletLevel;

    int32_t m_iChairId;

    uint64_t m_llBirthTime;

private:
    uint32_t m_uBulletMoney;
};

class NFFishBulletMgr {
public:
    NFFishBulletMgr();

    ~NFFishBulletMgr();

    int CreateInit();
    int ResumeInit();

    bool SaveBullet(const NFFishBullet& bullet);

    void DeleteBullet(uint32_t uBulletId);

    NFFishBullet* GetBullet(uint32_t uBulletId);

    int GetBulletCount() { return m_mapBullets.size(); };

    bool IsFull() const { return m_mapBullets.full(); }

    void CheckBulletOverTime();

    void Clear() { m_mapBullets.clear(); };

public:
    NFShmHashMap<uint32_t, NFFishBullet, MAX_FISH_BULLET_COUNT> m_mapBullets;
};
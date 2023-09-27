// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSomeZuanTou.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSomeZuanTou
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"
#include "NFFishTypeBaseData.h"
#include "Fish/NFGameFish.h"

class SomeZuanTouInfo
{
public:
    SomeZuanTouInfo()
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

    int CreateInit()
    {
        uId    = 0;
        uAngle        = 0;
        uTraceId      = 0;
        uTraceStartPt = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
public:
    uint32_t uId;
    uint32_t uAngle;
    uint32_t uTraceId;
    uint32_t uTraceStartPt;
};

class NFFishTypeSomeZuanTou;
class SomeZuanTouGroup : public NFFishTypeBaseData
{
public:
    SomeZuanTouGroup()
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

    virtual ~SomeZuanTouGroup()
    {

    }

    SomeZuanTouInfo* ShootZuanTou()
    {
        uShootCount++;
        CHECK_EXPR(m_pShmObj, NULL, "");
        uint32_t id = m_pShmObj->FindModule<NFISharedMemModule>()->Get32UUID();
        CHECK_EXPR(mapSomeZuanTous.size() < mapSomeZuanTous.max_size(), NULL, "mapSomeZuanTous space not enough");

        SomeZuanTouInfo* someZuanTouInfo = &mapSomeZuanTous[id];
        CHECK_EXPR(someZuanTouInfo, NULL, "mapSomeZuanTous Insert id:{} Failed", id);

        someZuanTouInfo->uId = id;
        someZuanTouInfo->uAngle     = uShootCount * 60;
        someZuanTouInfo->uTraceId   = 1000 + uShootCount;
        someZuanTouInfo->uTraceStartPt = 0;

        return someZuanTouInfo;
    }

    SomeZuanTouInfo* GetZuanTou(uint32_t uZuanTouId)
    {
        auto iter = mapSomeZuanTous.find(uZuanTouId);
        if (iter != mapSomeZuanTous.end())
        {
            return &iter->second;
        }
        return nullptr;
    }

    int CreateInit()
    {
        uId = 0;
        uChairId = 0;
        ullPlayerId = 0;
        uBornTime = 0;
        uStatus = 1;  //1-�ȴ�״̬ 2-����״̬
        uStatusTimeStart = 0;
        uStatusTimerId = INVALID_ID;
        uShootTimerId = INVALID_ID;
        uShootCount = 0;
        uTotalScore = 0;
        iBulletMoney = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    uint32_t uId;
    uint32_t uChairId;
    uint64_t ullPlayerId;
    NFGameFish bombFish;
    uint32_t uBornTime;
    uint32_t uStatus;  //
    uint32_t uStatusTimeStart;
    int32_t  uStatusTimerId;
    int32_t  uShootTimerId;
    int32_t  uShootCount;
    uint32_t uTotalScore;
    int32_t  iBulletMoney;
private:
    NFShmHashMap<uint32_t, SomeZuanTouInfo, 100> mapSomeZuanTous;
};

class NFFishTypeSomeZuanTou : public NFFishTypeHandler
{
public:
    NFFishTypeSomeZuanTou();

    virtual ~NFFishTypeSomeZuanTou();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnKilllingFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnKilledFish(NFGameFishPlayer* pPlayer, NFGameFish* pFish, const NFFishBullet& bullet);
    virtual int OnHandleClientMessage(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
    SomeZuanTouGroup* CreateSomeZuanTouGroup(NFGameFishPlayer* pPlayer, NFGameFish* pBombFish);
    int OnHandleSomeZuanTouHitFish(NFGameFishPlayer* pPlayer, NFDataPackage &packet);
public:
    int DeleteSomeZuanTouGroup(uint32_t id);
    SomeZuanTouGroup* GetSomeZuanTouGroup(uint32_t id);
public:
    NFShmHashMap<uint32_t, SomeZuanTouGroup, 10> m_mapSomeZuanTouGroups;
private:
DECLARE_IDCREATE(NFFishTypeSomeZuanTou)
};
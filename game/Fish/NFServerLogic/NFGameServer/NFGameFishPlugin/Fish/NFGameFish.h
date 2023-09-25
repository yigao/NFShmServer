// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish.h
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmStl/NFShmVector.h"
#include "Config/HMPoint.h"
#include "Config/NFFishTraceConfig.h"
#include "Config/NFFishConfigConfig.h"

#define INVALID_FISHID   0
#define INVALID_FISHKIND 255


#define NFGAME_FISHTYPE_NORMAL             1 //普通鱼
#define NFGAME_FISHTYPE_KINDBOMB           2 //同类炸弹/同类子鱼
#define NFGAME_FISHTYPE_LIGHTLINK          3 //闪电连锁/同类主鱼 - 不是同类主鱼，特效为3的全死？
#define NFGAME_FISHTYPE_DANAOTIANGONG      4 //同类炸弹，同时可能会带烟花效果
#define NFGAME_FISHTYPE_FREEZE             5 //定屏炸弹
#define NFGAME_FISHTYPE_FULLSCREENBOMB     9 //全屏炸弹
#define NFGAME_FISHTYPE_DIANCICANNON       10//电磁炮
#define NFGAME_FISHTYPE_ZUANTOU            11//钻头蟹的钻头
#define NFGAME_FISHTYPE_SOMEZUANTOU        12//连环钻头
#define NFGAME_FISHTYPE_FIRESTORM          13//烈焰风暴
#define NFGAME_FISHTYPE_MADCOW             14//疯牛
#define NFGAME_FISHTYPE_SERIALBOMBCRAB     15//连环炸弹螃蟹
#define NFGAME_FISHTYPE_HAIWANGCRAB        16//海王螃蟹
#define NFGAME_FISHTYPE_LIGHTNINGJELLYFISH 17//电光水母
#define NFGAME_FISHTYPE_DELAYBOMB          18//延时炸弹


#define NFGAME_FISHTYPE_MAX_VALUE 30



class KilledCrabPart
{
public:
    KilledCrabPart()
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
        m_llPlayerId = 0;
        m_iChairId = 0;
        m_iPartId = 0;
        m_iMul = 0;
        m_iScore = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    uint64_t m_llPlayerId;
    int m_iChairId;
    int m_iPartId;
    int m_iMul;
    int m_iScore;
};

typedef NFShmVector<KilledCrabPart, 5> KilledCrabPartList;


class FishKind
{
public:
    FishKind()
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
        m_btFishType = 0;
        m_nBaseMul = 0;
        m_nKilledMul = 0;
        m_nDoubleAwardMinRatio = 100;
        nMiniGameId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    bool IsCanTriggerDoubleCannon()
    {
        return m_nBaseMul > m_nDoubleAwardMinRatio;
    }

public:
    int m_btFishType;
    int m_nBaseMul;
    int m_nKilledMul;
    int m_nDoubleAwardMinRatio;
    NFShmVector<uint8_t, 10> vectSubFishes; //暂时定义最大10个
    int nMiniGameId;
};

class FishConfig;

class NFGameFish
{
public:
    NFGameFish();

    virtual ~NFGameFish();

    int CreateInit();

    int ResumeInit();

    bool IsOverTime(uint64_t uCurMSecond)
    {
        if (uCurMSecond > m_uBirthTime + m_uAliveTime)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsAlive()
    {
        return (!m_bIsKilled) && (!m_bIsOverTime);
    }

    bool IsKilled()
    {
        return m_bIsKilled;
    }

    void Kill()
    {
        m_bIsKilled = true;
    }

    void OverTime()
    {
        m_bIsOverTime = true;
    }

    void AddFreezeTime(uint32_t uFreezeTime)
    {
        m_uFreezeTime += uFreezeTime;
        m_uAliveTime += uFreezeTime;
    }

    int WalkPointCount();

    int GetCurBirthDelay();

    int GetMyPointIndex();

    CHMPoint GetMyPoint(NFFishTraceConfig* pTraceConfig);

    int GetBaseMul()
    {
        return m_fishKind.m_nBaseMul;
    }

    void AddKilledCrabPart(KilledCrabPart killedCrabPart);

    KilledCrabPartList &GetKilledCrabParts();

    int GetKillMyCrabPartCount(uint64_t llPlayerId);

    int GetKillAllCrabPartCount();

    int GetKilledDeathMul()
    {
        if (m_fishKind.m_nKilledMul > 0)
        {
            return m_fishKind.m_nKilledMul;
        }
        else
        {
            return m_fishKind.m_nBaseMul;
        }
    }

    bool IsCanKill(NFFishConfigConfig *pFishConfigDesc, int iSubFishKind);

public:
    uint32_t m_uFishId;
    uint64_t m_uBirthTime;
    uint32_t m_uBirthDelayMS;
    uint32_t m_nFishKind;
    uint32_t m_uTraceId;
    uint16_t m_nStartPointIndex;
    uint16_t m_nOffSetPointCount;
    int16_t m_nOffsetPosX;
    int16_t m_nOffsetPosY;
    uint32_t m_uAliveTime;
    uint32_t m_uFreezeTime;
    bool m_bIsRedFish;

    FishKind m_fishKind;

    int m_iDemageRadius;
    int m_iGroupId;
public:
    KilledCrabPartList m_aryKilledCrabPart;//螃蟹的爪子
private:
    bool m_bIsKilled;
    bool m_bIsOverTime;
public:
    uint32_t m_roomId;
    uint32_t m_deskId;
};

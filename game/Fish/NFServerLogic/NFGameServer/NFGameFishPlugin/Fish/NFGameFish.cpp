// -------------------------------------------------------------------------
//    @FileName         :    NFGameFish.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameFish
//
// -------------------------------------------------------------------------

#include "NFGameFish.h"
#include "Config/NFFishTraceConfig.h"
#include "Config/NFFishConfigConfig.h"

NFGameFish::NFGameFish()
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

NFGameFish::~NFGameFish()
{

}

int NFGameFish::CreateInit()
{
    m_uFishId = INVALID_FISHID;
    m_uBirthTime = 0;
    m_uBirthDelayMS = 0;
    m_nFishKind = INVALID_FISHKIND;
    m_uTraceId = 0;
    m_nStartPointIndex = 0;
    m_nOffSetPointCount = 0;
    m_uAliveTime = 0;
    m_bIsKilled = false;
    m_bIsOverTime = false;
    m_uFreezeTime = 0;
    m_bIsRedFish = false;
    m_iDemageRadius = 9999;
    m_nOffsetPosX = 0;
    m_nOffsetPosY = 0;
    m_iGroupId = 0;

    m_aryKilledCrabPart.clear();

    return 0;
}


int NFGameFish::ResumeInit()
{
    return 0;
}

int NFGameFish::WalkPointCount()
{
    int count = (NFTime::Now().UnixMSec() - m_uBirthTime - m_uFreezeTime - m_uBirthDelayMS) / 100;
    return count;
}

int NFGameFish::GetCurBirthDelay()
{
    int walkPointCount = WalkPointCount();
    if (walkPointCount < 0)
    {
        return -walkPointCount * 100;
    }
    else
    {
        return 0;
    }
}

int NFGameFish::GetMyPointIndex()
{
    int walkPointCount = WalkPointCount();
    if (walkPointCount < 0)
    {
        return m_nStartPointIndex;
    }
    else
    {
        return m_nStartPointIndex + WalkPointCount();
    }
}

CHMPoint NFGameFish::GetMyPoint(NFIPluginManager *pPluginManager, uint32_t roomId)
{
    int index = GetMyPointIndex();

    auto pTraceConfig = NFFishTraceConfig::GetObjByHashKey(pPluginManager, roomId);
    CHECK_EXPR(pTraceConfig, CHMPoint(), "GetTraceConfig failed, roomId:{}", roomId);

    CHMPoint point = pTraceConfig->GetPointByIndex(m_uTraceId, index);

    return point.OffSet(m_nOffsetPosX, m_nOffsetPosY);
}

void NFGameFish::AddKilledCrabPart(KilledCrabPart killedCrabPart)
{
    m_aryKilledCrabPart.push_back(killedCrabPart);

    if (killedCrabPart.m_iPartId == 1)
    {
        if (m_fishKind.vectSubFishes.size() > 0)
        {
            m_fishKind.vectSubFishes[0] = 0;
        }
    }
    else if (killedCrabPart.m_iPartId == 2)
    {
        if (m_fishKind.vectSubFishes.size() > 1)
        {
            m_fishKind.vectSubFishes[1] = 0;
        }
    }
}

KilledCrabPartList &NFGameFish::GetKilledCrabParts()
{
    return m_aryKilledCrabPart;
}

int NFGameFish::GetKillMyCrabPartCount(uint64_t llPlayerId)
{
    int count = 0;
    for (int i = 0; i < m_aryKilledCrabPart.size(); i++)
    {
        KilledCrabPart *pPart = &m_aryKilledCrabPart[i];
        if (pPart != NULL)
        {
            if (pPart->m_llPlayerId == llPlayerId)
            {
                count++;
            }
        }
    }

    return count;
}

int NFGameFish::GetKillAllCrabPartCount()
{
    int count = 0;
    for (int i = 0; i < m_aryKilledCrabPart.size(); i++)
    {
        KilledCrabPart *pPart = &m_aryKilledCrabPart[i];
        if (pPart != NULL)
        {
            count++;
        }
    }

    return count;
}

bool NFGameFish::IsCanKill(NFIPluginManager *pPluginManager, uint32_t roomId, int iSubFishKind)
{
    auto pFishConfigDesc = NFFishConfigConfig::GetObjByHashKey(pPluginManager, roomId);
    CHECK_NULL(pFishConfigDesc);
    FishConfig *pFishConfig = pFishConfigDesc->GetFishBaseInfo(m_nFishKind);
    if (pFishConfig != NULL)
    {
        for (int i = 0; i < (int) pFishConfig->vectDamageFishIds.size(); i++)
        {
            uint8_t *pKillSubKind = &pFishConfig->vectDamageFishIds[i];
            if (pKillSubKind != NULL)
            {
                if (*pKillSubKind == iSubFishKind)
                {
                    return true;
                }
            }
        }
    }

    return false;
}
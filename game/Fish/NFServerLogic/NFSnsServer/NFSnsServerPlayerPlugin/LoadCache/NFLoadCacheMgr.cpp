// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheMgr
//
// -------------------------------------------------------------------------

#include "NFLoadCacheMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "Cache/NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Trans/NFQueryRole.h"
#include "Trans/NFTransGetRoleSimple.h"
#include "Trans/NFTransGetRoleDetail.h"
#include "Trans/NFTransCacheBase.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFLoadCacheMgr, EOT_SNS_LOAD_CACHE_MGR_ID, NFShmObj)

NFLoadCacheMgr::NFLoadCacheMgr() : NFShmObj()
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

NFLoadCacheMgr::~NFLoadCacheMgr()
{
}

int NFLoadCacheMgr::CreateInit()
{
    flag = true;

    m_refreshTimer = SetTimer(100, 0, 0, 0, 1, 0);
    return 0;
}

int NFLoadCacheMgr::ResumeInit()
{
    return 0;
}

int NFLoadCacheMgr::OnTimer(int timeId, int callcount)
{
    if (timeId == m_refreshTimer)
    {
        RefreshSimpleQueue();
        RefreshDetailQueue();
    }
    return 0;
}

int NFLoadCacheMgr::RefreshSimpleQueue()
{
    uint64_t timeNow = NFTime::Now().UnixSec();

    for (auto loadIter = m_roleSimpleLoadingMap.begin(); loadIter != m_roleSimpleLoadingMap.end();)
    {
        auto pInfo = &loadIter->second;
        for (auto roleIter = pInfo->m_transInfo.begin(); roleIter != pInfo->m_transInfo.end();)
        {
            if ((timeNow - roleIter->second) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.empty())
        {
            loadIter = m_roleSimpleLoadingMap.erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_roleSimpleLoadingMap.full() && !m_roleSimpleWaitLoadMap.empty() && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_roleSimpleWaitLoadMap.begin();
        auto pWaitLoadData = &waitIter->second;
        CHECK_EXPR_ASSERT(pWaitLoadData, -1, "m_roleWaitLoadMap Begin Failed");

        NFLoadCacheData* pNewLoading = NULL;
        auto pNewLoading_iter = m_roleSimpleLoadingMap.find(pWaitLoadData->m_playerId);
        if (pNewLoading_iter == m_roleSimpleLoadingMap.end())
        {
            pNewLoading = &m_roleSimpleLoadingMap[pWaitLoadData->m_playerId];
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_playerId);
        }
        else {
            pNewLoading = &pNewLoading_iter->second;
        }

        *pNewLoading = *pWaitLoadData;
        m_roleSimpleWaitLoadMap.erase(waitIter);

        int retCode = TransGetRoleSimpleInfo(pNewLoading);
        if (retCode != 0)
        {
            return retCode;
        }
    }

    return 0;
}

int NFLoadCacheMgr::RefreshDetailQueue()
{
    uint64_t timeNow = NFTime::Now().UnixSec();

    for (auto loadIter = m_roleDetailLoadingMap.begin(); loadIter != m_roleDetailLoadingMap.end();)
    {
        auto pInfo = &loadIter->second;
        for (auto roleIter = pInfo->m_transInfo.begin(); roleIter != pInfo->m_transInfo.end();)
        {
            if ((timeNow - roleIter->second) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.empty())
        {
            loadIter = m_roleDetailLoadingMap.erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_roleDetailLoadingMap.full() && !m_roleDetailWaitLoadMap.empty() && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_roleDetailWaitLoadMap.begin();
        auto pWaitLoadData = &waitIter->second;

        NFLoadCacheData* pNewLoading = NULL;
        auto pNewLoading_iter = m_roleDetailLoadingMap.find(pWaitLoadData->m_playerId);
        if (pNewLoading_iter == m_roleDetailLoadingMap.end())
        {
            pNewLoading = &m_roleDetailLoadingMap[pWaitLoadData->m_playerId];
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_playerId);
        }
        else {
            pNewLoading = &pNewLoading_iter->second;
        }

        *pNewLoading = *pWaitLoadData;
        m_roleDetailWaitLoadMap.erase(waitIter);

        int retCode = TransGetRoleDetailInfo(pNewLoading);
        if (retCode != 0)
        {
            return retCode;
        }
    }

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleSimpleTransFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_roleSimpleLoadingMap.find(roleId);
    if (pLoadingData_iter != m_roleSimpleLoadingMap.end())
    {
        auto pLoadingData = &pLoadingData_iter->second;
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData->m_transInfo.begin(); iter != pLoadingData->m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleSimpleRes(iRunLogicRetCode, roleId);
                }
            }
        }

        m_roleSimpleLoadingMap.erase(roleId);
    }

    RefreshSimpleQueue();

    return 0;
}

int NFLoadCacheMgr::GetRoleSimpleInfo(uint64_t roleId, int transId, uint64_t time)
{
    if (roleId <= 0)
        return 0;

    if (transId <= 0)
    {
        transId = -1;
    }

    auto pLoadingData = m_roleSimpleLoadingMap.find(roleId);
    if (pLoadingData != m_roleSimpleLoadingMap.end())
    {
        pLoadingData->second.AddTrans(transId, time);
        return 0;
    }

    if (!m_roleSimpleLoadingMap.full() && m_roleSimpleWaitLoadMap.empty()
        && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_roleSimpleLoadingMap[roleId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = roleId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleSimpleInfo(pRoleInfo);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        auto pstFind_iter = m_roleSimpleWaitLoadMap.find(roleId);
        if (pstFind_iter != m_roleSimpleWaitLoadMap.end())
        {
            if (pstFind_iter->second.AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_roleSimpleWaitLoadMap.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = &m_roleSimpleWaitLoadMap[roleId];
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_sRoleStatic Insert Failed, roleId:{}", roleId);
                return -1;
            }

            pTmpData->m_playerId = roleId;
            if (pTmpData->AddTrans(transId, time))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFLoadCacheData AddTrans Failed, roleId:{}", roleId);
                return -1;
            }
        }
    }

    return 0;
}

int NFLoadCacheMgr::GetCheckedRoleSimpleInfo(uint64_t roleId)
{
    NFPlayerSimple *pSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryRoleSimple(roleId, false);
    if(pSimple)
    {
        NFPlayerDetail* pDetail = NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleDetail(roleId);
        if(pDetail)
        {
            return 0;
        }
        else
        {
            return GetRoleDetailInfo(roleId, 0, NFTime::Now().UnixSec());
        }
    }

    return GetRoleSimpleInfo(roleId, 0, NFTime::Now().UnixSec());
}

int NFLoadCacheMgr::TransGetRoleSimpleInfo(NFLoadCacheData *data)
{
    NFTransGetRoleSimple *pTrans = (NFTransGetRoleSimple *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleSimple Failed! UsedItem:{}",
                   NFTransGetRoleSimple::GetUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(data->m_playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->m_playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

int NFLoadCacheMgr::GetRoleDetailInfo(uint64_t roleId, int transId, uint32_t time)
{
    if (roleId <= 0)
        return 0;

    if (transId <= 0)
    {
        transId = -1;
    }

    auto pLoadingData_iter = m_roleDetailLoadingMap.find(roleId);
    if (pLoadingData_iter != m_roleDetailLoadingMap.end())
    {
        pLoadingData_iter->second.AddTrans(transId, time);
        return 0;
    }

    if (!m_roleDetailLoadingMap.full() && m_roleDetailWaitLoadMap.empty()
        && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = &m_roleDetailLoadingMap[roleId];
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_playerId = roleId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleDetailInfo(pRoleInfo);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        auto pstFind_iter = m_roleDetailWaitLoadMap.find(roleId);
        if (pstFind_iter != m_roleDetailWaitLoadMap.end())
        {
            if (pstFind_iter->second.AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_roleDetailWaitLoadMap.full())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = &m_roleDetailWaitLoadMap[roleId];
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap Insert Failed, roleId:{}", roleId);
                return -1;
            }

            pTmpData->m_playerId = roleId;
            if (pTmpData->AddTrans(transId, time))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "NFLoadCacheData AddTrans Failed, roleId:{}", roleId);
                return -1;
            }
        }
    }

    return 0;
}

int NFLoadCacheMgr::TransGetRoleDetailInfo(NFLoadCacheData *data)
{
    NFTransGetRoleDetail *pTrans = (NFTransGetRoleDetail *) FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_GET_ROLE_DETAIL_ID);
    if (!pTrans)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, " Create Trans NFTransGetRoleDetail Failed! UsedItem:{}",
                   NFTransGetRoleDetail::GetUsedCount(m_pObjPluginManager));
        return -1;
    }

    if (pTrans->QueryRole(data->m_playerId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->m_playerId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleDetailTransFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData_iter = m_roleDetailLoadingMap.find(roleId);
    if (pLoadingData_iter != m_roleDetailLoadingMap.end())
    {
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData_iter->second.m_transInfo.begin(); iter != pLoadingData_iter->second.m_transInfo.end(); iter++)
        {
            if (iter->first > 0 && (timeNow - iter->second) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->first);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleDetailRes(iRunLogicRetCode, roleId);
                }
            }
        }

        m_roleDetailLoadingMap.erase(roleId);
    }

    RefreshDetailQueue();

    return 0;
}


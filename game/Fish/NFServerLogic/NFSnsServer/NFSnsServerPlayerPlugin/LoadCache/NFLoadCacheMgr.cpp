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

    for (auto loadIter = m_roleSimpleLoadingMap.Begin(); loadIter != m_roleSimpleLoadingMap.End();)
    {
        auto pInfo = loadIter->second;
        for (auto roleIter = pInfo->m_transInfo.Begin(); roleIter != pInfo->m_transInfo.End();)
        {
            if ((timeNow - roleIter->m_loadTime) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.Erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.IsEmpty())
        {
            loadIter = m_roleSimpleLoadingMap.Erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_roleSimpleLoadingMap.IsFull() && !m_roleSimpleWaitLoadMap.IsEmpty() && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_roleSimpleWaitLoadMap.Begin();
        auto pWaitLoadData = waitIter->second;
        CHECK_EXPR_ASSERT(pWaitLoadData, -1, "m_roleWaitLoadMap Begin Failed");

        auto pNewLoading = m_roleSimpleLoadingMap.Find(pWaitLoadData->m_roleId);
        if (pNewLoading == NULL)
        {
            pNewLoading = m_roleSimpleLoadingMap.Insert(pWaitLoadData->m_roleId);
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_roleId);
        }

        *pNewLoading = *pWaitLoadData;
        m_roleSimpleWaitLoadMap.Erase(waitIter);

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

    for (auto loadIter = m_roleDetailLoadingMap.Begin(); loadIter != m_roleDetailLoadingMap.End();)
    {
        auto pInfo = loadIter->second;
        for (auto roleIter = pInfo->m_transInfo.Begin(); roleIter != pInfo->m_transInfo.End();)
        {
            if ((timeNow - roleIter->m_loadTime) >= TRANS_SNS_BASE_TIMEOUT)
            {
                roleIter = pInfo->m_transInfo.Erase(roleIter);
            }
            else
            {
                ++roleIter;
            }
        }

        if (pInfo->m_transInfo.IsEmpty())
        {
            loadIter = m_roleDetailLoadingMap.Erase(loadIter);
        }
        else
        {
            ++loadIter;
        }
    }

    while (!m_roleDetailLoadingMap.IsFull() && !m_roleDetailWaitLoadMap.IsEmpty() && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto waitIter = m_roleDetailWaitLoadMap.Begin();
        auto pWaitLoadData = waitIter->second;
        CHECK_EXPR_ASSERT(pWaitLoadData, -1, "m_roleWaitLoadMap.GetByIndex Index:{} Failed", *waitIter.m_staticListIter);

        auto pNewLoading = m_roleDetailLoadingMap.Find(pWaitLoadData->m_roleId);
        if (pNewLoading == NULL)
        {
            pNewLoading = m_roleDetailLoadingMap.Insert(pWaitLoadData->m_roleId);
            CHECK_EXPR_ASSERT(pNewLoading, -1, "m_RoleLoadingMap.Insert RoleId:{} Failed", pWaitLoadData->m_roleId);
        }

        *pNewLoading = *pWaitLoadData;
        m_roleDetailWaitLoadMap.Erase(waitIter);

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
    auto pLoadingData = m_roleSimpleLoadingMap.Find(roleId);
    if (pLoadingData)
    {
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData->m_transInfo.Begin(); iter != pLoadingData->m_transInfo.End(); iter++)
        {
            if (iter->m_transId > 0 && (timeNow - iter->m_loadTime) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->m_transId);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleSimpleRes(iRunLogicRetCode, roleId);
                }
            }
        }

        m_roleSimpleLoadingMap.Erase(roleId);
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
    if (pLoadingData)
    {
        pLoadingData->Add(transId, time);
        return 0;
    }

    if (!m_roleSimpleLoadingMap.IsFull() && m_roleSimpleWaitLoadMap.IsEmpty()
        && NFTransGetRoleSimple::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = m_roleSimpleLoadingMap.Insert(roleId);
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_roleId = roleId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleSimpleInfo(pRoleInfo);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        NFLoadCacheData *pstFind = m_roleSimpleWaitLoadMap.Find(roleId);
        if (pstFind)
        {
            if (pstFind->AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_roleSimpleWaitLoadMap.IsFull())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = m_roleSimpleWaitLoadMap.Insert(roleId);
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_sRoleStatic Insert Failed, roleId:{}", roleId);
                return -1;
            }

            pTmpData->m_roleId = roleId;
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
    NFRoleSimple *pSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryRoleSimple(roleId, false);
    if(pSimple)
    {
        NFRoleDetail* pDetail = NFCacheMgr::Instance(m_pObjPluginManager)->GetRoleDetail(roleId);
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

    if (pTrans->QueryRole(data->m_roleId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->m_roleId);
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

    auto pLoadingData = m_roleDetailLoadingMap.Find(roleId);
    if (pLoadingData)
    {
        pLoadingData->AddTrans(transId, time);
        return 0;
    }

    if (!m_roleDetailLoadingMap.IsFull() && m_roleDetailWaitLoadMap.IsEmpty()
        && NFTransGetRoleDetail::GetFreeCount(m_pObjPluginManager) > 0)
    {
        auto pRoleInfo = m_roleDetailLoadingMap.Insert(roleId);
        NF_ASSERT(pRoleInfo);
        pRoleInfo->m_roleId = roleId;
        pRoleInfo->AddTrans(transId, time);

        int retCode = TransGetRoleDetailInfo(pRoleInfo);
        if (retCode != 0)
        {
            return -1;
        }
    }
    else
    {
        NFLoadCacheData *pstFind = m_roleDetailWaitLoadMap.Find(roleId);
        if (pstFind)
        {
            if (pstFind->AddTrans(transId, time) != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "pstFind->AddTrans(transId, time) Failed");
                return -1;
            }
        }
        else
        {
            if (m_roleDetailWaitLoadMap.IsFull())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap full");
                return -1;
            }

            NFLoadCacheData *pTmpData = m_roleDetailWaitLoadMap.Insert(roleId);
            if (pTmpData == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_roleDetailWaitLoadMap Insert Failed, roleId:{}", roleId);
                return -1;
            }

            pTmpData->m_roleId = roleId;
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

    if (pTrans->QueryRole(data->m_roleId) != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "query role error {}", data->m_roleId);
        pTrans->SetFinished(-1);
    }

    return 0;
}

int NFLoadCacheMgr::HandleGetRoleDetailTransFinished(int iRunLogicRetCode, uint64_t roleId)
{
    uint32_t timeNow = NFTime::Now().UnixSec();
    auto pLoadingData = m_roleDetailLoadingMap.Find(roleId);
    if (pLoadingData)
    {
        // 判断时间，是确保返回的时候，transid没有失效，而且transid对应的obj也是对的
        for (auto iter = pLoadingData->m_transInfo.Begin(); iter != pLoadingData->m_transInfo.End(); iter++)
        {
            if (iter->m_transId > 0 && (timeNow - iter->m_loadTime) < TRANS_ACTIVE_TIMEOUT)
            {
                NFTransBase *pTransBase = FindModule<NFISharedMemModule>()->GetTrans(iter->m_transId);
                if (pTransBase)
                {
                    NFTransCacheBase *pTransRoleBase = dynamic_cast<NFTransCacheBase *>(pTransBase);
                    pTransRoleBase->HandleGetRoleDetailRes(iRunLogicRetCode, roleId);
                }
            }
        }

        m_roleDetailLoadingMap.Erase(roleId);
    }

    RefreshDetailQueue();

    return 0;
}


// -------------------------------------------------------------------------
//    @FileName         :    NFTransCacheBase.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransCacheBase
//
// -------------------------------------------------------------------------

#include "NFTransCacheBase.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "Cache/NFCacheMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransCacheBase, EOT_SNS_TRANS_CACHE_BASE_ID, NFTransBase)

NFTransCacheBase::NFTransCacheBase() : NFTransBase()
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

NFTransCacheBase::~NFTransCacheBase()
{
}

int NFTransCacheBase::CreateInit()
{
    m_bNotify = false;
    m_reqTrans = 0;
    m_bGetDetail= true;
    return 0;
}

int NFTransCacheBase::ResumeInit()
{
    return 0;
}

int NFTransCacheBase::Init(int reqTrans)
{
    m_query.CreateInit();
    m_reqTrans = reqTrans;
    return 0;
}

bool NFTransCacheBase::IsTimeOut()
{
    if (NFTime::Now().UnixSec() >= m_dwKeepAliveTime + TRANS_SNS_BASE_TIMEOUT)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "This Trans TimeOut Name:{} Type:{} Info:{}", GetClassName(), GetClassType(),
                   DebugString());
        OnTimeOut();
        return true;
    }
    return false;
}

int NFTransCacheBase::HandleGetRoleSimpleRes(int iRunLogicRetCode, uint64_t roleId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    AddQueryedSimpleNum();
    if (iRunLogicRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Query Role Simple Data Failed From DB, roleId:{} retCode:{}", roleId, iRunLogicRetCode);
    }

    if (IsQuerySimpleFinished())
    {
        if (m_bGetDetail)
        {
            QueryRoleDetail();
        }
        else
        {
            int iRetCode = QueryRole_CallBack(m_query);
            SetFinished(iRetCode);
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransCacheBase::QueryRoleSimple(NFQueryRole &query)
{
    m_query = query;
    return QueryRoleSimple();
}

int NFTransCacheBase::QueryRoleSimple(uint64_t roleID)
{
    m_query.Add(roleID);
    return QueryRoleSimple();
}

int NFTransCacheBase::QueryRoleSimple()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    for (int i = 0; i < (int)m_query.m_queryRoleList.size(); i++)
    {
        if (m_query.m_queryRoleList[i] == 0)
        {
            AddQueryedSimpleNum();
            continue;
        }

        if (NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimple(m_query.m_queryRoleList[i]))
        {
            AddQueryedSimpleNum();
        }
        else
        {
            NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfo(m_query.m_queryRoleList[i], GetGlobalId(),
                                                                                  m_dwKeepAliveTime);
        }
    }

    if (IsQuerySimpleFinished())
    {
        if (m_bGetDetail)
        {
            QueryRoleDetail();
        }
        else
        {
            int iRetCode = QueryRole_CallBack(m_query);
            SetFinished(iRetCode);
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransCacheBase::QueryRole_CallBack(NFQueryRole &query)
{
    return 0;
}

int NFTransCacheBase::QueryRoleDetail()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    for (int i = 0; i < (int)m_query.m_queryRoleList.size(); i++) {
        if (m_query.m_queryRoleList[i] == 0) {
            AddQueryedDetailNum();
            continue;
        }

        NFPlayerDetail* pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetail(m_query.m_queryRoleList[i]);
        if (pRoleDetail)
        {
            AddQueryedDetailNum();
            continue;
        }
        else
        {
            NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetailInfo(m_query.m_queryRoleList[i], GetGlobalId(),
                                                                                  m_dwKeepAliveTime);
        }
    }

    if (IsQueryDetailFinished())
    {
        int iRetCode = QueryRole_CallBack(m_query);
        SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransCacheBase::HandleGetRoleDetailRes(int iRunLogicRetCode, uint64_t roleId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    AddQueryedDetailNum();
    if (iRunLogicRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Query Role Detail Data Failed From DB, roleId:{} retCode:{}", roleId, iRunLogicRetCode);
    }

    if (IsQueryDetailFinished())
    {
        int iRetCode = QueryRole_CallBack(m_query);
        SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

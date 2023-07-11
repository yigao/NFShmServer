// -------------------------------------------------------------------------
//    @FileName         :    NFCacheMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFCacheMgr
//
// -------------------------------------------------------------------------

#include "NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFCacheMgr, EOT_SNS_CACHE_MGR_ID, NFShmObj)

NFCacheMgr::NFCacheMgr() : NFShmObj()
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

NFCacheMgr::~NFCacheMgr()
{
}

int NFCacheMgr::CreateInit()
{
    return 0;
}

int NFCacheMgr::ResumeInit()
{
    return 0;
}

int NFCacheMgr::ReleaseSimpleCount(int num)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "rolesimple release count :{} maxcount :{} usecount :{}", num, NFPlayerSimple::GetItemCount(m_pObjPluginManager), NFPlayerSimple::GetUsedCount(m_pObjPluginManager));
    FindModule<NFISharedMemModule>()->DestroyObjAutoErase(EOT_SNS_ROLE_SIMPLE_ID, NFPlayerSimple::GetItemCount(m_pObjPluginManager) >= num ? NFPlayerSimple::GetItemCount(m_pObjPluginManager) - num : 0, [](NFShmObj* pObj) -> bool {
        NFPlayerSimple *pUser = dynamic_cast<NFPlayerSimple*>(pObj);
        if (pUser)
        {
            if (pUser->CanDelete())
            {
                return true;
            }
        }
        return false;
    });
    return 0;
}

NFPlayerSimple *NFCacheMgr::GetRoleSimple(uint64_t roleId)
{
    return dynamic_cast<NFPlayerSimple*>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_SNS_ROLE_SIMPLE_ID, roleId));
}

NFPlayerSimple *NFCacheMgr::CreateRoleSimple(uint64_t roleId)
{
    NFPlayerSimple *pRoleSimple = GetRoleSimple(roleId);
    CHECK_EXPR(pRoleSimple == NULL, NULL, "Create Role Simple Failed, data exist, roleId:{}", roleId);

    if (NFPlayerSimple::GetItemCount(m_pObjPluginManager) - NFPlayerSimple::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseSimpleCount(NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleSimple = dynamic_cast<NFPlayerSimple *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_SNS_ROLE_SIMPLE_ID, roleId));
    CHECK_EXPR(pRoleSimple, NULL, "Create Role Simple Obj Failed, playerID:{}", roleId);

    pRoleSimple->SetRoleId(roleId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Role Simple Success, userId:{} globalId:{}", roleId,
              pRoleSimple->GetGlobalId());
    return pRoleSimple;
}

int NFCacheMgr::DeleteRoleSimple(NFPlayerSimple *pRoleSimple)
{
    CHECK_NULL(pRoleSimple);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Simple Info, RoleId:{}, gloablId:{}", pRoleSimple->GetPlayerId(), pRoleSimple->GetGlobalId());

    FindModule<NFISharedMemModule>()->DestroyObj(pRoleSimple);

    return 0;
}

NFPlayerSimple *NFCacheMgr::QueryRoleSimple(uint64_t role_id, bool query)
{
    NFPlayerSimple *pSimple = GetRoleSimple(role_id);
    if (pSimple)
    {
        return pSimple;
    }

    if (query == true)
    {
        NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleSimpleInfo(role_id, 0, NFTime::Now().UnixSec());
    }

    return NULL;
}

int NFCacheMgr::ReleaseDetailCount(int num)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "role detail release count :{} maxcount :{} usecount :{}", num, NFPlayerDetail::GetItemCount(m_pObjPluginManager), NFPlayerDetail::GetUsedCount(m_pObjPluginManager));
    FindModule<NFISharedMemModule>()->DestroyObjAutoErase(EOT_SNS_ROLE_DETAIL_ID, NFPlayerDetail::GetItemCount(m_pObjPluginManager) >= num ? NFPlayerDetail::GetItemCount(m_pObjPluginManager) - num : 0, [](NFShmObj* pObj) -> bool {
        NFPlayerDetail *pUser = dynamic_cast<NFPlayerDetail*>(pObj);
        if (pUser)
        {
            if (pUser->CanDelete())
            {
                return true;
            }
        }
        return false;
    });
    return 0;
}

NFPlayerDetail *NFCacheMgr::GetRoleDetail(uint64_t roleId)
{
    return dynamic_cast<NFPlayerDetail*>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_SNS_ROLE_DETAIL_ID, roleId));
}

NFPlayerDetail *NFCacheMgr::CreateRoleDetail(uint64_t roleId)
{
    NFPlayerDetail *pRoleDetail= GetRoleDetail(roleId);
    CHECK_EXPR(pRoleDetail == NULL, NULL, "Create Role Detail Failed, data exist, roleId:{}", roleId);

    if (NFPlayerDetail::GetItemCount(m_pObjPluginManager) - NFPlayerDetail::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseDetailCount(NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleDetail = dynamic_cast<NFPlayerDetail *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_SNS_ROLE_DETAIL_ID, roleId));
    CHECK_EXPR(pRoleDetail, NULL, "Create Role Detail Obj Failed, playerID:{}", roleId);

    pRoleDetail->SetRoleId(roleId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Role Detail Success, userId:{} globalId:{}", roleId,
              pRoleDetail->GetGlobalId());
    return pRoleDetail;
}

int NFCacheMgr::DeleteRoleDetail(NFPlayerDetail *pRoleDetail)
{
    CHECK_NULL(pRoleDetail);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, RoleId:{}, gloablId:{}", pRoleDetail->GetRoleId(), pRoleDetail->GetGlobalId());

    FindModule<NFISharedMemModule>()->DestroyObj(pRoleDetail);

    return 0;
}

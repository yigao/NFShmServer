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
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "rolesimple release count :{} maxcount :{} usecount :{}", num, NFRoleSimple::GetItemCount(m_pObjPluginManager), NFRoleSimple::GetUsedCount(m_pObjPluginManager));
    FindModule<NFISharedMemModule>()->DestroyObjAutoErase(EOT_SNS_ROLE_SIMPLE_ID, NFRoleSimple::GetItemCount(m_pObjPluginManager) >= num ? NFRoleSimple::GetItemCount(m_pObjPluginManager) - num : 0, [](NFShmObj* pObj) -> bool {
        NFRoleSimple *pUser = dynamic_cast<NFRoleSimple*>(pObj);
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

NFRoleSimple *NFCacheMgr::GetPlayerSimple(uint64_t roleId)
{
    return dynamic_cast<NFRoleSimple*>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_SNS_ROLE_SIMPLE_ID, roleId));
}

NFRoleSimple *NFCacheMgr::CreatePlayerSimple(uint64_t playerId)
{
    NFRoleSimple *pRoleSimple = GetRoleSimple(playerId);
    CHECK_EXPR(pRoleSimple == NULL, NULL, "Create Role Simple Failed, data exist, roleId:{}", playerId);

    if (NFRoleSimple::GetItemCount(m_pObjPluginManager) - NFRoleSimple::GetUsedCount(m_pObjPluginManager) <=
        NFRoleSimple::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseSimpleCount(NFRoleSimple::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleSimple = dynamic_cast<NFRoleSimple *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_SNS_ROLE_SIMPLE_ID, playerId));
    CHECK_EXPR(pRoleSimple, NULL, "Create Role Simple Obj Failed, playerID:{}", playerId);

    pRoleSimple->SetRoleId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Role Simple Success, userId:{} globalId:{}", playerId,
              pRoleSimple->GetGlobalId());
    return pRoleSimple;
}

int NFCacheMgr::DeleteRoleSimple(NFRoleSimple *pRoleSimple)
{
    CHECK_NULL(pRoleSimple);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Simple Info, RoleId:{}, gloablId:{}", pRoleSimple->GetRoleId(), pRoleSimple->GetGlobalId());

    FindModule<NFISharedMemModule>()->DestroyObj(pRoleSimple);

    return 0;
}

NFRoleSimple *NFCacheMgr::QueryRoleSimple(uint64_t role_id, bool query)
{
    NFRoleSimple *pSimple = GetRoleSimple(role_id);
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
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "role detail release count :{} maxcount :{} usecount :{}", num, NFRoleDetail::GetItemCount(m_pObjPluginManager), NFRoleDetail::GetUsedCount(m_pObjPluginManager));
    FindModule<NFISharedMemModule>()->DestroyObjAutoErase(EOT_SNS_ROLE_DETAIL_ID, NFRoleDetail::GetItemCount(m_pObjPluginManager) >= num ? NFRoleDetail::GetItemCount(m_pObjPluginManager) - num : 0, [](NFShmObj* pObj) -> bool {
        NFRoleDetail *pUser = dynamic_cast<NFRoleDetail*>(pObj);
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

NFRoleDetail *NFCacheMgr::GetRoleDetail(uint64_t roleId)
{
    return dynamic_cast<NFRoleDetail*>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_SNS_ROLE_DETAIL_ID, roleId));
}

NFRoleDetail *NFCacheMgr::CreateRoleDetail(uint64_t roleId)
{
    NFRoleDetail *pRoleDetail= GetRoleDetail(roleId);
    CHECK_EXPR(pRoleDetail == NULL, NULL, "Create Role Detail Failed, data exist, roleId:{}", roleId);

    if (NFRoleDetail::GetItemCount(m_pObjPluginManager) - NFRoleDetail::GetUsedCount(m_pObjPluginManager) <=
            NFRoleDetail::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseDetailCount(NFRoleDetail::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleDetail = dynamic_cast<NFRoleDetail *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_SNS_ROLE_DETAIL_ID, roleId));
    CHECK_EXPR(pRoleDetail, NULL, "Create Role Detail Obj Failed, playerID:{}", roleId);

    pRoleDetail->SetRoleId(roleId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Role Detail Success, userId:{} globalId:{}", roleId,
              pRoleDetail->GetGlobalId());
    return pRoleDetail;
}

int NFCacheMgr::DeleteRoleDetail(NFRoleDetail *pRoleDetail)
{
    CHECK_NULL(pRoleDetail);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, RoleId:{}, gloablId:{}", pRoleDetail->GetRoleId(), pRoleDetail->GetGlobalId());

    FindModule<NFISharedMemModule>()->DestroyObj(pRoleDetail);

    return 0;
}

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
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

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
    NFPlayerSimple::DestroyObjAutoErase(m_pObjPluginManager, num, [](NFShmObj* pObj) -> bool {
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

NFPlayerSimple *NFCacheMgr::GetPlayerSimple(uint64_t roleId)
{
    return NFPlayerSimple::GetObjByHashKey(m_pObjPluginManager, roleId);
}

NFPlayerSimple *NFCacheMgr::CreatePlayerSimple(uint64_t playerId)
{
    NFPlayerSimple *pRoleSimple = GetPlayerSimple(playerId);
    CHECK_EXPR(pRoleSimple == NULL, NULL, "Create Role Simple Failed, data exist, roleId:{}", playerId);

    if (NFPlayerSimple::GetItemCount(m_pObjPluginManager) - NFPlayerSimple::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseSimpleCount(NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleSimple = NFPlayerSimple::CreateObjByHashKey(m_pObjPluginManager, playerId);
    CHECK_EXPR(pRoleSimple, NULL, "Create Role Simple Obj Failed, playerID:{}", playerId);

    pRoleSimple->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Simple Success, userId:{} globalId:{}", playerId,
              pRoleSimple->GetGlobalId());
    return pRoleSimple;
}

int NFCacheMgr::DeleteRoleSimple(NFPlayerSimple *pRoleSimple)
{
    CHECK_NULL(pRoleSimple);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Simple Info, RoleId:{}, gloablId:{}", pRoleSimple->GetPlayerId(), pRoleSimple->GetGlobalId());

    NFPlayerSimple::DestroyObj(m_pObjPluginManager, pRoleSimple);

    return 0;
}

NFPlayerSimple *NFCacheMgr::QueryRoleSimple(uint64_t role_id, bool query)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(role_id);
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
    NFPlayerDetail::DestroyObjAutoErase(m_pObjPluginManager, num, [](NFShmObj* pObj) -> bool {
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

NFPlayerDetail *NFCacheMgr::GetRoleDetail(uint64_t playerId)
{
    return NFPlayerDetail::GetObjByHashKey(m_pObjPluginManager, playerId);
}

NFPlayerDetail *NFCacheMgr::CreateRoleDetail(uint64_t playerId)
{
    NFPlayerDetail *pRoleDetail= GetRoleDetail(playerId);
    CHECK_EXPR(pRoleDetail == NULL, NULL, "Create Role Detail Failed, data exist, roleId:{}", playerId);

    if (NFPlayerDetail::GetItemCount(m_pObjPluginManager) - NFPlayerDetail::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseDetailCount(NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleDetail = NFPlayerDetail::CreateObjByHashKey(m_pObjPluginManager, playerId);
    CHECK_EXPR(pRoleDetail, NULL, "Create Role Detail Obj Failed, playerID:{}", playerId);

    pRoleDetail->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Detail Success, userId:{} globalId:{}", playerId,
              pRoleDetail->GetGlobalId());
    return pRoleDetail;
}

int NFCacheMgr::DeleteRoleDetail(NFPlayerDetail *pRoleDetail)
{
    CHECK_NULL(pRoleDetail);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, RoleId:{}, gloablId:{}", pRoleDetail->GetRoleId(), pRoleDetail->GetGlobalId());

    NFPlayerDetail::DestroyObj(m_pObjPluginManager, pRoleDetail);

    return 0;
}

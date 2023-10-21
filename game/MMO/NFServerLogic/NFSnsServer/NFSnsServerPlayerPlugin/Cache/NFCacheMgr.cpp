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

NFPlayerSimple *NFCacheMgr::GetPlayerSimple(uint64_t cid)
{
    return NFPlayerSimple::GetObjByHashKey(m_pObjPluginManager, cid);
}

NFPlayerSimple *NFCacheMgr::CreatePlayerSimple(uint64_t cid)
{
    NFPlayerSimple *pRoleSimple = GetPlayerSimple(cid);
    CHECK_EXPR(pRoleSimple == NULL, NULL, "Create Role Simple Failed, data exist, cid:{}", cid);

    if (NFPlayerSimple::GetItemCount(m_pObjPluginManager) - NFPlayerSimple::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseSimpleCount(NFPlayerSimple::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleSimple = NFPlayerSimple::CreateObjByHashKey(m_pObjPluginManager, cid);
    CHECK_EXPR(pRoleSimple, NULL, "Create Role Simple Obj Failed, cid:{}", cid);

    pRoleSimple->SetCid(cid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Simple Success, cid:{} globalId:{}", cid,
              pRoleSimple->GetGlobalId());
    return pRoleSimple;
}

int NFCacheMgr::DeletePlayerSimple(NFPlayerSimple *pRoleSimple)
{
    CHECK_NULL(pRoleSimple);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Simple Info, cid:{}, gloablId:{}", pRoleSimple->GetCid(), pRoleSimple->GetGlobalId());

    pRoleSimple->UnInit();
    NFPlayerSimple::DestroyObj(m_pObjPluginManager, pRoleSimple);

    return 0;
}

NFPlayerSimple *NFCacheMgr::QueryPlayerSimple(uint64_t cid)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(cid);
    if (pSimple)
    {
        return pSimple;
    }

    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfo(cid, 0, NFTime::Now().UnixSec());
    return NULL;
}

NFPlayerSimple* NFCacheMgr::QueryPlayerSimpleByRpc(uint64_t cid)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(cid);
    if (pSimple)
    {
        return pSimple;
    }

    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfoByRpc(cid, NFTime::Now().UnixSec());
}

NFPlayerSimple* NFCacheMgr::QueryPlayerSimpleByRpc(uint64_t cid, uint64_t query_id)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(query_id);
    if (pSimple)
    {
        return pSimple;
    }

    FindModule<NFICoroutineModule>()->AddUserCo(cid);
    pSimple = NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfoByRpc(query_id, NFTime::Now().UnixSec());
    FindModule<NFICoroutineModule>()->DelUserCo(cid);
    return pSimple;
}

NFPlayerDetail* NFCacheMgr::QueryPlayerDetailByRpc(uint64_t cid)
{
    NFPlayerDetail* pDetail = GetPlayerDetail(cid);
    if (pDetail)
    {
        return pDetail;
    }

    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetailInfoByRpc(cid, NFTime::Now().UnixSec());
}

std::pair<NFPlayerSimple*, NFPlayerDetail*> NFCacheMgr::QueryPlayerByRpc(uint64_t cid, uint64_t query_id)
{
    std::pair<NFPlayerSimple*, NFPlayerDetail*> data;
    data.first = GetPlayerSimple(query_id);
    data.second = GetPlayerDetail(query_id);

    if (data.first == NULL || data.second == NULL)
    {
        QueryPlayerDetailByRpc(cid, query_id);
        QueryPlayerSimpleByRpc(cid, query_id);
    }

    data.first = GetPlayerSimple(query_id);
    data.second = GetPlayerDetail(query_id);
    return data;
}

NFPlayerDetail* NFCacheMgr::QueryPlayerDetailByRpc(uint64_t cid, uint64_t query_id)
{
    NFPlayerDetail* pDetail = GetPlayerDetail(query_id);
    if (pDetail)
    {
        return pDetail;
    }

    FindModule<NFICoroutineModule>()->AddUserCo(cid);
    pDetail = NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetailInfoByRpc(query_id, NFTime::Now().UnixSec());
    FindModule<NFICoroutineModule>()->DelUserCo(cid);
    return pDetail;
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

NFPlayerDetail *NFCacheMgr::GetPlayerDetail(uint64_t cid)
{
    return NFPlayerDetail::GetObjByHashKey(m_pObjPluginManager, cid);
}

NFPlayerDetail *NFCacheMgr::CreatePlayerDetail(uint64_t cid)
{
    NFPlayerDetail *pRoleDetail= GetPlayerDetail(cid);
    CHECK_EXPR(pRoleDetail == NULL, NULL, "Create Role Detail Failed, data exist, cid:{}", cid);

    if (NFPlayerDetail::GetItemCount(m_pObjPluginManager) - NFPlayerDetail::GetUsedCount(m_pObjPluginManager) <=
        NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseDetailCount(NFPlayerDetail::GetItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleDetail = NFPlayerDetail::CreateObjByHashKey(m_pObjPluginManager, cid);
    CHECK_EXPR(pRoleDetail, NULL, "Create Role Detail Obj Failed, cid:{}", cid);

    pRoleDetail->SetCid(cid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Detail Success, cid:{} globalId:{}", cid,
              pRoleDetail->GetGlobalId());
    return pRoleDetail;
}

int NFCacheMgr::DeletePlayerDetail(NFPlayerDetail *pRoleDetail)
{
    CHECK_NULL(pRoleDetail);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, cid:{}, gloablId:{}", pRoleDetail->GetCid(), pRoleDetail->GetGlobalId());

    pRoleDetail->UnInit();
    NFPlayerDetail::DestroyObj(m_pObjPluginManager, pRoleDetail);

    return 0;
}

NFPlayerOnline *NFCacheMgr::GetPlayerOnline(uint64_t player)
{
    return NFPlayerOnline::GetObjByHashKey(m_pObjPluginManager, player);
}

NFPlayerOnline *NFCacheMgr::CreatePlayerOnline(uint64_t cid)
{
    NFPlayerOnline *pPlayerOnline = GetPlayerOnline(cid);
    CHECK_EXPR(pPlayerOnline == NULL, NULL, "Create Role Online Failed, data exist, cid:{}", cid);

    pPlayerOnline = NFPlayerOnline::CreateObjByHashKey(m_pObjPluginManager, cid);
    CHECK_EXPR(pPlayerOnline, NULL, "Create Role Online Obj Failed, cid:{}", cid);

    pPlayerOnline->SetCid(cid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Online Success, cid:{} globalId:{}", cid,
              pPlayerOnline->GetGlobalId());
    return pPlayerOnline;
}

int NFCacheMgr::DeletePlayerOnline(NFPlayerOnline *pRoleOnline)
{
    CHECK_NULL(pRoleOnline);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, cid:{}, gloablId:{}", pRoleOnline->GetCid(), pRoleOnline->GetGlobalId());

    pRoleOnline->UnInit();
    NFPlayerOnline::DestroyObj(m_pObjPluginManager, pRoleOnline);

    return 0;
}

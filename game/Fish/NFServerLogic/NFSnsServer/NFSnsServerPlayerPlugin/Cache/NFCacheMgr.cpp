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

NFCacheMgr::NFCacheMgr()
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
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "rolesimple release count :{} maxcount :{} usecount :{}", num, NFPlayerSimple::GetStaticItemCount(m_pObjPluginManager), NFPlayerSimple::GetStaticUsedCount(m_pObjPluginManager));
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

    if (NFPlayerSimple::GetStaticItemCount(m_pObjPluginManager) - NFPlayerSimple::GetStaticUsedCount(m_pObjPluginManager) <=
        NFPlayerSimple::GetStaticItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseSimpleCount(NFPlayerSimple::GetStaticItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleSimple = NFPlayerSimple::CreateObjByHashKey(m_pObjPluginManager, playerId);
    CHECK_EXPR(pRoleSimple, NULL, "Create Role Simple Obj Failed, playerID:{}", playerId);

    pRoleSimple->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Simple Success, userId:{} globalId:{}", playerId,
              pRoleSimple->GetGlobalId());
    return pRoleSimple;
}

int NFCacheMgr::DeletePlayerSimple(NFPlayerSimple *pRoleSimple)
{
    CHECK_NULL(pRoleSimple);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Simple Info, RoleId:{}, gloablId:{}", pRoleSimple->GetPlayerId(), pRoleSimple->GetGlobalId());

    pRoleSimple->UnInit();
    NFPlayerSimple::DestroyObj(m_pObjPluginManager, pRoleSimple);

    return 0;
}

NFPlayerSimple *NFCacheMgr::QueryPlayerSimple(uint64_t role_id)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(role_id);
    if (pSimple)
    {
        return pSimple;
    }

    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfo(role_id, 0, NFTime::Now().UnixSec());
    return NULL;
}

NFPlayerSimple* NFCacheMgr::QueryPlayerSimpleByRpc(uint64_t role_id)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(role_id);
    if (pSimple)
    {
        return pSimple;
    }

    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfoByRpc(role_id, NFTime::Now().UnixSec());
}

NFPlayerSimple* NFCacheMgr::QueryPlayerSimpleByRpc(uint64_t playerId, uint64_t query_id)
{
    NFPlayerSimple *pSimple = GetPlayerSimple(query_id);
    if (pSimple)
    {
        return pSimple;
    }

    FindModule<NFICoroutineModule>()->AddUserCo(playerId);
    pSimple = NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerSimpleInfoByRpc(query_id, NFTime::Now().UnixSec());
    FindModule<NFICoroutineModule>()->DelUserCo(playerId);
    return pSimple;
}

NFPlayerSimple* NFCacheMgr::CreatePlayerSimpleDBDataByRpc(const proto_ff::tbFishSnsPlayerSimpleData& dbData)
{
    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerSimpleDBDataByRpc(dbData);
}

NFPlayerDetail* NFCacheMgr::CreatePlayerDetailDBDataByRpc(const proto_ff::tbFishSnsPlayerDetailData& dbData)
{
    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->CreatePlayerDetailDBDataByRpc(dbData);
}

NFPlayerDetail* NFCacheMgr::QueryPlayerDetailByRpc(uint64_t role_id)
{
    NFPlayerDetail* pDetail = GetPlayerDetail(role_id);
    if (pDetail)
    {
        return pDetail;
    }

    return NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetailInfoByRpc(role_id, NFTime::Now().UnixSec());
}

std::pair<NFPlayerSimple*, NFPlayerDetail*> NFCacheMgr::QueryPlayerByRpc(uint64_t playerId, uint64_t query_id)
{
    std::pair<NFPlayerSimple*, NFPlayerDetail*> data;
    data.first = GetPlayerSimple(query_id);
    data.second = GetPlayerDetail(query_id);

    if (data.first == NULL || data.second == NULL)
    {
        QueryPlayerDetailByRpc(playerId, query_id);
        QueryPlayerSimpleByRpc(playerId, query_id);
    }

    data.first = GetPlayerSimple(query_id);
    data.second = GetPlayerDetail(query_id);
    return data;
}

NFPlayerDetail* NFCacheMgr::QueryPlayerDetailByRpc(uint64_t playerId, uint64_t query_id)
{
    NFPlayerDetail* pDetail = GetPlayerDetail(query_id);
    if (pDetail)
    {
        return pDetail;
    }

    FindModule<NFICoroutineModule>()->AddUserCo(playerId);
    pDetail = NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->GetPlayerDetailInfoByRpc(query_id, NFTime::Now().UnixSec());
    FindModule<NFICoroutineModule>()->DelUserCo(playerId);
    return pDetail;
}

int NFCacheMgr::ReleaseDetailCount(int num)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "role detail release count :{} maxcount :{} usecount :{}", num, NFPlayerDetail::GetStaticItemCount(m_pObjPluginManager), NFPlayerDetail::GetStaticUsedCount(m_pObjPluginManager));
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

NFPlayerDetail *NFCacheMgr::GetPlayerDetail(uint64_t roleId)
{
    return NFPlayerDetail::GetObjByHashKey(m_pObjPluginManager, roleId);
}

NFPlayerDetail *NFCacheMgr::CreatePlayerDetail(uint64_t playerId)
{
    NFPlayerDetail *pRoleDetail= GetPlayerDetail(playerId);
    CHECK_EXPR(pRoleDetail == NULL, NULL, "Create Role Detail Failed, data exist, roleId:{}", playerId);

    if (NFPlayerDetail::GetStaticItemCount(m_pObjPluginManager) - NFPlayerDetail::GetStaticUsedCount(m_pObjPluginManager) <=
        NFPlayerDetail::GetStaticItemCount(m_pObjPluginManager) * 0.1)
    {
        ReleaseDetailCount(NFPlayerDetail::GetStaticItemCount(m_pObjPluginManager) * 0.1);
    }

    pRoleDetail = NFPlayerDetail::CreateObjByHashKey(m_pObjPluginManager, playerId);
    CHECK_EXPR(pRoleDetail, NULL, "Create Role Detail Obj Failed, playerID:{}", playerId);

    pRoleDetail->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Detail Success, userId:{} globalId:{}", playerId,
              pRoleDetail->GetGlobalId());
    return pRoleDetail;
}

int NFCacheMgr::DeletePlayerDetail(NFPlayerDetail *pRoleDetail)
{
    CHECK_NULL(pRoleDetail);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, RoleId:{}, gloablId:{}", pRoleDetail->GetPlayerId(), pRoleDetail->GetGlobalId());

    pRoleDetail->UnInit();
    NFPlayerDetail::DestroyObj(m_pObjPluginManager, pRoleDetail);

    return 0;
}

NFPlayerOnline *NFCacheMgr::GetPlayerOnline(uint64_t player)
{
    return NFPlayerOnline::GetObjByHashKey(m_pObjPluginManager, player);
}

NFPlayerOnline *NFCacheMgr::CreatePlayerOnline(uint64_t playerId)
{
    NFPlayerOnline *pPlayerOnline = GetPlayerOnline(playerId);
    CHECK_EXPR(pPlayerOnline == NULL, NULL, "Create Role Online Failed, data exist, playerId:{}", playerId);

    pPlayerOnline = NFPlayerOnline::CreateObjByHashKey(m_pObjPluginManager, playerId);
    CHECK_EXPR(pPlayerOnline, NULL, "Create Role Online Obj Failed, playerID:{}", playerId);

    pPlayerOnline->SetPlayerId(playerId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "AddTrans Role Online Success, userId:{} globalId:{}", playerId,
              pPlayerOnline->GetGlobalId());
    return pPlayerOnline;
}

int NFCacheMgr::DeletePlayerOnline(NFPlayerOnline *pRoleOnline)
{
    CHECK_NULL(pRoleOnline);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Detail Info, RoleId:{}, gloablId:{}", pRoleOnline->GetPlayerId(), pRoleOnline->GetGlobalId());

    pRoleOnline->UnInit();
    NFPlayerOnline::DestroyObj(m_pObjPluginManager, pRoleOnline);

    return 0;
}

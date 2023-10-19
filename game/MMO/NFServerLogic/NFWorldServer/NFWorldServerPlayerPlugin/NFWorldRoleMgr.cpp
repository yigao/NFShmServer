// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoleMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoleMgr
//
// -------------------------------------------------------------------------

#include "NFWorldRoleMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFWorldRole.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldRoleMgr, EOT_WORLD_ROLE_MGR_ID, NFShmObj)

NFWorldRoleMgr::NFWorldRoleMgr()
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

NFWorldRoleMgr::~NFWorldRoleMgr()
{
}

int NFWorldRoleMgr::CreateInit()
{
    SetTimer(100, 0, 0, 0, 0, 0);
    return 0;
}

int NFWorldRoleMgr::ResumeInit()
{
    return 0;
}

int NFWorldRoleMgr::OnTimer(int timeId, int callcount)
{
    Tick();
    return 0;
}

int NFWorldRoleMgr::Tick()
{
    for(auto iter = NFWorldRole::Begin(m_pObjPluginManager); iter != NFWorldRole::End(m_pObjPluginManager);)
    {
        NFWorldRole* pRole = iter.GetObj();
        if (pRole)
        {
            pRole->Tick();
            if (pRole->GetStatus() == proto_ff::PLAYER_STATUS_DEAD)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, pRole->GetCid(), "cid:{} be erase from memory", pRole->GetCid());
                iter = NFWorldRole::Erase(m_pObjPluginManager, iter);
            }
        }
        iter++;
    }
    return 0;
}

NFWorldRole *NFWorldRoleMgr::GetRole(uint64_t cid)
{
    return NFWorldRole::GetObjByHashKey(m_pObjPluginManager, cid);
}

NFWorldRole *NFWorldRoleMgr::CreateRole(uint64_t cid)
{
    NFWorldRole *pRole= GetRole(cid);
    CHECK_EXPR(pRole == NULL, NULL, "Create World Role Failed, role exist, cid:{}", cid);

    pRole = NFWorldRole::CreateObjByHashKey(m_pObjPluginManager, cid);
    CHECK_EXPR(pRole, NULL, "Create World Role Failed, Space is Not enough, cid:{}", cid);

    pRole->SetCid(cid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add World Role Success, cid:{} globalId:{}", cid,
              pRole->GetGlobalId());
    return pRole;
}

int NFWorldRoleMgr::DeleteRole(NFWorldRole *pRole)
{
    CHECK_NULL(pRole);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete World Role Info, uid:{} cid:{}, gloablId:{}", pRole->GetUid(), pRole->GetCid(), pRole->GetGlobalId());

    NFWorldRole::DestroyObj(m_pObjPluginManager, pRole);

    return 0;
}
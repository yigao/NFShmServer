// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFWorldAccountMgr.h"
#include "NFWorldAccount.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include <map>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldAccountMgr, EOT_WORLD_ACCOUNT_MGR_ID, NFShmObj)

NFWorldAccountMgr::NFWorldAccountMgr() : NFShmObj()
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

NFWorldAccountMgr::~NFWorldAccountMgr()
{
}

int NFWorldAccountMgr::CreateInit()
{
    SetTimer(100, 0, 0, 0, 0, 0);
    return 0;
}

int NFWorldAccountMgr::ResumeInit()
{
    return 0;
}

NFWorldAccount *NFWorldAccountMgr::GetAccount(uint64_t uid)
{
    return NFWorldAccount::GetObjByHashKey(m_pObjPluginManager, uid);
}

NFWorldAccount *NFWorldAccountMgr::CreateAccount(uint64_t uid)
{
    NFWorldAccount *pPlayer = GetAccount(uid);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, uid:{}", uid);

    pPlayer = NFWorldAccount::CreateObjByHashKey(m_pObjPluginManager, uid);
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", uid);

    pPlayer->SetUid(uid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Player Success, uid:{} globalId:{}", uid,
              pPlayer->GetGlobalId());
    return pPlayer;
}

int NFWorldAccountMgr::DeleteAccount(NFWorldAccount *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetUid(), pPlayer->GetGlobalId());

    NFWorldAccount::DestroyObj(m_pObjPluginManager, pPlayer);

    return 0;
}

int NFWorldAccountMgr::OnTimer(int timeId, int callcount)
{
    Tick();
    return 0;
}

int NFWorldAccountMgr::Tick()
{
    for(auto iter = NFWorldAccount::Begin(m_pObjPluginManager); iter != NFWorldAccount::End(m_pObjPluginManager);)
    {
        NFWorldAccount* pAccount = iter.GetObj();
        if (pAccount)
        {
            pAccount->Tick();
            if (pAccount->GetStatus() == proto_ff::PLAYER_STATUS_DEAD)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, pAccount->GetUid(), "uid:{} cid:{} be erase from memory", pAccount->GetUid(), pAccount->GetCid());
                iter = NFWorldAccount::Erase(m_pObjPluginManager, iter);
            }
        }
        iter++;
    }
    return 0;
}
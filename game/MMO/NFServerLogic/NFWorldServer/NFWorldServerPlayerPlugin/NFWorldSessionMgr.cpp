// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSessionMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSessionMgr
//
// -------------------------------------------------------------------------

#include "NFWorldSessionMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFWorldSession.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFWorldAccountMgr.h"
#include "NFWorldAccount.h"

NFWorldSessionMgr::NFWorldSessionMgr()
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

NFWorldSessionMgr::~NFWorldSessionMgr()
{
}

int NFWorldSessionMgr::CreateInit()
{
    SetTimer(1000, 0, 0, 0, 0, 0);
    return 0;
}

int NFWorldSessionMgr::ResumeInit()
{
    return 0;
}

int NFWorldSessionMgr::OnTimer(int timeId, int callcount)
{
    Tick();
    return 0;
}

int NFWorldSessionMgr::Tick()
{
    for(auto iter = NFWorldSession::Begin(m_pObjPluginManager); iter != NFWorldSession::End(m_pObjPluginManager);)
    {
        NFWorldSession* pSession = iter.GetObj();
        if (pSession)
        {
            auto pAccount = NFWorldAccountMgr::Instance(m_pObjPluginManager)->GetAccount(pSession->GetUid());
            if (pAccount == NULL || pAccount->GetClientId() != pSession->GetClientId())
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, pSession->GetCid(), "session:{} uid:{} cid:{} be erase from memory", pSession->GetClientId(), pSession->GetUid(), pSession->GetCid());
                iter = NFWorldSession::Erase(m_pObjPluginManager, iter);
            }
        }
        iter++;
    }
    return 0;
}

NFWorldSession *NFWorldSessionMgr::GetSession(uint64_t clientId)
{
    return NFWorldSession::GetObjByHashKey(m_pObjPluginManager, clientId);
}

NFWorldSession *NFWorldSessionMgr::CreateSession(uint64_t clientId)
{
    NFWorldSession *pSession= GetSession(clientId);
    CHECK_EXPR(pSession == NULL, NULL, "Create Seesion Failed, session exist, clientId:{}", clientId);

    pSession = NFWorldSession::CreateObjByHashKey(m_pObjPluginManager, clientId);
    CHECK_EXPR(pSession, NULL, "Create Seesion Failed, clientId:{}", clientId);

    pSession->SetClientId(clientId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Seesion Success, clientId:{} globalId:{}", clientId,
              pSession->GetGlobalId());
    return pSession;
}

int NFWorldSessionMgr::DeleteSession(NFWorldSession *pSession)
{
    CHECK_NULL(pSession);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Session Info, proxyId:{} clientId:{}, uid:{}, cid:{}", pSession->GetProxyId(), pSession->GetClientId(),
              pSession->GetUid(), pSession->GetCid());

    NFWorldSession::DestroyObj(m_pObjPluginManager, pSession);

    return 0;
}

int NFWorldSessionMgr::DeleteSession(uint64_t ClientId)
{
    auto pSession = GetSession(ClientId);
    if (pSession)
    {
        DeleteSession(pSession);
    }

    return 0;
}


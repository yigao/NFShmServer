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

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldSessionMgr, EOT_WORLD_SESSION_MGR_ID, NFShmObj)

NFWorldSessionMgr::NFWorldSessionMgr():NFShmObj()
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
    return 0;
}

int NFWorldSessionMgr::ResumeInit()
{
    return 0;
}

NFWorldSession *NFWorldSessionMgr::GetSession(uint64_t clientId)
{
    return dynamic_cast<NFWorldSession *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(clientId, EOT_WORLD_SESSION_ID));
}

NFWorldSession *NFWorldSessionMgr::CreateSession(uint64_t clientId)
{
    NFWorldSession *pSession= GetSession(clientId);
    CHECK_EXPR(pSession == NULL, NULL, "Create Seesion Failed, session exist, clientId:{}", clientId);

    pSession = dynamic_cast<NFWorldSession *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(clientId, EOT_WORLD_SESSION_ID));
    CHECK_EXPR(pSession, NULL, "Create Seesion Failed, clientId:{}", clientId);

    pSession->SetClientId(clientId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Seesion Success, clientId:{} globalId:{}", clientId,
              pSession->GetGlobalID());
    return pSession;
}

int NFWorldSessionMgr::DeleteSession(NFWorldSession *pSession)
{
    CHECK_NULL(pSession);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Session Info, proxyId:{} clientId:{}, playerId:{}, charId:{}", pSession->GetProxyId(), pSession->GetClientId(),
              pSession->GetUid(), pSession->GetRoleId());

    FindModule<NFISharedMemModule>()->DestroyObj(pSession);

    return 0;
}


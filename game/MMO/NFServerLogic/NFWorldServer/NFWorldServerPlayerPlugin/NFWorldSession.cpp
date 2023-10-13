// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSession.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSession
//
// -------------------------------------------------------------------------

#include "NFWorldSession.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldSession, EOT_WORLD_SESSION_ID, NFShmObj)

NFWorldSession::NFWorldSession() : NFShmObj()
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

NFWorldSession::~NFWorldSession()
{
}

int NFWorldSession::CreateInit()
{
    m_proxyId = 0;
    m_clientId = 0;
    m_uid = 0;
    m_cid = 0;
    return 0;
}

int NFWorldSession::ResumeInit()
{
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        m_uid = 0;
        m_cid = 0;
    }
    return 0;
}

uint64_t NFWorldSession::GetProxyId() const
{
    return m_proxyId;
}

void NFWorldSession::SetProxyId(uint64_t proxyId)
{
    m_proxyId = proxyId;
}

uint64_t NFWorldSession::GetClientId() const
{
    return m_clientId;
}

void NFWorldSession::SetClientId(uint64_t clientId)
{
    m_clientId = clientId;
}

uint64_t NFWorldSession::GetUid() const
{
    return m_uid;
}

void NFWorldSession::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint64_t NFWorldSession::GetCid() const
{
    return m_cid;
}

void NFWorldSession::SetCid(uint64_t cid)
{
    m_cid = cid;
}


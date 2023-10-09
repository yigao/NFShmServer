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
#include "NFLogicCommon/NFAccountDefine.h"

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
    m_roleId = 0;
    m_disconnect = false;
    m_logicId = 0;
    m_gameId = 0;
    m_state = EAccountState::none;
    m_stateTick = 0;
    return 0;
}

int NFWorldSession::ResumeInit()
{
    if (m_pObjPluginManager->IsLoadAllServer())
    {
        m_uid = 0;
        m_roleId = 0;
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

void NFWorldSession::SetUid(uint64_t playerId)
{
    m_uid = playerId;
}

uint64_t NFWorldSession::GetRoleId() const
{
    return m_roleId;
}

void NFWorldSession::SetRoleId(uint64_t roleId)
{
    m_roleId = roleId;
}

bool NFWorldSession::IsDisconnect() const
{
    return m_disconnect;
}

void NFWorldSession::SetDisconnect(bool disconnect)
{
    m_disconnect = disconnect;
}

EAccountState NFWorldSession::GetState() const
{
    return m_state;
}

void NFWorldSession::SetState(EAccountState state)
{
    m_state = state;
}

uint32_t NFWorldSession::GetLogicId() const
{
    return m_logicId;
}

void NFWorldSession::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFWorldSession::GetGameId() const
{
    return m_gameId;
}

void NFWorldSession::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

uint64_t NFWorldSession::GetStateTick() const
{
    return m_stateTick;
}

void NFWorldSession::SetStateTick(uint64_t stateTick)
{
    m_stateTick = stateTick;
}

uint32_t NFWorldSession::GetLoginZid() const
{
    return m_loginZid;
}

void NFWorldSession::SetLoginZid(uint32_t loginZid)
{
    m_loginZid = loginZid;
}

uint32_t NFWorldSession::GetChanId() const
{
    return m_chanId;
}

void NFWorldSession::SetChanId(uint32_t chanId)
{
    m_chanId = chanId;
}

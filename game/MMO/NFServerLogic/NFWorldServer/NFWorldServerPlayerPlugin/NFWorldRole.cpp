// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRole.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRole
//
// -------------------------------------------------------------------------

#include "NFWorldRole.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"

NFWorldRole::NFWorldRole()
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

NFWorldRole::~NFWorldRole()
{
}

int NFWorldRole::CreateInit()
{
    m_cid = 0;
    m_uid = 0;
    m_logicId = 0;
    m_gameId = 0;
    m_snsId = 0;
    m_status = proto_ff::PLAYER_STATUS_NONE;
    m_createTime = 0;
    m_lastDiconnectTime = 0;
    m_lastLogoutTime = 0;
    m_isDisconnect = false;
    return 0;
}

int NFWorldRole::ResumeInit()
{
    return 0;
}

uint64_t NFWorldRole::GetCid() const
{
    return m_cid;
}

void NFWorldRole::SetCid(uint64_t cid)
{
    m_cid = cid;
}

uint64_t NFWorldRole::GetUid() const
{
    return m_uid;
}

void NFWorldRole::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint32_t NFWorldRole::GetLogicId() const
{
    return m_logicId;
}

void NFWorldRole::SetLogicId(uint32_t logicId)
{
    m_logicId = logicId;
}

uint32_t NFWorldRole::GetGameId() const
{
    return m_gameId;
}

void NFWorldRole::SetGameId(uint32_t gameId)
{
    m_gameId = gameId;
}

uint32_t NFWorldRole::GetSnsId() const
{
    return m_snsId;
}

void NFWorldRole::SetSnsId(uint32_t snsId)
{
    m_snsId = snsId;
}

proto_ff::enPlayerStatus NFWorldRole::GetStatus() const
{
    return m_status;
}

void NFWorldRole::SetStatus(proto_ff::enPlayerStatus status)
{
    m_status = status;
}

uint64_t NFWorldRole::GetCreateTime() const
{
    return m_createTime;
}

void NFWorldRole::SetCreateTime(uint64_t createTime)
{
    m_createTime = createTime;
}

uint64_t NFWorldRole::GetLastDiconnectTime() const
{
    return m_lastDiconnectTime;
}

void NFWorldRole::SetLastDiconnectTime(uint64_t lastDiconnectTime)
{
    m_lastDiconnectTime = lastDiconnectTime;
}

uint64_t NFWorldRole::GetLastLogoutTime() const
{
    return m_lastLogoutTime;
}

void NFWorldRole::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_lastLogoutTime = lastLogoutTime;
}

bool NFWorldRole::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFWorldRole::SetIsDisconnect(bool isDisconnect)
{
    m_isDisconnect = isDisconnect;
}

int NFWorldRole::Tick()
{
    switch (m_status)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "cid:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetCid());
        }
            break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
        }
            break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDiconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "cid:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetCid());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetLastLogoutTime() + WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME > (uint64_t)NFTime::Now().UnixSec())
                break;

            SetStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "cid:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetCid());
        }
            break;
    }
    return 0;
}


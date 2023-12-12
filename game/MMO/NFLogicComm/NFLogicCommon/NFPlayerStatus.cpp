// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerStatus.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerStatus
//
// -------------------------------------------------------------------------

#include "NFPlayerStatus.h"

#include "NFLogicCommon.h"

NFPlayerStatus::NFPlayerStatus()
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

NFPlayerStatus::~NFPlayerStatus()
{
}

int NFPlayerStatus::CreateInit()
{
    m_playerStatus = proto_ff::PLAYER_STATUS_NONE;
    m_lastCreateTime = NFTime::Now().UnixSec();
    m_lastDiconnectTime = 0;
    m_lastLogoutTime = 0;
    m_isDisconnect = false;
    m_timeMulti = 1;
    return 0;
}

int NFPlayerStatus::ResumeInit()
{
    return 0;
}

int NFPlayerStatus::Tick()
{
    switch (m_playerStatus)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_lastCreateTime < PLAYER_MAX_DISCONNECT_RECONNECT_TIME * m_timeMulti)
                break;

            if (!IsCanLogout())
            {
                break;
            }
            
            SetPlayerStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, StatusId(), "StatusId:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", StatusId());
        }
        break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
            DoOnline();
        }
        break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDiconnectTime() < PLAYER_MAX_DISCONNECT_RECONNECT_TIME * m_timeMulti * 2)
                break;

            if (!IsCanLogout())
            {
                break;
            }
            
            SetPlayerStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, StatusId(), "StatusId:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", StatusId());
        }
        break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (!IsCanDead())
            {
                break;
            }

            DoLogout();
            
            SetPlayerStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, StatusId(), "StatusId:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", StatusId());
        }
        break;
    }
    return 0;
}

proto_ff::enPlayerStatus NFPlayerStatus::GetPlayerStatus() const
{
    return m_playerStatus;
}

void NFPlayerStatus::SetPlayerStatus(proto_ff::enPlayerStatus status)
{
    m_playerStatus = status;
}

uint64_t NFPlayerStatus::GetCreateTime() const
{
    return m_lastCreateTime;
}

void NFPlayerStatus::SetCreateTime(uint64_t createTime)
{
    m_lastCreateTime = createTime;
}

uint64_t NFPlayerStatus::GetLastDiconnectTime() const
{
    return m_lastDiconnectTime;
}

void NFPlayerStatus::SetLastDiconnectTime(uint64_t lastDiconnectTime)
{
    m_lastDiconnectTime = lastDiconnectTime;
}

uint64_t NFPlayerStatus::GetLastLogoutTime() const
{
    return m_lastLogoutTime;
}

void NFPlayerStatus::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_lastLogoutTime = lastLogoutTime;
}

bool NFPlayerStatus::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFPlayerStatus::SetIsDisconnect(bool isDisconnect)
{
    m_isDisconnect = isDisconnect;
}

bool NFPlayerStatus::IsOnline() const
{
    return m_playerStatus == proto_ff::PLAYER_STATUS_ONLINE;
}

void NFPlayerStatus::SetIsOnline(bool isOnline)
{
    m_playerStatus = proto_ff::PLAYER_STATUS_ONLINE;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFProxySession.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxySession
//
// -------------------------------------------------------------------------

#include "NFProxySession.h"

uint64_t NFProxySession::GetLinkId() const
{
    return m_linkId;
}

void NFProxySession::SetLinkId(uint64_t linkId)
{
    m_linkId = linkId;
}

uint64_t NFProxySession::GetPlayerId() const
{
    return m_playerId;
}

void NFProxySession::SetPlayerId(uint64_t playerId)
{
    NFProxySession::m_playerId = playerId;
}

const string &NFProxySession::GetIpAddr() const
{
    return m_ipAddr;
}

void NFProxySession::SetIpAddr(const string &ipAddr)
{
    m_ipAddr = ipAddr;
}

uint32_t NFProxySession::GetPort() const
{
    return m_port;
}

void NFProxySession::SetPort(uint32_t port)
{
    m_port = port;
}

uint64_t NFProxySession::GetLastHeartBeatTime() const
{
    return m_lastHeartBeatTime;
}

void NFProxySession::SetLastHeartBeatTime(uint64_t lastHeartBeatTime)
{
    m_lastHeartBeatTime = lastHeartBeatTime;
}

uint64_t NFProxySession::GetLastActiveTime() const
{
    return m_lastActiveTime;
}

void NFProxySession::SetLastActiveTime(uint64_t lastActiveTime)
{
    m_lastActiveTime = lastActiveTime;
}

uint32_t NFProxySession::GetTimeOut() const
{
    return m_timeOut;
}

void NFProxySession::SetTimeOut(uint32_t timeOut)
{
    m_timeOut = timeOut;
}

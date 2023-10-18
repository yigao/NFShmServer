// -------------------------------------------------------------------------
//    @FileName         :    NFProxyPlayerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyPlayerInfo
//
// -------------------------------------------------------------------------

#include "NFProxyAccount.h"

uint64_t NFProxyAccount::GetLinkId() const
{
    return m_linkId;
}

void NFProxyAccount::SetLinkId(uint64_t linkId)
{
    m_linkId = linkId;
}

uint64_t NFProxyAccount::GetDisconnectTime() const
{
    return m_disconnectTime;
}

void NFProxyAccount::SetDisconnectTime(uint64_t disconnectTime)
{
    m_disconnectTime = disconnectTime;
}

bool NFProxyAccount::IsOnline() const
{
    return m_online;
}

void NFProxyAccount::SetOnline(bool online)
{
    m_online = online;
}

bool NFProxyAccount::IsLogin() const
{
    return m_isLogin;
}

void NFProxyAccount::SetIsLogin(bool isLogin)
{
    m_isLogin = isLogin;
}

uint64_t NFProxyAccount::GetUid() const
{
    return m_uid;
}

void NFProxyAccount::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint64_t NFProxyAccount::GetCid() const
{
    return m_cid;
}

void NFProxyAccount::SetCid(uint64_t cid)
{
    m_cid = cid;
}

const string &NFProxyAccount::GetIpAddr() const
{
    return m_ipAddr;
}

void NFProxyAccount::SetIpAddr(const string &ipAddr)
{
    m_ipAddr = ipAddr;
}

void NFProxyAccount::SetWorldBusId(uint32_t busId)
{
    m_worldBusId = busId;
}

uint32_t NFProxyAccount::GetWorldBusId() const
{
    return m_worldBusId;
}

void NFProxyAccount::SetGameBusId(uint32_t busId)
{
    m_gameBusId = busId;
}

uint32_t NFProxyAccount::GetGameBusId() const
{
    return m_gameBusId;
}

void NFProxyAccount::SetLogicBusId(uint32_t busId)
{
    m_logicBusId = busId;
}

uint32_t NFProxyAccount::GetLogicBusId() const
{
    return m_logicBusId;
}
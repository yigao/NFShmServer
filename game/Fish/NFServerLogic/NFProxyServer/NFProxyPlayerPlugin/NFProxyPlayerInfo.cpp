// -------------------------------------------------------------------------
//    @FileName         :    NFProxyPlayerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyPlayerInfo
//
// -------------------------------------------------------------------------

#include "NFProxyPlayerInfo.h"

uint64_t NFProxyPlayerInfo::GetLinkId() const
{
    return m_linkId;
}

void NFProxyPlayerInfo::SetLinkId(uint64_t linkId)
{
    m_linkId = linkId;
}

uint32_t NFProxyPlayerInfo::GetWorldBusId() const
{
    return m_worldBusId;
}

void NFProxyPlayerInfo::SetWorldBusId(uint32_t worldBusId)
{
    m_worldBusId = worldBusId;
}

uint32_t NFProxyPlayerInfo::GetGameBusId() const
{
    return m_gameBusId;
}

void NFProxyPlayerInfo::SetGameBusId(uint32_t gameBusId)
{
    m_gameBusId = gameBusId;
}

uint32_t NFProxyPlayerInfo::GetLogicBusId() const
{
    return m_logicBusId;
}

void NFProxyPlayerInfo::SetLogicBusId(uint32_t logicBusId)
{
    m_logicBusId = logicBusId;
}

uint64_t NFProxyPlayerInfo::GetDisconnectTime() const
{
    return m_disconnectTime;
}

void NFProxyPlayerInfo::SetDisconnectTime(uint64_t disconnectTime)
{
    m_disconnectTime = disconnectTime;
}

bool NFProxyPlayerInfo::IsOnline() const
{
    return m_online;
}

void NFProxyPlayerInfo::SetOnline(bool online)
{
    m_online = online;
}

bool NFProxyPlayerInfo::IsLogin() const
{
    return m_isLogin;
}

void NFProxyPlayerInfo::SetIsLogin(bool isLogin)
{
    m_isLogin = isLogin;
}

uint64_t NFProxyPlayerInfo::GetPlayerId() const
{
    return m_playerId;
}

void NFProxyPlayerInfo::SetPlayerId(uint64_t uid)
{
    m_playerId = uid;
}

const string &NFProxyPlayerInfo::GetIpAddr() const
{
    return m_ipAddr;
}

void NFProxyPlayerInfo::SetIpAddr(const string &ipAddr)
{
    m_ipAddr = ipAddr;
}

const std::string& NFProxyPlayerInfo::GetAccount() const
{
    return m_account;
}

void NFProxyPlayerInfo::SetAccount(const std::string& account)
{
    m_account = account;
}
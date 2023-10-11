// -------------------------------------------------------------------------
//    @FileName         :    NFProxyPlayerInfo.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyPlayerInfo
//
// -------------------------------------------------------------------------

#include "NFProxyAccountInfo.h"

uint64_t NFProxyAccountInfo::GetLinkId() const
{
    return m_linkId;
}

void NFProxyAccountInfo::SetLinkId(uint64_t linkId)
{
    m_linkId = linkId;
}

uint64_t NFProxyAccountInfo::GetDisconnectTime() const
{
    return m_disconnectTime;
}

void NFProxyAccountInfo::SetDisconnectTime(uint64_t disconnectTime)
{
    m_disconnectTime = disconnectTime;
}

bool NFProxyAccountInfo::IsOnline() const
{
    return m_online;
}

void NFProxyAccountInfo::SetOnline(bool online)
{
    m_online = online;
}

bool NFProxyAccountInfo::IsLogin() const
{
    return m_isLogin;
}

void NFProxyAccountInfo::SetIsLogin(bool isLogin)
{
    m_isLogin = isLogin;
}

uint64_t NFProxyAccountInfo::GetUid() const
{
    return m_uid;
}

void NFProxyAccountInfo::SetUid(uint64_t uid)
{
    m_uid = uid;
}

const string &NFProxyAccountInfo::GetIpAddr() const
{
    return m_ipAddr;
}

void NFProxyAccountInfo::SetIpAddr(const string &ipAddr)
{
    m_ipAddr = ipAddr;
}
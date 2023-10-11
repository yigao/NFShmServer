// -------------------------------------------------------------------------
//    @FileName         :    NFProxyPlayerInfo.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/29
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyPlayerInfo
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

class NFProxyAccountInfo
{
public:
    NFProxyAccountInfo()
    {
        m_linkId = 0;
        m_isLogin = false;
        m_uid = 0;
        m_disconnectTime = 0;
        m_online = true;
    }

    virtual ~NFProxyAccountInfo()
    {
    }

    uint64_t GetLinkId() const;

    void SetLinkId(uint64_t linkId);

    uint64_t GetDisconnectTime() const;

    void SetDisconnectTime(uint64_t disconnectTime);

    bool IsOnline() const;

    void SetOnline(bool online);

    bool IsLogin() const;

    void SetIsLogin(bool isLogin);

    uint64_t GetUid() const;

    void SetUid(uint64_t uid);

    const string &GetIpAddr() const;

    void SetIpAddr(const string &ipAddr);
private:
    uint64_t m_linkId;
    uint32_t m_worldBusId;
    uint32_t m_gameBusId;
    uint32_t m_logicBusId;
    uint64_t m_disconnectTime;
    bool m_online;
    bool m_isLogin;
    uint64_t m_uid;
    std::string m_ipAddr;
};
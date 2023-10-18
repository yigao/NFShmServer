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

class NFProxyAccount
{
public:
    NFProxyAccount()
    {
        m_linkId = 0;
        m_isLogin = false;
        m_uid = 0;
        m_cid = 0;
        m_disconnectTime = 0;
        m_online = true;
        m_worldBusId = 0;
        m_logicBusId = 0;
        m_gameBusId = 0;
    }

    virtual ~NFProxyAccount()
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

    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    const string &GetIpAddr() const;

    void SetIpAddr(const string &ipAddr);

    void SetWorldBusId(uint32_t busId);

    uint32_t GetWorldBusId() const;

    void SetGameBusId(uint32_t busId);

    uint32_t GetGameBusId() const;

    void SetLogicBusId(uint32_t busId);

    uint32_t GetLogicBusId() const;
private:
    uint64_t m_linkId;
    uint32_t m_worldBusId;
    uint32_t m_gameBusId;
    uint32_t m_logicBusId;
    uint64_t m_disconnectTime;
    bool m_online;
    bool m_isLogin;
    uint64_t m_uid;
    uint64_t m_cid;
    std::string m_ipAddr;
};
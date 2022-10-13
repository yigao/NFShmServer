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

class NFProxyPlayerInfo
{
public:
    NFProxyPlayerInfo()
    {
        m_linkId = 0;
        m_isLogin = false;
        m_playerId = 0;
        m_worldBusId = 0;
        m_gameBusId = 0;
        m_logicBusId = 0;
        m_disconnectTime = 0;
        m_online = true;
        m_charId = 0;
    }

    virtual ~NFProxyPlayerInfo()
    {
    }

    uint64_t GetLinkId() const;

    void SetLinkId(uint64_t linkId);

    uint32_t GetWorldBusId() const;

    void SetWorldBusId(uint32_t worldBusId);

    uint32_t GetGameBusId() const;

    void SetGameBusId(uint32_t gameBusId);

    uint32_t GetLogicBusId() const;

    void SetLogicBusId(uint32_t logicBusId);

    uint64_t GetDisconnectTime() const;

    void SetDisconnectTime(uint64_t disconnectTime);

    bool IsOnline() const;

    void SetOnline(bool online);

    bool IsLogin() const;

    void SetIsLogin(bool isLogin);

    uint64_t GetPlayerId() const;

    void SetPlayerId(uint64_t playerId);

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
    uint64_t m_playerId;
    uint64_t m_charId;
public:
    uint64_t GetCharId() const;

    void SetCharId(uint64_t charId);

private:
    std::string m_ipAddr;
};
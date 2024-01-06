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
        m_gameId = 0;
        m_roomId = 0;
        m_online = true;
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

    void SetPlayerId(uint64_t uid);

    const string &GetIpAddr() const;

    void SetIpAddr(const string &ipAddr);

    const std::string& GetAccount() const;

    void SetAccount(const std::string& account);

    uint32_t GetGameId() const { return m_gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
private:
    uint64_t m_linkId;
    uint32_t m_worldBusId;
    uint32_t m_gameId;
    uint32_t m_roomId;
    uint32_t m_gameBusId;
    uint32_t m_logicBusId;
    uint64_t m_disconnectTime;
    bool m_online;
    bool m_isLogin;
    uint64_t m_playerId;
    std::string m_ipAddr;
    std::string m_account;
};
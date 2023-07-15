// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "ComDefine.pb.h"

class NFWorldPlayer : public NFShmObj
{
public:
    NFWorldPlayer();

    virtual ~NFWorldPlayer();

    int CreateInit();
    int ResumeInit();

    void  Tick();
    virtual int OnTimer(int timeId, int callcount);

    proto_ff::PlayerStatus GetStatus() const { return m_iStatus; }
    std::string GetStatusName() const { return proto_ff::PlayerStatus_Name(m_iStatus); }
    void SetStatus(proto_ff::PlayerStatus status) { m_iStatus = status; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetPlayerId() const { return m_playerId; }
    void SetPlayerId(uint64_t playerId) { m_playerId = playerId; }
    uint32_t GetProxyId() const { return m_proxyId; }
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    uint32_t GetLogicId() const { return m_logicId; }
    void SetLogicId(uint32_t logicId) { m_logicId = logicId; }
    uint32_t GetGameId() const { return m_gameId; }
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }
    bool IsInGaming() { return m_gameId > 0 && m_roomId > 0; }

    bool IsRoomLock() const { return m_roomLock; }
    void SetRoomLock(bool roomLock) { m_roomLock = roomLock; }
    void LockRoom();
    void ClearLockRoom();

    bool IsGameLock() const { return m_gameLock; }
    void SetgameLock(bool gameLock) { m_gameLock = gameLock; }
    void LockGame();
    void ClearLockGame();

    uint32_t m_gameId;
    uint32_t m_roomId;
private:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    uint32_t m_logicId;
    proto_ff::PlayerStatus m_iStatus;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;

    bool m_roomLock;
    int m_roomLockTimeId;

    bool m_gameLock;
    int m_gameLockTimeId;
DECLARE_IDCREATE(NFWorldPlayer)
};

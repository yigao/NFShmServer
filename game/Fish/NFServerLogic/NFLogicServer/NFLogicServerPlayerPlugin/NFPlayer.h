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
#include "DBProto.pb.h"

class NFPlayer : public NFShmObj
{
public:
    NFPlayer();

    virtual ~NFPlayer();

    int CreateInit();
    int ResumeInit();

    void  Tick();
    virtual int OnTimer(int timeId, int callcount);

public:
    virtual int Init(const proto_ff::tbFishPlayerData& data);
    //登入
    virtual int OnLogin();
    //生物登出入口
    virtual int OnLogout();
    //断开连接
    virtual int OnDisconnect();
    //重新连接
    virtual int OnReconnect();
    //生物update
    virtual int Update(uint64_t tick);

    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    virtual int DailyZeroUpdate(uint64_t unixSec);
    virtual int WeekZeroUpdate(uint64_t unixSec);
    virtual int MonthZeroUpdate(uint64_t unixSec);

public:
    proto_ff::PlayerStatus GetStatus() const { return m_iStatus; }
    void SetStatus(proto_ff::PlayerStatus status) { m_iStatus = status; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetPlayerId() const { return m_playerId; }
    void SetPlayerId(uint64_t playerId) { m_playerId = playerId; }
    uint32_t GetProxyId() const { return m_proxyId; }
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    uint32_t GetGameId() const { return m_gameId; }
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    uint32_t GetRoomId() const { return m_roomId; }
    void SetRoomId(uint32_t roomId) { m_roomId = roomId; }
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }
    bool IsInGaming() { return m_gameId > 0 && m_roomId > 0; }
private:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    proto_ff::PlayerStatus m_iStatus;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;
    uint32_t m_gameId;
    uint32_t m_roomId;
DECLARE_IDCREATE(NFPlayer)
};

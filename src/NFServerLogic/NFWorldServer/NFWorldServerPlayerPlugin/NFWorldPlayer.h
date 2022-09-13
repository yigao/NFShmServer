// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFCore/NFTime.h"

class NFWorldPlayer : public NFShmObj
{
public:
    NFWorldPlayer();

    virtual ~NFWorldPlayer();

    int CreateInit();
    int ResumeInit();

    void  Tick();
    virtual void OnTimer(int timeId, int callcount);

    PLAYER_STATUS GetStatus() const { return m_iStatus; }
    void SetStatus(PLAYER_STATUS status) { m_iStatus = status; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetPlayerId() const { return m_playerId; }
    void SetPlayerId(uint64_t playerId) { m_playerId = playerId; }
    uint32_t GetProxyId() const { return m_proxyId; }
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    uint32_t GetLogicId() const { return m_logicId; }
    void SetLogicId(uint32_t logicId) { m_logicId = logicId; }
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }
private:
    uint64_t m_playerId;
    uint32_t m_proxyId;
    uint32_t m_logicId;
    PLAYER_STATUS m_iStatus;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;

DECLARE_IDCREATE(NFWorldPlayer)
};

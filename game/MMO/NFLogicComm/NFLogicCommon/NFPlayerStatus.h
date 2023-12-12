// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerStatus.h
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerStatus
//
// -------------------------------------------------------------------------

#pragma once

#include <CommonClass.pb.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

/**
 * \brief 负责玩家数据的生命周期管理
 */
class NFPlayerStatus
{
public:
    NFPlayerStatus();
    
    virtual ~NFPlayerStatus();
    
    int CreateInit();
    int ResumeInit();
public:
    virtual int Tick();
public:
    virtual uint64_t StatusId() const = 0;

    virtual bool IsCanLogout() { return true; }

    virtual int DoOnline() { return 0; }

    virtual bool IsCanDead() { return true; }

    virtual int DoLogout() { return 0; }
public:
    proto_ff::enPlayerStatus GetPlayerStatus() const;

    void SetPlayerStatus(proto_ff::enPlayerStatus status);

    bool IsDeadStatus() const { return m_playerStatus == proto_ff::PLAYER_STATUS_DEAD; }

    uint64_t GetCreateTime() const;

    void SetCreateTime(uint64_t createTime);

    uint64_t GetLastDiconnectTime() const;

    void SetLastDiconnectTime(uint64_t lastDiconnectTime);

    uint64_t GetLastLogoutTime() const;

    void SetLastLogoutTime(uint64_t lastLogoutTime);

    bool IsDisconnect() const;

    void SetIsDisconnect(bool isDisconnect);

    bool IsOnline() const;

    void SetIsOnline(bool isOnline);
protected:
    /**
     * @brief
     */
    proto_ff::enPlayerStatus m_playerStatus;
    uint64_t m_lastCreateTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;
    bool m_isDisconnect;
protected:
    uint32_t m_timeMulti;
};
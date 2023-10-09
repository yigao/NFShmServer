// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSession.h
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSession
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "NFWorldCommonDefine.h"
#include "NFLogicCommon/NFAccountDefine.h"

class NFWorldSession : public NFShmObj
{
public:
    NFWorldSession();

    virtual ~NFWorldSession();

    int CreateInit();

    int ResumeInit();
public:
    uint64_t GetProxyId() const;

    void SetProxyId(uint64_t proxyId);

    uint64_t GetClientId() const;

    void SetClientId(uint64_t clientId);

    uint64_t GetUid() const;

    void SetUid(uint64_t playerId);

    uint64_t GetRoleId() const;

    void SetRoleId(uint64_t roleId);

    bool IsDisconnect() const;

    void SetDisconnect(bool disconnect);

    EAccountState GetState() const;

    void SetState(EAccountState state);

    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint64_t GetStateTick() const;

    void SetStateTick(uint64_t stateTick);

public:
    uint32_t GetLoginZid() const;

    void SetLoginZid(uint32_t loginZid);

    uint32_t GetChanId() const;

    void SetChanId(uint32_t chanId);
private:
    uint64_t m_proxyId;
    uint64_t m_clientId;
    uint64_t m_uid;
    uint64_t m_roleId;
    uint32_t m_logicId;
    uint32_t m_gameId;
    bool m_disconnect;
    EAccountState m_state;
    uint64_t m_stateTick;
    uint32_t m_loginZid;
    uint32_t m_chanId;
private:
DECLARE_IDCREATE(NFWorldSession)
};
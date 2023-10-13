// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"

class NFWorldAccount : public NFShmObj
{
public:
    NFWorldAccount();

    virtual ~NFWorldAccount();

    int CreateInit();

    int ResumeInit();
public:
    int Tick();
public:

    uint64_t GetUid() const;

    void SetUid(uint64_t uid);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

    uint64_t GetClientId() const;

    void SetClientId(uint64_t clientId);

    proto_ff::enPlayerStatus GetStatus() const;

    void SetStatus(proto_ff::enPlayerStatus status);

    uint64_t GetCreateTime() const;

    void SetCreateTime(uint64_t createTime);

    uint64_t GetLastDiconnectTime() const;

    void SetLastDiconnectTime(uint64_t lastDiconnectTime);

    uint64_t GetLastLogoutTime() const;

    void SetLastLogoutTime(uint64_t lastLogoutTime);

    bool IsDisconnect() const;

    void SetIsDisconnect(bool isDisconnect);

    uint64_t GetCid() const;

    void SetCid(uint64_t curCid);

private:
    /**
     * @brief
     */
    uint64_t m_uid;
private:
    /**
     * @brief
     */
    uint32_t m_proxyId;
    uint64_t m_clientId;

private:

    /**
     * @brief
     */
    proto_ff::enPlayerStatus m_status;
    uint64_t m_createTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;
    bool m_isDisconnect;

private:
    uint64_t m_cid;
private:
DECLARE_IDCREATE(NFWorldAccount)
};

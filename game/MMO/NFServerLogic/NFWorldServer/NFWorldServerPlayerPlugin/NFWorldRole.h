// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRole.h
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRole
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "CommonClass.pb.h"

class NFWorldRole : public NFShmObj
{
public:
    NFWorldRole();

    virtual ~NFWorldRole();

    int CreateInit();

    int ResumeInit();
public:
    int Tick();
public:
    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    uint64_t GetUid() const;

    void SetUid(uint64_t uid);

    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);
public:
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
private:
    uint64_t m_cid;
    uint64_t m_uid;
    uint32_t m_logicId;
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
DECLARE_IDCREATE(NFWorldRole)
};
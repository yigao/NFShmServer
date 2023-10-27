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
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFWorldSession : public NFShmObjTemplate<NFWorldSession, EOT_WORLD_SESSION_ID, NFShmObj>
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

    void SetUid(uint64_t uid);

    uint64_t GetCid() const;

    void SetCid(uint64_t cid);
private:
    uint64_t m_proxyId;
    uint64_t m_clientId;
    uint64_t m_uid;
    uint64_t m_cid;
};
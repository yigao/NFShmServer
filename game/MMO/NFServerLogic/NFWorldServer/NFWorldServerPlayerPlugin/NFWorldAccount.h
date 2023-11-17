// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFPlayerStatus.h>

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFAccountDefine.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFWorldAccount : public NFShmObjTemplate<NFWorldAccount, EOT_WORLD_ACCOUNT_ID, NFShmObj>, public NFPlayerStatus
{
public:
    NFWorldAccount();

    virtual ~NFWorldAccount();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * \brief 处理继承NFPlayerStatus 负责玩家数据的生命周期管理
     */
    virtual uint64_t StatusId() const { return GetUid(); }
public:
    uint64_t GetUid() const;

    void SetUid(uint64_t uid);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

    uint64_t GetClientId() const;

    void SetClientId(uint64_t clientId);

    uint64_t GetCid() const;

    void SetCid(uint64_t curCid);

    uint32_t GetRoleNum() const;

    void AddRoleNum(uint64_t cid);

    bool IsExistCid(uint64_t cid) const;

    void SetChanId(uint32_t chanId);

    uint32_t GetChanId() const;

    void SetBornZid(uint32_t bornZid);

    uint32_t GetBornZid() const;

private:
    /**
     * @brief
     */
    uint64_t m_uid;

    /**
     * @brief 渠道ID
     */
    uint32_t m_chanId;

    /**
     * @brief 登录的区服ID
     */
    uint32_t m_bornZid;

private:
    /**
     * @brief
     */
    uint32_t m_proxyId;
    uint64_t m_clientId;

private:
    uint64_t m_cid;
    NFShmHashSet<uint64_t, MAX_ROLE_NUM> m_roleSet;
};

// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldCreateRole.h
//    @Author           :    gaoyi
//    @Date             :    23-3-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldCreateRole
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "ServerInternal2.pb.h"
#include "CSLogin.pb.h"

class NFTransWorldCreateRole : public NFTransBase
{
public:
    NFTransWorldCreateRole();

    virtual ~NFTransWorldCreateRole();

    int CreateInit();

    int ResumeInit();
public:
    int Init(uint64_t uid, uint64_t roleId, uint32_t proxyId, uint64_t clientId, uint32_t bornZid);

    int OnHandleCreateRole(const proto_ff::ClientCreateRoleReq& msg);

    int SendCreateRoleInfo(const proto_ff::WorldToLogicCreateRoleReq& req);

    virtual int HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
public:
    /**
     * @brief 处理逻辑服务器创建角色返回
     * @param msgId
     * @param packet
     * @param param1
     * @param param2
     * @return
     */
    int OnHandleLogicCreateRoleRsp(uint32_t msgId, const NFDataPackage& packet, uint32_t reqTransId, uint32_t rspTransId);
public:
    virtual int OnTimeOut();

    virtual int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_uid;
    uint64_t m_roleId;
    uint32_t m_proxyId;
    uint64_t m_clientId;
    uint32_t m_bornZid;
private:
DECLARE_IDCREATE(NFTransWorldCreateRole)
};
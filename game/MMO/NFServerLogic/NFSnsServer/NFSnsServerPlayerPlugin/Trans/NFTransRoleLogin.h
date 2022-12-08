// -------------------------------------------------------------------------
//    @FileName         :    NFTransRoleLOgin.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransRoleLOgin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFTransCacheBase.h"
#include "DBProto2_s.h"
#include "ServerInternal2.pb.h"
#include "storesvr_sqldata.pb.h"

class NFTransRoleLogin : public NFTransCacheBase
{
public:
    NFTransRoleLogin();

    virtual ~NFTransRoleLogin();

    int CreateInit();

    int ResumeInit();

public:
    virtual int OnTransFinished(int iRunLogicRetCode) override;

    virtual int HandleTransFinished(int iRunLogicRetCode) override { return 0; }

    virtual int OnTimeOut() override { return 0; }

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) override;

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code) override;

public:
    /**
     * @brief 处理登录
     * @param req
     * @return
     */
    int OnRoleLogin(const proto_ff::WorldToSnsLoginReq &req);

    /**
     * @brief 处理登录返回
     * @param iRunLogicRetCode
     * @return
     */
    int OnRoleLoginRes(int iRunLogicRetCode);

    /**
     * @brief 处理数据库插入RoleDetail返回
     * @param pRes
     * @param err_code
     * @return
     */
    int OnHandleInsertRoleDetailRes(const storesvr_sqldata::storesvr_ins_res* pRes, int err_code);
public:
    /**
     * @brief 处理获取角色数据返回
     * @param iRunLogicRetCode
     * @param roleID
     * @return
     */
    virtual int HandleGetRoleSimpleRes(int iRunLogicRetCode, uint64_t roleId) override;

    /**
     * @brief
     * @param iRunLogicRetCode
     * @param roleId
     * @return
     */
    virtual int HandleGetRoleDetailRes(int iRunLogicRetCode, uint64_t roleId) override;

    /**
     * @brief 查询角色回调
     * @param query
     * @return
     */
    virtual int QueryRole_CallBack(NFQueryRole &query) override;

private:
    uint64_t m_roleId;
    uint32_t m_cmd;
    uint32_t m_logicId;
    uint32_t m_proxyId;
    proto_ff_s::RoleDBSimpleData_s m_simpleInfo;
    uint32_t m_lastLoginTime;
    uint32_t m_lastLogoutTime;
DECLARE_IDCREATE(NFTransRoleLogin)
};
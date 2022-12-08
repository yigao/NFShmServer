// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRole.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRole
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "Base/NFTransPlayerBase.h"
#include "DBProto.pb.h"

class NFTransGetRole : public NFTransPlayerBase
{
public:
    NFTransGetRole();

    virtual ~NFTransGetRole();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param roleId
     * @param uid
     * @param cmd
     * @param fromBusId
     * @param reqTransId
     * @return
     */
    virtual int Init(uint64_t roleId, uint64_t uid, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);

    /**
     * @brief
     * @param pCSMsgReq
     * @return
     */
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    /**
     * @brief
     * @param pSSMsgRes
     * @param cmd
     * @param table_id
     * @param seq
     * @param err_code
     * @return
     */
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int HandleTransFinished(int iRunLogicRetCode);
public:
    int SendGetRoleInfo();
    int HandleGetRoleDBRsp(proto_ff::RoleDBData& dbData);
private:
    uint32_t m_proxyId;
DECLARE_IDCREATE(NFTransGetRole)
};
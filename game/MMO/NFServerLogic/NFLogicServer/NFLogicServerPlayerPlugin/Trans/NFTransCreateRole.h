// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateRole.h
//    @Author           :    gaoyi
//    @Date             :    22-10-29
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransCreateRole
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "Base/NFTransPlayerBase.h"


class NFTransCreateRole : public NFTransPlayerBase
{
public:
    NFTransCreateRole();

    virtual ~NFTransCreateRole();

    int CreateInit();

    int ResumeInit();
public:
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
                               uint32_t seq, int32_t err_code);

    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int HandleTransFinished(int iRunLogicRetCode);
DECLARE_IDCREATE(NFTransCreateRole)
};
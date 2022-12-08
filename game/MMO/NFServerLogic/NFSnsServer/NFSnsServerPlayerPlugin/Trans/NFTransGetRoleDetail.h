// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleDetail
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "storesvr_sqldata.pb.h"
#include "NFComm/NFShmCore/NFTransBase.h"

class NFTransGetRoleDetail : public NFTransBase
{
public:
    NFTransGetRoleDetail();

    virtual ~NFTransGetRoleDetail();

    int CreateInit();

    int ResumeInit();
public:
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    int ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res* pSelectRsp, uint32_t err_code, int iTransID);
public:
    int QueryRole(uint64_t roleId);

    int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_roleId;
DECLARE_IDCREATE(NFTransGetRoleDetail)
};
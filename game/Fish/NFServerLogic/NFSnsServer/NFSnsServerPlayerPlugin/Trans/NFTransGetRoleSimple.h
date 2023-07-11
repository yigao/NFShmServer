// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleRimple.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleRimple
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "storesvr_sqldata.pb.h"

class NFTransGetRoleSimple : public NFTransBase
{
public:
    NFTransGetRoleSimple();

    virtual ~NFTransGetRoleSimple();

    int CreateInit();

    int ResumeInit();
public:
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, int32_t err_code);

    int ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res* pSelectRsp, int32_t err_code, int iTransID);
public:
    int QueryRole(uint64_t roleId);

    int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_roleId;
DECLARE_IDCREATE(NFTransGetRoleSimple)
};
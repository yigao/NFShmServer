// -------------------------------------------------------------------------
//    @FileName         :    NFTransHandleEventLog.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransHandleEventLog.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFTransLogicUserBase.h"

class NFUserDetail;
class NFTransHandleEventLog : public NFTransLogicUserBase {
public:
    NFTransHandleEventLog();

    virtual ~NFTransHandleEventLog();

    int CreateInit();

    int ResumeInit();

    virtual int OnTimeOut();

    virtual int HandleTransFinished(int iRunLogicRetCode);

    int HandleEventLog(proto_ff_s::tbEventLog_s *pstEventLog);
public:
    virtual int
    HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);

    int ProcessDeleteEventLogRes(const storesvr_sqldata::storesvr_delobj_res* pSelectRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
private:
    uint64_t m_ullEventLogUid;
DECLARE_IDCREATE(NFTransHandleEventLog);
};
// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetEventLog.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetEventLog.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFTransLogicUserBase.h"

class NFUserMisc;
class NFUserDetail;
class NFTransGetEventLog : public NFTransLogicUserBase {
public:
    NFTransGetEventLog();

    virtual ~NFTransGetEventLog();

    int CreateInit();

    int ResumeInit();

    virtual int OnTimeOut();
public:
    int GetEventLog(uint64_t ullRoleID, uint64_t ullEventLogID);
    int GetAllEventLog(uint64_t ullRoleID);
public:
    virtual int
    HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);

    int ProGetEventLogRes(const storesvr_sqldata::storesvr_selobj_res* pSelectRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    int ProGetEventLogListRes(const storesvr_sqldata::storesvr_sel_res *pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
private:
DECLARE_IDCREATE(NFTransGetEventLog);
};
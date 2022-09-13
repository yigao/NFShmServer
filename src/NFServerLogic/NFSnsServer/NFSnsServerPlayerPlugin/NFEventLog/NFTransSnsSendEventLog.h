// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsSendEventLog.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsSendEventLog.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"

class NFTransSnsSendEventLog : public NFTransBase {
public:
    NFTransSnsSendEventLog();

    virtual ~NFTransSnsSendEventLog();

    int CreateInit();

    int ResumeInit();

    virtual int OnTimeOut();
    int OnTransFinished(int iRunLogicRetCode);
public:
    virtual int
    HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);

    int ProCreateEvengLogRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
public:
    int SendEventLog(const proto_ff::tbEventLog& eventLog);
    int NotifyOnlinePlayer();
private:
    uint64_t m_ullTargetUserID;
    uint64_t m_ullEventLogID;

DECLARE_IDCREATE(NFTransSnsSendEventLog);
};
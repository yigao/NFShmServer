// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsSendEventLog.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsSendEventLog.cpp
//
// -------------------------------------------------------------------------

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFTransSnsSendEventLog.h"
#include "NFOnlineUser/NFOnlineUserMgr.h"
#include "NFOnlineUser/NFOnlineUser.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSnsSendEventLog, EOT_TRANS_SNS_SEND_EVENT_LOG_ID, NFTransBase)

NFTransSnsSendEventLog::NFTransSnsSendEventLog() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransSnsSendEventLog::~NFTransSnsSendEventLog() noexcept {

}

int NFTransSnsSendEventLog::CreateInit() {
    m_ullTargetUserID= 0;
    m_ullEventLogID = 0;
    return 0;
}

int NFTransSnsSendEventLog::ResumeInit() {
    return 0;
}

int NFTransSnsSendEventLog::OnTimeOut() {
    NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransSnsSendEventLog timeout, , targetUserId:{} eventId:{}",
               m_ullTargetUserID, m_ullEventLogID);
    return 0;
}

int NFTransSnsSendEventLog::OnTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransSnsSendEventLog error, targetUserId:{} eventId:{} error:{}",
                   m_ullTargetUserID, m_ullEventLogID, iRunLogicRetCode);
    }

    return 0;
}

int NFTransSnsSendEventLog::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                        uint32_t seq, uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    int iRetCode = 0;
    if (table_id == proto_ff::E_TABLE_EVENT_LOG) {
        if (cmd == proto_ff::E_STORESVR_S2C_INSERT)
        {
            iRetCode = ProCreateEvengLogRes((const storesvr_sqldata::storesvr_ins_res*)pSSMsgRes, cmd, table_id, err_code);
        }
    }
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFTransSnsSendEventLog::ProCreateEvengLogRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    CHECK_EXPR(err_code == 0, -1, "insert event log failed!");

    NotifyOnlinePlayer();
    SetFinished(0);
    return 0;
}

int NFTransSnsSendEventLog::SendEventLog(const proto_ff::tbEventLog& eventLog) {
    m_ullTargetUserID = eventLog.user_id();
    m_ullEventLogID = eventLog.event_id();

    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                                          proto_ff::E_STORESVR_C2S_INSERT,
                                                                          proto_ff::E_TABLE_EVENT_LOG,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, "tbEventLog", eventLog,
                                                                          GetGlobalID(),
                                                                          0, m_ullTargetUserID);
    if (iRetCode)
    {
        SetFinished(iRetCode);
        return iRetCode;
    }

    return 0;
}

int NFTransSnsSendEventLog::NotifyOnlinePlayer() {
    NFOnlineUser* pUser = NFOnlineUserMgr::GetInstance()->Find(m_ullTargetUserID);
    if (pUser)
    {
        proto_ff::SSEventLogNotify req;
        req.set_user_id(m_ullTargetUserID);
        req.set_eventlog_id(m_ullEventLogID);
        pUser->SendMsgToLogicServer(proto_ff::NF_UNICASTMSG_EVENTLOG_NOTIFY, req);
    }

    return 0;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFTransSendEventLog.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSendEventLog.cpp
//
// -------------------------------------------------------------------------

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFTransSendEventLog.h"
#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransGetUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSendEventLog, EOT_TRANS_SEND_EVENT_LOG_ID, NFTransLogicUserBase)

NFTransSendEventLog::NFTransSendEventLog() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransSendEventLog::~NFTransSendEventLog() noexcept {

}

int NFTransSendEventLog::CreateInit() {
    m_ullTargetUserID= 0;
    m_ullEventLogID = 0;
    return 0;
}

int NFTransSendEventLog::ResumeInit() {
    return 0;
}

int NFTransSendEventLog::OnTimeOut() {
    NFTransLogicUserBase::OnTimeOut();
    NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransSendEventLog timeout, , targetUserId:{} eventId:{}",
               m_ullTargetUserID, m_ullEventLogID);
    return 0;
}

int NFTransSendEventLog::OnTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode)
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransSendEventLog error, targetUserId:{} eventId:{} error:{}",
                   m_ullTargetUserID, m_ullEventLogID, iRunLogicRetCode);
    }

    return 0;
}

int NFTransSendEventLog::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
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

int NFTransSendEventLog::ProCreateEvengLogRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code)
{
    CHECK_EXPR(err_code == 0, -1, "insert event log failed!");

    NotifyOnlinePlayer();
    SetFinished(0);
    return 0;
}

int NFTransSendEventLog::SendEventLog(const proto_ff::tbEventLog& eventLog) {
    m_ullTargetUserID = eventLog.user_id();
    m_ullEventLogID = eventLog.event_id();

    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
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

int NFTransSendEventLog::NotifyOnlinePlayer() {
    proto_ff::SSEventLogNotify req;
    req.set_user_id(m_ullTargetUserID);
    req.set_eventlog_id(m_ullEventLogID);

    NFMessageMgr::Instance()->SendMsgToSuitLogicServer(NF_ST_LOGIC_SERVER, m_ullTargetUserID, proto_ff::NF_UNICASTMSG_EVENTLOG_NOTIFY, req, true);
    return 0;
}

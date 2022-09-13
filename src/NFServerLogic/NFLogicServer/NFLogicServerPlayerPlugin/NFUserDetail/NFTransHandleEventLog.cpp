// -------------------------------------------------------------------------
//    @FileName         :    NFTransHandleEventLog.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransHandleEventLog.cpp
//
// -------------------------------------------------------------------------

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFTransHandleEventLog.h"
#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransGetUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransHandleEventLog, EOT_TRANS_HANDLE_EVENT_LOG_ID, NFTransLogicUserBase)

NFTransHandleEventLog::NFTransHandleEventLog() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransHandleEventLog::~NFTransHandleEventLog() noexcept {

}

int NFTransHandleEventLog::CreateInit() {
    m_ullEventLogUid = 0;
    return 0;
}

int NFTransHandleEventLog::ResumeInit() {
    return 0;
}

int NFTransHandleEventLog::OnTimeOut() {
    NFTransLogicUserBase::OnTimeOut();
    NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransHandleEventLog timeout, roleId:{}, cmd:{}, transid:{}",
               m_userId, m_cmd, m_reqTransId);
    return 0;
}

int NFTransHandleEventLog::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                       uint32_t seq, uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_NULL(UserDetail());

    int iRetCode = 0;
    if (table_id == proto_ff::E_TABLE_EVENT_LOG) {
        if (cmd == proto_ff::E_STORESVR_S2C_DELETEOBJ)
        {
            iRetCode = ProcessDeleteEventLogRes((const storesvr_sqldata::storesvr_delobj_res*)pSSMsgRes, cmd, table_id, err_code);
        }
        else
        {
            NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransHandleEventLog error, roleId:{}, cmd:{}, transid:{}",
                       m_userId, m_cmd, m_reqTransId);
        }
    }
    else
    {
        NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransHandleEventLog error, roleId:{}, cmd:{}, transid:{}",
                   m_userId, m_cmd, m_reqTransId);
    }
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFTransHandleEventLog::HandleTransFinished(int iRunLogicRetCode)
{
    NFUserDetail* pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    if(iRunLogicRetCode != 0)
    {
        pUserDetail->GetEventLog()->OnHandleEventLog(m_ullEventLogUid, false);
    }

    return 0;
}

int NFTransHandleEventLog::HandleEventLog(proto_ff_s::tbEventLog_s *pstEventLog)
{
    CHECK_NULL(pstEventLog);
    NFUserDetail* pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);

    pUserDetail->GetEventLog()->SetInHandleTrans(true);
    m_ullEventLogUid = pstEventLog->event_id;

    proto_ff::tbEventLog tbEventLog;
    tbEventLog.set_user_id(pstEventLog->user_id);
    tbEventLog.set_event_id(m_ullEventLogUid);

    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                                          proto_ff::E_STORESVR_C2S_DELETEOBJ,
                                                                          proto_ff::E_TABLE_EVENT_LOG,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, "tbEventLog", tbEventLog,
                                                                          GetGlobalID(),
                                                                          0, pstEventLog->user_id);
    if (iRetCode)
    {
        SetFinished(iRetCode);
        return iRetCode;
    }

    return 0;
}

int
NFTransHandleEventLog::ProcessDeleteEventLogRes(const storesvr_sqldata::storesvr_delobj_res *pSelectRsp, uint32_t cmd,
                                                uint32_t table_id, uint32_t err_code) {
    NFUserDetail* pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);
    CHECK_NULL(pUserDetail->GetEventLog());

    if(proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY == err_code)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "eventlog id:{} is not exist!", m_ullEventLogUid);

        pUserDetail->GetEventLog()->DelEventLog(m_ullEventLogUid);

        SetFinished(0);
    }
    else if(proto_ff::E_STORESVR_ERRCODE_OK == err_code)
    {
        NFUserEventLog::HandleEventLog(pUserDetail, m_ullEventLogUid);

        SetFinished(0);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "del eventlog id::{}  failed! db ErrCode:{}", m_ullEventLogUid, err_code);
        return proto_ff::ERR_CODE_SYSTEM_DATABASE_ERROR;
    }

    return 0;
}




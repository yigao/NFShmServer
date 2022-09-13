// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetEventLog.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetEventLog.cpp
//
// -------------------------------------------------------------------------

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFTransGetEventLog.h"
#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"
#include "NFTransGetUserDetail.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetEventLog, EOT_TRANS_GET_EVENT_LOG_ID, NFTransLogicUserBase)

NFTransGetEventLog::NFTransGetEventLog() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransGetEventLog::~NFTransGetEventLog() noexcept {

}

int NFTransGetEventLog::CreateInit() {
    return 0;
}

int NFTransGetEventLog::ResumeInit() {
    return 0;
}

int NFTransGetEventLog::OnTimeOut() {
    NFTransLogicUserBase::OnTimeOut();
    NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransGetEventLog timeout, roleId:{}, cmd:{}, transid:{}",
               m_userId, m_cmd, m_reqTransId);
    return 0;
}

int NFTransGetEventLog::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                        uint32_t seq, uint32_t err_code) {
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_NULL(UserDetail());

    int iRetCode = 0;
    if (table_id == proto_ff::E_TABLE_EVENT_LOG) {
        if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ)
        {
            iRetCode = ProGetEventLogRes((const storesvr_sqldata::storesvr_selobj_res*)pSSMsgRes, cmd, table_id, err_code);
        }
        else if (cmd == proto_ff::E_STORESVR_S2C_SELECT)
        {
            iRetCode = ProGetEventLogListRes((const storesvr_sqldata::storesvr_sel_res*)pSSMsgRes, cmd, table_id, err_code);
        }
    }
    NFLogTrace(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFTransGetEventLog::GetEventLog(uint64_t userId, uint64_t eventId) {
    proto_ff::tbEventLog tbEventLog;
    tbEventLog.set_user_id(userId);
    tbEventLog.set_event_id(eventId);

    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                                          proto_ff::E_STORESVR_C2S_SELECTOBJ,
                                                                          proto_ff::E_TABLE_EVENT_LOG,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, "tbEventLog", tbEventLog,
                                                                          GetGlobalID(),
                                                                          0, userId);
    if (iRetCode)
    {
        SetFinished(iRetCode);
        return iRetCode;
    }
    return 0;
}

int NFTransGetEventLog::GetAllEventLog(uint64_t userId) {
    int iRetCode = 0;

    std::vector<storesvr_sqldata::storesvr_vk> vk_list;
    storesvr_sqldata::storesvr_vk vk;
    vk.set_column_name("user_id");
    std::string szID = NFCommon::tostr(userId);
    vk.set_column_value(szID);
    vk.set_column_type(storesvr_sqldata::E_COLUMNTYPE_NUM);
    vk.set_cmp_operator(storesvr_sqldata::E_CMPOP_EQUAL); //storesvr_sqldata::storesvr_cmp_operator
    vk.set_logic_operator(storesvr_sqldata::E_LOGICOP_NONE);
    vk_list.push_back(vk);

    if (vk_list.size() > 0) {
        std::string where_conds = NF_FORMAT("order by create_time asc LIMIT {}, {}", 0, MAX_EVENT_LOG_NUM + 1);

        vk_list[vk_list.size() - 1].set_logic_operator(storesvr_sqldata::E_LOGICOP_NONE);

        iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                                          proto_ff::E_STORESVR_C2S_SELECT,
                                                                          proto_ff::E_TABLE_EVENT_LOG,
                                                                          NF_DEFAULT_MYSQL_DB_NAME,
                                                                          "tbEventLog", vk_list, where_conds,
                                                                          GetGlobalID(),
                                                                          0, userId);
    }

    if (iRetCode)
    {
        SetFinished(iRetCode);
        return iRetCode;
    }
    return 0;
}

int NFTransGetEventLog::ProGetEventLogRes(const storesvr_sqldata::storesvr_selobj_res *pSelectRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code) {
    CHECK_NULL(pSelectRsp);
    CHECK_EXPR((0 == err_code), proto_ff::ERR_CODE_SYSTEM_DATABASE_ERROR, "get eventlog failed!");

    proto_ff::tbEventLog tbEventLog;
    bool ok = tbEventLog.ParseFromString(pSelectRsp->sel_record());
    CHECK_EXPR( ok, -1, "ParseFromString failed");

    NFUserDetail* pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);
    CHECK_NULL(pUserDetail->GetEventLog());

    pUserDetail->GetEventLog()->AddEventLog(tbEventLog);

    SetFinished(0);
    return 0;
}

int NFTransGetEventLog::ProGetEventLogListRes(const storesvr_sqldata::storesvr_sel_res *pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code) {
    CHECK_NULL(pSelRsp);
    CHECK_EXPR( (0 == err_code), proto_ff::ERR_CODE_SYSTEM_DATABASE_ERROR, "get eventlog failed!");

    NFUserDetail* pUserDetail = UserDetail();
    CHECK_NULL(pUserDetail);
    CHECK_NULL(pUserDetail->GetEventLog());

    if(proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY == err_code)
    {
        pUserDetail->GetEventLog()->SetGetFinish(true);
        SetFinished(0);
        return 0;
    }

    bool bEventLogFull = false;
    for(int i = 0; i < (int)pSelRsp->sel_records_size(); i++)
    {
        if (pUserDetail->GetEventLog()->IsEventLogFull())
        {
            bEventLogFull = true;
            break;
        }

        proto_ff::tbEventLog tbEventLog;
        bool ok = tbEventLog.ParseFromString(pSelRsp->sel_records(i));
        if (ok)
        {
            pUserDetail->GetEventLog()->AddEventLog(tbEventLog);
        }
    }

    if (pSelRsp->is_lastbatch() && !bEventLogFull)
    {
        pUserDetail->GetEventLog()->SetGetFinish(true);
    }
    else
    {
        pUserDetail->GetEventLog()->SetGetFinish(false);
    }

    SetFinished(0);
    return 0;
}



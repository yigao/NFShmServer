// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetSnsUserSimple.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetSnsUserSimple.cpp
//
// -------------------------------------------------------------------------

#include "NFTransGetSnsUserSimple.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

#include "NFSnsUserSimple.h"
#include "NFSnsUserSimpleMgr.h"
#include "NFSnsUserSimpleUtil.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetSnsUserSimple, EOT_TRANS_GET_USER_SIMPLE, NFTransBase)

NFTransGetSnsUserSimple::NFTransGetSnsUserSimple() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransGetSnsUserSimple::~NFTransGetSnsUserSimple() {

}

int NFTransGetSnsUserSimple::CreateInit() {
    m_userId = 0;
    return 0;
}

int NFTransGetSnsUserSimple::ResumeInit() {
    return 0;
}

int NFTransGetSnsUserSimple::Init(uint64_t userId) {
    m_userId = userId;
    return 0;
}

int NFTransGetSnsUserSimple::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetSnsUserSimple::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                            uint32_t seq,
                                            uint32_t err_code) {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");

    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ) {
        if (table_id == proto_ff::E_TABLE_USER_SIMPLE) {
            iRetCode = ProQueryRoleRes((const storesvr_sqldata::storesvr_selobj_res *)pSSMsgRes, err_code, seq);
        }
        else
        {
            iRetCode = -1;
        }
    }
    else
    {
        iRetCode = -1;
    }
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFTransGetSnsUserSimple::QueryUser(uint64_t userId) {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    if (NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(userId, false))
    {
        SetFinished(0);
        return 0;
    }

    proto_ff::tbUserSimpleData userSimple;
    m_userId = userId;
    userSimple.set_userid(userId);

    NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_SNS_SERVER,
                                                           proto_ff::E_STORESVR_C2S_SELECTOBJ, proto_ff::E_TABLE_USER_SIMPLE, NF_DEFAULT_MYSQL_DB_NAME, "tbUserSimpleData", userSimple,
                                                           GetGlobalID(), 0, userId);
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetSnsUserSimple::ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res *pSelectRsp, uint32_t err_code,
                                             int iTransID) {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");

    if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY) {
        SetFinished(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        return 0;
    }

    if (err_code == proto_ff::E_STORESVR_ERRCODE_OK)
    {
        proto_ff::tbUserSimpleData simpleData;
        bool ok = simpleData.ParseFromString(pSelectRsp->sel_record());
        CHECK_EXPR(ok, -1, "ParseFromString Faield!");

        NFSnsUserSimple* pUserSimple = NFSnsUserSimpleMgr::GetInstance()->CreateUser(m_userId);
        CHECK_EXPR(pUserSimple, -1, "insert role simple err");

        if (pUserSimple->IsSyncedRoleSimple() == false)
        {
            pUserSimple->InitWithSnsRoleSimpleInfo(&simpleData);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "trans get user simple data error:{}", err_code);
        return -1;
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransGetSnsUserSimple::OnTransFinished(int iRunLogicRetCode) {
    NFSnsUserSimpleUtil::GetInstance()->HandleGetRoleTransFinished(iRunLogicRetCode, m_userId);
    return 0;
}


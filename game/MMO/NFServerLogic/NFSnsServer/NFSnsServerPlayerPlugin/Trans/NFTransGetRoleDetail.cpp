// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleDetail.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleDetail
//
// -------------------------------------------------------------------------

#include "NFTransGetRoleDetail.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Cache/NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetRoleDetail, EOT_SNS_TRANS_GET_ROLE_DETAIL_ID, NFTransBase)

NFTransGetRoleDetail::NFTransGetRoleDetail() : NFTransBase()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransGetRoleDetail::~NFTransGetRoleDetail()
{
}

int NFTransGetRoleDetail::CreateInit()
{
    m_roleId = 0;
    return 0;
}

int NFTransGetRoleDetail::ResumeInit()
{
    return 0;
}


int NFTransGetRoleDetail::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransGetRoleDetail::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                         uint32_t seq,
                                         uint32_t err_code) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_SELECTOBJ) {
        iRetCode = ProQueryRoleRes((const storesvr_sqldata::storesvr_selobj_res *)pSSMsgRes, err_code, seq);
    }
    else
    {
        iRetCode = -1;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return iRetCode;
}

int NFTransGetRoleDetail::QueryRole(uint64_t roleId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    m_roleId = roleId;

    auto pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleDetail(m_roleId);
    if (pRoleDetail)
    {
        SetFinished(0);
        return 0;
    }

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_EXPR_ASSERT(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER) Failed");

    proto_ff::RoleDBSnsDetail xData;
    xData.set_cid(m_roleId);

    FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                 proto_ff::E_STORESVR_C2S_SELECTOBJ, 0, pServerConfig->DefaultDBName,
                                                                 "RoleDBSnsDetail", xData,GetGlobalID(), 0, m_roleId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransGetRoleDetail::ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res *pSelectRsp, uint32_t err_code,
                                          int iTransID) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY) {
        return proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY;
    }

    if (err_code == proto_ff::E_STORESVR_ERRCODE_OK)
    {
        proto_ff::RoleDBSnsDetail detailData;
        bool ok = detailData.ParsePartialFromString(pSelectRsp->sel_record());
        CHECK_EXPR(ok, -1, "ParseFromString Faield!");

        NFRoleDetail *pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreateRoleDetail(m_roleId);
        CHECK_EXPR(pRoleDetail, -1, "CreateRoleDetail Failed");

        if (!pRoleDetail->IsInited())
        {
            pRoleDetail->Init(detailData);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "trans get user detail data error:{}", err_code);
        return -1;
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransGetRoleDetail::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleDetailTransFinished(iRunLogicRetCode, m_roleId);
    return 0;
}
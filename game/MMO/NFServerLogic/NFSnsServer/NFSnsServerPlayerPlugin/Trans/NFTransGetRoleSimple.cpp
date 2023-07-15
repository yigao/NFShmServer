// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleRimple.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleRimple
//
// -------------------------------------------------------------------------

#include "NFTransGetRoleSimple.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "DBProto2.pb.h"
#include "Cache/NFCacheMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransGetRoleSimple, EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID, NFTransBase)

NFTransGetRoleSimple::NFTransGetRoleSimple() : NFTransBase()
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

NFTransGetRoleSimple::~NFTransGetRoleSimple()
{
}

int NFTransGetRoleSimple::CreateInit()
{
    m_roleId = 0;
    return 0;
}

int NFTransGetRoleSimple::ResumeInit()
{
    return 0;
}


int NFTransGetRoleSimple::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransGetRoleSimple::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                                            uint32_t seq,
                                            int32_t err_code) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    int iRetCode = 0;
    if (cmd == proto_ff::NF_STORESVR_S2C_SELECTOBJ) {
        iRetCode = ProQueryRoleRes((const storesvr_sqldata::storesvr_selobj_res *)pSSMsgRes, err_code, seq);
    }
    else
    {
        iRetCode = -1;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return iRetCode;
}

int NFTransGetRoleSimple::QueryRole(uint64_t roleId) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    m_roleId = roleId;

    if (NFCacheMgr::GetInstance(m_pObjPluginManager)->QueryRoleSimple(m_roleId, false))
    {
        SetFinished(0);
        return 0;
    }

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_EXPR_ASSERT(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER) Failed");

    proto_ff::RoleDBSimpleData xData;
    xData.set_cid(m_roleId);

    FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                 proto_ff::NF_STORESVR_C2S_SELECTOBJ, 0, pServerConfig->DefaultDBName,
                                                                 "RoleDBData", xData, GetGlobalId(), 0, m_roleId, "RoleDBSimpleData");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransGetRoleSimple::ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res *pSelectRsp, int32_t err_code,
                                             int iTransID) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    if (err_code == proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY) {
        return proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY;
    }

    if (err_code == proto_ff::ERR_CODE_SVR_OK)
    {
        proto_ff::RoleDBSimpleData simpleData;
        bool ok = simpleData.ParsePartialFromString(pSelectRsp->sel_record());
        CHECK_EXPR(ok, -1, "ParseFromString Faield!");

        NFRoleSimple* pRoleSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreateRoleSimple(m_roleId);
        CHECK_EXPR(pRoleSimple, -1, "insert role simple err");

        if (!pRoleSimple->IsInited())
        {
            pRoleSimple->Init(simpleData);
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "trans get user simple data error:{}", err_code);
        return -1;
    }

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransGetRoleSimple::OnTransFinished(int iRunLogicRetCode) {
    NFLoadCacheMgr::GetInstance(m_pObjPluginManager)->HandleGetRoleSimpleTransFinished(iRunLogicRetCode, m_roleId);
    return 0;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFTransRoleLOgin.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransRoleLOgin
//
// -------------------------------------------------------------------------

#include "NFTransRoleLogin.h"
#include "ServerInternalCmd2.pb.h"
#include "Cache/NFRoleSimple.h"
#include "Cache/NFCacheMgr.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransRoleLogin, EOT_SNS_TRANS_ROLE_LOGIN_ID, NFTransBase)

NFTransRoleLogin::NFTransRoleLogin() : NFTransCacheBase()
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

NFTransRoleLogin::~NFTransRoleLogin()
{
}

int NFTransRoleLogin::CreateInit()
{
    m_roleId = 0;
    m_cmd = 0;
    m_logicId = 0;
    m_proxyId = 0;
    m_simpleInfo.CreateInit();
    m_lastLoginTime = 0;
    m_lastLogoutTime = 0;
    return 0;
}

int NFTransRoleLogin::ResumeInit()
{
    return 0;
}

int NFTransRoleLogin::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    return NFTransBase::HandleCSMsgReq(pCSMsgReq);
}

int NFTransRoleLogin::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, uint32_t err_code)
{
    int iRetCode = 0;
    if (cmd == proto_ff::E_STORESVR_S2C_INSERT)
    {
        iRetCode = OnHandleInsertRoleDetailRes((const storesvr_sqldata::storesvr_ins_res*)pSSMsgRes, err_code);
    }
    else {
        iRetCode = -1;
    }
    return iRetCode;
}

int NFTransRoleLogin::OnHandleInsertRoleDetailRes(const storesvr_sqldata::storesvr_ins_res *pRes, int err_code)
{
    if (err_code == proto_ff::E_STORESVR_ERRCODE_OK)
    {
        proto_ff::RoleDBSnsDetail xData;
        xData.set_cid(m_roleId);

        NFRoleDetail *pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->CreateRoleDetail(m_roleId);
        CHECK_EXPR(pRoleDetail, -1, "CreateRoleDetail Failed");

        if (!pRoleDetail->IsInited())
        {
            pRoleDetail->Init(xData);
        }

        HandleGetRoleDetailRes(0, m_roleId);
    }
    return 0;
}

int NFTransRoleLogin::OnRoleLogin(const proto_ff::WorldToSnsLoginReq& req)
{
    m_cmd = proto_ff::WORLD_TO_SNS_LOGIN_REQ;
    m_proxyId = req.proxy_id();
    m_logicId = req.logic_id();
    m_simpleInfo.read_from_pbmsg(req.simple_data());
    m_roleId = m_simpleInfo.cid;

    QueryRoleSimple(m_simpleInfo.cid);
    return 0;
}

int NFTransRoleLogin::QueryRole_CallBack(NFQueryRole& query)
{
    NFRoleSimple* pRoleSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleSimple(query.m_roleId);
    if (pRoleSimple == NULL)
    {
        return -1;
    }

    NFRoleDetail* pRoleDetail = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleDetail(query.m_roleId);
    if (pRoleDetail == NULL)
    {
        return -1;
    }

    return 0;
}

int NFTransRoleLogin::HandleGetRoleSimpleRes(int iRunLogicRetCode, uint64_t roleId)
{
    AddQueryedSimpleNum();
    if (iRunLogicRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Query Role Simple Data Failed From DB, roleId:{} retCode:{}", roleId, iRunLogicRetCode);
    }

    if (IsQuerySimpleFinished())
    {
        if (m_bGetDetail)
        {
            QueryRoleDetail();
        }
        else
        {
            int iRetCode = QueryRole_CallBack(m_query);
            SetFinished(iRetCode);
        }
    }

    return 0;
}

int NFTransRoleLogin::OnTransFinished(int iRunLogicRetCode)
{
    if (m_cmd == proto_ff::WORLD_TO_SNS_LOGIN_REQ)
    {
        OnRoleLoginRes(iRunLogicRetCode);
    }

    return 0;
}

int NFTransRoleLogin::OnRoleLoginRes(int iRunLogicRetCode)
{
    proto_ff::SnsToWorldLoginRsp rspMsg;
    rspMsg.set_ret_code(iRunLogicRetCode);
    rspMsg.set_cid(m_simpleInfo.cid);
    rspMsg.set_uid(m_simpleInfo.uid);
    if (iRunLogicRetCode != 0)
    {
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_SNS_SERVER, proto_ff::SNS_TO_WORLD_LOGIN_RSP, rspMsg);
        return 0;
    }

    NFRoleSimple* pRoleSimple = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleSimple(m_simpleInfo.cid);
    CHECK_EXPR_ASSERT(pRoleSimple, -1, "GetRoleSimple Failed, uid:{} cid:{}", m_simpleInfo.uid, m_simpleInfo.cid);

    pRoleSimple->SetIsOnline(true);
    pRoleSimple->SetBaseData(m_simpleInfo.base);
    pRoleSimple->SetLogicId(m_logicId);
    pRoleSimple->SetProxyId(m_proxyId);

    pRoleSimple->SendMsgToWorldServer(proto_ff::SNS_TO_WORLD_LOGIN_RSP, rspMsg);
    return 0;
}

int NFTransRoleLogin::HandleGetRoleDetailRes(int iRunLogicRetCode, uint64_t roleId)
{
    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    CHECK_EXPR_ASSERT(pServerConfig, -1, "FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER) Failed");

    if (iRunLogicRetCode == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY)
    {
        proto_ff::RoleDBSnsDetail xData;
        xData.set_cid(roleId);

        return FindModule<NFIServerMessageModule>()->SendTransToStoreServer(NF_ST_LOGIC_SERVER, 0,
                                                                     proto_ff::E_STORESVR_C2S_INSERT, 0, pServerConfig->DefaultDBName,
                                                                     "RoleDBSnsDetail", xData,GetGlobalID(), 0, roleId);
    }
    else {
        return NFTransCacheBase::HandleGetRoleDetailRes(iRunLogicRetCode, roleId);
    }
}

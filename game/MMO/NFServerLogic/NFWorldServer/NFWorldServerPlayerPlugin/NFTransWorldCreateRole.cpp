// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldCreateRole.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldCreateRole
//
// -------------------------------------------------------------------------

#include "NFTransWorldCreateRole.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "ServerInternalCmd2.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "CSLogin.pb.h"
#include "ClientServerCmd.pb.h"
#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "NFTransWorldGetRoleList.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFServerTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransWorldCreateRole, EOT_NFTransWorldCreateRole_ID, NFTransBase)

NFTransWorldCreateRole::NFTransWorldCreateRole()
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

NFTransWorldCreateRole::~NFTransWorldCreateRole()
{
}

int NFTransWorldCreateRole::CreateInit()
{
    m_uid = 0;
    m_roleId = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_bornZid = 0;
    return 0;
}

int NFTransWorldCreateRole::ResumeInit()
{
    return 0;
}

int NFTransWorldCreateRole::Init(uint64_t uid, uint64_t roleId, uint32_t proxyId, uint64_t clientId, uint32_t bornZid)
{
    m_uid = uid;
    m_roleId = roleId;
    m_proxyId = proxyId;
    m_clientId = clientId;
    m_bornZid = bornZid;
    return 0;
}

int NFTransWorldCreateRole::SendCreateRoleInfo(const proto_ff::WorldToLogicCreateRoleReq& createRoleReq)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1, "OnHandleCreateRole, GetPlayerByUid return NULL, uid:{}", m_uid);

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_CREATE_ROLE_INFO_REQ, createRoleReq, GetGlobalID());

    return 0;
}

int NFTransWorldCreateRole::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch(nMsgId)
    {
        case proto_ff::LOGIC_TO_WORLD_CREATE_ROLE_INFO_RSP:
        {
            return OnHandleLogicCreateRoleRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransWorldCreateRole::OnHandleLogicCreateRoleRsp(uint32_t msgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::LogicToWorldCreateRoleRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t uid = xData.uid();
    uint64_t cid = xData.cid();

    CHECK_EXPR(uid == m_uid, -1, "");
    CHECK_EXPR(cid == m_roleId, -1, "");

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1, "OnHandleLogicCreateRoleRsp, GetPlayerByUid return NULL, playerId:{}", m_uid);

    proto_ff::ClientCreateRoleRsp xDataRsp;
    xDataRsp.set_result(xData.ret_code());

    if (xData.ret_code() == proto_ff::RET_SUCCESS)
    {
        if (pPlayer->GetRoleId() == m_roleId)
        {
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CharDBToCharSimpleDB(xData.role_info(), *xDataRsp.mutable_info());
            auto pRoleInfo = pPlayer->GetRoleInfo(cid);
            CHECK_EXPR_ASSERT(pRoleInfo == NULL, -1, "role:{} exist", cid);
            pRoleInfo = pPlayer->CreateRoleInfo(cid);
            CHECK_EXPR_ASSERT(pRoleInfo != NULL, -1, "CreateRoleInfo Failed:{}", cid);
            pRoleInfo->m_logicId = pPlayer->GetLogicId();
            pRoleInfo->SetRoleInfo(xData.role_info());

            auto pTempPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreateCidIndexToUid(cid, uid);
            CHECK_EXPR_ASSERT(pPlayer == pTempPlayer, -1, "CreateCidIndexToUid Error");
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateRoleInfo Error..........., the create roleId:{} not equal return roleId:{}", pPlayer->GetRoleId(),
                       cid);
            pPlayer->SetRoleId(0);
            //强制断开之前的客户端session
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId(), proto_ff::LOGOUT_REPLACE);
            return 0;
        }
    }

    uint64_t newClientId = pPlayer->GetClientId();
    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
        NFLogError(NF_LOG_SYSTEMLOG, uid, "clientId != newClientId....uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return 0;
    }

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return 0;
    }

    if (pSession->IsDisconnect())
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession IsDisconnect, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return 0;
    }

    pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_CREATE_ROLE_RSP, xDataRsp);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransWorldCreateRole::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0)
    {
        NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
        CHECK_EXPR(pPlayer, -1,
                   "OnTransFinished, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
                   m_uid);

        uint64_t newClientId = pPlayer->GetClientId();
        if (newClientId > 0 && m_clientId != newClientId)
        {
            //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
            //直接把旧的连接断开
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
            return 0;
        }

        NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
        if (pSession == NULL)
        {
            return 0;
        }

        if (pSession->IsDisconnect())
        {
            return 0;
        }

        proto_ff::ClientCreateRoleRsp xDataRsp;
        xDataRsp.set_result(iRunLogicRetCode);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_CREATE_ROLE_RSP, xDataRsp);
    }

    return 0;
}

int NFTransWorldCreateRole::OnTimeOut()
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1,
               "OnTransFinished, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
               m_uid);

    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
    return 0;
}
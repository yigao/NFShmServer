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
#include "DescStoreEx/NFMapDescStoreEx.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"

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

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    CHECK_EXPR(pSession, -1, "GetSession, GetSession return NULL, clientId:{}", m_clientId);

    pSession->SetState(EAccountState::createrole);

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
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CharDBToCharSimpleDB(xData.role_info(), *xDataRsp.mutable_info());
        auto pRoleInfo = pPlayer->GetRoleInfo(cid);
        CHECK_EXPR_ASSERT(pRoleInfo == NULL, -1, "role:{} exist", cid);
        pRoleInfo = pPlayer->CreateRoleInfo(cid);
        CHECK_EXPR_ASSERT(pRoleInfo != NULL, -1, "CreateRoleInfo Failed:{}", cid);
        pRoleInfo->SetRoleInfo(xData.role_info());
    }

    uint64_t newClientId = pPlayer->GetClientId();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    //创建角色的账号必须处于登录状态
    if (EAccountState::createrole != pSession->GetState())
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession state error, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFLogError(NF_LOG_SYSTEMLOG, uid, "clientId != newClientId....uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    pSession->SetState(EAccountState::loading);

    pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_CREATE_ROLE_RSP, xDataRsp);

    SetFinished(0);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFTransWorldCreateRole::OnTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0)
    {
        if (iRunLogicRetCode < 0)
        {
            NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
            NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, pSession, proto_ff::LOGOUT_KICK_OUT);
            return 0;
        }

        NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
        if (pSession == NULL) return 0;

        NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
        if (pPlayer == NULL)
        {
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
            return 0;
        }

        uint64_t newClientId = pPlayer->GetClientId();
        if (newClientId > 0 && m_clientId != newClientId)
        {
            //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
            //直接把旧的连接断开
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
            return 0;
        }

        pSession->SetState(EAccountState::loading);

        proto_ff::ClientCreateRoleRsp xDataRsp;
        xDataRsp.set_result(iRunLogicRetCode);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_CREATE_ROLE_RSP, xDataRsp);
    }

    return 0;
}

int NFTransWorldCreateRole::OnHandleCreateRole(const proto_ff::ClientCreateRoleReq& xData)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1, "OnHandleCreateRole, GetPlayerByUid return NULL, uid:{}", m_uid);

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "can't find the session from clientId:{}", m_clientId);
        return -1;
    }

    if (pPlayer->GetClientId() != m_clientId)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "pPlayer->GetClientId():{} != m_clientId:{}", pPlayer->GetClientId(), m_clientId);
        return -1;
    }

    if (pPlayer->IsInTransSceneing())
    {
        SetFinished(0);
        return 0;
    }

    //创建角色的账号必须处于拉取角色列表完毕状态
    if (pSession->GetState() != EAccountState::loading)
    {
        if (pSession->GetState() == EAccountState::loadrole || pSession->GetState() == EAccountState::createrole)
        {
            return proto_ff::RET_REPEATED_OPERATE;
        }
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "create role faild, account state error, uid:{}, state:{}, clientId:{},account_clientid:{}, gateid:{}", m_uid, (int)pSession->GetState(), m_clientId, pSession->GetClientId(), pSession->GetProxyId());
        return -1;
    }

    uint32_t prof = xData.prof();
    const string &name = xData.name();
    int32_t color = xData.color();

    if (pPlayer->GetCharNum() >= MAX_ROLE_NUM)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "the player role >= MAX_ROLE_NUM, some error happened, uid:{}", MAX_ROLE_NUM, m_uid);
        return proto_ff::RET_LOGIN_CHARACTER_NUM_LIMIT;
    }

    int32_t name_len = (int32_t) name.length();
    if (name_len < proto_ff::CHARACTER_NAME_MIN_LENGTH || name_len >= proto_ff::CHARACTER_NAME_MAX_LENGTH)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "create role, role name length error...uid:{},name_len:{}", m_uid, name_len);
        return proto_ff::RET_LOGIN_CHARACTER_NAME_LEN_ERROR;
    }

    auto pBornProf = NFMapDescStoreEx::Instance(m_pObjPluginManager)->GetBornCfg(prof);
    if (pBornProf == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "create role, prof error...uid:{},prof:{}", m_uid, prof);
        return proto_ff::RET_LOGIN_CHARACTER_PROF_ERROR;
    }

    const NFPoint3<float> *pPoscfg = NFMapDescStoreEx::Instance(m_pObjPluginManager)->RandBornPoint(pBornProf->m_mapid);
    if (nullptr == pPoscfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "create role, RandBornPoint error...uid:{},mapId:{}", m_uid, pBornProf->m_mapid);
        return proto_ff::RET_LOGIN_CHARACTER_PROF_ERROR;
    }

    m_roleId = FindModule<NFIKernelModule>()->Get32UUID();
    proto_ff::WorldToLogicCreateRoleReq createRoleReq;
    createRoleReq.set_uid(m_uid);
    createRoleReq.set_cid(m_roleId);
    createRoleReq.set_zid(m_pObjPluginManager->GetZoneID());
    createRoleReq.set_born_zid(m_bornZid);
    createRoleReq.set_name(name);
    createRoleReq.set_prof(prof);
    createRoleReq.set_level(pBornProf->m_bornlevel);
    createRoleReq.set_color(color);

    createRoleReq.set_enter_scene_id(pBornProf->m_mapid);
    createRoleReq.set_enter_map_id(pBornProf->m_mapid);
    createRoleReq.set_enterposx(pPoscfg->x);
    createRoleReq.set_enterposy(pPoscfg->y);
    createRoleReq.set_enterposz(pPoscfg->z);

    createRoleReq.set_lastsceneid(pBornProf->m_mapid);
    createRoleReq.set_lastmapid(pBornProf->m_mapid);
    createRoleReq.set_lastposx(pPoscfg->x);
    createRoleReq.set_lastposy(pPoscfg->y);
    createRoleReq.set_lastposz(pPoscfg->z);

    NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
    if (pPlayer->GetLogicId() > 0)
    {
        pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
    }

    if (pLogicServer)
    {
        SendCreateRoleInfo(createRoleReq);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "create role failed, can't find logic server");
        return -1;
    }

    return 0;
}
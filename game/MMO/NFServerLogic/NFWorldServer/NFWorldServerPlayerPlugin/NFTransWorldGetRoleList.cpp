// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldSendGetRoleList.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldSendGetRoleList
//
// -------------------------------------------------------------------------

#include "NFTransWorldGetRoleList.h"
#include "ServerInternal2.pb.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "ServerInternalCmd2.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFWorldConfig.h"
#include "CSLogin.pb.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "ClientServerCmd.pb.h"
#include "NFWorldSessionMgr.h"
#include "NFWorldSession.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "ServerInternalCmd.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransWorldGetRoleList, EOT_NFTransWorldSendGetRoleList_ID, NFTransBase)

NFTransWorldGetRoleList::NFTransWorldGetRoleList()
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

NFTransWorldGetRoleList::~NFTransWorldGetRoleList()
{
}

int NFTransWorldGetRoleList::CreateInit()
{
    m_uid = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_loginZid = 0;
    m_chanId = 0;
    return 0;
}

int NFTransWorldGetRoleList::ResumeInit()
{
    return 0;
}

int NFTransWorldGetRoleList::Init(uint64_t uid, uint32_t proxyId, uint64_t clientId, uint32_t loginZid, uint32_t chanId)
{
    m_uid = uid;
    m_proxyId = proxyId;
    m_clientId = clientId;
    m_loginZid = loginZid;
    m_chanId = chanId;
    return 0;
}

int NFTransWorldGetRoleList::OnHandleClientLogin()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    uint64_t tick = NFServerTime::Instance()->Tick();

    if (pExternalConfig->WhiteListState)
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(m_uid))
        {
            return proto_ff::RET_DISALLOW_ENTER_GAME;
        }
    }
    else {
        //没到开服时间，不让进去,白名单无视这个条件
        if (pConfig->ServerOpenTime > NFServerTime::Instance()->UnixSec())
        {
            return proto_ff::RET_NOT_OPEN_TIME;
        }

        //超过排队人数，则直接通知不能排队，返回消息
        if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsLoginQueueFull())
        {
            return proto_ff::RET_LOGIN_QUEUE_ENOUGHT_NUM;
        }
    }

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    if (pPlayer == NULL)
    {
        pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayerByUid(m_uid);
        if (pPlayer == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_uid, "CreatePlayerByUid Failed, uid:{}", m_clientId, m_uid);
            return -1;
        }
    }

    uint64_t oldClientId = pPlayer->GetClientId();

    NFWorldSession *pOldSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(oldClientId);

    bool isNeedLeaveScene = false;
    if (pOldSession != NULL)
    {
        if (oldClientId == m_clientId)
        {
            //如果是同一个连接在不断的请求发该协议 那么进行过滤
            NFLogError(NF_LOG_SYSTEMLOG, m_uid,
                       "LoginGateReq... same player login...clientid:{}, oldclientid:{}, gateid:{}, uid:{}, roleId:{}, logicid:{}, state:{}, oldgateid:{},loginzid:{}",
                       m_clientId, oldClientId, m_proxyId, pPlayer->GetUid(), pPlayer->GetRoleId(), pPlayer->GetLogicId(), pPlayer->GetStatus(),
                       pPlayer->GetProxyId(),
                       m_loginZid);
            SetFinished(0);
        }

        NFLogError(NF_LOG_SYSTEMLOG, m_uid,
                   "LoginGateReq...same account login, notify logic kick player logout.. uid:{}, kick_cid:{}, logicid:{}, clientid:{}, oldclientid:{},state:{},oldgateid:{},loginzid:{}"
        , pOldSession->GetUid(), pOldSession->GetRoleId(), pOldSession->GetLogicId(), m_clientId, oldClientId, (int)pOldSession->GetState(),
                   pOldSession->GetProxyId(), m_loginZid);

        //如果旧账号处于 登录或者向DB请求角色列表或者排队状态，删除账号
        //强制断开之前的客户端session
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pOldSession->GetProxyId(), pOldSession->GetClientId(), proto_ff::LOGOUT_REPLACE);

        //删除 uid和 clientid的映射
        pPlayer->SetProxyId(0);
        pPlayer->SetClientId(0);
        //如果在排队，需要从排队列表移除

        if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsInLoginQueue(m_uid))
        {
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->DeleteLoginQueue(m_uid);
        }
    }

    if (pPlayer->GetRoleId() > 0)
    {
        if (!pPlayer->IsInTransSceneing())
        {
            int ret = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, NULL, proto_ff::LOGOUT_REPLACE, GetGlobalId());
            if (ret == 0)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, m_uid, "player role:{} > 0 and not in trans scene, NotifyLogicLeave", pPlayer->GetRoleId());
                isNeedLeaveScene = true;
            }
        }
        else {
            NFLogInfo(NF_LOG_SYSTEMLOG, m_uid, "player role > 0, but in trans scene, get role list fail! wait....");
            SetFinished(0);
            return 0;
        }
    }

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->CreateSession(m_clientId);
        if (pSession == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_clientId, "CreateSession Failed, clientId:{} uid:{}", m_clientId, m_uid);
            return -1;
        }
    }

    pSession->SetProxyId(m_proxyId);
    pSession->SetUid(m_uid);
    pSession->SetState(EAccountState::login);
    pSession->SetStateTick(tick);
    pSession->SetLoginZid(m_loginZid);
    pSession->SetChanId(m_chanId);
    pSession->SetRoleId(0);

    pPlayer->SetTokenTimeStamp(tick);
    pPlayer->SetStatus(PLAYER_STATUS_ONLINE);
    pPlayer->SetProxyId(m_proxyId);
    pPlayer->SetClientId(m_clientId);
    pPlayer->SetLoginZid(m_loginZid);
    pPlayer->SetChannelId(m_chanId);
    pPlayer->SetRoleId(0);

    //如果到了排队为数，直接加进排队人数列表，返回排队消息
    if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsNeedLoginQueue())
    {
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->HandleLoginQueue(pPlayer);
        SetFinished(0);
    }
    else
    {
        NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
        if (pPlayer->GetLogicId() > 0)
        {
            pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
        }
        else {
            pLogicServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                     pPlayer->GetUid());
        }

        if (pLogicServer == NULL)
        {
            pLogicServer = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER);
        }

        if (pLogicServer)
        {
            pPlayer->SetLogicId(pLogicServer->mServerInfo.bus_id());
            pSession->SetLogicId(pLogicServer->mServerInfo.bus_id());

            if (!isNeedLeaveScene)
            {
                SendGetRoleList();
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_uid, "can not find suit logic server to player, the all logic server may be dump");
            pPlayer->SetProxyId(0);
            pPlayer->SetClientId(0);

            return -1;
        }
    }

    return 0;
}

int NFTransWorldGetRoleList::SendGetRoleList()
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_NULL(pPlayer);

    proto_ff::WorldToLogicGetRoleList xData;
    xData.set_uid(m_uid);
    xData.set_born_zone_id(m_loginZid);
    xData.set_proxy_id(m_proxyId);
    xData.set_client_id(m_clientId);

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_GET_ROLE_LIST_REQ, xData, GetGlobalId());
    return 0;
}

int NFTransWorldGetRoleList::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch(nMsgId)
    {
        case proto_ff::LOGIC_TO_WORLD_GET_ROLE_LIST_RSP:
        {
            return OnHandleLogicGetRoleListRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        case proto_ff::NOTIFY_LOGIC_LEAVE_GAME_RSP:
        {
            return OnHandleLogicLeaveGameRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:break;
    }

    return 0;
}

int NFTransWorldGetRoleList::OnHandleLogicGetRoleListRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::LogicToWorldGetRoleListRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    uint64_t uid = xData.uid();
    uint64_t clientId = xData.client_id();
    uint32_t proxyId = xData.proxy_id();
    uint32_t bornZid = xData.born_zone_id();

    CHECK_EXPR(uid == m_uid, -1, "");
    CHECK_EXPR(clientId == m_clientId, -1, "");
    CHECK_EXPR(proxyId == m_proxyId, -1, "");
    CHECK_EXPR(bornZid == m_loginZid, -1, "");

    int err_code = xData.ret_code();

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1,
               "OnHandleLogicGetRoleListRsp, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
               uid);

    uint64_t newClientId = pPlayer->GetClientId();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return -1;
    }

    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFLogError(NF_LOG_SYSTEMLOG, uid, "clientId != newClientId....uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return -1;
    }

    //再加一下状态判断 状态出错直接断开连接
    if (pSession->GetState() != EAccountState::login)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession->GetState() != EAccountState::login, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, clientId, proxyId);
        return -1;
    }

    proto_ff::ClientLoginRsp loginrsp;
    loginrsp.set_ret(proto_ff::RET_SUCCESS);
    loginrsp.set_unix_sec(NFTime::Now().UnixSec());
    loginrsp.set_unix_msec(NFTime::Now().UnixMSec());
    loginrsp.set_time_zone(NFServerTime::Instance()->CurTimeZone());
    if (err_code == 0)
    {
        pPlayer->ClearRoleInfo();

        //先判断是否注册人数已满,新号，且注册人数已超，则不让进
        if (xData.role_info_list_size() <= 0 && xData.register_num() >= pExternalConfig->MaxRegisterNum)
        {
            loginrsp.set_ret(proto_ff::RET_ACCOUNT_FULL);
        }
        else
        {
            for (int i = 0; i < (int) xData.role_info_list_size(); i++)
            {
                auto pDBProto = xData.mutable_role_info_list(i);
                NF_ASSERT(pDBProto);
                for (int j = 0; j < pDBProto->mutable_base()->mutable_facade()->growfacade_size(); j++)
                {
                    auto pAttr = pDBProto->mutable_base()->mutable_facade()->mutable_growfacade(j);
                    NF_ASSERT(pAttr);
                    if (pAttr->id() == proto_ff::GrowType_DEITY_TYPE)
                    {
                        pAttr->set_value(0);
                    }
                }

                auto pCharSimpleDB = loginrsp.add_role_lst();
                if (nullptr != pCharSimpleDB)
                {
                    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CharDBToCharSimpleDB(xData.role_info_list(i), *pCharSimpleDB);
                    auto pRoleInfo = pPlayer->CreateRoleInfo(pCharSimpleDB->cid());
                    CHECK_EXPR_ASSERT(pRoleInfo != nullptr, -1, "CreateRoleInfo Failed! cid:{}", pCharSimpleDB->cid());
                    pRoleInfo->SetRoleInfo(xData.role_info_list(i));
                }
            }
        }

        pPlayer->SetCharNum(xData.role_info_list_size());

        pSession->SetState(EAccountState::loading);
        pSession->SetStateTick(NFServerTime::Instance()->Tick());

        NFLogInfo(NF_LOG_SYSTEMLOG, uid, "client login  account ok, playerId:{}, bornzid:{}", uid, pPlayer->GetLoginZid());
    }
    else
    {
        loginrsp.set_ret(err_code);
    }

    pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_LOGIN_RSP, loginrsp);
    SetFinished(0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransWorldGetRoleList::OnHandleLogicLeaveGameRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::NotifyLogicLeaveGameRsp2 xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    uint64_t uid = xData.uid();

    CHECK_EXPR(uid == m_uid, -1, "");

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1,
               "OnHandleLogicGetRoleListRsp, NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(playerId) return NULL, playerId:{}",
               uid);

    pPlayer->SetRoleId(0);
    uint64_t newClientId = pPlayer->GetClientId();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        NFLogError(NF_LOG_SYSTEMLOG, uid, "clientId != newClientId....uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    //再加一下状态判断 状态出错直接断开连接
    if (pSession->GetState() != EAccountState::login)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession->GetState() != EAccountState::login, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId, m_proxyId);
        return -1;
    }

    SendGetRoleList();

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFTransWorldGetRoleList::OnTransFinished(int iRunLogicRetCode)
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

        if (pSession->GetState() != EAccountState::login)
        {
            //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
            //直接把旧的连接断开
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(m_proxyId, m_clientId);
            return 0;
        }

        proto_ff::ClientLoginRsp loginrsp;
        loginrsp.set_unix_sec(NFTime::Now().UnixSec());
        loginrsp.set_unix_msec(NFTime::Now().UnixMSec());
        loginrsp.set_time_zone(NFServerTime::Instance()->CurTimeZone());
        loginrsp.set_ret(iRunLogicRetCode);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_LOGIN_RSP, loginrsp);
    }

    return 0;
}
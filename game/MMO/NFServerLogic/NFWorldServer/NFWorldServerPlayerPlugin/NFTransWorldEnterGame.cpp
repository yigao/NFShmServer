// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldEnterGame.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-7
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldEnterGame
//
// -------------------------------------------------------------------------

#include "NFTransWorldEnterGame.h"
#include "NFWorldPlayer.h"
#include "NFWorldSession.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldSessionMgr.h"
#include "ServerInternalCmd2.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "CSLogin.pb.h"
#include "ClientServerCmd.pb.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFWorldConfig.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransWorldEnterGame, EOT_NFTransWorldEnterGame_ID, NFTransBase)

NFTransWorldEnterGame::NFTransWorldEnterGame()
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

NFTransWorldEnterGame::~NFTransWorldEnterGame()
{
}

int NFTransWorldEnterGame::CreateInit()
{
    m_uid = 0;
    m_roleId = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_loadLogic = false;
    m_loadSns = false;
    return 0;
}

int NFTransWorldEnterGame::ResumeInit()
{
    return 0;
}

int NFTransWorldEnterGame::Init(uint64_t uid, uint64_t roleId, uint32_t proxyId, uint64_t clientId)
{
    m_uid = uid;
    m_roleId = roleId;
    m_proxyId = proxyId;
    m_clientId = clientId;
    return 0;
}

int NFTransWorldEnterGame::OnHandleEnterGame(const proto_ff::ClientEnterGameReq &req)
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", m_uid);

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_uid, "can't find the session from clientId:{}", m_clientId);
        return -1;
    }

    if (pPlayer->GetClientId() != m_clientId)
    {
        return -1;
    }

    if (pPlayer->IsInTransSceneing())
    {
        SetFinished(0);
        return 0;
    }

    if (pExternalConfig->WhiteListState)
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(m_uid))
        {
            return proto_ff::RET_DISALLOW_ENTER_GAME;
        }
    }
    else
    {
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

    auto pRoleInfo = pPlayer->GetRoleInfo(m_roleId);
    if (pRoleInfo == NULL)
    {
        return proto_ff::RET_FAIL;
    }

    //保证登录的账号处于 已经加载DB角色列表返回的状态  并且该该号没有角色登录中， 这种情况直接断开网络
    if (pSession->GetState() != EAccountState::loading)
    {
        uint64_t curtick = NFServerTime::Instance()->Tick();
        if (pSession->GetState() == EAccountState::createrole || pSession->GetState() == EAccountState::loadrole)
        {
            return proto_ff::RET_REPEATED_OPERATE;
        }
        else if (EAccountState::enter == pSession->GetState() && pSession->GetRoleId() != 0)
        {
            if (curtick - pSession->GetStateTick() <= 3000)
            {
                //客户端如果网络不好的话，可能会出现玩家连续点击两次进入游戏按钮，这里做一个容错
                //服务器这时候正在登录进入场景的过程中，玩家在3秒内又点击进入游戏按钮了，这时不做任何处理
                NFLogError(NF_LOG_SYSTEMLOG, m_uid,
                           "EnterGameReq... EAccountState::enter == pAccount->state && pAccount->roleCid > 0...uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                           m_uid, m_roleId, m_clientId, m_clientId, (int) pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick,
                           pSession->GetStateTick());
                return proto_ff::RET_REPEATED_OPERATE;
            }
        }

        NFLogError(NF_LOG_SYSTEMLOG, m_uid,
                   "EnterGameReq... enter game fail because EAccountState::loading != pAccount->state || pAccount->roleCid != 0, uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                   m_uid, m_roleId, m_clientId, m_clientId, (int) pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick,
                   pSession->GetStateTick());

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId());
        return -1;
    }

    NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
    if (pPlayer->GetLogicId() > 0)
    {
        pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
    }

    if (pLogicServer)
    {
        proto_ff::WorldToLogicLoginReq loginLogicReq;
        loginLogicReq.set_cid(m_roleId);
        loginLogicReq.set_uid(m_uid);
        loginLogicReq.set_proxy_id(pPlayer->GetProxyId());
        loginLogicReq.set_client_id(pPlayer->GetClientId());
        loginLogicReq.set_scene_id(pRoleInfo->m_sceneId);
        loginLogicReq.set_map_id(pRoleInfo->m_mapId);
        proto_ff::Vector3PB *protopos = loginLogicReq.mutable_pos();
        if (nullptr != protopos)
        {
            protopos->set_x(pRoleInfo->m_pos.x);
            protopos->set_y(pRoleInfo->m_pos.y);
            protopos->set_z(pRoleInfo->m_pos.z);
        }

        SendLoadRoleInfo(loginLogicReq);
    }
    else
    {
        return -1;
    }

    return 0;
}

int NFTransWorldEnterGame::SendLoadRoleInfo(const proto_ff::WorldToLogicLoginReq &req)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
    CHECK_EXPR(pPlayer, -1, "OnHandleCreateRole, GetPlayerByUid return NULL, uid:{}", m_uid);

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    CHECK_EXPR(pSession, -1, "GetSession, GetSession return NULL, clientId:{}", m_clientId);

    pSession->SetState(EAccountState::loadrole);

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_LOGIN_REQ, req, GetGlobalId());

    return 0;
}

int NFTransWorldEnterGame::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    switch (nMsgId)
    {
        case proto_ff::LOGIC_TO_WORLD_LOGIN_RSP:
        {
            return OnHandleLogicLoginRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        case proto_ff::SNS_TO_WORLD_LOGIN_RSP:
        {
            return OnHandleSnsLoginRsp(nMsgId, packet, reqTransId, rspTransId);
        }
        default:
            break;
    }

    return 0;
}

int NFTransWorldEnterGame::OnHandleLogicLoginRsp(uint32_t msgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::LogicToWorldLoginRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t uid = xData.simple_data().uid();
    uint64_t cid = xData.simple_data().cid();
    uint32_t retCode = xData.ret_code();

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", uid);

    auto pRoleInfo = pPlayer->GetRoleInfo(cid);
    CHECK_EXPR(pRoleInfo, -1, "can't find role info, uid:{} cid:{}", uid, cid);

    uint64_t newClientId = pPlayer->GetClientId();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId,
                   m_proxyId);
        return -1;
    }

    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        return -1;
    }

    if (pSession->GetState() != EAccountState::loadrole)
    {
        return -1;
    }

    if (retCode == proto_ff::RET_SUCCESS)
    {
        m_loadLogic = true;

        proto_ff::WorldToSnsLoginReq snsLoginReq;
        snsLoginReq.set_proxy_id(pPlayer->GetProxyId());
        snsLoginReq.set_logic_id(pPlayer->GetLogicId());
        snsLoginReq.set_client_id(pPlayer->GetClientId());
        snsLoginReq.mutable_simple_data()->CopyFrom(xData.simple_data());

        pPlayer->SendTransToSnsServer(proto_ff::WORLD_TO_SNS_LOGIN_REQ, snsLoginReq, GetGlobalId());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return retCode;
}

int NFTransWorldEnterGame::OnHandleSnsLoginRsp(uint32_t msgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::SnsToWorldLoginRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t uid = xData.uid();
    uint64_t cid = xData.cid();
    uint32_t retCode = xData.ret_code();

    CHECK_EXPR(uid == m_uid, -1, "uid:{} != m_uid:{}", uid, m_uid);
    CHECK_EXPR(cid == m_roleId, -1, "cid:{} != m_roleId:{}", cid, m_roleId);

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", uid);

    uint64_t newClientId = pPlayer->GetClientId();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", uid, newClientId, m_clientId,
                   m_proxyId);
        return -1;
    }

    if (newClientId > 0 && m_clientId != newClientId)
    {
        //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
        //直接把旧的连接断开
        return -1;
    }

    if (pSession->GetState() != EAccountState::loadrole)
    {
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, pSession, proto_ff::LOGOUT_REPLACE);
        return -1;
    }

    if (retCode == proto_ff::RET_SUCCESS)
    {
        m_loadSns = true;
        SetFinished(0);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return retCode;
}

int NFTransWorldEnterGame::OnTransFinished(int iRunLogicRetCode)
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
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, pSession, proto_ff::LOGOUT_REPLACE);
            return 0;
        }

        pSession->SetState(EAccountState::login);

        proto_ff::ClientEnterGameRsp xDataRsp;
        xDataRsp.set_ret(iRunLogicRetCode);
        if (m_proxyId > 0)
        {
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, m_proxyId, proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp, m_uid, m_roleId);
        }

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, pSession, proto_ff::LOGOUT_KICK_OUT);
    }
    else
    {
        if (m_loadLogic && m_loadSns)
        {
            NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(m_uid);
            CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", m_uid);

            auto pRoleInfo = pPlayer->GetRoleInfo(m_roleId);
            CHECK_EXPR(pRoleInfo, -1, "can't find role info, uid:{} cid:{}", m_uid, m_roleId);

            uint64_t newClientId = pPlayer->GetClientId();
            NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(m_clientId);
            if (pSession == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_uid, "pSession == NULL, uid:{} ,clientid:{}, reqClientId:{}, reqgateid:{} ", m_uid, newClientId,
                           m_clientId, m_proxyId);
                NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyOtherServerPlayerDisconnect(pPlayer, proto_ff::LOGOUT_KICK_OUT);
                return 0;
            }

            if (newClientId > 0 && m_clientId != newClientId)
            {
                //有新的角色登录上来准备进行挤号操作了 这种情况直接返回 客户端不会收到任何跟账号相关的角色摘要数据
                //直接把旧的连接断开
                NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pPlayer, pSession, proto_ff::LOGOUT_REPLACE);
                return 0;
            }

            pPlayer->SetRoleId(m_roleId);
            pSession->SetRoleId(m_roleId);

            pSession->SetState(EAccountState::enter);

            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_LOGIC_SERVER, pPlayer->GetLogicId());
            proto_ff::ClientEnterGameRsp xDataRsp;
            xDataRsp.set_ret(proto_ff::RET_SUCCESS);
            if (m_proxyId > 0)
            {
                FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, m_proxyId, proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp, m_uid, m_roleId);
            }

            uint64_t dstmapid = pRoleInfo->m_mapId;
            uint64_t dstsceneid = pRoleInfo->m_sceneId;
            NFPoint3<float> dstpos = pRoleInfo->m_pos;

            proto_ff::WorldToLogicLoginFinishNotify notify;
            notify.set_uid(m_uid);
            notify.set_role_id(m_roleId);
            notify.set_proxy_id(pPlayer->GetProxyId());
            notify.set_client_id(pPlayer->GetClientId());
            notify.set_map_id(dstmapid);
            notify.set_scene_id(dstsceneid);
            auto pPos = notify.mutable_pos();
            pPos->set_x(dstpos.x);
            pPos->set_y(dstpos.y);
            pPos->set_z(dstpos.z);
            pPlayer->SendMsgToLogicServer(proto_ff::WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY, notify);
            return 0;
        }
    }

    return 0;
}
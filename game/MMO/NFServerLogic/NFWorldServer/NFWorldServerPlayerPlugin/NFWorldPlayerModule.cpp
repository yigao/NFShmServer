// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include <ClientServerCmd.pb.h>
#include <Com.pb.h>
#include <ComDefine.pb.h>
#include <ClientServer.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFCore/NFServerIDUtil.h>
#include <NFComm/NFCore/NFTime.h>
#include <NFLogicCommon/NFLogicCommon.h>
#include <NFComm/NFCore/NFCommon.h>
#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <ServerInternalCmd.pb.h>
#include <ServerInternalCmd2.pb.h>
#include <ServerInternal.pb.h>
#include <ServerInternal2.pb.h>
#include <NFComm/NFCore/NFServerTime.h>
#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"
#include "NFWorldConfig.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "CSLogin.pb.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "NFLogicCommon/NFAccountDefine.h"
#include "DescStoreEx/NFMapDescStoreEx.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "NFWorldSceneMgr.h"
#include "NFTransWorldGetRoleList.h"
#include "NFTransWorldCreateRole.h"
#include "NFTransWorldEnterGame.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    NFWorldConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);

    auto pWorldConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pWorldConfig, false, "");

    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->SetStartQueueNum(pWorldConfig->StartQueueNum);
    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->SetMaxQueueNum(pWorldConfig->MaxQueueNum);

    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_LOGIN_REQ);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_CREATE_ROLE_REQ);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_ENTER_GAME_REQ);

    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NOTIFY_CENTER_DISCONNECT);
    ///////////logic msg//////////////////////////////////////////////////////////
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ);

    //////////game msg///////////////////////////////////////////////////////////
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::GAME_TO_WORLD_REGISTER_MAP_REQ);
    return true;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCWorldPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        case proto_ff::CLIENT_LOGIN_REQ:
        {
            OnHandleClientLogin(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::CLIENT_CREATE_ROLE_REQ:
        {
            OnHandleCreateRole(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::CLIENT_ENTER_GAME_REQ:
        {
            OnHandleEnterGame(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

int NFCWorldPlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (msgId != proto_ff::GAME_TO_WORLD_REGISTER_MAP_REQ)
    {
        if (!m_pObjPluginManager->IsInited())
        {
            NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
            return -1;
        }

        if (m_pObjPluginManager->IsServerStopping())
        {
            NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
            return -1;
        }
    }

    switch (msgId)
    {
        case proto_ff::NOTIFY_CENTER_DISCONNECT:
        {
            OnHandleClientDisconnect(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::GAME_TO_WORLD_REGISTER_MAP_REQ:
        {
            OnHandleGameRegisterMapReq(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::LOGIC_TO_WORLD_ENTER_SCENE_REQ:
        {
            OnHandleEnterSceneReq(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server Internal MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

/**
 * @brief 处理登录协议
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCWorldPlayerModule::OnHandleClientLogin(uint32_t msgId, NFDataPackage &packet, uint64_t clientId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    proto_ff::ClientLoginRsp xMsgRsp;

    uint64_t uid = xMsg.uid();
    uint32_t loginzid = xMsg.zid();
    uint32_t chanid = xMsg.channel_id();

    uint32_t proxyId = (uint32_t) packet.nSrcId;

    NFTransWorldGetRoleList* pTrans = dynamic_cast<NFTransWorldGetRoleList *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldSendGetRoleList_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
    pTrans->Init(uid, proxyId, clientId, loginzid, chanid);
    int retCode = pTrans->OnHandleClientLogin();
    if (retCode != 0)
    {
        pTrans->SetFinished(retCode);
    }

    return 0;
}

int NFCWorldPlayerModule::OnHandleCreateRole(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t clientId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientCreateRoleReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    CHECK_NULL(pSession);
    CHECK_EXPR(pSession && pSession->GetUid() == uid, -1, "");

    NFTransWorldCreateRole* pTrans = dynamic_cast<NFTransWorldCreateRole *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldCreateRole_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
    pTrans->Init(uid, 0, pSession->GetProxyId(), clientId, pSession->GetLoginZid());
    int iRetCode = pTrans->OnHandleCreateRole(xData);
    if (iRetCode != 0)
    {
        pTrans->SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleClientDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t unlinkId, uint64_t uid)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::NotifyCenterDisConnect xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(unlinkId);
    if (pSession)
    {
        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pSession);
    }

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    if (pPlayer && pPlayer->GetClientId() == unlinkId)
    {
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->OnHandlePlayerDisconnect(pPlayer, ROLE_DISCONN_FROM_CLIENT);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleEnterGame(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientEnterGameReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t roleId = xData.cid();
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", uid);

    uint64_t clientId = pPlayer->GetClientId();

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "can't find the session from clientId:{}", clientId);
        return 0;
    }

    proto_ff::ClientEnterGameRsp xDataRsp;
    xDataRsp.set_ret(proto_ff::RET_SUCCESS);

    //没到开服时间，不让进去,白名单无视这个条件
    if (pConfig->ServerOpenTime > NFServerTime::Instance()->UnixSec())
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xDataRsp.set_ret(proto_ff::RET_NOT_OPEN_TIME);
            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
            return 0;
        }
    }

    //超过排队人数，则直接通知不能排队，返回消息
    if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsLoginQueueFull())
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xDataRsp.set_ret(proto_ff::RET_LOGIN_QUEUE_ENOUGHT_NUM);
            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
            return 0;
        }
    }

    if (pExternalConfig->WhiteListState)
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xDataRsp.set_ret(proto_ff::RET_DISALLOW_ENTER_GAME);
            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
            return 0;
        }
    }

    auto pRoleInfo = pPlayer->GetRoleInfo(roleId);
    if (pRoleInfo == NULL)
    {
        xDataRsp.set_ret(proto_ff::RET_FAIL);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId(), proto_ff::LOGOUT_KICK_OUT);
        return 0;
    }

    //保证登录的账号处于 已经加载DB角色列表返回的状态  并且该该号没有角色登录中， 这种情况直接断开网络
    if (pSession->GetState() != EAccountState::loading)
    {
        uint64_t curtick = NFServerTime::Instance()->Tick();
        if (pSession->GetState() == EAccountState::createrole)
        {
            xDataRsp.set_ret(proto_ff::RET_REPEATED_OPERATE);
            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
            return 0;
        }
        else if (pSession->GetState() == EAccountState::loadrole)
        {
            xDataRsp.set_ret(proto_ff::RET_REPEATED_OPERATE);
            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
            return 0;
        }
        else if (EAccountState::enter == pSession->GetState() && pSession->GetRoleId() != 0)
        {
            if (curtick - pSession->GetStateTick() <= 3000)
            {
                //客户端如果网络不好的话，可能会出现玩家连续点击两次进入游戏按钮，这里做一个容错
                //服务器这时候正在登录进入场景的过程中，玩家在3秒内又点击进入游戏按钮了，这时不做任何处理
                NFLogError(NF_LOG_SYSTEMLOG, uid, "EnterGameReq... EAccountState::enter == pAccount->state && pAccount->roleCid > 0...uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                           uid, roleId, clientId, clientId, (int)pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick, pSession->GetStateTick());
                xDataRsp.set_ret(proto_ff::RET_REPEATED_OPERATE);
                pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
                return 0;
            }
        }

        //
        xDataRsp.set_ret(proto_ff::RET_FAIL);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
        //
        //
        NFLogError(NF_LOG_SYSTEMLOG, uid, "EnterGameReq... enter game fail because EAccountState::loading != pAccount->state || pAccount->roleCid != 0, uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                   uid, roleId, clientId, clientId, (int)pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick, pSession->GetStateTick());

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId());
        return 0;
    }

    NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
    if (pPlayer->GetLogicId() > 0)
    {
        pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
    }

    if (pLogicServer)
    {
        proto_ff::WorldToLogicLoginReq loginLogicReq;
        loginLogicReq.set_cid(roleId);
        loginLogicReq.set_uid(uid);
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

        NFTransWorldEnterGame* pTrans = dynamic_cast<NFTransWorldEnterGame *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldEnterGame_ID));
        CHECK_EXPR(pTrans, -1, "CreateTrans NFTransWorldEnterGame failed!");
        pTrans->Init(uid, roleId, pPlayer->GetProxyId(), pPlayer->GetClientId());
        pTrans->SendLoadRoleInfo(loginLogicReq);
    }
    else {
        //
        xDataRsp.set_ret(proto_ff::RET_FAIL);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
        //
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleGameRegisterMapReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::GameToWorldRegisterMapReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldSceneMgr::Instance(m_pObjPluginManager)->LoadGameMap(xData);

    proto_ff::WorldToGameRegisterMapRsp rspMsg;
    rspMsg.set_ret_code(proto_ff::RET_SUCCESS);
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_WORLD_SERVER, xData.game_bus(), proto_ff::WORLD_TO_GAME_RESITER_MAP_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldPlayerModule::OnHandleEnterSceneReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::LogicToWorldEnterSceneReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t cid = xData.cid();
    uint64_t mapId = xData.map_id();
    uint64_t sceneId = xData.scene_id();

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(cid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, cid:{}", cid);

    bool ret = NFWorldSceneMgr::Instance(m_pObjPluginManager)->IsStaticMapId(mapId);
    if (ret)
    {
        uint32_t gameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(mapId);
        CHECK_EXPR(gameId > 0, -1, "GetStaticMapGameId Failed, mapId:{}", mapId);

        pPlayer->SetGameId(gameId);

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_GAME_SERVER, gameId);

        proto_ff::WorldToGameEnterSceneReq reqMsg;
        reqMsg.set_cid(cid);
        reqMsg.set_map_id(mapId);
        reqMsg.set_scene_id(sceneId);
        reqMsg.set_req_trans_id(xData.req_trans_id());
        reqMsg.set_gate_id(pPlayer->GetProxyId());
        reqMsg.set_logic_id(pPlayer->GetLogicId());
        reqMsg.mutable_pos()->CopyFrom(xData.pos());
        reqMsg.mutable_data()->CopyFrom(xData.data());

        pPlayer->SendMsgToGameServer(proto_ff::WORLD_TO_GAME_ENTER_SCENE_REQ, reqMsg);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

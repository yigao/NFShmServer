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

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    NFWorldConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);

    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_LOGIN_REQ);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_CREATE_ROLE_REQ);
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_ENTER_GAME_REQ);

    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NOTIFY_CENTER_DISCONNECT);
    ///////////logic msg//////////////////////////////////////////////////////////
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::LOGIC_TO_WORLD_LOGIN_RSP);
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::SNS_TO_WORLD_LOGIN_RSP);
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
        case proto_ff::LOGIC_TO_WORLD_LOGIN_RSP:
        {
            OnHandleLogicLoginRsp(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::SNS_TO_WORLD_LOGIN_RSP:
        {
            OnHandleSnsLoginRsp(msgId, packet, param1, param2);
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

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s *pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    uint64_t uid = xMsg.uid();
    uint32_t loginzid = xMsg.zid();
    uint32_t chanid = xMsg.channel_id();

    uint32_t proxyId = (uint32_t) packet.nSrcId;

/*    if (!g_GetCenterService()->IsValidMergeZid(bornZid))
    {
        LogErrFmtPrint("[center] CenterAccountMgr::LoginGateReq...invalid mergezid...uid:%u,clientid:%u,param:%s", uid, clientId, strParam.c_str());
        goto Exit0;
    } */

    uint64_t tick = NFServerTime::Instance()->Tick();

    //没到开服时间，不让进去,白名单无视这个条件
    if (pConfig->ServerOpenTime > NFServerTime::Instance()->UnixSec())
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xMsgRsp.set_ret(proto_ff::RET_NOT_OPEN_TIME);
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_CLIENT, proto_ff::CLIENT_LOGIN_RSP,
                                                                       xMsgRsp, uid);
            return 0;
        }
    }

    //超过排队人数，则直接通知不能排队，返回消息
    if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsLoginQueueFull())
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xMsgRsp.set_ret(proto_ff::RET_LOGIN_QUEUE_ENOUGHT_NUM);
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_CLIENT, proto_ff::CLIENT_LOGIN_RSP,
                                                                       xMsgRsp, uid);
            return 0;
        }
    }

    if (pExternalConfig->WhiteListState)
    {
        if (!NFWorldConfig::Instance(m_pObjPluginManager)->IsWhiteAccount(uid))
        {
            xMsgRsp.set_ret(proto_ff::RET_DISALLOW_ENTER_GAME);
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_CLIENT, proto_ff::CLIENT_LOGIN_RSP,
                                                                       xMsgRsp, uid);
            return 0;
        }
    }

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    if (pPlayer == NULL)
    {
        pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayerByUid(uid);
        if (pPlayer == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, uid, "CreatePlayerByUid Failed, uid:{}", clientId, uid);
            xMsgRsp.set_ret(proto_ff::RET_FAIL);
            FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_CLIENT, proto_ff::CLIENT_LOGIN_RSP,
                                                                       xMsgRsp, uid);
            return 0;
        }
    }



    uint64_t oldClientId = pPlayer->GetClientId();

    NFWorldSession *pOldSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(oldClientId);

    if (pOldSession != NULL)
    {
        if (oldClientId == clientId)
        {
            //如果是同一个连接在不断的请求发该协议 那么进行过滤
            NFLogError(NF_LOG_SYSTEMLOG, uid,
                       "LoginGateReq... same player login...clientid:{}, oldclientid:{}, gateid:{}, uid:{}, roleId:{}, logicid:{}, state:{}, oldgateid:{},loginzid:{}",
                       clientId, oldClientId, proxyId, pPlayer->GetUid(), pPlayer->GetRoleId(), pPlayer->GetLogicId(), pPlayer->GetStatus(),
                       pPlayer->GetProxyId(),
                       loginzid);
            return 0;
        }

        //强制断开之前的客户端session
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pOldSession->GetProxyId(), pOldSession->GetClientId(), proto_ff::LOGOUT_REPLACE);

        //掉线重登或者被挤, 通知逻辑服退出
        //如果旧角色处于进入游戏 游戏中 切换场景中 断线中 四种状态
        //那么需要通知旧角色从逻辑服退出 并且需要将 pOldAccount 作移除操作
        if (EAccountState::enter == pOldSession->GetState() ||
            EAccountState::gaming == pOldSession->GetState() ||
            EAccountState::disconnect == pOldSession->GetState() ||
            EAccountState::logout == pOldSession->GetState() ||
            EAccountState::switch_scene == pOldSession->GetState())
        {
            NFLogError(NF_LOG_SYSTEMLOG, uid,
                       "LoginGateReq...same account login, notify logic kick player logout.. uid:{}, kick_cid:{}, logicid:{}, clientid:{}, oldclientid:{},state:{},oldgateid:{},loginzid:{}"
                       , pOldSession->GetUid(), pOldSession->GetRoleId(), pOldSession->GetLogicId(), clientId, oldClientId, (int)pOldSession->GetState(),
                       pOldSession->GetProxyId(), loginzid);

            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyLogicLeave(pOldSession->GetRoleId(), pOldSession->GetUid(), pOldSession->GetClientId(), pOldSession->GetLogicId(), proto_ff::LOGOUT_REPLACE);
            //防止逻辑服没有回来中心服做账号回收
            pOldSession->SetState(EAccountState::logout);
            pOldSession->SetStateTick(tick);
            //将在离线的角色 clientId 放到离线列表中
            AddLogoutClientId(pOldSession->GetUid(), pOldSession->GetClientId());
        }
        else if (EAccountState::login == pOldSession->GetState() ||
                 EAccountState::loading == pOldSession->GetState() ||
                 EAccountState::queue == pOldSession->GetState())
        {
            //如果旧账号处于 登录或者向DB请求角色列表或者排队状态，删除账号
            NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pOldSession);
            //删除 uid和 clientid的映射
            pPlayer->SetClientId(0);
            //如果在排队，需要从排队列表移除

            if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsInLoginQueue(uid))
            {
                NFWorldPlayerMgr::Instance(m_pObjPluginManager)->DeleteLoginQueue(uid);
            }
        }
    }

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession != NULL)
    {
        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pSession);
    }

    pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->CreateSession(clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, clientId, "CreateSession Failed, clientId:{} uid:{}", clientId, uid);
        xMsgRsp.set_ret(proto_ff::RET_FAIL);
        FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_CLIENT, proto_ff::CLIENT_LOGIN_RSP,
                                                                   xMsgRsp, uid);
        return 0;
    }

    pSession->SetProxyId(proxyId);
    pSession->SetUid(uid);
    pSession->SetState(EAccountState::login);
    pSession->SetStateTick(tick);

    pPlayer->SetTokenTimeStamp(tick);
    pPlayer->SetStatus(PLAYER_STATUS_ONLINE);
    pPlayer->SetProxyId(proxyId);
    pPlayer->SetClientId(clientId);
    pPlayer->SetZid(loginzid);
    pPlayer->SetChannelId(chanid);
    pPlayer->SetRoleId(0);

    //如果到了排队为数，直接加进排队人数列表，返回排队消息
    if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsNeedLoginQueue())
    {
        proto_ff::ClientQueuePosRsp xQueueRsp;

        //超过排队人数，则直接通知不能排队，返回消息
        if (NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsLoginQueueFull())
        {
            xQueueRsp.set_ret(proto_ff::RET_LOGIN_QUEUE_ENOUGHT_NUM);
            pPlayer->SendMsgToClient(proto_ff::CLIENT_QUEUE_POS_RSP, xQueueRsp);

            pPlayer->SetProxyId(0);
            pPlayer->SetClientId(0);
            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pSession->GetProxyId(), pSession->GetClientId(), proto_ff::LOGOUT_LOGOUT);
            NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pSession);
            return 0;
        }
        else
        {
            //如果不在排队列表中，加入到排队列表中
            if (!NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsInLoginQueue(uid))
            {
                bool ret = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->InsertLoginQueue(uid);
                CHECK_EXPR(ret, -1, "NFWorldPlayerMgr::Instance(m_pObjPluginManager)->InsertLoginQueue(uid) Failed");
            }

            xQueueRsp.set_ret(proto_ff::RET_SUCCESS);
            xQueueRsp.set_num(NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetLoginQueueNum());

            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_QUEUE_POS_RSP, xQueueRsp);
        }
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

            NFTransWorldGetRoleList* pTrans = dynamic_cast<NFTransWorldGetRoleList *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldSendGetRoleList_ID));
            CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
            pTrans->Init(uid, proxyId, clientId, loginzid);
            pTrans->SendGetRoleList();
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, uid, "can not find suit logic server to player, the all logic server may be dump");
            pPlayer->SetProxyId(0);
            pPlayer->SetClientId(0);

            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pSession->GetProxyId(), pSession->GetClientId(), proto_ff::LOGOUT_KICK_OUT);
            NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pSession);
            return 0;
        }
    }

    return 0;
}



//添加离线uid和clientid的映射
void NFCWorldPlayerModule::AddLogoutClientId(uint32_t uid, uint32_t clientid)
{

}

//移除离线uid和clientid的映射
void NFCWorldPlayerModule::DelLogoutClientId(uint32_t uid)
{

}

/**
 * @brief
 * @param pPlayer
 * @param logicId
 * @param type
 * @return
 */
/*int NFCWorldPlayerModule::NotifyLogicLeave(NFWorldPlayer *pPlayer, uint32_t logicId, proto_ff::LOGOUT_TYPE type *//*= proto_ff::LOGOUT_TYPE_NONE*//*)
{
    CHECK_NULL(pPlayer);

    return 0;
}*/



int NFCWorldPlayerModule::OnHandleCreateRole(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientCreateRoleReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "OnHandleCreateRole, GetPlayerByUid return NULL, uid:{}", uid);

    uint64_t clientId = pPlayer->GetClientId();

    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "can't find the session from clientId:{}", clientId);
        return 0;
    }

    //创建角色的账号必须处于拉取角色列表完毕状态
    if (pSession->GetState() != EAccountState::loading)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "create role faild, account state error, uid:{}, state:{}, clientId:{},account_clientid:{}, gateid:{}", uid, (int)pSession->GetState(), clientId, pSession->GetClientId(), pSession->GetProxyId());
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pSession->GetProxyId(), pSession->GetClientId(), proto_ff::LOGOUT_KICK_OUT);
        return 0;
    }

    uint32_t prof = xData.prof();
    const string &name = xData.name();
    int32_t color = xData.color();

    if (pPlayer->GetCharNum() >= MAX_ROLE_NUM)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "the player role >= MAX_ROLE_NUM, some error happened, uid:{}", MAX_ROLE_NUM, uid);
        proto_ff::ClientCreateRoleRsp clientRsp;
        clientRsp.set_result(proto_ff::RET_LOGIN_CHARACTER_NUM_LIMIT);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_CREATE_ROLE_RSP, clientRsp);
        return 0;
    }

    int32_t name_len = (int32_t) name.length();
    if (name_len < proto_ff::CHARACTER_NAME_MIN_LENGTH || name_len >= proto_ff::CHARACTER_NAME_MAX_LENGTH)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "create role, role name length error...uid:{},name_len:{}", uid, name_len);
        proto_ff::ClientCreateRoleRsp clientRsp;
        clientRsp.set_result(proto_ff::RET_LOGIN_CHARACTER_NAME_LEN_ERROR);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_CREATE_ROLE_RSP, clientRsp);
        return 0;
    }

    auto pBornProf = NFMapDescStoreEx::Instance(m_pObjPluginManager)->GetBornCfg(prof);
    if (pBornProf == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "create role, prof error...uid:{},prof:{}", uid, prof);
        proto_ff::ClientCreateRoleRsp clientRsp;
        clientRsp.set_result(proto_ff::RET_LOGIN_CHARACTER_PROF_ERROR);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_CREATE_ROLE_RSP, clientRsp);
        return 0;
    }

    const NFPoint3<float> *pPoscfg = NFMapDescStoreEx::Instance(m_pObjPluginManager)->RandBornPoint(pBornProf->m_mapid);
    if (nullptr == pPoscfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "create role, RandBornPoint error...uid:{},mapId:{}", uid, pBornProf->m_mapid);
        proto_ff::ClientCreateRoleRsp clientRsp;
        clientRsp.set_result(proto_ff::RET_LOGIN_CHARACTER_PROF_ERROR);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_CREATE_ROLE_RSP, clientRsp);
        return 0;
    }

    uint64_t cid = FindModule<NFIKernelModule>()->Get32UUID();
    proto_ff::WorldToLogicCreateRoleReq createRoleReq;
    createRoleReq.set_uid(pPlayer->GetUid());
    createRoleReq.set_cid(cid);
    createRoleReq.set_zid(pPlayer->GetZid());
    createRoleReq.set_born_zid(pPlayer->GetZid());
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
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_LOGIC_SERVER, pLogicServer->mServerInfo.bus_id());

        NFTransWorldCreateRole* pTrans = dynamic_cast<NFTransWorldCreateRole *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldCreateRole_ID));
        CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
        pTrans->Init(uid, cid, pSession->GetProxyId(), clientId, pPlayer->GetZid());
        pTrans->SendCreateRoleInfo(createRoleReq);
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "create role failed, can't find logic server");
        proto_ff::ClientCreateRoleRsp clientRsp;
        clientRsp.set_result(proto_ff::RET_LOGIN_CHARACTER_CREATE_FAILED);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_CREATE_ROLE_RSP, clientRsp);
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
        pPlayer->SetProxyId(0);
        pPlayer->SetClientId(0);
        pPlayer->SetStatus(PLAYER_STATUS_OFFLINE);
        pPlayer->SetLastDiconnectTime(NFTime::Now().UnixSec());

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyOtherServerPlayerDisconnect(pPlayer, ROLE_DISCONN_FROM_CLIENT);
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
    if (pSession->GetState() != EAccountState::loading || pSession->GetRoleId() != 0)
    {
        uint64_t curtick = NFServerTime::Instance()->Tick();
        if (EAccountState::enter == pSession->GetState() && pSession->GetRoleId() != 0)
        {
            if (curtick - pSession->GetStateTick() <= 3000)
            {
                //客户端如果网络不好的话，可能会出现玩家连续点击两次进入游戏按钮，这里做一个容错
                //服务器这时候正在登录进入场景的过程中，玩家在3秒内又点击进入游戏按钮了，这时不做任何处理
                NFLogError(NF_LOG_SYSTEMLOG, uid, "EnterGameReq... EAccountState::enter == pAccount->state && pAccount->roleCid > 0...uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                           uid, roleId, clientId, clientId, (int)pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick, pSession->GetStateTick());
                xDataRsp.set_ret(proto_ff::RET_REPEATED_OPERATE);
                pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
                return true;
            }
        }

        //
        xDataRsp.set_ret(proto_ff::RET_FAIL);
        pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);
        //
        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId());
        //
        NFLogError(NF_LOG_SYSTEMLOG, uid, "EnterGameReq... enter game fail because EAccountState::loading != pAccount->state || pAccount->roleCid != 0, uid:{}, cid:{}, oldClientId:{}, newClientId:{}, state:{} , rolecid:{}, logicId:{}, curtick:%{}, stateTick:{} ",
                   uid, roleId, clientId, clientId, (int)pSession->GetState(), pSession->GetRoleId(), pSession->GetLogicId(), curtick, pSession->GetStateTick());
        return 0;
    }

    NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
    if (pPlayer->GetLogicId() > 0)
    {
        pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
    }

    if (pLogicServer)
    {
        pPlayer->SetRoleId(roleId);
        pSession->SetRoleId(roleId);

        NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateChangeServerBusId(pPlayer, NF_ST_LOGIC_SERVER, pLogicServer->mServerInfo.bus_id());

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

        pPlayer->SendMsgToLogicServer(proto_ff::WORLD_TO_LOGIC_LOGIN_REQ, loginLogicReq);
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



int NFCWorldPlayerModule::OnHandleLogicLoginRsp(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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

    if (retCode == proto_ff::RET_SUCCESS)
    {
        pRoleInfo->m_logicId = pPlayer->GetLogicId();

        auto pTemPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->CreateCidIndexToUid(cid, uid);
        CHECK_EXPR_ASSERT(pTemPlayer == pPlayer, -1, "");

        proto_ff::WorldToSnsLoginReq snsLoginReq;
        snsLoginReq.set_proxy_id(pPlayer->GetProxyId());
        snsLoginReq.set_logic_id(pPlayer->GetLogicId());
        snsLoginReq.mutable_simple_data()->CopyFrom(xData.simple_data());


        pPlayer->SendMsgToSnsServer(proto_ff::WORLD_TO_SNS_LOGIN_REQ, snsLoginReq);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}


int NFCWorldPlayerModule::OnHandleSnsLoginRsp(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::SnsToWorldLoginRsp xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t uid = xData.uid();
    uint64_t cid = xData.cid();
    uint32_t retCode = xData.ret_code();

    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", uid);

    auto pRoleInfo = pPlayer->GetRoleInfo(cid);
    CHECK_EXPR(pRoleInfo, -1, "can't find role info, uid:{} cid:{}", uid, cid);

    pPlayer->SetRoleId(cid);

    proto_ff::ClientEnterGameRsp xDataRsp;
    xDataRsp.set_ret(retCode);
    pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_ENTER_GAME_RSP, xDataRsp);

    uint64_t dstmapid = pRoleInfo->m_mapId;
    uint64_t dstsceneid = pRoleInfo->m_sceneId;
    NFPoint3<float> dstpos = pRoleInfo->m_pos;

    proto_ff::WorldToLogicLoginFinishNotify notify;
    notify.set_uid(uid);
    notify.set_cid(cid);
    notify.set_proxy_id(pPlayer->GetProxyId());
    notify.set_map_id(dstmapid);
    notify.set_scene_id(dstsceneid);
    auto pPos = notify.mutable_pos();
    pPos->set_x(dstpos.x);
    pPos->set_y(dstpos.y);
    pPos->set_z(dstpos.z);
    pPlayer->SendMsgToLogicServer(proto_ff::WORLD_TO_LOGIC_LOGIN_FINISH_NOTIFY, notify);
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

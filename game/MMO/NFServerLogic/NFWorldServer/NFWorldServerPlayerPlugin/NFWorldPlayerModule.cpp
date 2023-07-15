﻿// -------------------------------------------------------------------------
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
#include "NFTransWorldTransScene.h"

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
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::LOGIC_TO_WORLD_LEAVE_SCENE_REQ);
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::LOGIC_TO_WORLD_GET_MAP_INFO_REQ);

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
        case proto_ff::LOGIC_TO_WORLD_LEAVE_SCENE_REQ:
        {
            OnHandleLeaveSceneReq(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::LOGIC_TO_WORLD_GET_MAP_INFO_REQ:
        {
            OnHandleWorldGetMapInfoReq(msgId, packet, param1, param2);
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleClientDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t unlinkId, uint64_t uid)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleEnterGame(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t clientId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::ClientEnterGameReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t roleId = xData.cid();
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, uid, "can't find the session from clientId:{}", clientId);
        return 0;
    }

    NFTransWorldEnterGame* pTrans = dynamic_cast<NFTransWorldEnterGame *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldEnterGame_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransWorldEnterGame failed!");
    pTrans->Init(uid, roleId, pSession->GetProxyId(), pSession->GetClientId());
    int iRetCode = pTrans->OnHandleEnterGame(xData);
    if (iRetCode != 0)
    {
        pTrans->SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleGameRegisterMapReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::GameToWorldRegisterMapReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFWorldSceneMgr::Instance(m_pObjPluginManager)->LoadGameMap(xData);

    proto_ff::WorldToGameRegisterMapRsp rspMsg;
    rspMsg.set_ret_code(proto_ff::RET_SUCCESS);
    FindModule<NFIServerMessageModule>()->SendMsgToGameServer(NF_ST_WORLD_SERVER, xData.game_bus(), proto_ff::WORLD_TO_GAME_RESITER_MAP_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleEnterSceneReq(uint32_t msgId, NFDataPackage &packet, uint64_t reqTransId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::LogicToWorldEnterSceneReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t roleId = xData.role_id();
    uint64_t mapId = xData.map_id();
    uint64_t sceneId = xData.scene_id();
    NFPoint3<float> pos(xData.pos());

    NFTransWorldTransScene* pTrans = dynamic_cast<NFTransWorldTransScene *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldTransScene_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransWorldEnterGame failed!");
    pTrans->Init(roleId, mapId, sceneId, pos, reqTransId, msgId);
    int iRetCode = pTrans->OnHandleTransScene(xData);
    if (iRetCode != 0)
    {
        pTrans->SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleLeaveSceneReq(uint32_t msgId, NFDataPackage& packet, uint64_t reqTransId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::LogicToWorldLeaveSceneReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t roleId = xData.role_id();
    uint64_t mapId = xData.map_id();
    uint64_t sceneId = xData.scene_id();
    NFPoint3<float> pos(xData.pos());

    NFTransWorldTransScene* pTrans = dynamic_cast<NFTransWorldTransScene *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldTransScene_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransWorldEnterGame failed!");
    pTrans->Init(roleId, mapId, sceneId, pos, reqTransId, msgId);
    int iRetCode = pTrans->OnHandleLeaveScene(xData);
    if (iRetCode != 0)
    {
        pTrans->SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCWorldPlayerModule::OnHandleWorldGetMapInfoReq(uint32_t msgId, NFDataPackage& packet, uint64_t reqTransId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::LogicToWorldGetMapInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    uint64_t roleId = xData.role_id();
    uint64_t srcMapId = xData.src_map_id();
    uint64_t dstMapId = xData.dst_map_id();

    uint32_t srcGameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(srcMapId);
    uint32_t dstGameId = NFWorldSceneMgr::Instance(m_pObjPluginManager)->GetStaticMapGameId(dstMapId);

    proto_ff::LogicToWorldGetMapInfoRsp rspMsg;
    NFWorldPlayer *pPlayer = NULL; //NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByCid(roleId);
    if (pPlayer)
    {
        rspMsg.set_ret_code(proto_ff::RET_SUCCESS);
        rspMsg.set_cur_game_id(pPlayer->GetGameId());
    }
    else {
        rspMsg.set_ret_code(proto_ff::RET_FAIL);
    }

    rspMsg.set_role_id(roleId);
    rspMsg.set_src_map_id(srcMapId);
    rspMsg.set_src_game_id(srcGameId);
    rspMsg.set_dst_map_id(dstMapId);
    rspMsg.set_dst_game_id(dstGameId);

    pPlayer->SendTransToLogicServer(proto_ff::WORLD_TO_LOGIC_GET_MAP_INFO_RSP, rspMsg, 0, reqTransId);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

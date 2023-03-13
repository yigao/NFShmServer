// -------------------------------------------------------------------------
//    @FileName         :    NFCSceneModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFCSceneModule
//
// -------------------------------------------------------------------------

#include "NFCSceneModule.h"
#include "Map/NFMapMgr.h"
#include "NFGameConfig.h"
#include "Scene/NFSceneMgr.h"
#include "ServerInternalCmd2.pb.h"
#include "ServerInternal2.pb.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Creature/NFBattlePlayer.h"
#include "Creature/NFCreatureMgr.h"

NFCSceneModule::NFCSceneModule(NFIPluginManager *pPluginManager) : NFIDynamicModule(pPluginManager)
{

}

NFCSceneModule::~NFCSceneModule()
{
}

bool NFCSceneModule::Awake()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_EXPR_ASSERT(pConfig, -1, "GetAppConfig Failed, server type:{}", NF_ST_GAME_SERVER);

    NFGameConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);
    NFMapMgr::Instance(m_pObjPluginManager)->LoadConfig();

    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::WORLD_TO_GAME_RESITER_MAP_RSP);
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::WORLD_TO_GAME_ENTER_SCENE_REQ);
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::WORLD_TO_GAME_LEAVE_SCENE_REQ);
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT);

    m_pObjPluginManager->RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER,
                                         NF_FORMAT("{} {}", pConfig->ServerName, "Register GameServer Map Info To WorldServer"));

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_NEED_WORLD_SERVER, __FUNCTION__);
    return true;
}

int NFCSceneModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (serverType == NF_ST_GAME_SERVER && nEventID == proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nSrcID == APP_INIT_NEED_WORLD_SERVER)
        {
            RegisterMapToWorldServer();
        }
    }

    return 0;
}

bool NFCSceneModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCSceneModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCSceneModule::RegisterMapToWorldServer()
{
    std::set<uint64_t> vecMap;
    auto pConfig = NFGameConfig::Instance(m_pObjPluginManager)->GetConfig();
    vecMap.insert(pConfig->map.begin(), pConfig->map.end());
    NFSceneMgr::Instance(m_pObjPluginManager)->InitScene(vecMap);
    return 0;
}

int NFCSceneModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (msgId != proto_ff::WORLD_TO_GAME_RESITER_MAP_RSP)
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

    switch(msgId)
    {
        case proto_ff::WORLD_TO_GAME_RESITER_MAP_RSP:
        {
            OnHandleRegisterMapRsp(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_GAME_ENTER_SCENE_REQ:
        {
            OnHandleEnterSceneReq(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_GAME_LEAVE_SCENE_REQ:
        {
            OnHandleLeaveSceneReq(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT:
        {
            OnHandlePlayerDisconnect(msgId, packet, param1, param2);
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

int NFCSceneModule::OnHandleRegisterMapRsp(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToGameRegisterMapRsp xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    m_pObjPluginManager->FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    return 0;
}

int NFCSceneModule::OnHandleEnterSceneReq(uint32_t msgId, NFDataPackage &packet, uint64_t reqTransId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToGameEnterSceneReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t mapId = xMsg.map_id();
    uint64_t sceneId = xMsg.scene_id();
    uint64_t roleId = xMsg.role_id();
    NFPoint3<float> pos(xMsg.pos());

    proto_ff::GameToWorldEnterSceneRsp rspMsg;
    rspMsg.set_ret_code(proto_ff::RET_SUCCESS);
    rspMsg.set_role_id(roleId);
    rspMsg.set_map_id(mapId);
    rspMsg.set_scene_id(sceneId);

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        pPlayer = dynamic_cast<NFBattlePlayer*>(NFCreatureMgr::Instance(m_pObjPluginManager)->CreateCreature(CREATURE_PLAYER, roleId));
        if (pPlayer == NULL)
        {
            return -1;
        }
        pPlayer->Init(xMsg.data());
    }

    pPlayer->Init(xMsg.gate_id(), xMsg.client_id(), xMsg.logic_id(), xMsg.data());
    pPlayer->SetPlayerStatus(PLAYER_STATUS_ONLINE);

    NFLogDebug(NF_LOG_SYSTEMLOG, roleId, "recv enter scene from world server, mapId:{} sceneId:{}", mapId, sceneId);
    int ret = NFSceneMgr::Instance(m_pObjPluginManager)->EnterScene(roleId, mapId, sceneId, pos);
    if (ret != proto_ff::RET_SUCCESS)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "role:{} Enter Scene Failed, mapId:{} sceneId:{}", roleId, mapId, sceneId);
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, roleId, "send enter scene to world server, mapId:{} sceneId:{}", mapId, sceneId);
    rspMsg.mutable_pos()->CopyFrom(xMsg.pos());
    rspMsg.set_ret_code(ret);
    pPlayer->SendTransToWorldServer(proto_ff::GAME_TO_WORLD_ENTER_SCENE_RSP, rspMsg, 0, reqTransId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    return 0;
}

int NFCSceneModule::OnHandleLeaveSceneReq(uint32_t msgId, NFDataPackage & packet, uint64_t reqTransId, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToGameLeaveSceneReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t mapId = xMsg.map_id();
    uint64_t sceneId = xMsg.scene_id();
    uint64_t roleId = xMsg.role_id();

    proto_ff::GameToWorldLeaveSceneRsp rspMsg;
    rspMsg.set_ret_code(proto_ff::RET_SUCCESS);
    rspMsg.set_role_id(roleId);
    rspMsg.set_map_id(mapId);
    rspMsg.set_scene_id(sceneId);

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        rspMsg.set_ret_code(proto_ff::RET_FAIL);
        pPlayer->SendTransToWorldServer(proto_ff::GAME_TO_WORLD_LEAVE_SCENE_RSP, rspMsg, 0, reqTransId);
        return 0;
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, roleId, "recv enter scene from world server, mapId:{} sceneId:{}", mapId, sceneId);
    int ret = NFSceneMgr::Instance(m_pObjPluginManager)->LeaveScene(roleId, mapId, sceneId);
    if (ret != proto_ff::RET_SUCCESS)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "role:{} Leave Scene Failed, mapId:{} sceneId:{}", roleId, mapId, sceneId);
    }
    else {
        pPlayer->SetPlayerStatus(PLAYER_STATUS_DEAD);
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, roleId, "send leave scene to world server, mapId:{} sceneId:{}", mapId, sceneId);
    rspMsg.set_ret_code(ret);
    rspMsg.set_logic_id(pPlayer->GetLogicId());
    pPlayer->SendTransToWorldServer(proto_ff::GAME_TO_WORLD_LEAVE_SCENE_RSP, rspMsg, 0, reqTransId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    return 0;
}

int NFCSceneModule::OnHandlePlayerDisconnect(uint32_t msgId, NFDataPackage & packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToOtherServerDisconnectNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(xMsg.roleid());
    if (pPlayer)
    {
        pPlayer->OnDisconnect();
    }
    else {
        NFLogWarning(NF_LOG_SYSTEMLOG, xMsg.roleid(), "GetBattlePlayer Fail, roleId:{}", xMsg.roleid());
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

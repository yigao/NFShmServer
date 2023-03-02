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

int NFCSceneModule::OnHandleEnterSceneReq(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToGameEnterSceneReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    uint64_t mapId = xMsg.map_id();
    uint64_t sceneId = xMsg.scene_id();
    uint64_t roleId = xMsg.cid();
    NFPoint3<float> pos;
    pos.x = xMsg.pos().x();
    pos.y = xMsg.pos().y();
    pos.z = xMsg.pos().z();

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        pPlayer = dynamic_cast<NFBattlePlayer*>(NFCreatureMgr::Instance(m_pObjPluginManager)->CreateCreature(CREATURE_PLAYER, roleId));
        if (pPlayer == NULL)
        {
            return -1;
        }

        pPlayer->Init(xMsg.gate_id(), xMsg.logic_id(), xMsg.data());
    }

    NFSceneMgr::Instance(m_pObjPluginManager)->EnterScene(roleId, mapId, sceneId, pos);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    return 0;
}

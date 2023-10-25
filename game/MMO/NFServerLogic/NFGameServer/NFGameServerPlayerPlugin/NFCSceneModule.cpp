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
#include "Map/NFMap.h"
#include "NFGameConfig.h"
#include "Scene/NFSceneMgr.h"
#include "ServerInternalCmd2.pb.h"
#include "ServerInternal2.pb.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Creature/NFBattlePlayer.h"
#include "Creature/NFCreatureMgr.h"
#include "NFServerComm/NFServerCommon/NFIGameServerModule.h"

NFCSceneModule::NFCSceneModule(NFIPluginManager *pPluginManager) : NFMMODynamicModule(pPluginManager)
{

}

NFCSceneModule::~NFCSceneModule()
{
}

bool NFCSceneModule::Awake()
{
    FindModule<NFIGameServerModule>()->SetCheckCenterServer(true);
    
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_EXPR_ASSERT(pConfig, -1, "GetAppConfig Failed, server type:{}", NF_ST_GAME_SERVER);
    
    NFGameConfig::Instance(m_pObjPluginManager)->LoadConfig(m_luaModule);
    NFMapMgr::Instance(m_pObjPluginManager)->LoadConfig();
    
    RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_DESC_STORE_LOAD, "GameServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);
    
    RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_CENTER_SERVER,
                    NF_FORMAT("{} {}", pConfig->ServerName, "Register GameServer Map Info To CenterServer"), APP_INIT_TASK_GROUP_SERVER_REGISTER);
    
    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_CONNECT,
              __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE,
              __FUNCTION__);
    
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::STS_ENTER_SCENE_REQ>(NF_ST_GAME_SERVER, this,
                                                                                 &NFCSceneModule::OnRpcServiceEnterScene, true);
    return true;
}

int NFCSceneModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE &&
        (nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE || nSrcID == APP_INIT_TASK_GROUP_SERVER_CONNECT))
    {
        if (m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE) && m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT))
        {
            std::unordered_set<uint64_t> mapIds(NFGameConfig::Instance(m_pObjPluginManager)->GetConfig()->map.begin(), NFGameConfig::Instance(m_pObjPluginManager)->GetConfig()->map.end());
            NFSceneMgr::Instance(m_pObjPluginManager)->InitScene(mapIds);
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

int NFCSceneModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server Internal MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }
    
    return 0;
}

int NFCSceneModule::OnRpcServiceEnterScene(proto_ff::EnterSceneReq &request, proto_ff::EnterSceneRsp &respone)
{
    uint64_t mapId = request.dst_map_id();
    uint64_t sceneId = request.dst_scene_id();
    uint64_t cid = request.cid();
    NFPoint3<float> pos;
    NFLogicCommon::NFPoint3FromProto(pos, request.dst_pos());
    
    NFBattlePlayer *pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(cid);
    if (pPlayer == NULL)
    {
        pPlayer = dynamic_cast<NFBattlePlayer *>(NFCreatureMgr::Instance(m_pObjPluginManager)->CreateCreature(CREATURE_PLAYER, cid));
        if (pPlayer == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, cid, "CreateCreature CREATURE_PLAYER Failed");
            respone.set_ret_code(proto_ff::RET_FAIL);
            return 0;
        }
        pPlayer->Init(request.data());
    }
    
    pPlayer->Init(request.proxy_id(), request.logic_id(), request.world_id(), request.sns_id(), request.data());
    pPlayer->SetPlayerStatus(proto_ff::PLAYER_STATUS_ONLINE);
    
    int ret = NFSceneMgr::Instance(m_pObjPluginManager)->EnterScene(cid, mapId, sceneId, pos);
    if (ret != proto_ff::RET_SUCCESS)
    {
        respone.set_ret_code(ret);
        NFLogError(NF_LOG_SYSTEMLOG, cid, "role:{} Enter Scene Failed, mapId:{} sceneId:{}", cid, mapId, sceneId);
        return 0;
    }
    
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);
    
    respone.set_ret_code(proto_ff::RET_SUCCESS);
    respone.set_game_id(pConfig->GetBusId());
    respone.set_map_id(mapId);
    respone.set_scene_id(sceneId);
    NFLogicCommon::NFPoint3ToProto(pPlayer->GetPos(), *respone.mutable_pos());
    NFLogError(NF_LOG_SYSTEMLOG, cid, "role:{} Enter Scene Success, mapId:{} sceneId:{}", cid, mapId, sceneId);
    return 0;
}


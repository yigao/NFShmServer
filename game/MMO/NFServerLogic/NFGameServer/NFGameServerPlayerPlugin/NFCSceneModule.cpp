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

    RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_DESC_STORE_LOAD, "GameServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);


    RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_CENTER_SERVER,
                                         NF_FORMAT("{} {}", pConfig->ServerName, "Register GameServer Map Info To CenterServer"), APP_INIT_TASK_GROUP_SERVER_REGISTER);

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_CONNECT,
              __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE,
              __FUNCTION__);
    return true;
}

int NFCSceneModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE &&
            (nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE || nSrcID == APP_INIT_TASK_GROUP_SERVER_CONNECT))
    {
        if (m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE) && m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT))
        {
            NFMapMgr::Instance(m_pObjPluginManager)->LoadConfig();
            RegisterMapInfo();
        }
    }
    return 0;
}

int NFCSceneModule::RegisterMapInfo()
{
    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pServerConfig);

    std::vector<NF_SHARE_PTR<NFServerData>> pAllCenterServer = FindModule<NFIMessageModule>()->GetAllServer(NF_ST_GAME_SERVER, NF_ST_CENTER_SERVER, pServerConfig->IsCrossServer());
    CHECK_EXPR(pAllCenterServer.size() == 1, -1, "game server get the center server num is not 1........");

    uint32_t centerBusId = pAllCenterServer[0]->mServerInfo.bus_id();

    proto_ff::RegisterMapInfoReq  req;
    req.set_bus_id(pServerConfig->GetBusId());
    for(auto iter = NFMap::Begin(m_pObjPluginManager); iter != NFMap::End(m_pObjPluginManager); iter++)
    {
        req.add_map_id(iter->GetMapId());
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Register Map:{} to Center Server", iter->GetMapId());
    }

    int rpcRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::STS_MAP_REG_RPC>(NF_ST_GAME_SERVER, NF_ST_CENTER_SERVER, centerBusId, req, [this](int rpcRetCode, proto_ff::ReigsterMapInfoRsp &respone){
        if (rpcRetCode != proto_ff::RET_SUCCESS)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_MAP_REG_RPC> failed, rpcError:{}", GetErrorStr(rpcRetCode));
            return;
        }

        if (respone.ret_code() != proto_ff::RET_SUCCESS)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_MAP_REG_RPC> failed:{}, register failed", GetErrorStr(respone.ret_code()));
            return;
        }

        FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_CENTER_SERVER, APP_INIT_TASK_GROUP_SERVER_REGISTER);
    });

    if (rpcRet == INVALID_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_MAP_REG_RPC> error");
        return -1;
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

    switch(msgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server Internal MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}


// -------------------------------------------------------------------------
//    @FileName         :    NFSceneMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFSceneMgr
//
// -------------------------------------------------------------------------

#include "NFSceneMgr.h"
#include "Map/NFMapMgr.h"
#include "Map/NFMap.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFScene.h"
#include "ServerInternal2.pb.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "ServerInternalCmd2.pb.h"
#include "Creature/NFCreatureMgr.h"
#include "Creature/NFBattlePlayer.h"

NFSceneMgr::NFSceneMgr()
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

NFSceneMgr::~NFSceneMgr()
{
}

int NFSceneMgr::CreateInit()
{
    //例如第一层m_mapLyaer[1]
    //  00000
    //	01110
    //	01010
    //	01110
    //	00000
    //******************计算每层所需定位的格子******************
    m_nineGridLayer.resize(m_nineGridLayer.max_size());
    m_nineGridLayer[0].push_back({0, 0 });
    for (int a = 1; a <= MAX_LAYER; a++)
    {
        {
            int y = -a;
            for (int x = -a; x <= a; x++)
            {
                NF_ASSERT_MSG(m_nineGridLayer[a].size() < m_nineGridLayer[a].max_size(), "size:{} max_size:{}", m_nineGridLayer[a].size(), m_nineGridLayer[a].max_size());
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int y = a;
            for (int x = -a; x <= a; x++)
            {
                NF_ASSERT_MSG(m_nineGridLayer[a].size() < m_nineGridLayer[a].max_size(), "size:{} max_size:{}", m_nineGridLayer[a].size(), m_nineGridLayer[a].max_size());
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int x = -a;
            for (int y = -a + 1; y <= a - 1; y++)
            {
                NF_ASSERT_MSG(m_nineGridLayer[a].size() < m_nineGridLayer[a].max_size(), "size:{} max_size:{}", m_nineGridLayer[a].size(), m_nineGridLayer[a].max_size());
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int x = a;
            for (int y = -a + 1; y <= a - 1; y++)
            {
                NF_ASSERT_MSG(m_nineGridLayer[a].size() < m_nineGridLayer[a].max_size(), "size:{} max_size:{}", m_nineGridLayer[a].size(), m_nineGridLayer[a].max_size());
                m_nineGridLayer[a].push_back({x, y });
            }
        }
    }
    return 0;
}

int NFSceneMgr::ResumeInit()
{
    return 0;
}

int NFSceneMgr::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    EVENT_PROCESS_WITH_PRINTF(serverType, nEventID, bySrcType, nSrcID, pMessage, proto_ff::NFEventNoneData, pEventMsg);
    return 0;
}

NFScene *NFSceneMgr::CreateScene(uint64_t mapId, uint64_t sceneId)
{
    NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
    CHECK_EXPR(pMap, NULL, "GetMap Failed, mapId:{}", mapId);

    NFScene* pScene = GetScene(sceneId);
    CHECK_EXPR(pScene == NULL, NULL, "GetScene Exist, mapId:{} sceneId:{}", mapId, sceneId);

    pScene = dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(EOT_GAME_SCENE_ID, sceneId));
    CHECK_EXPR(pScene, NULL, "Create Scene Obj Failed, mapId:{} sceneId:{}", mapId, sceneId);

    int retCode = pScene->Init(mapId, sceneId);
    if (retCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "pScene Init Failed, mapId:{} sceneId:{}", mapId, sceneId);
        DeleteScene(pScene);
        return NULL;
    }

    return pScene;
}

NFScene* NFSceneMgr::GetScene(uint64_t sceneId)
{
    return dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(EOT_GAME_SCENE_ID, sceneId));
}

int NFSceneMgr::DeleteScene(NFScene *pScene)
{
    CHECK_NULL(pScene);
    pScene->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pScene);
    return 0;
}

int NFSceneMgr::InitScene(const std::unordered_set<uint64_t> &mapIds)
{
    std::vector<uint64_t> vec;
    for(auto iter = mapIds.begin(); iter != mapIds.end(); iter++)
    {
        uint64_t mapId = *iter;
        NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        CHECK_EXPR_CONTINUE(pMap, "GetMap Failed, mapId:{}", mapId);

        //启动服务器时创建 非动态场景
        if (!pMap->IsDynamic() && !pMap->IsMainCity())
        {
            NFScene* pScene = GetScene(pMap->GetMapId());
            if (pScene == NULL)
            {
                pScene = CreateScene(pMap->GetMapId(), pMap->GetMapId());
            }
            CHECK_EXPR_CONTINUE(pScene, "CreateScene Failed, MapId:{}", mapId);
            vec.push_back(mapId);
        }
    }

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);
    
    proto_ff::RegisterMapInfoReq  req;
    req.set_bus_id(pConfig->GetBusId());
    for(auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        req.add_map_id(*iter);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Register Map:{} to Center Server", *iter);
    }
    
    int rpcRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::STS_MAP_REG_RPC>(NF_ST_GAME_SERVER, NF_ST_CENTER_SERVER, 0, req, [this](int rpcRetCode, proto_ff::ReigsterMapInfoRsp &respone){
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
        
        m_pObjPluginManager->FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_CENTER_SERVER, APP_INIT_TASK_GROUP_SERVER_REGISTER);
    });
    
    if (rpcRet == INVALID_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_MAP_REG_RPC> error");
        return -1;
    }
    return 0;
}

bool NFSceneMgr::IsClosed(uint64_t sceneId)
{
    auto iter = m_delCacheMap.find(sceneId);
    return (iter != m_delCacheMap.end()) ? true : false;
}

const NFSceneMgr::OneLayer* NFSceneMgr::GetLayerPoint(uint32_t nlayer)
{
    if (nlayer > MAX_LAYER)
        nlayer = MAX_LAYER;
    return &m_nineGridLayer[nlayer];
}

int NFSceneMgr::EnterScene(uint64_t roleId, uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos, const proto_ff::SceneTransParam& transParam)
{
    NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
    if (pMap == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "Can't find mapId data, mapId:{}, sceneId:{}", mapId, sceneId);
        return proto_ff::RET_FAIL;
    }

    NFScene* pScene = GetScene(sceneId);
    if (pScene == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "Can't find scene data, mapId:{}, sceneId:{}", mapId, sceneId);
        return proto_ff::RET_FAIL;
    }

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "Can't find player data, mapId:{}, sceneId:{}", mapId, sceneId);
        return proto_ff::RET_FAIL;
    }
    
    //设置游戏状态,需要再切换场景前面，切换场景中可能会涉及到跨逻辑节点需要修改状态的
    pPlayer->SetAccountState(ACCOUNT_GAME_STATE_GAMING);
    return pPlayer->TransScene(sceneId, pos, mapId, transParam);
}

int NFSceneMgr::LeaveScene(uint64_t roleId, uint64_t mapId, uint64_t sceneId)
{
    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "Can't find player data, mapId:{}, sceneId:{}", mapId, sceneId);
        return proto_ff::RET_FAIL;
    }

    if (pPlayer->GetMapId() > 0)
    {
        if (pPlayer->GetMapId() != mapId || pPlayer->GetSceneId() != sceneId)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "LeaveScene mapId:{} sceneId:{}, but player mapId:{} sceneId:{}", mapId, sceneId, pPlayer->GetMapId(), pPlayer->GetSceneId());
        }
    }

    return pPlayer->LeaveScene();
}
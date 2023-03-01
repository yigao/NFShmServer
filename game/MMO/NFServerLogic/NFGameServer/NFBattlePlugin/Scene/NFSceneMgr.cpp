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
#include "ServerInternalCmd2.pb.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Creature/NFCreatureMgr.h"
#include "Creature/NFBattlePlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSceneMgr, EOT_GAME_SCENE_MGR_ID, NFShmObj)

NFSceneMgr::NFSceneMgr() : NFShmObj()
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
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int y = a;
            for (int x = -a; x <= a; x++)
            {
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int x = -a;
            for (int y = -a + 1; y <= a - 1; y++)
            {
                m_nineGridLayer[a].push_back({x, y });
            }
        }

        {
            int x = a;
            for (int y = -a + 1; y <= a - 1; y++)
            {
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

    pScene = dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(sceneId, EOT_GAME_SCENE_ID));
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
    return dynamic_cast<NFScene *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(sceneId, EOT_GAME_SCENE_ID));
}

int NFSceneMgr::DeleteScene(NFScene *pScene)
{
    CHECK_NULL(pScene);
    pScene->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pScene);
    return 0;
}

int NFSceneMgr::InitScene(const std::set<uint64_t> &mapIds)
{
    std::vector<uint64_t> vec;
    for(auto iter = mapIds.begin(); iter != mapIds.end(); iter++)
    {
        uint64_t mapId = *iter;
        NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
        CHECK_EXPR_CONTINUE(pMap, "GetMap Failed, mapId:{}", mapId);

        //启动服务器时创建 非动态场景
        if (pMap->IsDynamic() == false)
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

    proto_ff::GameToWorldRegisterMapReq xMsg;
    xMsg.set_game_bus(pConfig->BusId);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        xMsg.add_map_id(vec[i]);
    }
    FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::GAME_TO_WORLD_REGISTER_MAP_REQ, xMsg);
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

int NFSceneMgr::EnterScene(const proto_ff::WorldToGameEnterSceneReq& xMsg)
{
    uint64_t mapId = xMsg.map_id();
    uint64_t sceneId = xMsg.scene_id();
    uint64_t roleId = xMsg.cid();
    NFPoint3<float> pos;
    pos.x = xMsg.pos().x();
    pos.y = xMsg.pos().y();
    pos.z = xMsg.pos().z();

    NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
    if (pMap == NULL)
    {
        return -1;
    }

    NFScene* pScene = GetScene(sceneId);
    if (pScene == NULL)
    {
        return -1;
    }

    NFBattlePlayer* pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer == NULL)
    {
        pPlayer = dynamic_cast<NFBattlePlayer*>(NFCreatureMgr::Instance(m_pObjPluginManager)->CreateCreature(CREATURE_PLAYER, roleId));
        if (pPlayer == NULL)
        {
            return -1;
        }
    }

    pPlayer->Init(xMsg.gate_id(), xMsg.logic_id(), xMsg.data());

    STransParam param;
    pPlayer->EnterScene(sceneId, pos, param);
    return 0;
}
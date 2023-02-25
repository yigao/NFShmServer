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

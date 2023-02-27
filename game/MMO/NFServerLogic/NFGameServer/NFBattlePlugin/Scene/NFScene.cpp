// -------------------------------------------------------------------------
//    @FileName         :    NFScene.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFScene
//
// -------------------------------------------------------------------------

#include "NFScene.h"
#include "Map/NFMapMgr.h"
#include "Map/NFMap.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Creature/NFCreature.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "NFSceneMgr.h"
#include "Event.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFScene, EOT_GAME_SCENE_ID, NFShmObj)

NFScene::NFScene() : NFShmObj()
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

NFScene::~NFScene()
{

}

int NFScene::CreateInit()
{
    m_mapId = 0;
    m_sceneId = 0;
    m_gridMaxWidth = 0;
    m_gridMaxHeight = 0;

    //Subscribe(NF_EVENT_CREATE_SCENE_EVENT, 0, 0, NF_MACRO_FUNCTION);
    //SetTimer(100, INVALID_ID, 0, 0, 0, 100);
    return 0;
}

int NFScene::ResumeInit()
{
    return 0;
}

int NFScene::OnTimer(int timeId, int callcount)
{
    return 0;
}

int NFScene::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (nEventID == NF_EVENT_CREATE_SCENE_EVENT)
    {

    }
    return 0;
}

int NFScene::Init(uint64_t mapId, uint64_t sceneId)
{
    NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(mapId);
    CHECK_EXPR(pMap, -1, "GetMap Failed, mapId:{}", mapId);
    CHECK_EXPR(pMap->GetMapCfg(), -1, "GetMap Failed, map");

    m_gridMaxWidth = (uint32_t) (pMap->GetWidth() / GRID_LENGTH) + 1;
    m_gridMaxHeight = (uint32_t) (pMap->GetHeight() / GRID_LENGTH) + 1;

    CHECK_EXPR_ASSERT(m_gridMaxWidth <= NF_SCENE_MAX_GRID_NUM, -1,
                      "m_gridMaxWidth Failed, Not Enough Space, m_gridMaxWidth:{} > NF_SCENE_MAX_GRID_NUM:{}", m_gridMaxWidth, NF_SCENE_MAX_GRID_NUM);

    CHECK_EXPR_ASSERT(m_gridMaxHeight <= NF_SCENE_MAX_GRID_NUM, -1,
                      "m_gridMaxHeight Failed, Not Enough Space, m_gridMaxHeight:{} > NF_SCENE_MAX_GRID_NUM:{}", m_gridMaxHeight,
                      NF_SCENE_MAX_GRID_NUM);

    m_mapId = mapId;
    m_sceneId = sceneId;
    m_gridList.resize(m_gridMaxWidth);
    for (uint32_t w = 0; w < (uint32_t) m_gridList.size(); w++)
    {
        m_gridList[w].resize(m_gridMaxHeight);
        for (uint32_t h = 0; h < (uint32_t) m_gridList[w].size(); h++)
        {
            m_gridList[w][h].SetGridPos({w, h});
        }
    }
    return 0;
}

int NFScene::UnInit()
{
    for (int w = 0; w < (int) m_gridList.size(); w++)
    {
        for (int h = 0; h < (int) m_gridList[w].size(); h++)
        {
            m_gridList[w][h].UnInit(m_pObjPluginManager);
        }
    }
    return 0;
}

NFGrid *NFScene::GetGrid(uint32_t w, uint32_t h)
{
    if (w < (uint32_t) m_gridList.size())
    {
        if (h < (uint32_t) m_gridList[h].size())
        {
            return &m_gridList[w][h];
        }
    }

    return NULL;
}

NFGrid *NFScene::EnterScene(NFCreature *pCreature, const NFPoint3<float> &pos, STransParam &transParam)
{
    CHECK_EXPR(pCreature, NULL, "pCreature == NULL");
    uint32_t gridX = uint32_t(pos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(pos.z / GRID_LENGTH);

    CHECK_EXPR(gridX >= m_gridMaxWidth, NULL, "gridX:{} m_gridMaxWidth:{}", gridX, m_gridMaxWidth);
    CHECK_EXPR(gridZ >= m_gridMaxHeight, NULL, "gridX:{} m_gridMaxHeight:{}", gridX, m_gridMaxHeight);

    if (NFSceneMgr::Instance(m_pObjPluginManager)->IsClosed(m_sceneId))
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, pCreature->Cid(),
                   "Scene::EnterScene, scene is destorying cannt enter, Cid:{}, dstpos({},{},{},), sceneId:{}, mapId:{},transType:{}",
                   pCreature->Cid(), pos.x, pos.y, pos.z, m_sceneId, m_mapId, transParam.transType);
        return NULL;
    }

    m_gridList[gridX][gridZ].AddCreature(m_pObjPluginManager, pCreature);
    AddCreature(pCreature);

    return &m_gridList[gridX][gridZ];
}

int NFScene::AddMonster(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    return m_creatureList.AddNode(m_pObjPluginManager, NF_CREATURE_NODE_LIST_SCENE_INDEX, pCreature);
}

int NFScene::RemoveMonster(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    return m_creatureList.RemoveNode(m_pObjPluginManager, NF_CREATURE_NODE_LIST_SCENE_INDEX, pCreature);
}

int NFScene::AddPlayer(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    return m_playerList.AddNode(m_pObjPluginManager, NF_CREATURE_NODE_LIST_SCENE_INDEX, pCreature);
}

int NFScene::RemovePlayer(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    return m_playerList.RemoveNode(m_pObjPluginManager, NF_CREATURE_NODE_LIST_SCENE_INDEX, pCreature);
}

int NFScene::AddCreature(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    if (pCreature->Kind() != CREATURE_PLAYER)
    {
        return AddMonster(pCreature);
    }
    else
    {
        return AddPlayer(pCreature);
    }
}

int NFScene::RemoveCreature(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    if (pCreature->Kind() != CREATURE_PLAYER)
    {
        return RemoveMonster(pCreature);
    }
    else
    {
        return RemovePlayer(pCreature);
    }
}

NFGrid *NFScene::MoveInScene(NFCreature *pCreature, const NFPoint3<float> &pos, bool &isSameGrid)
{
    CHECK_EXPR(pCreature, NULL, "pCreature == NULL");

    uint32_t gridX = uint32_t(pos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(pos.z / GRID_LENGTH);
    CHECK_EXPR(gridX >= m_gridMaxWidth, NULL, "gridX:{} m_gridMaxWidth:{}", gridX, m_gridMaxWidth);
    CHECK_EXPR(gridZ >= m_gridMaxHeight, NULL, "gridX:{} m_gridMaxHeight:{}", gridX, m_gridMaxHeight);
    NFGrid *pGrid = pCreature->GetGrid();
    CHECK_EXPR(pGrid, NULL, "pCreature->GetGrid() == NULL");

    if (pGrid->IsSame({gridX, gridZ}))
    {
        isSameGrid = true;
        return pGrid;
    }

    NFGrid *pNewGrid = nullptr;
    pNewGrid = &m_gridList[gridX][gridZ];
    pGrid->RemoveCreature(m_pObjPluginManager, pCreature);
    pNewGrid->AddCreature(m_pObjPluginManager, pCreature);

    isSameGrid = false;
    return pNewGrid;
}

bool NFScene::LeaveScene(NFCreature *pCreature)
{
    CHECK_EXPR(pCreature, false, "pCreature == NULL");
    NFGrid *pGrid = pCreature->GetGrid();
    CHECK_EXPR(pGrid, false, "pCreature->GetGrid() == NULL");

    //先通知九宫格玩家离开
    pCreature->NoticeNineGridLeave();
    pGrid->RemoveCreature(m_pObjPluginManager, pCreature);

    RemoveCreature(pCreature);

    proto_ff::LeaveSceneEvent leaveEvent;
    leaveEvent.set_cid(pCreature->Cid());
    leaveEvent.set_sceneid(m_sceneId);
    leaveEvent.set_mapid(m_mapId);

    FireExecute(NF_ST_GAME_SERVER, EVENT_LEAVE_SCENE, pCreature->Kind(), m_sceneId, leaveEvent);

    proto_ff::ChgSceneEvent chgEvent;
    chgEvent.set_cid(pCreature->Cid());
    chgEvent.set_enterflag(false);
    FireExecute(NF_ST_GAME_SERVER, EVENT_CHANGE_SCENE, 0, pCreature->Cid(), chgEvent);

    return true;
}

void NFScene::GetNineGrid(const NFPoint3<float>& srcPos, std::vector<NFGrid*>& vecGrid)
{
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    NFPoint2<uint32_t> gridPos(gridX, gridZ);
    for (uint32_t i = 0; i <= 2; i++)
    {
        auto pVecPoint2 = NFSceneMgr::Instance(m_pObjPluginManager)->GetLayerPoint(i);
        if (!pVecPoint2)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_sceneId, "g_GetSceneMgr()->GetLayerPoint(i) is null, layer:%d", i);
            return;
        }

        for (uint32_t j = 0; j < pVecPoint2->size(); j++)
        {
            gridPos.x = uint32_t(gridX + pVecPoint2->at(j).x);
            gridPos.y = uint32_t(gridZ + pVecPoint2->at(j).y);

            if (gridPos.x >= m_gridMaxWidth || gridPos.y >= m_gridMaxHeight)
            {
                continue;
            }

            vecGrid.push_back(&m_gridList[gridPos.x][gridPos.y]);
        }
    }
}
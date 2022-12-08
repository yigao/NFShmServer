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

int NFScene::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
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
    m_gridList.SetSize(m_gridMaxWidth);
    for (uint32_t w = 0; w < (uint32_t) m_gridList.GetSize(); w++)
    {
        m_gridList[w].SetSize(m_gridMaxHeight);
        for (uint32_t h = 0; h < (uint32_t) m_gridList[w].GetSize(); h++)
        {
            m_gridList[w][h].SetGridPos({w, h});
        }
    }
    return 0;
}

int NFScene::UnInit()
{
    for(int w = 0; w < (int)m_gridList.GetSize(); w++)
    {
        for(int h = 0; h < (int)m_gridList[w].GetSize(); h++)
        {
            m_gridList[w][h].UnInit(m_pObjPluginManager);
        }
    }
    return 0;
}

int NFScene::EnterScene(NFCreature *pCreature, const NFPoint3<float> &pos, STransParam &transParam)
{
    int retCode = 0;
    CHECK_NULL(pCreature);
    uint32_t gridX = uint32_t(pos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(pos.z / GRID_LENGTH);

    CHECK_EXPR(gridX >= m_gridMaxWidth, -1, "gridX:{} m_gridMaxWidth:{}", gridX, m_gridMaxWidth);
    CHECK_EXPR(gridZ >= m_gridMaxHeight, -1, "gridX:{} m_gridMaxHeight:{}", gridX, m_gridMaxHeight);

    m_gridList[gridX][gridZ].AddCreature(m_pObjPluginManager, pCreature);
    if (pCreature->GetKind() == CREATURE_PLAYER)
    {
        retCode = AddPlayer(pCreature);
    }
    else {
        retCode = AddCreature(pCreature);
    }

    return retCode;
}

int NFScene::AddCreature(NFCreature *pCreature)
{
    CHECK_NULL(pCreature);
    return m_creatureList.AddNode(m_pObjPluginManager, NF_CREATURE_NODE_LIST_SCENE_INDEX, pCreature);
}

int NFScene::RemoveCreature(NFCreature *pCreature)
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

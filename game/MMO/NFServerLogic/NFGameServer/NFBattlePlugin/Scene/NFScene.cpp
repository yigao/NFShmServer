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
#include "NFSceneMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

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
    m_mapGlobalId = -1;

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
    m_mapGlobalId = pMap->GetGlobalId();
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

NFMap *NFScene::GetMap() const
{
    if (m_mapGlobalId >= 0)
    {
        return dynamic_cast<NFMap *>(FindModule<NFISharedMemModule>()->GetObjByObjId(EOT_GAME_MAP_ID, m_mapGlobalId));
    }

    return NFMapMgr::Instance(m_pObjPluginManager)->GetMap(m_mapId);
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

bool NFScene::IsDynamic() const
{
    NFMap* pMap = GetMap();
    if (pMap)
    {
        return pMap->IsDynamic();
    }
    return false;
}

NFGrid *NFScene::EnterScene(NFCreature *pCreature, const NFPoint3<float> &pos, STransParam &transParam)
{
    CHECK_EXPR(pCreature, NULL, "pCreature == NULL");
    uint32_t gridX = uint32_t(pos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(pos.z / GRID_LENGTH);

    CHECK_EXPR(gridX < m_gridMaxWidth, NULL, "gridX:{} m_gridMaxWidth:{}", gridX, m_gridMaxWidth);
    CHECK_EXPR(gridZ < m_gridMaxHeight, NULL, "gridX:{} m_gridMaxHeight:{}", gridX, m_gridMaxHeight);

    if (NFSceneMgr::Instance(m_pObjPluginManager)->IsClosed(m_sceneId))
    {
        NFLogDebug(NF_LOG_SYSTEMLOG, pCreature->Cid(),
                   "Scene::EnterScene, scene is destorying cannt enter, RoleId:{}, dstpos({},{},{},), sceneId:{}, mapId:{},transType:{}",
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

NFCreature *NFScene::GetCreature(uint64_t cid)
{
    NFCreature *pCreature = dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetObjByGlobalIdWithNoCheck(cid));
    if (pCreature)
    {
        if (pCreature->Kind() == CREATURE_PLAYER)
        {
            if (!m_playerList.IsExistNode(pCreature, NF_CREATURE_NODE_LIST_SCENE_INDEX))
            {
                return NULL;
            }
        }
        else
        {
            if (!m_creatureList.IsExistNode(pCreature, NF_CREATURE_NODE_LIST_SCENE_INDEX))
            {
                return NULL;
            }
        }
    }

    return pCreature;
}

NFGrid *NFScene::MoveInScene(NFCreature *pCreature, const NFPoint3<float> &pos, bool &isSameGrid)
{
    CHECK_EXPR(pCreature, NULL, "pCreature == NULL");

    uint32_t gridX = uint32_t(pos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(pos.z / GRID_LENGTH);
    CHECK_EXPR(gridX < m_gridMaxWidth, NULL, "gridX:{} m_gridMaxWidth:{}", gridX, m_gridMaxWidth);
    CHECK_EXPR(gridZ < m_gridMaxHeight, NULL, "gridX:{} m_gridMaxHeight:{}", gridX, m_gridMaxHeight);
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

int NFScene::LeaveScene(NFCreature *pCreature)
{
    CHECK_EXPR(pCreature, proto_ff::RET_FAIL, "pCreature == NULL");
    NFGrid *pGrid = pCreature->GetGrid();
    CHECK_EXPR(pGrid, proto_ff::RET_FAIL, "pCreature->GetGrid() == NULL");

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

    return proto_ff::RET_SUCCESS;
}

bool BroadCast(uint32_t cmd, const google::protobuf::Message &msg)
{
    return true;
}

bool BroadCast(const SET_UINT64 &setcid, uint16_t cmd, const google::protobuf::Message &msg)
{
    return true;
}

void NFScene::GetNineGrid(const NFPoint3<float> &srcPos, std::vector<NFGrid *> &vecGrid)
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

void NFScene::GetLayerGrid(uint32_t layer, const NFPoint3<float> &srcPos, std::vector<NFGrid *> &vecGrid)
{
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    NFPoint2<uint32_t> gridPos(gridX, gridZ);
    for (uint32_t i = 0; i <= (uint32_t) layer; i++)
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

uint32_t NFScene::GetGridLayer(uint32_t gridX, uint32_t gridZ, const NFPoint3<float> &srcPos, float flength)
{
    uint32_t addGridX = (uint32_t(srcPos.x + flength)) / GRID_LENGTH;
    uint32_t addGridZ = (uint32_t(srcPos.z + flength)) / GRID_LENGTH;
    uint32_t reduceGridX = (uint32_t(srcPos.x - flength)) / GRID_LENGTH;
    uint32_t reduceGridZ = (uint32_t(srcPos.z - flength)) / GRID_LENGTH;

    uint32_t addCountX = 0;
    uint32_t reduceCountX = 0;
    uint32_t addCountZ = 0;
    uint32_t reduceCountZ = 0;
    while ((addGridX > gridX + addCountX)) addCountX++;
    while ((reduceGridX < gridX - reduceCountX)) reduceCountX++;
    while ((addGridZ > gridZ + addCountZ)) addCountZ++;
    while ((reduceGridZ < gridZ - reduceCountZ)) reduceCountZ++;

    uint32_t max_X = addCountX > reduceCountX ? addCountX : reduceCountX;
    uint32_t max_Z = addCountZ > reduceCountZ ? addCountZ : reduceCountZ;

    return max_X > max_Z ? max_X : max_Z;
}

void NFScene::GetLayerGrid(const NFPoint3<float> &srcPos, float flength, std::vector<NFGrid *> &vecGrid)
{
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    uint32_t layer = GetGridLayer(gridX, gridZ, srcPos, flength);

    layer = layer > MAX_LAYER ? MAX_LAYER : layer;

    GetLayerGrid(layer, srcPos, vecGrid);
}

int NFScene::FindDoubleSeeLstInNineGrid(NFCreature *pSrc, std::vector<NFCreature *> &clist, const NFPoint3<float> &srcPos)
{
    uint8_t srcCreatureKind = pSrc->Kind();
    std::vector<NFGrid *> vecGrid;
    GetNineGrid(srcPos, vecGrid);
    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        auto &gridCidlst = vecGrid[i]->GetCidList();

        for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
             pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
        {
            if (pCreature)
            {
                uint8_t dstCreatureKind = pCreature->Kind();
                if (srcCreatureKind == CREATURE_PLAYER && dstCreatureKind == CREATURE_PLAYER)
                {
                    continue;
                }

                if (srcCreatureKind != CREATURE_PLAYER && dstCreatureKind != CREATURE_PLAYER)
                {
                    continue;
                }

                if (pCreature->GetVisionData().chVisionUnitType == (int8_t) EVisionFlag::ALREADY)
                {
                    continue;
                }

                float dict = point2LengthSquare(srcPos, pCreature->GetPos());
                if (!pSrc->ViewFliter(pCreature, dict))
                {
                    clist.push_back(pCreature);
                }
            }
        }
    }

    return 0;
}

int NFScene::FindSeeLstInNineGrid(NFCreature *pSrc, std::vector<NFCreature *> *clist, const NFPoint3<float> &srcPos)
{
    std::vector<NFGrid *> vecGrid;
    GetNineGrid(srcPos, vecGrid);

    uint32_t nMax = MAX_SEE_CREATURE_COUNT_IN_THE_VISION - pSrc->GetVisionData().m_doublePVPSeeLst.size();
    float sixteenOfSightDictSquare = MAX_CHARACTER_SINGLERANGE_SQUARE / 16;
    float fourOfSightDictSquare = MAX_CHARACTER_SINGLERANGE_SQUARE / 4;
    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        auto &gridCidlst = vecGrid[i]->GetCidList();

        for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
             pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
        {
            //如果是玩家的情况
            if (pCreature && pCreature->Kind() == CREATURE_PLAYER)
            {
                if (pCreature->GetVisionData().chVisionUnitType == (int8_t) EVisionFlag::ALREADY)
                {
                    continue;
                }

                float dict = point2LengthSquare(pSrc->GetPos(), pCreature->GetPos());
                if (!pSrc->ViewFliter(pCreature, dict))
                {
                    if (dict < sixteenOfSightDictSquare)
                    {
                        clist[NEW_SEE_VISION_LESS_HALF_OF_HALF_MAX_SIGHT_RANGE].push_back(pCreature);
                    }
                    else if (dict < fourOfSightDictSquare)
                    {
                        clist[NEW_SEE_VISION_LESS_HALF_OF_MAX_SIGHT_RANGE].push_back(pCreature);
                    }
                    else
                    {
                        clist[NEW_SEE_VISION_THAN_HALF_OF_MAX_SIGHT_RANGE].push_back(pCreature);
                    }

                    if (clist[NEW_SEE_VISION_LESS_HALF_OF_HALF_MAX_SIGHT_RANGE].size() +
                        clist[NEW_SEE_VISION_LESS_HALF_OF_MAX_SIGHT_RANGE].size() +
                        clist[NEW_SEE_VISION_THAN_HALF_OF_MAX_SIGHT_RANGE].size() >= (uint32_t) nMax)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int NFScene::FindCreatureInScene(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount /* = 0 */)
{
    return FindCreatureInCircle(clist, srcPos, flength, creatureCount);
}

int NFScene::FindCreatureInScene(SET_Creature &setcreature, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount /* = 0 */)
{
    return FindCreatureInCircle(setcreature, srcPos, flength, creatureCount);
}

int NFScene::FindCreatureInCircle(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount /* = 0 */)
{
    std::vector<NFGrid *> vecGrid;

    GetLayerGrid(srcPos, flength, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        GridCreaturesWithCircle(clist, vecGrid[i], srcPos, flength, creatureCount);

        if (creatureCount > 0 && clist.size() >= creatureCount)
            return 0;
    }

    return 0;
}

int NFScene::GridCreaturesWithCircle(LIST_UINT64 &clist, NFGrid *pGrid, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount)
{
    auto &gridCidlst = pGrid->GetCidList();

    for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
         pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
    {
        if (creatureCount > 0 && clist.size() >= creatureCount) return 0;

        NFPoint3<float> dstPos = pCreature->GetPos();

        if (InCircle(dstPos, srcPos, flength + pCreature->GetModelRadius()))
            AddRangeLstCids(clist, srcPos, pCreature, creatureCount);
    }

    return 0;
}

int NFScene::FindCreatureInCircle(SET_Creature &setcreature, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount)
{
    std::vector<NFGrid *> vecGrid;

    GetLayerGrid(srcPos, flength, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        GridCreaturesWithCircle(setcreature, vecGrid[i], srcPos, flength, creatureCount);

        if (creatureCount > 0 && setcreature.size() >= creatureCount)
            return 0;
    }
    return 0;
}

int NFScene::GridCreaturesWithCircle(SET_Creature &setcreature, NFGrid *pGrid, const NFPoint3<float> &srcPos, float flength,
                                     uint32_t creatureCount /* = 0 */)
{
    auto &gridCidlst = pGrid->GetCidList();

    for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
         pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
    {
        if (creatureCount > 0 && setcreature.size() >= creatureCount) return 0;

        NFPoint3<float> dstPos = pCreature->GetPos();

        if (InCircle(dstPos, srcPos, flength + pCreature->GetModelRadius()))
            AddRangeLstCids(setcreature, srcPos, pCreature, creatureCount);
    }

    return 0;
}

int NFScene::FindCreatureInSector(LIST_UINT64 &clist, const NFPoint3<float> &center, NFPoint3<float> &dir, float angle, float sectorR,
                                  uint32_t creatureCount /* = 0 */)
{
    float halfAngle = (float) (double(angle / 2) * 3.14159 / 180.0f);
    float cosa = cos(halfAngle);

    std::vector<NFGrid *> vecGrid;

    GetLayerGrid(center, sectorR, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        GridCreaturesWithSector(clist, center, dir, vecGrid[i], cosa, sectorR, creatureCount);

        if (creatureCount > 0 && clist.size() >= creatureCount)
            return 0;
    }

    return 0;
}

int NFScene::GridCreaturesWithSector(LIST_UINT64 &clist, const NFPoint3<float> &center, NFPoint3<float> &vdir, NFGrid *pGrid, float cosAngle,
                                     float squaredR, uint32_t creatureCount/* = 0*/)
{
    CHECK_NULL(pGrid);

    auto &gridCidlst = pGrid->GetCidList();

    for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
         pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
    {
        if (creatureCount > 0 && clist.size() >= creatureCount) return 0;

        if (InSector(center, vdir, pCreature->GetPos(), cosAngle, squaredR + pCreature->GetModelRadius()))
            AddRangeLstCids(clist, center, pCreature, creatureCount);
    }

    return 0;
}


int NFScene::AddRangeLstCids(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, NFCreature *pTarget, uint32_t creatureCount)
{
    CHECK_NULL(pTarget);
    if (creatureCount <= 0 || clist.size() <= creatureCount)
    {
        clist.push_back(pTarget->Cid());
        return 0;
    }

    NFPoint3<float> to = pTarget->GetPos();
    float calNew = (srcPos.x - to.x) * (srcPos.x - to.x) + (srcPos.z - to.z) * (srcPos.z - to.z);
    uint64_t replacedCid = 0; //被替换的生物cid
    float calOld = 0;
    NFCreature *plistCreature = nullptr;
    auto iter = clist.begin();
    for (; iter != clist.end(); iter++)
    {
        plistCreature = GetCreature(*iter);
        if (!plistCreature)
        {
            replacedCid = *iter;
            clist.erase(iter);
            break;
        }
        to = plistCreature->GetPos();
        calOld = (srcPos.x - to.x) * (srcPos.x - to.x) + (srcPos.z - to.z) * (srcPos.z - to.z);
        if (calOld > calNew)
        {
            replacedCid = *iter;
            clist.erase(iter);
            break;
        }
    }
    if (replacedCid > 0)
        clist.push_back(pTarget->Cid());

    return 0;
}

int NFScene::AddRangeLstCids(SET_Creature &setcreature, const NFPoint3<float> &srcPos, NFCreature *pTarget, uint32_t creatureCount)
{
    CHECK_NULL(pTarget);
    if (creatureCount <= 0 || setcreature.size() <= creatureCount)
    {
        setcreature.insert(pTarget);
        return 0;
    }

    NFPoint3<float> to = pTarget->GetPos();
    float calNew = (srcPos.x - to.x) * (srcPos.x - to.x) + (srcPos.z - to.z) * (srcPos.z - to.z);
    NFCreature *preplaced = nullptr; //被替换的生物
    float calOld = 0;
    NFCreature *plistCreature = nullptr;
    auto iter = setcreature.begin();
    for (; iter != setcreature.end(); iter++)
    {
        plistCreature = (*iter);
        if (!plistCreature)
        {
            preplaced = *iter;
            setcreature.erase(iter);
            break;
        }
        to = plistCreature->GetPos();
        calOld = (srcPos.x - to.x) * (srcPos.x - to.x) + (srcPos.z - to.z) * (srcPos.z - to.z);
        if (calOld > calNew)
        {
            preplaced = *iter;
            setcreature.erase(iter);
            break;
        }
    }

    if (nullptr != preplaced)
        setcreature.insert(pTarget);

    return 0;
}

int NFScene::FindCreatureInRect(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, NFPoint3<float> &srcDir, float flength, float fwidth,
                                uint32_t creatureCount)
{
    NFPoint3<float> center = srcPos + srcDir * (flength / 2);
    NFPoint3<float> dir = srcDir; // srcPos - center;
    return FindCreatureInRect(clist, center, dir, srcPos, flength, fwidth, creatureCount);
}


int NFScene::FindCreatureInRect(LIST_UINT64 &clist, const NFPoint3<float> &center, const NFPoint3<float> &dir, const NFPoint3<float> &searchpos,
                                float flength, float fwidth, uint32_t creatureCount /* = 0 */)
{
    std::vector<NFGrid *> vecGrid;

    uint32_t maxLength = flength > fwidth ? flength : fwidth;
    GetLayerGrid(searchpos, maxLength, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        GridCreaturesWithRect(clist, vecGrid[i], center, dir, flength, fwidth, creatureCount);

        if (creatureCount > 0 && clist.size() >= creatureCount)
            return 0;
    }
    return 0;
}

int NFScene::FindCreatureInRect(SET_Creature &setcreature, const NFPoint3<float> &srcPos, NFPoint3<float> &srcDir, float flength, float fwidth,
                                uint32_t creatureCount)
{
    std::vector<NFGrid *> vecGrid;
    NFPoint3<float> center = srcPos + srcDir * (flength / 2);
    NFPoint3<float> dir = srcDir;
    uint32_t maxLength = flength > fwidth ? flength : fwidth;
    GetLayerGrid(srcPos, maxLength, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        GridCreaturesWithRect(setcreature, vecGrid[i], center, dir, flength, fwidth, creatureCount);

        if (creatureCount > 0 && setcreature.size() >= creatureCount)
            return 0;
    }

    return 0;
}

int NFScene::GridCreaturesWithRect(LIST_UINT64 &clist, NFGrid *pGrid, const NFPoint3<float> &center, const NFPoint3<float> &dir, float flength,
                                   float fwidth, uint32_t creatureCount/* = 0*/)
{
    CHECK_NULL(pGrid);

    auto &gridCidlst = pGrid->GetCidList();

    for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
         pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
    {
        if (creatureCount > 0 && clist.size() >= creatureCount) return 0;

        if (InRect(pCreature->GetPos(), center, flength + pCreature->GetModelRadius(), fwidth + pCreature->GetModelRadius(), dir))
            AddRangeLstCids(clist, center, pCreature, creatureCount);
    }

    return 0;
}

int NFScene::GridCreaturesWithRect(SET_Creature &setcreature, NFGrid *pGrid, const NFPoint3<float> &center, const NFPoint3<float> &dir,
                                   float flength, float fwidth, uint32_t creatureCount/* = 0*/)
{
    CHECK_NULL(pGrid);
    auto &gridCidlst = pGrid->GetCidList();

    for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
         pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
    {
        if (creatureCount > 0 && setcreature.size() >= creatureCount) return 0;

        if (InRect(pCreature->GetPos(), center, flength + pCreature->GetModelRadius(), fwidth + pCreature->GetModelRadius(), dir))
            AddRangeLstCids(setcreature, center, pCreature, creatureCount);
    }
    return 0;
}

//圆形范围内 查找敌人
int NFScene::FindEnemyInCircle(NFCreature *psrc, SET_Creature &setcreature, float fradius, uint32_t creatureCount)
{
    if (nullptr == psrc || fradius <= EPS) return 0;

    NFPoint3<float> srcPos = psrc->GetPos();

    std::vector<NFGrid *> vecGrid;
    GetLayerGrid(srcPos, fradius, vecGrid);

    for (size_t i = 0; i < vecGrid.size(); i++)
    {
        if (vecGrid[i] == NULL) continue;

        auto &gridCidlst = vecGrid[i]->GetCidList();

        for (NFCreature *pCreature = gridCidlst.GetHeadNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX);
             pCreature != nullptr; pCreature = gridCidlst.GetNextNodeObj(m_pObjPluginManager, NF_CREATURE_NODE_LIST_GRID_INDEX, pCreature))
        {
            if (creatureCount > 0 && setcreature.size() >= creatureCount) return 0;

            NFPoint3<float> dstPos = pCreature->GetPos();
            //
            if (!InCircle(dstPos, srcPos, fradius + pCreature->GetModelRadius())) continue;

            if (!psrc->CanAddSeeNewCreature(pCreature, 1)) continue;

            setcreature.insert(pCreature);

            if (creatureCount > 0 && setcreature.size() >= creatureCount) return 0;
        }

        if (creatureCount > 0 && setcreature.size() >= creatureCount)
            return 0;
    }

    return 0;
}

void NFScene::FindPointLstInRect(const NFPoint3<float> &center, VecPoint3 &vecPos, float fwidth, float fhigh, int32_t pointCnt, uint32_t curcount)
{
    if (pointCnt <= 0)
    {
        return;
    }

    NFMap *pMap = GetMap();
    if (nullptr == pMap)
    {
        for (int32_t i = 0; i < pointCnt; ++i)
        {
            vecPos.push_back(center);
        }
        return;
    }

    uint32_t tempcount = 0;
    int32_t idx = 1;
    uint32_t idx_startcount = 0;
    if (curcount > 0)
    {
        for (int32_t tmpidx = 1; tmpidx < 100; ++tmpidx)
        {
            uint32_t cnt = 4 + ((tmpidx - 1) * 2 + 1) * 4;
            if (curcount < (tempcount + cnt))
            {
                idx = tmpidx;
                idx_startcount = curcount - tempcount;
                break;
            }
            tempcount += cnt;
        }
    }
    //
    int32_t count = 0;
    while (true)
    {
        if (count >= 300)
        {
            NFLogDebug(NF_LOG_SYSTEMLOG, m_sceneId,
                       "Scene::FindPointLstInRect....count >= 300....idx:{},fwidth:{},fhigh:{},pointCnt:{},beginidx:{},count:{} ", idx,
                       fwidth, fhigh, pointCnt, curcount, count);
            break;
        }
        float fcoef = idx * fwidth;
        float fcoefB = idx * fhigh;
        int32_t exnum = (idx - 1) * 2 + 2;

        NFPoint3<float> posa(center.x - fcoef, center.y, center.z + fcoefB);
        NFPoint3<float> posb(center.x + fcoef, center.y, center.z + fcoefB);
        NFPoint3<float> posc(center.x + fcoef, center.y, center.z - fcoefB);
        NFPoint3<float> posd(center.x - fcoef, center.y, center.z - fcoefB);

        //
        VecPoint3 vecTmpA;
        vecTmpA.push_back(posa);
        VecPoint3 vecTmpB;
        vecTmpB.push_back(posb);
        VecPoint3 vecTmpC;
        vecTmpC.push_back(posc);
        VecPoint3 vecTmpD;
        vecTmpD.push_back(posd);
        if (exnum > 0)
        {
            float fpera = (posb.x - posa.x) / exnum;
            float fperb = (posc.z - posb.z) / exnum;
            float fperc = (posd.x - posc.x) / exnum;
            float fperd = (posa.z - posd.z) / exnum;
            int32_t i = 1;
            for (i = 1; i < exnum; ++i)
            {
                NFPoint3<float> tmpa(posa.x + fpera * i, posa.y, posa.z);
                NFPoint3<float> tmpb(posb.x, posb.y, posb.z + fperb * i);
                NFPoint3<float> tmpc(posc.x + fperc * i, posc.y, posc.z);
                NFPoint3<float> tmpd(posd.x, posd.y, posd.z + fperd * i);
                vecTmpA.push_back(tmpa);
                vecTmpB.push_back(tmpb);
                vecTmpC.push_back(tmpc);
                vecTmpD.push_back(tmpd);
            }
        }
        VecPoint3::iterator iterA = vecTmpA.begin();
        for (; iterA != vecTmpA.end(); ++iterA)
        {
            if (idx_startcount > 0)
            {
                idx_startcount--;
                continue;
            }
            NFPoint3<float> tmpPos = (*iterA);
            NFPoint3<float> targetPos = tmpPos;
            if (pMap->FindNearestPos(tmpPos.x, tmpPos.z, tmpPos.y, &targetPos.x, &targetPos.z, &targetPos.y, nullptr))
            {
                vecPos.push_back(targetPos);
                if (++count >= pointCnt) return;
            }
        }
        VecPoint3::iterator iterB = vecTmpB.begin();
        for (; iterB != vecTmpB.end(); ++iterB)
        {
            if (idx_startcount > 0)
            {
                idx_startcount--;
                continue;
            }
            NFPoint3<float> tmpPos = (*iterB);
            NFPoint3<float> targetPos = tmpPos;
            if (pMap->FindNearestPos(tmpPos.x, tmpPos.z, tmpPos.y, &targetPos.x, &targetPos.z, &targetPos.y, nullptr))
            {
                vecPos.push_back(targetPos);
                if (++count >= pointCnt) return;
            }
        }
        VecPoint3::iterator iterC = vecTmpC.begin();
        for (; iterC != vecTmpC.end(); ++iterC)
        {
            if (idx_startcount > 0)
            {
                idx_startcount--;
                continue;
            }
            NFPoint3<float> tmpPos = (*iterC);
            NFPoint3<float> targetPos = tmpPos;
            if (pMap->FindNearestPos(tmpPos.x, tmpPos.z, tmpPos.y, &targetPos.x, &targetPos.z, &targetPos.y, nullptr))
            {
                vecPos.push_back(targetPos);
                if (++count >= pointCnt) return;
            }
        }
        VecPoint3::iterator iterD = vecTmpD.begin();
        for (; iterD != vecTmpD.end(); ++iterD)
        {
            if (idx_startcount > 0)
            {
                idx_startcount--;
                continue;
            }
            NFPoint3<float> tmpPos = (*iterD);
            NFPoint3<float> targetPos = tmpPos;
            if (pMap->FindNearestPos(tmpPos.x, tmpPos.z, tmpPos.y, &targetPos.x, &targetPos.z, &targetPos.y, nullptr))
            {
                vecPos.push_back(targetPos);
                if (++count >= pointCnt) return;
            }
        }

    } // end of while (true)
}

//矩形范围内 查找技能目标
void NFScene::FindSkillTargetInRect(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos,
                                    const NFPoint3<float> &srcDir, float flength, float fwidth, const SearchSkillTargetParam &param)
{
/*    if (nullptr == param.pcfg || nullptr == param.pcfg->cfg || nullptr == psrc) return;
    NFPoint3<float> center = srcPos + srcDir * (flength / 2);
    //
    uint8_t srckind = psrc->Kind();
    uint32_t totalcount = 0;
    uint32_t searchcount = 0;
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    uint32_t maxLength = flength > fwidth ? flength : fwidth;
    uint32_t layer = GetGridLayer(gridX, gridZ, srcPos, maxLength);
    layer = layer > MAX_LAYER ? MAX_LAYER : layer;
    //
    NFPoint2 <uint32_t> gridpos(gridX, gridZ);
    const vecPoint2 *pVecPoint2 = nullptr;
    for (uint32_t i = 0; i <= layer; i++)
    {
        pVecPoint2 = g_GetSceneMgr()->GetLayerPoint(i);
        if (!pVecPoint2)
        {
            LogErrFmtPrint("g_GetSceneMgr()->GetLayerPoint(i) is null, layer:%d", i);
            return;
        }
        for (uint32_t j = 0; j < pVecPoint2->size(); j++)
        {
            gridpos.x = uint32_t(gridX + pVecPoint2->at(j).x);
            gridpos.y = uint32_t(gridZ + pVecPoint2->at(j).y);
            //
            if (gridpos.x >= m_gridmaxWidth || gridpos.y >= m_gridmaxHight) continue;
            Grid &mgrid = m_sceneGrid[gridpos.x][gridpos.y];
            auto &gridCidlst = mgrid.GetCids();
            if (gridCidlst.Count() <= 0) continue;
            //
            for (auto pNode = gridCidlst.Head(); pNode != nullptr; pNode = gridCidlst.Next(pNode))
            {
                Creature *pCreature = (Creature *) pNode->GetHost();
                if (nullptr == pCreature)
                {
                    LogErrFmtPrint("Scene::FindSkillTargetInRect %p not exit in this grid(%d,%d), src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld",
                                   pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                                   param.pcfg->cfg->skillID);
                    mgrid.RemoveNode(pNode);
                    break;
                }
                if (!InRect(pCreature->GetPos(), center, flength + pCreature->GetModelRadius(), fwidth + pCreature->GetModelRadius(), srcDir))
                {
                    continue;
                }
                ++searchcount;
                //
                if (!g_GetSkillMgr()->CanAtk(psrc, pCreature, param.pcfg))
                {
                    continue;
                }
                if (g_GetSkillMgr()->IsPriorityTarget(srckind, pCreature->Kind()))
                {
                    if ((uint32_t) setpriority.size() < param.priority_count)
                    {
                        setpriority.insert(pCreature);
                        totalcount++;
                    }
                }
                else
                {
                    if ((uint32_t) setother.size() < param.total_count)
                    {
                        setother.insert(pCreature);
                        totalcount++;
                    }
                }
                //
                if (totalcount >= param.total_count || (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT))
                {
                    if (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT)
                    {
                        LogErrFmtPrint("Scene::FindSkillTargetInRect...search too many times... src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld",
                                       pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                                       param.pcfg->cfg->skillID);
                    }
                    //
                    return;
                }
            }
        }
    }*/
}

//圆形范围内 查找技能目标
void
NFScene::FindSkillTargetInCircle(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos, float flength,
                                 const SearchSkillTargetParam &param)
{
/*    if (nullptr == param.pcfg || nullptr == param.pcfg->cfg || nullptr == psrc) return;
    //
    uint8_t srckind = psrc->Kind();
    LIST_Creature lstpriority;
    LIST_Creature lstother;
    uint32_t totalcount = 0;
    uint32_t searchcount = 0;
    //
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    uint32_t layer = GetGridLayer(gridX, gridZ, srcPos, flength);
    layer = layer > MAX_LAYER ? MAX_LAYER : layer;
    Point2 <uint32_t> gridpos(gridX, gridZ);
    const vecPoint2 *pVecPoint2 = nullptr;
    for (uint32_t i = 0; i <= layer; i++)
    {
        pVecPoint2 = g_GetSceneMgr()->GetLayerPoint(i);
        if (!pVecPoint2)
        {
            LogErrFmtPrint("g_GetSceneMgr()->GetLayerPoint(i) is null, layer:%d", i);
            return;
        }
        for (uint32_t j = 0; j < pVecPoint2->size(); j++)
        {
            gridpos.x = uint32_t(gridX + pVecPoint2->at(j).x);
            gridpos.y = uint32_t(gridZ + pVecPoint2->at(j).y);
            //
            if (gridpos.x >= m_gridmaxWidth || gridpos.y >= m_gridmaxHight) continue;
            Grid &mgrid = m_sceneGrid[gridpos.x][gridpos.y];
            Point3<float> dstPos;
            auto &gridCidlst = mgrid.GetCids();
            if (gridCidlst.Count() <= 0) continue;
            //
            for (auto pNode = gridCidlst.Head(); pNode != nullptr; pNode = gridCidlst.Next(pNode))
            {
                Creature *pCreature = (Creature *) pNode->GetHost();
                if (nullptr == pCreature)
                {
                    LogErrFmtPrint("Scene::FindSkillTargetInCircle %p not exit in this grid(%d,%d), src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld",
                                   pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                                   param.pcfg->cfg->skillID);
                    mgrid.RemoveNode(pNode);
                    break;
                }
                if (!InCircle(srcPos, pCreature->GetPos(), flength + pCreature->GetModelRadius()))
                {
                    continue;
                }
                ++searchcount;
                //
                if (!g_GetSkillMgr()->CanAtk(psrc, pCreature, param.pcfg))
                {
                    continue;
                }
                if (g_GetSkillMgr()->IsPriorityTarget(srckind, pCreature->Kind()))
                {
                    if ((uint32_t) setpriority.size() < param.priority_count)
                    {
                        setpriority.insert(pCreature);
                        totalcount++;
                    }
                }
                else
                {
                    if ((uint32_t) setother.size() < param.total_count)
                    {
                        setother.insert(pCreature);
                        totalcount++;
                    }
                }
                //
                if (totalcount >= param.total_count || (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT))
                {
                    if (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT)
                    {
                        LogErrFmtPrint("Scene::FindSkillTargetInCircle...search too many times... src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld",
                                       pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                                       param.pcfg->cfg->skillID);
                    }

                    return;
                }
            }
        }
    }*/
}

//扇形范围内 查找技能目标
void NFScene::FindSkillTargetInSector(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos,
                                      const NFPoint3<float> &srcDir, float fradius, float fangle, const SearchSkillTargetParam &param)
{
/*    if (nullptr == param.pcfg || nullptr == param.pcfg->cfg || nullptr == psrc) return;
    //
    uint8_t srckind = psrc->Kind();
    LIST_Creature lstpriority;
    LIST_Creature lstother;
    uint32_t totalcount = 0;
    uint32_t searchcount = 0;
    //
    uint32_t gridX = uint32_t(srcPos.x / GRID_LENGTH);
    uint32_t gridZ = uint32_t(srcPos.z / GRID_LENGTH);
    uint32_t layer = GetGridLayer(gridX, gridZ, srcPos, fradius);
    layer = layer > MAX_LAYER ? MAX_LAYER : layer;
    Point2 <uint32_t> gridpos(gridX, gridZ);
    const vecPoint2 *pVecPoint2 = nullptr;
    for (uint32_t i = 0; i <= layer; i++)
    {
        pVecPoint2 = g_GetSceneMgr()->GetLayerPoint(i);
        if (!pVecPoint2)
        {
            LogErrFmtPrint("g_GetSceneMgr()->GetLayerPoint(i) is null, layer:%d", i);
            return;
        }
        for (uint32_t j = 0; j < pVecPoint2->size(); j++)
        {
            gridpos.x = uint32_t(gridX + pVecPoint2->at(j).x);
            gridpos.y = uint32_t(gridZ + pVecPoint2->at(j).y);
            //
            if (gridpos.x >= m_gridmaxWidth || gridpos.y >= m_gridmaxHight) continue;
            Grid &mgrid = m_sceneGrid[gridpos.x][gridpos.y];
            Point3<float> dstPos;
            auto &gridCidlst = mgrid.GetCids();
            if (gridCidlst.Count() <= 0) continue;
            //
            for (auto pNode = gridCidlst.Head(); pNode != nullptr; pNode = gridCidlst.Next(pNode))
            {
                Creature *pCreature = (Creature *) pNode->GetHost();
                if (nullptr == pCreature)
                {
                    LogErrFmtPrint(
                            "Scene::FindSkillTargetInSector %p not exit in this grid(%d,%d), src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld,fradius:%f",
                            pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                            param.pcfg->cfg->skillID, fradius);
                    mgrid.RemoveNode(pNode);
                    break;
                }
                if (!InSector2(srcPos, srcDir, pCreature->GetPos(), fangle, fradius + pCreature->GetModelRadius()))
                {
                    continue;
                }
                ++searchcount;
                //
                if (!g_GetSkillMgr()->CanAtk(psrc, pCreature, param.pcfg))
                {
                    continue;
                }
                if (g_GetSkillMgr()->IsPriorityTarget(srckind, pCreature->Kind()))
                {
                    if ((uint32_t) setpriority.size() < param.priority_count)
                    {
                        setpriority.insert(pCreature);
                        totalcount++;
                    }
                }
                else
                {
                    if ((uint32_t) setother.size() < param.total_count)
                    {
                        setother.insert(pCreature);
                        totalcount++;
                    }
                }
                //
                if (totalcount >= param.total_count || (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT))
                {
                    if (searchcount >= MAX_SKILL_TARGET_SERACH_COUNT)
                    {
                        LogErrFmtPrint(
                                "Scene::FindSkillTargetInSector...search too many times... src:%lu,cfgid:%lu,scene:%lu,map:%lu,skillid:%ld,fradius:%f",
                                pNode, gridpos.x, gridpos.y, psrc->Cid(), psrc->GetCfgId(), psrc->GetSceneId(), psrc->GetMapId(),
                                param.pcfg->cfg->skillID, fradius);
                    }

                    return;
                }
            }
        }
    }*/
}

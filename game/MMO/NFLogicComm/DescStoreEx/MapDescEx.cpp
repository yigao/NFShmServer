#include "MapDescEx.h"
#include "DescStore/RoleBornDesc.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "ServerConfig.pb.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFGameCommon/NFMath.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFLogicCommon/NFDupDefine.h"

MapDescEx::MapDescEx()
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

MapDescEx::~MapDescEx()
{
}

int MapDescEx::CreateInit()
{
    m_1v1ReadyMapId = 0;//1v1准备地图ID
    m_qyMapId = 0;
    m_3v3WaitMapId = 0;
    m_3v3MapId = 0;
    m_safeMapId = 0;
    return 0;
}

int MapDescEx::ResumeInit()
{
    return 0;
}

int MapDescEx::Load()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    
    std::string dir = m_pObjPluginManager->GetConfigPath() + "/Json/";
    
    auto& mapResDesc = MapMapDesc::Instance()->GetResDesc();
    for (auto iter = mapResDesc.begin(); iter != mapResDesc.end(); iter++)
    {
        auto pDesc = &iter->second;
        if (pDesc)
        {
            if (IsMainCity(pDesc))
            {
                m_setMainCity.insert(pDesc->m_mapId);
            }
            else if (Is1v1Ready(pDesc))
            {
                m_1v1ReadyMapId = pDesc->m_mapId;
            }
            else if (IsQyActMap(pDesc))
            {
                m_qyMapId = pDesc->m_mapId;
            }
            else if (Is3v3WaitMap(pDesc))
            {
                m_3v3WaitMapId = pDesc->m_mapId;
            }
            else if (Is3v3Map(pDesc))
            {
                m_3v3MapId = pDesc->m_mapId;
            }
            else if (IsSafeMap(pDesc))
            {
                m_safeMapId = pDesc->m_mapId;
            }
            
            LoadBornCfg(pDesc->m_mapId, dir + NFCommon::tostr(pDesc->m_mapId) + ".json");
        }
    }
    
    auto& bornResDesc = RoleBornDesc::Instance()->GetResDesc();
    for (auto iter = bornResDesc.begin(); iter != bornResDesc.end(); iter++)
    {
        auto pDesc = &iter->second;
        if (pDesc)
        {
            CHECK_EXPR_ASSERT(m_bornProfMap.find(pDesc->m_professionID) == m_bornProfMap.end(), -1, "m_bornProfMap Repeated role prof:{} born:{}", pDesc->m_professionID,
                              pDesc->m_bornID);
            auto iter = m_bornProfMap.emplace_hint(pDesc->m_professionID, pDesc->m_bornID);
            CHECK_EXPR_ASSERT(iter != m_bornProfMap.end(), -1, "m_bornProfMap Space Not Enough prof:{} born:{}", pDesc->m_professionID, pDesc->m_bornID);
        }
    }
    
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int MapDescEx::CheckWhenAllDataLoaded()
{
    return 0;
}

int MapDescEx::LoadBornCfg(uint64_t mapId, const std::string& file)
{
    std::string context;
    bool ret = NFFileUtility::ReadFileContent(file, context);
    if (ret)
    {
        std::string strErr;
        proto_ff::MapJsonConfig jsonConfig;
        ret = NFProtobufCommon::JsonToProtoMessage(context, &jsonConfig, &strErr);
        if (!ret)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "JsonToProtoMessage Failed, file:{} error:{}", context, strErr);
        }
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "file:{} parse:{}", file, jsonConfig.DebugString());
        
        for (int i = 0; i < (int)jsonConfig.objs_size(); i++)
        {
            auto& obj = jsonConfig.objs(i);
            if (obj.id() == mapId)
            {
                CHECK_EXPR_ASSERT(m_bornPosMap.size() < m_bornPosMap.max_size(), -1, "m_bornPosMap Full, the hashmap space not enough, bornId:{}", obj.id());
                CHECK_EXPR_ASSERT(m_bornPosMap.find(obj.id()) == m_bornPosMap.end(), -1, "file:{} exist repeated bornId:{}", file, obj.id());
                auto pBornArray = &m_bornPosMap[obj.id()];
                CHECK_EXPR_ASSERT(pBornArray, -1, "m_bornPosMap.Insert Failed bornId:{}", obj.id());
                for (int j = 0; j < (int)obj.pos_size(); j++)
                {
                    CHECK_EXPR_ASSERT(pBornArray->size() < pBornArray->max_size(), -1, "pBornArray Space Not Enough!");
                    pBornArray->push_back();
                    auto pPos = &pBornArray->back();
                    pPos->m_pos.x = obj.pos(j).pos().x();
                    pPos->m_pos.y = obj.pos(j).pos().y();
                    pPos->m_pos.z = obj.pos(j).pos().z();
                    pPos->m_dir = obj.pos(j).rot();
                }
            }
            
            {
                CHECK_EXPR_ASSERT(m_pointMap.size() < m_pointMap.max_size(), -1, "m_pointMap Full, the hashmap space not enough, bornId:{}", obj.id());
                CHECK_EXPR_ASSERT(m_pointMap.find(obj.id()) == m_pointMap.end(), -1, "file:{} exist repeated bornId:{}", file, obj.id());
                auto pPosArray = &m_pointMap[obj.id()];
                pPosArray->id = obj.id();
                pPosArray->mapid = mapId;
                CHECK_EXPR_ASSERT(pPosArray, -1, "m_posMap.Insert Failed bornId:{}", obj.id());
                CHECK_EXPR_ASSERT((int)pPosArray->vecposcfg.max_size() >= (int)obj.pos_size(), -1, "m_posMap pos array space not enough, bornId:{}, pos size:{}",
                                  obj.id(), obj.pos_size());
                pPosArray->vecposcfg.resize(obj.pos_size());
                for (int j = 0; j < (int)obj.pos_size(); j++)
                {
                    auto pPos = &pPosArray->vecposcfg.at(j);
                    pPos->m_pos.x = obj.pos(j).pos().x();
                    pPos->m_pos.y = obj.pos(j).pos().y();
                    pPos->m_pos.z = obj.pos(j).pos().z();
                    pPos->m_dir = obj.pos(j).rot();
                }
            }
        }
        
        for (int i = 0; i < (int)jsonConfig.paths_size(); i++)
        {
            auto& pathConfig = jsonConfig.paths(i);
            CHECK_EXPR_ASSERT(m_pathMap.size() < m_pathMap.max_size(), -1, "m_pathMap Full, the hashmap space not enough, pathId:{}", pathConfig.id());
            CHECK_EXPR_ASSERT(m_pathMap.find(pathConfig.id()) == m_pathMap.end(), -1, "file:{} exist repeated pathId:{}", file, pathConfig.id());
            auto pPath = &m_pathMap[pathConfig.id()];
            CHECK_EXPR_ASSERT(pPath, -1, "m_pathMap.Insert Failed bornId:{}", pathConfig.id());
            pPath->m_id = pathConfig.id();
            pPath->m_mapId = mapId;
            CHECK_EXPR_ASSERT((int)pPath->m_pathCfg.max_size() >= (int)pathConfig.pos_size(), -1,
                              "m_pathMap pos array space not enough, pathId:{}", file, pathConfig.id());
            pPath->m_pathCfg.resize(pathConfig.pos_size());
            for (int j = 0; j < (int)pathConfig.pos_size(); j++)
            {
                auto pPos = &pPath->m_pathCfg.at(j);
                pPos->x = pathConfig.pos(j).x();
                pPos->y = pathConfig.pos(j).y();
                pPos->z = pathConfig.pos(j).z();
            }
        }
        
        for (int i = 0; i < (int)jsonConfig.areas_size(); i++)
        {
            auto& areaConfig = jsonConfig.areas(i);
            CHECK_EXPR_ASSERT(m_areaMap.size() < m_areaMap.max_size(), -1, "m_areaMap Full, the hashmap space not enough, areaId:{}", areaConfig.id());
            CHECK_EXPR_ASSERT(m_areaMap.find(areaConfig.id()) == m_areaMap.end(), -1, "file:{} exist repeated areaId:{}", file, areaConfig.id());
            auto pArea = &m_areaMap[areaConfig.id()];
            CHECK_EXPR_ASSERT(pArea, -1, "m_areaMap.Insert Failed areaId:{}", areaConfig.id());
            pArea->m_id = areaConfig.id();
            pArea->m_mapId = mapId;
            CHECK_EXPR_ASSERT((int)pArea->m_areaCfg.max_size() >= (int)areaConfig.detail_size(), -1,
                              "m_areaMap pos array space not enough, areaId:{}", areaConfig.id());
            pArea->m_areaCfg.resize(areaConfig.detail_size());
            for (int j = 0; j < (int)areaConfig.detail_size(); j++)
            {
                auto pPos = &pArea->m_areaCfg[j];
                pPos->m_circle.x = areaConfig.detail(j).pos().x();
                pPos->m_circle.y = areaConfig.detail(j).pos().y();
                pPos->m_circle.z = areaConfig.detail(j).pos().z();
                pPos->m_radius = areaConfig.detail(j).pos().z();
            }
        }
        return 0;
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ReadFileContent Failed, file:{}", file);
    }
    return -1;
}

int32_t MapDescEx::BornPointCount(int64_t mapId)
{
    auto pVecBorn = GetBornPosCfg(mapId);
    if (pVecBorn)
    {
        return pVecBorn->size();
    }
    return 0;
}

const NFPoint3<float>* MapDescEx::RandBornPoint(int64_t mapId)
{
    auto pVecBorn = GetBornPosCfg(mapId);
    if (pVecBorn)
    {
        int idx = NFRandInt((int)0, (int)pVecBorn->size());
        auto pPos = &pVecBorn->at(idx);
        if (pPos)
        {
            return &pPos->m_pos;
        }
    }
    return NULL;
}

const VecPosCfg* MapDescEx::GetBornPosCfg(int64_t mapId)
{
    auto iter = m_bornPosMap.find(mapId);
    if (iter != m_bornPosMap.end())
    {
        return &iter->second;
    }
    return NULL;
}

const proto_ff_s::E_RoleBorn_s* MapDescEx::GetBornCfg(int32_t prof)
{
    auto iter = m_bornProfMap.find(prof);
    if (iter != m_bornProfMap.end())
    {
        return RoleBornDesc::Instance()->GetDesc(iter->second);
    }
    return NULL;
}

const NFPointCfg* MapDescEx::GetPointCfg(int64_t id)
{
    auto iter = m_pointMap.find(id);
    if (iter != m_pointMap.end())
    {
        return &iter->second;
    }
    return NULL;
}

const NFPathCfg* MapDescEx::GetPathCfg(int64_t id)
{
    auto iter = m_pathMap.find(id);
    if (iter != m_pathMap.end())
    {
        return &iter->second;
    }
    return NULL;
}

const NFAreaCfg* MapDescEx::GetAreaCfg(int64_t id)
{
    auto iter = m_areaMap.find(id);
    if (iter != m_areaMap.end())
    {
        return &iter->second;
    }
    return NULL;
}

bool MapDescEx::InArea(int64_t areaid, const NFPoint3<float>& pos)
{
    const NFAreaCfg* pCfg = GetAreaCfg(areaid);
    if (nullptr != pCfg)
    {
        for (int i = 0; i < (int)pCfg->m_areaCfg.size(); i++)
        {
            const NFAreaPosCfg* pPos = &pCfg->m_areaCfg[i];
            if (NFMath::InCircle(pPos->m_circle, pos, (pPos->m_radius + 0.5)))
            {
                return true;
            }
        }
        return false;
    }
    
    return false;
}

bool MapDescEx::RandPosInArea(int64_t areaid, NFPoint3<float>& outpos)
{
    const NFAreaCfg* pcfg = GetAreaCfg(areaid);
    if (nullptr == pcfg) { return false; }
    
    uint32_t nsize = (uint32_t)pcfg->m_areaCfg.size();
    if (nsize <= 0) { return false; }
    
    uint32_t idx = NFRandInt((uint32_t)0, nsize); //0 - (nsize-1)
    const NFAreaPosCfg& area = pcfg->m_areaCfg[idx];
    float radius = (float)(NFRandInt((uint32_t)1, (uint32_t)(area.m_radius * 1000)) / 1000.0f);
    float angle = (float)(NFRandInt(0, 360 * 1000)) / 1000.0f;
    outpos.x = area.m_circle.x + radius * cos(angle);
    outpos.y = area.m_circle.y;
    outpos.z = area.m_circle.z + radius * sin(angle);
    return true;
}

bool MapDescEx::IsDynamic(int64_t mapId)
{
    auto pMapCfg = MapMapDesc::Instance()->GetDesc(mapId);
    if (pMapCfg)
    {
        return (1 == pMapCfg->m_isDyn);
    }
    
    return false;
}

bool MapDescEx::IsActSpecMap(int64_t mapId)
{
    return false;
}

bool MapDescEx::IsMainCity(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsMainCity(pCfg);
}

bool MapDescEx::IsMainCity(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    return (NORMAL_MAP == pCfg->m_mapType && (int32_t)ENormalMapType::MainCity == pCfg->m_mapSubType);
}

bool MapDescEx::Is1v1Ready(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return Is1v1Ready(pCfg);
}

bool MapDescEx::Is1v1Ready(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    return (NORMAL_MAP == pCfg->m_mapType && (int32_t)ENormalMapType::Ready1v1 == pCfg->m_mapSubType);
}

bool MapDescEx::IsQyActMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsQyActMap(pCfg);
}

bool MapDescEx::IsQyActMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == 510)
    {
        return true;
    }
    return false;
}

bool MapDescEx::Is3v3WaitMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return Is3v3WaitMap(pCfg);
}

bool MapDescEx::Is3v3WaitMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == 511)
    {
        return true;
    }
    return false;
}

bool MapDescEx::Is3v3Map(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return Is3v3Map(pCfg);
}

bool MapDescEx::Is3v3Map(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == 512)
    {
        return true;
    }
    return false;
}

bool MapDescEx::IsXiYouReadyMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsXiYouReadyMap(pCfg);
}

bool MapDescEx::IsXiYouReadyMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == EDupGroupID_XiYouReady)
    {
        return true;
    }
    return false;
}

bool MapDescEx::IsXiYouKillBossMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsXiYouKillBossMap(pCfg);
}

bool MapDescEx::IsXiYouKillBossMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == EDupGroupID_XiYouKillBoss)
    {
        return true;
    }
    return false;
}

bool MapDescEx::IsXiYouRouBaoZiMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsXiYouRouBaoZiMap(pCfg);
}

bool MapDescEx::IsXiYouRouBaoZiMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == EDupGroupID_XiYouRouBaoZi)
    {
        return true;
    }
    return false;
}

bool MapDescEx::IsXiYouCaiJiMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsXiYouCaiJiMap(pCfg);
}

bool MapDescEx::IsXiYouCaiJiMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    if (pCfg->m_mapType == DUP_MAP && pCfg->m_mapSubType == EDupGroupID_XiYouCollect)
    {
        return true;
    }
    return false;
}

bool MapDescEx::IsSafeMap(int64_t mapId)
{
    auto pCfg = MapMapDesc::Instance()->GetDesc(mapId);
    return IsSafeMap(pCfg);
}

bool MapDescEx::IsSafeMap(const proto_ff_s::E_MapMap_s* pCfg)
{
    if (nullptr == pCfg) { return false; }
    return (SAFE_MAP == pCfg->m_mapType);
}

bool MapDescEx::InPoint(int64_t pointid, const NFPoint3<float>& pos)
{
    auto pcfg = GetPointCfg(pointid);
    if (nullptr != pcfg)
    {
        for (auto& iter : pcfg->vecposcfg)
        {
            if (NFMath::InCircle(iter.m_pos, pos, 3.5))
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

bool MapDescEx::IsCrossBossDupMap(int64_t mapId)
{
    return false;
}

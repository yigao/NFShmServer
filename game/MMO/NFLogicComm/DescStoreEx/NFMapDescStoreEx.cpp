// -------------------------------------------------------------------------
//    @FileName         :    NFMapDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFMapDescStoreEx.h"
#include "NFComm/NFPluginModule/NFCheck.h"

#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "common_logic.pb.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFLogicCommon/NFMath.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFMapDescStoreEx, EOT_CONST_MAP_CONFIG_DESCEX_ID, NFShmObj)

NFMapDescStoreEx::NFMapDescStoreEx() : NFIDescStore()
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

NFMapDescStoreEx::~NFMapDescStoreEx()
{
}

int NFMapDescStoreEx::CreateInit()
{
    return 0;
}

int NFMapDescStoreEx::ResumeInit()
{
    return 0;
}

int NFMapDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR_ASSERT(MapMapDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      MapMapDesc::Instance(m_pObjPluginManager)->GetFileName());
    CHECK_EXPR_ASSERT(RoleBornDesc::Instance(m_pObjPluginManager)->IsLoaded(), -1, "must load descstore:{}",
                      RoleBornDesc::Instance(m_pObjPluginManager)->GetFileName());

    Initialize();

    std::string dir = m_pObjPluginManager->GetConfigPath() + "/Json/";

    auto &mapResDesc = MapMapDesc::Instance(m_pObjPluginManager)->GetResDesc();
    for (int i = 0; i < (int) mapResDesc.size(); i++)
    {
        auto pDesc = &mapResDesc[i];
        if (pDesc)
        {
            LoadBornCfg(pDesc->m_mapid, dir + NFCommon::tostr(pDesc->m_mapid) + ".json");
        }
    }

    auto &bornResDesc = RoleBornDesc::Instance(m_pObjPluginManager)->GetResDesc();
    for (int i = 0; i < (int) bornResDesc.size(); i++)
    {
        auto pDesc = &bornResDesc[i];
        if (pDesc)
        {
            CHECK_EXPR_ASSERT(m_bornProfMap.Find(pDesc->m_professionid) == NULL, -1, "m_bornProfMap Repeated role prof:{} born:{}", pDesc->m_professionid,
                              pDesc->m_bornid);
            auto pId = m_bornProfMap.Insert(pDesc->m_professionid);
            CHECK_EXPR_ASSERT(pId != NULL, -1, "m_bornProfMap Space Not Enough prof:{} born:{}", pDesc->m_professionid, pDesc->m_bornid);
            *pId = pDesc->m_bornid;
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFMapDescStoreEx::LoadBornCfg(uint64_t mapId, const std::string &file)
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

        for (int i = 0; i < (int) jsonConfig.objs_size(); i++)
        {
            auto &obj = jsonConfig.objs(i);
            if (obj.id() == mapId)
            {
                CHECK_EXPR_ASSERT(!m_bornPosMap.IsFull(), -1, "m_bornPosMap Full, the hashmap space not enough, bornId:{}", obj.id());
                CHECK_EXPR_ASSERT(m_bornPosMap.Find(obj.id()) == NULL, -1, "file:{} exist repeated bornId:{}", file, obj.id());
                auto pBornArray = m_bornPosMap.Insert(obj.id());
                CHECK_EXPR_ASSERT(pBornArray, -1, "m_bornPosMap.Insert Failed bornId:{}", obj.id());
                for (int j = 0; j < (int) obj.pos_size(); j++)
                {
                    auto pPos = pBornArray->Add();
                    pPos->m_pos.x = obj.pos(j).pos().x();
                    pPos->m_pos.y = obj.pos(j).pos().y();
                    pPos->m_pos.z = obj.pos(j).pos().z();
                    pPos->m_dir = obj.pos(j).rot();
                }
            }

            {
                CHECK_EXPR_ASSERT(!m_pointMap.IsFull(), -1, "m_posMap Full, the hashmap space not enough, bornId:{}", obj.id());
                CHECK_EXPR_ASSERT(m_pointMap.Find(obj.id()) == NULL, -1, "file:{} exist repeated bornId:{}", file, obj.id());
                auto pPosArray = m_pointMap.Insert(obj.id());
                CHECK_EXPR_ASSERT(pPosArray, -1, "m_posMap.Insert Failed bornId:{}", obj.id());
                CHECK_EXPR_ASSERT((int) pPosArray->GetMaxSize() >= (int) obj.pos_size(), -1, "m_posMap pos array space not enough, bornId:{}, pos size:{}",
                                  obj.id(), obj.pos_size());
                pPosArray->SetSize(obj.pos_size());
                for (int j = 0; j < (int) obj.pos_size(); j++)
                {
                    auto pPos = pPosArray->Get(j);
                    pPos->m_pos.x = obj.pos(j).pos().x();
                    pPos->m_pos.y = obj.pos(j).pos().y();
                    pPos->m_pos.z = obj.pos(j).pos().z();
                    pPos->m_dir = obj.pos(j).rot();
                }
            }
        }

        for (int i = 0; i < (int) jsonConfig.paths_size(); i++)
        {
            auto &pathConfig = jsonConfig.paths(i);
            CHECK_EXPR_ASSERT(!m_pathMap.IsFull(), -1, "m_pathMap Full, the hashmap space not enough, pathId:{}", pathConfig.id());
            CHECK_EXPR_ASSERT(m_pathMap.Find(pathConfig.id()) == NULL, -1, "file:{} exist repeated pathId:{}", file, pathConfig.id());
            auto pPath = m_pathMap.Insert(pathConfig.id());
            CHECK_EXPR_ASSERT(pPath, -1, "m_pathMap.Insert Failed bornId:{}", pathConfig.id());
            pPath->m_id = pathConfig.id();
            pPath->m_mapId = mapId;
            CHECK_EXPR_ASSERT((int) pPath->m_pathCfg.GetMaxSize() >= (int) pathConfig.pos_size(), -1,
                              "m_pathMap pos array space not enough, pathId:{}", file, pathConfig.id());
            pPath->m_pathCfg.SetSize(pathConfig.pos_size());
            for (int j = 0; j < (int) pathConfig.pos_size(); j++)
            {
                auto pPos = pPath->m_pathCfg.Get(j);
                pPos->x = pathConfig.pos(j).x();
                pPos->y = pathConfig.pos(j).y();
                pPos->z = pathConfig.pos(j).z();
            }
        }

        for (int i = 0; i < (int) jsonConfig.areas_size(); i++)
        {
            auto &areaConfig = jsonConfig.areas(i);
            CHECK_EXPR_ASSERT(!m_areaMap.IsFull(), -1, "m_areaMap Full, the hashmap space not enough, areaId:{}", areaConfig.id());
            CHECK_EXPR_ASSERT(m_areaMap.Find(areaConfig.id()) == NULL, -1, "file:{} exist repeated areaId:{}", file, areaConfig.id());
            auto pArea = m_areaMap.Insert(areaConfig.id());
            CHECK_EXPR_ASSERT(pArea, -1, "m_areaMap.Insert Failed areaId:{}", areaConfig.id());
            pArea->m_id = areaConfig.id();
            pArea->m_mapId = mapId;
            CHECK_EXPR_ASSERT((int) pArea->m_areaCfg.GetMaxSize() >= (int) areaConfig.detail_size(), -1,
                              "m_areaMap pos array space not enough, areaId:{}", areaConfig.id());
            pArea->m_areaCfg.SetSize(areaConfig.detail_size());
            for (int j = 0; j < (int) areaConfig.detail_size(); j++)
            {
                auto pPos = pArea->m_areaCfg.Get(j);
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
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "ReadFileContent Failed, file:{}", file);
    }
    return -1;
}

int NFMapDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}

int32_t NFMapDescStoreEx::BornPointCount(int64_t mapId)
{
    auto pVecBorn = GetBornPosCfg(mapId);
    if (pVecBorn)
    {
        return pVecBorn->GetSize();
    }
    return 0;
}

const NFPoint3<float> *NFMapDescStoreEx::RandBornPoint(int64_t mapId)
{
    auto pVecBorn = GetBornPosCfg(mapId);
    if (pVecBorn)
    {
        int idx = NFRandInt((int) 0, (int) pVecBorn->GetSize());
        auto pPos = pVecBorn->Get(idx);
        if (pPos)
        {
            return &pPos->m_pos;
        }
    }
    return NULL;
}

const VecPosCfg *NFMapDescStoreEx::GetBornPosCfg(int64_t mapId)
{
    return m_bornPosMap.Find(mapId);
}

const proto_ff_s::E_RoleBorn_s *NFMapDescStoreEx::GetBornCfg(int32_t prof)
{
    auto pBornId = m_bornProfMap.Find(prof);
    if (pBornId)
    {
        return RoleBornDesc::Instance(m_pObjPluginManager)->GetDesc(*pBornId);
    }
    return NULL;
}

bool NFMapDescStoreEx::IsDynamic(int64_t mapId)
{
    auto pMapCfg = MapMapDesc::Instance(m_pObjPluginManager)->GetDesc(mapId);
    if (pMapCfg)
    {
        return (DYNAMIC_MAP == pMapCfg->m_maptype);
    }

    return false;
}

bool NFMapDescStoreEx::IsActSpecMap(int64_t mapId)
{
    return false;
}

const VecPosCfg *NFMapDescStoreEx::GetPointCfg(int64_t id)
{
    return m_pointMap.Find(id);
}

const NFPathCfg *NFMapDescStoreEx::GetPathCfg(int64_t id)
{
    return m_pathMap.Find(id);
}

const NFAreaCfg *NFMapDescStoreEx::GetAreaCfg(int64_t id)
{
    return m_areaMap.Find(id);
}

bool NFMapDescStoreEx::InArea(int64_t areaid, const NFPoint3<float> &pos)
{
    const NFAreaCfg *pCfg = GetAreaCfg(areaid);
    if (nullptr != pCfg)
    {
        for (int i = 0; i < (int) pCfg->m_areaCfg.GetSize(); i++)
        {
            const NFAreaPosCfg *pPos = pCfg->m_areaCfg.Get(i);
            if (NFMath::InCircle(pPos->m_circle, pos, (pPos->m_radius + 0.5)))
            {
                return true;
            }
        }
        return false;
    }

    return false;
}

bool NFMapDescStoreEx::RandPosInArea(int64_t areaid, NFPoint3<float> &outpos)
{
    const NFAreaCfg *pcfg = GetAreaCfg(areaid);
    if (nullptr == pcfg) return false;

    uint32_t nsize = (uint32_t) pcfg->m_areaCfg.GetSize();
    if (nsize <= 0) return false;

    uint32_t idx = NFRandInt((uint32_t)0, nsize); //0 - (nsize-1)
    const NFAreaPosCfg &area = pcfg->m_areaCfg[idx];
    float radius = (float) (NFRandInt((uint32_t)1, (uint32_t) (area.m_radius * 1000)) / 1000.0f);
    float angle = (float) (NFRandInt(0, 360 * 1000)) / 1000.0f;
    outpos.x = area.m_circle.x + radius * cos(angle);
    outpos.y = area.m_circle.y;
    outpos.z = area.m_circle.z + radius * sin(angle);
    return true;
}




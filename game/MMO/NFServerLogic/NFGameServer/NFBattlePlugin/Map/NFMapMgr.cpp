// -------------------------------------------------------------------------
//    @FileName         :    NFMapMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapMgr
//
// -------------------------------------------------------------------------

#include "NFMapMgr.h"
#include "DescStore/MapMapDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFMap.h"
#include "NFComm/NFCore/NFRandom.hpp"

IMPLEMENT_IDCREATE_WITHTYPE(NFMapMgr, EOT_GAME_MAP_MGR_ID, NFShmObj)

NFMapMgr::NFMapMgr() : NFShmObj()
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

NFMapMgr::~NFMapMgr()
{
}

int NFMapMgr::CreateInit()
{
    m_mapNavMesh.CreateInit();
    return 0;
}

int NFMapMgr::ResumeInit()
{
    m_mapNavMesh.CreateInit();
    return 0;
}

NFNavMeshInfo *NFMapMgr::AddNavMeshInfo(const std::string &navName)
{
    NFShmString<MAP_NAME_MAX_LENGHT> name;
    name.Copy(navName);
    return m_mapNavMesh.Insert(name);
}

NFNavMeshInfo *NFMapMgr::GetNavMeshInfo(const std::string &navName)
{
    NFShmString<MAP_NAME_MAX_LENGHT> name;
    name.Copy(navName);
    return m_mapNavMesh.Find(name);
}

int NFMapMgr::LoadConfig()
{
    FindModule<NFISharedMemModule>()->ClearAllObj(EOT_GAME_MAP_ID);
    CreateInit();
    auto &arrayMap = MapMapDesc::Instance(m_pObjPluginManager)->GetResDesc();
    for (int i = 0; i < (int) arrayMap.size(); i++)
    {
        auto &info = arrayMap[i];
        NFMap* pMap = CreateMap(info.m_mapid);
        CHECK_EXPR_ASSERT(pMap, -1, "CreateMap Failed, mapId:{}", info.m_mapid);
    }
    return 0;
}

NFMap *NFMapMgr::GetMap(uint64_t mapId)
{
    return dynamic_cast<NFMap *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(mapId, EOT_GAME_MAP_ID));
}

NFMap *NFMapMgr::CreateMap(uint64_t mapId)
{
    NFMap *pMap = GetMap(mapId);
    CHECK_EXPR(pMap == NULL, NULL, "CreateMap Failed, map exist, mapId:{}", mapId);

    pMap = dynamic_cast<NFMap *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(mapId, EOT_GAME_MAP_ID));
    CHECK_EXPR(pMap, NULL, "Create Map Obj Failed, mapId:{}", mapId);

    int iRet = pMap->Init(mapId);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "NFMap Init Failed! mapId:{}", mapId);
        DeleteMap(pMap);
        return NULL;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, mapId, "Create Map Success, mapId:{} globalId:{}", mapId, pMap->GetGlobalID());
    return pMap;
}

int NFMapMgr::DeleteMap(NFMap *pMap)
{
    CHECK_NULL(pMap);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Map Info, mapId:{}, gloablId:{}", pMap->GetMapId(),
              pMap->GetGlobalID());

    FindModule<NFISharedMemModule>()->DestroyObj(pMap);

    return 0;
}

int NFMapMgr::ClearAllMap()
{
    FindModule<NFISharedMemModule>()->ClearAllObj(EOT_GAME_MAP_ID);
    return 0;
}

NFPoint3<float> NFMapMgr::RandPosAroundPos(uint64_t mapId, const NFPoint3<float> &pos, uint32_t nRadius)
{
    NFMap *pMap = GetMap(mapId);
    if (pMap)
    {
        int32_t nDeltaX = NFRandInt((int32_t)0, (int32_t)nRadius) * (NFRandInt(0, 100) % 2 == 0 ? 1 : -1);
        int32_t nDeltaZ = NFRandInt((int32_t)0, (int32_t)nRadius) * (NFRandInt(0, 100) % 2 == 0 ? 1 : -1);
        NFPoint3<float> destPos = pos;
        destPos.x += nDeltaX;
        destPos.z += nDeltaZ;
        if (pMap->FindNearestPos(destPos.x, destPos.z, destPos.y, &destPos.x, &destPos.z, &destPos.y, nullptr))
        {
            return destPos;
        }
    }
    return pos;
}

// -------------------------------------------------------------------------
//    @FileName         :    NFMap.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMap
//
// -------------------------------------------------------------------------

#include "NFMap.h"
#include "DescStore/MapMapDesc.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFMapMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFGameCommon/NFRecastUtility.h"
#include "NFGameCommon/NFMath.h"
#include "DescStoreEx/MapDescEx.h"
#include <float.h>

IMPLEMENT_IDCREATE_WITHTYPE(NFMap, EOT_GAME_MAP_ID, NFShmObj)

NFMap::NFMap() : NFShmObj()
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

NFMap::~NFMap()
{
    if (m_navMesh)
    {
        MMO_FREE_NAVMESH(m_navMesh);
    }

    if (m_navMeshQuery)
    {
        MMO_FREE_NAVMESHQUERY(m_navMeshQuery);
    }

    if (m_normalFilter)
    {
        NF_SAFE_DELETE(m_normalFilter);
    }
}

int NFMap::CreateInit()
{
    m_mapId = 0;
    ///////////////////////////////地图信息，服务器崩溃后需要修复////////////////////////////
    m_navMesh = NULL;
    m_navMeshQuery = NULL;
    for (int i = 0; i < (int) proto_ff::MAX_NAV_POLYS; i++)
    {
        m_pathPolys[i] = 0;
    }

    for (int i = 0; i < (int) proto_ff::MAX_NAV_POINT_VALUE; i++)
    {
        m_straightPathPoints[i] = 0;
    }
    m_name.CreateInit();
    m_normalFilter = NF_NEW dtQueryFilter();
    ///////////////////////////////地图信息，服务器崩溃后需要修复////////////////////////////
    return 0;
}

int NFMap::ResumeInit()
{
    CreateInit();
    return 0;
}

int NFMap::Init(uint64_t mapId)
{
    m_mapId = mapId;
    Init();
    return 0;
}

int NFMap::Init()
{
    int retCode = 0;

    auto pMapCfg = MapMapDesc::Instance()->GetDesc(m_mapId);
    if (nullptr == pMapCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "MapMapDesc GetDesc Failed:{}", m_mapId);
        return -1;
    }

    retCode = LoadNavMesh(pMapCfg->m_mapresources.ToString());
    CHECK_RET(retCode, "_LoadNavMesh Failed, mapId:{} mapResource:{}", m_mapId, pMapCfg->m_mapresources.ToString());

    //关闭所有行走开发
    m_normalFilter->setIncludeFlags(0);

    //开启行走开发
    m_normalFilter->setIncludeFlags(m_normalFilter->getIncludeFlags() | proto_ff::SAMPLE_POLYFLAGS_WALK);

    //关闭执行开关
    m_normalFilter->setExcludeFlags(0);

    return 0;
}

int NFMap::LoadNavMesh(const std::string &name)
{
    int retCode = 0;

    std::string path = NF_FORMAT("{}/{}/{}.bytes", m_pObjPluginManager->GetConfigPath(), "Map", name);
    dtStatus status;

    MMO_FREE_NAVMESHQUERY(m_navMeshQuery);
    MMO_FREE_NAVMESH(m_navMesh);

    auto *pNav = NFMapMgr::Instance(m_pObjPluginManager)->GetNavMeshInfo(name);
    if (!pNav)
    {
        retCode = NFRecastUtility::LoadNavMeshByJsonFile(path, &m_navMesh);
        CHECK_RET_ASSERT(retCode, "LoadNavMeshByJsonFile failed....path:{} ", path);

        m_navMeshQuery = dtAllocNavMeshQuery();
        CHECK_EXPR_ASSERT(m_navMeshQuery, -1, "dtAllocNavMeshQuery failed....path:{} ", path);

        status = m_navMeshQuery->init(m_navMesh, proto_ff::MAX_NAV_POLYS);
        CHECK_EXPR_ASSERT(dtStatusSucceed(status), -1, "m_navMeshQuery->init Failed");

        pNav = NFMapMgr::Instance(m_pObjPluginManager)->AddNavMeshInfo(name);
        CHECK_EXPR_ASSERT(pNav, -1, "AddNavMeshInfo Failed");
        pNav->pdtNavMesh = m_navMesh;
        pNav->pdtNavMeshQuery = m_navMeshQuery;
    }
    else
    {
        m_navMesh = pNav->pdtNavMesh;
        m_navMeshQuery = pNav->pdtNavMeshQuery;
    }

    return 0;
}

dtPolyRef NFMap::GetNearestPoly2D(float posX, float posY, float *extents, float *nearestPt)
{
    dtPolyRef nearestRef = proto_ff::INVALID_NAVMESH_POLYREF;
    float center[3];
    dtPolyRef nearest = 0;
    float nearestDistanceSqr = FLT_MAX;
    float maxHeight = 0.0f;

    if (extents == nullptr) return nearestRef;

    extents[1] = 2000.0f;
    dtVset(center, posX, 0.0f, posY);

    dtPolyRef polys[128];
    int polyCount = 0;
    if (dtStatusFailed(m_navMeshQuery->queryPolygons(center, extents, m_normalFilter, polys, &polyCount, 128)))
    {
        return nearestRef;
    }

    // Find nearest polygon amongst the nearby polygons.
    nearest = 0;
    nearestDistanceSqr = FLT_MAX;

    for (int i = 0; i < polyCount; ++i)
    {
        dtPolyRef ref = polys[i];
        float closestPtPoly[3];
        float closetPtPoly2D[3];
        float diff[3];
        bool posOverPoly = false;
        float d = 0;
        m_navMeshQuery->closestPointOnPoly(ref, center, closestPtPoly, &posOverPoly);

        // 不计入高度
        dtVset(closetPtPoly2D, closestPtPoly[0], 0.0f, closestPtPoly[2]);

        // If a point is directly over a polygon and closer than
        // climb height, favor that instead of straight line nearest point.
        dtVsub(diff, center, closetPtPoly2D);
        if (posOverPoly)
        {
            const dtMeshTile *tile = 0;
            const dtPoly *poly = 0;
            m_navMesh->getTileAndPolyByRefUnsafe(polys[i], &tile, &poly);
            d = dtAbs(diff[1]) - tile->header->walkableClimb;
            d = d > 0 ? d * d : 0;
        }
        else
        {
            d = dtVlenSqr(diff);
        }

        if (d < nearestDistanceSqr || (dtAbs(d - nearestDistanceSqr) < 0.00001f && maxHeight < closestPtPoly[1]))
        {
            if (nearestPt)
            {
                dtVcopy(nearestPt, closestPtPoly);
                maxHeight = closestPtPoly[1];
            }
            nearestDistanceSqr = d;
            nearest = ref;
        }
    }
    nearestRef = nearest;

    return nearestRef;
}

uint64_t NFMap::GetMapId() const
{
    return m_mapId;
}

uint32_t NFMap::GetWidth() const
{
    auto pCfg = GetMapCfg();
    CHECK_EXPR(pCfg, 0, "");
    return pCfg->m_mapwide;
}

uint32_t NFMap::GetHeight() const
{
    auto pCfg = GetMapCfg();
    CHECK_EXPR(pCfg, 0, "");
    return pCfg->m_mapheight;
}

uint32_t NFMap::GetMapType() const
{
    auto pCfg = GetMapCfg();
    CHECK_EXPR(pCfg, 0, "");
    return pCfg->m_maptype;
}

uint32_t NFMap::GetMapSubType() const
{
    auto pCfg = GetMapCfg();
    CHECK_EXPR(pCfg, 0, "");
    return pCfg->m_mapsubtype;
}

bool NFMap::IsDynamic() const
{
    return MapDescEx::Instance()->IsDynamic(m_mapId);
}

bool NFMap::IsMainCity() const
{
    return MapDescEx::Instance()->IsMainCity(m_mapId);
}

const proto_ff_s::E_MapMap_s *NFMap::GetMapCfg() const
{
    return MapMapDesc::Instance()->GetDesc(m_mapId);
}

int NFMap::GetNavPath(const float *srcPos, const float *dstPos, VEC_POINT3 &path, VEC_FLAGS &flags)
{
    CHECK_NULL(srcPos);
    CHECK_NULL(dstPos);
    CHECK_NULL(m_navMesh);
    CHECK_NULL(m_navMeshQuery);

    int retCode = 0;

    int nPolys = 0;
    int nStraightPoints = 0;
    dtStatus status;

    float nearStartPos[3];
    float nearEndPos[3];

    dtPolyRef startRef = proto_ff::INVALID_NAVMESH_POLYREF;
    dtPolyRef endRef = proto_ff::INVALID_NAVMESH_POLYREF;

    unsigned char straightPathFlags[proto_ff::MAX_NAV_POLYS];
    dtPolyRef straightPathPolys[proto_ff::MAX_NAV_POLYS];

    retCode = FindNearestPos(srcPos[0], srcPos[2], srcPos[1], &nearStartPos[0], &nearStartPos[2], &nearStartPos[1], &startRef);
    CHECK_RET(retCode, "FindNearestPos Failed, x:{} y:{} z:{}", srcPos[0], srcPos[2], srcPos[1]);

    retCode = FindNearestPos(dstPos[0], dstPos[2], dstPos[1], &nearEndPos[0], &nearEndPos[2], &nearEndPos[1], &endRef);
    CHECK_RET(retCode, "FindNearestPos Failed, x:{} y:{} z:{}", dstPos[0], dstPos[2], dstPos[1]);

    status = m_navMeshQuery->findPath(startRef, endRef, nearStartPos, nearEndPos, m_normalFilter, m_pathPolys, &nPolys, proto_ff::MAX_NAV_POLYS);
    CHECK_EXPR(dtStatusSucceed(status) && (status & DT_PARTIAL_RESULT) == 0, -1, "findPath Failed");
    CHECK_EXPR(nPolys > 0, -1, "nPolys:{} Error", nPolys);

    //fix add by lian In case of partial path, make sure the end point is clamped to the last polygon.
    float epos[3];
    dtVcopy(epos, nearEndPos);
    if (m_pathPolys[nPolys - 1] != endRef)
    {
        m_navMeshQuery->closestPointOnPoly(m_pathPolys[nPolys - 1], nearEndPos, epos, 0);
    }

    status = m_navMeshQuery->findStraightPath(nearStartPos, epos, m_pathPolys, nPolys, m_straightPathPoints, straightPathFlags, straightPathPolys,
                                              &nStraightPoints, proto_ff::MAX_NAV_POLYS);
    CHECK_EXPR(dtStatusSucceed(status), -1, "");

    path.clear();
    flags.clear();
    path.resize(nStraightPoints);
    flags.resize(nStraightPoints);

    for (int i = 0, j = 0; i < nStraightPoints * 3; i += 3, j++)
    {
        path[j].x = m_straightPathPoints[i + 0];
        path[j].y = m_straightPathPoints[i + 1];
        path[j].z = m_straightPathPoints[i + 2];
        flags[j] = straightPathFlags[j];
    }

    return true;
}

int NFMap::GetIntNavPath(const float *srcPos, const float *dstPos, VEC_PATH &IntPath)
{
    CHECK_NULL(srcPos);
    CHECK_NULL(dstPos);

    int retCode = 0;

    VEC_POINT3 path = {};
    VEC_FLAGS flgs = {};
    NFPoint3<uint32_t> pathPoint;

    retCode = GetNavPath(srcPos, dstPos, path, flgs);
    CHECK_RET(retCode, "GetNavPath Failed");

    for (size_t i = 0; i < path.size(); i++)
    {
        pathPoint.x = uint32_t(path[i].x * 1000);
        pathPoint.y = uint32_t(path[i].y * 1000);
        pathPoint.z = uint32_t(path[i].z * 1000);
        IntPath.push_back(pathPoint);
    }

    return true;
}

dtPolyRef NFMap::GetNearestPoly(float posX, float posY, float posH, float *extents, float *nearPoint)
{
    dtPolyRef polyRef = proto_ff::INVALID_NAVMESH_POLYREF;
    float startPos[3];

    if (extents == nullptr) return polyRef;

    extents[1] = 2000.0f;
    dtVset(startPos, posX, posH, posY);

    // 使用重写的忽略高度的最近poly查找函数
    if (posH >= -0.00001f && posH <= 0.00001f)
    {
        return GetNearestPoly2D(posX, posY, extents, nearPoint);
    }

    m_navMeshQuery->findNearestPoly(startPos, extents, m_normalFilter, &polyRef, nearPoint);
    return polyRef;
}

int NFMap::FindNearestPos(float posX, float posY, float posH, float *rsPosX, float *rsPosY, float *rsPosH, dtPolyRef *rsPolyRef)
{
    dtPolyRef polyRef = proto_ff::INVALID_NAVMESH_POLYREF;
    float extents[3] = {0.5f, 4.0f, 0.5f};
    float nearPoint[3] = {0.0f};

    polyRef = GetNearestPoly(posX, posY, posH, extents, nearPoint);
    CHECK_EXPR(polyRef != proto_ff::INVALID_NAVMESH_POLYREF, false, "GetNearestPoly Failed");

    if (rsPosX != nullptr)
    {
        *rsPosX = nearPoint[0];
    }
    if (rsPosY != nullptr)
    {
        *rsPosY = nearPoint[2];
    }
    if (rsPosH != nullptr)
    {
        *rsPosH = nearPoint[1];
    }
    if (rsPolyRef != nullptr)
    {
        *rsPolyRef = polyRef;
    }

    return true;
}

int NFMap::Raycast(float *startPos, float dir, float length, HitWallParam *hitParam)
{
    CHECK_NULL(startPos);
    CHECK_NULL(hitParam);

    int retCode = 0;

    dtPolyRef startRef = proto_ff::INVALID_NAVMESH_POLYREF;
    dtStatus status;
    float nearPos[3] = {0.0f};
    float endPos[3] = {0.0f};
    float hitNormal[3] = {0.0f};
    float t = 0.0f;
    int polyCount = 0;
    float radian = 0.0f;
    NFPoint2<float> offsetLength;

    radian = NFMath::AngleToRadian(NFMath::ReviseDir(dir));
    NFMath::FormulaPos(radian, length, &offsetLength);

    dtVset(endPos, startPos[0] + offsetLength.x, 0.0f, startPos[2] + offsetLength.y);

    retCode = FindNearestPos(startPos[0], startPos[2], startPos[1], &nearPos[0], &nearPos[2], &nearPos[1], &startRef);
    CHECK_RET(retCode, "FindNearestPos Failed");

    status = m_navMeshQuery->raycast(startRef, nearPos, endPos, m_normalFilter,
                                     &t, hitNormal, m_pathPolys, &polyCount, proto_ff::MAX_NAV_POLYS);

    CHECK_EXPR(dtStatusSucceed(status), -1, "raycast Failed");

    hitParam->pathPolys = m_pathPolys;
    hitParam->polyCount = polyCount;

    if (t > 1.0f)
    {
        dtVcopy(hitParam->hitPos, endPos);
        hitParam->hitPos[1] = startPos[1];

        hitParam->hitLength  = 0.0f;
        hitParam->tangentDir = 0.0f;

        NF_ASSERT(polyCount > 0);

        if (polyCount > 0)
        {
            hitParam->hitRef = m_pathPolys[polyCount - 1];
            GetPolyHeight(hitParam->hitRef, hitParam->hitPos[0], hitParam->hitPos[2], &hitParam->hitPos[1]);
        }

        return true;
    }

    if (t > 0.01 && t < 1.0f)
    {
        dtVlerp(hitParam->hitPos, nearPos, endPos, t);
        hitParam->hitPos[1] = startPos[1];
        hitParam->hitLength = (1 - t) * length;

        NF_ASSERT(polyCount > 0);

        if (polyCount > 0)
        {
            hitParam->hitRef = m_pathPolys[polyCount - 1];
            GetPolyHeight(hitParam->hitRef, hitParam->hitPos[0], hitParam->hitPos[2], &hitParam->hitPos[1]);
        }
    }
    else
    {
        dtVcopy(hitParam->hitPos, startPos);
        hitParam->hitLength = length;
        hitParam->hitRef = startRef;
    }

    // 计算碰撞切线方向
    if (t > 0.0f)
    {
        float tangenDir = 0.0f;
        NFPoint2<float> from = { 0.0f, 0.0f };
        NFPoint2<float> to = { hitNormal[0], hitNormal[2] };
        float normalDir = NFMath::Angle2D(from, to); // 碰撞法线
        float detaDir = NFMath::DeltaAngle(normalDir, dir); // 当前方向和法线的夹角

        if (detaDir > 90.0f && detaDir <= 180.0f)
        {
            tangenDir = NFMath::ReviseDir(dir - (detaDir - 90.0f) - 2.0f);
        }
        else if (detaDir > 180.0f && detaDir <= 270.0f)
        {
            tangenDir = NFMath::ReviseDir(dir + (270.0f - detaDir) + 2.0f);
        }

        hitParam->tangentDir = tangenDir;
    }

    return true;
}

int NFMap::GetHitWallTangentAngle(float hitX, float hitY, float hitH, float dir, float *rsTangentDir)
{
    // hitX hitY 为墙上的点

    bool retCode = false;

    dtPolyRef startRef = proto_ff::INVALID_NAVMESH_POLYREF;
    dtStatus status;
    float nearPos[3] = {0.0f};
    float centerPos[3] = {0.0f};
    float endPos[3] = {0.0f};
    float hitNormal[3] = {0.0f};
    float t = 0.0f;
    int polyCount = 0;
    float radian = 0.0f;
    NFPoint2<float> offsetForward;
    const dtMeshTile* tile = nullptr;
    const dtPoly* poly = nullptr;
    NFPoint2<float> from;
    NFPoint2<float> to;

    CHECK_NULL(rsTangentDir);
    CHECK_NULL(m_navMesh);

    retCode = FindNearestPos(hitX, hitY, hitH, &nearPos[0], &nearPos[2], &nearPos[1], &startRef);
    CHECK_EXPR(retCode, false, "FindNearestPos error");

    m_navMesh->getTileAndPolyByRefUnsafe(startRef, &tile, &poly);
    dtCalcPolyCenter(centerPos, poly->verts, poly->vertCount, tile->verts);

    from.x = centerPos[0];
    from.y = centerPos[2];
    to.x = hitX;
    to.y = hitY;
    //Point2<float> from = { centerPos[0], centerPos[2] };
    //Point2<float> to = { hitX, hitY };
    radian = NFMath::AngleToRadian(NFMath::ReviseDir(NFMath::Angle2D(from, to)));
    NFMath::FormulaPos(radian, 1.5f, &offsetForward);
    dtVset(endPos, hitX + offsetForward.x, 0.0f, hitY + offsetForward.y);

    status = m_navMeshQuery->raycast(startRef, centerPos, endPos, m_normalFilter,
                                     &t, hitNormal, m_pathPolys, &polyCount, proto_ff::MAX_NAV_POLYS);

    CHECK_EXPR(dtStatusSucceed(status), -1, "");
    CHECK_EXPR(t > 0.0f && t < 1.0f, -1, "");

    // 计算碰撞切线方向
    {
        float tangenDir = 0.0f;
        from.x = 0;
        from.y = 0;
        to.x = hitNormal[0];
        to.y = hitNormal[2];
        /*	Point2<float> from1 = { 0, 0 };
            Point2<float> to1 = { hitNormal[0], hitNormal[2] };*/
        float normalDir = NFMath::Angle2D(from, to); // 碰撞法线
        float detaDir = NFMath::DeltaAngle(normalDir, dir); // 当前方向和法线的夹角

        if (detaDir > 90.0f && detaDir <= 180.0f)
        {
            tangenDir = NFMath::ReviseDir(dir - (detaDir - 90.0f) - 2.0f);
        }
        else if (detaDir > 180.0f && detaDir <= 270.0f)
        {
            tangenDir = NFMath::ReviseDir(dir + (270.0f - detaDir) + 2.0f);
        }

        *rsTangentDir = tangenDir;
    }

    return true;
}

int NFMap::GetPolyHeight(dtPolyRef polyRef, float posX, float posY, float *height)
{
    CHECK_NULL(height);

    float h = 0;
    float pos[3] = {posX, 0.0f, posY};

    dtStatus status = m_navMeshQuery->getPolyHeight(polyRef, pos, &h);
    CHECK_EXPR(dtStatusSucceed(status), -1, "getPolyHeight failed");

    if (height != nullptr)
    {
        *height = h;
    }

    return true;
}

int NFMap::CheckPolyFlag(dtPolyRef polyRef, proto_ff::SamplePolyFlags flag)
{
    unsigned short flags = 0;

    dtStatus status = m_navMesh->getPolyFlags(polyRef, &flags);
    CHECK_EXPR(dtStatusSucceed(status), false, "getPolyFlags failed");
    CHECK_EXPR(flags & flag, false, "");
    return true;
}

void NFMap::GetPolyFlags(dtPolyRef ref, uint_least16_t *flags)
{
    m_navMesh->getPolyFlags(ref, flags);
}

bool NFMap::IsInSafeArea(NFPoint3<float> &nPos)
{
    return false;
}

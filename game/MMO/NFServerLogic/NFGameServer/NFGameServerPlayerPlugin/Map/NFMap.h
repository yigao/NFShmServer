// -------------------------------------------------------------------------
//    @FileName         :    NFMap.h
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMap
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

#include "Detour/Include/DetourNavMesh.h"
#include "Detour/Include/DetourNavMeshQuery.h"

#include "NFLogicCommon/NFSceneDefine.h"
#include "NFComm/NFShmStl/NFShmString.h"
#include "ComDefine.pb.h"
#include "E_Map_s.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"

class NFMap : public NFShmObjTemplate<NFMap, EOT_GAME_MAP_ID, NFShmObj>
{
public:
    NFMap();
    
    virtual ~NFMap();
    
    int CreateInit();
    
    int ResumeInit();

public:
    uint64_t GetMapId() const;
    
    uint32_t GetWidth() const;
    
    uint32_t GetHeight() const;
    
    uint32_t GetMapType() const;
    
    uint32_t GetMapSubType() const;
    
    bool IsDynamic() const;
    
    bool IsMainCity() const;
public:
    /**
     * @brief
     * @return
     */
    const proto_ff_s::E_MapMap_s *GetMapCfg() const;
    
    /**
     * @brief
     * @param srcPos
     * @param dstPos
     * @param path
     * @param flags
     * @return
     */
    int GetNavPath(const float *srcPos, const float *dstPos, VEC_POINT3 &path, VEC_FLAGS &flags);
    
    /**
     * @brief
     * @param srcPos
     * @param dstPos
     * @param IntPath
     * @return
     */
    int GetIntNavPath(const float *srcPos, const float *dstPos, VEC_PATH &IntPath);
    
    /**
     * @brief
     * @param posX
     * @param posY
     * @param posH
     * @param extents
     * @param nearPoint
     * @return
     */
    dtPolyRef GetNearestPoly(float posX, float posY, float posH, float *extents, float *nearPoint);
    
    /**
     * @brief
     * @param posX
     * @param posY
     * @param posH
     * @param rsPosX
     * @param rsPosY
     * @param rsPosH
     * @param rsPolyRef
     * @return
     */
    int FindNearestPos(float posX, float posY, float posH, float *rsPosX, float *rsPosY, float *rsPosH,
                       dtPolyRef *rsPolyRef);
    
    /**
     * @brief
     * @param startPos
     * @param dir
     * @param length
     * @param hitParam
     * @return
     */
    int Raycast(float *startPos, float dir, float length, HitWallParam *hitParam);
    
    /**
     * @brief
     * @param hitX
     * @param hitY
     * @param hitH
     * @param dir
     * @param rsTangentDir
     * @return
     */
    int GetHitWallTangentAngle(float hitX, float hitY, float hitH, float dir, float *rsTangentDir);
    
    /**
     * @brief
     * @param polyRef
     * @param posX
     * @param posY
     * @param height
     * @return
     */
    int GetPolyHeight(dtPolyRef polyRef, float posX, float posY, float *height);
    
    /**
     * @brief
     * @param polyRef
     * @param flag
     * @return
     */
    int CheckPolyFlag(dtPolyRef polyRef, proto_ff::SamplePolyFlags flag);
    
    /**
     * @brief
     * @return
     */
    dtNavMesh *GetNavMesh() { return m_navMesh; }
    
    /**
     * @brief
     * @param ref
     * @param flags
     */
    void GetPolyFlags(dtPolyRef ref, uint_least16_t *flags);
    
    /**
     * @brief
     * @param nPos
     * @return
     */
    bool IsInSafeArea(NFPoint3<float> &nPos);

public:
    /**
     * @brief
     * @param mapId
     * @return
     */
    int Init(uint64_t mapId);
    
    /**
     * @brief
     * @return
     */
    int Init();

private:
    /**
     * @brief
     * @param name
     * @return
     */
    int LoadNavMesh(const std::string &name);
    
    /**
     * @brief 获取忽略高度值的最近poly，返回值的nearestPt带有高度
     * @param posX
     * @param posY
     * @param extents
     * @param nearestPt
     * @return
     */
    dtPolyRef GetNearestPoly2D(float posX, float posY, float *extents, float *nearestPt);

protected:

protected:
    uint64_t m_mapId;
protected:
    dtNavMesh *m_navMesh;
    dtNavMeshQuery *m_navMeshQuery;
    dtPolyRef m_pathPolys[proto_ff::MAX_NAV_POLYS];
    float m_straightPathPoints[proto_ff::MAX_NAV_POINT_VALUE];
    NFCommonStr m_name;
    dtQueryFilter *m_normalFilter;
};
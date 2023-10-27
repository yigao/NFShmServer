// -------------------------------------------------------------------------
//    @FileName         :    NFMapMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFComm/NFShmStl/NFShmString.h"
#include "NFNavMeshInfo.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"

#define GAME_SERVER_MAX_BATTLE_MAP_SIZE 10

class NFMap;
class NFMapMgr : public NFShmObjTemplate<NFMapMgr, EOT_GAME_MAP_MGR_ID, NFShmObj>
{
public:
    NFMapMgr();

    virtual ~NFMapMgr();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param navName
     * @return
     */
    NFNavMeshInfo* AddNavMeshInfo(const std::string& navName);

    /**
     * @brief
     * @param navName
     * @return
     */
    NFNavMeshInfo* GetNavMeshInfo(const std::string& navName);

public:
    /**
     * @brief 在指定坐标点周围随机一个坐标
     * @param mapId
     * @param pos
     * @param nRadius
     * @return
     */
    NFPoint3<float> RandPosAroundPos(uint64_t mapId, const NFPoint3<float>& pos, uint32_t nRadius);
public:
    /**
     * @brief
     * @return
     */
    int LoadConfig();

public:
    /**
     * @brief
     * @param mapId
     * @return
     */
    NFMap *GetMap(uint64_t mapId);

    /**
     * @brief
     * @param mapId
     * @return
     */
    NFMap *CreateMap(uint64_t mapId);

    /**
     * @brief
     * @param pMap
     * @return
     */
    int DeleteMap(NFMap *pMap);

    /**
     * @brief
     * @return
     */
    int ClearAllMap();
private:
    NFShmHashMap<NFCommonStr, NFNavMeshInfo, GAME_SERVER_MAX_BATTLE_MAP_SIZE> m_mapNavMesh;
};
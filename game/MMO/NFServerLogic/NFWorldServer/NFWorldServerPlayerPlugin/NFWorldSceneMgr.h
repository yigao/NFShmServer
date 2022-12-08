// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSceneMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSceneMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "ServerInternal2.pb.h"

#define NF_WORLD_SERVER_MAX_MAP_NUM 1000
#define NF_WORLD_MAP_ID_MAX_SERVER_NUM 10

class NFWorldSceneMgr : public NFShmObj
{
public:
    NFWorldSceneMgr();

    virtual ~NFWorldSceneMgr();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param xData
     * @return
     */
    int LoadGameMap(const proto_ff::GameToWorldRegisterMapReq& xData);

public:
    bool IsStaticMapId(uint64_t mapId) const;
    uint32_t GetStaticMapGameId(uint64_t mapId) const;
private:
    NFShmHashMap<uint64_t, NFArray<uint32_t, NF_WORLD_MAP_ID_MAX_SERVER_NUM>, NF_WORLD_SERVER_MAX_MAP_NUM> m_mapIdToGameBusIdMap;
    NFShmHashMap<uint64_t, SceneSimpleInfo, NF_WORLD_SERVER_MAX_MAP_NUM*10> m_sceneMap;
private:
DECLARE_IDCREATE(NFWorldSceneMgr)
};
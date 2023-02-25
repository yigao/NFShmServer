// -------------------------------------------------------------------------
//    @FileName         :    NFSceneMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFSceneMgr
//
// -------------------------------------------------------------------------

#pragma once


#include <set>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

#define GAME_SERVER_MAX_BATTLE_SCENE_SIZE 1000

class NFScene;
class NFSceneMgr : public NFShmObj
{
public:
    NFSceneMgr();

    virtual ~NFSceneMgr();

    int CreateInit();

    int ResumeInit();

    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
public:
    /**
     * @brief
     * @param mapIds
     * @return
     */
    int InitScene(const std::set<uint64_t>& mapIds);

public:
    /**
     * @brief
     * @param mapId
     * @param sceneId
     * @return
     */
    NFScene* CreateScene(uint64_t mapId, uint64_t sceneId);

    /**
     * @brief
     * @param sceneId
     * @return
     */
    NFScene* GetScene(uint64_t sceneId);

    /**
     * @brief
     * @param pScene
     * @return
     */
    int DeleteScene(NFScene* pScene);
public:
    /**
     * @brief 是否关闭
     * @param sceneId
     * @return
     */
    bool IsClosed(uint64_t sceneId);
private:
    //场景销毁缓存表 sceneid - tick
    NFShmHashMap<uint64_t, uint64_t, 1000> m_delCacheMap;
private:
DECLARE_IDCREATE(NFSceneMgr)
};
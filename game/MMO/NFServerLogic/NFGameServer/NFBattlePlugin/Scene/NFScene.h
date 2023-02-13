// -------------------------------------------------------------------------
//    @FileName         :    NFScene.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFScene
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFGrid.h"
#include "NFComm/NFShmCore/NFShmOldHashMap.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFShmStl/NFShmVector.h"

#define NF_SCENE_MAX_GRID_NUM 100
#define NF_SCENE_MAX_CREATURE_NUM 1000

class NFScene : public NFShmObj
{
public:
    NFScene();

    virtual ~NFScene();

    int CreateInit();

    int ResumeInit();
public:
    virtual int Init(uint64_t mapId, uint64_t sceneId);
    virtual int UnInit();
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;
    virtual int OnTimer(int timeId, int callcount) override;
public:
    /**
     * @brief
     * @param pCreature
     * @param pos
     * @param transParam
     * @return
     */
    virtual int EnterScene(NFCreature* pCreature, const NFPoint3<float>& pos, STransParam &transParam);
public:
    /**
     * @brief
     * @param pCreature
     */
    int AddCreature(NFCreature* pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemoveCreature(NFCreature* pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int AddPlayer(NFCreature* pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemovePlayer(NFCreature* pCreature);
private:
    uint64_t m_mapId;
    uint64_t m_sceneId;
    uint32_t m_gridMaxWidth;
    uint32_t m_gridMaxHeight;
    NFShmVector<NFShmVector<NFGrid, NF_SCENE_MAX_GRID_NUM>, NF_SCENE_MAX_GRID_NUM> m_gridList;
private:
    NFShmNodeObjMultiList<NFCreature> m_creatureList;
    NFShmNodeObjMultiList<NFCreature> m_playerList;
DECLARE_IDCREATE(NFScene)
};
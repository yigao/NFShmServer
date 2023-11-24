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
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFGrid.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFSkillDefine.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"

#define NF_SCENE_MAX_GRID_NUM 600
#define NF_SCENE_MAX_CREATURE_NUM 1000

class NFMap;

class NFScene : public NFShmObjTemplate<NFScene, EOT_GAME_SCENE_ID, NFShmObj>
{
public:
    NFScene();

    virtual ~NFScene();

    int CreateInit();

    int ResumeInit();

public:
    virtual int Init(uint64_t mapId, uint64_t sceneId);

    virtual int UnInit();

    virtual int
    OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage) override;

    virtual int OnTimer(int timeId, int callcount) override;

public:
    uint64_t GetMapId() const { return m_mapId; }

    uint64_t GetSceneId() const { return m_sceneId; }

    bool IsDynamic() const;

    NFMap *GetMap() const;
public:
    /**
     * @brief
     * @param pCreature
     * @param pos
     * @param transParam
     * @return
     */
    virtual NFGrid *EnterScene(NFCreature *pCreature, const NFPoint3<float> &pos, STransParam &transParam);

    /**
     * @brief
     * @param Cid
     * @param pGrid
     * @param pos
     * @param isSameGrid
     * @return
     */
    virtual NFGrid *MoveInScene(NFCreature *pCreature, const NFPoint3<float> &pos, bool &isSameGrid);

    /**
     * @brief
     * @param pCreature
     * @return
     */
    virtual int LeaveScene(NFCreature *pCreature);

public:
    bool BroadCast(uint32_t cmd, const google::protobuf::Message &msg);

    bool BroadCast(const SET_UINT64 &setcid, uint16_t cmd, const google::protobuf::Message &msg);

public:
    int FindCreatureInScene(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount = 0);

    int FindCreatureInScene(SET_Creature &setcreature, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount = 0);

    int FindCreatureInCircle(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount = 0);

    int FindCreatureInCircle(SET_Creature &setcreature, const NFPoint3<float> &srcPos, float flength, uint32_t creatureCount = 0);

    int FindCreatureInSector(LIST_UINT64 &clist, const NFPoint3<float> &center, NFPoint3<float> &dir, float angle, float sectorR,
                             uint32_t creatureCount = 0);

    //srcPos是玩家位置，srcDir是玩家移动方向
    int FindCreatureInRect(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, NFPoint3<float> &srcDir, float flength, float fwidth,
                           uint32_t creatureCount = 0);

    int FindCreatureInRect(LIST_UINT64 &clist, const NFPoint3<float> &center, const NFPoint3<float> &dir, const NFPoint3<float> &searchpos,
                           float flength, float fwidth, uint32_t creatureCount = 0);

    int FindCreatureInRect(SET_Creature &setcreature, const NFPoint3<float> &srcPos, NFPoint3<float> &srcDir, float flength, float fwidth,
                           uint32_t creatureCount = 0);

    //圆形范围内 查找敌人
    int FindEnemyInCircle(NFCreature *psrc, SET_Creature &setcreature, float fradius, uint32_t creatureCount = 0);

    //矩形范围内 查找技能目标
    void FindSkillTargetInRect(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos,
                               const NFPoint3<float> &srcDir, float flength, float fwidth, const SearchSkillTargetParam &param);

    //圆形范围内 查找技能目标
    void FindSkillTargetInCircle(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos, float fradius,
                                 const SearchSkillTargetParam &param);

    //扇形范围内 查找技能目标
    void FindSkillTargetInSector(NFCreature *psrc, SET_Creature &setpriority, SET_Creature &setother, const NFPoint3<float> &srcPos,
                                 const NFPoint3<float> &srcDir, float fradius, float fangle, const SearchSkillTargetParam &param);

    //获取中点周围矩形范围内的坐标点
    void FindPointLstInRect(const NFPoint3<float> &center, VecPoint3 &vecPos, float fwidth, float fhigh, int32_t pointCnt, uint32_t beginidx = 0);


    int FindSeeLstInNineGrid(NFCreature *pSrc, std::vector<NFCreature *> *clist, const NFPoint3<float> &srcPos);

    int FindDoubleSeeLstInNineGrid(NFCreature *pSrc, std::vector<NFCreature *> &clist, const NFPoint3<float> &srcPos);

    int GridCreaturesWithCircle(LIST_UINT64 &clist, NFGrid *pGrid, const NFPoint3<float> &srcPos, float flength,
                                uint32_t creatureCount = 0);

    int GridCreaturesWithCircle(SET_Creature &setcreature, NFGrid *pGrid, const NFPoint3<float> &srcPos, float flength,
                                uint32_t creatureCount = 0);

    int GridCreaturesWithSector(LIST_UINT64 &clist, const NFPoint3<float> &center, NFPoint3<float> &vdir, NFGrid *pGrid, float cosAngle,
                                float sectorR, uint32_t creatureCount = 0);

    int GridCreaturesWithRect(LIST_UINT64 &clist, NFGrid *pGrid, const NFPoint3<float> &center, const NFPoint3<float> &dir, float flength,
                              float fwidth, uint32_t creatureCount = 0);

    int GridCreaturesWithRect(SET_Creature &setcreature, NFGrid *pGrid, const NFPoint3<float> &center, const NFPoint3<float> &dir,
                              float flength, float fwidth, uint32_t creatureCount = 0);

public:
    int AddRangeLstCids(LIST_UINT64 &clist, const NFPoint3<float> &srcPos, NFCreature *pTarget, uint32_t creatureCount);

    int AddRangeLstCids(SET_Creature &setcreature, const NFPoint3<float> &srcPos, NFCreature *pTarget, uint32_t creatureCount);

public:
    /**
     * @brief
     * @param pCreature
     */
    int AddMonster(NFCreature *pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemoveMonster(NFCreature *pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int AddPlayer(NFCreature *pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemovePlayer(NFCreature *pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int AddCreature(NFCreature *pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemoveCreature(NFCreature *pCreature);

    /**
     * @brief
     * @param cid
     * @return
     */
    NFCreature *GetCreature(uint64_t cid);

public:
    NFGrid *GetGrid(uint32_t w, uint32_t h);
    int GetIndex(uint32_t w, uint32_t h);

    virtual void GetNineGrid(const NFPoint3<float> &pos, std::vector<NFGrid *> &vecGrid);

    virtual void GetLayerGrid(uint32_t layer, const NFPoint3<float> &pos, std::vector<NFGrid *> &vecGrid);

    virtual uint32_t GetGridLayer(uint32_t gridX, uint32_t gridZ, const NFPoint3<float> &srcPos, float flength);

    virtual void GetLayerGrid(const NFPoint3<float> &srcPos, float flength, std::vector<NFGrid *> &vecGrid);

public:


private:
    uint64_t m_mapId;
    int m_mapGlobalId;
    uint64_t m_sceneId;
    uint32_t m_gridMaxWidth;
    uint32_t m_gridMaxHeight;
    NFShmVector<int, NF_SCENE_MAX_GRID_NUM> m_gridList;
private:
    NFShmNodeObjMultiList<NFCreature> m_creatureList;
    NFShmNodeObjMultiList<NFCreature> m_playerList;
};
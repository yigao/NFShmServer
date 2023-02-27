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
#include "NFLogicCommon/NFComTypeDefine.h"

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
    virtual NFGrid* EnterScene(NFCreature* pCreature, const NFPoint3<float>& pos, STransParam &transParam);

    /**
     * @brief
     * @param Cid
     * @param pGrid
     * @param pos
     * @param isSameGrid
     * @return
     */
    virtual NFGrid* MoveInScene(NFCreature* pCreature, const NFPoint3<float>& pos, bool &isSameGrid);

    /**
     * @brief
     * @param pCreature
     * @return
     */
    virtual bool LeaveScene(NFCreature* pCreature);

    virtual void GetNineGrid(const NFPoint3<float>& pos, std::vector<NFGrid*>& vecGrid);
public:
    void FindCreatureInScene(LIST_UINT64& clist, const NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);
    void FindCreatureInScene(SET_Creature& setcreature, const NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);

    void FindCreatureInCircle(LIST_UINT64& clist, const NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);
    void FindCreatureInCircle(SET_Creature &setcreature, const  NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);
    void FindCreatureInSector(LIST_UINT64& clist, const NFPoint3<float>& center, Point3<float>& dir, float angle, float sectorR, uint32_t creatureCount = 0);

    //srcPos是玩家位置，srcDir是玩家移动方向
    void FindCreatureInRect(LIST_UINT64& clist, const NFPoint3<float>& srcPos, NFPoint3<float>& srcDir, float flength, float fwidth, uint32_t creatureCount = 0);
    void FindCreatureInRect(LIST_UINT64& clist, const NFPoint3<float>& center, const NFPoint3<float>& dir, const Point3<float>& searchpos, float flength, float fwidth, uint32_t creatureCount = 0);
    void FindCreatureInRect(SET_Creature& setcreature, const NFPoint3<float>& srcPos, NFPoint3<float>& srcDir, float flength, float fwidth, uint32_t creatureCount = 0);

    //圆形范围内 查找敌人
    void FindEnemyInCircle(Creature* psrc, SET_Creature& setcreature, float fradius, uint32_t creatureCount = 0);

    //矩形范围内 查找技能目标
    void FindSkillTargetInRect(Creature* psrc, SET_Creature& setpriority, SET_Creature& setother, const Point3<float>& srcPos, const Point3<float>& srcDir, float flength, float fwidth, const SearchSkillTargetParam &param);
    //圆形范围内 查找技能目标
    void FindSkillTargetInCircle(Creature* psrc, SET_Creature& setpriority, SET_Creature& setother, const Point3<float>& srcPos, float fradius, const SearchSkillTargetParam& param);
    //扇形范围内 查找技能目标
    void FindSkillTargetInSector(Creature* psrc, SET_Creature& setpriority, SET_Creature& setother, const Point3<float>& srcPos, const Point3<float>& srcDir, float fradius,float fangle, const SearchSkillTargetParam& param);
    //获取中点周围矩形范围内的坐标点
    void FindPointLstInRect(const NFPoint3<float>& center, VecPoint3& vecPos, float fwidth, float fhigh, int32_t pointCnt, uint32_t beginidx = 0);


    void FindSeeLstInNineGrid(Creature* pSrc, std::vector<Creature*>* clist, const Point3<float>& srcPos);
    void FindDoubleSeeLstInNineGrid(Creature* pSrc, std::vector<Creature*>& clist, const Point3<float>& srcPos);

    void GridCreaturesWithCircle(LIST_UINT64& clist, NFPoint2<uint32_t>& gridpos, const NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);
    void GridCreaturesWithCircle(SET_Creature &setcreature, NFPoint2<uint32_t>& gridpos, const NFPoint3<float>& srcPos, float flength, uint32_t creatureCount = 0);
    void GridCreaturesWithSector(LIST_UINT64& clist, const  NFPoint3<float>& center, NFPoint3<float>& vdir, NFPoint2<uint32_t>& gridpos, float cosAngle, float sectorR, uint32_t creatureCount = 0);
    void GridCreaturesWithRect(LIST_UINT64& clist, NFPoint2<uint32_t>& gridpos, const NFPoint3<float>& center, const NFPoint3<float>& dir, float flength, float fwidth, uint32_t creatureCount = 0);
    void GridCreaturesWithRect(SET_Creature& setcreature, NFPoint2<uint32_t>& gridpos, const NFPoint3<float>& center, const NFPoint3<float>& dir, float flength, float fwidth, uint32_t creatureCount = 0);

public:
    /**
     * @brief
     * @param pCreature
     */
    int AddMonster(NFCreature* pCreature);

    /**
     * @brief
     * @param pCreature
     */
    int RemoveMonster(NFCreature* pCreature);

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
public:
    NFGrid* GetGrid(uint32_t w, uint32_t h);
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
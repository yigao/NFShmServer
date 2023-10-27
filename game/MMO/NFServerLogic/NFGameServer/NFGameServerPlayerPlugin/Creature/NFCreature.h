// -------------------------------------------------------------------------
//    @FileName         :    NFCreature.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreature
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFAccountDefine.h"
#include "NFComm/NFShmStl/NFShmList.h"
#include "NFCreatureVisionData.h"
#include "Part/NFBattlePart.h"
#include "View.pb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFGameCommon/NFPoint3.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "NFLogicCommon/NFAttr.h"

class NFScene;

class NFGrid;

class NFCreature;

class NFBattlePart;

enum
{
    NF_CREATURE_NODE_LIST_GRID_INDEX = 0,
    NF_CREATURE_NODE_LIST_SCENE_INDEX = 1,
    NF_CREATURE_NODE_LIST_MAX_TYPE_INDEX = 2,
};

//生物状态
class CreatureState
{
public:
    CreatureState()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        } else
        {
            ResumeInit();
        }
    }
    
    ~CreatureState()
    {
    
    }
    
    int CreateInit()
    {
        m_curstate = 0;
        m_laststate = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool BState(proto_ff::ECState state)
    {
        return (state == m_curstate);
    }
    
    uint8_t GetState()
    {
        return m_curstate;
    }
    
    void SetState(proto_ff::ECState state)
    {
        m_curstate = state;
    }
    
    bool EnterState(NFCreature *pCreature, proto_ff::ECState state);

protected:
    uint8_t m_curstate;
    uint8_t m_laststate;
};

class NFCreature : public NFShmObjTemplate<NFCreature, EOT_GAME_CREATURE_ID, NFShmObj>, public NFMultiListNodeObjWithGlobalID<NFCreature, EOT_GAME_CREATURE_ID, NF_CREATURE_NODE_LIST_MAX_TYPE_INDEX>
{
public:
    NFCreature();
    
    virtual ~NFCreature();
    
    int CreateInit();
    
    int ResumeInit();

public:
    virtual int Init();
    
    virtual int UnInit();
    
    virtual int Update(uint64_t tick);

public:
    virtual bool IsDestory() { return m_destory; }
    
    virtual void SetDestory() { m_destory = true; }
    
    virtual AccountGameState GetAccountState() { return ACCOUNT_GAME_STATE_NULL; }
    
    virtual bool IsDead() { return BState(proto_ff::state_dead); }
    
    virtual uint64_t GetCfgId() { return 0; } //获取生物对应实例配置表Id
    void SetPos(const NFPoint3<float> &pos);
    
    NFPoint3<float> &GetPos() { return m_pos; }
    
    void SetDir(const NFPoint3<float> &point);
    
    NFPoint3<float> &GetDir() { return m_dir; }
    
    NFGrid *GetGrid();
    
    void SetGrid(NFGrid *pGrid);
    
    NFScene *GetScene();
    
    uint64_t GetSceneId() const { return m_sceneId; };
    
    void SetSceneId(uint64_t sceneId) { m_sceneId = sceneId; }
    
    uint64_t GetMapId() const { return m_mapId; }
    
    void SetMapId(uint64_t mapId) { m_mapId = mapId; }
    
    virtual uint8_t Kind() const { return m_kind; };
    
    uint64_t Cid() const { return m_cid; }
    
    float GetSpeed();
    
    float GetSightRange() const { return m_sightRange; }
    
    virtual uint64_t GetUid() { return 0; }
    
    virtual uint64_t GetRoleId() { return 0; }
    
    virtual uint32_t GetChannId() { return 0; }
    
    virtual uint32_t GetZid() { return 0; }
    
    virtual uint32_t GetProxyId() { return 0; }
    
    virtual uint64_t GetClientId() { return 0; }
    
    virtual uint32_t GetLogicId() { return 0; }
    
    //获取怪物模型半径, 长度单位m
    virtual float GetModelRadius() { return m_fRadius; };
public:
    /**
     * @brief 强制传送(场景内传送、切场景传送)
     * @param scenceId 目标场景ID（唯一ID，静态地图场景ID和地图ID相同）
     * @param dstPos 目标场景坐标
     * @param mapId 地图ID
     * @param transParam 传送参数
     * @return
     */
    virtual int TransScene(uint64_t scenceId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam) { return 0; }
    
    //进入场景(这个接口只给移动部件和生物内部自身调用，其他请调用transScene)
    virtual int EnterScene(uint64_t sceneId, const NFPoint3<float> &enterPos, STransParam &transParam);
    
    //离开场景
    virtual int LeaveScene();
    
    virtual int CanTrans(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float> &dstPos, NFPoint3<float> &outPos, STransParam &transParam, bool checkPosFlag = true) { return 0; }
public:
    //状态
    virtual bool EnterNormalState();
    
    virtual bool EnterDeadState();
    
    virtual bool EnterReliveState();
    
    virtual bool EnterSeatState();
    
    virtual bool LeaveSeatState();
    
    virtual bool EnterFightState();
    
    virtual bool LeaveFigthState();
    
    virtual bool LeaveState();
    
    virtual bool BState(proto_ff::ECState state);
    
    uint8_t GetState();
    
    void SetState(proto_ff::ECState state);
    
    //状态改变
    virtual void OnChangeState(uint8_t curstate, uint8_t laststate);

public:
    //是否有战力压制
    virtual bool HasFightSuppress() { return true; }
    
    //是否是组队机器人
    virtual bool IsTeamRobot() { return false; }
    
    virtual void OnDead(uint64_t killerCid, bool isSync = false, int64_t lastDamage = 0);
    
    virtual void OnCorpse() {}; //尸体停留阶段
    
    virtual void OnRevive(int64_t curhp = 0);
    
    virtual NFCreature *GetOwner() { return nullptr; }
    
    virtual void SetOwner(NFCreature *powner) {}

public:
    virtual void FindCreatureInScene(LIST_UINT64 &clist);
    
    virtual void FindCreatureInScene(SET_Creature &setcreature);
    
    virtual void FindSeeListInNineGride(NFCreature *pSrc, std::vector<NFCreature *> *clist, NFPoint3<float> &sorPos);
    
    virtual void FindDoubleSeeListInNineGride(NFCreature *pSrc, std::vector<NFCreature *> &clist, NFPoint3<float> &sorPos);
    
    //将对方加入到自己的视野中
    virtual void SimpleAddPVPSeeLst(int releation, NFCreature *pOther);
    
    virtual void SimplePVMAddSeeLst(NFCreature *pOther);
    
    virtual void ReplacePVPSeeList(int releation, NFCreature *pOther, std::vector<NFCreature *> &vecBeen);
    
    virtual void AddPVPSeeLst(int releation, NFCreature *pOther, std::vector<NFCreature *> &vecBeen);
    
    virtual void AddPVMSeeLst(NFCreature *pOther, std::vector<NFCreature *> &vecBeen);
    
    virtual int DelPVMSeeLst(int delpos, NFCreature *pOther);
    
    virtual int DelPVPSeeLst(int delpos, NFCreature *pOther);
    
    //视野裁剪接口 后面需要做更复杂的视野裁剪那么子类继承去实现
    virtual bool ViewFliter(NFCreature *pCreature, float dict);
    
    virtual void OnDelPVPSeeLst(NFCreature *pOther) {}
    
    virtual void GetSeeLst(std::vector<uint64_t> &);
    
    virtual void GetCreatureList(std::vector<NFCreature *> &vec);
    
    virtual NFCreatureVisionData &GetVisionData() { return m_visionData; }
    
    virtual const NFCreatureVisionData &GetVisionData() const { return m_visionData; }
    
    //视野类接口
    virtual void UpdateSeeLst();
    
    virtual void UpdateNineGridLst();
    
    virtual void GetVisibleDataToClient(proto_ff::CreatureCreateData &cvData) {};  //获取客户端可见数据
    
    //更新生物视野数据(生物视野数据变更，需要通知周围已经看到了他们的玩家)
    virtual void UpdateViewData() {};
    
    //用于重连上后，再重新发送一次全体视野信息。
    void SendAllSeeCreatureListToClient();
    
    void NoticeNineGridLeave();

public:
    //判断是否能发送消息
    bool IsCanSendMessage();
    
    //设置能否被看见
    void SetCanBeSeenFlag(bool isCanBeSeen);
    
    //获取能否被看见
    bool GetCanBeSeenFlag();

public:
    //////////////////////////////////////////////////////////////////////////
    //增加属性 主要是为了增加虚拟物品相关的属性 costFlag:是否是扣除属性
    virtual void AddVirAttr(MAP_UINT32_INT64 &mapAttr, bool costFlag = false, SCommonSource *pSource = nullptr, bool syn = false) {};
    
    //属性是否足够，主要是为了属性虚拟物品的判断
    virtual bool EnoughVirAttr(MAP_UINT32_INT64 &mapAttr) { return false; };
    
    //增加属性
    virtual bool AddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr, bool syn = false);
    
    //增加属性 不同步到客户端
    virtual bool AddAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //能否增加属性
    virtual bool CanAddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr) { return true; };
    
    //增加属性处理
    virtual void OnAddAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource = nullptr) {};
    
    //设置属性
    virtual bool SetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr, bool syn = false);
    
    //设置属性 不同步客户端
    virtual bool SetAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //能否设置属性
    virtual bool CanSetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr) { return true; };
    
    //设置属性处理
    virtual void OnSetAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource = nullptr) {};
    
    //获取该组属性值
    virtual int64_t GetAttrGroup(uint32_t attrGroup, uint32_t ANum);
    
    //获取该组所有属性值
    virtual void GetAttrGroup(uint32_t attrGroup, MAP_UINT32_INT64 &mapattr);
    
    //清除某一组属性
    virtual bool ClearAttrGroup(uint32_t attrGroup, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool ClearAttrGroupCache(uint32_t attrGroup, SCommonSource *pSource = nullptr);
    
    //增加属性组属性
    virtual bool AddAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool AddAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr);
    
    //设置属性组属性
    virtual bool SetAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool SetAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr);
    
    //设置属性组所有属性
    virtual bool SetAttrGroup(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool SetAttrGroupCache(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource = nullptr);
    
    //计算属性
    virtual void CalcAttr(uint32_t ANum);
    
    //计算属性组属性 主要是把属性组中的属性汇总到总属性中 ANum:属性组中的属性ID
    virtual void CalcAttrGroup(uint32_t attrgroup, uint32_t ANum, MAP_UINT32_INT64 &mapchg);
    
    //获取属性值
    virtual int64_t GetAttr(uint32_t ANum);
    
    //属性改变
    virtual void OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource *pSource = nullptr);
    
    //同步属性
    virtual void SynAttrToClient();

public:
    //是否可以添加新看到的生物
    virtual bool CanAddSeeNewCreature(NFCreature *pCreature, int64_t hateValue);

public:
    //获取对应部件指针
    virtual NFBattlePart *GetPart(uint32_t partType) { return nullptr; }

public:
    //****************消息发送接口*****************
    virtual int BroadCast(uint32_t nMsgId, const google::protobuf::Message &xData, bool IncludeMyself = false);
    
    virtual int SendRedirectMsgToClient(uint32_t zid, uint32_t gateId, const std::unordered_set<uint64_t> &set, uint32_t nMsgId,
                                        const google::protobuf::Message &xData);
    
    virtual int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
    
    virtual int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    virtual int SendTransToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId = 0, uint32_t rspTransId = 0);
    
    virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    virtual int SendTransToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId = 0, uint32_t rspTransId = 0);
    
    virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    virtual int SendTransToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t reqTransId = 0, uint32_t rspTransId = 0);
    
    virtual int FireLogic(uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message &message, bool self = false);

protected:
    uint64_t m_cid;     //生物实例id
    uint32_t m_kind;     //实体类型
    
    NFPoint3<float> m_pos;                   //当前生物坐标
    uint64_t m_sceneId;                //场景id
    uint64_t m_mapId;                  //地图模板id
    
    NFCreatureVisionData m_visionData;    //视野数据
    float m_sightRange;                //可见视野范围长度
    float m_fRadius;                    //人物半径
    
    uint32_t m_seeInterval;                //视野更新间隔(毫秒)
    uint64_t m_lastSeeTime;                //上次更新视野时间
    uint64_t m_lastUpdateNineTime;        //上次更新9宫格时间
    
    
    NFPoint2<uint32_t> m_gridPos;             //生物在地图中的格子
    NFPoint2<uint32_t> m_littleGrid;
    
    NFPoint3<float> m_dir;                    //运动方向,单位向量
    bool m_destory;            //是否要回收
    bool m_bCanBeSeen;        //是否被见
    CreatureState m_state;                    //状态
    
    NFShmPtr<IFightAttr> m_pFightAttr;        //战斗属性
    NFShmPtr<IAttr> m_pAttr;                //普通属性
    
    NFShmHashMap<uint32_t, int64_t, 100> m_attrCache;            //需要同步单个客户端属性缓存
    NFShmHashMap<uint32_t, int64_t, 100> m_attrBroadCache;        //需要广播属性缓存
};
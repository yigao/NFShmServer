// -------------------------------------------------------------------------
//    @FileName         :    NFMissionPart.h
//    @Author           :    gaoyi
//    @Date             :    23-2-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFPart.h"
#include "NFLogicCommon/NFMissionDefine.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "DescStoreEx/NFMissionDescStoreEx.h"
#include "NFLogicCommon/NFItemDefine.h"
#include "NFLogicCommon/NFComTypeDefine.h"

#define PLAYER_TRACK_MISSION_MAX_MISSION_COUNT MISSION_MAX_ACCEPT_NUM*2

class NFMissionPart : public NFPart
{
public:
    // eventtype - level - dynamicid
    typedef NFShmHashMap<uint32_t, NFShmHashMap<int32_t, NFShmHashSet<uint64_t, PLAYER_TRACK_MISSION_MAX_MISSION_COUNT>,
            PLAYER_TRACK_MISSION_MAX_MISSION_COUNT>, 10> EventTabal;


    typedef NFShmHashMap<uint64_t, MissionTrack, PLAYER_TRACK_MISSION_MAX_MISSION_COUNT> PlayerTrackMissionMap;
    typedef NFShmHashMap<int32_t, DyMissionTrack, NF_MISSION_TYPE_MAX_COUNT> PlayerDyMissionTrackMap;
public:
    NFMissionPart();

    virtual ~NFMissionPart();

    int CreateInit();

    int ResumeInit();

public:
    static int RetisterClientMessage(NFIPluginManager *pPluginManager);

    static int RetisterServerMessage(NFIPluginManager *pPluginManager);

public:
public:
    //******************part调用生物接口******************
    //生物init调用
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);

    //生物uint调用
    virtual int UnInit();

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);

public:
    /**
     * @brief 检查主线任务
     * @param notify
     */
    void CheckTrunkMission(bool notify = true);

public: //消息回调接口
    /**
     * @brief NPC接取任务
     * @param msgId
     * @param packet
     */
    int HandleNpcAcceptMission(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 提交任务
     * @param msgId
     * @param packet
     */
    int HandleSubmitMission(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief NPC对话,寻人接口
     * @param msgId
     * @param packet
     */
    int HandleTalkWithNpc(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 提交任务物品
     * @param msgId
     * @param packet
     */
    int HandleSubmitMissionGoods(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 一键完成任务
     * @param msgId
     * @param packet
     */
    int HandleOnekeyFinishMission(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 立即完成
     * @param msgId
     * @param packet
     */
    int HandleOnceFinishMission(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 领取特殊奖励
     * @param msgId
     * @param packet
     */
    int HandleMissionRecvSpecialReward(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 推送任务列表信息
     * @param msgId
     * @param packet
     */
    int SendMissionList(uint32_t msgId, NFDataPackage &packet);

public:
    /**
     * @brief 接取任务
     * @param missionId
     * @param notify
     * @return
     */
    int32_t OnAccept(uint64_t missionId, bool notify);

    /** 接取任务
     * @brief
     * @param missionId
     * @param kind
     */
    void OnAccept(uint64_t missionId, uint32_t kind);

    /**
     * @brief 获取可接任务列表(主支线)
     * @param missionId
     * @return
     */
    int32_t CanAccept(uint64_t missionId);

    /**
     * @brief
     * @param cond
     * @param param
     * @return
     */
    int32_t CanAccept(const AcceptInfo &cond, SCanAcceptParam &param);

public:
    /////////////////////////////////////////普通任务接口/////////////////////////////////////////////
    /**
     * @brief 通过任务类型接取任务
     * @param missionType
     * @param notify
     * @return
     */
    int32_t AcceptMissionByType(int32_t missionType, bool notify);

    /**
     * @brief 能否通过任务类型接取任务
     * @param missionType
     * @return
     */
    int32_t CanAcceptMissionByType(int32_t missionType);

    /**
     * @brief 通过任务类型清除任务,返回清除的任务数量 notify：是否需要通知客户端删除任务
     * @param missionType
     * @param notify
     * @return
     */
    int32_t ClearMissionByType(int32_t missionType, bool notify);

public:
    /**
     * @brief 获取任务最大环数
     * @param missionType
     * @param level
     * @return
     */
    int32_t DyMaxCount(int32_t missionType, int32_t level);

    /**
     * @brief 根据任务类型获取动态任务已经接取次数
     * @param missionType
     * @return
     */
    uint32_t GetDyMissionAceeptCnt(int32_t missionType);

    /**
     * @brief 完成任务(动态任务)
     * @param dymissionId
     * @param dymissionType
     */
    void OnFinishDy(uint64_t dymissionId, uint32_t dymissionType);

    /**
     * @brief 根据任务类型获取动态任务记录信息
     * @param missionType
     * @return
     */
    DyMissionTrack *GetDyMissionTrack(int32_t missionType);

    /**
     * @brief 动态任务奖励
     * @param missionType
     * @param missionId
     * @param missionReward
     * @return
     */
    int32_t OnAddDyMissionReward(int32_t missionType, uint64_t missionId, SMissionReward &missionReward);

    /**
     * @brief 更新动态任务接取次数
     * @param setMissionType
     */
    void NotifyDyAcceptCount(SET_UINT32 &setMissionType);

    /**
     * @brief 是否是有效的动态任务ID
     * @param dyMissionId
     * @return
     */
    bool ValidDyMissionId(uint64_t dyMissionId);

    /**
     * @brief 分配一个动态任务ID
     * @return
     */
    uint64_t AllocNewDyMisssionId();

    /**
     * @brief 回收一个动态任务ID
     * @param dyMissionId
     */
    void FreeDyMissionId(uint64_t dyMissionId);

    /**
     * @brief 根据任务类型随机一个任务ID
     * @param missionType
     * @return
     */
    uint64_t DyRandMissionId(int32_t missionType);
public:
    /** 最近提交列表里面是否有指定类型的任务
     * @brief
     * @param missionType
     * @return
     */
    bool HaveRecentSubmit(int32_t missionType);

    /**
     * @brief  根据任务类型获取当前任务列表中存在的数量
     * @param missionType
     * @return
     */
    int32_t MissionNumByType(int32_t missionType);

    /**
     * @brief 该任务是否已经接收过了
     * @param missionId
     * @return
     */
    bool HaveAccpet(const uint64_t &missionId);

    /**
     * @brief 是否已经提交过的任务
     * @param missionId
     * @return
     */
    bool HaveSubmited(uint64_t missionId);

public:
    int32_t OnExtractCond(MissionInfo *pMissionInfo, MissionTrack *pMissionTrack);

    /**
     * @brief 条件预判断(有些条件接取任务时就已经完成了)
     * @param cond
     */
    void OnPreUpdateProgress(ItemInfo &cond);

    /**
     * @brief 更新条件进度
     * @param data
     * @param cond
     * @param notify
     */
    void OnUpdateCondProcess(const ExecuteData &data, ItemInfo &cond, bool &notify);

public:
    /**
     * @brief 增加发任务时的物品奖励
     * @param pMissionTrack
     * @return
     */
    int32_t AddReward(uint64_t missionId, int32_t kind, TASK_REWARD &reward, float ration = 1);

    /**
     * @brief 是否能增加任务奖励
     * @param pPlayer
     * @param reward
     * @param param
     * @param lstOutItem
     * @return
     */
    bool CanAddReward(uint64_t missionId, int32_t kind, TASK_REWARD &reward, LIST_ITEM &lstOutItem);

public:
    //更新进度
    int32_t OnUpdateProgress(uint64_t missionId, const ExecuteData &data);

    /**
     * @brief 更新任务进度
     * @param missionId
     */
    void UpdateMissionProgress(uint64_t missionId);

public:
    /**
     * @brief 添加任务掉落
     * @param pMissionTrack
     * @param progressLev
     * @return
     */
    int32_t OnAddMissionDrop(MissionTrack *pMissionTrack, int32_t progressLev);

    /**
     * @brief 添加任务掉落
     * @param dymissionId
     * @param monsId
     * @param dropId
     * @param boxId
     * @param progressLev
     * @return
     */
    bool AddMissionDrop(uint64_t dymissionId, uint64_t monsId, uint64_t dropId, uint64_t boxId, int32_t progressLev);

    /**
     * @brief 删除任务掉落
     * @param dymissionId
     * @param monsId
     * @return
     */
    bool DelMissionDrop(uint64_t dymissionId, uint64_t monsId);

    /**
     * @brief 获取任务掉落
     * @param monsterId
     * @return
     */
    MissionDropMap *GetMissionDrop(uint64_t monsterId);

public://任务事件处理接口
    /**
     * @brief 注册监听事件，接任务成功后注册
     * @param eventType
     * @param missionId
     * @param progressLev
     */
    void RegisterEvent(uint32_t eventType, uint64_t missionId, int32_t progressLev);

    /**
     * @brief 移除这个任务注册的所有事件
     * @param missionId
     */
    void RemoveEvent(uint64_t missionId);

    /**
     * @brief 发送任务事件，阻塞
     * @param eventType
     * @param data
     * @param dynamicId
     */
    void OnEvent(uint32_t eventType, const ExecuteData &data, uint64_t dynamicId = 0);

private:
    PlayerTrackMissionMap _playerTrackMissionMap;    //当前任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, NF_MISSION_TYPE_MAX_COUNT> _mapRecentSubmit;        //最近提交的任务
    NFShmHashSet<uint64_t, NF_MISSION_TYPE_MAX_MISSION_COUNT> _setAlreadySubmit;        //已经提交的任务
    //动态任务
    PlayerDyMissionTrackMap _mapDyMissionTrack;        //动态任务数据
    MissionAllDropMap _mapMissionAllDrop;        //任务掉落
    //
    EventTabal _eventTabal;            //任务事件表
    NFShmVector<bool, MISSION_MAX_DYNAMIC_ALLOC + 1> _aryDyIdAlloc; //动态任务ID分配
private:
DECLARE_IDCREATE(NFMissionPart)
};
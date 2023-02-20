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

#define PLAYER_TRACK_MISSION_MAX_MISSION_COUNT 100

class NFMissionPart : public NFPart
{
public:
    // eventtype - level - dynamicid
    typedef NFShmHashMap<uint32_t, NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 10>, 10>, 10> EventTabal;


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
     * @brief 接取任务 reacceptFlag:是否是重新接取标志,triggerFlag:是否执行触发器的标志
     * @param missionId
     * @param notify
     * @return
     */
    int32_t OnAccept(uint64_t missionId, bool notify);

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
    /**
     * @brief 检查主线任务
     * @param notify
     */
    void CheckTrunkMission(bool notify = true);

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

private:
    PlayerTrackMissionMap _playerTrackMissionMap;    //当前任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, NF_MISSION_TYPE_MAX_COUNT> _mapRecentSubmit;        //最近提交的任务
    NFShmHashSet<uint64_t, NF_MISSION_TYPE_MAX_MISSION_COUNT> _setAlreadySubmit;        //已经提交的任务
    //动态任务
    PlayerDyMissionTrackMap _mapDyMissionTrack;        //动态任务数据
    //MissionAllDropMap					_mapMissionAllDrop;		//任务掉落
    //
    EventTabal _eventTabal;            //任务事件表
private:
DECLARE_IDCREATE(NFMissionPart)
};
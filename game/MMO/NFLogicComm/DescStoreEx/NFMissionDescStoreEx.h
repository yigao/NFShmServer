// -------------------------------------------------------------------------
//    @FileName         :    NFMissionDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    23-2-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFMissionDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"

#include "NFLogicCommon/NFMissionDefine.h"
#include "DescStore/TaskdynamicTaskdynamicDesc.h"
#include "DescStore/TaskrewardTaskrewardDesc.h"
#include "DescStore/TaskdynamicTaskcomcondDesc.h"
#include "DescStore/TaskTaskDesc.h"

//通过移位组合动态任务text表条件 text 表中 目标场景(最多11位十进制数字，对应的二进制位是 37bit)+任务类型(6bit)+完成条件(20bit)
#define DY_MISSION_TEXT_KEY(type, cond) ((type << 20) | cond )
#define DY_MISSION_TEXT_TYPE(key) (key >> 20)
#define DY_MISSION_TEXT_COND(key) ( key & 0xFFFFF)

//动态任务奖励组合key
#define DY_MISSION_REWARD_KEY(type, lv) ((lv << 8) | type)

#define NF_MISSION_TYPE_MAX_COUNT 20
#define NF_MISSION_TYPE_MAX_MISSION_COUNT (MAX_TASK_TASK_NUM+MAX_TASKDYNAMIC_TASKDYNAMIC_NUM)

class NFMissionDescStoreEx : public NFIDescStore
{
public:
    typedef NFShmHashMap<uint64_t, DyMissionInfo, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM> DyMissionInfoMap;
    typedef NFShmHashMap<uint64_t, DyConditionInfo, MAX_TASKDYNAMIC_TASKCOMCOND_NUM> DyCondtionInfoMap;
    typedef NFShmHashMap<uint64_t, MissionInfo, MAX_TASK_TASK_NUM> MissionInfoMap;
    //动态任务奖励 key是玩家等级(32 - 9)+任务类型(8 - 1) 组合
    typedef NFShmHashMap<uint32_t, TASK_REWARD, MAX_TASKREWARD_TASKREWARD_NUM> DyTaskRewardMap;
    typedef NFShmHashMap<int32_t, NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM>, NF_MISSION_TYPE_MAX_COUNT> FirstMissionMap;
    typedef NFShmHashMap<int32_t, NFShmHashSet<uint64_t, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>, NF_MISSION_TYPE_MAX_COUNT> DyMissionTypeMap;
public:
    NFMissionDescStoreEx();

    virtual ~NFMissionDescStoreEx();

    int CreateInit();

    int ResumeInit();

public:
    bool ProcessDyMission();//处理动态任务配置
    bool ProcessDyCondition();//处理动态条件
    bool ProcessDyText();    //处理动态任务前端显示
    bool ProcessReward();    //处理动态任务奖励
    bool ProcessTask();

public:
    const DyMissionInfo *GetDyMissionCfgInfo(uint64_t missionId);

    const DyConditionInfo *GetDyConditionCfgInfo(uint64_t condId);

    MissionInfo *GetMissionCfgInfo(uint64_t missionId);

public:
    bool ParseMissionCond(MissionInfo *pMissionInfo, const std::string &strParam);              //解析任务接取条件
    bool ParseTaskExecute(MissionInfo *pMissionInfo, const std::string &sExecute);      //解析任务完成条件
    bool ParseTaskReceAdd(MissionInfo *pMissionInfo, const std::string &sReceAdd);

    bool ParseTaskSubAward(MissionInfo *pMissionInfo, int64_t sSubAward);

public:
    //解析接取条件(公用接口)
    bool ParseAcceptCond(AcceptInfo &accept, const std::string &strAcceptParam, SParaseAcceptParam &param);
    //解析完成条件(公用接口)
    bool ParseFinishCond(InterExecute &conds, const std::string &strFinish, SParseFinishParam &param);
    //校验完成条件(公用接口)
    bool CheckFinishCond(InterItemPair &item, SParseFinishParam &param);

    bool CheckRewardParam(uint64_t missionId, uint32_t type, uint64_t id);

public:
    uint64_t ComposeTextKey(int32_t missionType, int32_t condType); //组装text表的key
    uint32_t ComposeDyRewardKey(int32_t taskType, int32_t level);//组装动态任务奖励key
public:
    //获取每条线的第一个任务
    const FirstMissionMap &GetFirstMission() { return _missionFirstMap; }
    const NFShmHashSet<uint64_t, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>* GetDyMissionLstByType(int32_t missionType) const;
    uint64_t GetDyTextId(uint64_t key);
    uint64_t GetDyTextId(int32_t missionType, uint32_t condType);
private:
    DyMissionTypeMap m_dymissionTypeMap;                    //动态任务类型map
    DyMissionInfoMap m_dymissionInfoMap;                    //动态任务配置
    DyCondtionInfoMap m_dycondtionInfoMap;                    //动态条件配置
    MissionInfoMap m_missionInfoMap;                    //任务配置列表
    DyTaskRewardMap m_mapDyReward;                        //动态任务奖励
    FirstMissionMap _missionFirstMap;                    //任务类型对应的第一个任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, 1000> m_mapLevMission;                    //等级任务

    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM>, MAX_TASK_TASK_NUM> m_mapPreOrAcceptMap;                //任务配置中的前置任务或条件
    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM>, MAX_TASK_TASK_NUM> m_mapPreAndAcceptMap;                //任务配置中的前置任务与条件
    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM>, MAX_TASK_TASK_NUM> m_mapPreAcceptMap;                    //接取条件中前置任务完成可接取的任务

    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, 100>, 5> _dymissionTextMap;                    //动态任务前端显示配置
private:
DECLARE_IDCREATE(NFMissionDescStoreEx)

IMPL_RES_SIMPLE_DESC(NFMissionDescStoreEx);
};
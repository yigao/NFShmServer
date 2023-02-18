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

//通过移位组合动态任务text表条件 text 表中 目标场景(最多11位十进制数字，对应的二进制位是 37bit)+任务类型(6bit)+完成条件(20bit)
#define DY_MISSION_TEXT_KEY(type, cond) ((type << 20) | cond )
#define DY_MISSION_TEXT_TYPE(key) (key >> 20)
#define DY_MISSION_TEXT_COND(key) ( key & 0xFFFFF)

//动态任务奖励组合key
#define DY_MISSION_REWARD_KEY(type, lv) ((lv << 8) | type)

class NFMissionDescStoreEx : public NFIDescStore
{
    typedef NFShmHashMap<uint64_t, DyMissionInfo, 100> DyMissionInfoMap;
    typedef NFShmHashMap<uint64_t, DyConditionInfo, 100> DyCondtionInfoMap;
    typedef NFShmHashMap<uint64_t, MissionInfo, 500> MissionInfoMap;
    //动态任务奖励 key是玩家等级(32 - 9)+任务类型(8 - 1) 组合
    typedef NFShmHashMap<uint32_t, NFShmVector<TaskComplex, 10>, 1000> DyTaskRewardMap;
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
private:
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, 30> _dymissionTypeMap;                    //动态任务类型map
    DyMissionInfoMap _dymissionInfoMap;                    //动态任务配置
    DyCondtionInfoMap _dycondtionInfoMap;                    //动态条件配置
    MissionInfoMap _missionInfoMap;                    //任务配置列表
    DyTaskRewardMap m_mapDyReward;                        //动态任务奖励
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, 30> _missionFirstMap;                    //任务类型对应的第一个任务列表
    NFShmHashMap<int32_t, NFShmHashSet<uint64_t, 100>, 1000> m_mapLevMission;                    //等级任务

    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, 100>, 100> m_mapPreOrAcceptMap;                //任务配置中的前置任务或条件
    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, 100>, 100> m_mapPreAndAcceptMap;                //任务配置中的前置任务与条件
    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, 100>, 100> m_mapPreAcceptMap;                    //接取条件中前置任务完成可接取的任务

    NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, 100>, 5> _dymissionTextMap;                    //动态任务前端显示配置
private:
DECLARE_IDCREATE(NFMissionDescStoreEx)

IMPL_RES_SIMPLE_DESC(NFMissionDescStoreEx);
};
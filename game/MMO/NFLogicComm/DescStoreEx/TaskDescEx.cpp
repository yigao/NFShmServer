#include "TaskDescEx.h"

#include <DescStore/FunctionunlockFunctionunlockDesc.h>

#include "NFGameCommon/NFComTypeDefine.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/TaskrewardTasktypeDesc.h"
#include "DescStore/MonsterMonsterDesc.h"
#include "DescStore/PointPointDesc.h"
#include "DescStore/BoxBoxDesc.h"
#include "DescStore/DupDupDesc.h"
#include "DescStore/DupGroupDesc.h"
#include "DescStore/ButtonButtonDesc.h"
#include "DescStore/SkillSkillDesc.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFLogicCommon/Attr/NFAttrMgr.h"

TaskDescEx::TaskDescEx()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

TaskDescEx::~TaskDescEx()
{
}

int TaskDescEx::CreateInit()
{
	return 0;
}

int TaskDescEx::ResumeInit()
{
	return 0;
}

int TaskDescEx::Load()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    
    CHECK_EXPR(ProcessTask(), -1, "ProcessTask Failed");
    CHECK_EXPR(ProcessDyCondition(), -1, "ProcessDyCondition Failed");
    CHECK_EXPR(ProcessDyMission(), -1, "ProcessDyMission Failed");
    CHECK_EXPR(ProcessDyText(), -1, "ProcessDyText Failed");
    CHECK_EXPR(ProcessReward(), -1, "ProcessReward Failed");
    
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int TaskDescEx::CheckWhenAllDataLoaded()
{
    //校验前置接取或条件中的任务ID
    for (auto iterOr = m_mapPreOrAcceptMap.begin(); iterOr != m_mapPreOrAcceptMap.end(); ++iterOr)
    {
        auto &setMission = iterOr->second;
        for (auto iterCheck = setMission.begin(); iterCheck != setMission.end(); ++iterCheck)
        {
            if (nullptr == GetMissionCfgInfo((*iterCheck)))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "InitConfig...missionid in preor accept condition not exists...missionid:{} premissionid:{} ",
                           iterOr->first, (*iterCheck));
                return -1;
            }
        }
    }
    
    //校验前置接取与条件中的任务ID
    for (auto iterAnd = m_mapPreAndAcceptMap.begin(); iterAnd != m_mapPreAndAcceptMap.end(); ++iterAnd)
    {
        auto &setMission = iterAnd->second;
        for (auto iterCheck = setMission.begin(); iterCheck != setMission.end(); ++iterCheck)
        {
            if (nullptr == GetMissionCfgInfo((*iterCheck)))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0,
                           "InitConfig...missionid in preand accept condition not exists...missionid:{} premissionid:{} ",
                           iterAnd->first, (*iterCheck));
                return -1;
            }
        }
    }
    
    return 0;
}


bool TaskDescEx::ProcessTask()
{
    auto pTaskCfgMap = TaskTaskDesc::Instance()->GetResDescPtr();
    for (auto iter = pTaskCfgMap->begin(); iter != pTaskCfgMap->end(); iter++)
    {
        auto pTaskInfo = &iter->second;
        if (pTaskInfo->m_id <= 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "missionId <= 0:missionId:{}", pTaskInfo->m_id);
            return false;
        }
        
        if (m_missionInfoMap.size() >= m_missionInfoMap.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "_missionInfoMap Note Enough Space.........");
            return false;
        }
        
        if (m_missionInfoMap.find(pTaskInfo->m_id) != m_missionInfoMap.end())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "mission id:{} exist............", pTaskInfo->m_id);
            return false;
        }
        
        MissionInfo *pMissionInfo = &m_missionInfoMap[pTaskInfo->m_id];
        pMissionInfo->missionId = pTaskInfo->m_id;
        
        pMissionInfo->accept.minLevel = pTaskInfo->m_minlv;
        pMissionInfo->progressLev = pTaskInfo->m_truelv;
        pMissionInfo->kind = pTaskInfo->m_type;
        
        if (pMissionInfo->missionId <= 0) {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MissionManager::LoadConfig but pMissionInfo->missionId <= 0:missionId:%lu", pMissionInfo->missionId);
            return false;
        }
        
        //接取条件
        if (!ParseMissionCond(pMissionInfo, pTaskInfo->m_rececond.ToString()))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "task id:{} rececond error:{}", pTaskInfo->m_id, pTaskInfo->m_rececond.ToString());
            return false;
        }
        
        //接取任务时发放任务物品
        if (!ParseTaskReceAdd(pMissionInfo, pTaskInfo->m_receadd.ToString()))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "task id:{} receadd error:{}", pTaskInfo->m_id, pTaskInfo->m_receadd.ToString());
            return false;
        }
        
        //完成条件
        if (!ParseTaskExecute(pMissionInfo, pTaskInfo->m_comcond.ToString()))
        {
            return false;
        }
        
        //后置任务
        pMissionInfo->backTaskId = pTaskInfo->m_nexttask;
        
        //固定奖励
        if (pTaskInfo->m_subaward > 0)
        {
            if (!ParseTaskSubAward(pMissionInfo, pTaskInfo->m_subaward))
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "MissionManager::LoadConfig....subaward error...missionid:{}, subaward:{}", pMissionInfo->missionId,
                           pTaskInfo->m_subaward);
                return false;
            }
        }
    }
    
    MAP_UINT64_SET_UINT64 mapPost;
    mapPost.clear();
    //构造主线/支线任务关系表
    for (auto ite = m_missionInfoMap.begin(); ite != m_missionInfoMap.end(); ++ite)
    {
        if (ite->second.kind != MISSION_TYPE_ID_TRUNK
            && ite->second.kind != MISSION_TYPE_ID_BRANCH
            && ite->second.kind != MISSION_TYPE_ID_STAGE_GUIDE
            && ite->second.kind != MISSION_TYPE_ID_GOD_EVIL
            && ite->second.kind != MISSION_TYPE_ID_OCCUPATION
            && ite->second.kind != MISSION_TYPE_ID_FLY_UPWARD
            ) {
            continue;
        }
        
        //通过后置任务推导前置任务
        if (ite->second.backTaskId > 0)
        {
            MissionInfo *pBackMission = GetMissionCfgInfo(ite->second.backTaskId);
            if (nullptr == pBackMission)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find back task cfg....missionId:{}", ite->second.backTaskId);
                return false;
            }
            
            if (ite->second.missionId == pBackMission->missionId)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "mission is equal backmission ....missionId:{},backtaskid:{} ",
                           ite->first,
                           ite->second.backTaskId);
                return false;
            }
            
            auto iterFind = ite->second.setPreTask.find(pBackMission->missionId);
            if (iterFind != ite->second.setPreTask.end())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "mission is equal premission ....missionId:{},premission:{} ", ite->first,
                           (*iterFind));
                return false;
            }
            
            //
            if (pBackMission->setPreTask.size() >= pBackMission->setPreTask.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "setPreTask space not enough");
                return false;
            }
            pBackMission->setPreTask.insert(ite->first);
            //
            auto tempIte = mapPost.find(ite->second.missionId);
            if (tempIte != mapPost.end())
            {
                tempIte->second.insert(ite->second.backTaskId);
            }
            else
            {
                SET_UINT64 mission;
                mission.clear();
                mission.insert(ite->second.backTaskId);
                mapPost.insert(make_pair(ite->second.missionId, mission));
            }
        }
    }
    
    //找出每种类型任务的第一个任务
    for (MissionInfoMap::iterator iterMission = m_missionInfoMap.begin(); iterMission != m_missionInfoMap.end(); ++iterMission)
    {
        MissionInfo *pMissionInfo = &iterMission->second;
        if (MISSION_TYPE_ID_ESCORT == pMissionInfo->kind ||
            MISSION_TYPE_ID_GOD_EVIL == pMissionInfo->kind ||
            MISSION_TYPE_ID_OCCUPATION == pMissionInfo->kind ||
            MISSION_TYPE_ID_FLY_UPWARD == pMissionInfo->kind ||
            MISSION_TYPE_ID_WEEK_LOOP == pMissionInfo->kind) {
            //神魔,护送仙女,转职任务需要过滤掉，转职任务是由其他系统接取，任务系统不会自动接取
            continue;
        }
        
        if (pMissionInfo->setPreTask.size() <= 0)
        {
            auto iterPre = m_missionFirstMap.find(pMissionInfo->kind);
            if (iterPre != m_missionFirstMap.end())
            {
                auto &setMission = iterPre->second;
                if (setMission.size() >= setMission.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "_missionFirstMap setmission space not enough!");
                    return false;
                }
                
                setMission.insert(pMissionInfo->missionId);
                
                //主线只有一条线，前置任务为0 的不允许有多个，
                if (MISSION_TYPE_ID_TRUNK == pMissionInfo->kind)
                {
                    if (setMission.size() > 1)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] trunk has multi first mission..%s ",
                                   NFCommon::tostr(std::set<uint64_t>(setMission.begin(), setMission.end())));
                    }
                }
            }
            else
            {
                if (m_missionFirstMap.size() >= m_missionFirstMap.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "_missionFirstMap Space Not Enough!");
                    return false;
                }
                m_missionFirstMap[pMissionInfo->kind].insert(pMissionInfo->missionId);
            }
            
            //按等级统计
            auto iterLv = m_mapLevMission.find(pMissionInfo->accept.minLevel);
            if (iterLv != m_mapLevMission.end())
            {
                if (iterLv->second.size() >= iterLv->second.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapLevMission set space not enough");
                    return false;
                }
                iterLv->second.insert(pMissionInfo->missionId);
            }
            else
            {
                if (m_mapLevMission.size() >= m_mapLevMission.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapLevMission space not enough");
                    return false;
                }
                m_mapLevMission[pMissionInfo->accept.minLevel].insert(pMissionInfo->missionId);
            }
        } // end of if (pMissionInfo->setPreTask.size() <= 0)
        
        //统计接取条件中前置任务完成可接取的任务
        for (auto iterPreOr = pMissionInfo->accept.setPreOrMission.begin(); iterPreOr != pMissionInfo->accept.setPreOrMission.end(); ++iterPreOr)
        {
            uint64_t preId = (*iterPreOr);
            auto iterA = m_mapPreAcceptMap.find(preId);
            if (iterA != m_mapPreAcceptMap.end())
            {
                if (iterA->second.size() >= iterA->second.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAcceptMap set space not enough");
                    return false;
                }
                iterA->second.insert(pMissionInfo->missionId);
            }
            else
            {
                if (m_mapPreAcceptMap.size() >= m_mapPreAcceptMap.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAcceptMap space not enough");
                    return false;
                }
                m_mapPreAcceptMap[preId].insert(pMissionInfo->missionId);
            }
        }
        
        for (auto iterPreAnd = pMissionInfo->accept.setPreAndMission.begin(); iterPreAnd != pMissionInfo->accept.setPreAndMission.end(); ++iterPreAnd)
        {
            uint64_t preId = (*iterPreAnd);
            auto iterA = m_mapPreAcceptMap.find(preId);
            if (iterA != m_mapPreAcceptMap.end())
            {
                if (iterA->second.size() >= iterA->second.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAcceptMap set space not enough");
                    return false;
                }
                iterA->second.insert(pMissionInfo->missionId);
            }
            else
            {
                if (m_mapPreAcceptMap.size() >= m_mapPreAcceptMap.max_size())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAcceptMap space not enough");
                    return false;
                }
                
                m_mapPreAcceptMap[preId].insert(pMissionInfo->missionId);
            }
        }
    }
    
    //检查主支线任务的后置任务数量,目前主支线任务的后置 在当前条件下只能接取一个，或者只能有一个后置任务
    MAP_UINT64_SET_UINT64::iterator backIter = mapPost.begin();
    for (; backIter != mapPost.end(); ++backIter)
    {
        SET_UINT64 &setBack = backIter->second;
        if (setBack.size() > 1)
        {
            char szPre[20] = {'\0'};
            
            snprintf(szPre, 20, "%lu == ", backIter->first);
            string strlog = "[logic] check mission back num :";
            strlog += szPre;
            SET_UINT64::iterator iterSet = setBack.begin();
            for (; iterSet != setBack.end(); ++iterSet)
            {
                uint64_t missionId = (*iterSet);
                char szTmp[20] = {'\0'};
                snprintf(szTmp, 20, "%lu,", missionId);
                strlog += szTmp;
            }
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, " %s ", strlog.c_str());
        }
    }
    mapPost.clear();
    
    //检查死循环任务
    for (MissionInfoMap::iterator ite = m_missionInfoMap.begin(); ite != m_missionInfoMap.end(); ++ite) {
        if (ite->second.kind != MISSION_TYPE_ID_TRUNK
            && ite->second.kind != MISSION_TYPE_ID_BRANCH
            && ite->second.kind != MISSION_TYPE_ID_STAGE_GUIDE
            && ite->second.kind != MISSION_TYPE_ID_GOD_EVIL
            && ite->second.kind != MISSION_TYPE_ID_OCCUPATION
            && ite->second.kind != MISSION_TYPE_ID_FLY_UPWARD
            ) {
            continue;
        }
        
        MissionInfo *pMissionInfo = &ite->second;
        if (pMissionInfo->setPreTask.size() >= 2) {
            std::string errorInfo;
            for (auto pre_iter = pMissionInfo->setPreTask.begin(); pre_iter != pMissionInfo->setPreTask.end(); pre_iter++) {
                errorInfo += NFCommon::tostr(*pre_iter) + ",";
            }
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] the prev task of the trunk task:%ld  can't has many the prev mission:%s the dead cycle task", pMissionInfo->missionId, errorInfo.c_str());
            return false;
        }
    }
    
    return true;
}

bool TaskDescEx::ProcessDyMission()
{
    auto pTaskDynamicDesc = TaskdynamicTaskdynamicDesc::Instance()->GetResDescPtr();
    NF_ASSERT(pTaskDynamicDesc);
    
    for (auto iter = pTaskDynamicDesc->begin(); iter != pTaskDynamicDesc->end(); iter++)
    {
        auto &cfg = iter->second;
        DyMissionInfo dyInfo;
        dyInfo.missionId = cfg.m_taskID;
        dyInfo.kind = cfg.m_taskType;
        dyInfo.minLev = cfg.m_minlv;
        dyInfo.maxLev = cfg.m_maxlv;
        dyInfo.canAccept = cfg.m_receCount;
        dyInfo.weights = cfg.m_weights;
        //随机条件ID列表
        string strCondtion = cfg.m_idList.data();
        NFCommonApi::SplitStrToSetInt64(strCondtion, ";", &dyInfo.setComplete);
        //校验所有的条件必须在条件表存在
        for (auto iterCond = dyInfo.setComplete.begin(); iterCond != dyInfo.setComplete.end(); ++iterCond)
        {
            uint64_t condId = (*iterCond);
            const DyConditionInfo *pDyCondCfg = GetDyConditionCfgInfo(condId);
            if (nullptr == pDyCondCfg)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ProcessDyMission....can not find condition config...id:{}, condid:{} ", dyInfo.missionId, condId);
                return false;
            }
            dyInfo.totalRate += pDyCondCfg->rate;
        }

        //
        auto iterType = m_dymissionTypeMap.find(dyInfo.kind);
        if (iterType != m_dymissionTypeMap.end())
        {
            if (iterType->second.size() >= iterType->second.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_dymissionTypeMap  Space Not Enough");
                return false;
            }
            iterType->second.insert(dyInfo.missionId);
        }
        else
        {
            if (m_dymissionTypeMap.size() >= m_dymissionTypeMap.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "m_dymissionTypeMap NFShmHashSet<uint64_t, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM> Space Not Enough");
                return false;
            }
            m_dymissionTypeMap[dyInfo.kind].insert(dyInfo.missionId);
        }

        m_dymissionInfoMap[dyInfo.kind] = dyInfo;
    }
    return true;
}

bool TaskDescEx::ProcessDyCondition()
{
    auto pTaskCondDesc = TaskdynamicTaskcomcondDesc::Instance()->GetResDescPtr();
    NF_ASSERT(pTaskCondDesc);
    
    for (auto iter = pTaskCondDesc->begin(); iter != pTaskCondDesc->end(); iter++)
    {
        auto &cfg = iter->second;
        DyConditionInfo dyInfo;
        dyInfo.condId = cfg.m_comcondID;
        dyInfo.rate = cfg.m_comcondRandomValue;
        //
        dyInfo.cond.itemType = cfg.m_comcondType;
        dyInfo.cond.itemId = cfg.m_param1;
        dyInfo.cond.itemCount = cfg.m_param2;
        dyInfo.cond.parma1 = cfg.m_param3;
        dyInfo.cond.parma2 = cfg.m_param4;
        dyInfo.cond.parma3 = cfg.m_param5;
        //
        SParseFinishParam param;
        param.traceId = cfg.m_comcondID;
        //
        if (!CheckFinishCond(dyInfo.cond, param))
        {
            return false;
        }
        
        if (nullptr != GetDyConditionCfgInfo(dyInfo.condId))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ProcessDyCondition....repeat cond cfg...id:{} ", dyInfo.condId);
            return false;
        }
        
        if (m_dycondtionInfoMap.size() >= m_dycondtionInfoMap.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "_dycondtionInfoMap Not Enough Space.........");
            return false;
        }
        
        m_dycondtionInfoMap[dyInfo.condId] = dyInfo;
    }
    return true;
}

bool TaskDescEx::ProcessReward()
{
    auto pMapCfg = TaskrewardTaskrewardDesc::Instance()->GetResDescPtr();
    if (nullptr != pMapCfg)
    {
        for (auto iter = pMapCfg->begin(); iter != pMapCfg->end(); ++iter)
        {
            auto &info = iter->second;
            
            std::vector<TaskComplex> reward;
            //
            for (auto iterAttr = info.m_attr.begin(); iterAttr != info.m_attr.end(); ++iterAttr)
            {
                auto &attr = (*iterAttr);
                if (attr.m_id <= 0 || attr.m_val <= 0)
                {
                    continue;
                }
                TaskComplex complex;
                complex.type = MISSION_AWARD_ATTR;
                complex.id = attr.m_id;
                complex.value = attr.m_val;
                //
                if (!CheckRewardParam(info.m_id, complex.type, complex.id))
                {
                    return false;
                }
                reward.push_back(complex);
            }
            //
            for (auto iterItem = info.m_item.begin(); iterItem != info.m_item.end(); ++iterItem)
            {
                auto &item = (*iterItem);
                if (item.m_box > 0) {
                    TaskComplex complex;
                    complex.type = MISSION_AWARD_GOODS;
                    complex.id = 0;
                    complex.value = 1;
                    complex.bind = item.m_bind;
                    complex.profession = item.m_prof;
                    complex.boxId = item.m_box;
                    reward.push_back(complex);
                }
                
                if (item.m_id <= 0 || item.m_val <= 0)
                {
                    continue;
                }
                
                TaskComplex complex;
                complex.type = MISSION_AWARD_GOODS;
                complex.id = item.m_id;
                complex.value = item.m_val;
                complex.bind = item.m_bind;
                complex.profession = item.m_prof;
                //
                auto pItemCfg = ItemItemDesc::Instance()->GetDesc(item.m_id);
                if (nullptr == pItemCfg)
                {
                    auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(item.m_id);
                    if (nullptr == pEquipCfg)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "ProcessReward()....nullptr == pEquipCfg...id:{}, taskType:{}, lv:{}, itemid:{} ",
                                   info.m_id, info.m_taskType, info.m_lv, item.m_id);
                        return false;
                    }
                    else
                    {
                        complex.type = MISSION_AWARD_EQUIP;
                    }
                }
                reward.push_back(complex);
            }
            
            if (info.m_guildExp > 0)
            {
                TaskComplex complex;
                complex.type = MISSION_AWARD_UNION_EXP;
                complex.id = info.m_guildExp;
                reward.push_back(complex);
            }
            
            if (info.m_guildPoint > 0)
            {
                TaskComplex complex;
                complex.type = MISSION_AWARD_USE_CONTRI;
                complex.id = info.m_guildPoint;
                reward.push_back(complex);
            }
            
            if (reward.size() > 0)
            {
                if (TaskrewardTasktypeDesc::Instance()->GetDesc(info.m_taskType))
                {
                    uint32_t key = ComposeDyRewardKey(info.m_taskType, info.m_lv);
                    DyTaskRewardMap::iterator iterReward = m_mapDyReward.find(key);
                    if (iterReward != m_mapDyReward.end())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0,
                                   "ProcessReward()...iterReward != m_mapDyReward.end()...info.m_tasktype:{}  info.m_lv:{}",
                                   info.m_taskType, info.m_lv);
                        return false;
                    }
                    
                    if (m_mapDyReward.size() >= m_mapDyReward.max_size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapDyReward Space Not Enough");
                        return false;
                    }
                    
                    if (m_mapDyReward[key].max_size() < reward.size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapDyReward vector Space Not Enough");
                        return false;
                    }
                    m_mapDyReward[key].assign(reward.begin(), reward.end());
                }
            }
        }
    }
    return true;
}

bool TaskDescEx::CheckFinishCond(InterItemPair &item, SParseFinishParam &param)
{
    uint64_t monsId = 0;
    bool checkMons = false;
    uint64_t areaId = 0;
    bool checkArea = false;
    uint64_t itemId = 0;
    bool checkItem = false;
    uint64_t equipId = 0;
    bool checkEquip = false;
    uint64_t boxId = 0;
    bool checkBox = false;
    uint64_t dupId = 0;
    bool checkDup = false;
    uint64_t dupGroupId = 0;
    bool checkDupGroup = false;
    uint64_t actionId = 0;
    bool checkAction = false;
    //uint64_t pathid = 0;
    bool checkPath = false;
    //uint64_t aptitudeId = 0;
    bool checkAptitude = false;
    //uint64_t giftid = 0;
    bool checkGift = false;
    
    if (MISSION_FINISH_TYPE_KILL_MONS == item.itemType)
    {
        monsId = item.itemId;
        checkMons = true;
        areaId = item.parma1;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_KILL_MONS_TRACE_PATH == item.itemType)
    {
        monsId = item.itemId;
        //    pathid = item.parma1;
        checkMons = true;
        checkPath = true;
    }
    else if (MISSION_FINISH_TYPE_KILL_MONS_AREA == item.itemType)
    {
        monsId = item.itemId;
        areaId = item.parma1;
        checkMons = true;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_TAKL == item.itemType)
    {
        //    pathid = item.parma1;
        checkPath = true;
    }
    else if (MISSION_FINISH_TYPE_COLLECT_ITEM == item.itemType)
    {
        itemId = item.itemId;
        monsId = item.parma1;
        boxId = item.parma2;
        areaId = item.parma3;

        checkItem = true;
        checkMons = true;
        checkBox = true;
        checkArea = true;

    }
    else if (MISSION_FINISH_TYPE_COLLECT_KILL_MONS == item.itemType)
    {
        itemId = item.itemId;
        monsId = item.parma1;
        boxId = item.parma2;
        //    pathid = item.parma3;

        checkItem = true;
        checkMons = true;
        checkBox = true;
        checkPath = true;
    }
    else if (MISSION_FINISH_TYPE_COLLECT_CLIENT == item.itemType)
    {
        itemId = item.itemId;
        areaId = item.parma2;
        checkItem = true;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_COLLECT_JUST == item.itemType) //策划确认这里的NPC不用校验
    {
        itemId = item.itemId;
        checkItem = true;
    }
    else if (MISSION_FINISH_TYPE_COLLECT_MONS == item.itemType)
    {
        itemId = item.itemId;
        boxId = item.parma2;

        checkItem = true;
        checkBox = true;
    }
    else if (MISSION_FINISH_TYPE_PASS_DUP == item.itemType || MISSION_FINISH_TYPE_PASS_DUP1 == item.itemType)
    {
        dupId = item.itemId;
        checkDup = true;
    }
    else if (MISSION_FINISH_TYPE_PASS_DUP_GROUP == item.itemType || MISSION_FINISH_TYPE_PASS_DUP_GROUP1 == item.itemType)
    {
        dupGroupId = item.itemId;
        checkDupGroup = true;
    }
    else if (MISSION_FINISH_TYPE_USE_ITEM == item.itemType)
    {
        itemId = item.itemId;
        areaId = item.parma1;
        checkItem = true;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_SUBMIT_ITEM == item.itemType) //策划确认这里的NPC不用校验
    {
        itemId = item.itemId;
        checkItem = true;
    }
    else if (MISSION_FINISH_TYPE_SUBMIT_EQUIP == item.itemType)
    {
        equipId = item.itemId;
        checkEquip = true;
    }
    else if (MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP == item.itemType ||
        MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP == item.itemType ||
        MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP == item.itemType)
    {

    }
    else if (MISSION_FINISH_TYPE_AREA == item.itemType)
    {
        areaId = item.itemId;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_USE_THING == item.itemType)
    {
        monsId = item.itemId;
        checkMons = true;
        areaId = item.parma1;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_USE_THING_PATH == item.itemType)
    {
        monsId = item.itemId;
        checkMons = true;
        //    pathid = item.parma1;
        checkPath = true;
    }
    else if (MISSION_FINISH_TYPE_FINISH_ACTION == item.itemType)
    {
        actionId = item.itemId;
        areaId = item.parma1;
        checkAction = true;
        checkArea = true;
    }
    else if (MISSION_FINISH_TYPE_APTITUDE == item.itemType)
    {
        //   aptitudeId = item.itemId;
        checkAptitude = true;
    }
    else if (MISSION_FINISH_TYPE_FETCH_GIFT == item.itemType)
    {
        //   giftid = item.itemId;
        checkGift = true;
    }
    else if (MISSION_FINISH_TYPE_SPECIAL_COLLECT == item.itemType || MISSION_FINISH_TYPE_SPECIAL_COLLECT2 == item.itemType)
    {
        monsId = item.itemId;
        areaId = item.parma1;
        checkMons = true;
        checkArea = true;
    }
    //
    if (checkMons)
    {
        auto *pMonsCfg = MonsterMonsterDesc::Instance()->GetDesc(monsId);
        if (nullptr == pMonsCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find monster confg ...missionId:{},dupid:{},traceid:{}, condtype:{}, monsid:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, monsId);
            return false;
        }
    }
    if (checkArea)
    {
        auto *pAreaCfg = PointPointDesc::Instance()->GetDesc(areaId);
        if (nullptr == pAreaCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "can not find  area confg ...missionId:{},dupid:{},traceid:{}, condtype:{}, monsid:{},pointid:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, monsId, areaId);
            return false;
        }
    }
    if (checkPath)
    {

    }
    if (checkItem)
    {
        auto *pItemCfg = ItemItemDesc::Instance()->GetDesc(itemId);
        if (nullptr == pItemCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find item confg ...missionId:{},dupid:{},traceid:{}, condtype:{}, itemid:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, itemId);
            return false;
        }
    }
    if (checkEquip)
    {
        auto *pEquipCfg = EquipEquipDesc::Instance()->GetDesc(equipId);
        if (nullptr == pEquipCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find equip confg ...missionId:{},dupid:{},traceid:{}, condtype:{}, equipId:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, equipId);
            return false;
        }
    }
    if (checkBox)
    {
        auto *pBoxCfg = BoxBoxDesc::Instance()->GetDesc(boxId);
        if (nullptr == pBoxCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find box confg ...missionId:{},traceid:{}, condtype:{} boxid:{} ",
                       param.missionId, param.traceId, item.itemType, boxId);
            return false;
        }
    }
    if (checkDup)
    {
        auto *pDupCfg = DupDupDesc::Instance()->GetDesc(dupId);
        if (nullptr == pDupCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find duplicate confg  ...missionId:{},dupid:{},traceid:{}, condtype:{}, dupId:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, dupId);
            return false;
        }
    }
    if (checkDupGroup)
    {
        auto *pGroupCfg = DupGroupDesc::Instance()->GetDesc(dupGroupId);
        if (nullptr == pGroupCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find duplicate group confg  ...missionId:{},traceid:{}, condtype:{], dupGroupId:{} ",
                       param.missionId, param.traceId, item.itemType, dupGroupId);
            return false;
        }
    }
    
    if (checkAction)
    {
        auto *pButtonCfg = ButtonButtonDesc::Instance()->GetDesc(actionId);
        if (nullptr == pButtonCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can not find button confg ...missionId:{},dupid:{},traceid:{}, condtype:{}, actionId:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType, actionId);
            return false;
        }
    }
    
    if (checkAptitude)
    {

    }
    
    if (checkGift)
    {

    }
    
    return true;
}

const DyMissionInfo *TaskDescEx::GetDyMissionCfgInfo(uint64_t missionId)
{
    DyMissionInfoMap::iterator iter = m_dymissionInfoMap.find(missionId);
    return (iter != m_dymissionInfoMap.end()) ? &iter->second : nullptr;
}

const DyConditionInfo *TaskDescEx::GetDyConditionCfgInfo(uint64_t condId)
{
    auto iter = m_dycondtionInfoMap.find(condId);
    return (iter != m_dycondtionInfoMap.end()) ? &iter->second : nullptr;
}

bool TaskDescEx::ParseMissionCond(MissionInfo *pMissionInfo, const std::string &strParam)              //解析任务接取条件
{
    NF_ASSERT(pMissionInfo != nullptr);
    SParaseAcceptParam param;
    param.kind = pMissionInfo->kind;
    param.missionId = pMissionInfo->missionId;
    bool ret = ParseAcceptCond(pMissionInfo->accept, strParam, param);
    if (ret)
    {
        if (pMissionInfo->accept.functionId > 0)
        {
            m_mapFuntionMission[pMissionInfo->accept.functionId].insert(pMissionInfo->missionId);
        }
    }
    return true;
}

bool TaskDescEx::ParseTaskExecute(MissionInfo *pMissionInfo, const std::string &sExecute)      //解析任务完成条件
{
    NF_ASSERT(pMissionInfo != nullptr);
    SParseFinishParam param;
    param.missionId = pMissionInfo->missionId;
    return ParseFinishCond(pMissionInfo->execute, sExecute, param);
}

bool TaskDescEx::ParseTaskReceAdd(MissionInfo *pMissionInfo, const std::string &sReceAdd)
{
    NF_ASSERT(pMissionInfo != nullptr);
    std::vector<std::string> vecStr;
    //接取分隔符
    NFCommonApi::SplitStr(sReceAdd, "&", &vecStr);
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        std::vector<std::string> sonVecStr;
        NFCommonApi::SplitStr(vecStr[i], "=", &sonVecStr);
        
        if (sonVecStr.size() <= 0)
        {
            continue;
        }
        
        if (sonVecStr.size() != 6)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ParseTaskReceAdd but size not equal 6 ...missionId={}", pMissionInfo->missionId);
            return false;
        }
        
        //默认有6个字段
        if (sonVecStr[0] == "" || sonVecStr[1] == "" || sonVecStr[2] == "" || sonVecStr[3] == "" || sonVecStr[4] == "")
        {
            continue;
        }
        
        TaskComplex complex;
        complex.type = atoi(sonVecStr[0].c_str());
        complex.id = atoi(sonVecStr[1].c_str());
        complex.value = atoi(sonVecStr[2].c_str());
        complex.time = atoi(sonVecStr[3].c_str());
        complex.bind = atoi(sonVecStr[4].c_str());
        
        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }
        
        if (pMissionInfo->receAdd.size() >= pMissionInfo->receAdd.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "pMissionInfo->receAdd Space Not Enough");
            return false;
        }
        
        pMissionInfo->receAdd.push_back(complex);
    }
    return true;
}

bool TaskDescEx::ParseAcceptCond(AcceptInfo &accept, const std::string &strAcceptParam, SParaseAcceptParam &param)
{
    std::vector<std::string> vecStr;
    vecStr.clear();
    //接取分隔符
    NFCommonApi::SplitStr(strAcceptParam, "&", &vecStr);
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        std::vector<std::string> sonVecStr;
        NFCommonApi::SplitStr(vecStr[i], ";", &sonVecStr);
        int32_t isize = sonVecStr.size();
        if (isize != 6)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ParseAcceptCond....isize != 6...kind:{},missionid:{},isize:{} ", param.kind, param.missionId, isize);
            return false;
        }
        
        //第一位表示的是类型
        if (sonVecStr[0] == "")
        {
            continue;
        }
        uint32_t type = atoi(sonVecStr[0].c_str());
        
        // M_ACCEPT_TYPE_PRE_OR_CHAPTER  和  M_ACCEPT_TYPE_PRE_AND_MISSION 只允许出现再支线中
        if ((M_ACCEPT_TYPE_PRE_OR_CHAPTER == type || M_ACCEPT_TYPE_PRE_AND_CHAPTER == type)
            && param.kind != MISSION_TYPE_ID_BRANCH
            )
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "MissionManager::ParseAcceptCond....M_ACCEPT_TYPE_PRE_OR_CHAPTER and M_ACCEPT_TYPE_PRE_AND_CHAPTER is only allowed in branch and adventure mission...kind:{},accept_type:{},missionid:{}",
                       param.kind, type, param.missionId);
            return false;
        }
        //解析该类型下面的数据
        //前置任务（或关系）
        if (type == M_ACCEPT_TYPE_PRE_OR_CHAPTER)
        {
            for (int32_t j = 1; j < 6; ++j)
            {
                uint64_t preId = atoll(sonVecStr[j].c_str());
                if (preId > 0)
                {
                    if (accept.setPreOrMission.size() >= accept.setPreOrMission.max_size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "accept.setPreOrMission Not Enough Space");
                        return false;
                    }
                    
                    accept.setPreOrMission.insert(preId);
                    //
                    auto iterA = m_mapPreOrAcceptMap.find(preId);
                    if (iterA != m_mapPreOrAcceptMap.end())
                    {
                        if (iterA->second.size() >= iterA->second.max_size())
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreOrAcceptMap iter->second Not Enough Space");
                            return false;
                        }
                        iterA->second.insert(param.missionId);
                    }
                    else
                    {
                        if (m_mapPreOrAcceptMap.size() >= m_mapPreOrAcceptMap.max_size())
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreOrAcceptMap Not Enough Space");
                            return false;
                        }
                        m_mapPreOrAcceptMap[preId].insert(param.missionId);
                    }
                }
            }
        }
            //职业
        else if (type == M_ACCEPT_TYPE_PROFESSION)
        {
            if (sonVecStr[1] == "")
            {
                continue;
            }
            accept.profession = atoi(sonVecStr[1].c_str());
            if (!proto_ff::ERoleProf_IsValid(accept.profession))
            {

               NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "MissionManager::ParseAcceptCond....ECharacterProf_IsValid...missionid:%lu,kind:%u,accept_type:%u,prof:%u ",
                                 param.missionId, param.kind, type, accept.profession);
                return false;
            }
            return false;
        }
            //前置任务（与关系）
        else if (type == M_ACCEPT_TYPE_PRE_AND_CHAPTER)
        {
            for (int32_t j = 1; j < 6; ++j)
            {
                uint64_t preId = atoll(sonVecStr[j].c_str());
                if (preId > 0)
                {
                    if (accept.setPreAndMission.size() >= accept.setPreAndMission.max_size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "accept.setPreAndMission Not Enough Space");
                        return false;
                    }
                    accept.setPreAndMission.insert(preId);
                    //
                    auto iterA = m_mapPreAndAcceptMap.find(preId);
                    if (iterA != m_mapPreAndAcceptMap.end())
                    {
                        if (iterA->second.size() >= iterA->second.max_size())
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAndAcceptMap iterA->second Not Enough Space");
                            return false;
                        }
                        iterA->second.insert(param.missionId);
                    }
                    else
                    {
                        if (iterA->second.size() >= iterA->second.max_size())
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "m_mapPreAndAcceptMap Not Enough  Space");
                            return false;
                        }
                        m_mapPreAndAcceptMap[preId].insert(param.missionId);
                    }
                }
            }
        }
        else if (type == M_ACCEPT_TYPE_FUNCTION_ID)
        {
            if (sonVecStr[1] == "")
            {
                continue;
            }
            accept.functionId = atoi(sonVecStr[1].c_str());
            if (accept.functionId > 0)
            {
                auto pFunctionId = FunctionunlockFunctionunlockDesc::Instance()->GetDesc(accept.functionId);
                if (pFunctionId == NULL)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "ParseAcceptCond....FunctionunlockFunctionunlockDesc()->GetDesc...missionid:%lu,kind:%u,accept_type:%u,funcId:%u ",
                                     param.missionId, param.kind, type, accept.functionId);
                    return false;
                }
            }
        }
        else
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "MissionManager::ParseAcceptCond....unkown type...kind:%u,missionid:%lu,type:%u ", param.kind,
                       param.missionId, type);
            return false;
        }
    }
    return true;
}

bool TaskDescEx::CheckRewardParam(uint64_t missionId, uint32_t type, uint64_t id)
{
    if (MISSION_AWARD_GOODS == type || MISSION_AWARD_EQUIP == type)
    {
        auto pItemCfg = ItemItemDesc::Instance()->GetDesc(id);
        if (nullptr == pItemCfg)
        {
            auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(id);
            if (nullptr == pEquipCfg)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "CheckRewardParam mission{}....nullptr == pEquipCfg || pItemCfg type:{},itemid:{} ", missionId, type,
                           id);
                return false;
            }
        }
    }
    else if (MISSION_AWARD_ATTR == type)
    {
        if (NFAttrMgr::Instance(m_pObjPluginManager)->ValidFightAttrId(id)) {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] MissionManager::CheckRewardParam missionId:%s...ValidFightAttrId type:%u, attrid:%lu ", missionId, type, id);
            return false;
        }
    }
    else if (MISSION_AWARD_SKILL == type)
    {
        auto pSkillCfg = SkillSkillDesc::Instance()->GetDesc(id);
        if (nullptr == pSkillCfg)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CheckRewardParam mission{}....nullptr == pSkillCfg type:{},itemid:{} ", missionId, type, id);
            return false;
        }
    }
    
    return true;
}

//解析完成条件(公用接口)
bool TaskDescEx::ParseFinishCond(InterExecute &conds, const std::string &strFinish, SParseFinishParam &param)
{
    std::vector<std::string> vecStr;
    vecStr.clear();
    //接取分隔符
    NFCommonApi::SplitStr(strFinish, "&", &vecStr);
    for (uint32_t i = 0; i < vecStr.size(); i++)
    {
        std::vector<std::string> sonVecStr;
        sonVecStr.clear();
        NFCommonApi::SplitStr(vecStr[i], ";", &sonVecStr);
        
        if (sonVecStr.size() != 6)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ParseFinishCond but size not num 6 ...missionId:{},dupid:{},traceid:{}", param.missionId,
                       param.dupId, param.traceId);
            return false;
        }
        
        InterItemPair item;
        item.itemType = atoi(sonVecStr[0].c_str());
        item.itemId = atoll(sonVecStr[1].c_str());
        item.itemCount = atoll(sonVecStr[2].c_str());
        item.parma1 = atoll(sonVecStr[3].c_str());
        item.parma2 = atoll(sonVecStr[4].c_str());
        item.parma3 = atoll(sonVecStr[5].c_str());
        
        if (item.itemType <= MIN_MISSION_COND_TYPE)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0,
                       "[logic] MissionManager::ParseFinishCond item.itemType <= MIN_MISSION_COND_TYPE ...missionId:{},dupid:{},traceid:{}, condtype:{} ",
                       param.missionId, param.dupId, param.traceId, item.itemType);
        }
        
        if (!CheckFinishCond(item, param))
        {
            return false;
        }
        
        conds.items.push_back(item);
    }
    return true;
}

bool TaskDescEx::ParseTaskSubAward(MissionInfo *pMissionInfo, int64_t sSubAward)
{
    NF_ASSERT(pMissionInfo);
    
    auto pCfgInfo = TaskrewardTaskrewardDesc::Instance()->GetDesc(sSubAward);
    if (pCfgInfo == NULL)
    {
        return true;
    }
    
    if (pCfgInfo->m_guildExp > 0)
    {
        TaskComplex complex;
        complex.type = MISSION_AWARD_UNION_EXP;
        complex.id = pCfgInfo->m_guildExp;
        complex.value = 0;
        complex.time = 0;
        complex.bind = 0;
        complex.profession = 0;
        
        if (complex.profession != 0 && !proto_ff::ERoleProf_IsValid(complex.profession))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ParseTaskSubAward profession error ...missionId={}, complex.profession:{}",
                       pMissionInfo->missionId, complex.profession);
            return false;
        }
        
        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }
        
        pMissionInfo->subAward.push_back(complex);
    }
    
    if (pCfgInfo->m_guildPoint > 0)
    {
        TaskComplex complex;
        complex.type = MISSION_AWARD_USE_CONTRI;
        complex.id = pCfgInfo->m_guildPoint;
        complex.value = 0;
        complex.time = 0;
        complex.bind = 0;
        complex.profession = 0;
        
        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }
        
        pMissionInfo->subAward.push_back(complex);
    }
    
    if (pCfgInfo->m_skillId > 0)
    {
        TaskComplex complex;
        complex.type = MISSION_AWARD_SKILL;
        complex.id = pCfgInfo->m_skillId;
        complex.value = 0;
        complex.time = 0;
        complex.bind = 0;
        complex.profession = 0;

        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }

        pMissionInfo->subAward.push_back(complex);
    }
    
    for (int i = 0; i < (int) pCfgInfo->m_attr.size(); i++)
    {
        if (pCfgInfo->m_attr[i].m_id <= 0)
            continue;
        
        TaskComplex complex;
        complex.type = MISSION_AWARD_ATTR;
        complex.id = pCfgInfo->m_attr[i].m_id;
        complex.value = pCfgInfo->m_attr[i].m_val;
        complex.time = 0;
        complex.bind = 0;
        complex.profession = 0;
        
        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }
        
        pMissionInfo->subAward.push_back(complex);
    }
    
    for (int i = 0; i < (int) pCfgInfo->m_item.size(); i++)
    {
        if (pCfgInfo->m_item[i].m_id <= 0)
            continue;
        
        TaskComplex complex;
        complex.type = MISSION_AWARD_GOODS;
        complex.id = pCfgInfo->m_item[i].m_id;
        complex.value = pCfgInfo->m_item[i].m_val;
        complex.time = 0;
        complex.bind = pCfgInfo->m_item[i].m_bind;
        complex.profession = pCfgInfo->m_item[i].m_prof;
        
        if (complex.profession != 0 && !proto_ff::ERoleProf_IsValid(complex.profession))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "ParseTaskSubAward profession error ...missionId={},complex.profession:{}",
                       pMissionInfo->missionId, complex.profession);
            return false;
        }
        
        if (!CheckRewardParam(pMissionInfo->missionId, complex.type, complex.id))
        {
            return false;
        }
        
        pMissionInfo->subAward.push_back(complex);
    }
    
    return true;
}

MissionInfo *TaskDescEx::GetMissionCfgInfo(uint64_t missionId)
{
    auto iter = m_missionInfoMap.find(missionId);
    return (iter != m_missionInfoMap.end()) ? &iter->second : nullptr;
}

bool TaskDescEx::ProcessDyText()    //处理动态任务前端显示
{
    auto pTextCfg = TaskdynamicTasktextDesc::Instance()->GetResDescPtr();
    if (nullptr != pTextCfg)
    {
        for (auto iter = pTextCfg->begin(); iter != pTextCfg->end(); ++iter)
        {
            auto &info = iter->second;
            VEC_INT32 vecTaskType;
            vecTaskType.clear();
            if (!info.m_taskType.empty())
            {
                string strType = info.m_taskType.data();
                NFCommonApi::SplitStrToVecInt(strType, "&", &vecTaskType);
            }
            if (vecTaskType.size() <= 0)
            {
                continue;
            }
            SET_UINT64 setKey;
            setKey.clear();
            //
            for (auto iterType = vecTaskType.begin(); iterType != vecTaskType.end(); ++iterType)
            {
                int32_t taskType = (*iterType);
                uint64_t key = ComposeTextKey(taskType, info.m_comcondType);
                setKey.insert(key);
            }
            //
            for (auto iterKey = setKey.begin(); iterKey != setKey.end(); ++iterKey)
            {
                uint64_t keyA = (*iterKey);
                auto iterKeyEx = m_dymissionTextMap.find(keyA);
                if (iterKeyEx != m_dymissionTextMap.end())
                {
                    if (iterKeyEx->second.size() >= iterKeyEx->second.max_size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "_dymissionTextMap set Space Not Enough");
                        return false;
                    }
                    iterKeyEx->second.insert(info.m_textID);
                }
                else
                {
                    if (m_dymissionTextMap.size() >= m_dymissionTextMap.max_size())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "_dymissionTextMap Space Not Enough");
                        return false;
                    }
                    m_dymissionTextMap[keyA].insert(info.m_textID);
                }
            }
        }
    }
    
    return true;
}

//组装text表的key
uint64_t TaskDescEx::ComposeTextKey(int32_t missionType, int32_t condType)
{
    int64_t resmissionType = (int64_t) missionType;
    int32_t rescondType = (int32_t) condType;
    
    uint64_t key = DY_MISSION_TEXT_KEY(resmissionType, rescondType);
    return key;
}

//组装动态任务奖励key
uint32_t TaskDescEx::ComposeDyRewardKey(int32_t taskType, int32_t level)
{
    return (uint32_t) (DY_MISSION_REWARD_KEY(taskType, level));
}

const NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM> *TaskDescEx::GetFirstMissionByType(int32_t missionType)
{
    auto iter = m_missionFirstMap.find(missionType);
    if (iter != m_missionFirstMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

const NFShmHashSet<uint64_t, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>* TaskDescEx::GetDyMissionLstByType(int32_t missionType) const
{
    auto iter = m_dymissionTypeMap.find(missionType);
    return (iter != m_dymissionTypeMap.end()) ? &iter->second : nullptr;
}

const NFShmHashSet<uint64_t, MAX_TASK_TASK_NUM> *TaskDescEx::GetPreAcceptMission(uint64_t missionId)
{
    auto iter = m_mapPreAcceptMap.find(missionId);
    return (iter != m_mapPreAcceptMap.end()) ? &iter->second : nullptr;
}

uint64_t TaskDescEx::GetDyTextId(int32_t missionType, uint32_t condType)
{
    return GetDyTextId(ComposeTextKey(missionType, condType));
}

uint64_t TaskDescEx::GetDyTextId(uint64_t key)
{
    auto iter = m_dymissionTextMap.find(key);
    if (iter == m_dymissionTextMap.end())
    {
        return 0;
    }
    
    auto &setText = iter->second;
    std::vector<uint32_t> vec(setText.begin(), setText.end());
    int32_t isize = vec.size();
    if (isize <= 0)
    {
        return 0;
    }
    
    int32_t rnd = NFRandInt(0, isize);
    return vec[rnd];
}

//获取动态任务奖励
const TASK_REWARD *TaskDescEx::GetDyMissionReward(int32_t missionType, int32_t level)
{
    uint32_t key = ComposeDyRewardKey(missionType, level);
    DyTaskRewardMap::iterator iter = m_mapDyReward.find(key);
    return (iter != m_mapDyReward.end()) ? &iter->second : nullptr;
}

	//获取等级接取任务列表
const NFShmHashSet<uint64_t, MAX_LEV_MISSION_NUM>* TaskDescEx::GetLevMission(uint32_t level)
{
    auto iter = m_mapLevMission.find(level);
    if (iter != m_mapLevMission.end())
    {
        return &iter->second;
    }
    return nullptr;
}


	//获取等级接取任务列表
const NFShmHashSet<uint64_t, MAX_FUNCTION_MISSION_NUM>* TaskDescEx::GetFunctionMission(uint64_t functionId)
{
    auto iter = m_mapFuntionMission.find(functionId);
    if (iter != m_mapFuntionMission.end())
    {
        return &iter->second;
    }
    return nullptr;
}
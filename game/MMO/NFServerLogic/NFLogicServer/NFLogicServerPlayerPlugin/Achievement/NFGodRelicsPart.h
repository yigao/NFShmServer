// -------------------------------------------------------------------------
//    @FileName         :    NFGodRelicsPart.h
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGodRelicsPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "Part/NFPart.h"
#include "DescStore/GodrelicsConditionDesc.h"

struct stGodRelicsTaskGroupEntry;

//天机谱任务
struct stGodRelicsTaskEntry
{
    int64_t task_cfg_id;
    int32_t cur_num;
    int32_t all_num;
    int32_t task_state; //0:no finish //1:finish //2:repair
    
    stGodRelicsTaskEntry()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        clear();
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    void clear()
    {
        task_cfg_id = 0;
        cur_num = 0;
        task_state = proto_ff::EN_GODRELICS_TASK_STATUS_NOT_FINISH;
        all_num = 0;
    }
    
    stGodRelicsTaskEntry(int64_t task_cfg_id, int32_t cur_num, int32_t task_state, int32_t all_num)
    {
        this->task_cfg_id = task_cfg_id;
        this->cur_num = cur_num;
        this->task_state = task_state;
        this->all_num = all_num;
    }
    
    void WriteToPB(proto_ff::GodRelicsTaskEntry *pProto)
    {
        if (!pProto)return;
        pProto->set_task_cfg_id(task_cfg_id);
        pProto->set_cur_num(cur_num);
        pProto->set_task_state(task_state);
        pProto->set_all_num(all_num);
    }
};

//天机谱任务组组数据
struct stGodRelicsTaskGroupEntry
{
    int64_t group_cfg_id;
    int32_t normal_reward_state; //0 未解锁 //1 未完成 //2 完成 //领取奖励
    uint64_t create_time;
    NFShmHashMap<int64_t, stGodRelicsTaskEntry, MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM> task_map;
    
    stGodRelicsTaskGroupEntry()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        clear();
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    void clear()
    {
        group_cfg_id = 0;
        normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_NOT_UNLOCK;
        create_time = 0;
        task_map.clear();
    }
    
    void ReadFromPB(const proto_ff::GodRelicsTaskGroupEntry &group)
    {
        clear();
        this->group_cfg_id = group.group_cfg_id();
        this->normal_reward_state = group.normal_reward_state();
        this->create_time = group.create_time();
        
        for (int32_t i = 0; i < group.entrys_size(); i++)
        {
            const proto_ff::GodRelicsTaskEntry &e = group.entrys(i);
            task_map[e.task_cfg_id()] = stGodRelicsTaskEntry(e.task_cfg_id(), e.cur_num(), e.task_state(), e.all_num());
        }
    }
    
    stGodRelicsTaskGroupEntry(int64_t group_cfg_id)
    {
        this->group_cfg_id = group_cfg_id;
        this->normal_reward_state = proto_ff::EN_GODRELICS_GROUP_TASK_STATUS_NOT_UNLOCK;
        this->create_time = NFTime::GetZeroTime(NFTime::Now().UnixSec());
        task_map.clear();
    }
    
    void WriteToPB(proto_ff::GodRelicsTaskGroupEntry *pEntry)
    {
        if (!pEntry)return;
        pEntry->set_group_cfg_id(group_cfg_id);
        pEntry->set_normal_reward_state(normal_reward_state);
        pEntry->set_create_time(create_time);
        for (auto iter = task_map.begin(); iter != task_map.end(); iter++)
        {
            proto_ff::GodRelicsTaskEntry *pC = pEntry->add_entrys();
            if (!pC)continue;
            iter->second.WriteToPB(pC);
        }
    }
    
    stGodRelicsTaskEntry *getTask(int64_t id)
    {
        auto iter = task_map.find(id);
        return iter != task_map.end() ? &(iter->second) : nullptr;
    }
    
    void addTask(int64_t id, int32_t all_num)
    {
        if (getTask(id)) return;
        task_map[id] = stGodRelicsTaskEntry(id, 0, proto_ff::EN_GODRELICS_TASK_STATUS_NOT_FINISH, all_num);
    }
    
    int32_t getTaskNum(int64_t id)
    {
        stGodRelicsTaskEntry *pEntry = getTask(id);
        if (!pEntry)return 0;
        return pEntry->cur_num;
    }
    
    int32_t getTaskState(int64_t id)
    {
        stGodRelicsTaskEntry *pEntry = getTask(id);
        if (!pEntry)return 0;
        return pEntry->task_state;
    }
    
    bool isFinish()
    {
        for(auto iter = task_map.begin(); iter != task_map.end(); iter++)
        {
            if (iter->second.task_state != proto_ff::EN_GODRELICS_TASK_STATUS_GET_REWARD)
            {
                return false;
            }
        }
        return true;
    }
};

class NFGodRelicsPart : public NFShmObjTemplate<NFGodRelicsPart, EOT_LOGIC_PART_ID+PART_GODRELIS, NFPart>
{
public:
    NFGodRelicsPart();
    
    virtual ~NFGodRelicsPart();
    
    int CreateInit();
    int ResumeInit();
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData& data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData& data);
    
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
    virtual int OnLogin() { return 0; }
    virtual int OnLogin(proto_ff::PlayerInfoRsp& playerInfo) { return 0; }
    
    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }
    
    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }
    
    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto& outproto) { return 0; }
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();
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
     * @brief 获得天机谱活动数据
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleGetGodRelicsInfo(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 领取小任务奖励
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleGetGodRelicsTaskReward(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 领取任务组奖励，以及通知新的任务组
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleGetGodRelecsGroupTaskReward(uint32_t msgId, NFDataPackage &packet);
public:
    stGodRelicsTaskGroupEntry* GetGroup(int64_t groupId);
    stGodRelicsTaskGroupEntry* InsertGroup(int64_t groupId);
    stGodRelicsTaskEntry* GetTask(int64_t groupId, int64_t taskId);
    bool IsPrevFinish(int64_t groupId, int64_t taskId);
    bool IsFinishGroup(int64_t groupId);
private:
    NFShmHashMap<int64_t, stGodRelicsTaskGroupEntry, UNIQUE_KEY_MAX_INDEX_GODRELICS_CONDITION_GROUP_NUM> m_groupMap;
    int64_t m_curGroupId;
};
// -------------------------------------------------------------------------
//    @FileName         :    NFActivityDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFActivityDefine
//
// -------------------------------------------------------------------------

#pragma once

#include <Activity.pb.h>

#include "NFComm/NFCore/NFPlatform.h"

//帮派神兽最大排名
#define FACTION_BEAST_MAX_RANK 10
//烛龙挑战最大排名
#define CANDLE_MAX_RANK 10
//烛龙挑战 - 本服开服天数限制
#define CANDLE_FIVE_OPEN_DAY 5
//烛龙挑战 - 本服开服天数限制
#define CANDLE_TWELVE_OPEN_DAY 12

//活动类型
enum class EActType
{
    none = 0,
    trans = 1,              //帮派传功
    dinner = 2,             //帮派晚宴
    godvalley = 3,          //神机谷
    protect = 4,            //双倍护送
    beast = 5,              //帮派神兽
    mountain_top = 6,       //青云之巅
    faction_protect = 7,    //帮派守护
    cross_1v1 = 8,          //跨服1v1
    deitywar = 9,           //封神之战
    pool = 10,              //圣母瑶池
    peakpk = 11,            //巅峰对决
    citywar = 12,           //圣天城战
    nightwar = 13,          //夜战云巅
    herowar = 14,           //群雄逐鹿
    detective = 15,         //双倍刺探
    cross_3v3 = 16,         //跨服3v3
    cross_factionwar = 17,  //跨服帮战
    spy = 18,               //刺探活动
    candle = 19,            //烛龙挑战(天天养龙)
    huimengxiyou = 20,      //回梦游仙
    xianxia = 21,      //仙侠事件
	limit,
};

//活动状态
enum class EActState
{
	close = 0,			// 关闭
	open = 1,			// 开启
    forever_close = 2,  // 永久结束
    limit,
};

//活动初始化参数
struct ActInitParam
{
	uint64_t curtime = 0;
	uint64_t zerotime = 0;
	uint64_t week_zerotime = 0;
};
//
enum class EActChkResult
{
	run = 0,		//活动进行中
	not_run = 1,	//活动不在进行中
	end = 2,		//活动结束了
	error = 3,		//错误
};

////////////////////////////////////////////////////////////////////////////////////////////////

//活动状态
enum ACTIVITY_STATE
{
    AS_NOT_START = 0,	// 未开启
    AS_READY = 1,		// 准备
    AS_RUNNING = 2,		// 进行中
    AS_END = 3,			// 结束
    AS_TIME_OUT = 4		// 过期
};

//活动ID类型
enum ACTIVITY_TYPE_ID
{
    ATI_NONE = 0,
    ATI_MAX,						//最大类型
};

enum
{
    MINI_ACTIVITY_GOD_RELICS = 0,
    MINI_ACTIVITY_DAILY_TASK = 1,
    MINI_ACTIVITY_MAX,
};

//天机谱任务类型
enum EN_GODRELICS_TASK_TYPE
{
    EN_GODRELICS_TASK_TYPE_FINISH_MAIN_TASK = 1,    //1:完成特定的主线任务，参数-任务ID
    EN_GODRELICS_TASK_TYPE_MONEY_REWARD_TASK = 2,        //2:完成赏金任务xxx次，参数- 次数
    EN_GODRELICS_TASK_TYPE_TRANS_PROF = 3,            //3:完成转职xxx转，参数- 转职等级
    EN_GODRELICS_TASK_TYPE_LEVEL = 4,            //3:角色等级达到xxx级，参数- 角色等级
    EN_GODRELICS_TASK_TYPE_FINISH_DUP = 5,            //3:通关指定的副本xxx次，参数- 副本ID，副本次数
};

//Daily任务类型
enum EN_DAILY_TASK_TYPE
{
    EN_DAILY_TASK_TYPE_DAILY_TASK = 1, //每日任务
    EN_DAILY_TASK_TYPE_LIMIT_TASK = 2, //每日限时任务
};

// 活动简单数据
struct stActBaseData
{
    uint32_t activity_inst_id;		//活动实例ID
    int64_t activity_id;			//活动ID
    int32_t  state;					//活动状态，0 关闭，1 开启
    uint64_t begin_time;		 	//活动开始时间(针对开启的活动来说)
    uint64_t end_time;		 		//活动结束时间(针对开启的活动来说)
    uint64_t forward_finish_time; 	//提前完成时间
    uint32_t zid;					//zid
    VEC_INT32	see_zid_list;		//活动开放的zone列表
    VEC_INT32	finish_zid_list;	//提前完成活动的ZID
    stActBaseData()
    {
        clear();
    }
    ~stActBaseData()
    {
        clear();
    }
    void clear()
    {
        activity_inst_id = 0;
        activity_id = 0;
        state = 0;
        begin_time = 0;
        end_time = 0;
        forward_finish_time = 0;
        zid = 0;
        see_zid_list.clear();
        finish_zid_list.clear();
    }

    void fillProto(proto_ff::ActBaseDataProto *pProto) const
    {
        if (!pProto)return;
        pProto->set_activity_inst_id(activity_inst_id);
        pProto->set_activity_id(activity_id);
        pProto->set_state(state);
        pProto->set_begin_time(begin_time);
        pProto->set_end_time(end_time);
        pProto->set_forward_finish_time(forward_finish_time);
        pProto->set_zid(zid);
        for (auto iter = see_zid_list.begin(); iter != see_zid_list.end(); iter++)
        {
            pProto->add_see_zid_list(*iter);
        }
        for (auto iter = finish_zid_list.begin(); iter != finish_zid_list.end(); iter++)
        {
            pProto->add_forward_finish_zid(*iter);
        }
    }

    void Deserialize(proto_ff::ActBaseDataProto *pProto)
    {
        if (!pProto)return;
        clear();
        activity_inst_id = pProto->activity_inst_id();
        activity_id = pProto->activity_id();
        state = pProto->state();
        begin_time = pProto->begin_time();
        end_time = pProto->end_time();
        forward_finish_time = pProto->forward_finish_time();
        zid = pProto->zid();
        for (int32_t i = 0; i < pProto->see_zid_list_size(); i++)
        {
            see_zid_list.push_back(pProto->see_zid_list(i));
        }
        for (int32_t i = 0; i < pProto->forward_finish_zid_size(); i++)
        {
            finish_zid_list.push_back(pProto->forward_finish_zid(i));
        }
    }

    stActBaseData& operator =(const stActBaseData & b)
    {
        clear();
        proto_ff::ActBaseDataProto proto;
        b.fillProto(&proto);
        Deserialize(&proto);
        return *this;
    }

    bool hasZoneId(int32_t zoneid)
    {
        auto iter = std::find(see_zid_list.begin(), see_zid_list.end(), zoneid);
        return iter != see_zid_list.end() ? true : false;
    }

    bool hasForwardFinish(int32_t zoneid)
    {
        auto iter = std::find(finish_zid_list.begin(), finish_zid_list.end(), zoneid);
        return iter != finish_zid_list.end() ? true : false;
    }
};

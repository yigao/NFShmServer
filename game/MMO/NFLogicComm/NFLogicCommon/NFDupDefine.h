// -------------------------------------------------------------------------
//    @FileName         :    NFDupDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-10-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDupDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFGameCommon/NFComTypeDefine.h"


//副本最大星级数
#define DUPLICATE_MAX_STAR 3

//副本默认拾取状态时间
#define DUP_PICK_STATE_SEC 30		//这个时间不要随便修改
//副本默认清理状态时间
#define DUP_CLEAN_STATE_SEC 15		//这个时间不要随便修改
//副本默认清理状态时间的最大时间
#define DUP_CLEAN_STATE_MAX_SEC 600
//副本默认销毁状态时间
#define DUP_DESTORY_STATE_SEC 30	//这个时间不要随便修改
//副本排队人数上限
#define DUP_QUEUE_MAX_NUM	30

//副本死亡复活时间
#define DUP_RELIVE_SEC 15


enum  DupState
{
    Dup_state_none = 0,
    Dup_state_wait_create = 1,		//等待创建状态 (中心服已经创建了副本，等待逻辑服返回中)
    Dup_state_created = 2,			//副本准备状态 (副本创建完成，等待玩家进入阶段）
    Dup_state_begin_cd = 3,			//副本战前倒计时状态，如果有倒计时就会有这个状态，这个独立出来。
    Dup_state_begin = 4,			//副本开始状态 (玩家已经进入副本,开始通关副本，多人副本要等待所有人都进入才开始）
    Dup_state_finsh = 5,			//副本完成状态 (副本完成，客户端弹出副本结算界面，通知客户端副本结果,完成态等待倒计时进入清理态）
    Dup_state_clean = 6,			//副本清理状态 (清理玩家退出副本，清理副本，清理场景)
    Dup_state_destory = 7,			//副本销毁状态 (开始销毁副本）
    Dup_state_limit = 8,
};


//副本任务类型
enum  EDupTaskType
{
    EDupTaskType_None = -1,
    EDupTaskType_Empty = 0,				//没有条件
    EDupTaskType_time_win	= 1,		//1，到时间胜利
    EDupTaskType_kill_num	= 2,		//2，指定时间内消灭所有怪物，才能通关；超时失败
    EDupTaskType_kill_monster  = 3,		//3，击杀指定的怪物
    EDupTaskType_kill = 4,				//4, 竞技场用
    EDupTaskType_time_out_fail = 5,		//5, 超时失败
    EDupTaskType_kill_expect_num = 6,   //6, 杀多少只怪
    EDupTaskType_Limit = 7,
};
//条件检测状态
enum EDupCondState
{
    EDupCondState_none = 0, //条件检测未启动
    EDupCondState_run = 1,	//条件检测启动检测
    EDupCondState_finish = 2, //条件检测完毕
};
//副本结果
enum EDupResult
{
    EDupResult_none = -1,	//副本还没有产生结果
    EDupResult_success = 0,	//副本成功或胜利
    EDupResult_failed = 1,	//副本失败
};


enum EDupMode
{
    EDupMode_none = 0,
    EDupMode_com = 1,				//普通杀怪本(一次创建所有怪物)
    EDupMode_unlimit = 2,			//无限制刷怪(经验本,无限刷经验等)
    EDupMode_wave = 3,				//波次本
    //其他特殊玩法在加
    EDupMode_marry = 4,				//结婚副本
    EDupMode_limit					//
};

//角色在副本行为
enum EDupRoleAction
{
    EDupRoleAction_none = 0,
    EDupRoleAction_enter_dup = 1,
    EDupRoleAction_leave_dup = 2,
    EDupRoleAction_limit
};

//副本类型
enum  EDupType
{
    EDupType_None = 0,
    EDupType_tower = 1,			//爬塔(凡人修真)
    EDupType_level = 2,			//等级(等级副本)
    EDupType_boss = 3,			//boss专属副本
    EDupType_deify = 4,			//封神台
    EDupType_pet = 5,			//宠物
    EDupType_bagua = 6,			//八卦
    EDupType_dragon_pre = 7,	//养龙寺前传
    EDupType_dragon = 8,		//养龙寺
    EDupType_boat = 9,			//仙舟
    EDupType_equip = 10,		//装备
    EDupType_rares = 11,		//藏宝图秘境
    EDupType_srares = 12,		//高级藏宝图秘境
    EDupType_Arena = 13,		//竞技场副本
    EDupType_Transfer =14,		//转职
    EDupType_FlyUp = 15,		//飞升
    EDupType_Land = 16,			//帮派领地
    EDupType_cross_boss = 17,	//跨服boss副本
    EDupType_marry = 18,		//结婚副本
    EDupType_FactionGuard = 19, //帮派守卫
    EDupType_Beast = 20,		//帮派神兽副本
    EDupType_Wedding = 21,		//婚宴副本
    EDupType_1v1 = 22,			//1v1副本
    EDupType_qy = 23,			//青云之巅
    EDupType_CrossWar = 24,		//跨服帮派战
    EDupType_3v3_wait = 25,		//3v3等待场景
    EDupType_3v3 = 26,			//3v3场景
    EDupType_Candle = 27,		//烛龙挑战(天天养龙)
    EDupType_XiYouReady = 28,   //回梦西游准备副本
    EDupType_XiYouRouBaozi = 29,   //回梦西游肉包子
    EDupType_XiYouCaiJiu = 30,   //回梦西游采酒
    EDupType_XiYouKillBoss = 31,   //回梦西游打boss
    EDupType_Plane = 32,		//位面副本
    EDupType_ghost = 33,		//幽灵古殿
    EDupType_task = 34,			//给任务用
    EDupType_moyu = 35,			//镇魂魔域(工会)
    EDupType_yaota = 36,		//九层妖塔
    EDupType_Limit,
};

//副本组ID
enum EDupGroupID
{
    EDupGroupID_tower = 101,		//爬塔（凡人修真)
    EDupGroupID_level = 102,		//福利
    EDupGroupID_deify = 103,		//天神
    EDupGroupID_pet = 104,			//宠物
    EDupGroupID_bagua = 105,		//八卦
    EDupGroupID_dragon_pre = 107,	//养龙寺前传
    EDupGroupID_dragon = 108,		//养龙寺
    EDupGroupID_candle = 109,		//烛龙挑战(天天养龙)
    EDupGroupID_boat = 201,			//仙舟
    EDupGroupID_equip = 202,		//装备
    EDupGroupID_ghost = 203,		//幽灵古殿
    EDupGroupID_yaota = 204,		//九层妖塔
    EDupGroupID_boss = 301,			//boss
    EDupGroupID_rares = 401,		//藏宝图秘境
    EDupGroupID_srares = 402,		//高级藏宝图秘境
    EDupGroupID_arena = 403,		//竞技场
    EDupGroupID_transfer = 501,		//转职副本
    EDupGroupID_flyup = 502,		//飞升副本
    EDupGroupID_land = 503,			//帮派领地
    EDupGroupID_cross_boss = 504,	//跨服boss副本
    EDupGroupID_marry = 505,		//结婚副本
    EDupGroupID_guard = 506,		//帮派守卫
    EDupGroupID_beast = 507,		//帮派神兽
    EDupGroupID_wedding = 600,		//婚宴副本
    EDupGroupID_qy = 700,			//青云之巅
    EDupGroupID_3v3_wait = 800,		//3v3等待场景
    EDupGroupID_3v3 = 801,			//3v3场景
    EDupGroupID_XiYouReady = 802,		//回梦西游
    EDupGroupID_XiYouKillBoss = 803,		//回梦西游
    EDupGroupID_XiYouCollect = 804,		//回梦西游
    EDupGroupID_XiYouRouBaoZi = 805,		//回梦西游
    EDupGroupID_task = 810,				//任务用
    EDupGroupID_Plane = 901,		//位面
    EDupGroupID_moyu = 902,			//魔域
};

enum class EDupPlaneType
{
    none,
    task = 1,
    limit,
};


//中心服创建副本参数
struct CDupInit
{
    uint64_t sceneId = 0;				//副本uid，直接使用场景id
    uint32_t logicId = 0;				//逻辑服ID
    uint64_t dupId = 0;					//副本id，配置id
    uint64_t cid = 0;					//创建副本的玩家cid
    uint64_t keyVal = 0;				//副本keytype对应的key值
    uint64_t keyType = 0;				//创建类型
    uint32_t teamId = 0;				//队伍ID
    uint64_t mapId = 0;					//地图ID
    string param;						//字符串参数
};

enum DupRes
{
    DupRes_create_failed = 1,	//逻辑服创建副本失败了
    DupRes_wait_create_out = 2,	//中心服等待超时
};

//副本
struct SDup
{
    uint64_t nDupId;		//副本ID
    uint8_t nStar;			//星级
    SDup()
    {
        nDupId = 0;
        nStar = 0;
    }
};
//副本组
struct SDupGroup
{
    uint64_t groupId;		//副本组ID
    int32_t enterNum;		//已进入次数
    int32_t buyNum;			//已经购买的次数
    int32_t useNum;			//使用物品次数
    uint64_t lastFresh;		//上次进入的时间
    SDupGroup()
    {
        groupId = 0;
        enterNum = 0;
        buyNum = 0;
        useNum = 0;
        lastFresh = 0;
    }

};

//副本数据
typedef std::unordered_map<uint64_t, SDup> DupMap;
//副本组数据
typedef std::unordered_map<uint64_t, SDupGroup> DupGroupMap;

struct stDupTowerRecordEntry
{
    std::string name;
    uint64_t time = 0;
    uint64_t cid = 0;
};

struct stDupTowerRecord
{
    uint64_t id = 0;
    std::list<stDupTowerRecordEntry> entrys;
};

//爬塔副本数据
struct DupTower
{
    SET_UINT64 ids;
};

using DupRecordMap = std::unordered_map<uint64_t, SDup>;
using DupGroupRecordMap = std::unordered_map<uint32_t, DupRecordMap>; //groupID

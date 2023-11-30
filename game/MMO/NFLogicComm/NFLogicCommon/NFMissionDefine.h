// -------------------------------------------------------------------------
//    @FileName         :    NFMIssionDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-2-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFMIssionDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "Mission.pb.h"
#include "NFPackageDefine.h"
#include "E_Taskreward_s.h"

#define INVALID_MISSION_ID          (0)    //非法任务id
#define MISSION_COND_TYPE_TO_EVENT(type)    (type / 100) //任务完成条件类型转换到事件类型
#define MIN_MISSION_COND_TYPE 100 //最小的任务完成条件类型
#define MISSION_ALL_DY_MISSION_TYPE -1 //所有的动态任务类型
#define MISSION_ALL_DY_ITEM_LEVEL -1 //所有的物品等级
#define MISSION_INFINITE_COUNT -1 //无限次数
#define MISSION_COMCOND_MAX_COUNT 10 //最大物品条件数

#define MISSION_ARE_MONS_PER_NUM  5 //怪追踪区域每次刷新的怪物数量(到达区域直接杀怪)
#define MISSION_RATION_BASE 10 //任务奖励倍率基数
const uint32_t MISSION_MAX_ACCEPT_NUM = 20; //已接列表最大只能接取20个
const uint32_t MISSION_MAX_DYNAMIC_ALLOC = (MISSION_MAX_ACCEPT_NUM * 5); //动态任务ID最大分配ID

/**
* 任务事件类型
*/
enum MISSION_EVENT_TYPE
{
    M_EVENT_KILL_MONSTER = 1,                        //杀怪
    M_EVENT_TALK = 2,                        //对话
    M_EVENT_COLL_COLLECT_ITEM = 3,                        //收集物品，计算操作次数
    M_EVENT_PASS_DUPLICATE = 4,                        //通关副本
    M_EVENT_USE_GOODS = 5,                        //使用物品
    M_EVENT_INBUFF = 6,                        //处于某种BUFF
    M_EVENT_ANSWER = 7,                        //答题
    M_EVENT_AREA_FLAG = 8,                        //区域类型任务
    E_EVENT_USETHING_FINISH = 9,                        //使用物件
    M_EVENT_ACTION_BUTTON = 10,                        //行为逻辑
    M_EVENT_LEVEL = 11,                        //等级达到多少级
    //M_EVENT_GOD_LEVEL						= 101,						//神格升级
    //M_EVENT_REFINE_EQUIP					= 102,						//精炼装备
    M_EVENT_GUIDE_DESCRIPTIONS = 100,    //引导描述 什么都不做，只是用来客户端给人看的
    M_EVENT_JOIN_GUILD = 101,                        //加入工会
    M_EVENT_ADD_FRIEND = 102,                        //加好友
    M_EVENT_KILL_BOSS = 103,                         //kill boss
    M_EVENT_DEPUTY_COLLECT = 104,                        //副业采集
    M_EVENT_DEPUTY_MAKE = 105,                        //副业打造
    M_EVENT_SKILL_LEVEL = 106,                        //技能升级
    M_EVENT_ANY_GOD_LEVEL = 107,                        //任意神格升级
    M_EVNET_ANY_REFINE_EQUIP = 108,                        //任意装备精炼
    M_EVENT_RUNE_DW = 110,                        //武器雕文
    M_EVENT_EMBLEM_INLAY = 111,                        //纹章镶嵌
    M_EVENT_ANY_STONE_INLAY = 112,                        //任意宝石镶嵌
    //M_EVENT_SOUL_STAR_MARK				= 112,						//心魂标记
    //M_EVENT_EMBLEM_ACTIVE					= 113,						//纹章激活
    M_EVENT_SLOT_STREN = 113,                        //槽位强化
    M_EVENT_APTITUDE = 114,                        //转职资质

    M_EVENT_TREASURE_LEV = 115,                        //宝具等级
    M_EVENT_PARTNER_RANKLEV = 116,                        //契灵等阶
    M_EVENT_WING_LEV = 117,                        //翅膀等级


    M_EVENT_ATTR_POINT = 120,                        //属性洗点
    M_EVENT_ARENA_JOIN = 121,                        //进入竞技场
    M_EVENT_LADDER = 122,                        //天梯层数
    M_EVENT_INFINITE_HUNT = 123,                        //无限狩猎
    M_EVENT_CONNVOY_COMMIT = 124,                        //提交镖车
    M_EVENT_LOOPMISSIONNUM = 125,                        //完成循环任务事件
    M_EVENT_BOUNTYMISSIONNUM = 126,                        //完成赏金

    M_EVENT_ARENA = 130,                        //竞技场挑战次数
    M_EVENT_FETCH_OPERATE = 131,                        //领取运营活动奖励
    M_EVENT_JOIN_CAMP = 140,                        //加入阵营
    M_EVENT_ANY_GUILD_FIGHT_LEVEL = 151,                        //任意工会精修
    M_EVENT_ANY_RUN_BUSINESS = 152,                        //任意工会跑商
    M_EVENT_ANY_ESCORT = 153,                        //任意物资护送
    M_EVENT_LIGHT_SOUL = 154,                   //点亮龙魂
    M_EVENT_CROSS_3V3 = 160,                    //跨服3v3

};

/**
* 任务事件数据结构体
*/
struct ExecuteData
{
    uint32_t type;                                //事件类型
    uint64_t id;                                    //物品id
    int32_t count;                                    //这次操作数量 count为正数表示相加 count为负数表示相减
    uint64_t killer;                                //击杀者id,杀怪任务特定参数
    int32_t source;                                    //物品来源
    ExecuteData(uint32_t type_ = 0, uint64_t id_ = 0, int32_t count_ = 0, uint64_t playerId = 0, int32_t src = 0) : type(type_), id(id_),
                                                                                                                    count(count_), killer(playerId),
                                                                                                                    source(src)
    {

    }
};

/**
* 任务类型
*/
enum MISSION_TYPE_FLAG
{
    MISSION_TYPE_ID_TRUNK = 1,                //主线
    MISSION_TYPE_ID_BRANCH = 2,                //支线
    MISSION_TYPE_ID_OCCUPATION = 3,            //转职任务
    MISSION_TYPE_ID_GOD_EVIL = 4,        //神魔
    MISSION_TYPE_ID_BOUNTY = 5,            //赏金任务
    MISSION_TYPE_ID_BOUNTY_INSTANCE = 7,            //赏金引导
    MISSION_TYPE_ID_ESCORT = 8,            //护送任务
    MISSION_TYPE_ID_FLY_UPWARD = 9,        //飞升任务

    MISSION_TYPE_ID_WEEK_LOOP_INSTANCE = 10,    //周环任务引导
    MISSION_TYPE_ID_WEEK_LOOP = 11,             //周环任务
    MISSION_TYPE_ID_GUILD = 12,                //工会任务
    MISSION_TYPE_ID_GUILD_PRESTIGE_TASK = 13,      //工会帮派声望 占用130-140,用来做奖励
    MISSION_TYPE_ID_GUILD_PRESTIGE_TASK_INSTANCE = 15,      //工会帮派声望
    /*100-105 给工会帮派声望特殊奖励任务用*/
    MISSION_TYPE_ID_HUNT_TREASURE = 16, //探宝
    MISSION_TYPE_ID_HUNT_TREASURE_INSTANCE = 17, //探宝引导
    MISSION_TYPE_ID_HUNT_TREASURE_USE_ITEM18 = 18, //使用物品获得的探宝任务(有两种物品，这是第1种)
    MISSION_TYPE_ID_HUNT_TREASURE_USE_ITEM19 = 19, //使用物品获得的探宝任务(有两种物品，这是第2种)
    MISSION_TYPE_ID_STAGE_GUIDE = 40,        //阶段引导任务
};

/**
* 任务外部系统类型,这个类型主要是针对外部系统的，跟任务本身的业务逻辑没关系（主要用于完成任务触发其他系统，比如活跃度，成就等等）
* 以后每次添加新类型必须注明是哪个系统的，比如藏宝图是针对活跃度的
*/
enum MISSION_OUTTYPE_FLAG
{
    MISSION_OUTTYPE_FLAG_NONE = 0,
    MISSION_OUTTYPE_FLAG_TREASURE = 1, //藏宝图（活跃度）
    MISSION_OUTTYPE_FLAG_LIMIT,
};

//任务接取条件类型
enum MISSION_ACCEPT_TYPE
{
    M_ACCEPT_TYPE_PRE_OR_CHAPTER = 1,            //前置任务（或关系）			1=章节ID=章节ID=章节ID=章节ID=章节ID
    M_ACCEPT_TYPE_PROFESSION = 2,                //职业限制					2=职业=0=0=0=0
    M_ACCEPT_TYPE_SEX = 3,                        //性别限制					3=性别=0=0=0=0
    M_ACCEPT_TYPE_FUNCTION_ID = 4,                //功能开放                 4=功能开放ID=0=0=0=0
    M_ACCEPT_TYPE_PRE_AND_CHAPTER = 7,            //前置任务（与关系）			7=章节ID=章节ID=章节ID=章节ID=章节ID
};

/*
	任务完成条件类型
*/
enum MISSION_FINISH_TYPE
{
    MISSION_FINISH_TYPE_KILL_MONS = 101,        //杀怪								格式 101=怪物id=怪物数量=追踪区域ID=0=0
    MISSION_FINISH_TYPE_KILL_MONS_TRACE_PATH = 102,        //杀怪追踪区域 (只追踪路径点,不杀怪)		格式 102=怪物id=怪物数量=追踪路径id=0=0
    MISSION_FINISH_TYPE_KILL_MONS_AREA = 103,        //杀怪追踪区域	(到达区域直接杀怪)			格式 103=怪物id=怪物数量=追踪区域id=0=0（仅适用刷出怪物）
    MISSION_FINISH_TYPE_KILL_MONS_DUP = 104,        //杀怪(副本)							格式 104=怪物id=怪物数量=追踪副本id=0=0
    MISSION_FINISH_TYPE_KILL_MONS_WILD_BOSS = 105,        //杀怪(野外BOSS)						格式 105=0=怪物数量=ui编号=0=0
    MISSION_FINISH_TYPE_KILL_MONS_BARREN_BOSS = 106,        //杀怪(蛮荒BOSS)						格式 106=0=怪物数量=link id=0=0


    MISSION_FINISH_TYPE_TAKL = 201,        //对话								格式 201=npcid=1=追踪路径id=0=0
    MISSION_FINISH_TYPE_COLLECT_ITEM = 301,        //收集物品							格式 301=物品id=物品数量=生物ID=宝箱id=追踪区域ID（背包中有足够数量，即完成任务）
    MISSION_FINISH_TYPE_COLLECT_KILL_MONS = 302,        //打怪收集							格式 302=物品id=物品数量=生物ID=宝箱id=追踪路径id
    //MISSION_FINISH_TYPE_COLLECT_COLLECT			= 303,		//采集收集						格式 303=物品id=物品数量=采集物id=0=0
    MISSION_FINISH_TYPE_COLLECT_CLIENT = 304,        //刷新采集物获得物品    				格式 304=物品id=物品数量=采集物id=刷新区域id=0
    MISSION_FINISH_TYPE_COLLECT_MONS			= 305,		//采集怪物							格式 305=物品id=物品数量=可采集怪物类型=宝箱id=0
    MISSION_FINISH_TYPE_COLLECT_BUY			    = 306,		//购买收集						格式 306=物品id=物品数量=NPC商店=0=0
    MISSION_FINISH_TYPE_COLLECT_JUST			 = 307,		//收集（背包中有足够数量，即完成任务）						格式 307=物品id=物品数量=0=0=0
    MISSION_FINISH_TYPE_SPECIAL_COLLECT			= 310,		//特殊 先刷新采集物采集收集						格式 310=采集物id=采集物数量=刷新区域id=0=0=0
    MISSION_FINISH_TYPE_SPECIAL_COLLECT2		= 311,		//特殊 先刷新采集物采集收集						格式 310=采集物id=采集物数量=刷新区域id=0=0=0
    MISSION_FINISH_TYPE_EQUIP_KILL_MONS         = 312,      //打世界BOSS掉落装备(312的目的是为了掉落装备，这个条件任务一接取就完成了)  312=装备品阶=装备数量=装备品质=装备星级=boss品阶
    MISSION_FINISH_TYPE_ACTIVE_DEITY            = 313,      //收集物品，激活天神 格式 313=物品id=物品数量=天神ID=出战槽位ID=0(天神ID是avatar表change的id, 出战槽位ID是avatar表battleSlot的id)

    MISSION_FINISH_TYPE_PASS_DUP = 401,        //通关副本							格式 401=副本id=通关次数=0=0=0
    MISSION_FINISH_TYPE_PASS_DUP_GROUP = 402,        //通关副本组							格式 402=副本组id=通关次数=ui编号=0=0
    MISSION_FINISH_TYPE_PASS_DUP1 = 403,        //通关副本							格式 401=副本id=通关次数=0=0=0  区别是这个点击后打开界面，不进行挑战，完成条件还是一样的
    MISSION_FINISH_TYPE_PASS_DUP_GROUP1 = 404,        //通关副本组							格式 402=副本组id=通关次数=ui编号=0=0  区别是这个点击后打开界面，不进行挑战，完成条件还是一样的

    MISSION_FINISH_TYPE_USE_ITEM = 501,        //使用物品     (暂时不用)				格式 501=物品id=物品数量=使用区域=0=0
    MISSION_FINISH_TYPE_SUBMIT_ITEM = 502,        //提交物品							格式 502=物品id=物品数量=0=0=0
    MISSION_FINISH_TYPE_SUBMIT_EQUIP = 503,        //提交装备							格式 503=装备id=装备数量=0=0=0
    MISSION_FINISH_TYPE_SUBMIT_SPEC_EQUIP = 504,        //提交指定品阶指定品质的装备				格式 504=装备品阶=装备数量=装备品质=0=0
    MISSION_FINISH_TYPE_SUBMIT_SPEC2_EQUIP = 505,        //提交指定品阶指定品质的装备				格式 505=装备品阶=装备数量=装备品质=装备星级=装备部位。如穿戴7件3阶红1星装备，装备部位可填多个，如1-2-3-4-5-6-7，表示1~7部位的装备
    MISSION_FINISH_TYPE_SUBMIT_SPEC3_EQUIP = 506,        //提交指定品阶指定品质的装备				格式 505=装备品阶=装备数量=装备品质=装备星级=linkid。如穿戴7件3阶红1星装备，
    //MISSION_FINISH_TYPE_SUBMIT_NPC				= 504,		//提交条件NPC						格式 504=物品id=物品数量=提交条件npc=0=0
    //MISSION_FINISH_TYPE_IN_BUFF					= 601,		//处于某种BUFF					格式 601=buffid=buff等级=0=0=0
    //MISSION_FINISH_TYPE_ANSEER					= 701,		//答题							格式 701=题目id=1=答题npc=0=0
    MISSION_FINISH_TYPE_AREA = 801,        //达到某区域							格式 801=区域id=次数=0=0=0
    MISSION_FINISH_TYPE_USE_THING = 901,        //使用物件       (暂时不用)				格式 901=怪物id=使用次数=刷新区域ID=0=0
    MISSION_FINISH_TYPE_USE_THING_PATH = 902,        //使用物件(路径点)	(暂时不用)			格式 902=怪物id=使用次数=路径点ID=0=0
    MISSION_FINISH_TYPE_FINISH_ACTION = 1001,        //完成行为							格式 1001=行为ID=行为次数=行为区域=0=0
    MISSION_FINISH_TYPE_FINISH_TIANJIPU = 1002,        //完成行为						【打开界面】1002=天机谱ID=linkid=？	//点击打开界面，判断为是否修复成功
    MISSION_FINISH_TYPE_FINISH_JIESUO = 1003,        //完成行为							【原地不动】1003=0 用以单纯的解锁功能，播放引导等，现在都是要一个完成参数
    M_EVENT_GUIDE_DESCRIPTIONS_ACTION = 10001,      //引导描述 什么都不做，只是用来客户端给人看的
    MISSION_FINISH_TYPE_JOIN_GUILD = 10101,    //加入工会							格式 10101=0=1=linkid=0=0
    MISSION_FINISH_TYPE_ADD_FRIEND = 10201,    //添加好友							格式 10201=0=添加好友次数=ui编号=0=0
    MISSION_FINISH_TYPE_BOSS_KILL_BY_QUALITY    = 10301,    //击杀指定品阶指定数量的BOSS  格式 10301=0=boss数量=linkid=boss品阶=0
    MISSION_FINISH_TYPE_BOSS_KILL = 10302,    //击杀指定品阶指定数量的BOSS            格式 10302=bossid=boss数量=linkid=0=0

    MISSION_FINISH_TYPE_EMBLEM_INLAY = 11101,    //任意纹章镶嵌个数						格式 11101=0=指定个数=ui编号=0=0
    MISSION_FINISH_TYPE_ANY_STONE_INLAY = 11201,    //任意宝石镶嵌							格式 11201=0=行为次数=ui编号=0=0
    MISSION_FINISH_TYPE_SLOT_STREN = 11301,    //装备槽位强化等级						格式 11301=0=装备槽位数量=等级=ui编号=0
    MISSION_FINISH_TYPE_APTITUDE = 11401,    //转职资质等级							格式 11301=资质ID(境界ID)=1=Link id=0=0


    MISSION_FINISH_TYPE_ARENA_JOIN = 12101,    //进入竞技场							格式 12101=0=行为次数=ui编号=0=0
    MISSION_FINISH_TYPE_LADDER = 12201,    //纹章宝库层数							格式 12201=0=指定层数=ui编号=0=0

    MISSION_FINISH_TYPE_INFINITE_HUNT = 12301,    //单次无限狩猎经验						格式 12301=value=1=ui编号=0=0
    MISSION_FINISH_TYPE_CONVOY_COMMIT = 12401,    //护送物资次数							格式 12401=0=护送镖车次数=linkid=0=0

    MISSION_FINISH_TYPE_FETCH_GIFT = 13101,    //领取运营礼包							格式 13101=礼包ID=1=LinkID=0=0 (礼包ID取operate_jiangli_tiaoJianId)

    MISSION_FINISH_TYPE_TREASURE_LEV = 11501,    //宝具等级达到指定等级					格式 11501=指定宝具等级=1=linkid=0=0

    MISSION_FINISH_TYPE_PARTNER_RANKLEV = 11601,    //契灵等阶达到指定阶级					格式 11601=指定契灵等阶=1=linkid=0=0

    MISSION_FINISH_TYPE_WING_LEV = 11701,    //翅膀等级达到指定等级					格式 11701=指定翅膀等级=1=linkid=0=0

    MISSION_FINISH_TYPE_LOOPMISSIONNUM = 12501,    //完成诺林冒险指定环数					格式 12501=0=完成诺林冒险环数=linkid=0=0

    MISSION_FINISH_TYPE_LIGHT_SOUL = 15401,   //点亮龙魂 格式 15401=龙魂类型=1=0=0=0

    MISSION_FINISH_TYPE_CROSS_3V3 = 16001, //跨服3v3 格式 16001=0=1=0=0=0
};

/**
* 任务状态
*/
enum MISSION_STATUS_FLAG
{
    MISSION_E_UNACCEPTABLE = 0,        //不可接
    MISSION_E_ACCEPTABLE = 1,        //可接
    MISSION_E_ACCEPTED = 2,            //已接
    MISSION_E_COMPLETION = 3,        //已完成
    MISSION_E_SUBMITTED = 4,        //已提交
    MISSION_E_FAILURE = 5,            //失败
    MISSION_E_ABANDON = 6            //放弃
};

/**
* 任务奖励类型
*/
enum MISSION_AWARD_TYPE
{
    MISSION_AWARD_GOODS = 1,                //道具
    MISSION_AWARD_ATTR = 2,                    //属性奖励类型
    MISSION_AWARD_EQUIP = 3,                //装备
    MISSION_AWARD_SKILL = 4,                //技能奖励
    MISSION_AWARD_UNION_EXP = 5,            //工会经验
    MISSION_AWARD_USE_CONTRI = 6,            //工会可用贡献

    //CTODO后续继续扩展
};

/**
* 刷新规则方式
*/
enum MISSION_UPDATE_TYPE
{
    MISSION_UPDATE_DAY = 1,                //每日
    MISSION_UPDATE_WEEK = 2,            //每周
};

//放弃类型
enum MISSION_ABANDON_TYPE
{
    M_ABANDON_TYPE_REMOVE_CHAPTER = 0,    //移除整个目录
    M_ABANDON_TYPE_ACCEPT_CURRENT = 1,    //当前任务重新接取
    M_ABANDON_TYPE_REMOVE_CURRENT = 2,    //移除当前任务
};

//保存章节类型
enum ECHAPTER_SAVE_TYPE
{
    ECHAPTER_SAVE_TYPE_NONE = 0,            //不记录
    ECHAPTER_SAVE_TYPE_RECV_RECORD = 1,        //接取记录(放弃任务时，不需要从已完成列表移除当前章节)
    ECHAPTER_SAVE_TYPE_SUBMIT_RECORD = 2,    //完成记录(放弃任务时，需要从已完成列表移除当前章节)
};

//任务计数方式
enum EMISSION_CNT_TYPE
{
    EMISSION_CNT_TYPE_ACCEPT = 1, //接取计数
    EMISSION_CNT_TYPE_SUBMIT = 2, //提交计数
};

/*
	动态任务配置
*/
struct DyMissionInfo
{
    uint64_t missionId;                //任务id
    uint32_t kind;                    //任务种类
    uint32_t minLev;                //最低等级
    uint32_t maxLev;                //最高等级
    uint32_t canAccept;                //可接取数量
    uint32_t weights;
    NFShmHashSet<int64_t, 30> setComplete;            //抽取的完成条件ID
    int32_t totalRate;                //抽取的总概率
    DyMissionInfo()
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
        missionId = 0;
        kind = 0;
        minLev = 0;
        maxLev = 0;
        canAccept = 0;
        totalRate = 0;
        weights = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

/**
*
*/
struct InterItemPair
{
    uint32_t itemType;//第1个参数
    uint64_t itemId;  //第2个参数
    uint64_t itemCount;//第3个参数
    uint64_t parma1;//第4个参数
    uint64_t parma2;//第5个参数
    uint64_t parma3;//第6个参数

    InterItemPair()
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
        itemType = 0;
        itemId = 0;
        itemCount = 0;
        parma1 = 0;
        parma2 = 0;
        parma3 = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
    
    InterItemPair(const InterItemPair &item)
    {
        CopyFrom(item);
    }
    
    InterItemPair& operator=(const InterItemPair &item)
    {
        if (this != &item)
        {
            CopyFrom(item);
        }
        return *this;
    }
    
    void CopyFrom(const InterItemPair &item)
    {
        itemType = item.itemType;
        itemId = item.itemId;
        itemCount = item.itemCount;
        parma1 = item.parma1;
        parma2 = item.parma2;
        parma3 = item.parma3;
    }
};

/*
	任务动态完成条件信息
*/
struct DyConditionInfo
{
    int64_t condId;        //条件ID
    InterItemPair cond; //完成条件
    int32_t rate;        //被抽取的概率
    DyConditionInfo()
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
        condId = 0;
        rate = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//解析完成条件时外部参数
struct SParseFinishParam
{
    uint64_t missionId;    //任务ID
    uint64_t dupId;        //副本ID
    uint64_t traceId;    //追踪ID
    SParseFinishParam()
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
        missionId = 0;
        dupId = 0;
        traceId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

#define MAX_PRE_MISSION_NUM 2

/**
* 接取条件类型
*/
struct AcceptInfo
{
    NFShmHashSet<uint64_t, MAX_PRE_MISSION_NUM> setPreOrMission;                     //前置任务（或关系）
    uint32_t profession;                                            //职业
    uint32_t functionId;                        //功能开发ID
    int32_t minLevel;                                               //最小等级限制
    NFShmHashSet<uint64_t, MAX_PRE_MISSION_NUM> setPreAndMission;                    //前置任务（与关系）
    AcceptInfo()
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
        profession = 0;
        minLevel = 0;
        functionId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

/**
* 接取条件类型
*/
struct InterExecute
{
    NFShmVector<InterItemPair, MISSION_COMCOND_MAX_COUNT> items;

    InterExecute()
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
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

/**
* 数据奖励
*/
struct TaskComplex
{
    uint32_t type;                    //奖励类型
    uint64_t id;                    //奖励的id 属性的话对应角色表属性 物品对应物品表
    int64_t value;                    //奖励的数值
    uint32_t time;                    //时间限制
    uint32_t bind;                    //是否绑定
    uint32_t profession;            //职业
    uint32_t boxId;
    //后续继续扩展

    TaskComplex()
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
        type = 0;
        id = 0;
        value = 0;
        time = 0;
        bind = 0;
        profession = 0;
        boxId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//参考taskreward表，可能有13个，定15
typedef NFShmVector<TaskComplex, DEFINE_E_TASKREWARDTASKREWARD_M_ITEM_MAX_NUM+DEFINE_E_TASKREWARDTASKREWARD_M_ATTR_MAX_NUM> TASK_REWARD;

#define MAX_PRE_MISSION_COND 5

/**
* 单个任务信息结构体
*/
struct MissionInfo
{
    uint64_t missionId;                        //任务id
    uint32_t kind;                            //任务类型
    uint32_t progressLev;                    //任务进度等级（任务进度的改变等级）
    AcceptInfo accept;                        //接取条件
    NFShmHashSet<uint64_t, MAX_PRE_MISSION_COND> setPreTask;                    //前置任务
    uint64_t backTaskId;                    //后置任务
    TASK_REWARD receAdd;        //接取任务时发放任务物品
    InterExecute execute;                    //完成条件
    TASK_REWARD subAward;        //固定奖励
    TASK_REWARD subAwardRand;    //可选奖励

    MissionInfo()
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
        missionId = 0;
        kind = 0;
        progressLev = 0;
        backTaskId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//解析接取条件时外部参数
struct SParaseAcceptParam
{
    uint32_t kind;            //任务类型
    uint64_t missionId;        //任务ID
    SParaseAcceptParam()
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
        kind = 0;
        missionId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//判断接取条件时的参数
struct SCanAcceptParam
{
    uint64_t missionId;

    SCanAcceptParam()
    {
        missionId = 0;
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
        missionId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

/**
* 任务物品信息
*/
struct ItemInfo
{
    uint32_t type;                //物品类型(条件类型,条件中第1个参数)
    uint64_t itemId;            //当前值(条件中第2个参数))
    int32_t currentValue;        //完成值
    int32_t finalValue;            //完成值(条件中第3个参数)
    bool completedFlag;            //是否完成标记
    uint64_t parma1;                //保留参数1(条件中第4个参数)
    uint64_t parma2;                //保留参数2(条件中第5个参数)
    uint64_t parma3;                //保留参数3(条件中第6个参数)

    ItemInfo()
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

    ItemInfo(uint64_t parItemId, int32_t parCurrentValue = 0, int32_t parFinalValue = 0, bool parCompletedFlag = false, uint32_t parType = 0,
             uint64_t parParma1 = 0, uint64_t parParma2 = 0, uint64_t parParma3 = 0)
    {
        itemId = parItemId;
        currentValue = parCurrentValue;
        finalValue = parFinalValue;
        completedFlag = parCompletedFlag;
        type = parType;
        parma1 = parParma1;
        parma2 = parParma2;
        parma3 = parParma3;
    }

    int CreateInit()
    {
        itemId = 0;
        currentValue = 0;
        finalValue = 0;
        completedFlag = 0;
        type = 0;
        parma1 = 0;
        parma2 = 0;
        parma3 = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    ItemInfo(const ItemInfo &Value)
    {
        if (this != &Value)
        {
            itemId = Value.itemId;
            currentValue = Value.currentValue;
            finalValue = Value.finalValue;
            completedFlag = Value.completedFlag;
            type = Value.type;
            parma1 = Value.parma1;
            parma2 = Value.parma2;
            parma3 = Value.parma3;
        }
    }

    inline ItemInfo &operator=(const ItemInfo &Value)
    {
        itemId = Value.itemId;
        currentValue = Value.currentValue;
        finalValue = Value.finalValue;
        completedFlag = Value.completedFlag;
        type = Value.type;
        parma1 = Value.parma1;
        parma2 = Value.parma2;
        parma3 = Value.parma3;
        return (*this);
    }

    bool IsSpecialCond()
    {
        return type == MISSION_FINISH_TYPE_EQUIP_KILL_MONS;
    }
};


/**
* 玩家单个任务数据
*/
struct MissionTrack
{
    uint64_t missionId;                    //任务ID（配置ID）
    uint64_t dynamicId;                    //动态任务ID（针对动态任务来说的,主支线和配置ID相同）
    uint32_t missionType;               //任务类型
    uint32_t status;                    //任务当前状态
    uint64_t acceptMissionTime;            //接取任务时间
    NFShmVector<ItemInfo, MISSION_COMCOND_MAX_COUNT> items;        //<ItemInfo>，这个任务的物品数据
    uint64_t textId;                    //前端显示用的id(对应taskcontent中text表)

    MissionTrack()
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

    ~MissionTrack()
    {
        status = 0;
        acceptMissionTime = 0;
        items.clear();
        missionId = 0;
        dynamicId = 0;
        missionType = 0;
        textId = 0;
    }

    int CreateInit()
    {
        status = 0;
        acceptMissionTime = 0;
        items.clear();
        missionId = 0;
        dynamicId = 0;
        missionType = 0;
        textId = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    //设置任务proto信息
    bool SetMissionTrackProto(proto_ff::CharacterDBMissionTrack &missionProto) const
    {
        missionProto.set_missionid(missionId);
        missionProto.set_dynamicid(dynamicId);
        missionProto.set_missiontype(missionType);
        missionProto.set_textid(textId);
        missionProto.set_status(status);
        missionProto.set_acceptmissiontime(acceptMissionTime);
        for (uint32_t i = 0; i < items.size(); i++)
        {
            proto_ff::CharacterDBMissionItemInfo *pItemInfo = missionProto.add_iteminfo();
            pItemInfo->set_type(items[i].type);
            pItemInfo->set_id(items[i].itemId);
            pItemInfo->set_currentvalue(items[i].currentValue);
            pItemInfo->set_finalvalue(items[i].finalValue);
            pItemInfo->set_completedflag(items[i].completedFlag);
            pItemInfo->set_parma1(items[i].parma1);
            pItemInfo->set_parma2(items[i].parma2);
            pItemInfo->set_parma3(items[i].parma3);
        }

        return true;
    }

    bool SetMissionTrackProto(proto_ff::CMissionTrack &missionProto) const
    {
        missionProto.set_missionid(missionId);
        missionProto.set_dynamicid(dynamicId);
        missionProto.set_textid(textId);
        missionProto.set_status(status);
        missionProto.set_accepttime(acceptMissionTime);
        for (uint32_t i = 0; i < items.size(); i++)
        {
            proto_ff::CItemInfo *pItemInfo = missionProto.add_iteminfo();
            pItemInfo->set_type(items[i].type);
            pItemInfo->set_id(items[i].itemId);
            pItemInfo->set_curvalue(items[i].currentValue);
            pItemInfo->set_finvalue(items[i].finalValue);
            pItemInfo->set_parma1(items[i].parma1);
            pItemInfo->set_parma2(items[i].parma2);
            pItemInfo->set_parma3(items[i].parma3);
        }
        return true;
    }

    //从任务proto拷贝信息
    bool CopyFromMissionProto(const proto_ff::CharacterDBMissionTrack &missionProto)
    {
        missionId = missionProto.missionid();
        dynamicId = missionProto.dynamicid();
        missionType = missionProto.missiontype();
        textId = missionProto.textid();
        status = missionProto.status();
        acceptMissionTime = missionProto.acceptmissiontime();
        for (int32_t j = 0; j < missionProto.iteminfo_size(); j++)
        {
            const proto_ff::CharacterDBMissionItemInfo &pItemInfo = missionProto.iteminfo(j);
            ItemInfo itemInfo;
            itemInfo.type = pItemInfo.type();
            itemInfo.itemId = pItemInfo.id();
            itemInfo.currentValue = pItemInfo.currentvalue();
            itemInfo.finalValue = pItemInfo.finalvalue();
            itemInfo.completedFlag = pItemInfo.completedflag();
            itemInfo.parma1 = pItemInfo.parma1();
            itemInfo.parma2 = pItemInfo.parma2();
            itemInfo.parma3 = pItemInfo.parma3();
            if (items.size() >= items.max_size())
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "items Space Not Enough............");
            }
            items.push_back(itemInfo);
        }

        return true;
    }

    //从任务proto拷贝信息
    bool CopyFromMissionProto(const proto_ff::CMissionTrack &missionProto)
    {
        missionId = missionProto.missionid();
        dynamicId = missionProto.dynamicid();
        status = missionProto.status();
        acceptMissionTime = missionProto.accepttime();
        for (uint32_t i = 0; i < (uint32_t) missionProto.iteminfo_size(); i++)
        {
            ItemInfo item;
            const proto_ff::CItemInfo &itemInfo = missionProto.iteminfo(i);
            item.type = itemInfo.type();
            item.itemId = itemInfo.id();
            item.currentValue = itemInfo.curvalue();
            item.finalValue = itemInfo.finvalue();
            item.parma1 = itemInfo.parma1();
            item.parma2 = itemInfo.parma2();
            item.parma3 = itemInfo.parma3();
            items.push_back(item);
        }
        return true;
    }
};

/*
	动态任务数据
*/
struct DyMissionTrack
{
    int32_t kind;        //任务类型
    uint32_t acceptNum; //周期内已接取次数
    uint64_t lastFresh;    //上次刷新时间

    struct BountyParam
    {
        BountyParam()
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
            ten_status = 0;
            twenty_status = 0;
            return 0;
        }

        int ResumeInit()
        {
            return 0;
        }

        uint8_t ten_status; //对赏金任务来说, 0:表示 10 次 未达到 1表示10次未领取 2表示已经领取
        uint8_t twenty_status; //对赏金任务来说, 0:表示 20 次 未达到 1表示20次未领取 2表示已经领取
    };

    BountyParam bountyParam; //赏金任务

    DyMissionTrack()
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
        kind = 0;
        acceptNum = 0;
        lastFresh = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//任务额外掉落
struct MissionDrop
{
    uint64_t dropId;        //掉落ID
    uint64_t boxId;            //box id
    int32_t progressLv;        //进度等级

    MissionDrop()
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
        dropId = 0;
        boxId = 0;
        progressLv = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

//任务掉落 dymissionid - MissionDrop
typedef NFShmHashMap<uint64_t, MissionDrop, 10> MissionDropMap;
//任务所有掉落 monsterid - MissionDropMap
typedef NFShmHashMap<uint64_t, MissionDropMap, 100> MissionAllDropMap;

//任务奖励参数
struct SMissionReward
{
    MAP_UINT32_INT64 mapAttr;
    LIST_ITEM lstItem;
    SET_UINT64 setSkill;
    int32_t useContri;
    int32_t unionExp;

    SMissionReward()
    {
        mapAttr.clear();
        lstItem.clear();
        setSkill.clear();
        useContri = 0;
        unionExp = 0;
    }

    void addDouble(int times)
    {
        for(auto iter = mapAttr.begin(); iter != mapAttr.end(); ++iter)
        {
            iter->second = iter->second * times;
        }

        for(auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
        {
            iter->nNum += iter->nNum * times;
        }

        unionExp += unionExp * times;
        useContri += useContri * times;
    }

    void write_to_pb(proto_ff::MissionRewardProto& proto)
    {
        for(auto iter = mapAttr.begin(); iter != mapAttr.end(); ++iter)
        {
            bool find = false;
            for(int i = 0; i < (int)proto.attr_size(); i++)
            {
                if (proto.attr(i).id() == iter->first)
                {
                    find = true;
                    proto.mutable_attr(i)->set_value(proto.attr(i).value() + iter->second);
                    break;
                }
            }

            if (!find)
            {
                auto pAttr = proto.add_attr();
                pAttr->set_id(iter->first);
                pAttr->set_value(iter->second);
            }
        }

        for(auto iter = lstItem.begin(); iter != lstItem.end(); iter++)
        {
            bool find = false;
            for(int i = 0; i < (int)proto.item_size(); i++)
            {
                if (proto.item(i).key() == iter->nItemID)
                {
                    find = true;
                    proto.mutable_item(i)->set_value(proto.item(i).value() + iter->nNum);
                    break;
                }
            }

            if (!find)
            {
                auto pItem = proto.add_item();
                pItem->set_key(iter->nItemID);
                pItem->set_value(iter->nNum);
            }
        }

        for(auto iter = setSkill.begin(); iter != setSkill.end(); ++iter)
        {
            proto.add_skill(*iter);
        }

        proto.set_union_exp(unionExp);
        proto.set_use_contri(useContri);
    }
};

struct OccupationSoulData
{
    uint64_t soul_id = 0;
    uint64_t item_id = 0;
    uint32_t item_num = 0;
    uint32_t soul_pos = 0;
    uint32_t soul_type = 0;
};

//转职配置数据
struct OccupationMissionCfgData
{
    uint64_t id = 0;
    uint32_t grade = 0;
    uint32_t stage = 0;
    uint32_t task_id = 0;
    std::unordered_map<uint32_t, std::unordered_map<uint32_t, OccupationSoulData>> lightSoul;
};
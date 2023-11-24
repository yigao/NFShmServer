// -------------------------------------------------------------------------
//    @FileName         :    NFFestivalDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-11-24
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestivalDefine
//
// -------------------------------------------------------------------------

#pragma once

#pragma pack(push)
#pragma pack(1)


//砸蛋(天天养龙)日志最大长度
const uint32_t FEST_DIG_EGG_MAX_LOG_NUM = 300;

//转盘多倍返玉日志最大长度
const uint32_t FEST_RTURANBLE_MAX_LOG_NUM = 100;

const uint32_t FEST_DRAWPIZE_MAX_LOG_NUM = 100;

//时间类型
enum class ETimeType
{
    permanent = 1,		//常驻
    openserver = 2,		//开服时间
    date = 3,			//日期
    //create = 4,		//创角时间(去掉)
    limit,
};
//生效的服务器类型
enum class EServType
{
    newzone = 1,	//新服
    merge = 2,		//合服
    all = 3,		//所有的
    limit,
};

//活动数据期数类型
enum class EPeriodType
{
    none = 0,
    fix = 1,		//固定
    dynamic = 2,	//动态
    limit,
};


//模板类型
enum class ETplType
{
    none = 0,				//无
    bosskill = 1,			//boss首杀
    openrank = 2,			//开服冲榜
    collect = 3,			//集字活动
    shop = 4,				//限时商店(天天养龙、开服直购)
    activeplat = 5,			//活跃转盘
    opencheer = 6,			//开服狂欢
    timeonline = 7,			//定时在线
    chargeplat = 8,			//充值转盘
    totalcharge = 9,		//累积充值
    fish = 10,				//猫猫捞鱼
    dailytotalcharge = 11,	//累积充值
    sign = 12,				//签到(天天养龙)
    goldstore = 13,			//金库(天天养龙)
    digegg = 14,			//砸蛋(天天养龙)
    candle = 15,			//烛龙挑战(天天养龙)
    btdragon = 16,			//变态养龙寺(天天养龙)
    total_recharge = 17,	//累计充值
    marry = 18,				//完美情人
    huimengxiyou = 20,      //回梦西游
    drop = 22,				//节日额外掉落
    mult_drop = 23,			//多倍掉落
    login = 24,				//登录奖励
    conti_recharge = 25,	//连续充值
    limit_sale = 26,		//限时秒杀
    day_totalecharge = 27,	//每日累充
    recharge_prize = 28, //累充喵喵
    mystery = 29,			//神秘商人
    field_boss = 30,		//野外BOSS
    shoots_sun = 33,		//后羿射日
    limit,
};

//活动状态
enum EFestState
{
    fest_not_open = 0,	//未开启
    fest_open = 1,		//活动开启
    fest_end = 2,		//活动结束
};


//活动处理结果类型
enum class EFestRes
{
    success = 0,
    fail = 1,
    ignore = 2,
};




//检查活动状态需要的参数
struct ChkFestParam
{
    uint32_t zid = 0;		//区服ID
    uint64_t curtime = 0;	//当前unix时间
    bool isret = false;		//合服标记是否从web返回了
    bool ismerge = false;   //是否合服
    uint32_t days = 0;		//现在是开服之后的第几天
    uint64_t zerotime = 0;	//开服那一天的0点时间
};

#define XIYOU_MAX_TIME_LENGTH 20 * 60

enum {
    FestHuiMengXiYouStatus_Close = 0, //0:关闭 1：准备阶段 2:玩游戏阶段 3:完成阶段
    FestHuiMengXiYouStatus_Ready = 1,
    FestHuiMengXiYouStatus_Play = 2,
    FestHuiMengXiYouStatus_Finish = 3,
};

enum {
    FestHuiMengXiYouState_READY = 1, //准备场景配置 配置为muban_play_game order 1
};


#pragma pack(pop)
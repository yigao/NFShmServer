// -------------------------------------------------------------------------
//    @FileName         :    NFLogDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogDefine
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
using namespace  std;


//道具或货币来源(已经定义的来源跟内部统计日志逻辑有关，如需改动已定义的来源，请咨询下负责统计日志的相关人员)
enum ESource
{
    S_NONE					= 0,
    S_GM					= 1,	//GM命令
    S_MALL_BUY				= 2,	//商店购买
    S_PAY					= 3,	//充值
    S_ACTUINEER				= 4,	//拍卖行  来源值1：1-上架 求购，2-购买，3-下架，来源值2：订单类型
    S_MISSION				= 5,	//任务奖励 来源值1：任务ID
    S_USE_ITEM				= 6,	//使用物品 来源值1：物品ID
    S_ACHIEVEMENT_Fetch		= 7,	//领取成就奖励 来源值1：成就ID
    S_GODHOOD				= 8,	//神格 来源值1：1-镶嵌，2-取下,3-熔炼,4-分解,5-一键熔炼,6-升级
    S_ACTIVE				= 9,	//活动(activity表格中的活动) 来源值1：活动ID
    S_FRIEND				= 10,	//好友 来源值1：1-送礼，2-送礼失败
    S_UNION_CREATE			= 11,	//公会 来源值1：1-创建，2-创建失败
    S_OPERATE_ACT			= 12,	//运营活动
    S_Chat					= 13,	//聊天 来源值1:频道ID
    S_Refine				= 14,	//精炼
    S_Born					= 15,   //创角
    S_Marry_Divorce			= 16,	//离婚
    S_Emblem				= 17,	//纹章 来源值1：1-镶嵌，2-卸下，3-重生，4-熔炼
    S_EquipScrutiny			= 18,	//装备洗练
    S_MapBoss_BuyNum		= 19,	//野外BOSS 购买次数 来源值1：BOSS类型
    S_Marry					= 20,	//结婚 来源值1：目标玩家CID, 来源值2：是否是AA制 1-是 0-否
    S_SkillDamage			= 21,	//技能伤害
    S_Treasure_UseFragment	= 22,	//宝具 使用碎片 来源值1：当前已使用次数
    S_Equip_Suit			= 23,	//装备套装
    S_IdentifyFate_Levup	= 24,	//图鉴 升级 来源值1:图鉴ID，来源值2：当前图鉴等级
    S_Occupation_Breach		= 25,	//转职 境界突破 来源值1：当前突破的境界ID
    S_Element_Upgrade		= 26,	//元素 升级 来源值1：元素类型，来源值2：元素当前等级
    S_Fashion_Upgrade		= 27,	//时装 升级 来源值1：时装ID，来源值2：时装当前的等级
    S_Mount_Levup			= 28,	//坐骑 升级 来源值1：坐骑ID， 来源值2：坐骑当前的等级
    S_Wing_UseFragment		= 29,	//翅膀 使用碎片 来源值1：当前已使用次数
    S_Artifact_Levup		= 30,	//神器幻化 来源值1：神器ID, 来源值2：神器ID幻化之前的星级
    S_Star					= 31,   //命星占星 来源值1：占星次数
    S_Daily_Fetch			= 32,	//日常 领取奖励 来源值1：奖励ID
    S_Field					= 33,	//领域 拓展 来源值1：最大数量
    S_Partner_Swallow		= 34,	//伙伴 吞噬 来源值1：吞噬获得的经验
    S_Recovery				= 35,	//资源找回
    S_EquipClear			= 36,	//洗炼升段
    S_MissionSubmitItem		= 37,	//提交物品任务 来源值1：任务动态ID
    S_ServOpenAct			= 38,	//开服活动
    S_Convoy_Commit			= 39,	//提交镖车 来源值1：当前选中的镖车ID
    S_BuyDupNum				= 40,	//购买副本次数 来源值1：副本组ID
    S_Marry_Agree			= 41,	//同意结婚 来源值1：对方角色CID，来源值2：是否是AA制 1-是 0-否
    S_Solo					= 42,	//1v1solo赛 来源值1：1-段位奖励，2-每日段位奖励，3-购买次数，4-参与次数奖励
    S_PickDrop				= 43,	//拾取掉落
    s_SweepDup				= 44,	//副本扫荡 来源值1：副本ID
    S_FetchSubpack			= 45,	//领取分包奖励
    S_Mail					= 46,	//领取邮件附件
    S_Union_Donate			= 47,	//工会捐献 来源值1：1-捐献，2-捐献失败
    S_Union_Exchange		= 48,	//工会仓库兑换
    S_Union_FetchRed		= 49,	//领取工会红包
    S_MapBoss_FreshNum		= 50,	//野外BOSS 次数刷新 来源值1：地图ID
    S_MapBoss_EnterBossMap  = 51,	//野外BOSS 进入BOSS地图  来源值1：玩家当前VIP等级，来源值2：进入的层数
    S_Convoy_Fresh			= 52,	//刷新镖车 来源值1：当前选中的镖车ID, 来源值2：目标镖车ID
    S_Element_UseFragment	= 53,	//元素 使用碎片 来源值1：当前已使用次数
    S_Star_Buy				= 54,   //命星 兑换 来源值1：兑换的命星ID, 来源值2：当前拥有的命星碎片数量
    S_Star_Decompose		= 55,	//命星 分解 来源值1：分解获得的命星经验， 来源值2：分解获得命星精华
    S_Field_TakeOff			= 56,	//领域 卸下 来源值1：领域ID
    S_Field_Decompose		= 57,	//领域 分解 来源值1：分解获得的经验
    S_Partner_Levup			= 58,	//伙伴 升级 来源值1：类型， 来源值2：升级的伙伴ID
    S_Partner_UseFragment   = 59,	//伙伴 使用碎片 来源值1：当前已使用次数
    S_Marry_Wedding			= 60,	//结婚 预约婚宴
    S_Treasure_Levup		= 61,	//宝具 升级 来源值1：类型， 来源值2：升级的宝具ID
    S_Wing_Levup			= 62,	//翅膀 升级 来源值1：类型， 来源值2：升级的翅膀ID
    S_USE_BOX_ITEM			= 63,	//使用box类物品,来源值1：boxid,来源之2：物品ID
    S_SellItem				= 64,	//出售物品
    S_Package_Storage		= 65,	//背包和仓库物品移入移出
    S_Stone					= 66,	//宝石镶嵌 来源值1：1-镶嵌，2-卸下,3-镶嵌的宝石升级
    S_Material_Compose		= 67,	//材料合成
    S_ACHIEVEMENT_Point		= 68,	//领取成就点数奖励 来源值1：奖励ID
    S_DupRelive				= 69,	//副本复活
    S_DupInspire			= 70,	//副本鼓舞 来源值1：副本ID
    S_Mission_OnceFinish	= 71,	//任务立即完成，来源值1：任务配置ID
    S_Equip_Renew			= 72,	//装备续费 来源值1：装备ID
    S_Equip_Strong			= 73,	//装备强化 来源值1：装备部位， 来源值2：强化之前的等级
    S_Pk_DeadDrop			= 74,	//PK 死亡掉落 来源值1：被谁击杀，来源值2：地图ID
    S_Arena_Challenge		= 75,	//竞技场 挑战奖励
    S_Equip_Dress			= 76,	//装备穿戴 来源值1：1-穿戴，2-卸下
    S_Change_RoleName		= 77,	//角色改名
    S_Change_RoleNameFail	= 190,	//角色改名失败

    S_Change_UnionName		= 78,	//工会改名 来源值1：工会ID
    S_DupDrop				= 79,	//副本掉落,来源参数1：副本ID
    S_BossDrop				= 80,	//BOSS掉落,来源参数1：BOSS类型
    S_EquipAwk				= 81,	//装备觉醒，来源之1：equip.xlsx-awakening表 id 字段
    S_EquipEnchant			= 82,	//装备附魔，来源值1：equip.xlsx-enchanting表 id 字段
    S_EquipMarryStrong		= 83,	//结婚装备强化，来源值1：equip.xlsx-marry表 id 字段
    S_EquipMarryStage		= 84,	//结婚装备进阶，来源值1：equip.xlsx-marry表 id 字段
    S_MysteryShop			= 85,   //神秘商店
    S_PAY_Card				= 86,	//使用充值卡，来源值1：充值卡物品ID
    S_MapBoss_UnitRefresh   = 87,	//单个刷新野外BOSS， parameter1 ：bossID
    S_Vip					= 88,	//vip
    S_Union_SubmitMaterial	= 89,	//提交工会 失落神迹 活动材料 来源参数1：工会ID
    S_Union_SubmitMaterialFail=90,	//提交工会 失落神迹 活动材料失败 来源参数1：工会ID
    S_Wedding				= 91,	//婚宴
    S_FetchPalaceLayerReward = 92,	//领取工会地宫 层数奖励 来源参数1：层数
    S_EquipDecompose		= 93,	//装备分解 来源参数1：分解的装备ID
    S_1v1Train				= 94,	//1v1挑战
    S_RareStarLv			= 95,	//秘宝升星
    S_RareStrongLv			= 96,	//秘宝强化
    S_RareStepLv			= 97,	//秘宝升阶
    S_PartnerEquip			= 98,	//伙伴装备
    S_PartnerRefine			= 99,	//伙伴精炼
    S_TreasureEquip			= 100,	//宝具装备
    S_TreasureRefine		= 101,	//宝具精炼
    S_OperationTurntable	= 102,	//幸运转盘
    S_BuffEffect_Attr		= 103,	//Buff效果改变属性先关的来源 来源值1：效果类型，来源值2：状态包ID，来源值3：触发状态包的技能ID
    S_Union_Boss_Reward		= 104,	//工会BOSS奖励 来源值1：boss组id   la
    S_Equip_Smelt			= 105,	//装备熔炼
    S_Head_Levup			= 106,	//头像
    S_Frame_Levup			= 107,	//边框
    S_Bubble_Levup			= 108,	//气泡
    S_Manor_Monster_Lv = 109,	//奇兽升级
    S_Manor_Donate =110,		//献祭
    S_Manor_UpBook = 111,		//上交证书
    S_Manor_Shop_Buy = 112,		//领地商店购买
    S_Manor_Egg = 113,			//孵化蛋
    S_Manor_Build_Lv = 114,		//建筑升级
    S_Power_Lv	= 115,			//神力觉醒
    S_Collection = 122,			//采集
    S_Teleport				= 130,	//传送门传送，来源值1：传送门配置ID
    S_Manor_Shop_BuyFail	= 133,	//领地商店购买失败, 来源值1：manor.xlsx-shop表ID字段
    S_Online_Gift	= 134,			//在线礼包
    S_GmHelp	= 135,				//gm助力

    S_KillMonsExp = 140,			//打怪经验，来源值1：怪物配置ID
    S_GodGM	=	141,				//神权
    S_MallGmLv = 142,				//gm商城升级
    S_DieDrop = 150,		//死亡掉落, 来源值1：地图配置ID

    S_1V1_Ridicule = 160,		//1v1训练-嘲讽

    S_QueryEnemy = 170,		//追踪仇人

    S_hangup = 180,			//挂机
    S_PokerOneRound = 181,  //扑克一轮结束给玩家经验

    S_grow = 182,			//养成
    S_EquipChg = 183,		//装备换装
    S_FunctionUnlock = 184, //
    S_GodRelics = 185, //天机谱

    S_END,
};


//通用的来源结构
struct SCommonSource
{
    // ------------------ 来源  ---------------------------
    ESource src;	//运营需要的物品来源
    int64_t param1;					//运营来源参数1(根据不同的来源确定值)
    int64_t param2;					//运营来源参数2(根据不同的来源确定值)
    int64_t param3;					//运营来源参数3(根据不同的来源确定值)

    // ------------------- A_CUR_HP 相关 --------------------------

    uint64_t killerCid;		//击杀者cid,目前用于技能击杀生物时，传入击杀者的cid
    int64_t  damageVal;		//击杀者对被击者造成的伤害

    bool bTips;				//是否通知客户端弹出TIPS

    SCommonSource()
    {
        clear();
    }
    void clear()
    {
        src = S_NONE;
        param1 = 0;
        param2 = 0;
        param3 = 0;
        killerCid = 0;
        damageVal = 0;
        bTips = true;
    }
};

enum EnAuctioneerOperateType
{
    enAuctioneerOperateType_Publish = 1,	//发布定单
    enAuctioneerOperateType_Dowith	= 2,    //处理定单
    EnAuctioneerOperateType_SystemRevoke =3, //系统下架
    EnAuctioneerOperateType_PlayerRevoke =4, //玩家手动下架
};


//奥飞日志类型，一个类型对应一个文件
enum EnAoFeiLogType
{
    EnAoFeiLogType_None,
    EnAoFeiLogType_Login,		//登陆日志
    EnAoFeiLogType_LoginOut,	//登出日志
    EnAoFeiLogType_CreateRole,	//创建角色
    EnAoFeiLogType_OnlineRoleNum,//在线日志
    EnAOFeiLogType_LevelUp,		//升级日志
    EnAOFeiLogType_Recharge,	//充值日志

    EnAOFeiLogType_Trade,		//交易日志(拍卖行，赠送......)

    EnAOFeiLogType_PVP,				//PVP日志
    EnAOFeiLogType_OtherDiamonUse,	//其他钻石使用日志
    EnAOFeiLogType_OtherDiamonGet,	//其他钻石获得日志
    EnAOFeiLogType_ItemBuy,			//物品购买日志
    EnAOFeiLogType_Activity,		//活动参与日志
    EnAOFeiLogType_BossKill,		//Boss击杀日志
    EnAOFeiLogType_Attribute,		//属性日志
    EnAOFeiLogType_Resourcechange,	//资源变化
    EnAOFeiLogType_Chat,			//聊天日志
    EnAOFeiLogType_Mail,			//邮件
    EnAOFeiLogType_BoxItem,			//宝箱物品
    EnAOFeiLogType_Faction,			//工会
    EnAOFeiLogType_Mission,			//任务
    EnAOFeiLogType_PickDrop,		//拾取掉落
    EnAoFeiLogType_Max,
};

//流通类型
enum TradeType
{
    TradeType_Auctioneer = 1,//拍卖行
    TradeType_Give,			 //赠送
};

static map<int32_t,std::string> s_aofei_log_name =
        {
                { EnAoFeiLogType_None, "NONE" },
                { EnAoFeiLogType_Login, "LoginRole.txt" },
                { EnAoFeiLogType_LoginOut, "LogoutRole.txt" },
                { EnAoFeiLogType_CreateRole, "CreateRole.txt" },
                { EnAoFeiLogType_OnlineRoleNum, "OnlineRoleNum.txt" },
                { EnAOFeiLogType_LevelUp, "LevelUp.txt" },
                { EnAOFeiLogType_Recharge, "Prepaid.txt" },
                { EnAOFeiLogType_Trade, "Trade.txt" },
                { EnAOFeiLogType_PVP, "PVP.txt" },
                { EnAOFeiLogType_OtherDiamonUse, "ZuanshiUse.txt" },
                { EnAOFeiLogType_OtherDiamonGet, "ZuanshiGain.txt" },
                { EnAOFeiLogType_ItemBuy, "ItemBuy.txt" },
                { EnAOFeiLogType_Activity, "Activity.txt" },
                { EnAOFeiLogType_BossKill, "BossKill.txt" },
                { EnAOFeiLogType_Attribute, "Attribute.txt" },
                { EnAOFeiLogType_Resourcechange, "Resourcechange.txt" },
                { EnAOFeiLogType_Chat, "Monitoring.txt" },
                { EnAOFeiLogType_Mail, "Mail.txt" },
                { EnAOFeiLogType_BoxItem, "OpenCrates.txt" },
                { EnAOFeiLogType_Faction, "faction.txt" },
                { EnAOFeiLogType_Mission, "Misson.txt" },
                { EnAOFeiLogType_PickDrop ,"Drop.txt"}
        };



//日志公用字段结构体
struct CommonLog
{
    uint32_t log_time;		//日志时间戳(秒)
    uint32_t log_ymd;		//年月日，例如20160405
    uint32_t log_ym;		//年月,例如201604
    uint32_t year;			//年 例如2016
    uint32_t month;			//月，例如04，即4月
    uint32_t day;			//日，例如05，即5日
    uint32_t week;			//第几个星期,按这一年中的第几周
    uint32_t hour;			//时，例如11，即上午11点
    uint32_t minute;		//例如20，即20分
    int32_t zoneid;			//游戏大区ID，比如荣耀1区，下面是服务器比如S1，如果没有大区的概念，zoneid就都传0吧
    int32_t server;			//游戏服ID, 服务器编号，1,2,3,4...
    string server_name;		//服务器名字，这个字段最好不要空的，不然我们的ES后台也是空的。看把服务器ID传进去

    string os_name;			//操作系统,直接通过系统提供API返回的字符串，如ios,android,windows,ubuntu,symbian等
    string os_ver;			//操作系统版本,设备操作系统版本号如：6.1,2.3等
    string mac_addr;		//设备mac地址,如08:00:20:0A:8C:6D
    string udid;			//设备唯一标示符,设备UDID号,ios详情见：《苹果公司建议的UUID替代方案》
    string device_model;	//设备型号,直接获取通过系统提供API返回的设备制造商,设备型号,CPU名称,CPU核心数,CPU频率,GPU名称字符串，并使用分割符号_进行拼接。
    string ip;				//Ipv4地址,如果是ipv4网络
    uint32_t port;			//端口（网络审查需要）

    string app_channel;		//运营渠道,运营渠道，如app_store/91_assistant等…
    string app_ver;			//客户端版本号,
    string network;			//网络连接,例如有3g,2.5g,4g,wifi几种。
    string platform_tag;	//发行平台标记,奥飞国内aofei，预留其它
    int32_t group_id;		//操作系统ID,例如IOS为1，android为2，windows为3等
    int32_t channel_id;		//运营渠道ID,原记录方式100，101
    uint32_t active_time;	//激活时间
    string device_screen;	//屏幕高度X宽度,设备屏幕高度宽度，如100X80这样表达

    string idfa;			//iOS设备标识 iOS设备标识
    string imei;			//Android设备标识

    string account_id;		//账号唯一标识符,游戏账号的唯一标示符,用于统计用户数量。
    string role_id;			//角色唯一标识符,角色唯一标识，在所有服唯一。（可以通过加入游戏服名称和角色名称的MD5实现全服唯一的标识符，又或者为角色创建UUID）。
    string role_name;		//角色名称,游戏角色名称，多服可重复，单服唯一（视情况而定）
    uint32_t create_time;	//角色创建时间,这个角色的创建时间
    int32_t	role_level;		//角色等级
    int32_t role_job;		//角色职业
    float total_pay;		//总充值
    int32_t vip_level;		//角色VIP等级
    int64_t power;			//角色战力


    CommonLog()
    {
        log_time = 0;
        log_ymd = 0;
        log_ym = 0;
        year = 0;
        month = 0;
        day = 0;
        week = 0;
        hour = 0;
        minute = 0;
        zoneid = 0;
        server = 0;

        port = 0;

        group_id = 0;
        channel_id = 0;
        active_time = 0;

        create_time = 0;
        role_level = 0;
        role_job = 0;
        total_pay = 0.0f;
        vip_level = 0;
        power = 0;
    }
};


//在线日志
struct OnlineRoleNumLog : public CommonLog
{

    int32_t ip_online_num;	//IP在线数
    int32_t online;			//在线角色数
    uint32_t online_time;	//记录时间,记录的时间，精确到秒

    OnlineRoleNumLog()
    {
        ip_online_num = 0;
        online = 0;
        online_time = 0;
    }
};

//创角日志
struct CreateRoleLog : public CommonLog
{
    CreateRoleLog()
    {

    }
};

//登陆日志
struct LoginLog : public CommonLog
{
    uint32_t login_time;			//角色登录游戏的时间
    uint32_t last_logout_time;	//角色上次退出游戏的时间
    string offline_item;		//本次登陆奖励的物品或者资源，包括离线挂机奖励。若无奖励，则不需要本字段(可选字段)

    LoginLog()
    {
        login_time = 0;
        last_logout_time = 0;
    }
};

//登出日志
struct LoginOutLog :public CommonLog
{
    int64_t exp;			//角色经验
    uint32_t logout_time;	//登出时间
    int32_t	online_time;	//在线时长，本次玩家在线时长（单位：秒）
    string	scene;			//登出时所在场景
    string  last_operation; //登出前操作，登出前角色最后一次操作或者完成的玩法，游戏自己定义
    int64_t	money_sum;		//本次在线累计获得金钱总量，每次登出的时候将本次在线所有系统产生游戏币进行累加
    int64_t exp_sum;		//本次在线累计获得经验总量,每次登出的时候将本次在线所有获得的经验值进行累加写出。
    int32_t	total_time;		//总在线时长(秒)
    int32_t	left_zuanshi;	//剩余钻石, 角色退出时身上钻石
    int32_t	left_bangzuan;	//剩余绑定钻石, 角色退出时身上绑定钻石
    int64_t	left_gold;		//剩余游戏金币, 角色退出时身上游戏金币
    int64_t	s_degree;		//角色战力, 角色自身的战力
    int32_t quit_state;		//退出操作 1：按退出游戏正常退出  2：按home后台检测心跳退出 3：闪退
    int32_t shenzuan;		//角色退出时身上神钻数量
    LoginOutLog()
    {
        exp = 0;
        logout_time = 0;
        online_time = 0;
        money_sum = 0;
        exp_sum = 0;
        total_time = 0;
        left_zuanshi = 0;
        left_bangzuan = 0;
        left_gold = 0;
        s_degree = 0;
        quit_state = 0;
        shenzuan = 0;
    }
};





//升级
struct LevelUpLog : public CommonLog
{
    int64_t levelup_time;		//升级时间

    LevelUpLog()
    {
        levelup_time = 0;
    }
};

//充值日志
struct PayLog : public CommonLog
{
    int32_t state;			//成功为1,补单为2
    string pay_channel;		//如app_store，91_assistant
    int32_t zuanshi;		//本次充值获得的钻石数量
    int32_t free_zuanshi;	//本次充值获得的绑定钻石数量
    float cash;				//本次充值花费现金
    string currency;		//货币类型，CNY代表中国货币，EUR代表欧元，统一采用标准货币代码，(可选字段)
    int32_t left_zuanshi;	//角色充值后剩余钻石量
    int32_t left_bangzuan;	//角色充值后剩余的绑钻量
    uint32_t pay_time;		//角色充值的时间
    string pay_method;		//充值通道 返回计费SDK接口中的pay_method，注意一定返回该字段，涉及财务收入统计
    string sn;				//充值的订单号  订单编号，一般是唯一的
    int32_t shenzuan;		//本次充值获得的神钻数量
    PayLog()
    {
        state = 0;
        zuanshi = 0;
        free_zuanshi = 0;
        cash = 0.0f;
        left_zuanshi = 0;
        left_bangzuan = 0;
        pay_time = 0;
        shenzuan = 0;
    }
};

//PVP 日志
struct PvpLog : public CommonLog
{
    uint32_t begin_time;		//进入玩法的时间
    uint32_t use_time;			//玩法耗时
    string		pvp_name;			//PVP玩法名称,需唯一标识该任务或玩法 竞技场	 野外PVP	公会战
    int32_t		gameplay_number;	//记录当前玩法的任务编号  竞技场:当前已经挑战了的次数  野外PVP：无  公会战：无
    int32_t end_state;			//玩法完成情况（源账号失败：0，源账号胜利：1，平手：2）
    int32_t s_prod_money;		//源角色获得的银币
    string s_prod_item;			//源角色获得的物品
    int32_t		team;				//是否开启组队  是组队PVP还是单人PVP  1为组队，0没有组队
    string		other_items;		//杂项 记录其它杂项内容
    PvpLog()
    {
        begin_time = 0;
        use_time = 0;
        gameplay_number = 0;
        end_state = 0;
        s_prod_money = 0;
        team = 0;
    }
};

//交易日志
struct TradeLog : public CommonLog
{
    int32_t	trade_time;		//流通时间
    int32_t kuafu_id;		//跨服ID
    string	type;			//流通类型,游戏内流通方式，求购或寄售
    uint32_t s_server;		//卖家服务器ID
    string	s_account_id;	//源账号唯一标识符
    string	s_role_id;		//源角色唯一标识符
    string	s_role_name;	//源角色名称
    string	s_ip;			//源角色IP
    string	s_mac;			//源角色MAC
    string	s_udid;			//源角色设备唯一标示符, 设备UDID号, 具体参见关于UDID说明章节，用于统计设备数
    uint32_t s_zuanshi;		//卖家获得钻石

    string	item_uuid;		//交易物品唯一ID 若每个物品就算类型一样也有唯一的标识符（如UUID），则记录标识这一个物品
    int64_t	item_id;		//交易物品标识符，（标志同一种物品），非中文
    string	item_name;		//交易物品名称
    int32_t item_type;		//交易物品类型，如武器为1等
    int32_t	count;			//交易物品数量

    uint32_t d_server;		//买家服务器ID
    string	d_account_id;	//目标账号唯一标识
    string	d_role_id;		//目标角色ID
    string	d_role_name;	//目标角色昵称
    string	d_ip;			//目标角色IP
    string	d_mac;			//目标角色MAC地址
    string	d_udid;			//目标角色设备唯一标示符, 目标角色UDID
    uint32_t d_zuanshi;		//买家花费的钻石
    TradeLog()
    {
        trade_time = 0;
        kuafu_id = 0;
        s_server = 0;
        s_zuanshi = 0;
        item_id = 0;
        item_type = 0;
        count = 0;
        d_server = 0;
        d_zuanshi = 0;
    }
};

//资源变化
struct ResourcechangeLog : public CommonLog
{
    int32_t change;				//消耗\产出 产出=1，消耗=0
    string reason;				//变化原因
    string details;				//细节
    int32_t zuanshi;			//变化钻石量（非绑定）  产出或消耗的钻石量（非绑定）
    int32_t left_zuanshi;		//剩余钻石量（非绑定）
    int64_t free_zuanshi;		//变化绑钻石量 产出或消耗的绑定钻石量
    int64_t left_free_zuanshi;	//剩余绑钻量
    int64_t gold;				//变化的金币
    int64_t left_gold;			//剩余金币量
    string item;				//道具变化，产出或者消耗的道具 格式：{ 道具名A:数量;道具名B:数量 }
    int64_t free_shenzuan;		//产出或消耗的神钻数量
    int64_t left_shenzuan;		//剩余神钻数量

    ResourcechangeLog()
    {
        change = 0;
        zuanshi = 0;
        left_zuanshi = 0;
        free_zuanshi = 0;
        left_free_zuanshi = 0;
        gold = 0;
        left_gold = 0;
        free_shenzuan = 0;
        left_shenzuan = 0;
    }
};

//其他钻石使用
struct OtherDiamonUseLog : public CommonLog
{
    string reason;		//如补充体力等
    int32_t zuanshi;		//本次消耗钻石量（非绑定）
    int32_t left_zuanshi;		//消耗后角色剩余钻石量（非绑定）
    int32_t free_zuanshi;		//本次消耗的绑定钻石量（红钻）
    int32_t left_free_zuanshi;		//消耗后角色剩余绑定钻石量（红钻）
    int32_t use_time;		//消耗的时间

    OtherDiamonUseLog()
    {
        reason = "";
        zuanshi = 0;
        left_zuanshi = 0;
        free_zuanshi = 0;
        left_free_zuanshi = 0;
        use_time = 0;
    }

};

//其他钻石获得
struct OtherDiamonGetLog : public CommonLog
{
    string reason;		//获取原因，如节日赠送等
    int32_t zuanshi;		//获得的钻石量（非绑定）
    int32_t left_zuanshi;		//获取后剩余的钻石量（非绑定）
    int32_t free_zuanshi;		//获得的绑定钻石量（红钻）
    int32_t left_free_zuanshi;		//获取后剩余的绑定钻石量（红钻）
    int32_t gain_time;		//获取时间

    OtherDiamonGetLog()
    {
        reason = "";
        zuanshi = 0;
        left_zuanshi = 0;
        free_zuanshi = 0;
        left_free_zuanshi = 0;
        gain_time = 0;
    }

};

//购买
struct BuyLog : public CommonLog
{
    string mall_source;				//商城、商城-限购\商城 - 钻石\商城 - 紫钻
    uint64_t item_id;				//item_id
    string item_name;				//物品名称，不做标识符，方便读
    uint32_t item_type;				//物品类型，如武器为1等
    uint32_t buy_time;				//购买物品时间
    uint32_t expire_time;			//物品失效时间
    uint32_t count;					//购买这一物品数量
    int32_t price;					//物品单价(以元宝计价)
    int64_t zuanshi;				//本次购买花费的钻石量（非绑定）
    int64_t left_zuanshi;			//购买后角色剩余钻石量（非绑定）
    int64_t free_zuanshi;			//本次购买花费的绑定钻石量（红钻）
    int64_t left_free_zuanshi;		//购买后角色剩余的绑定钻石量（红钻）
    int64_t cost_gold;				//本次购买花费的游戏金币(交易用)
    int64_t left_gold;				//购买后角色剩余游戏金币(交易用)
    string cost_other;				//花费其他  先传空值
    string left_other;				//剩余其他  先传空值
    int32_t shenzuan;				//花费神钻 本次购买花费的神钻量
    int32_t left_shenzuan;			//剩余神钻 购买后角色剩余神钻量

    BuyLog()
    {
        item_id = 0;
        item_type = 0;
        buy_time = 0;
        expire_time = 0;
        count = 0;
        price = 0;
        zuanshi = 0;
        left_zuanshi = 0;
        free_zuanshi = 0;
        left_free_zuanshi = 0;
        cost_gold = 0;
        left_gold = 0;
        shenzuan = 0;
        left_shenzuan = 0;
    }
};

//玩法参与日志
struct ActivityLog : public CommonLog
{
    string activity_name;	//玩法名称
    int32_t state;			//玩法状态 0：进入活动时的记录，	1：结算时的记录
    int32_t end_state;		//结算时记录，0：失败,1：成功
    string details;			//玩法明细,玩法的细节，例如第几关卡等
    ActivityLog()
    {
        state = 0;
        end_state = 0;
    }
};

//BOSS 击杀
struct BossKillLog : public CommonLog
{
    uint64_t boss_id;		//BossID 被击杀的Boss、野怪ID
    string activity_name;	//Boss所属玩法 Boss所属的玩法\活动名称 野外Boss、专属Boss、VIP-Boss、深渊Boss、秘境Boss
    uint32_t kill_time;		//击杀Boss时间 击杀Boss的时间戳
    BossKillLog()
    {
        boss_id = 0;
        kill_time = 0;
    }
};

//属性日志
struct AttributeLog : public CommonLog
{
    string reason;			//系统属性
    string upgrade_item;	//属性提升部位
    int32_t nclass;			//提升后的等级
    AttributeLog()
    {
        nclass = 0;
    }
};

//聊天日志
struct ChatLog : public CommonLog
{
    string content;		//聊天内容，因#字符为日志分割符，建议内容里不能包含#字符,如果聊天内容会出现html的标签，需要转义（或者去掉）处理
    string channel;		//聊天频道 world：指世界频道 tong：指公会频道  team：指队伍频道  private：指私聊频道
    uint32_t chat_time;	//聊天时间戳
    int32_t vip_level;	//vip等级
    uint32_t faction_id;//帮派ID
    string scene;		//场景地图ID
    ChatLog()
    {
        chat_time = 0;
        vip_level = 0;
        faction_id = 0;
    }
};

//邮件日志
struct MailLog : public CommonLog
{
    string mail_name;				//邮件名字,邮件标题
    string mail_;					//邮件内容
    uint32_t bonus_money;			//奖励游戏金币
    uint32_t bonus_free_zuanshi;	//奖励绑定紫钻
    uint32_t bonus_zuanshi;			//奖励蓝钻
    string bonus_item;				//奖励物品
    uint32_t bonus_shenzuan;		//奖励神钻
    MailLog()
    {
        bonus_money = 0;
        bonus_free_zuanshi = 0;
        bonus_zuanshi = 0;
        bonus_shenzuan = 0;
    }
};

//开启宝箱日志
struct OpenBoxLog : public CommonLog
{
    uint32_t caozuo_time;	//打开时间
    string gifi_name;		//宝兴名字
    uint32_t zuanshi;		//获得钻石（非绑定蓝钻）
    uint32_t bonus_gold;	//金币
    uint32_t free_zuanshi;	//获得钻石（绑定紫钻）
    string bonus_item;		//获得物品
    uint32_t shenzuan;		//获得神钻数量
    OpenBoxLog()
    {
        caozuo_time = 0;
        zuanshi = 0;
        bonus_gold = 0;
        free_zuanshi = 0;
        shenzuan = 0;
    }
};

//工会日志
struct FactionLog : public CommonLog
{
    int32_t faction_caozuo;		//工会操作 1、为创建公会；2、成功进入公会；3、自动离开公会；4、被开除公会；5、被转移成为会长
    string faction_name;		//工会名字
    uint32_t faction_id;		//工会ID
    uint64_t wang;				//盟主 新会长的角色ID，只有转移会长行为才有此记录
    uint32_t faction_time;		//公会操作时间 玩家创建公会、进入公会、离开公会
    FactionLog()
    {
        faction_caozuo = 0;
        faction_id = 0;
        wang = 0;
        faction_time = 0;
    }
};

//任务
struct MissionLog : public CommonLog
{
    uint64_t mission_id;		//任务ID
    uint32_t mission_time;		//操作时间
    int32_t mission_caozuo;		//操作 0=接取，1=提交，2=放弃
    MissionLog()
    {
        mission_id = 0;
        mission_time = 0;
        mission_caozuo = 0;
    }
};

//拾取掉落
struct PickDropLog : public CommonLog
{
    uint32_t reason_time;	//获得时间
    uint64_t bonus_money;	//金币
    string bonus_item;		//物品
    string monster_name;	//怪物名字
    uint64_t boss_id;		//boss id
    string engulf;			//吞噬的物品
    PickDropLog()
    {
        reason_time = 0;
        bonus_money = 0;
        boss_id = 0;
    }
};
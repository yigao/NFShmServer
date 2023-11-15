// -------------------------------------------------------------------------
//    @FileName         :    NFChatDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "Item/NFItem.h"

/*--------------------------------------------
*	系统传闻广播类型定义
-------------------------------------------*/

enum BROADCAST_TYPE
{
    BT_NONE = -1,

    BT_PVP_KILL_RED_PLAYER = 104,	//xxx玩家在xxx地图击杀作恶多端的XXX玩家，大快人心


    BT_PACKAGE_RENEW_ITEM = 53000000005,	//xxx玩家成功激活了XXX守护装备，战力大增


    BT_EQUIP_CLEAR_ATTR_ORANGE = 53000000006,	//xxx吉星高照，洗练出一条橙色品质的属性
    BT_EQUIP_CLEAR_ATTR_RED = 53000000007,		//xxx运气爆棚，洗练出一条红色品质的属性
    BT_EQUIP_CLEAR_ATTR_PINK = 53000000008,		//xxx运气爆棚，洗练出一条粉色品质的属性

    BT_EQUIP_SUIT_PREFECT = 53000000009,		//xxx历经艰辛，终于成功激活完美xxx件套的套装属性，战力大幅提升
    BT_EQUIP_SUIT_LEGEND = 53000000010,			//xxx历经磨练，终于成功激活传说xxx件套的套装属性，战力大幅提升

    BT_FATESTAR_ORANGE_QUALITY = 53000000011, //xxx在纹章征授时意外获得一个橙色品质的xxx纹章  废弃
    BT_FATESTAR_HIGH_QUALITY = 53000000012, //xxx在纹章征授时，吉星高照，获得一个xxx品质的xxx纹章

    BT_IDENTIFY_ACTIVE = 53000000013,			//xxx成功激活了xxx图鉴：xxx
    BT_IDENTIFY_ACTIVE_FATE = 53000000014,		//xxx通过努力终于激活了羁绊：xxx
    BT_FASHION_ACTIVE = 53000000015,			//xxx成功激活了时装：xxx
    BT_FASHION_LVUP = 53000000016,				//xxx成功把时装：xxx升星至xxx星
    BT_MOUNT_ACTIVE = 53000000017,				//xxx成功激活了坐骑：xxx
    BT_MOUNT_LVUP = 53000000018,				//xxx成功把坐骑：xxx升星至xxx星
    BT_UNION_CREATE_UNION_SUCESS = 53000000019,	//xxx刚刚创建了xxx公会，志同道合的小伙伴们快加入吧！
    BT_AUCTIONEER_PUBLISH_BUY_ORDER = 53000000021,//xxx以xxx钻石求购xxx个xxx，快去看看吧！

    BT_VIP_ACTIVATE_VIP1 = 53000000023,		//xxx激活了vip1，引来丰收平原所有村民的争相八卦！
    BT_VIP_ACTIVATE_VIP2 = 53000000024,		//xxx激活了vip2，不愿透露姓名的地精咔咔表示他吃了一斤的柠檬！
    BT_VIP_ACTIVATE_VIP3 = 53000000025,		//xxx激活了vip3，绝望沙漠有人投诉被这份财气薰红了眼睛！
    BT_VIP_ACTIVATE_VIP4 = 53000000026,		//xxx激活了vip4，誓约城骑士团下达指令：截图干什么，愣着啊！
    BT_VIP_ACTIVATE_VIP5 = 53000000027,		//xxx激活了vip5，登上了诺林大陆头条：这就是传说中的土豪吗！
    BT_VIP_ACTIVATE_VIP6 = 53000000028,		//xxx激活了vip6，感谢xxx今天又拯救了诺林大陆的GDP！
    BT_VIP_ACTIVATE_VIP7 = 53000000029,		//xxx激活了vip7，有名的富商贾雷恩（化名）决定放弃首富的梦想，选择流浪！
    BT_VIP_ACTIVATE_VIP8 = 53000000030,		//xxx激活了vip8，著名海盗团团长透露，xxx已被列入了赏金榜中！
    BT_VIP_ACTIVATE_VIP9 = 53000000031,		//xxx激活了vip9，各大城镇首领纷纷发起社交宴席，邀请xxx赏光！
    BT_VIP_ACTIVATE_VIP10 = 53000000032,	//xxx激活了vip10，诺林大陆天降大雨，世界树都为xxx流下了眼泪！
    BT_BUY_DISCOUNT = 53000000033,			//消息都传上世界树啦！xxx购买了每日特惠！就是这么划算！
    BT_BUY_MOONCHARD = 53000000034,			//xxx激活了月卡！叶尔表示，不愧是我看中的人！就是有眼光！
    BT_BUY_NOVICE_FUND = 53000000035,		//xxx投资了萌新基金！传奇冒险家阿尔卡米感慨——我！后继有人！
    BT_BUY_GROWTH_FUND = 53000000036,		//xxx投资了成长基金！先知洛菲缇示下预言——此子，必成大器！
    BT_BUY_DREAM_FUND = 53000000037,		//xxx投资了梦想基金！泰拉瑞恩含泪——诺林大陆，就交给你了！
    BT_FIRST_RECHARGE = 53000000038,		//xxx完成了首充！森金调查团员奔走相告，我们项目有救啦！
    BT_FIRST_DAILY_RECHARGE = 53000000039,	//今天的太阳为何如此闪耀！原来是xxx进行了每日充值！
    BT_FESTIVAL_INVESTMENT = 53000000040,	//xxx购买了节日投资，豪礼不断，连精灵女王都羡慕！

    //工会
    BT_UNION_JOIN_UNION					= 53000000041,	//xxx加入了公会
    BT_UNION_QUIT_UNION					= 53000000042,	//xxx离开了公会
    BT_UNION_SEND_RED					= 53000000044,	//xxx购买了xxx，同时不忘给公会成员发个红包！抢红包xxx
    BT_UNION_STORAGE_EXCHANGE			= 53000000045,	//xxx兑换了xxx！
    BT_UNION_STORAGE_DONATE				= 53000000046,	//xxx捐献了xxx！
    BT_UNION_STORAGE_DESTORY			= 53000000047,	//xxx销毁了xxx件装备！
    BT_UNION_DUP_OPEN					= 53000000087,	//公会副本已开启，请大家速速参加。
    BT_UNION_LOST_DUP_SUBMIT_MATERIAL	= 53000000219,	//xxx玩家上交了1个“神意之书”，当前“神意之书”储备xxx！
    BT_UNION_LOST_DUP_OPEN				= 53000000220,	//会长开启了挑战失落神迹！

    //合成
    BT_COMPOSE_MATERIAL = 53000000043,			//xxx巧手天成，成功合了xxx！
    BT_COMPOSE_MATERIAL_EQUIP = 53000000048,			//xxx巧手天成，成功合了xxx！(参数是装备详细信息)
    BT_COMPOSE_MATERIAL_FAILED = 53000000092,			//xxx合成失败

    BT_ACTIVEITY_READY = 53000000049,	//限时活动xxx马上就要开始了，各位勇士快快准备吧！

    //领域
    BT_FIELD_LV_40 = 53000000050,		//xxx把xxx精炼至40级，战力突飞猛进！
    BT_FIELD_LV_50 = 53000000051,		//xxx把xxx精炼至50级，战力突飞猛进！
    BT_FIELD_LV_60 = 53000000052,		//xxx把xxx精炼至60级，战力突飞猛进！
    BT_FIELD_LV_70 = 53000000053,		//xxx把xxx精炼至70级，战力突飞猛进！
    BT_FIELD_LV_80 = 53000000054,		//xxx把xxx精炼至80级，战力突飞猛进！
    BT_FIELD_LV_90 = 53000000055,		//xxx把xxx精炼至90级，战力突飞猛进！
    BT_FIELD_LV_100 = 53000000056,		//xxx把xxx精炼至100级，战力突飞猛进！

    //占星
    BT_HOROSCOPE_DRAW = 53000000058,	//玩家xxx在占星中获得了道具xxx，真是羡煞旁人！
    BT_HOROSCOPE_WELFARE = 53000000059,	//消息都传上世界树啦！Xxx在占星中挥金如土，攒够福气值，获得了xxx！

    BT_MARRY_FRIST_MARRY = 53000000060,	//玩家xxx和xxx成功缔结誓约
    BT_MARRY_AGAIN_MARRY = 53000000061, //玩家xxx和xxx再次完成了誓约

    BT_HUNDUN_SUCCESS = 53000000062, //经过大家的不懈努力，混沌之龙已被击败，相关奖励已经通关邮件发放！
    BT_HUNDUN_FAILED = 53000000063,	//很遗憾，让混沌之龙逃走了，下次一定击败它！参与奖励已经通过邮件发送！
    BT_BOSS_SYSTEM_MSG = 53000000064,	//xxx在xxx击败了xxx，幸运的获得了xxx！

    BT_SCUFFLE_KILL_BOSS_ID = 53000000065, //击杀玩家或怪物可获得积分，积分足够后可进入下一层。
    BT_SCUFFLE_KILL_BOSS_ID_1 = 53000000066, //击杀玩家或怪物可获得积分，赢取最终奖励。

    BT_CHAOS_DRAGONS_ID_1 = 53000000067, //对BOSS造成伤害即可获得阶段活动（80%）奖励！高伤害玩家可获得伤害排名宝箱！
    BT_CHAOS_DRAGONS_ID_2 = 53000000068, //对BOSS造成伤害即可获得阶段活动（60%）奖励！
    BT_CHAOS_DRAGONS_ID_3 = 53000000069, //对BOSS造成伤害即可获得阶段活动（40%）奖励！
    BT_CHAOS_DRAGONS_ID_4 = 53000000070, //对BOSS造成伤害即可获得阶段活动（20%）奖励！
    BT_CHAOS_DRAGONS_ID_5 = 53000000071, //对BOSS完成最后一击，可获得终极奖励 补刀宝箱！

    BT_DISPUTE_WAR_RED_OCCUP_CRY1 = 53000000072,	//红色阵营夺得了能量水晶 - 天的控制权，获得了水晶能量的强化。
    BT_DISPUTE_WAR_RED_OCCUP_CRY2 = 53000000073,	//红色阵营夺得了能量水晶 - 地的控制权，获得了水晶能量的强化。
    BT_DISPUTE_WAR_RED_OCCUP_CRYBOTH = 53000000074, //红色阵营同时控制了两座能量水晶，能力获得了极大的强化。
    BT_DISPUTE_WAR_BLUE_OCCUP_CRY1 = 53000000075,	//蓝色阵营夺得了能量水晶 - 天的控制权，获得了水晶能量的强化。
    BT_DISPUTE_WAR_BLUE_OCCUP_CRY2 = 53000000076,	//蓝色阵营夺得了能量水晶 - 地的控制权，获得了水晶能量的强化。
    BT_DISPUTE_WAR_BLUE_OCCUP_CRYBOTH = 53000000077,//蓝色阵营同时控制了两座能量水晶，能力获得了极大的强化。

    BT_CONGRATULATION_WING_LVUP = 53000000078,		//恭喜XXX玩家翅膀达到XXX阶
    BT_CONGRATULATION_PARTNER_LVUP = 53000000079,	//恭喜XXX玩家契灵达到XXX阶
    BT_CONGRATULATION_TREASURE_LVUP = 53000000080,	//恭喜XXX玩家宝具达到XXX阶
    BT_CONGRATULATION_ELEMENT_LVUP = 53000000081, 	//恭喜XXX玩家XXX元素达到XXX阶
    BT_CONGRATULATION_ADD_TITLE = 53000000082, 		//恭喜XXX玩家激活XXX称号
    BT_CONGRATULATION_ADD_ADV_SKILL = 53000000083, 	//恭喜XXX玩家解锁了XXX冒险获得XXX技能
    BT_CONGRATULATION_PASS_LADDER_DUP = 53000000084,//恭喜XXX玩家通过了纹章宝库XX
    BT_CONGRATULATION_ADD_RARE_ITEM = 53000000085, 	//恭喜XXX玩家获得稀有道具XXX
    BT_CONGRATULATION_ADD_RARE_EQUIP = 53000000086,	//恭喜XXX玩家获得稀有装备XXX
    BT_POKER_RANKING_NOTIFY = 53000000088,			//第xxx局，第xxx名是：xxx公会的xxx，牌型为xxx，分数：xxx xxx

    BT_CHAOS_DRAGONS_KILL_BOSS = 53000000093,		//xxx在混沌之龙活动中冲锋陷阵，一往无前，对混沌之龙造成了最后一击！
    BT_EQUIP_SUIT_LV = 53000000094,					//历经千辛万苦，xxx终于把xxx锻造为xxx套装。
    BT_WING_ACTIVE = 53000000095,					//xxx成功激活了翅膀：xxx
    BT_WING_LEVUP = 53000000096,					//xxx成功把翅膀：xxx升星至xxx星
    BT_TREASURE_ACTIVE = 53000000097,				//xxx成功激活了宝具：xxx
    BT_TREASURE_LEVUP = 53000000098,				//xxx成功把宝具：xxx升星至xxx星
    BT_PARTNER_ACTIVE = 53000000099,				//xxx成功激活了契灵：xxx
    BT_PARTNER_LEVUP = 53000000100,					//xxx成功把契灵：xxx升星至xxx星
    BT_SOLO_SCORE_LEVUP = 53000000101,				//solo钻石以上广播
    BT_FIELD_ACTIVE_BC = 53000000102,				//xxx成功激活了xxx领域，战力获得了巨大提升
    BT_ACTIVITY_SCUFFLE_OVER_BC = 53000000103,		//xxx战力爆表，无人可挡，成功通关了绝地乱斗！


    BT_UNION_WAR_CALL_PARTNER = 53000000109,		//请大家速度赶往xxx，坚守阵地
    BT_UNION_WAR_USE_SKILL = 53000000110,		//管理层释放了能量技能【xxx】，10秒内获得极高属性增强！大家一起上！
    BT_UNION_WAR_BUILDING_DESTROY = 53000000111,	//xxx已被摧毁！守护方要加油啊！
    BT_UNION_WAR_FIRST_CYCLE_START = 53000000112,	//荣耀之战第一轮比赛开始！请参赛公会成员速速进入比赛场地参与比赛！
    BT_UNION_WAR_SECOND_CYCLE_START = 53000000113,	//荣耀之战第二轮比赛开始！请参赛公会成员速速进入比赛场地参与比赛！
    BT_MAP_BOSS_ALIVE = 53000000114,				//xxx在xxx复活了，请各位勇士前去讨伐！

    BT_DISPUTE_WAR_PLAYER_ENTER_NOTICE = 53000000115,//处于中心区域即可每秒获得积分，摧毁地图两侧的水晶可获得增强BUFF！


    BT_ACTIVITY_START = 53000000116,    //xxx活动开启！
    BT_ACTIVITY_BOX_START_MAP = 53000000117,    //xxx场景出现大量宝箱，先到先得！


    BT_DUPLICATE_STORY = 53000000200,			//恭喜玩家xxx在挑战剧情副本时人品爆发获得了稀有道具xxx。
    BT_DUPLICATE_ExcusiveBoss = 53000000201,	//恭喜玩家xxx在挑战个人首领时人品爆发获得了稀有道具xxx。
    BT_DUPLICATE_Gods = 53000000206,			//恭喜玩家xxx在挑战诸神园墟时人品爆发获得了稀有道具xxx。
    BT_DUPLICATE_UnionBoss = 53000000207,		//恭喜玩家xxx在挑战公会首领时人品爆发获得了稀有道具xxx。

    BT_MAP_BOSS_GAIN_ITEM = 53000000202,		//恭喜玩家xxx在挑战野外首领时人品爆发获得了稀有道具xxx。
    BT_VIP_BOSS_GAIN_ITEM = 53000000203,		//恭喜玩家xxx在挑战vip首领时人品爆发获得了稀有道具xxx。
    BT_BARREN_BOSS_GAIN_ITEM = 53000000204,		//恭喜玩家xxx在挑战深渊首领时人品爆发获得了稀有道具xxx。
    BT_SECRET_BOSS_GAIN_ITEM = 53000000205,		//恭喜玩家xxx在挑战秘境首领时人品爆发获得了稀有道具xxx。

    BT_SERVER_OPEN_ADVANCE = 53000000208,		//恭喜玩家xxx在开服冲榜中达成目标获得了稀有物品xxx。
    BT_SERVER_OPEN_BUY = 53000000209,			//恭喜玩家xxx在开服限购中购买了稀有物品xxx，大家快去抢购吧

    BT_FESTIVAL_SMASH_EGG = 53000000210,		//恭喜玩家xxx在惊喜砸蛋中福星高照获得了稀有物品xxx。
    BT_FESTIVAL_EXCHANGE = 53000000211,			//恭喜玩家xxx经过辛勤努力在庆典活动中兑换了道具xxx。
    BT_FESTIVAL_YANHUA = 53000000212,			//恭喜玩家xxx在烟花庆典中福星高照获得了稀有物品xxx。

    BT_OPERATE_LIMIT_GIFT = 53000000213,		//恭喜玩家xxx购买开服礼包，获得了稀有道具xxx。
    BT_OPERATE_LIMIT_GIFT_ZERO = 53000000214,	//恭喜玩家xxx购买0元礼包，获得了稀有道具xxx，还会返还所有花费。

    BT_POKER_READY_NOTIFY = 53000000215,//点选任意数量的扑克牌，然后点击【换牌】可以再次抽牌；每局有一次换牌机会；换牌后若有新的牌型组合得分翻3倍！

    BT_3v3_GUESS_READY_NOTIFY = 53000000216,//3V3竞猜准备通知
    BT_MAPBOSS_FIRST_KILL1 = 53000000217,		//boss 个人首杀
    BT_MAPBOSS_FIRST_KILL2 = 53000000218,		//boss 队伍首杀
    BT_MARRY_WEDDING_BEGIN = 53000000221,		//婚宴开始了
    BT_MARRY_WEDDING_FULL_BOX = 53000000222,	//神意袭来，地上的箱子刷满了！
    BT_MARRY_WEDDING_NEW_WARM = 53000000223,	//场景中气氛高涨，温馨值达到了xxx，此时一股神意袭来，刷出来的箱子更高级了！与会者可采集的次数也增加了！
    BT_MARRY_WEDDING_SECOND_STAGE_BC = 53000000224, //以世界树之名，群星见证了xxx与xxx的誓约，从此…………
    BT_WORLD_BOSS_REFRESH = 53000000225,		//混沌巨龙刷新了！
    BT_WORLD_BOSS_DEAD = 53000000226,			//混沌巨龙挂了！
    BT_WORLD_BOSS_WILL_DIE = 53000000227,		//混沌巨龙要死了！快点！

    BT_MARRY_WEDDING_NOTICE_BROADECAST = 53000000228, //xxx和xxx的婚宴典礼即将在xxx开始，请留意时间！


    BT_OPERATIONTURNTABLE_DRAW = 53000000229, //恭喜玩家xxx在幸运转盘中福星高照抽到了xxx。
    BT_UNION_WAR_20_BROAD = 53000000231,	//过去20秒内，本公会积分增加细节：建筑加分xxx，采集加分xxx，击败对手玩家加分xxx，斩获首领加分xxx。
    BT_UNION_WAR_KILL_BOSS = 53000000232,	//xxx斩获了首领的狗头，为本公会增加了积分xxx！

    BT_ANCIENT_DRAGEON_ACT_END = 53000000250, //远古龙域活动结束

    BT_MANOR_CAPTURE = 53000000248,		//领土争夺占领广播
    BT_MANOR_ATTACK_1 = 53000000251,		//公会对领地xxx发起了进攻！请火速支援！
    BT_MANOR_ATTACK_2 = 53000000252,		//公会xxx对我公会的领地xxx发起宣战！请注意布防！
    BT_MANOR_CROSS_LOGIN = 53000000253,		//远征王者xxx上线了，一时间雷光电影，地动山摇，大家快去摩拜！
    BT_WORLD_BOSS_HP_BORAD = 53000000260,	//会掉超多好东西可以随便捡的xxx在xxx被鞭挞得不要不要的！快点一起盘它！(剩余xxx)
    BT_ANCIENT_WAVE = 53000000280,	//怪物正在进攻，请到水晶处协防！当前第xxx/xxx波。
    BT_ANCIENT_END = 53000000281, //活动已结束！
    BT_DIE_DROP = 53000001001, //您因死亡掉落了：xxx X xxx!

    BT_1V1_RIDICULE = 53000001011,				//面对xxx玩家的决斗挑战，xxx玩家“认怂”，选择了拒绝！
    BT_WORLD_BOSS_KILL_PLAYER = 53000001012,	//玩家xxx挑战xxx时被阵亡了，他的勇气可歌可泣!
    BT_WORLD_BOSS_ALIVE_NOTIFY = 53000001013,   //世界BOSSxxx正在本地肆虐快去集结勇士讨伐它吧！

    BT_ARRIVAL_BOSS_ID1 = 53000001020, //降临BOSS生命已经达到xxx，击败可以获得丰厚奖励，快去讨伐吧
    BT_ARRIVAL_BOSS_ID2 = 53000001021, //玩家xxx召唤了降临boss,讨伐BOSS海量奖励大家快来讨伐吧
    BT_ARRIVAL_BOSS_ID3 = 53000001022, //降临boss已被玩家xxx击败，排名第一的玩家是xxx，快去完成献祭再次召唤吧

    //结婚广播

    BT_MARRY_MARRY = 133,	//恭喜XXX与xxx缔结誓约，成为全服第xx队令人羡慕的伴侣
    BT_MARRY_WEDDING_NOTICE = 134,	//XXX与xxx的婚宴即将开始
    BT_MARRY_WEDDING_TOUR_NOTICE = 135,	//XXX与xxx的婚宴巡游开始
    BT_MARRY_WEDDING_START = 136,	//XXX与xxx的婚宴已经开始
    BT_MARRY_MAKE_WEDDING = 137,    //XXX与xxx的婚宴将于xx点开始，请大家参与
    BT_WEDDING_FIRE = 138,      //xxx燃放了xxx，仪式热度+xxx点
    BT_WEDDING_CAKE_HIT = 139,  //xxx被蛋糕扔中，居然变声成为了xxx
    BT_WEDDING_QY = 150,    //结缘双方顺利通过了考验，亲友满意地送出了礼物

};


/*--------------------------------------------
*	传闻或各系统广播消息所需发送数据结构体定义
-------------------------------------------*/
struct SystemChatMsgData
{
    std::vector<proto_ff::RolePlayerMiniInfo> players;		//玩家基本数据
    std::vector<std::string> 				  text;				//突出显示的文本数据，例如：XXX副本 XXX怪物 XX工会 XX杀等等
    std::vector<uint64_t>					  params;			//数字参数：颜色等级，工会id 副本id 等数据都按顺序填充到这个字段
    VEC_ITEM_PROTO_EX						  items;
    //CTODO后续继续扩展

    SystemChatMsgData()
    {
        players.clear();
        text.clear();
        params.clear();
        items.clear();
    }

    void Clear()
    {
        players.clear();
        text.clear();
        params.clear();
        items.clear();
    }
};

const uint32_t MAX_OFFLINE_MSG = 15;   //每人最多保存20个离线私聊记录
const uint32_t CHAT_WORLD_USE_GOODS_ID = 180109003;	//小喇叭
const uint32_t CHAT_WORLD_USE_HORN_GOODS_ID = 180109004;//大喇叭

const uint32_t CHAT_WORLD_CD_TIME = 10;
const uint32_t CHAT_OTHER_CD_TIME = 5;



/////////////////////////////////  特殊事件的跑马灯  /////////////////////////////////////////

enum EChatSpecialEvent
{
    EChatSpecialEvent_EquipRefine = 4,	//装备精炼
    EChatSpecialEvent_ArenaRank = 5,	//竞技场排名
    EChatSpecialEvent_ComposStone = 6,	//宝石合成
    EChatSpecialEvent_UnionHall = 7,	//工会大厅等级
};
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


//游戏内用到的所有来源，包括道具和货币来源(已经定义的来源跟内部统计日志逻辑有关，如需改动已定义的来源，请咨询下负责统计日志的相关人员)
enum ESource
{
    S_NONE						= 0,
    S_GM						= 1,	//GM命令
    S_MISSION					= 2,	//任务奖励 来源值1：任务ID
    S_USE_ITEM					= 3,	//使用物品 来源值1：物品ID
    S_FRIEND					= 4,	//好友 来源值1：1-送礼，2-送礼失败
    S_Chat						= 5,	//聊天 来源值1:频道ID
    S_Born						= 6,   //创角
    S_SkillDamage				= 7,	//技能伤害
    S_MissionSubmitItem			= 8,	//提交物品任务 来源值1：任务动态ID
    S_Mail						= 9,	//领取邮件附件
    
    S_Treasure_Levup			= 10,	//宝具 升级 来源值1：类型， 来源值2：升级的宝具ID
    S_Wing_Levup				= 11,	//翅膀 升级 来源值1：类型， 来源值2：升级的翅膀ID
    S_Artifact_Levup			= 12,	//神器幻化 来源值1：神器ID, 来源值2：神器ID幻化之前的星级
    S_Partner_Levup				= 13,	//伙伴 升级 来源值1：类型， 来源值2：升级的伙伴ID
    
    S_USE_BOX_ITEM				= 14,	//使用box类物品,来源值1：boxid,来源之2：物品ID
    S_Package_Storage			= 15,	//背包和仓库物品移入移出
    S_Mission_OnceFinish		= 16,	//任务立即完成，来源值1：任务配置ID
    S_Equip_Strong				= 17,	//装备强化 来源值1：装备部位， 来源值2：强化之前的等级
    S_Arena_Challenge			= 18,	//竞技场 挑战奖励
    S_Change_RoleName			= 19,	//角色改名
    S_Change_RoleNameFail		= 20,	//角色改名失败
    
    S_BossDrop					= 21,	//BOSS掉落,来源参数1：BOSS类型
    S_EquipMarryStrong			= 22,	//结婚装备强化，来源值1：equip.xlsx-marry表 id 字段
    S_Vip						= 23,	//vip
    S_Teleport					= 24,	//传送门传送，来源值1：传送门配置ID
    S_KillMonsExp				= 25,	//打怪经验，来源值1：怪物配置ID
    
    S_Mission_OnekeyFinishLoop	= 26,	//一键完成诺林冒险
    S_Mission_OnekeyFinishGuild = 27,	//一键完成工会任务  来源值1：完成的次数
    
    S_hangup					= 28,	//挂机
    
    S_grow						= 29,	//养成
    S_EquipChg					= 30,	//装备换装
    
    S_FunctionUnlock			= 31,	//
    S_GodRelics					= 32,	//天机谱
    S_DailyTask					= 33,	//Daily Task
    S_Dup						= 34,	//副本
    
    S_SkillInit					= 35,	//初始化添加技能
    S_SkillUpgrade				= 36,	//技能升级, 来源值1：等级
    S_RoleLevup					= 37,	//角色升级
    S_Dup_Tower					= 38,	//爬塔领奖
    S_SkillWakeup				= 39,	//技能觉醒
    
    S_Buff						= 40,	//buff, 来源值1：技能ID，来源值2：buffid
    S_Boss_back					= 41,	//boss 找回
    S_MonsSkillInit				= 42,	//怪物初始化添加技能 来源值1：怪物配置ID
    S_Stone_lv					= 43,	//宝石升级
    S_EQUIP_STOVE				= 44,	//装备熔炼
    
    S_SellItem				    = 45,	//出售物品
    S_EnterBoss					= 46,	//进入boss地图
    S_Pet_Hatch					= 47,	//宠物孵化
    S_Pet_Fetter				= 48,	//宠物羁绊
    S_Pet_Lv					= 49,	//宠物升级
    S_Pet_StepLv				= 50,	//宠物进阶
    S_Pet_StarLv				= 51,	//宠物升星
    S_Pet_Rest					= 52,	//宠物重生
    S_Pet_Decompose				= 53,	//宠物分解
    S_Pet_EggUnlock				= 54,	//宠物蛋位置解锁
    S_Mall						= 55,	//商城，来源值1：商品ID
    S_SkillAdv					= 55,	//技能进阶，来源值1：进阶类型，来源值2：进阶等级
    S_SkillAdvChgpos			= 56,	//修改技能进阶位置， 来源值1：旧进阶类型，来源值2：新进阶类型
    S_Pet_War					= 57,	//宠物出战，来源值1：宠物配置ID，来源值2：宠物实例ID
    S_Pet_HaveRest				= 58,	//宠物休息，来源值1：宠物配置ID，来源值2：宠物实例ID
    
    S_Faction_Create			= 59,	//创建帮派
    S_Faction_ChgName			= 60,	//帮派改名
    S_Faction_ChgNameFail		= 61,	//帮派改名失败
    
    S_Convoy_Fresh				= 62,	//刷新镖车 来源值1：当前选中的镖车ID, 来源值2：目标镖车ID
    S_Convoy_Commit				= 63,	//提交镖车 来源值1：当前选中的镖车ID
    S_Armor						= 64,	//玄真护甲
    S_Mission_OnekeyFinishBOUNTY	= 65,	//一键完成赏金任务
    S_Mission_MissionBOUNTYSpecialReward	= 66,	//一键完成赏金任务
    S_Assist					= 67,	//boss助战
    S_Equip_Wash_unlock			= 68,	//装备洗练解锁
    S_Equip_Wash				= 69,	//装备洗练解锁
    S_GodEvil_Notice			= 70,	//神魔 预告奖励
    S_GodEvil_Task				= 71,	//神魔 任务奖励
    S_GodEvil_Active			= 72,	//神魔 激活奖励
    S_GodEvil_Upgrade			= 73,	//神魔 升级 来源值1：当前等级
    S_GodEvil_ChgFacade			= 74,	//神魔 变身
    S_Equip_Suitlv				= 75,	//套装升级
    
    S_Pay_Deliver				= 76,	//充值发货，来源值1:rechargeid
    
    
    S_Faction_Donate			= 77,	//帮派捐献
    S_Faction_SalaryFetch		= 78,	//领取帮派工资奖励 来源值1：工资id
    S_BestEQ_Task				= 79,	//神机装备前置任务
    S_BestEQ_Decompose			= 80,	//神机装备分解
    S_BestEQ_Strong				= 81,	//神机装备打造
    S_BestEQ_Dress				= 82,	//神机装备穿戴
    S_BestEQ_Pour				= 83,	//神机装备注灵
    S_BestEQ_Break				= 84,	//神机装备铭刻
    S_BestEQ_Awaken				= 85,	//神机装备觉醒
    
    S_PT_StageUp				= 86,	//修真升级材料消耗
    S_PT_StageDJ				= 87,	//修真渡劫材料消耗
    S_PT_EventItemsRecv			= 88,	//修真事件道具领取
    S_PT_GBEnterArea			= 89,	//修真神塊进入新的区域
    S_PT_GBLvlUp				= 90,	//神魂升级
    S_PT_EBLvlUp				= 91,	//淬炼（飞升）升级
    S_PT_AttriUpdate			= 92,	//修真属性变更
    S_PT_GF_Active				= 93,	//修真功法激活
    S_PT_GF_LvlUp				= 94,	//修真功法升级
    S_PT_GF_StageUp				= 95,	//修真功法进阶
    S_PT_JM_LvlUp				= 96,	//修真脉升级
    S_PT_JM_StageUp				= 97,	//修真脉冲破
    S_PT_LG_Active				= 98,	//修真灵根激活
    S_PT_LG_EatPotion			= 99,	//修真吃丹药
    
    S_Collect					= 100,   //采集 来源值1：怪物配置ID
    
    S_Dinner					= 101,   //帮派晚宴
    S_Trans						= 102,   //帮派传功
    
    S_Ancient					= 103,   //上古神灵
    
    S_FactionSkill				= 104,	 //帮派技能升级
    
    S_Marry_Apply				= 105,	 //结婚申请
    S_Marry_Recv_Gear			= 106,	 //结婚领取奖励
    S_Marry_Child_Active		= 107,	 //结婚仙娃激活
    S_Marry_Child_Lv			= 108,	 //结婚仙娃升级
    S_Marry_Child_Star			= 109,	 //仙娃升星
    S_Marry_Express				= 110,	 //表白
    S_Marry_Buy_Dup				= 111,	 //结婚购买副本次数
    S_Marry_Lock_lv				= 112,	 //结婚同心锁升级
    S_Marry_Buy_Card			= 113,	 //购买宝匣
    S_Marry_Card_Recv			= 114,	 //领取购买宝匣奖励
    S_Marry_Dup					= 115,	 //情缘副本
    S_Marry_Task				= 116,	 //结婚前置任务
    S_Marry_BuySeat				= 117,	 //结婚购买席位
    
    S_SkillTalentReset			= 118,	 //技能天赋重置
    
    S_GuildAnswer				= 119,	 //帮派答题
    S_GVBDailyScoreReward		= 120,	 //神机谷日积分奖励
    
    S_EmblemLv					= 121,   //战徽战旗进阶 来源值1：id, 来源值2:阶级
    S_EmblemStar				= 122,   //战徽战旗升星 来源值1：id, 来源值2:星级
    S_1V1_DailyReward			= 123,	 //1v1领取每日奖励 来源值1：id
    S_1V1_Finish				= 124,	 //1v1完成奖励 来源值1：boxid
    
    S_GodEvil_BuyPriv			= 125,   //购买神魔特权 来源值1：特权类型，来源值2:特权等级
    
    S_PT_gfBookPurchase			= 126,   //修真功法书本购买
    S_Merge						= 127,	 //合成
    S_PS_Purchase				= 128,	//个人商店购买
    
    S_Wedding_sign				= 129,  //婚礼签到
    S_Wedding_collect_cake		= 130,  //婚礼采集蛋糕
    S_Wedding_kill_monster		= 131,	//婚礼杀怪
    S_Wedding_fire				= 132,	//婚礼放烟花
    S_Wedding_exp				= 133,	//婚礼添加经验
    S_Weddomg_collect_yx		= 134,  //婚礼采集宴席
    
    S_WPP_ExpAdd				= 135,	//圣母瑶池加经验
    S_QY_PassLayer				= 136,	//青云通过副本
    S_Marry_red					= 137,	//结婚巡游红包
    S_WPP_MassageReward			= 138,	//按摩奖励
    S_WarWinReward				= 139,  //帮派战主宰帮派每日俸禄
    S_1v1ReadyMap				= 140,  //1v1准备场景
    S_FetchFirstCharge			= 141,  //领取首充活动奖励 来源值1：type, 来源值2：id, 来源值3: onekey
    S_FetchOpenTotal			= 141,  //领取贵族-开服累充 奖励 来源值1：id
    S_Clan3_chg_name			= 142,	//3v3战队改名
    S_GiftCondBuy				= 143,	//购买条件礼包 来源值1：id
    S_GiftZeroBuy				= 144,	//购买0元礼包 来源值1：id
    S_GiftZeroFetch				= 145,	//领取0元礼包返还的货币 来源值1：id
    S_Relive					= 146,	//角色复活 来源值1：复活类型
    S_3v3_day_reward			= 147,	//3v3每日参与奖励
    S_CloudPeak_ExpAdd			= 148,	//云颠PK加经验
    S_FindTreasureBigDragon	    = 149,	//真龙寻宝巨龙宝藏
    S_FindTreasureFindTreasure	= 150,	//真龙寻宝
    S_Vip_lv_gift				= 151,	//vip等级礼包
    S_Vip_0_gift				= 152,	//vip0元购
    S_Vip_day_gift				= 153,	//vip每日礼包
    S_Vip_0_retrun				= 154,	//vip0元购返还
    
    S_Fest_ShopBuy				= 160,  //节日活动商店购买，来源值1：节日模板ID，来源值2：id
    S_Fest_Sign					= 161,	//节日活动签到，来源值1：节日模板ID，来源值2：期数
    S_Fest_GoldStoreBuy			= 162,	//节日活动金库购买，来源值1：节日模板ID，来源值2：id
    S_Fest_Lottery				= 163,	//节日活动抽奖，来源值1：节日模板ID，来源值2：id
    S_Fest_ResetLottery			= 164,  //节日活动重置抽奖，来源值1：节日模板ID，来源值2：期数
    S_Fest_DailyTotalRecharge	= 165,  //节日活动购买，来源值1：节日模板ID，来源值2：id
    S_Fest_ServerRank           = 166,  //节日活动排行榜，来源值1：节日模板ID，来源值2：id
    S_Fest_DigEggTaskFetch		= 167,	//节日活动砸蛋任务领奖，来源值1：节日模板ID，来源值2：任务id
    S_Fest_CandleFetch			= 168,	//节日活动烛龙挑战领奖，来源值1：节日模板ID，来源值2：id
    S_Fest_CandleAutoFetch		= 169,	//节日活动烛龙挑战自动领奖，来源值1：节日模板ID
    
    S_Dragon_Lev				= 171,	//幻世烛龙 升级 来源值1：等级, 来源值2：经验
    S_Dragon_Frag				= 172,	//幻世烛龙 使用碎片
    S_Dragon_Star				= 173,	//幻世烛龙 升星 来源值1：id, 来源值2：星级,来源值3：是否是激活
    S_Subpack_Reward			= 174,	//领取分包奖励
    S_Market_up					= 175,	//市场上架
    S_Market_vie				= 176,	//市场竞价
    S_Market_vie_return			= 177,	//竞价返还
    S_Fest_bosskf				= 178,	//boss首杀
    S_BestEQ_Return_pre			= 179,	//神机返回上一级
    S_Equip_Undress				= 180,	//脱装备
    S_Equip_dress				= 181,	//穿装备
    S_Equip_refine_lv			= 182,	//精炼升级
    S_Equip_refine_attr			= 183,	//精炼洗属性
    S_Fest_huimengxiyou	        = 184,  //回梦西游
    S_Fest_marry				= 185,	//完美情人
    S_Red_fetch					= 186,  //领取红包奖励 来源值1：领取类型，来源值2：配置ID
    S_Equip_Awaken_lv			= 187,	//装备觉醒升级
    S_Equip_Awaken_break		= 188,	//装备突破
    S_Equip_soaring_lv			= 189,	//飞升
    S_Equip_quality_lv			= 190,	//升品
    S_Equip_seal_inlay			= 191,	//印记镶嵌
    S_Equip_seal_lv				= 192,	//印记升级
    S_Star_Awaken_lv	        = 193,	//不灭星辰觉醒
    S_Star_Fantasy_Active	    = 194,	//不灭星辰幻化激活
    S_Star_Fantasy_lv	        = 195,	//不灭星辰幻化升级
    S_Star_Attr_GuiZheng	    = 196,	//不灭星辰归真
    S_Star_SKILL_SLOT           = 197, //不灭星辰槽位激活
    S_Star_SKILL_LEVEL          = 198, //不灭星辰技能升级
    S_Star_SKILL_Shop           = 199, //不灭星辰Shop
    
    S_GodEvil_undress			= 200,	//卸下神魔装备 来源值1:位置，来源值2：卸下装备的ID
    S_GodEvil_wearqua			= 201,	//神魔装备升阶 来源值1：装备ID，来源值2：新装备ID, 来源值3：总经验
    S_GodEvil_qualv				= 202,	//神魔装备升品 来源值1：装备ID，来源值2：新装备ID
    S_GodEvil_make				= 203,	//神魔装备打造 来源值1：类型, 来源值2：id, 来源值3：新装备ID
    S_GodEvil_dress				= 204,	//穿戴神魔装备 来源值1：位置，来源值2：穿戴装备ID，来源值3：卸下装备的ID
    S_GodEvil_trans				= 205,	//神魔装备转移 来源值1：原始穿戴装备，来源值2：背包装备ID，来源值3：转移之后穿戴的装备ID
    S_GodMetaPrivilege			= 206,	//神元地域特效购买
    S_Turn_turning				= 207,  //神体转生
    S_Turn_strong				= 208,	//神体强化
    S_Turn_evolve				= 209,	//神体进化
    S_Turn_awaken				= 210,	//神体觉醒
    S_Turn_compose				= 211,	//神体神炼
    S_Turn_starup				= 212,	//神体升星
    S_Turn_suit					= 213,	//神体套装
    S_Guwu						= 214,	//鼓舞
    S_GVB_Skill					= 215,//神机谷战场特殊技能
    
    S_MountKun_levlevel         = 220,  //坐骑化鲲升级
    S_MountKun_AdvanceLevel     = 221,  //坐骑化鲲进阶
    S_MountKun_Star             = 222,  //坐骑化鲲升星
    S_GodMetaTimeRecharge		= 223,	//神元地域时间兑换
    S_MountKun_equipStrong      = 224,  //坐骑化鲲装备强化
    S_MountKun_equipStrongLv      = 225,  //坐骑化鲲装备进阶
    S_MountKun_equipWakeLv      = 226,  //坐骑化鲲装备突破
    S_MountKun_TiWuLv           = 227,  //坐骑化鲲提悟升级
    S_MountKunChange_Active     = 228,  //坐骑化鲲异化激活
    S_MountKunChange_Star		= 229,  //坐骑化鲲异化升星
    S_Pet_Grow_Active			= 230,	//宠物专属激活
    S_Pet_Grow_Strong			= 231,	//宠物专属强化
    S_Pet_Grow_Starlv			= 232,	//宠物专属升星
    S_Pet_Grow_StarReset		= 233,	//宠物专属升星重置
    S_MountFairySlot            = 234, //坐骑坐骑历练
    S_Pet_YaoHun_Unlock			= 235,	//妖魂解锁
    S_Pet_Lianyao				= 236,	//妖魂炼妖
    S_Pet_Qs_Lianyao			= 237,	//快速炼妖
    S_Pet_exchange				= 238,	//妖气兑换
    S_Pet_yaohun_lv				= 239,	//妖魂升级
    S_Pet_yaohun_tp				= 240,	//妖魂突破
    S_Pet_lianyao_tq			= 241,	//炼妖特权购买
    S_Pet_yaohun_reset			= 242,  //妖魂分解
    
    S_MISSION_GuildPre          = 250, //公会声望
    S_MISSION_GuildWEEKLOOP     = 251, //公会周循环
    
    S_Fest_mons_drop			= 260,  //节日活动打怪掉落 来源值1：怪物ID，来源值2：怪物等级
    S_Fest_DayTotalRecharge		= 261,	//节日活动每日累充领奖，来源值1：节日模板ID，来源值2：id
    S_Fest_DayTotalRechargeAuto	= 262,	//节日活动每日累充 自动领奖，来源值1：节日模板ID
    S_Fest_LoginAuto			= 263,	//节日活动登录奖励 自动领奖，来源值1：节日模板ID
    S_Fest_LoginFetch			= 264,	//节日活动登录奖励 领奖 来源值1：节日模板ID，来源值2：day
    S_Fest_TotalRechargeFetch	= 265,	//节日活动累计充值 领奖 来源值1：节日模板ID，来源值2：id
    S_Soul_Task					= 267,	//战魂前置任务
    S_Soul_lv					= 268,	//魂灵升级
    S_Soul_step					= 269,	//魂灵进阶
    S_Soul_pool_bless_lv		= 270,	//聚灵池祝福
    S_Soul_pool_pg_lv			= 271,	//聚灵池特权升级
    S_Equip_Gem_open			= 272,	//宝石解锁
    S_Rune_dress				= 273,	//符文穿戴
    S_Rune_undress				= 274,  //符文卸载
    S_Rune_lv					= 275,  //符文升级
    S_Rune_step					= 276,	//符文进阶
    S_Rune_make					= 277,	//符文淬炼
    S_Rune_star					= 278,	//符语升星
    S_Rune_jj_active			= 279,	//符文绝技激活
    S_Rune_decompose			= 280,	//符文分解
    //deity
    S_Deity_SKILL               = 281, //天神技能
    S_DEITY_LV                  = 282, //天神升级
    S_DEITY_RRAGMENT             = 283, //天神碎片
    S_DEITY_ACTIVE_FANTASY      = 284, //天神幻化激活
    S_DEITY_FANTASY_LV      = 285, //天神幻化升级
    S_DEITY_FANTASY_STAR      = 286, //天神幻化升星
    S_DEITY_UNLOCK_BATTLE_SLOT = 287, //天神幻化解锁战斗槽位
    S_DEITY_FANTASY_EQUIP_STRONG = 288, //天神幻化强化装备
    S_DEITY_FANTASY_EQUIP_STRONG_QUALITY = 289, //天神幻化强化装备品质
    S_DEITY_FANTASY_EQUIP_DRESS = 290, //天神幻化装备穿戴 卸下
    S_DEITY_FANTASY_EQUIP_UNDRESS = 291, //天神幻化装备卸下
    S_DEITY_FANTASY_EQUIP_DECOMPOSE = 292, //天神幻化装备分解
    
    //奇门八卦
    S_MoFa_UNLOCK_SLOT = 300, //解锁槽位
    S_MoFa_UnDress_Equip = 301, //卸装备
    S_MoFa_ZuFu = 302, //祝福
    S_MoFa_Equip_LV = 303, //装备升级
    S_MoFa_Equip_WAKE = 304, //装备觉醒
    S_MoFa_Exchange = 305, //兑现
    S_MoFa_Decompose = 306, //装备分解
    
    S_Treasure_ActiveSoul			= 310,	//宝具 激活器魂
    S_Wing_ActiveSoul				= 311,	//翅膀 激活器魂
    S_Artifact_ActiveSoul			= 312,	//神器幻化 激活器魂
    S_Partner_ActiveSoul			= 313,	//伙伴 激活器魂
    S_Treasure_SoulLv			= 314,	//宝具 器魂升级
    S_Wing_SoulLv				= 315,	//翅膀 器魂升级
    S_Artifact_SoulLv			= 316,	//神器幻化器魂升级
    S_Partner_SoulLv			= 317,	//伙伴 器魂升级
    S_Treasure_SoulRecv			= 318,	//宝具 器魂成就领取
    S_Wing_SoulRecv				= 319,	//翅膀 器魂成就领取
    S_Artifact_SoulRecv			= 320,	//神器幻化器魂成就领取
    S_Partner_SoulRecv			= 321,	//伙伴 器魂成就领取
    S_Treasure_SoulResetSkill			= 322,	//宝具 器魂重置技能
    S_Wing_SoulResetSkill				= 323,	//翅膀 器魂重置技能
    S_Artifact_SoulResetSkill			= 324,	//神器幻化器魂重置技能
    S_Partner_SoulResetSkill			= 325,	//伙伴 器魂重置技能
    S_END,
};


//通用的来源结构
struct SCommonSource
{
    // ------------------ 来源  ---------------------------
    ESource src = S_NONE;				//运营需要的物品来源
    int64_t param1 = 0;					//运营来源参数1(根据不同的来源确定值)
    int64_t param2 = 0;					//运营来源参数2(根据不同的来源确定值)
    int64_t param3 = 0;					//运营来源参数3(根据不同的来源确定值)
    
    // ------------------- A_CUR_HP 相关 --------------------------
    
    uint64_t killerCid = 0;				//击杀者cid,目前用于技能击杀生物时，传入击杀者的cid
    int64_t  damageVal = 0;				//击杀者对被击者造成的伤害
    uint64_t skillId = 0;				//击杀者使用的技能ID
    
    bool bTips = true;					//是否通知客户端弹出TIPS
    
    
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

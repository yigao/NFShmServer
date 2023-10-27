#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

enum AchievementEventType
{
    ACHIEVEMENT_EVENT_LEVELUP = 1,   //人物等级
    ACHIEVEMENT_EVENT_WING_ADVANCE = 2, //羽翼
    ACHIEVEMENT_EVENT_TREASURE_ADVANCE = 3, //法宝
    ACHIEVEMENT_EVENT_MOUNT_LEVELUP = 4, //坐骑
    ACHIEVEMENT_EVENT_ARTIFACT_ADVANCE = 5, //神兵
//修真 6
    ACHIEVEMENT_EVENT_XIUZHEN_LEVELUP = 6,
    ACHIEVEMENT_EVENT_OCCUPATION_LEVELUP = 7, //转职
//星辰 8
    ACHIEVEMENT_EVENT_GET_PET = 9, //宠物孵化
    ACHIEVEMENT_EVENT_PET_CALL = 10, //宠物上阵
    ACHIEVEMENT_EVENT_GET_PET_WITH_QUALITY = 11, //宠物品质
    ACHIEVEMENT_EVENT_PET_LV = 12, //宠物升级
    ACHIEVEMENT_EVENT_PET_LV_WITH_NUM = 13, //宠物进阶
    ACHIEVEMENT_EVENT_PET_STARLV = 14, //宠物升星
    ACHIEVEMENT_EVENT_EQUIP_DRESS_SUIT_WITH_150 = 150, //150（普通套装)  带星级装备：param参数1：橙色装备：5   红色装备：6   粉色装备：7
    ACHIEVEMENT_EVENT_EQUIP_DRESS_SUIT_WITH_151 = 151, //151 (普通套装)（param参数1：橙色装备：5   红色装备：6   粉色装备：7, param参数2：1星装备：1   2星：2   3星：3）
    ACHIEVEMENT_EVENT_EQUIP_DRESS_SUIT_WITH_152 = 152, //152 (仙器)  param参数1：橙色装备：5   红色装备：6   粉色装备：7
    ACHIEVEMENT_EVENT_EQUP_STREN_WITH160 = 160, //160（普通套装)  带星级装备：param参数1：
    ACHIEVEMENT_EVENT_EQUP_STREN_WITH161 = 161, //161 (仙器)  param参数1
    ACHIEVEMENT_EVENT_WASH_QUALITY = 17, //装备洗炼
    //18 装备升品
    //19 装备套装
    ACHIEVEMENT_EVENT_STONE_INLAY = 20, //宝石
    //21 暗器
    //22 软甲
    
};

enum XiuZhenRoadEventType
{
    XIUZHENROAD_EVENT_LEVELUP = 1,   //人物等级
    XIUZHENROAD_EVENT_OCCUPATION_LEVELUP = 2, //转职
    XIUZHENROAD_EVENT_EQUIP = 3, //穿戴装备
    XIUZHENROAD_EVENT_XIAN_EQUIP_STREN = 4, //仙器强化
    XIUZHENROAD_EVENT_EQUIP_STREN = 5, //装备强化
    XIUZHENROAD_EVENT_XIUZHEN_LEVELUP = 6, //仙阶
    XIUZHENROAD_EVENT_FANGREN_XIUZHEN_DUP = 7, //凡人修真
    XIUZHENROAD_EVENT_OPEN_PET_SLOT = 8, //开启XXX个宠物蛋孵化槽位
    XIUZHENROAD_EVENT_MOJINGSHANGDIAN_COST = 9, //魔镜商场累计花费XXX幻晶石
    XIUZHENROAD_EVENT_SHANGGUSHENGLING_ALL_LEVELUP = 10, //上古神灵XXX全身进阶至XXX阶
    XIUZHENROAD_EVENT_PET_STEPLV = 11, // 拥有xxx/xxx个进阶等级达到5阶的宠物
    XIUZHENROAD_EVENT_PET_QUALITY = 12,//拥有XXX个不低于XXX品质的宠物
    XIUZHENROAD_EVENT_PengLaiTanBao = 13, //蓬莱探宝XXX次
    XIUZHENROAD_EVENT_TongXinSuo = 14,//装备同心锁
    XIUZHENROAD_EVENT_QingLV_DUP = 15,//参与情侣副本XXX次
    XIUZHENROAD_EVENT_LIGHTSUOL_DRESS = 16,//装备XXX个XXX品质及以上的龙魂
    XIUZHENROAD_EVENT_STONE_DRESS = 17, //镶嵌XXX个XXX级及以上的宝石
    XIUZHENROAD_EVENT_TONGXINSUO_LEVELUP = 18,//同心锁达到XXX阶（XXX/XXX)
    XIUZHENROAD_EVENT_MARRY_XIANWA = 19,//拥有XXX个达到XXX阶的仙娃
    XIUZHENROAD_EVENT_PET_LEVELUP = 20,//拥有XXX个等级达到XXX级的宠物
    XIUZHENROAD_EVENT_SHENGMOJINGDI_DUP = 21,//进入神魔禁地XXX次
    XIUZHENROAD_EVENT_WASH_QUALITY = 22, //拥有XXX条XXX品质及以上品质的洗炼属性
    XIUZHENROAD_EVENT_EQUIP_DRESS_SUIT = 23,//激活诛魔套装XXX件套装效果（XXX/XXX)
    XIUZHENROAD_EVENT_LIGHTSUOL_ACTIVE_SLOT = 24,//激活XXX个龙魂核心孔
    XIUZHENROAD_EVENT_KILL_MANGHUANGSHENGSHOU_BOSS = 25,//击杀XXX只XXX阶及以上的蛮荒神兽BOSS
    XIUZHENROAD_EVENT_DEITY_BATTLE = 26,//出战XXX个天神
    XIUZHENROAD_EVENT_ACTIVE_SHENGSHOU = 27,//激活神兽-XXX（XXX/1)
    XIUZHENROAD_EVENT_GET_HUA_KUN = 28,//拥有XXX个等级达到XXX级的鲲
    XIUZHENROAD_EVENT_COST_SHENGWANG = 29,//声望商场累计花费XXX声望
    XIUZHENROAD_EVENT_GET_KUN_YUANSHENG = 30,//渡化XXX个XXX品质及以上的幼鲲元神
    XIUZHENROAD_EVENT_WING_LEVEL = 31,//羽翼等级达到XXX级
    XIUZHENROAD_EVENT_ACTIVE_DEITY_FANTASY = 32,//激活天神-XXX（XXX/1)
    XIUZHENROAD_EVENT_GET_KUN = 33,//拥有XXX个XXX品质及以上的鲲
    XIUZHENROAD_EVENT_GET_FANTASY_WING = 34,//拥有XXX个橙色羽翼幻装
    XIUZHENROAD_EVENT_BUY_DRAGONSOUL = 35,//元宝商店购买XXX个龙尾玉
    XIUZHENROAD_EVENT_BUY_BAGUA = 36,//元宝商店购买XXX个八卦命盘
    XIUZHENROAD_EVENT_DRESS_BAGUA = 37,//装备XXX个XXX品质及以上的八卦
    XIUZHENROAD_EVENT_GET_PET_SHANGWUXIANZI = 38,//获得宠物-扇舞仙子（XXX/1)
    XIUZHENROAD_EVENT_GET_FAQI_JIUFENGQINGLIANJIN = 39,//获得法器外观-九焚清莲镜（XXX/1)
    XIUZHENROAD_EVENT_STONE_LEVEL_SUM = 40,//宝石总等级达到XXX/XXXX级
    XIUZHENROAD_EVENT_DRESS_EQUIP_POS = 41,//穿戴指定部位装备
    XIUZHENROAD_EVENT_WELFARE_FIRSTCHARGE = 42,//完成指定首充活动 填写id，对应welfare-fristcharge表活动id
    XIUZHENROAD_EVENT_WELFARE_LOGIN = 43,//完成指定的登录活动 填写id，对应welfare-logon表活动id
    XIUZHENROAD_EVENT_SEND_FLOWER_TO_FRIEND = 44, //抚摸好友
    XIUZHENROAD_EVENT_KILL_BOSS_WORLD = 47, //击杀XXX只XXX阶及以上的世界BOSS
    XIUZHENROAD_EVENT_KILL_BOSS_HARMONY = 48, //击杀XXX只XXX阶及以上的鸿蒙BOSS
    XIUZHENROAD_EVENT_KILL_BOSS_SELF = 49, //击杀XXX只XXX阶及以上的专属BOSS
    XIUZHENROAD_EVENT_FACTION_CHAT = 50, //帮派频道发言
    XIUZHENROAD_EVENT_WORLD_CHAT = 51, //世界频道发言
    XIUZHENROAD_EVENT_BUY_DIALY_WELFARE_GIFT = 52, //购买指定id的礼包
    XIUZHENROAD_EVENT_MISSION_HUNT_TREASURE= 53, //使用藏宝图
    XIUZHENROAD_EVENT_MISSION_BOUNTY = 54, //赏金任务
    XIUZHENROAD_EVENT_QIFU = 55, //祈福
    XIUZHENROAD_EVENT_JOIN_PER_ACTIVITY = 56, //参与指定活动玩法id
    XIUZHENROAD_EVENT_JOIN_DAILY_ACTIVITY = 57, //参与指定日常的id
    XIUZHENROAD_EVENT_FACTION_JUANXIAN = 59, //完成帮派捐献xxx次
    XIUZHENROAD_EVENT_BOSS_ASSIST = 60, //完成boss协助xxx次
    XIUZHENROAD_EVENT_1V1_REWARD = 61, //领取1v1宝箱
    XIUZHENROAD_EVENT_3v3_REWARD = 62, //领取3v3宝箱
    XIUZHENROAD_EVENT_FACTION_DATI = 64, //参与帮派答题
    
    XIUZHENROAD_EVENT_FIRST_LOGIN = 66, //当日首次登陆
    XIUZHENROAD_EVENT_ACTIVE_EXP = 67, //当日日常活跃度
    XIUZHENROAD_EVENT_ONLINE_TIME = 68, //当日在线时间
    XIUZHENROAD_EVENT_MARRY = 69,       //完成一次结缘或已经结缘
    XIUZHENROAD_EVENT_GIVE_ITEM = 70,   //赠送花
    XIUZHENROAD_EVENT_EXPRESS = 71,     //赠送指定id表白道具
    XIUZHENROAD_EVENT_FINISH_MAIN_TASK = 72,     //完成特定的主线任务
    XIUZHENROAD_EVENT_FINISH_DUP = 73,     //通关指定的副本xxx次
    XIUZHENROAD_EVENT_FINISH_KIND_YONGJIUSHOUHU = 74,     //穿戴X种永久守护
    XIUZHENROAD_EVENT_FINISH_SHOP_BUY = 75,     //购买
    XIUZHENROAD_EVENT_FINISH_SHANGGUSHENGLING_LEVELUP = 76,     //上古神灵进阶X次
    XIUZHENROAD_EVENT_FINISH_FIGHT_VALUE = 77,     //角色战力达到X
    XIUZHENROAD_EVENT_OWNER_LONG_SOUL_NUM = 78,     //拥有X个龙魂
    XIUZHENROAD_EVENT_SHENGLING_SHENGGE = 79,       //神灵任意X个神格达到X阶
    XIUZHENROAD_EVENT_COLECT_NUM = 80, //采集X次
};

class AchievementDescEx : public NFShmObjGlobalTemplate<AchievementDescEx, EOT_CONST_ACHIEVEMENT_DESC_EX_ID, NFIDescStoreEx>
{
public:
	AchievementDescEx();
	virtual ~AchievementDescEx();
	int CreateInit();
	int ResumeInit();
public:
    virtual int Load() override;
    virtual int CheckWhenAllDataLoaded() override;
};

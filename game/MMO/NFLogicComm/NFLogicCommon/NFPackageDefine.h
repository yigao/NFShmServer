// -------------------------------------------------------------------------
//    @FileName         :    NFPackageDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageDefine
//
// -------------------------------------------------------------------------

#pragma once

//背包最大堆叠数
//#define PACKAGE_MAX_PILE_NUM 99
//背包栏初始格子数
#define COMMON_PACKAGE_INIT_GRID_NUM 100
//背包栏最大格子数(不要随便改动)
#define COMMON_PACKAGE_MAX_GRID_NUM 400
//仓库初始格子数
#define STORAGE_PACKAGE_INIT_GRID_NUM 100
//宠物初始格子数
#define MOUNT_PACKAGE_INIT_GRID_NUM 100
//仓库最大格子数
#define STORAGE_PACKAGE_MAX_GRID_NUM 400
//宠物最大格子数
#define MOUNT_PACKAGE_MAX_GRID_NUM 100
//神饰最大格子数
#define DEITY_EQUP_PACKAGE_INIT_GRID_NUM 100
//神饰最大格子数
#define DEITY_EQUIP_PACKAGE_MAX_GRID_NUM 200
//藏经阁图鉴最大格子数
#define HANDBOOK_PACKAGE_INIT_GRID_NUM 300
//藏经阁图鉴最大格子数
#define HANDBOOK_PACKAGE_MAX_GRID_NUM 300
//神兽最大格子数
#define BEAST_EQUP_PACKAGE_INIT_GRID_NUM 100
//神兽最大格子数
#define BEAST_EQUIP_PACKAGE_MAX_GRID_NUM 100
//龙魂最大格子数
#define LONG_HUN_PACKAGE_INIT_GRID_NUM 100
//龙魂最大格子数
#define LONG_HUN_PACKAGE_MAX_GRID_NUM 100
//不灭星辰4最大格子数
#define STAR_HUN_PACKAGE_MAX_GRID_NUM 100
//其它类型背包初始格子数量
#define OTHER_PACKAGE_INIT_GRID_NUM 300
//其它类型背包格子最大数量
#define OTHER_PACKAGE_MAX_GRID_NUM 300
//神格背包格子最大数量
#define SOUL_PACKAGE_MAX_GRID_NUM 500
//纹章背包格子最大数量
#define STAR_PACKAGE_MAX_GRID_NUM 500
//领域背包格子最大数量
#define FAIMATERI_PACKAGE_MAX_GRID_NUM 500
//每次扩展格子数
#define PACKAGE_EXPAND_GRID_NUM 5
//打造者名字长度
#define MAX_EQUIP_MAKER_NAME_LEN 35
//装备镶嵌孔最大数量
#define MAX_EQUIP_HOLE_NUM 6
//装备合成时 记录消耗装备的最大数量
#define MAX_COMPOSE_COST_EQUIP_NUM 5
//一次保存背包物品数
#define UNIT_SAVE_BAG_ITEM_SIZE  200
//神体装备最大800个
#define TURN_PACKAGE_MAX_GRID_NUM 800
//最大宝石槽位数
#define MAX_STONE_SLOT 5
//洗练最大槽位数
#define MAX_WASH_SLOT 4

//通用背包大小
#define COM_BAG_SIZE 200
//蛋背包大小
#define EGG_BAG_SIZE 100

//坐骑化鲲
#define MOUNT_KUN_PACKAGE_MAX_GRID_NUM 800

enum EBindState
{
    EBindState_no = 0,		//未绑定
    EBindState_bind = 1,	//绑定
    EBindState_all = 2,		//所有（包括绑定，未绑定，只是为了背包那边查找接口参数用的）
};

//堆叠状态
enum class EStackState
{
    EStackState_no = 0,		//不可堆叠
    EStackState_yes = 1,	//可堆叠
};
//cd类型
enum class ECdType
{
    ECdType_none,
    ECdType_nocd = 1,			//没有冷却
    ECdType_independent = 2,	//独立冷却
    ECdType_common = 3,			//公共冷却
    ECdType_limit,
};

//物品是否可使用的类型
enum class EItemCanUseType
{
    EItemCanUseType_NoUse = 0,	//不能使用
    EItemCanUseType_CanUse = 1,	//可使用
    EItemCanUseType_SysUse = 2, //系统使用
};

//装备绑定类型
enum class EEquipBindType
{
    EEquipBindType_none = 0,
    EEquipBindType_get = 1,			//获取绑定
    EEquipBindType_dress = 2,		//穿戴绑定
    EEquipBindType_limit,
};


//装备类型
enum EEquipFromType
{
    EEquipFromType_None = 0,
    EEquipFromType_Bag = 1,			//背包装备
    EEquipFromType_Dress = 2,		//穿戴装备
};


//时装类型
enum EEquipFashionType
{
    EEquipFashionType_None = 0,
    EEquipFashionType_Weapon = 1,			//时装武器
    EEquipFashionType_Clothes = 2,			//时装衣服
    EEquipFashionType_Limit,
};

//物品绑定途径（适用于物品和装备）
enum EItemBindWay
{
    EItemBindWay_None = -1,
    EItemBindWay_UnBind = 0,	//非绑定
    EItemBindWay_Get = 1,		//获取绑定（获取之前非绑定）
    EItemBindWay_Bind = 2,		//永久绑定
    EItemBindWay_Dress = 3,		//穿戴绑定（获取之前非绑定）
    EItemBindWay_Limit,
};

//物品禁止类型
enum EItemForbidType
{
    EItemForbidType_None = -1,
    EItemForbidType_Follow = 0, //跟随绑定规则
    EItemForbidType_Forbid = 1,	//禁止
    EItemForbidType_Limit,
};

//物品使用之后广播特效，特效类型
enum EItemUseEffectType
{
    EItemUseEffectType_Server = 1,	//全服
    EItemUseEffectType_Scene = 2,	//场景
};


/*物品功能类型对应的参数
0，无功能
1，使用修改属性、货币数值（加属性上限的物品、金币袋、军功勋章）
30，内挂卡
38, 虚拟物品
*/
//物品功能类型
enum EItemFuncType
{
    EItemFuncType_None					= -1,
    EItemFuncType_NoFunc				= 0,			//0，无功能
    EItemFuncType_ModifyAttr			= 1,			//1，使用修改属性、货币数值（血瓶、加属性上限的物品、金币袋、军功勋章）
    EItemFuncType_AddDupGroupNum		= 2,			//2，添加副本次数
    EItemFuncType_AddBossNum			= 3,			//2，添加Boss次数(boss副本不要填)
    EItemFuncType_Stone					= 6,			//6, 宝石
    EItemFuncType_AddAttrForever		= 7,			//7,使用物品增加属性
    EItemFuncType_Box					= 9,			//9，包物品（可以开出其他物品的物品）
    EItemFuncType_SelectBox				= 10,			//10，自选宝箱
    EItemFuncType_Fashion				= 21,			//21，使用时装
    EItemFuncType_HangCard				= 30,			//30，内挂卡,functionType=30 有效时间（填写小时，永久填写-1）
    EItemFuncType_addSkill				= 35,			//35,添加技能
    EItemFuncType_Virtual				= 38,			//38,虚拟物品(资源)
    EItemFuncType_dynExp				= 39,			//39,动态经验类
    EItemFuncType_AddDyMission          = 52,           //34, 添加一个动态任务
    EItemFuncType_ActiveVip				= 54,			//激活vip
    EItemFuncType_AddVipExp				= 55,			//添加vip经验卡
    EItemFuncType_AddHuaKun				= 56,           //56,使用物品，获得鲲
    EItemFuncType_AddRoleExp			= 57,			//57添加固定经验
    EItemFuncType_AddRoleRaceExp		= 58,			//58添加百分比经验
    EItemFuncType_Limit,
};


/*
有特殊使用要求的物品
特殊要求类型，类型值
1，指定场景
2，指定区域
3，指定目标
*/
//物品其他参数类型
enum class EItemOtherParamType
{
    EItemOtherParamType_None,
    EItemOtherParamType_NoType = 0,
    EItemOtherParamType_Scene = 1,
    EItemOtherParamType_Area = 2,
    EItemOtherParamType_Target = 3,
    EItemOtherParamType_Limit,
};


//物品作用目标 1，自身角色；2，无目标；3，其他玩家角色；4，怪物；5，NPC；6，任意目标
enum class EItemTarge
{
    EItemTarge_SelfPlayer = 1,			//1，自身角色
    EItemTarge_NoTarge = 2,				//2，无目标
    EItemTarge_OtherPlayer = 3,			//3，其他玩家角色
    EItemTarge_Monster = 4,				//4，怪物
    EItemTarge_Npc = 5,					//5，NPC
    EItemTarge_RandTarget = 6,			//6，任意目标
};


//作用目标和自身关系 1，不限；2，敌对；3，友好
enum class EItemRelation
{
    EItemRelation_NoLimit = 1,		//1，不限
    EItemRelation_Enemy = 2,		//2，敌对
    EItemRelation_Friend = 3,		//3，友好
};


enum EEquipType
{
    EEquipType_none = 0,		//无
    EEquipType_nomal = 1,		//普通装备
    EEquipType_xq = 2,			//仙器
    EEquipType_deity = 3,       //天神
};

enum EEquipTotalType
{
    EEquipTotalType_normal_strong = 1,	//普通装备强化总等级
    EEquipTotalType_xq_strong = 2,		//仙气装备强化总等级
    EEquipTotalType_stone = 3,			//宝石镶嵌总等级
    EEquipTotalType_star = 4,			//装备总星级
};

/*
	境界材料（subType=1）
	转职材料（subType=2）
	暂时未分配类型（subType=3）
	宝石精炼类（subType=4）
	男套装石类（subType=5）
	女套装石类（subType=6）
	高级套装石（subType=7）
	仙器套装石（subType=8）
	洗炼类（subType=9）
	觉醒类（subType=10）
	附魔类（subType=11）
	伙伴进阶类（subType=12）
	伙伴灵丹类（subType=13）
	法宝进阶类（subType=14）
	伙伴法灵类（subType=15）
	神器进阶类（subType=16）
	神器器灵类（subType=17）
	翅膀进阶类（subType=18）
	翅膀羽灵类（subType=19）
	戒指养成材料（subType=20）
	宝宝养成材料（subType=21）
	时装武器，分职业（subType=22）
	时装衣服，分男女（subType=23）
	神兵，分职业（subType=24）
	伙伴幻化外形（subType=25）
	坐骑外形（subType=26）
	法宝幻化外形（subType=27）
	翅膀外形（subType=28）
	宝宝幻化外形（subType=29）
	仙阵扩展卡（subType=30）
	小蝙蝠、小凤仙（subType=31）
	经验卡（subType=32）
	扫荡券（subType=33）
	经验丹（subType=34）
	经验加成道具（subType=35）
	活动兑换道具（subType=36）
	Boss图鉴（subType=37）
	仙阵图鉴（subType=38）
	攻击宝石类型（subType=39）
	生命宝石类型（subType=40）
	数值类（subType=99）
*/
//物品子类型
enum class EItemSubType
{
    EItemSubType_none,
    EItemSubType_RealmMaterial		= 1,	//境界材料
    EItemSubType_TransferMaterial	= 2,	//转职材料
    EItemSubType_StoneRefine		= 4,	//宝石精炼类
    EItemSubType_ManSuitStone		= 5,	//男套装石
    EItemSubType_FemaleSuitStone	= 6,	//女套装石
    EItemSubType_AdvSuitStone		= 7,	//高级套装石
    EItemSubType_FaiSuitStone		= 8,	//仙器套装石
    EItemSubType_Wash				= 9,	//洗练类
    EItemSubType_Wake				= 10,	//觉醒类
    EItemSubType_Enchant			= 11,	//附魔类
    EItemSubType_PartnerAdv			= 12,	//伙伴进阶
    EItemSubType_PartnerPil			= 13,	//伙伴灵丹
    EItemSubType_MagWeaponAdv		= 14,	//法宝进阶类
    EItemSubType_PartnerSpirit		= 15,	//伙伴法灵
    EItemSubType_ArtifactAdv		= 16,	//神器进阶
    EItemSubType_ArtifactSpirit		= 17,	//神器器灵
    EItemSubType_WingAdv			= 18,	//翅膀进阶类
    EItemSubType_WingSpirit			= 19,	//翅膀羽灵类
    EItemSubType_RingMaterial		= 20,	//戒指养成材料
    EItemSubType_BabyMaterial		= 21,	//宝宝养成材料
    
    EItemSubType_FashWeaponProf		= 22,	//时装武器，分职业
    EItemSubType_FashWeaponSex		= 23,	//时装武器，分性别
    EItemSubType_MagArms			= 24,	//神兵，分职业
    EItemSubType_PartnerFatastic	= 25,	//伙伴幻化
    
    EItemSubType_HorseFace			= 26,	//坐骑外形
    EItemSubType_MagWeaponFace		= 27,	//法宝幻化外形
    EItemSubType_WingFace			= 28,	//翅膀外形
    EItemSubType_BabyFace			= 29,	//宝宝幻化外形
    
    EItemSubType_FaiExpandCard		= 30,	//仙阵扩展卡
    
    EItemSubType_SmallBat			= 31,	//小蝙蝠
    EItemSubType_ExpCard			= 32,	//经验卡
    EItemSubType_SweepTicket		= 33,	//扫荡券
    EItemSubType_ExpPil				= 34,	//经验丹
    EItemSubType_AddExpItem			= 35,	//经验加成道具
    EItemSubType_ActExchange		= 36,	//活动兑换道具
    EItemSubType_BossBook			= 37,	//BOSS图鉴
    EItemSubType_FaiBook			= 38,	//仙阵图鉴
    EItemSubType_AtkStone			= 39,	//攻击宝石
    EItemSubType_HpStone			= 40,	//生命宝石
    EItemSubType_Blue_FieldCylstal  = 53,	//领域蓝水晶
    EItemSubType_Green_FieldCylstal  = 54,	//领域绿水晶
    
    EItemSubType_limit,
};

//合成中货币类型
enum EComposeCurrency
{
    EComposeCurrency_gold = 1,			//金币
    EComposeCurrency_small_spirit = 2,	//小灵魄货币
    EComposeCurrency_big_spirit = 3,	//大灵魄货币
    EComposeCurrency_star = 4,			//命星货币
    EComposeCurrency_binddia = 5,		//绑钻
    EComposeCurrency_dia = 6,			//钻石
    EComposeCurrency_holydia = 11,		//神钻货币
};


struct SItem
{
    uint64_t nItemID;
    int64_t nNum;			//物品数量，这里用 int64_t 类型主要为了兼容 虚拟物品的数量(金币，钻石等)
    int8_t byBind;
    SItem() :nItemID(0), nNum(0), byBind((int8_t)EBindState::EBindState_no){}
    SItem(uint64_t itemId, int64_t num, int8_t bind = (int8_t)EBindState::EBindState_no) :nItemID(itemId), nNum(num), byBind(bind) {}
};

//物品列表
using LIST_ITEM = list<SItem>;
//itemid - SItem
using MAP_UINT64_ITEM = unordered_map<uint64_t, SItem>;
//
using MAP_UINT32_MAP_UINT64_ITEM = unordered_map<uint32_t, MAP_UINT64_ITEM > ;

enum EItemOpetateType
{
    EItemOpetateType_None = 1,
    EItemOpetateType_Add,			//增加
    EItemOpetateType_Del,			//减少
    EItemOpetateType_Use,			//使用
};

//物品初始化属性类型
enum class EInitAttrType
{
    None = 0,
    Common = 1, //通用的属性初始化
    Limit,
};

//生成物品条件
struct SItemCond
{
    EInitAttrType inittype = EInitAttrType::Common;			//物品初始化属性类型
    int32_t level = 1;										//等级(玩家等级)
    int32_t prof = 0;										//职业
    //
    string makeName;										//打造者名字(神魔装备初始化)
    uint64_t makeTime = 0;									//打造时间(神魔装备初始化)
    
    //有其他条件可以往后面增加
};


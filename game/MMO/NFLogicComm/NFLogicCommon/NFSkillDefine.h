// -------------------------------------------------------------------------
//    @FileName         :    NFSkillDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-2-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFGameCommon/NFComTypeDefine.h"

#pragma pack(push)
#pragma pack(1)

//宠物技能位置最大编号
const uint32_t MAX_PET_SKILL_POS = 4;
//战魂技能位置最大编号
const uint32_t MAX_SPIRIT_SKILL_POS = 3;
//角色技能最大编号
const uint32_t MAX_ROLE_SKILL_POS = 10;
//角色职业技能进阶最大位置
const uint32_t MAX_ROLE_SKILL_ADVANCE_POS = 3;
//怒气技能位置最大编号
const uint32_t MAX_ANGER_SKILL_POS = 2;

//技能解锁类型
enum class ESkillUnlock
{
    none,
    level = 1,			//等级
    trans = 2,			//转职
    task = 3,			//任务
    advance = 4,		//技能是否已进阶
    limit,
};

//技能类型
enum class ESkillType
{
    none = 0,			//无
    normal = 1,			//普攻
    skill = 2,			//技能
    magweapon = 3,		//法宝技能
    cape = 4,			//披风技能
    limit,
};
//技能目标类型
enum class ESkillTarget
{
    none,
    EnemyDam = 1,		//敌方伤害
    Friend = 2,			//主动已方非死亡
    FriendLove = 3,		//主动已方情吕
    FriendMaster = 4,	//主动已方主人
    Passive = 5,		//被动技能
    FriendNoSelf = 6,	//主动已方非死亡(不包括自己)
    limit,
};
//技能伤害类型
enum class ESkillDam
{
    none = 0,		//无
    physics = 1,	//物理伤害
    limit,
};

//技能过程类型
enum class ESkillProcess
{
    none,
    normal = 1,					//普通技能
    fly_lock = 2,				//飞行（有目标的飞行，锁定目标的飞行）
    fly = 3,					//飞行，无目标的飞行
    bullet = 4,					//子弹穿透
    flash = 5,					//闪烁,生物先闪到目标点造成圆形伤害，紧接着残影从起始点移动到目标点，造成矩形伤害(多伤害范围类型)
    assault = 6,				//冲锋,生物先冲锋到目标点造成矩形伤害，到目的地后跳斩劈地造成范围伤害(多伤害范围类型)
    grab = 7,					//抓取，把附近的敌人抓取到自己身前
    fly_muti = 8,				//飞行，按照目标点 不锁定目标的飞行 分段释放，每一段都是一个独立的技能释放流程，每一段都段都单独计算伤害,只能搭配范围类型12和8
    limit,
};

//技能范围类型
enum class ESkillRange
{
    none,
    target = 1,				//选中对象 目标角色【空】
    target_circle = 2,		//选中对象 目标角色为圆心的圆形效果【半径】（范围内的其他目标不锁定）
    mine = 3,				//不选对象 自身【空】
    mine_rect = 4,			//不选对象 直线通道效果【通道长度, 通道宽度】
    mine_sector = 5,		//不选对象 自身圆心扇形效果【半径, 扇形角度（角度待定）】（实际角度需要乘以1000填写）
    mine_circle = 6,		//不选对象 自身圆心圆形效果 【半径】
    target_circle_lock = 7,	//选中对象 目标角色为圆心的圆形范围【半径】，锁定该区域内所有敌方目标，无目标不能释放该技能（范围内的其他目标锁定）
    target_pos = 8,			//选定目标点（圆形范围），参数半径
    bullet_rect = 9,		//不选对象，以子弹为范围的直线通道，【通道长度,通道宽度】
    target_var_rect = 10,	//选中定目标点 直线通道效果【通道宽度】，长度可变，长度是角色起点到目标点的距离，用于闪烁技能
    target_self_sector = 11,//11=选中对象，自身圆心扇形效果【半径,扇形角度（角度1-180）】（半径、实际角度需要乘以1000填写），抓取技能需要锁定目标
    angle_rect = 12,		//不选对象，直线通道通道效果，【通道长度,通道宽度，通道数量】,每个通道间隔的角度=360/通道数量
    limit,
};
//技能产生的buff目标类型
enum class ESkillBuffTarget
{
    enemy = 0,		//敌人
    self = 1,		//自己
    owner = 2,		//主人
    allteam = 3,	//队友(包括自己)
    team = 4,		//队友(不包括自己)
    allfaction = 5,	//帮派(包括自己)
    faction = 6,	//帮派(不包括自己)
    allfriend = 7,  //友方(包括自己)
    friendnoself = 8,//友方(不包括自己)
};

//技能组类型
enum class ESkillGroup
{
    male_master			= 101,	//男法师技能
    female_master		= 102,	//女法师技能
    male_sickle			= 103,	//男镰刀技能
    female_sickle		= 104,	//女镰刀技能
    male_sword			= 105,	//男剑客技能
    female_sword		= 106,	//女剑客技能
    male_knife			= 107,	//男太刀技能
    female_knife		= 108,	//女太刀技能
    
    god					= 201,	//天神技能组
    pet					= 301,	//宠物技能组
    spirit				= 401,	//战魂技能组
    anger				= 501,	//怒气技能组
};


//技能进阶类型
enum class ESkillAdvance
{
    none = 0,
    fire = 1,        //火
    thunder = 2,    //雷
    ice = 3,        //冰
    limit,
};

//查找技能目标的参数
struct SearchSkillTargetParam
{
    uint32_t priority_count = 0;
    uint32_t total_count = 0;
};

#pragma pack(pop)

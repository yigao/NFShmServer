// -------------------------------------------------------------------------
//    @FileName         :    NFEventDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFEventDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

enum NF_EVENT_ID
{
    NF_EVENT_CREATE_SCENE_EVENT = 100,
};


enum EventId
{
    EVENT_NONE = 0,
    ///////////////////////视野事件//////////////////////////
    EVENT_BEEN_SEE,						//被别人看见
    EVENT_MONSTER_BEEN_FIRST_PLAYER_SEE, //怪物被第一个玩家进入视野的玩家看见
    EVENT_MONSTER_NO_PLAYER_SEE, //没有人看见怪物
    EVENT_SCENE_FIRST_PLAYER, //第一个进入场景的玩家
    EVENT_SCENE_NO_PLAYER, //最后玩家离开场景

    ///////////////////////战斗事件//////////////////////////
    EVENT_UNDER_ATTACK,					//被人攻击
    EVENT_ATTACK_SOMEBODY,				//攻击别人
    EVENT_USE_SKILL,					//使用技能事件


    ///////////////////////技能事件//////////////////////////
    EVENT_USE_SKILL_ATTACK,				//玩家使用技能，并且达到了人，使用一次技能，只发送一次事件
    EVENT_BUFF_START_TYPE,				//BUFF生效条件
    EVENT_BUFF_END_TYPE,				//BUFF结束条件
    EVENT_BUFF_START_BUFF,				//开始一个BUFF
    EVENT_BUFF_DODGE,					//技能闪避事件
    EVENT_BUFF_CRIT,					//技能暴击事件

    ///////////////////////角色相关事件//////////////////////
    EVENT_CREATURE_DEAD,				//生物死亡
    EVENT_CREATURE_REVIVE,				//生物复活
    EVENT_LOGIN_GAME,					//登入游戏
    EVENT_LOGOUT_GAME,					//登出游戏
    EVENT_START_MOVE,					//开始移动
    EVENT_END_MOVE,						//停止移动
    EVENT_TELEPORT_MOVE,				//瞬间移动
    EVENT_DISCONNECT,					//断开连接
    EVENT_LEVELUP,						//升级
    EVENT_FACADE_CHANGE,				//外观改变
    EVENT_CALC_FIGHT_POWER,				//通知计算战斗力事件，在计算战斗力条件改变的时候，触发
    EVENT_ADD_TITLE,					//获得称号			titileId
    EVENT_SKILL_UP,						//升级角色技能		skillLevel
    EVENT_RECHARGE,						//充值钻石			num
    EVENT_VIP_UP,						//vip等级提升		vipLevel
    EVENT_LEAVE_TEAM,					//离开队伍
    EVENT_JOIN_TEAM,					//加入队伍
    EVENT_DISMISS_TEAM,					//解散队伍
    EVENT_RECONNECT_SUCCEED,			//重连成功
    EVENT_PAY,                          //玩家充值
    EVENT_INVISIBLE_STATE,				//玩家隐身
    ////////////////////////场景相关事件//////////////////////////
    EVENT_CREATE_SCENE,					//创建场景
    EVENT_LEAVE_SCENE,					//离开场景
    EVENT_ENTER_SCENE,					//进入场景
    EVENT_TRANS_CHECK_RES,				//传送校验结果（通知源逻辑节点，跨逻辑节点传送之校验结果）
    EVENT_TRANS_PREPARE,				//准备传送（跨逻辑节点传送 校验完了之后，准备传送）
    EVENT_TRANS_SUCCESS,				//传送成功（跨逻辑节点传送 目标逻辑节点成功收到传送参数信息）
    EVENT_CHANGE_SCENE,					//生物场景改变

    ////////////////////////任务事件/////////////////////////
    EVENT_ACCEPT_TASK,					//接取任务
    EVENT_FINISH_TASK,					//完成任务
    //////////////////////////////////////////////////////////////////////////

    ////////////////////////副本事件///////////////////////////
    EVENT_PASS_DUPLICATE,				//通关副本
    EVENT_ENTER_DUPLICATE,				//进入副本
    EVENT_INSPIRE_DUPLICATE,			//副本鼓舞
    EVENT_SWEEP_DUPLICATE,				//扫荡副本

    ////////////////////////物品装备事件////////////////////////
    EVENT_EQUP_STREN,					//装备强化
    EVENT_ITEM_CHANGE,					//物品改变
    EVENT_ITEM_USE,						//使用物品
    EVENT_PICK_ITEM,					//拾取事件
    EVENT_EQUIP_REFINE,					//装备精炼
    EVENT_STONE_INLAY,					//镶嵌宝石
    EVENT_EQUIP_DRESS,					//装备穿戴
    EVENT_MATERIAL_COMPOSE,				//材料合成
    EVENT_MATERIAL_COMPOSE_FAIL,		//材料合成失败
    ////////////////////////好友事件//////////////////////////////
    EVENT_ADD_FRIEND,					//添加好友事件   2019.6.27 修改

    ////////////////////////成就事件//////////////////////////////
    EVENT_FINISH_ACHIVEMENT,			//领取成就
    EVENT_ADD_ACHIVEMENT_PROGRESS,      //成就进度增加

    ///////////////////////竞技场事件/////////////////////////////
    EVENT_ARENA_LEVEL_UP,				//竞技场排名提升
    EVENT_ARENA_RESULT,					//挑战竞技场		胜负、层数、是否连续7天位于竞技场第2的位置上(尼玛)
    EVENT_ARENA_JOIN,					//参加竞技场事件
    EVENT_ARENA_SCORE_CHANGE,			//积分改变

    ///////////////////////活动相关////////////////////////////////
    EVENT_ACTIVIST_CHANGE,					//活跃度改变
    ///////////////////////聊天事件////////////////////////////////
    EVENT_CHAT,							//聊天				channel、是否发送坐标

    ///////////////////////帮派事件////////////////////////////////
    EVENT_GUILD_CHANGE,					//工会改变
    EVENT_DISMISS_UNION,				//工会解散


    //位面事件
    EVENT_PLANE_OPEN,					//开启位面
    EVENT_PLANE_CLOSE,					//关闭位面
    EVENT_PLANE_LEAVE,					//离开位面

    EVENT_FUNCTIONUNLOCK,				//功能解锁

    EVENT_ACTIVITY_READY,				// 活动开放事件
    EVENT_ACTIVITY_START,				// 活动开放事件
    EVENT_ACTIVITY_END,					// 活动结束事件
    EVENT_ACTIVITY_ENTER,				// 进入活动事件
    EVENT_ACTIVITY_LEAVE,				// 离开活动事件
    EVENT_ACTIVITY_COMPLETE,			// 玩家完成活动事件
    EVENT_SIGN_IN,						// 签到
    EVENT_EQUIP_SUIT,					// 装备锻造


    EVENT_EQUIP_UNDRESS,				//装备卸装

    EVENT_GROW_PART_ACTIVE,					//养成激活事件
    EVENT_GROW_PART_LVUP,					//养成升级事件
    EVENT_GROW_PART_DRESS,					//穿戴外观部件

    EVENT_WING_FIGHT_CHANGE,			//翅膀战力改变事件
    EVENT_TREASURE_FIGHT_CHANGE,        //宝具战力改变事件
    EVENT_PARTNER_FIGHT_CHANGE,			//伙伴战力改变事件
    EVENT_ARTIFACT_FIGHT_CHANGE,        //神器战力改变事件

    EVENT_WING_FANTASY,					//翅膀幻化事件
    EVENT_TREASURE_FANTASY,				//宝具幻化事件
    EVENT_ARTIFACT_FANTASY,				//神器幻化事件
    EVENT_PARTNER_FANTASY,				//幻伙伴化事件

    EVENT_WING_ADVANCE,                 //翅膀升级事件
    EVENT_TREASURE_ADVANCE,             //宝具升级事件
    EVENT_ARTIFACT_ADVANCE,             //神器升级事件
    EVENT_PARTNER_ADVANCE,              //幻伙升级事件
    EVENT_KILL_BOSS,					//击杀BOSS事件
    EVENT_DAILY_BACK,				    //每日找回事件
    EVENT_CONVOY_ESCORT,				//护送镖车事件
    EVENT_CONVOY_ESCORT_CMPT,			//护送镖车事件
    EVENT_CONVOY_ACCEPT,
    EVENT_MOUNT_FIGHT_CHANGE,          //坐骑战力改变事件
    //坐骑事件
    EVENT_HORSE_ACTIVE,					//激活坐骑
    EVENT_HORSE_LEVELUP,				//坐骑升级
    EVENT_GET_PET,                      //获得一个宠物
    EVENT_PET_STEPLV,                   //宠物进阶升级
    EVENT_PET_LV,                       //宠物升级
    EVENT_PET_STARLV,                   //宠物升星
    EVENT_ID_LIMIT = 255,				//事件ID最大值


};



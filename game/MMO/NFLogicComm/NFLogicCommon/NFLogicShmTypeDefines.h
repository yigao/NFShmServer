// -------------------------------------------------------------------------
//    @FileName         :    NFServerFrameTypeDefines.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTypeDefines.h"

enum PartType
{
    PART_NONE = 0,
    PART_VIP,				//VIP (VIP里面有权限,权限不存数据库，各模块加载要再次添加权限。所以放在前面)
    PART_MOVE,				//移动
    PART_FUNCTIONUNLOCK,	//功能解锁
    PART_PACKAGE,			//背包
    PART_GROW,				//养成
    PART_MINI,				//杂项模块
    PART_CHAT,				//聊天
    PART_EQUIP,				//装备模块
    PART_SKILL,				//技能
    PART_BUFF,				//buff
    PART_FACADE,            //外观
    PART_DUP,				//副本
    PART_MINI_ACTIVITY,     //杂项活动
    PART_BOSS,				//boss
    PART_MISSION,			//任务
    PART_MOUNT,             //坐骑
    PART_MALL,				//商城
    PART_DEITY,            //天神
    PART_PET,			   //宠物
    PART_CONVOY,		   //护送
    PART_ARMOR,			   //玄功真甲
    PART_TITLE,            //title
    PART_ASSIST,		   //Boss助战
    PART_GODEVIL,		   //神魔
    PART_OCCUPATION,        //转职
    PART_PAY,			   //充值
    PART_FACTION,		   //帮派
    PART_PracticeTrue,		//修真
    PART_BESTEQ,		   //神机装备
    PART_COLLECT,		   //采集
    PART_ACHIEVEMENT,      //成就系统
    PART_PVP,			   //PVP
    PART_ANCIENT,		   //上古神灵
    PART_ENCYLOPEDIA,      //藏经阁
    PART_MARRY,			   //结婚
    PART_GVBPData,			//神谷战场
    PART_RANK,              //排行榜
    PART_PersonalShop,     //个人商店
    PART_DRAGONSOUL,        //龙魂
    PART_WELFARE,           //福利
    PART_DAILYWELFARE,      //每日特惠
    PART_GIFT,				//礼包
    PART_FINDTREASURE,      //真龙寻宝
    PART_FEST,				//节日活动
    PART_DRAGON,			//幻世烛龙
    PART_STAR,              //灭星辰
    PART_GMA,				//神元区域
    PART_TURN,				//神体
    PART_MAX,
};

enum BattlePartType
{
    BATTLE_PART_NONE = 0,
    BATTLE_PART_MOVE,
    BATTLE_PART_MAX,
};

enum SnsPartType
{
    SNS_PART_NONE = 0,
    SNS_PART_RELATION,
    SNS_PART_MAX,
};

typedef enum
{
	EOT_SF_BEGIN_ID = EOT_SERVER_FRAME_BEGIN_ID,
    ////////////////////////////server common////////////////////////////////////////////////
    EOT_SERVER_COMMON_ATTR_MGR_ID,
    EOT_SERVER_COMMON_COMFIGHT_ATTR_ID,
    EOT_SERVER_COMMON_ROLEFIGHT_ATTR_ID,
    EOT_SERVER_COMMON_COM_ATTR_ID,
    EOT_SERVER_COMMON_ROLE_ATTR_ID,
    ////////////////////////////server common////////////////////////////////////////////////

	////////////////////////////sns server/////////////////////////////
    EOT_SNS_ROLE_SIMPLE_ID,
    EOT_SNS_ROLE_DETAIL_ID,
    EOT_PLAYER_ONLINE_ID,
    EOT_SNS_CACHE_MGR_ID,
    EOT_SNS_LOAD_CACHE_MGR_ID,
    ////////////////////////////sns trans server/////////////////////////////
    EOT_SNS_TRANS_CACHE_BASE_ID,
    EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID,
    EOT_SNS_TRANS_GET_ROLE_DETAIL_ID,
    EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE,
    EOT_SNS_TRANS_SAVE_PLAYER_DETAIL,
    ////////////////////////////sns part server/////////////////////////////
    EOT_SNS_PART_ID,
    EOT_SNS_MAX_ID = EOT_SNS_PART_ID+SNS_PART_MAX,
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////

    //////////////////////////logic part////////////////////////
    EOT_LOGIC_PART_ID,
    EOT_LOGIC_PART_MAX_ID=EOT_LOGIC_PART_ID+PART_MAX,
    //////////////////////////logic trans////////////////////////
    EOT_TRANS_LOGIC_USER_BASE,
    EOT_TRANS_SAVE_PLAYER,
	////////////////////////////logic server/////////////////////////////
    EOT_LOGIC_PLAYER_MGR_ID,
    EOT_LOGIC_PLAYER_ID,
	////////////////////////////login server/////////////////////////////
    EOT_ACCOUNTLOGIN_HASHTABLE_ID,
	////////////////////////////login server/////////////////////////////
	////////////////////////////world server/////////////////////////////
    EOT_WORLD_ACCOUNT_MGR_ID,
    EOT_WORLD_ACCOUNT_ID,
    EOT_WORLD_SESSION_ID,
    EOT_WORLD_SESSION_MGR_ID,
    EOT_WORLD_ROLE_ID,
    EOT_WORLD_ROLE_MGR_ID,
    ////////////////////////////world server trans/////////////////////////////

    ////////////////////////////world server trans/////////////////////////////
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
    EOT_GAME_CONFIG_ID,
    EOT_GAME_SCENE_ID,
    EOT_GAME_MAP_ID,
    EOT_GAME_MAP_MGR_ID,
    EOT_GAME_CREATURE_ID,
    EOT_GAME_SCENE_MGR_ID,
    EOT_GAME_CREATURE_MGR_ID,
    EOT_GAME_NFBattlePlayer_ID,
    ////////////////////////////sns part server/////////////////////////////
    EOT_NFBattlePart_ID,
    EOT_NFBattlePart_MAX_ID = EOT_NFBattlePart_ID+BATTLE_PART_MAX,
    ////////////////////////////sns server/////////////////////////////

    ////////////////////////////center server/////////////////////////////
    EOT_NFMapAddrMgr_ID,
    ////////////////////////////center server/////////////////////////////
	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;

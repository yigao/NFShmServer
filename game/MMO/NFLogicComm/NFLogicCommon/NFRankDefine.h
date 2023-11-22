// -------------------------------------------------------------------------
//    @FileName         :    NFRankDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-10-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFGameCommon/NFComTypeDefine.h"

//排行榜最大容量
#define RANK_MAX_SIZE 100
//排行榜实际排名容量
#define RANK_REAL_SIZE 150
//世界等级取排行榜前几名平均值
#define RANK_WORLDLEVEL_RANK 5

enum enRankType
{
    RANK_TYPE_POWER = 1,	//战斗力
    RANK_TYPE_LEVEL = 2,	//等级
    RANK_TYPE_GUILD = 3,	//帮派
    RANK_TYPE_EQUIP = 4,    //装备
    RANK_TYPE_XIUZHEN = 5,    //修真榜
    RANK_TYPE_FANGREN_XIUZHEN = 6,    //凡人修真榜
    RANK_TYPE_BATTLE_PASS_XIANCE = 7, //福缘仙册
    RANK_TYPE_BATTLE_PASS_BAODING = 8, //举世宝鼎
    RANK_TYPE_PET_FIGHT = 11, //宠物战力
    RANK_TYPE_MOUNT_FIGHT = 12, //坐骑阶数
    RANK_TYPE_YUANMAO_SUM = 13, //元宝累计获取
    RANK_TYPE_WING_FIGHT = 14, //羽翼等级
    RANK_TYPE_BAOSHI_LEVEL = 15, //宝石总等级
    RANK_TYPE_MARRY_VALUE = 16, //情侣积分排行
    RANK_TYPE_DEITY_FIGHT = 17, //天神战力
    RANK_TYPE_BEAST_FIGHT = 18, //神兽战力
    RANK_TYPE_BIAOBAI_VALUE = 19, //表白榜
    RANK_TYPE_MEILI_VALUE = 20, //魅力榜
    RANK_TYPE_ANQI_FIGHT = 21, //暗器榜
    RANK_TYPE_LINGJIA_FIGHT = 22, //灵甲榜
    RANK_TYPE_MAX = 22,
};


//排行榜玩家显示内容
enum enRankPlayerParam
{
    RANK_PLAYER_PARAM_RANK = 1,				//1排名
    RANK_PLAYER_PARAM_PT_STAGE= 2,	//2玩家修真境界
    RANK_PLAYER_PARAM_NAME = 3,				//3玩家名称
    RANK_PLAYER_PARAM_JOB = 4,				//4玩家职业
    RANK_PLAYER_PARAM_POWER = 5,			//5战斗力
    RANK_PLAYER_PARAM_LEVEL = 6,			//6等级
    RANK_PLAYER_PARAM_GUILD_RANK = 7,		//7帮派排名
    RANK_PLAYER_PARAM_GUILD_NAME = 8,		//8帮派名称
    RANK_PLAYER_PARAM_GUILD_LEVEL = 9,		//9帮派等级
    RANK_PLAYER_PARAM_GUILD_POWER = 10,		//10帮派战力
    RANK_PLAYER_PARAM_EQUIP_SCORE = 11,		//11装备评分
    RANK_PLAYER_PARAM_RANK_PT_STAGE = 12,		//12玩家修真境界
    RANK_PLAYER_PARAM_FANGREN_LAYER = 13,	//13凡人修真通过层数
};




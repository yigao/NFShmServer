// -------------------------------------------------------------------------
//    @FileName         :    NFSceneDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFSceneDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFPoint3.h"

#define  MAP_NAME_MAX_LENGHT    64
#define  DROP_OBJECT_MIN_WIDTH  0.5f		// 每个掉落物品占位置大小（单位：米）
#define  REGION_DROP_FALG_MAX_WIDTH  64		// 每个region分割为64*32个0.5方块大小的标志位，记录掉落位置信息
#define  REGION_DROP_FALG_MAX_HEIGHT  32
#define  DROP_POS_OFFSET 10					// 掉落偏移范围



#define  CREATE_SECENE_TIME 60000           //逻辑服创建场景回复时间
#define  UPDATE_SECENE_TIME  43200000 //60000 * 60 * 12 //现有场景更新检查时间
#define  SECENE_EXIST_TIME  86400000 //60000 * 60 * 24 //单个副本场景存在时间上限

typedef std::vector<NFPoint3<uint32_t>> VEC_PATH;

enum MapMainType
{
    NONE_MAP,
    WILD_MAP = 1,			//野外地图
    DYNAMIC_MAP = 2,		//动态地图
    WILD_BOSS_MAP = 3,		//野外BOSS地图
    SAVAGE_BOSS_MAP = 4,	//蛮荒BOSS地图
    VIP_BOSS_MAP = 5,		//VIP BOSS 地图
    SECRET_TERRITORY = 6,   //秘境
    JEDI_FIGHTING = 7,      //绝地乱斗
    CHAOSDRAGON_MAP = 8,	//混沌之龙

    BOX_ACTIVITY_MAP = 11,	//刷宝箱地图
};

enum MapSubType
{
    NONE_SUBMAP,
    SINGLE_SUBMAP = 1,  //单人副本
    DISPUTE_SUBMAP = 2,		//纷争之地
    COMBAT_TEAM_PK_SUBMAP= 3,		// 3V3PK地图
    SOLO_SUBMAP = 4,				// solo地图
    UNION_WAR_SUBMAP = 5,	//公会战地图
};

//地图PK规则
enum MapPkRule
{
    MAP_PK_RULE_CAN_NOT_PK = 0,							//不能PK
    MAP_PK_RULE_CAN_PK = 1,								//可PK
    MAP_PK_RULE_CAN_PK_BUT_NOT_COUNT_PK_VALUE = 2,		//可PK但是不加PK值
};

//地图区域类型
enum EMapAreaType
{
    EMapAreaType_Circle = 0,	//圆
    EMapAreaType_Quadrangle = 1,//四边形
};


//传送地图类型(针对客户端传送地图用)
enum ETransMapType
{
    ETransMapType_None = 0,			//无,默认出生点传送
    ETransMapType_Point = 1,		//路径点传送
    ETransMapType_Area = 2,			//区域传送
    ETransMapType_Teleport = 3,		//传送门传送
};


//切场景类型
enum ETransType
{
    ETransType_None = 0,
    ETransType_Scene = 1,		//场景传送
    ETransType_Dup = 2,			//副本
    ETransType_GM = 3,			//GM
    ETransType_Born = 4,		//出生进入场景
    ETransType_Relive = 5,		//复活传送场景
    ETransType_Rand = 6,		//场景随机传送
    ETransType_SkipGuidDup = 7,//跳过新手副本
    ETransType_Reconnect = 8,	//重连之后场景传送
    ETransType_Teleport = 9,	//传送门传送
    ETransType_Limit,
};



//创建场景参数类型
enum ESceneParamType
{
    ESceneParamType_None,
    ESceneParamType_Dup			= 1,		//副本场景  类型值：副本ID
    ESceneParamType_Teleport	= 2,		//传送门传送 类型值：传送门ID
    ESceneParamType_Limit,
};

/*
struct CurCenterSceneInfo
{
	uint64_t sceneId;
	uint64_t mapId;
	uint32_t OnlineCount;
	uint32_t logicId;
	uint64_t startTimestrap; //开始时间戳
	CurCenterSceneInfo()
	{
		sceneId = 0;
		mapId = 0;
		OnlineCount = 0;
		logicId = 0;
		startTimestrap = 0;
	}
};*/
//场景简要信息
struct SceneSimpleInfo
{
    uint64_t sceneId = 0;
    uint64_t mapId = 0;
    uint32_t logicId = 0;
    uint64_t createtime = 0;
};


//切场景参数
struct STransParam
{
    uint64_t srcMapId; //源地图ID
    int32_t transType; //传送类型，详见 ETransType枚举
    //扩展字段可以往下面加
    uint64_t transVal;	//传送类型值
    NFPoint3<float> srcPos;//源地图坐标
    STransParam()
    {
        srcMapId = 0;
        transType = 0;
        transVal = 0;
    }
};

//传送门类型
enum ETeleportType
{
    ETeleportType_None = 0,
    ETeleportType_Map = 1,	//传送到指定地图
    ETeleportType_Dup = 2,	//传送到指定副本
    ETeleportType_Limit,
};


//传送门产生的条件
enum ETeleportCond
{
    ETeleportCond_None = 0,
    ETeleportCond_KillMonster = 1,		//击杀怪物出现
    ETeleportCond_UseItem = 2,			//使用物品
    ETeleportCond_Forever = 3,			//永久存在
    ETeleportCond_Limit,
};

//传送门进入权限
enum ETeleEnterAllow
{
    ETeleEnterAllow_All = 0,
    ETeleEnterAllow_Player = 1,
    ETeleEnterAllow_Union = 2,
};
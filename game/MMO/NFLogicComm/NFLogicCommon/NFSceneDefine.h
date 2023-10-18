// -------------------------------------------------------------------------
//    @FileName         :    NFSceneDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-10-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFSceneDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFGameCommon/NFPoint3.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include <unordered_map>

typedef std::vector<NFPoint3<uint32_t>> VEC_PATH;

//地图主类型
enum MapMainType
{
    NONE_MAP,				//无
    NORMAL_MAP = 1,			//主城
    DUP_MAP = 2,			//副本
    BOSS_MAP = 3,			//BOSS地图
    SAFE_MAP = 5,			//安全地图
    //GVB_MAP = 5,			//神机谷战场地图
};

//普通地图的子类型
enum class ENormalMapType
{
    None = 0,
    Novice = 1,		//新手村
    Wild = 2,		//野外地图
    MainCity = 3,	//主城
    Ready1v1 = 4,   //1v1准备场景
    Safe = 5,		//安全地图
    Limit,
};



//0、进入地图保持原PK模式，1、和平，2、全体，3、公会，4、阵营模式，5跨服，6入侵，7守护，8乱斗
//PK模式
enum class EPKMode
{
    none = 0,
    peace = 1,			//和平
    all = 2,			//全体
    faction = 3,		//帮派
    camp = 4,			//阵营
    cross = 5,			//跨服
    invade = 6,			//入侵
    protect = 7,		//守护
    scuffle = 8,		//乱斗
    limit
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
    ETransType_Teleport = 9,	//瞬移-传送
    ETransType_Leave1v1Ready = 10,	//离开1v1准备场景
    ETransType_dyn_dup = 11,		//动态副本
    ETransType_CreateDupFail = 12,//创建副本失败
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


//场景简要信息
struct SceneSimpleInfo
{
    uint64_t sceneId = 0;
    uint64_t mapId = 0;
    uint32_t logicId = 0;
    uint32_t zid = 0;
    uint64_t createtime = 0;
};


//切场景参数
/*
struct STransParam
{
	uint64_t srcMapId; //源地图ID
	int32_t transType; //传送类型，详见 ETransType枚举
	//扩展字段可以往下面加
	uint64_t transVal;	//传送类型值
	Point3<float> srcPos;//源地图坐标
	STransParam()
	{
		srcMapId = 0;
		transType = 0;
		transVal = 0;
	}
};*/

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


struct stCorpseInfo
{
    uint64_t monsterId = 0;
    uint64_t aliveTime = 0;
    NFPoint3<float> pos;
    uint64_t cid = 0;	//用实体死亡前cid做唯一id就可以了
};

using CropseMap = std::unordered_map<uint64_t, stCorpseInfo>;

struct stDriveInfo
{
    uint64_t cid =0;				//驱离的玩家id
    int32_t drivePoint =0;			//驱离值
    int64_t lastUpdateTime =0;		//上次更新的驱离值的时间
    int64_t lastMinTime =0;		//上一分钟时间
    int64_t driveTime =0;			//驱离时间
};

using DriveMap = std::unordered_map<uint64_t, stDriveInfo>;

struct stEncourageInfo
{
    MAP_INT32_INT8 infos;			//id ->次数
};
using EncourageMap = std::unordered_map<uint64_t, stEncourageInfo>;

// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFPoint3.h"
#include "NFPoint2.h"
#include <vector>
#include <Com.pb.h>
#include "NFSceneDefine.h"

#define MAX_CHARACTER_SINGLERANGE  30      //视野
#define MAX_CHARACTER_SINGLERANGE_SQUARE 900
//grid count (100-200)*(100-200)
#define GRID_LENGTH 10   //和视野是1:3的关系
#define F_TEN_THOUSAND 10000.0
#define F_ONE_HANDURD 100.0
#define TEN_THOUSAND 10000
#define ONE_HANDURD 100
#define MAX_KILLING_VALUE 250  //杀戮值上限

enum CreatureType
{
    CREATURE_NONE = 0,
    CREATURE_PLAYER,    //玩家
    CREATURE_MONSTER,   //怪物
    CREATURE_DROP,		//掉落
    CREATURE_REBOT,     //机器人
    CREATURE_PARTNER,	//伙伴
    CREATURE_MAX
};

enum PartType
{
    PART_NONE = 0,
    PART_FUNCTIONUNLOCK,	//功能解锁
    PART_PACKAGE,			//背包
    PART_GROW,				//养成
    PART_MINI,				//杂项模块
    PART_CHAT,				//聊天
    PART_EQUIP,				//装备模块
    PART_MISSION,
    PART_MAX,
};

enum
{
    ROLE_DISCONN_FROM_CLIENT =1,         //client close connection
    ROLE_DISCONN_FROM_SERVER =2,         //server dump
    ROLE_DISCONN_HEARTBEAT_TIMEOUT = 3,  //
    ROLE_DISCONN_MSG_MONITOR = 4,
};

typedef std::vector<NFPoint3<float>> VEC_POINT3;
typedef std::vector<int> VEC_FLAGS;

struct HitWallParam
{
    float         tangentDir;			//
    float         hitLength;			//
    float         hitPos[3];			//
    unsigned int  hitRef;				//
    unsigned int* pathPolys;			//
    int           polyCount;			//

    void Clear()
    {
        tangentDir = 0.0f;
        hitLength = 0.0f;
        hitPos[0] = 0.0f;
        hitPos[1] = 0.0f;
        hitPos[2] = 0.0f;
        hitRef    = 0;
        pathPolys = nullptr;
        polyCount = 0;
    }

    HitWallParam()
    {
        Clear();
    }
};

struct CharLoginInfo
{
    uint64_t reqid = 0;

    uint64_t sceneid = 0;
    uint64_t mapid = 0;
    NFPoint3<float> pos;
    //上一个地图和坐标目前只用于切逻辑节点保存数据用的
    uint64_t lastSceneId = 0;
    uint64_t lastMapId = 0;
    NFPoint3<float> lastpos;

    int32_t last_state = 0;

    uint32_t uid = 0;
    uint32_t clientId = 0;
    uint32_t gateId = 0;
    uint32_t channelId = 0;
    uint32_t zid = 0;

    proto_ff::LoginSyncProto proto;

    STransParam transParam;
};

//客户端提示、飘字等显示信息类型
enum class EClientShowType
{
    Exp = 1,		//经验
    Drop = 2,		//掉落(前端掉落飘入背包的效果), 现在没用到了
    Virtual = 3,	//虚拟物品提示
    Dispute = 4,	//纷争之地贡献提示
    Help = 5,		//助攻提示
    WarScore = 6,	//工会战积分限时
    UseContri = 7,	//工会可用贡献提示
    MonsExp = 8,	//打怪经验
};
// -------------------------------------------------------------------------
//    @FileName         :    NFCreatureVisionData.h
//    @Author           :    gaoyi
//    @Date             :    23-2-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreatureVisionData
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmStl/NFShmList.h"

class NFCreature;

//视野标记
enum class EVisionFlag
{
    NONE = 0,				//无
    ALREADY,				//已经在视野里
};

enum
{
    NEW_SEE_VISION_NONE = 0,
    NEW_SEE_VISION_SPECIAL_RELATIONSHIP = 1,
    NEW_SEE_VISION_LESS_HALF_OF_HALF_MAX_SIGHT_RANGE = 2,
    NEW_SEE_VISION_LESS_HALF_OF_MAX_SIGHT_RANGE = 3,
    NEW_SEE_VISION_THAN_HALF_OF_MAX_SIGHT_RANGE = 4,
    NEW_SEE_VISION_MAX,
};

//生物功能类型
enum class ECreatureFunc
{
    Monster = 101,					//怪物
    Npc = 201,						//常驻NPC
    TaskNpc = 202,					//任务NPC
    Collect = 301,					//采集物
    Collect_Box = 302,				//采集物 宝箱
    Collect_Buff = 304,				//带BUFF的采集物
    UseThing = 401,					//可使用物件
    DartCar = 501,					//镖车
    Transfer = 601,					//传送门
};

#define MAX_SEE_CREATURE_COUNT_IN_THE_VISION 100

class NFCreatureVisionDataNode
{
public:
    NFCreatureVisionDataNode();

    virtual ~NFCreatureVisionDataNode();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t creatureCid;
    int nMeInHisVisionPos;
};

class NFCreatureVisionData
{
public:
    NFCreatureVisionData();

    virtual ~NFCreatureVisionData();

    int CreateInit();

    int ResumeInit();
public:
    int AddPVPSeeList(NFCreature* pCreature);
    int AddPVMSeeList(NFCreature* pCreature);
    bool DelPVMSeeList(int pos);
    bool DelPVPSeeList(int pos);
public:
    NFShmList<NFCreatureVisionDataNode, MAX_SEE_CREATURE_COUNT_IN_THE_VISION>	m_doublePVPSeeLst;								//人和人的视野处理
    NFShmList<NFCreatureVisionDataNode, MAX_SEE_CREATURE_COUNT_IN_THE_VISION>	m_doublePVMSeeLst;								//这里只处理人和其他非人生物之间的视野管理， 怪物或NPC必须所有人都能看到
    int8_t	chVisionUnitType;		//用于记录此角色视野单元在进入别人视野处理的标记
};
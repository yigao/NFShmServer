#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_ROBOT_NUM 8192

class ArenaRobotDesc : public NFIDescTemplate<ArenaRobotDesc, proto_ff_s::E_ArenaRobot_s, EOT_CONST_ARENA_ROBOT_DESC_ID, MAX_ARENA_ROBOT_NUM>
{
public:
	ArenaRobotDesc();
	virtual ~ArenaRobotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

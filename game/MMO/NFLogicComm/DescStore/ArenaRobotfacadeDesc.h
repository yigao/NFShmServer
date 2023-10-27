#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_ROBOTFACADE_NUM 2

class ArenaRobotfacadeDesc : public NFIDescTemplate<ArenaRobotfacadeDesc, proto_ff_s::E_ArenaRobotfacade_s, EOT_CONST_ARENA_ROBOTFACADE_DESC_ID, MAX_ARENA_ROBOTFACADE_NUM>
{
public:
	ArenaRobotfacadeDesc();
	virtual ~ArenaRobotfacadeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

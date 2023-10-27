#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_ARENAWARD_NUM 2048

class ArenaArenawardDesc : public NFIDescTemplate<ArenaArenawardDesc, proto_ff_s::E_ArenaArenaward_s, EOT_CONST_ARENA_ARENAWARD_DESC_ID, MAX_ARENA_ARENAWARD_NUM>
{
public:
	ArenaArenawardDesc();
	virtual ~ArenaArenawardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

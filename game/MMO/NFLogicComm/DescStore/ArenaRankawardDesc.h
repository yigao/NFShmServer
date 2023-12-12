#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_RANKAWARD_NUM 8

class ArenaRankawardDesc : public NFIDescTemplate<ArenaRankawardDesc, proto_ff_s::E_ArenaRankaward_s, EOT_CONST_ARENA_RANKAWARD_DESC_ID, MAX_ARENA_RANKAWARD_NUM>
{
public:
	ArenaRankawardDesc();
	virtual ~ArenaRankawardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

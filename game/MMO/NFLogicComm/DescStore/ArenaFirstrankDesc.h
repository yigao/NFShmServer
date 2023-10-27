#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Arena_s.h"

#define MAX_ARENA_FIRSTRANK_NUM 16

class ArenaFirstrankDesc : public NFIDescTemplate<ArenaFirstrankDesc, proto_ff_s::E_ArenaFirstrank_s, EOT_CONST_ARENA_FIRSTRANK_DESC_ID, MAX_ARENA_FIRSTRANK_NUM>
{
public:
	ArenaFirstrankDesc();
	virtual ~ArenaFirstrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

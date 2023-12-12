#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_RUNE_NUM 32

class RuneRuneDesc : public NFIDescTemplate<RuneRuneDesc, proto_ff_s::E_RuneRune_s, EOT_CONST_RUNE_RUNE_DESC_ID, MAX_RUNE_RUNE_NUM>
{
public:
	RuneRuneDesc();
	virtual ~RuneRuneDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

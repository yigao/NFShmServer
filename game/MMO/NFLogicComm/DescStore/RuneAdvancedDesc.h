#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_ADVANCED_NUM 256

class RuneAdvancedDesc : public NFIDescTemplate<RuneAdvancedDesc, proto_ff_s::E_RuneAdvanced_s, EOT_CONST_RUNE_ADVANCED_DESC_ID, MAX_RUNE_ADVANCED_NUM>
{
public:
	RuneAdvancedDesc();
	virtual ~RuneAdvancedDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

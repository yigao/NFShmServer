#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_COMPARE_NUM 64

class RuneCompareDesc : public NFIDescTemplate<RuneCompareDesc, proto_ff_s::E_RuneCompare_s, EOT_CONST_RUNE_COMPARE_DESC_ID, MAX_RUNE_COMPARE_NUM>
{
public:
	RuneCompareDesc();
	virtual ~RuneCompareDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

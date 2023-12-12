#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_CONST_NUM 2

class RuneConstDesc : public NFIDescTemplate<RuneConstDesc, proto_ff_s::E_RuneConst_s, EOT_CONST_RUNE_CONST_DESC_ID, MAX_RUNE_CONST_NUM>
{
public:
	RuneConstDesc();
	virtual ~RuneConstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

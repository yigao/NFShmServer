#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_STUNTSKILL_NUM 16

class RuneStuntskillDesc : public NFIDescTemplate<RuneStuntskillDesc, proto_ff_s::E_RuneStuntskill_s, EOT_CONST_RUNE_STUNTSKILL_DESC_ID, MAX_RUNE_STUNTSKILL_NUM>
{
public:
	RuneStuntskillDesc();
	virtual ~RuneStuntskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

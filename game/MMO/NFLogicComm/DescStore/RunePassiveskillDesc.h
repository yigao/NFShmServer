#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_PASSIVESKILL_NUM 8

class RunePassiveskillDesc : public NFIDescTemplate<RunePassiveskillDesc, proto_ff_s::E_RunePassiveskill_s, EOT_CONST_RUNE_PASSIVESKILL_DESC_ID, MAX_RUNE_PASSIVESKILL_NUM>
{
public:
	RunePassiveskillDesc();
	virtual ~RunePassiveskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

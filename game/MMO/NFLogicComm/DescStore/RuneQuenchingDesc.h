#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_QUENCHING_NUM 16

class RuneQuenchingDesc : public NFIDescTemplate<RuneQuenchingDesc, proto_ff_s::E_RuneQuenching_s, EOT_CONST_RUNE_QUENCHING_DESC_ID, MAX_RUNE_QUENCHING_NUM>
{
public:
	RuneQuenchingDesc();
	virtual ~RuneQuenchingDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

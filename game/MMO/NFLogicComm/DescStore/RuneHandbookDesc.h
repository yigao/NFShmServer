#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_HANDBOOK_NUM 128

class RuneHandbookDesc : public NFIDescTemplate<RuneHandbookDesc, proto_ff_s::E_RuneHandbook_s, EOT_CONST_RUNE_HANDBOOK_DESC_ID, MAX_RUNE_HANDBOOK_NUM>
{
public:
	RuneHandbookDesc();
	virtual ~RuneHandbookDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

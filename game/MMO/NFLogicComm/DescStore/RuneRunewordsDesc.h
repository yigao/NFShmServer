#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_RUNEWORDS_NUM 128

class RuneRunewordsDesc : public NFIDescTemplate<RuneRunewordsDesc, proto_ff_s::E_RuneRunewords_s, EOT_CONST_RUNE_RUNEWORDS_DESC_ID, MAX_RUNE_RUNEWORDS_NUM>
{
public:
	RuneRunewordsDesc();
	virtual ~RuneRunewordsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

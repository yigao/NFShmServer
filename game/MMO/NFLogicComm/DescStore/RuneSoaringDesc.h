#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_SOARING_NUM 64

class RuneSoaringDesc : public NFIDescTemplate<RuneSoaringDesc, proto_ff_s::E_RuneSoaring_s, EOT_CONST_RUNE_SOARING_DESC_ID, MAX_RUNE_SOARING_NUM>
{
public:
	RuneSoaringDesc();
	virtual ~RuneSoaringDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

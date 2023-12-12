#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_BLESS_NUM 4

class SoulBlessDesc : public NFIDescTemplate<SoulBlessDesc, proto_ff_s::E_SoulBless_s, EOT_CONST_SOUL_BLESS_DESC_ID, MAX_SOUL_BLESS_NUM>
{
public:
	SoulBlessDesc();
	virtual ~SoulBlessDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

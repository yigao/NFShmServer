#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_AFFIXES_NUM 32

class SoulAffixesDesc : public NFIDescTemplate<SoulAffixesDesc, proto_ff_s::E_SoulAffixes_s, EOT_CONST_SOUL_AFFIXES_DESC_ID, MAX_SOUL_AFFIXES_NUM>
{
public:
	SoulAffixesDesc();
	virtual ~SoulAffixesDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

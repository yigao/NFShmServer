#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_AFFIXESSUIT_NUM 128

class SoulAffixessuitDesc : public NFIDescTemplate<SoulAffixessuitDesc, proto_ff_s::E_SoulAffixessuit_s, EOT_CONST_SOUL_AFFIXESSUIT_DESC_ID, MAX_SOUL_AFFIXESSUIT_NUM>
{
public:
	SoulAffixessuitDesc();
	virtual ~SoulAffixessuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

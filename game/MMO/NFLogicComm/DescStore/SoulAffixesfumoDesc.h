#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_AFFIXESFUMO_NUM 8

class SoulAffixesfumoDesc : public NFIDescTemplate<SoulAffixesfumoDesc, proto_ff_s::E_SoulAffixesfumo_s, EOT_CONST_SOUL_AFFIXESFUMO_DESC_ID, MAX_SOUL_AFFIXESFUMO_NUM>
{
public:
	SoulAffixesfumoDesc();
	virtual ~SoulAffixesfumoDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

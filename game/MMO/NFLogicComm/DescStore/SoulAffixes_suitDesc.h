#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_AFFIXES_SUIT_NUM 128

class SoulAffixes_suitDesc : public NFIDescTemplate<SoulAffixes_suitDesc, proto_ff_s::E_SoulAffixes_suit_s, EOT_CONST_SOUL_AFFIXES_SUIT_DESC_ID, MAX_SOUL_AFFIXES_SUIT_NUM>
{
public:
	SoulAffixes_suitDesc();
	virtual ~SoulAffixes_suitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

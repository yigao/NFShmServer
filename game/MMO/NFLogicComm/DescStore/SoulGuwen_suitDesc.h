#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWEN_SUIT_NUM 64

class SoulGuwen_suitDesc : public NFIDescTemplate<SoulGuwen_suitDesc, proto_ff_s::E_SoulGuwen_suit_s, EOT_CONST_SOUL_GUWEN_SUIT_DESC_ID, MAX_SOUL_GUWEN_SUIT_NUM>
{
public:
	SoulGuwen_suitDesc();
	virtual ~SoulGuwen_suitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

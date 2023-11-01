#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWEN_TYPE_SUIT_NUM 16

class SoulGuwen_type_suitDesc : public NFIDescTemplate<SoulGuwen_type_suitDesc, proto_ff_s::E_SoulGuwen_type_suit_s, EOT_CONST_SOUL_GUWEN_TYPE_SUIT_DESC_ID, MAX_SOUL_GUWEN_TYPE_SUIT_NUM>
{
public:
	SoulGuwen_type_suitDesc();
	virtual ~SoulGuwen_type_suitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWEN_SLOT_NUM 8

class SoulGuwen_slotDesc : public NFIDescTemplate<SoulGuwen_slotDesc, proto_ff_s::E_SoulGuwen_slot_s, EOT_CONST_SOUL_GUWEN_SLOT_DESC_ID, MAX_SOUL_GUWEN_SLOT_NUM>
{
public:
	SoulGuwen_slotDesc();
	virtual ~SoulGuwen_slotDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

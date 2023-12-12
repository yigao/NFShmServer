#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_BLESS_NUM 128

class AncientgodBlessDesc : public NFIDescTemplate<AncientgodBlessDesc, proto_ff_s::E_AncientgodBless_s, EOT_CONST_ANCIENTGOD_BLESS_DESC_ID, MAX_ANCIENTGOD_BLESS_NUM>
{
public:
	AncientgodBlessDesc();
	virtual ~AncientgodBlessDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

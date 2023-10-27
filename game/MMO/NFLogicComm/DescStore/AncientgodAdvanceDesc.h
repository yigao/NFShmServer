#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ADVANCE_NUM 128

class AncientgodAdvanceDesc : public NFIDescTemplate<AncientgodAdvanceDesc, proto_ff_s::E_AncientgodAdvance_s, EOT_CONST_ANCIENTGOD_ADVANCE_DESC_ID, MAX_ANCIENTGOD_ADVANCE_NUM>
{
public:
	AncientgodAdvanceDesc();
	virtual ~AncientgodAdvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

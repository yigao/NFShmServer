#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EVOLVE_NUM 256

class ShentiEvolveDesc : public NFIDescTemplate<ShentiEvolveDesc, proto_ff_s::E_ShentiEvolve_s, EOT_CONST_SHENTI_EVOLVE_DESC_ID, MAX_SHENTI_EVOLVE_NUM>
{
public:
	ShentiEvolveDesc();
	virtual ~ShentiEvolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

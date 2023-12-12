#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_EVOLVE_NUM 512

class XiuzhenEvolveDesc : public NFIDescTemplate<XiuzhenEvolveDesc, proto_ff_s::E_XiuzhenEvolve_s, EOT_CONST_XIUZHEN_EVOLVE_DESC_ID, MAX_XIUZHEN_EVOLVE_NUM>
{
public:
	XiuzhenEvolveDesc();
	virtual ~XiuzhenEvolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

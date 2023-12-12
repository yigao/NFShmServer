#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EVOLVEPROGRESS_NUM 256

class ShentiEvolveprogressDesc : public NFIDescTemplate<ShentiEvolveprogressDesc, proto_ff_s::E_ShentiEvolveprogress_s, EOT_CONST_SHENTI_EVOLVEPROGRESS_DESC_ID, MAX_SHENTI_EVOLVEPROGRESS_NUM>
{
public:
	ShentiEvolveprogressDesc();
	virtual ~ShentiEvolveprogressDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

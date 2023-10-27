#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Peractivity_s.h"

#define MAX_PERACTIVITY_PERACTIVITY_NUM 32

class PeractivityPeractivityDesc : public NFIDescTemplate<PeractivityPeractivityDesc, proto_ff_s::E_PeractivityPeractivity_s, EOT_CONST_PERACTIVITY_PERACTIVITY_DESC_ID, MAX_PERACTIVITY_PERACTIVITY_NUM>
{
public:
	PeractivityPeractivityDesc();
	virtual ~PeractivityPeractivityDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

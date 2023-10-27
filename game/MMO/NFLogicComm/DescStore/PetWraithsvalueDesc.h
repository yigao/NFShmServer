#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_WRAITHSVALUE_NUM 256

class PetWraithsvalueDesc : public NFIDescTemplate<PetWraithsvalueDesc, proto_ff_s::E_PetWraithsvalue_s, EOT_CONST_PET_WRAITHSVALUE_DESC_ID, MAX_PET_WRAITHSVALUE_NUM>
{
public:
	PetWraithsvalueDesc();
	virtual ~PetWraithsvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

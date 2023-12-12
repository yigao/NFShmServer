#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_STARVALUE_NUM 256

class PetStarvalueDesc : public NFIDescTemplate<PetStarvalueDesc, proto_ff_s::E_PetStarvalue_s, EOT_CONST_PET_STARVALUE_DESC_ID, MAX_PET_STARVALUE_NUM>
{
public:
	PetStarvalueDesc();
	virtual ~PetStarvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

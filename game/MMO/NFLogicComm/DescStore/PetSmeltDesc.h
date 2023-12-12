#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_SMELT_NUM 64

class PetSmeltDesc : public NFIDescTemplate<PetSmeltDesc, proto_ff_s::E_PetSmelt_s, EOT_CONST_PET_SMELT_DESC_ID, MAX_PET_SMELT_NUM>
{
public:
	PetSmeltDesc();
	virtual ~PetSmeltDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

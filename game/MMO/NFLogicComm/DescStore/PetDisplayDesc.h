#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_DISPLAY_NUM 64

class PetDisplayDesc : public NFIDescTemplate<PetDisplayDesc, proto_ff_s::E_PetDisplay_s, EOT_CONST_PET_DISPLAY_DESC_ID, MAX_PET_DISPLAY_NUM>
{
public:
	PetDisplayDesc();
	virtual ~PetDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

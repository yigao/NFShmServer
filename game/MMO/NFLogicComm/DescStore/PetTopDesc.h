#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_TOP_NUM 256

class PetTopDesc : public NFIDescTemplate<PetTopDesc, proto_ff_s::E_PetTop_s, EOT_CONST_PET_TOP_DESC_ID, MAX_PET_TOP_NUM>
{
public:
	PetTopDesc();
	virtual ~PetTopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

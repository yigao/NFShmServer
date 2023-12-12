#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_WRAITHS_NUM 256

class PetWraithsDesc : public NFIDescTemplate<PetWraithsDesc, proto_ff_s::E_PetWraiths_s, EOT_CONST_PET_WRAITHS_DESC_ID, MAX_PET_WRAITHS_NUM>
{
public:
	PetWraithsDesc();
	virtual ~PetWraithsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

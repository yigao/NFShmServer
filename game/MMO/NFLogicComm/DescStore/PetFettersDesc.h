#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_FETTERS_NUM 16

class PetFettersDesc : public NFIDescTemplate<PetFettersDesc, proto_ff_s::E_PetFetters_s, EOT_CONST_PET_FETTERS_DESC_ID, MAX_PET_FETTERS_NUM>
{
public:
	PetFettersDesc();
	virtual ~PetFettersDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

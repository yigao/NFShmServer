#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_CONST_NUM 2

class PetConstDesc : public NFIDescTemplate<PetConstDesc, proto_ff_s::E_PetConst_s, EOT_CONST_PET_CONST_DESC_ID, MAX_PET_CONST_NUM>
{
public:
	PetConstDesc();
	virtual ~PetConstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

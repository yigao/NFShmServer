#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_ATTRIBUTETPYE_NUM 128

class PetAttributetpyeDesc : public NFIDescTemplate<PetAttributetpyeDesc, proto_ff_s::E_PetAttributetpye_s, EOT_CONST_PET_ATTRIBUTETPYE_DESC_ID, MAX_PET_ATTRIBUTETPYE_NUM>
{
public:
	PetAttributetpyeDesc();
	virtual ~PetAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

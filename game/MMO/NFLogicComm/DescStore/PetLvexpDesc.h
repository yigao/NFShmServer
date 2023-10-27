#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_LVEXP_NUM 512

class PetLvexpDesc : public NFIDescTemplate<PetLvexpDesc, proto_ff_s::E_PetLvexp_s, EOT_CONST_PET_LVEXP_DESC_ID, MAX_PET_LVEXP_NUM>
{
public:
	PetLvexpDesc();
	virtual ~PetLvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

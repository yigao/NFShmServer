#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_EQUIPVALUE_NUM 1024

class PetEquipvalueDesc : public NFIDescTemplate<PetEquipvalueDesc, proto_ff_s::E_PetEquipvalue_s, EOT_CONST_PET_EQUIPVALUE_DESC_ID, MAX_PET_EQUIPVALUE_NUM>
{
public:
	PetEquipvalueDesc();
	virtual ~PetEquipvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

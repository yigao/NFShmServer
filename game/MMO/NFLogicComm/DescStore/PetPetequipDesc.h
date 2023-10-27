#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_PETEQUIP_NUM 32

class PetPetequipDesc : public NFIDescTemplate<PetPetequipDesc, proto_ff_s::E_PetPetequip_s, EOT_CONST_PET_PETEQUIP_DESC_ID, MAX_PET_PETEQUIP_NUM>
{
public:
	PetPetequipDesc();
	virtual ~PetPetequipDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_EGG_NUM 64

class PetEggDesc : public NFIDescTemplate<PetEggDesc, proto_ff_s::E_PetEgg_s, EOT_CONST_PET_EGG_DESC_ID, MAX_PET_EGG_NUM>
{
public:
	PetEggDesc();
	virtual ~PetEggDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

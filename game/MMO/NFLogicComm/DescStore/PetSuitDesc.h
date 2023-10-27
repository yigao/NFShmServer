#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_SUIT_NUM 32

class PetSuitDesc : public NFIDescTemplate<PetSuitDesc, proto_ff_s::E_PetSuit_s, EOT_CONST_PET_SUIT_DESC_ID, MAX_PET_SUIT_NUM>
{
public:
	PetSuitDesc();
	virtual ~PetSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_STOVE_NUM 512

class PetStoveDesc : public NFIDescTemplate<PetStoveDesc, proto_ff_s::E_PetStove_s, EOT_CONST_PET_STOVE_DESC_ID, MAX_PET_STOVE_NUM>
{
public:
	PetStoveDesc();
	virtual ~PetStoveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

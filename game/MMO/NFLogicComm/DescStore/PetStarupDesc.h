#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_STARUP_NUM 64

class PetStarupDesc : public NFIDescTemplate<PetStarupDesc, proto_ff_s::E_PetStarup_s, EOT_CONST_PET_STARUP_DESC_ID, MAX_PET_STARUP_NUM>
{
public:
	PetStarupDesc();
	virtual ~PetStarupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

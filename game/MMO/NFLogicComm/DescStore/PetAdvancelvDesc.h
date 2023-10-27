#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_ADVANCELV_NUM 128

class PetAdvancelvDesc : public NFIDescTemplate<PetAdvancelvDesc, proto_ff_s::E_PetAdvancelv_s, EOT_CONST_PET_ADVANCELV_DESC_ID, MAX_PET_ADVANCELV_NUM>
{
public:
	PetAdvancelvDesc();
	virtual ~PetAdvancelvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

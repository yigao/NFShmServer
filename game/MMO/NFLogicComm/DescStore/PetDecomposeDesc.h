#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_DECOMPOSE_NUM 8

class PetDecomposeDesc : public NFIDescTemplate<PetDecomposeDesc, proto_ff_s::E_PetDecompose_s, EOT_CONST_PET_DECOMPOSE_DESC_ID, MAX_PET_DECOMPOSE_NUM>
{
public:
	PetDecomposeDesc();
	virtual ~PetDecomposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

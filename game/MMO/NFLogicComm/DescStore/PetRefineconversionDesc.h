#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_REFINECONVERSION_NUM 32

class PetRefineconversionDesc : public NFIDescTemplate<PetRefineconversionDesc, proto_ff_s::E_PetRefineconversion_s, EOT_CONST_PET_REFINECONVERSION_DESC_ID, MAX_PET_REFINECONVERSION_NUM>
{
public:
	PetRefineconversionDesc();
	virtual ~PetRefineconversionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

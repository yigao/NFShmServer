#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_WRAITHSLV_NUM 256

class PetWraithslvDesc : public NFIDescTemplate<PetWraithslvDesc, proto_ff_s::E_PetWraithslv_s, EOT_CONST_PET_WRAITHSLV_DESC_ID, MAX_PET_WRAITHSLV_NUM>
{
public:
	PetWraithslvDesc();
	virtual ~PetWraithslvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

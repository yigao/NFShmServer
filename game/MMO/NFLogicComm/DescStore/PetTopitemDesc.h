#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_TOPITEM_NUM 32

class PetTopitemDesc : public NFIDescTemplate<PetTopitemDesc, proto_ff_s::E_PetTopitem_s, EOT_CONST_PET_TOPITEM_DESC_ID, MAX_PET_TOPITEM_NUM>
{
public:
	PetTopitemDesc();
	virtual ~PetTopitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

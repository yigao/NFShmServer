#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_DISPLAY_NUM 20

class PetDisplayDesc : public NFIDescStore
{
public:
	PetDisplayDesc();
	virtual ~PetDisplayDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetDisplay_s* GetDesc(int id) const;
	proto_ff_s::E_PetDisplay_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetDisplay_s, E_PetDisplay, MAX_PET_DISPLAY_NUM);
DECLARE_IDCREATE(PetDisplayDesc);
};

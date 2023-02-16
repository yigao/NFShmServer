#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_LVEXP_NUM 500

class PetLvexpDesc : public NFIDescStore
{
public:
	PetLvexpDesc();
	virtual ~PetLvexpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetLvexp_s* GetDesc(int id) const;
	proto_ff_s::E_PetLvexp_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetLvexp_s, E_PetLvexp, MAX_PET_LVEXP_NUM);
DECLARE_IDCREATE(PetLvexpDesc);
};

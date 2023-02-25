#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_FETTERS_NUM 20

class PetFettersDesc : public NFIDescStore
{
public:
	PetFettersDesc();
	virtual ~PetFettersDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetFetters_s* GetDesc(int id) const;
	proto_ff_s::E_PetFetters_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetFetters_s, E_PetFetters, MAX_PET_FETTERS_NUM);
DECLARE_IDCREATE(PetFettersDesc);
};
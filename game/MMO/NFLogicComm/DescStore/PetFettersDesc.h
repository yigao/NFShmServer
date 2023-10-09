#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_FETTERS_NUM 8

class PetFettersDesc : public NFIDescStore
{
public:
	PetFettersDesc();
	virtual ~PetFettersDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetFetters_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetFetters_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetFetters_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetFetters_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetFettersDesc, proto_ff_s::E_PetFetters_s, E_PetFetters, MAX_PET_FETTERS_NUM);
DECLARE_IDCREATE(PetFettersDesc);
};

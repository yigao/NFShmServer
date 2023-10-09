#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_LVEXP_NUM 512

class PetLvexpDesc : public NFIDescStore
{
public:
	PetLvexpDesc();
	virtual ~PetLvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetLvexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetLvexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetLvexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetLvexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetLvexpDesc, proto_ff_s::E_PetLvexp_s, E_PetLvexp, MAX_PET_LVEXP_NUM);
DECLARE_IDCREATE(PetLvexpDesc);
};

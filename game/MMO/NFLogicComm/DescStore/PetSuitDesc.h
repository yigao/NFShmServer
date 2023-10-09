#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_SUIT_NUM 32

class PetSuitDesc : public NFIDescStore
{
public:
	PetSuitDesc();
	virtual ~PetSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetSuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetSuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetSuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetSuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetSuitDesc, proto_ff_s::E_PetSuit_s, E_PetSuit, MAX_PET_SUIT_NUM);
DECLARE_IDCREATE(PetSuitDesc);
};

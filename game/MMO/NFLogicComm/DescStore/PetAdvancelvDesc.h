#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_ADVANCELV_NUM 200

class PetAdvancelvDesc : public NFIDescStore
{
public:
	PetAdvancelvDesc();
	virtual ~PetAdvancelvDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetAdvancelv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetAdvancelv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetAdvancelv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetAdvancelv_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_PetAdvancelv_s, E_PetAdvancelv, MAX_PET_ADVANCELV_NUM);
DECLARE_IDCREATE(PetAdvancelvDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_STOVE_NUM 512

class PetStoveDesc : public NFIDescStore
{
public:
	PetStoveDesc();
	virtual ~PetStoveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetStove_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetStove_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetStove_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetStove_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetStoveDesc, proto_ff_s::E_PetStove_s, E_PetStove, MAX_PET_STOVE_NUM);
DECLARE_IDCREATE(PetStoveDesc);
};

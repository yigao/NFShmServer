#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_WRAITHSLV_NUM 256

class PetWraithslvDesc : public NFIDescStore
{
public:
	PetWraithslvDesc();
	virtual ~PetWraithslvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetWraithslv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetWraithslv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetWraithslv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetWraithslv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetWraithslvDesc, proto_ff_s::E_PetWraithslv_s, E_PetWraithslv, MAX_PET_WRAITHSLV_NUM);
DECLARE_IDCREATE_GLOBAL(PetWraithslvDesc);
};

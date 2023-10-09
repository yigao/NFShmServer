#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_ATTRIBUTETPYE_NUM 128

class PetAttributetpyeDesc : public NFIDescStore
{
public:
	PetAttributetpyeDesc();
	virtual ~PetAttributetpyeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetAttributetpye_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetAttributetpye_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetAttributetpye_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetAttributetpye_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetAttributetpyeDesc, proto_ff_s::E_PetAttributetpye_s, E_PetAttributetpye, MAX_PET_ATTRIBUTETPYE_NUM);
DECLARE_IDCREATE(PetAttributetpyeDesc);
};

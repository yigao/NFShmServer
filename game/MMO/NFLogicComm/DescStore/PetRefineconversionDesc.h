#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pet_s.h"

#define MAX_PET_REFINECONVERSION_NUM 32

class PetRefineconversionDesc : public NFIDescStore
{
public:
	PetRefineconversionDesc();
	virtual ~PetRefineconversionDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_PetRefineconversion_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetRefineconversion_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetRefineconversion_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetRefineconversion_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(PetRefineconversionDesc, proto_ff_s::E_PetRefineconversion_s, E_PetRefineconversion, MAX_PET_REFINECONVERSION_NUM);
DECLARE_IDCREATE_GLOBAL(PetRefineconversionDesc);
};

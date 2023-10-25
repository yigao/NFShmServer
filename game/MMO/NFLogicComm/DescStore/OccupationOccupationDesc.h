#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_OCCUPATION_NUM 16

class OccupationOccupationDesc : public NFIDescStore
{
public:
	OccupationOccupationDesc();
	virtual ~OccupationOccupationDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OccupationOccupation_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationOccupation_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationOccupation_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationOccupation_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OccupationOccupationDesc, proto_ff_s::E_OccupationOccupation_s, E_OccupationOccupation, MAX_OCCUPATION_OCCUPATION_NUM);
DECLARE_IDCREATE_GLOBAL(OccupationOccupationDesc);
};

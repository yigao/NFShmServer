#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_OCCUPATION_NUM 20

class OccupationOccupationDesc : public NFIDescStore
{
public:
	OccupationOccupationDesc();
	virtual ~OccupationOccupationDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_OccupationOccupation_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationOccupation_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationOccupation_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationOccupation_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(OccupationOccupationDesc, proto_ff_s::E_OccupationOccupation_s, E_OccupationOccupation, MAX_OCCUPATION_OCCUPATION_NUM);
DECLARE_IDCREATE(OccupationOccupationDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_SOUL_NUM 64

class OccupationSoulDesc : public NFIDescStore
{
public:
	OccupationSoulDesc();
	virtual ~OccupationSoulDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OccupationSoul_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationSoul_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationSoul_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationSoul_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OccupationSoulDesc, proto_ff_s::E_OccupationSoul_s, E_OccupationSoul, MAX_OCCUPATION_SOUL_NUM);
DECLARE_IDCREATE(OccupationSoulDesc);
};

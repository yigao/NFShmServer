#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_ATTRIBUTE_NUM 64

class OccupationAttributeDesc : public NFIDescStore
{
public:
	OccupationAttributeDesc();
	virtual ~OccupationAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OccupationAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationAttribute_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OccupationAttributeDesc, proto_ff_s::E_OccupationAttribute_s, E_OccupationAttribute, MAX_OCCUPATION_ATTRIBUTE_NUM);
DECLARE_IDCREATE_GLOBAL(OccupationAttributeDesc);
};

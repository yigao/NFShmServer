#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/occupation_s.h"

#define MAX_OCCUPATION_ATTRIBUTE_NUM 20

class OccupationAttributeDesc : public NFIDescStore
{
public:
	OccupationAttributeDesc();
	virtual ~OccupationAttributeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_OccupationAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OccupationAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OccupationAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OccupationAttribute_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_OccupationAttribute_s, E_OccupationAttribute, MAX_OCCUPATION_ATTRIBUTE_NUM);
DECLARE_IDCREATE(OccupationAttributeDesc);
};

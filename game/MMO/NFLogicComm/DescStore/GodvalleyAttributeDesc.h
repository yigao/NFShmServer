#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godvalley_s.h"

#define MAX_GODVALLEY_ATTRIBUTE_NUM 2

class GodvalleyAttributeDesc : public NFIDescStore
{
public:
	GodvalleyAttributeDesc();
	virtual ~GodvalleyAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodvalleyAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodvalleyAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodvalleyAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodvalleyAttribute_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodvalleyAttributeDesc, proto_ff_s::E_GodvalleyAttribute_s, E_GodvalleyAttribute, MAX_GODVALLEY_ATTRIBUTE_NUM);
DECLARE_IDCREATE(GodvalleyAttributeDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_ATTRIBUTE_NUM 512

class ShentiAttributeDesc : public NFIDescStore
{
public:
	ShentiAttributeDesc();
	virtual ~ShentiAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiAttribute_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiAttributeDesc, proto_ff_s::E_ShentiAttribute_s, E_ShentiAttribute, MAX_SHENTI_ATTRIBUTE_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiAttributeDesc);
};

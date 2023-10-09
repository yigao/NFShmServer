#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Attribute_s.h"

#define MAX_ATTRIBUTE_ATTRIBUTE_NUM 256

class AttributeAttributeDesc : public NFIDescStore
{
public:
	AttributeAttributeDesc();
	virtual ~AttributeAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AttributeAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AttributeAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AttributeAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AttributeAttribute_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AttributeAttributeDesc, proto_ff_s::E_AttributeAttribute_s, E_AttributeAttribute, MAX_ATTRIBUTE_ATTRIBUTE_NUM);
DECLARE_IDCREATE(AttributeAttributeDesc);
};

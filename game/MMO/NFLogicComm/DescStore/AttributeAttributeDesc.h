#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_ATTRIBUTE_NUM 200

class AttributeAttributeDesc : public NFIDescStore
{
public:
	AttributeAttributeDesc();
	virtual ~AttributeAttributeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::attributeattribute_s* GetDesc(int id) const;
	proto_ff_s::attributeattribute_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::attributeattribute_s, attributeattribute, MAX_ATTRIBUTE_ATTRIBUTE_NUM);
DECLARE_IDCREATE(AttributeAttributeDesc);
};

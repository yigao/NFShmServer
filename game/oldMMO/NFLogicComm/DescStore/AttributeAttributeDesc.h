#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_ATTRIBUTE_NUM 200

class AttributeAttributeDesc : public NFIDescStore
{
public:
	AttributeAttributeDesc(NFIPluginManager* pPluginManager);
	virtual ~AttributeAttributeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::attributeattribute_s* GetDesc(int id) const;
	proto_ff_s::attributeattribute_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::attributeattribute_s, MAX_ATTRIBUTE_ATTRIBUTE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::attributeattribute_s, MAX_ATTRIBUTE_ATTRIBUTE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::attributeattribute_s, attributeattribute, MAX_ATTRIBUTE_ATTRIBUTE_NUM);
DECLARE_IDCREATE(AttributeAttributeDesc);
};

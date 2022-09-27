#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/attribute_s.h"

#define MAX_ATTRIBUTE_SUPPRESS_NUM 600

class AttributeSuppressDesc : public NFIDescStore
{
public:
	AttributeSuppressDesc(NFIPluginManager* pPluginManager);
	virtual ~AttributeSuppressDesc();
	const proto_ff_s::attributesuppress_s* GetDesc(int id) const;
	proto_ff_s::attributesuppress_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::attributesuppress_s, MAX_ATTRIBUTE_SUPPRESS_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::attributesuppress_s, MAX_ATTRIBUTE_SUPPRESS_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::attributesuppress_s, attributesuppress, MAX_ATTRIBUTE_SUPPRESS_NUM);
DECLARE_IDCREATE(AttributeSuppressDesc);
};

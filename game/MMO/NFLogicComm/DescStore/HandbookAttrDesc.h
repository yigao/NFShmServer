#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/handbook_s.h"

#define MAX_HANDBOOK_ATTR_NUM 500

class HandbookAttrDesc : public NFIDescStore
{
public:
	HandbookAttrDesc(NFIPluginManager* pPluginManager);
	virtual ~HandbookAttrDesc();
	const proto_ff_s::handbookattr_s* GetDesc(int id) const;
	proto_ff_s::handbookattr_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::handbookattr_s, MAX_HANDBOOK_ATTR_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::handbookattr_s, MAX_HANDBOOK_ATTR_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::handbookattr_s, handbookattr, MAX_HANDBOOK_ATTR_NUM);
DECLARE_IDCREATE(HandbookAttrDesc);
};

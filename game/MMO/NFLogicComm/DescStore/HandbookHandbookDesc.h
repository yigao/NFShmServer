#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/handbook_s.h"

#define MAX_HANDBOOK_HANDBOOK_NUM 500

class HandbookHandbookDesc : public NFIDescStore
{
public:
	HandbookHandbookDesc(NFIPluginManager* pPluginManager);
	virtual ~HandbookHandbookDesc();
	const proto_ff_s::handbookhandbook_s* GetDesc(int id) const;
	proto_ff_s::handbookhandbook_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::handbookhandbook_s, MAX_HANDBOOK_HANDBOOK_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::handbookhandbook_s, MAX_HANDBOOK_HANDBOOK_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::handbookhandbook_s, handbookhandbook, MAX_HANDBOOK_HANDBOOK_NUM);
DECLARE_IDCREATE(HandbookHandbookDesc);
};

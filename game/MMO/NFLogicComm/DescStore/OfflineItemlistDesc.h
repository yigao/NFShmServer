#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/offline_s.h"

#define MAX_OFFLINE_ITEMLIST_NUM 60

class OfflineItemlistDesc : public NFIDescStore
{
public:
	OfflineItemlistDesc(NFIPluginManager* pPluginManager);
	virtual ~OfflineItemlistDesc();
	const proto_ff_s::offlineitemlist_s* GetDesc(int id) const;
	proto_ff_s::offlineitemlist_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::offlineitemlist_s, MAX_OFFLINE_ITEMLIST_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::offlineitemlist_s, MAX_OFFLINE_ITEMLIST_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::offlineitemlist_s, offlineitemlist, MAX_OFFLINE_ITEMLIST_NUM);
DECLARE_IDCREATE(OfflineItemlistDesc);
};

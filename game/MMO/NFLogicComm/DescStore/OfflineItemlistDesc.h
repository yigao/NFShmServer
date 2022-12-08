#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/offline_s.h"

#define MAX_OFFLINE_ITEMLIST_NUM 60

class OfflineItemlistDesc : public NFIDescStore
{
public:
	OfflineItemlistDesc();
	virtual ~OfflineItemlistDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::offlineitemlist_s* GetDesc(int id) const;
	proto_ff_s::offlineitemlist_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::offlineitemlist_s, offlineitemlist, MAX_OFFLINE_ITEMLIST_NUM);
DECLARE_IDCREATE(OfflineItemlistDesc);
};

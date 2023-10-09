#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Offline_s.h"

#define MAX_OFFLINE_ITEMLIST_NUM 32

class OfflineItemlistDesc : public NFIDescStore
{
public:
	OfflineItemlistDesc();
	virtual ~OfflineItemlistDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OfflineItemlist_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OfflineItemlist_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OfflineItemlist_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OfflineItemlist_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OfflineItemlistDesc, proto_ff_s::E_OfflineItemlist_s, E_OfflineItemlist, MAX_OFFLINE_ITEMLIST_NUM);
DECLARE_IDCREATE(OfflineItemlistDesc);
};

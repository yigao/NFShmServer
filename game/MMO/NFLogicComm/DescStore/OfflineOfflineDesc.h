#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/offline_s.h"

#define MAX_OFFLINE_OFFLINE_NUM 2000

class OfflineOfflineDesc : public NFIDescStore
{
public:
	OfflineOfflineDesc();
	virtual ~OfflineOfflineDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_OfflineOffline_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OfflineOffline_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OfflineOffline_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OfflineOffline_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_OfflineOffline_s, E_OfflineOffline, MAX_OFFLINE_OFFLINE_NUM);
DECLARE_IDCREATE(OfflineOfflineDesc);
};

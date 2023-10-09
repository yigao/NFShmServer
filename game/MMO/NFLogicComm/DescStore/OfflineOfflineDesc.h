#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Offline_s.h"

#define MAX_OFFLINE_OFFLINE_NUM 2048

class OfflineOfflineDesc : public NFIDescStore
{
public:
	OfflineOfflineDesc();
	virtual ~OfflineOfflineDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_OfflineOffline_s* GetDesc(int64_t id) const;
	proto_ff_s::E_OfflineOffline_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_OfflineOffline_s* GetDescByIndex(int index) const;
	proto_ff_s::E_OfflineOffline_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(OfflineOfflineDesc, proto_ff_s::E_OfflineOffline_s, E_OfflineOffline, MAX_OFFLINE_OFFLINE_NUM);
DECLARE_IDCREATE(OfflineOfflineDesc);
};

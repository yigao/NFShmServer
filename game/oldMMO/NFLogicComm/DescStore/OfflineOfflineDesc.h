#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/offline_s.h"

#define MAX_OFFLINE_OFFLINE_NUM 2000

class OfflineOfflineDesc : public NFIDescStore
{
public:
	OfflineOfflineDesc(NFIPluginManager* pPluginManager);
	virtual ~OfflineOfflineDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::offlineoffline_s* GetDesc(int id) const;
	proto_ff_s::offlineoffline_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::offlineoffline_s, MAX_OFFLINE_OFFLINE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::offlineoffline_s, MAX_OFFLINE_OFFLINE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::offlineoffline_s, offlineoffline, MAX_OFFLINE_OFFLINE_NUM);
DECLARE_IDCREATE(OfflineOfflineDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/collect_s.h"

#define MAX_COLLECT_COLLECT_NUM 60

class CollectCollectDesc : public NFIDescStore
{
public:
	CollectCollectDesc();
	virtual ~CollectCollectDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_CollectCollect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CollectCollect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CollectCollect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CollectCollect_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(CollectCollectDesc, proto_ff_s::E_CollectCollect_s, E_CollectCollect, MAX_COLLECT_COLLECT_NUM);
DECLARE_IDCREATE(CollectCollectDesc);
};

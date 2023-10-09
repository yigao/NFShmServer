#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/collect_s.h"

#define MAX_COLLECT_CONST_NUM 20

class CollectConstDesc : public NFIDescStore
{
public:
	CollectConstDesc();
	virtual ~CollectConstDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_CollectConst_s* GetDesc(int64_t id) const;
	proto_ff_s::E_CollectConst_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_CollectConst_s* GetDescByIndex(int index) const;
	proto_ff_s::E_CollectConst_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(CollectConstDesc, proto_ff_s::E_CollectConst_s, E_CollectConst, MAX_COLLECT_CONST_NUM);
DECLARE_IDCREATE(CollectConstDesc);
};

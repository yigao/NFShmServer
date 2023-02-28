#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_CollectConst_s* GetDesc(int id) const;
	proto_ff_s::E_CollectConst_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_CollectConst_s, E_CollectConst, MAX_COLLECT_CONST_NUM);
DECLARE_IDCREATE(CollectConstDesc);
};

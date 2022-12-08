#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dup_s.h"

#define MAX_DUP_BPLEVEL_NUM 1100

class DupBplevelDesc : public NFIDescStore
{
public:
	DupBplevelDesc();
	virtual ~DupBplevelDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::dupBPlevel_s* GetDesc(int id) const;
	proto_ff_s::dupBPlevel_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::dupBPlevel_s, dupBPlevel, MAX_DUP_BPLEVEL_NUM);
DECLARE_IDCREATE(DupBplevelDesc);
};

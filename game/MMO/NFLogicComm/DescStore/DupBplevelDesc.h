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
	const proto_ff_s::E_DupBplevel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupBplevel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupBplevel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupBplevel_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_DupBplevel_s, E_DupBplevel, MAX_DUP_BPLEVEL_NUM);
DECLARE_IDCREATE(DupBplevelDesc);
};

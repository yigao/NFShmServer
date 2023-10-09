#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_BPLEVEL_NUM 1024

class DupBplevelDesc : public NFIDescStore
{
public:
	DupBplevelDesc();
	virtual ~DupBplevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupBplevel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupBplevel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupBplevel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupBplevel_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupBplevelDesc, proto_ff_s::E_DupBplevel_s, E_DupBplevel, MAX_DUP_BPLEVEL_NUM);
DECLARE_IDCREATE(DupBplevelDesc);
};

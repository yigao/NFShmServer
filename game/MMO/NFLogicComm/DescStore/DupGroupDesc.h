#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/dup_s.h"

#define MAX_DUP_GROUP_NUM 20

class DupGroupDesc : public NFIDescStore
{
public:
	DupGroupDesc();
	virtual ~DupGroupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DupGroup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupGroup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupGroup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupGroup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DupGroupDesc, proto_ff_s::E_DupGroup_s, E_DupGroup, MAX_DUP_GROUP_NUM);
DECLARE_IDCREATE(DupGroupDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_GROUP_NUM 64

class DupGroupDesc : public NFIDescStore
{
public:
	DupGroupDesc();
	virtual ~DupGroupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupGroup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupGroup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupGroup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupGroup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupGroupDesc, proto_ff_s::E_DupGroup_s, E_DupGroup, MAX_DUP_GROUP_NUM);
DECLARE_IDCREATE(DupGroupDesc);
};

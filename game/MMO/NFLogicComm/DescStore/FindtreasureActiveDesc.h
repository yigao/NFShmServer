#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVE_NUM 8

class FindtreasureActiveDesc : public NFIDescStore
{
public:
	FindtreasureActiveDesc();
	virtual ~FindtreasureActiveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureActive_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureActive_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureActive_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureActive_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureActiveDesc, proto_ff_s::E_FindtreasureActive_s, E_FindtreasureActive, MAX_FINDTREASURE_ACTIVE_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureActiveDesc);
};

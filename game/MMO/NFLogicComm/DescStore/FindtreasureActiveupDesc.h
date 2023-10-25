#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVEUP_NUM 32

class FindtreasureActiveupDesc : public NFIDescStore
{
public:
	FindtreasureActiveupDesc();
	virtual ~FindtreasureActiveupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureActiveup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureActiveup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureActiveup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureActiveup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureActiveupDesc, proto_ff_s::E_FindtreasureActiveup_s, E_FindtreasureActiveup, MAX_FINDTREASURE_ACTIVEUP_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureActiveupDesc);
};

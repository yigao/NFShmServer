#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVESHOP_NUM 4

class FindtreasureActiveshopDesc : public NFIDescStore
{
public:
	FindtreasureActiveshopDesc();
	virtual ~FindtreasureActiveshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureActiveshop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureActiveshop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureActiveshop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureActiveshop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureActiveshopDesc, proto_ff_s::E_FindtreasureActiveshop_s, E_FindtreasureActiveshop, MAX_FINDTREASURE_ACTIVESHOP_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureActiveshopDesc);
};

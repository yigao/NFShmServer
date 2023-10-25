#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_ACTIVEGOODS_NUM 4

class FindtreasureActivegoodsDesc : public NFIDescStore
{
public:
	FindtreasureActivegoodsDesc();
	virtual ~FindtreasureActivegoodsDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureActivegoods_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureActivegoods_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureActivegoods_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureActivegoods_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureActivegoodsDesc, proto_ff_s::E_FindtreasureActivegoods_s, E_FindtreasureActivegoods, MAX_FINDTREASURE_ACTIVEGOODS_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureActivegoodsDesc);
};

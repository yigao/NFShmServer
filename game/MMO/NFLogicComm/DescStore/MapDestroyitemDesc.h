#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_DESTROYITEM_NUM 256

class MapDestroyitemDesc : public NFIDescStore
{
public:
	MapDestroyitemDesc();
	virtual ~MapDestroyitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MapDestroyitem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapDestroyitem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapDestroyitem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapDestroyitem_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MapDestroyitemDesc, proto_ff_s::E_MapDestroyitem_s, E_MapDestroyitem, MAX_MAP_DESTROYITEM_NUM);
DECLARE_IDCREATE(MapDestroyitemDesc);
};

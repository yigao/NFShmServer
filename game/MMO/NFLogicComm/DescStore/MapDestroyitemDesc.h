#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_DESTROYITEM_NUM 200

class MapDestroyitemDesc : public NFIDescStore
{
public:
	MapDestroyitemDesc();
	virtual ~MapDestroyitemDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MapDestroyitem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapDestroyitem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapDestroyitem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapDestroyitem_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MapDestroyitem_s, E_MapDestroyitem, MAX_MAP_DESTROYITEM_NUM);
DECLARE_IDCREATE(MapDestroyitemDesc);
};

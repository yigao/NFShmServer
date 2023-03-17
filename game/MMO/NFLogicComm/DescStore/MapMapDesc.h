#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_MAP_NUM 100

class MapMapDesc : public NFIDescStore
{
public:
	MapMapDesc();
	virtual ~MapMapDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MapMap_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapMap_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapMap_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapMap_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MapMapDesc, proto_ff_s::E_MapMap_s, E_MapMap, MAX_MAP_MAP_NUM);
DECLARE_IDCREATE(MapMapDesc);
};

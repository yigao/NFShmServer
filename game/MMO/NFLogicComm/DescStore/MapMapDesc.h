#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_MAP_NUM 128

class MapMapDesc : public NFIDescStore
{
public:
	MapMapDesc();
	virtual ~MapMapDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MapMap_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapMap_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapMap_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapMap_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MapMapDesc, proto_ff_s::E_MapMap_s, E_MapMap, MAX_MAP_MAP_NUM);
DECLARE_IDCREATE(MapMapDesc);
};

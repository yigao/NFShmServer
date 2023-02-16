#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_MAP_NUM 40

class MapMapDesc : public NFIDescStore
{
public:
	MapMapDesc();
	virtual ~MapMapDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MapMap_s* GetDesc(int id) const;
	proto_ff_s::E_MapMap_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MapMap_s, mapmap, MAX_MAP_MAP_NUM);
DECLARE_IDCREATE(MapMapDesc);
};

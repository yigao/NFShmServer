#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_INSPIRE_NUM 8

class MapInspireDesc : public NFIDescStore
{
public:
	MapInspireDesc();
	virtual ~MapInspireDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MapInspire_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapInspire_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapInspire_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapInspire_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MapInspireDesc, proto_ff_s::E_MapInspire_s, E_MapInspire, MAX_MAP_INSPIRE_NUM);
DECLARE_IDCREATE(MapInspireDesc);
};

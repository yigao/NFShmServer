#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Map_s.h"

#define MAX_MAP_ITEMDROP_NUM 32

class MapItemdropDesc : public NFIDescStore
{
public:
	MapItemdropDesc();
	virtual ~MapItemdropDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MapItemdrop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MapItemdrop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MapItemdrop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MapItemdrop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MapItemdropDesc, proto_ff_s::E_MapItemdrop_s, E_MapItemdrop, MAX_MAP_ITEMDROP_NUM);
DECLARE_IDCREATE(MapItemdropDesc);
};

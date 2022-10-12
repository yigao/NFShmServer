#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/map_s.h"

#define MAX_MAP_ITEMDROP_NUM 40

class MapItemdropDesc : public NFIDescStore
{
public:
	MapItemdropDesc(NFIPluginManager* pPluginManager);
	virtual ~MapItemdropDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::mapitemdrop_s* GetDesc(int id) const;
	proto_ff_s::mapitemdrop_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::mapitemdrop_s, MAX_MAP_ITEMDROP_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::mapitemdrop_s, MAX_MAP_ITEMDROP_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::mapitemdrop_s, mapitemdrop, MAX_MAP_ITEMDROP_NUM);
DECLARE_IDCREATE(MapItemdropDesc);
};

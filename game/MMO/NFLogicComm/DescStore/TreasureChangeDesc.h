#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_CHANGE_NUM 20

class TreasureChangeDesc : public NFIDescStore
{
public:
	TreasureChangeDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureChangeDesc();
	const proto_ff_s::treasurechange_s* GetDesc(int id) const;
	proto_ff_s::treasurechange_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasurechange_s, MAX_TREASURE_CHANGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasurechange_s, MAX_TREASURE_CHANGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasurechange_s, treasurechange, MAX_TREASURE_CHANGE_NUM);
DECLARE_IDCREATE(TreasureChangeDesc);
};

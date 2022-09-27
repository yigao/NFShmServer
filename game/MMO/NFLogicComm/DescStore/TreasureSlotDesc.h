#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/treasure_s.h"

#define MAX_TREASURE_SLOT_NUM 20

class TreasureSlotDesc : public NFIDescStore
{
public:
	TreasureSlotDesc(NFIPluginManager* pPluginManager);
	virtual ~TreasureSlotDesc();
	const proto_ff_s::treasureslot_s* GetDesc(int id) const;
	proto_ff_s::treasureslot_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::treasureslot_s, MAX_TREASURE_SLOT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::treasureslot_s, MAX_TREASURE_SLOT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::treasureslot_s, treasureslot, MAX_TREASURE_SLOT_NUM);
DECLARE_IDCREATE(TreasureSlotDesc);
};

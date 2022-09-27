#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_DISPLAY_NUM 300

class MonsterDisplayDesc : public NFIDescStore
{
public:
	MonsterDisplayDesc(NFIPluginManager* pPluginManager);
	virtual ~MonsterDisplayDesc();
	const proto_ff_s::monsterdisplay_s* GetDesc(int id) const;
	proto_ff_s::monsterdisplay_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::monsterdisplay_s, MAX_MONSTER_DISPLAY_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::monsterdisplay_s, MAX_MONSTER_DISPLAY_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::monsterdisplay_s, monsterdisplay, MAX_MONSTER_DISPLAY_NUM);
DECLARE_IDCREATE(MonsterDisplayDesc);
};

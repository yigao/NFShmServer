#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Godvalley_s.h"

#define MAX_GODVALLEY_BATTLE_NUM 20

class GodvalleyBattleDesc : public NFIDescStore
{
public:
	GodvalleyBattleDesc();
	virtual ~GodvalleyBattleDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodvalleyBattle_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodvalleyBattle_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodvalleyBattle_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodvalleyBattle_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodvalleyBattleDesc, proto_ff_s::E_GodvalleyBattle_s, E_GodvalleyBattle, MAX_GODVALLEY_BATTLE_NUM);
DECLARE_IDCREATE(GodvalleyBattleDesc);
};

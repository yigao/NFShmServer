#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_GodvalleyBattle_s* GetDesc(int id) const;
	proto_ff_s::E_GodvalleyBattle_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GodvalleyBattle_s, E_GodvalleyBattle, MAX_GODVALLEY_BATTLE_NUM);
DECLARE_IDCREATE(GodvalleyBattleDesc);
};

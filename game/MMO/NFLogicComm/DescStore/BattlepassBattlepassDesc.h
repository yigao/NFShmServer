#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_BATTLEPASS_NUM 16

class BattlepassBattlepassDesc : public NFIDescStore
{
public:
	BattlepassBattlepassDesc();
	virtual ~BattlepassBattlepassDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BattlepassBattlepass_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BattlepassBattlepass_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BattlepassBattlepass_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BattlepassBattlepass_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BattlepassBattlepassDesc, proto_ff_s::E_BattlepassBattlepass_s, E_BattlepassBattlepass, MAX_BATTLEPASS_BATTLEPASS_NUM);
DECLARE_IDCREATE(BattlepassBattlepassDesc);
};
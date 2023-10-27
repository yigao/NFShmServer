#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godvalley_s.h"

#define MAX_GODVALLEY_BATTLE_NUM 8

class GodvalleyBattleDesc : public NFIDescTemplate<GodvalleyBattleDesc, proto_ff_s::E_GodvalleyBattle_s, EOT_CONST_GODVALLEY_BATTLE_DESC_ID, MAX_GODVALLEY_BATTLE_NUM>
{
public:
	GodvalleyBattleDesc();
	virtual ~GodvalleyBattleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

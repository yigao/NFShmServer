#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tianxiafirst_s.h"

#define MAX_TIANXIAFIRST_BATTLE_NUM 8

class TianxiafirstBattleDesc : public NFIDescTemplate<TianxiafirstBattleDesc, proto_ff_s::E_TianxiafirstBattle_s, EOT_CONST_TIANXIAFIRST_BATTLE_DESC_ID, MAX_TIANXIAFIRST_BATTLE_NUM>
{
public:
	TianxiafirstBattleDesc();
	virtual ~TianxiafirstBattleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

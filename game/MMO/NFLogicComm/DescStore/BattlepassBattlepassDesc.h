#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_BATTLEPASS_NUM 16

class BattlepassBattlepassDesc : public NFIDescTemplate<BattlepassBattlepassDesc, proto_ff_s::E_BattlepassBattlepass_s, EOT_CONST_BATTLEPASS_BATTLEPASS_DESC_ID, MAX_BATTLEPASS_BATTLEPASS_NUM>
{
public:
	BattlepassBattlepassDesc();
	virtual ~BattlepassBattlepassDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

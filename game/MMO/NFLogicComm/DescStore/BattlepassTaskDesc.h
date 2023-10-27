#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Battlepass_s.h"

#define MAX_BATTLEPASS_TASK_NUM 32

class BattlepassTaskDesc : public NFIDescTemplate<BattlepassTaskDesc, proto_ff_s::E_BattlepassTask_s, EOT_CONST_BATTLEPASS_TASK_DESC_ID, MAX_BATTLEPASS_TASK_NUM>
{
public:
	BattlepassTaskDesc();
	virtual ~BattlepassTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

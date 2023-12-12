#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_UPGRADEEXP_NUM 512

class RuneUpgradeexpDesc : public NFIDescTemplate<RuneUpgradeexpDesc, proto_ff_s::E_RuneUpgradeexp_s, EOT_CONST_RUNE_UPGRADEEXP_DESC_ID, MAX_RUNE_UPGRADEEXP_NUM>
{
public:
	RuneUpgradeexpDesc();
	virtual ~RuneUpgradeexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

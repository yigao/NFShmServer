#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Rune_s.h"

#define MAX_RUNE_UPGRADE_NUM 32

class RuneUpgradeDesc : public NFIDescTemplate<RuneUpgradeDesc, proto_ff_s::E_RuneUpgrade_s, EOT_CONST_RUNE_UPGRADE_DESC_ID, MAX_RUNE_UPGRADE_NUM>
{
public:
	RuneUpgradeDesc();
	virtual ~RuneUpgradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

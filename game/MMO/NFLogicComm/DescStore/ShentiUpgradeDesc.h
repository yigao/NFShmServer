#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_UPGRADE_NUM 128

class ShentiUpgradeDesc : public NFIDescTemplate<ShentiUpgradeDesc, proto_ff_s::E_ShentiUpgrade_s, EOT_CONST_SHENTI_UPGRADE_DESC_ID, MAX_SHENTI_UPGRADE_NUM>
{
public:
	ShentiUpgradeDesc();
	virtual ~ShentiUpgradeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

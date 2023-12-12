#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_RAREITEM_NUM 1024

class BossRareitemDesc : public NFIDescTemplate<BossRareitemDesc, proto_ff_s::E_BossRareitem_s, EOT_CONST_BOSS_RAREITEM_DESC_ID, MAX_BOSS_RAREITEM_NUM>
{
public:
	BossRareitemDesc();
	virtual ~BossRareitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

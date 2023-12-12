#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_BOSSTYPE_NUM 16

class BossBosstypeDesc : public NFIDescTemplate<BossBosstypeDesc, proto_ff_s::E_BossBosstype_s, EOT_CONST_BOSS_BOSSTYPE_DESC_ID, MAX_BOSS_BOSSTYPE_NUM>
{
public:
	BossBosstypeDesc();
	virtual ~BossBosstypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

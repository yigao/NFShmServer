#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_BOSS_NUM 1024

class BossBossDesc : public NFIDescTemplate<BossBossDesc, proto_ff_s::E_BossBoss_s, EOT_CONST_BOSS_BOSS_DESC_ID, MAX_BOSS_BOSS_NUM>
{
public:
	BossBossDesc();
	virtual ~BossBossDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

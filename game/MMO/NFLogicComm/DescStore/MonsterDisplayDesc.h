#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_DISPLAY_NUM 256

class MonsterDisplayDesc : public NFIDescTemplate<MonsterDisplayDesc, proto_ff_s::E_MonsterDisplay_s, EOT_CONST_MONSTER_DISPLAY_DESC_ID, MAX_MONSTER_DISPLAY_NUM>
{
public:
	MonsterDisplayDesc();
	virtual ~MonsterDisplayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

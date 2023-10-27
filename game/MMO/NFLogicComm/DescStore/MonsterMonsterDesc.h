#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_MONSTER_NUM 2048

class MonsterMonsterDesc : public NFIDescTemplate<MonsterMonsterDesc, proto_ff_s::E_MonsterMonster_s, EOT_CONST_MONSTER_MONSTER_DESC_ID, MAX_MONSTER_MONSTER_NUM>
{
public:
	MonsterMonsterDesc();
	virtual ~MonsterMonsterDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

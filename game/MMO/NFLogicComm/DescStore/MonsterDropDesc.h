#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_DROP_NUM 512

class MonsterDropDesc : public NFIDescTemplate<MonsterDropDesc, proto_ff_s::E_MonsterDrop_s, EOT_CONST_MONSTER_DROP_DESC_ID, MAX_MONSTER_DROP_NUM>
{
public:
	MonsterDropDesc();
	virtual ~MonsterDropDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

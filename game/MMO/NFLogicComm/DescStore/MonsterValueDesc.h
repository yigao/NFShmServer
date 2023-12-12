#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_VALUE_NUM 8192

class MonsterValueDesc : public NFIDescTemplate<MonsterValueDesc, proto_ff_s::E_MonsterValue_s, EOT_CONST_MONSTER_VALUE_DESC_ID, MAX_MONSTER_VALUE_NUM>
{
public:
	MonsterValueDesc();
	virtual ~MonsterValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

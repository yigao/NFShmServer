#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_VALUEPARAM_NUM 128

class MonsterValueparamDesc : public NFIDescTemplate<MonsterValueparamDesc, proto_ff_s::E_MonsterValueparam_s, EOT_CONST_MONSTER_VALUEPARAM_DESC_ID, MAX_MONSTER_VALUEPARAM_NUM>
{
public:
	MonsterValueparamDesc();
	virtual ~MonsterValueparamDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

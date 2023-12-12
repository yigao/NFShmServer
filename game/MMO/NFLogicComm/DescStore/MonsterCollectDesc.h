#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_COLLECT_NUM 32

class MonsterCollectDesc : public NFIDescTemplate<MonsterCollectDesc, proto_ff_s::E_MonsterCollect_s, EOT_CONST_MONSTER_COLLECT_DESC_ID, MAX_MONSTER_COLLECT_NUM>
{
public:
	MonsterCollectDesc();
	virtual ~MonsterCollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

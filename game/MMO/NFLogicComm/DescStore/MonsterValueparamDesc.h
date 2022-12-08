#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/monster_s.h"

#define MAX_MONSTER_VALUEPARAM_NUM 20

class MonsterValueparamDesc : public NFIDescStore
{
public:
	MonsterValueparamDesc();
	virtual ~MonsterValueparamDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::monstervalueParam_s* GetDesc(int id) const;
	proto_ff_s::monstervalueParam_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::monstervalueParam_s, monstervalueParam, MAX_MONSTER_VALUEPARAM_NUM);
DECLARE_IDCREATE(MonsterValueparamDesc);
};

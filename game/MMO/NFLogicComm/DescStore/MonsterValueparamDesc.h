#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Monster_s.h"

#define MAX_MONSTER_VALUEPARAM_NUM 128

class MonsterValueparamDesc : public NFIDescStore
{
public:
	MonsterValueparamDesc();
	virtual ~MonsterValueparamDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MonsterValueparam_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MonsterValueparam_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MonsterValueparam_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MonsterValueparam_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MonsterValueparamDesc, proto_ff_s::E_MonsterValueparam_s, E_MonsterValueparam, MAX_MONSTER_VALUEPARAM_NUM);
DECLARE_IDCREATE(MonsterValueparamDesc);
};

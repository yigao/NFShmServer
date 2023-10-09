#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_STARVALUE_NUM 2048

class DragonStarvalueDesc : public NFIDescStore
{
public:
	DragonStarvalueDesc();
	virtual ~DragonStarvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonStarvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonStarvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonStarvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonStarvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonStarvalueDesc, proto_ff_s::E_DragonStarvalue_s, E_DragonStarvalue, MAX_DRAGON_STARVALUE_NUM);
DECLARE_IDCREATE(DragonStarvalueDesc);
};

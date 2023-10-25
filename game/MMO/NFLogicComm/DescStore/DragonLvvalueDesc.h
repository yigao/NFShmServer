#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_LVVALUE_NUM 1024

class DragonLvvalueDesc : public NFIDescStore
{
public:
	DragonLvvalueDesc();
	virtual ~DragonLvvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonLvvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonLvvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonLvvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonLvvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonLvvalueDesc, proto_ff_s::E_DragonLvvalue_s, E_DragonLvvalue, MAX_DRAGON_LVVALUE_NUM);
DECLARE_IDCREATE_GLOBAL(DragonLvvalueDesc);
};

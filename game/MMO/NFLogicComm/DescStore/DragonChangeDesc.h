#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dragon_s.h"

#define MAX_DRAGON_CHANGE_NUM 8

class DragonChangeDesc : public NFIDescStore
{
public:
	DragonChangeDesc();
	virtual ~DragonChangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DragonChange_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DragonChange_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DragonChange_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DragonChange_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DragonChangeDesc, proto_ff_s::E_DragonChange_s, E_DragonChange, MAX_DRAGON_CHANGE_NUM);
DECLARE_IDCREATE(DragonChangeDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_REMANIE_NUM 8

class ShentiRemanieDesc : public NFIDescStore
{
public:
	ShentiRemanieDesc();
	virtual ~ShentiRemanieDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiRemanie_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiRemanie_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiRemanie_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiRemanie_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiRemanieDesc, proto_ff_s::E_ShentiRemanie_s, E_ShentiRemanie, MAX_SHENTI_REMANIE_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiRemanieDesc);
};

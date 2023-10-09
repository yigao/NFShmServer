#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_SUIT_NUM 128

class ShentiSuitDesc : public NFIDescStore
{
public:
	ShentiSuitDesc();
	virtual ~ShentiSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiSuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiSuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiSuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiSuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiSuitDesc, proto_ff_s::E_ShentiSuit_s, E_ShentiSuit, MAX_SHENTI_SUIT_NUM);
DECLARE_IDCREATE(ShentiSuitDesc);
};

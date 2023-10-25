#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EVOLVE_NUM 256

class ShentiEvolveDesc : public NFIDescStore
{
public:
	ShentiEvolveDesc();
	virtual ~ShentiEvolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiEvolve_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiEvolve_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiEvolve_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiEvolve_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiEvolveDesc, proto_ff_s::E_ShentiEvolve_s, E_ShentiEvolve, MAX_SHENTI_EVOLVE_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiEvolveDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EVOLVEPROGRESS_NUM 256

class ShentiEvolveprogressDesc : public NFIDescStore
{
public:
	ShentiEvolveprogressDesc();
	virtual ~ShentiEvolveprogressDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiEvolveprogress_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiEvolveprogress_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiEvolveprogress_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiEvolveprogress_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiEvolveprogressDesc, proto_ff_s::E_ShentiEvolveprogress_s, E_ShentiEvolveprogress, MAX_SHENTI_EVOLVEPROGRESS_NUM);
DECLARE_IDCREATE(ShentiEvolveprogressDesc);
};

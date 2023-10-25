#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhen_s.h"

#define MAX_XIUZHEN_EVOLVE_NUM 512

class XiuzhenEvolveDesc : public NFIDescStore
{
public:
	XiuzhenEvolveDesc();
	virtual ~XiuzhenEvolveDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenEvolve_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenEvolve_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenEvolve_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenEvolve_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenEvolveDesc, proto_ff_s::E_XiuzhenEvolve_s, E_XiuzhenEvolve, MAX_XIUZHEN_EVOLVE_NUM);
DECLARE_IDCREATE_GLOBAL(XiuzhenEvolveDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_STRONG_NUM 512

class ShentiStrongDesc : public NFIDescStore
{
public:
	ShentiStrongDesc();
	virtual ~ShentiStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiStrong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiStrong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiStrong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiStrong_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiStrongDesc, proto_ff_s::E_ShentiStrong_s, E_ShentiStrong, MAX_SHENTI_STRONG_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiStrongDesc);
};

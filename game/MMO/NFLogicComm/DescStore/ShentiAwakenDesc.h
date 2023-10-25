#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_AWAKEN_NUM 64

class ShentiAwakenDesc : public NFIDescStore
{
public:
	ShentiAwakenDesc();
	virtual ~ShentiAwakenDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiAwaken_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiAwaken_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiAwaken_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiAwaken_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiAwakenDesc, proto_ff_s::E_ShentiAwaken_s, E_ShentiAwaken, MAX_SHENTI_AWAKEN_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiAwakenDesc);
};

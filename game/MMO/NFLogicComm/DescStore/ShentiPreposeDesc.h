#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_PREPOSE_NUM 8

class ShentiPreposeDesc : public NFIDescStore
{
public:
	ShentiPreposeDesc();
	virtual ~ShentiPreposeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiPrepose_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiPrepose_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiPrepose_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiPrepose_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiPreposeDesc, proto_ff_s::E_ShentiPrepose_s, E_ShentiPrepose, MAX_SHENTI_PREPOSE_NUM);
DECLARE_IDCREATE_GLOBAL(ShentiPreposeDesc);
};

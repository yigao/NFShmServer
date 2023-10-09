#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_CONSTANT_NUM 2

class ShentiConstantDesc : public NFIDescStore
{
public:
	ShentiConstantDesc();
	virtual ~ShentiConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiConstantDesc, proto_ff_s::E_ShentiConstant_s, E_ShentiConstant, MAX_SHENTI_CONSTANT_NUM);
DECLARE_IDCREATE(ShentiConstantDesc);
};

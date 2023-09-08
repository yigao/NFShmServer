#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Constant_s.h"

#define MAX_CONSTANT_CONSTANT_NUM 8

class ConstantConstantDesc : public NFIDescStore
{
public:
	ConstantConstantDesc();
	virtual ~ConstantConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ConstantConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConstantConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConstantConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConstantConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConstantConstantDesc, proto_ff_s::E_ConstantConstant_s, E_ConstantConstant, MAX_CONSTANT_CONSTANT_NUM);
DECLARE_IDCREATE(ConstantConstantDesc);
};

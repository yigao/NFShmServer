#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenworld_s.h"

#define MAX_XIUZHENWORLD_CONSTANT_NUM 4

class XiuzhenworldConstantDesc : public NFIDescStore
{
public:
	XiuzhenworldConstantDesc();
	virtual ~XiuzhenworldConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenworldConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenworldConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenworldConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenworldConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenworldConstantDesc, proto_ff_s::E_XiuzhenworldConstant_s, E_XiuzhenworldConstant, MAX_XIUZHENWORLD_CONSTANT_NUM);
DECLARE_IDCREATE(XiuzhenworldConstantDesc);
};

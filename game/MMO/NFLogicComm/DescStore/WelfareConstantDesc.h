#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_CONSTANT_NUM 2

class WelfareConstantDesc : public NFIDescStore
{
public:
	WelfareConstantDesc();
	virtual ~WelfareConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareConstantDesc, proto_ff_s::E_WelfareConstant_s, E_WelfareConstant, MAX_WELFARE_CONSTANT_NUM);
DECLARE_IDCREATE(WelfareConstantDesc);
};

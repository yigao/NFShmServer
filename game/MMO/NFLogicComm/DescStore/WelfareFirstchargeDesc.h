#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_FIRSTCHARGE_NUM 8

class WelfareFirstchargeDesc : public NFIDescStore
{
public:
	WelfareFirstchargeDesc();
	virtual ~WelfareFirstchargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareFirstcharge_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareFirstcharge_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareFirstcharge_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareFirstcharge_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareFirstchargeDesc, proto_ff_s::E_WelfareFirstcharge_s, E_WelfareFirstcharge, MAX_WELFARE_FIRSTCHARGE_NUM);
DECLARE_IDCREATE(WelfareFirstchargeDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_INVEST_NUM 8

class WelfareInvestDesc : public NFIDescStore
{
public:
	WelfareInvestDesc();
	virtual ~WelfareInvestDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareInvest_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareInvest_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareInvest_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareInvest_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareInvestDesc, proto_ff_s::E_WelfareInvest_s, E_WelfareInvest, MAX_WELFARE_INVEST_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareInvestDesc);
};

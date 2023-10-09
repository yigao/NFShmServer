#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Moneyreward_s.h"

#define MAX_MONEYREWARD_MONEYREWARD_NUM 4

class MoneyrewardMoneyrewardDesc : public NFIDescStore
{
public:
	MoneyrewardMoneyrewardDesc();
	virtual ~MoneyrewardMoneyrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MoneyrewardMoneyreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MoneyrewardMoneyreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MoneyrewardMoneyreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MoneyrewardMoneyreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MoneyrewardMoneyrewardDesc, proto_ff_s::E_MoneyrewardMoneyreward_s, E_MoneyrewardMoneyreward, MAX_MONEYREWARD_MONEYREWARD_NUM);
DECLARE_IDCREATE(MoneyrewardMoneyrewardDesc);
};

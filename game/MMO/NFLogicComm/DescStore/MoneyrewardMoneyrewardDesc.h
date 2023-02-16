#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/moneyReward_s.h"

#define MAX_MONEYREWARD_MONEYREWARD_NUM 20

class MoneyrewardMoneyrewardDesc : public NFIDescStore
{
public:
	MoneyrewardMoneyrewardDesc();
	virtual ~MoneyrewardMoneyrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MoneyrewardMoneyreward_s* GetDesc(int id) const;
	proto_ff_s::E_MoneyrewardMoneyreward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MoneyrewardMoneyreward_s, E_MoneyrewardMoneyreward, MAX_MONEYREWARD_MONEYREWARD_NUM);
DECLARE_IDCREATE(MoneyrewardMoneyrewardDesc);
};

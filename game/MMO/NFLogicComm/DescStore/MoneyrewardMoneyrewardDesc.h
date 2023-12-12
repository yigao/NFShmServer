#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Moneyreward_s.h"

#define MAX_MONEYREWARD_MONEYREWARD_NUM 4

class MoneyrewardMoneyrewardDesc : public NFIDescTemplate<MoneyrewardMoneyrewardDesc, proto_ff_s::E_MoneyrewardMoneyreward_s, EOT_CONST_MONEYREWARD_MONEYREWARD_DESC_ID, MAX_MONEYREWARD_MONEYREWARD_NUM>
{
public:
	MoneyrewardMoneyrewardDesc();
	virtual ~MoneyrewardMoneyrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

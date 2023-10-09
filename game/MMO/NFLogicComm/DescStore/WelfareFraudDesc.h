#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_FRAUD_NUM 16

class WelfareFraudDesc : public NFIDescStore
{
public:
	WelfareFraudDesc();
	virtual ~WelfareFraudDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareFraud_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareFraud_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareFraud_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareFraud_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareFraudDesc, proto_ff_s::E_WelfareFraud_s, E_WelfareFraud, MAX_WELFARE_FRAUD_NUM);
DECLARE_IDCREATE(WelfareFraudDesc);
};

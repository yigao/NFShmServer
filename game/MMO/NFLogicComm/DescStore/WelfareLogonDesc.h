#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LOGON_NUM 16

class WelfareLogonDesc : public NFIDescStore
{
public:
	WelfareLogonDesc();
	virtual ~WelfareLogonDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareLogon_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareLogon_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareLogon_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareLogon_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareLogonDesc, proto_ff_s::E_WelfareLogon_s, E_WelfareLogon, MAX_WELFARE_LOGON_NUM);
DECLARE_IDCREATE(WelfareLogonDesc);
};

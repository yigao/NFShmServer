#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_ONLINE_NUM 8

class WelfareOnlineDesc : public NFIDescStore
{
public:
	WelfareOnlineDesc();
	virtual ~WelfareOnlineDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareOnline_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareOnline_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareOnline_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareOnline_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareOnlineDesc, proto_ff_s::E_WelfareOnline_s, E_WelfareOnline, MAX_WELFARE_ONLINE_NUM);
DECLARE_IDCREATE(WelfareOnlineDesc);
};

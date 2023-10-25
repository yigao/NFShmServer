#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCRAFFLE_NUM 8

class WelfareLcraffleDesc : public NFIDescStore
{
public:
	WelfareLcraffleDesc();
	virtual ~WelfareLcraffleDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareLcraffle_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareLcraffle_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareLcraffle_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareLcraffle_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareLcraffleDesc, proto_ff_s::E_WelfareLcraffle_s, E_WelfareLcraffle, MAX_WELFARE_LCRAFFLE_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareLcraffleDesc);
};

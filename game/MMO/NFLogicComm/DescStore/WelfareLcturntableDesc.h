#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCTURNTABLE_NUM 4

class WelfareLcturntableDesc : public NFIDescStore
{
public:
	WelfareLcturntableDesc();
	virtual ~WelfareLcturntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareLcturntable_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareLcturntable_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareLcturntable_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareLcturntable_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareLcturntableDesc, proto_ff_s::E_WelfareLcturntable_s, E_WelfareLcturntable, MAX_WELFARE_LCTURNTABLE_NUM);
DECLARE_IDCREATE(WelfareLcturntableDesc);
};

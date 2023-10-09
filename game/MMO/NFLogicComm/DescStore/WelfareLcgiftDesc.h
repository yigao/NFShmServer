#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCGIFT_NUM 32

class WelfareLcgiftDesc : public NFIDescStore
{
public:
	WelfareLcgiftDesc();
	virtual ~WelfareLcgiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareLcgift_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareLcgift_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareLcgift_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareLcgift_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareLcgiftDesc, proto_ff_s::E_WelfareLcgift_s, E_WelfareLcgift, MAX_WELFARE_LCGIFT_NUM);
DECLARE_IDCREATE(WelfareLcgiftDesc);
};

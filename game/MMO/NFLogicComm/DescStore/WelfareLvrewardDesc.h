#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LVREWARD_NUM 64

class WelfareLvrewardDesc : public NFIDescStore
{
public:
	WelfareLvrewardDesc();
	virtual ~WelfareLvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareLvreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareLvreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareLvreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareLvreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareLvrewardDesc, proto_ff_s::E_WelfareLvreward_s, E_WelfareLvreward, MAX_WELFARE_LVREWARD_NUM);
DECLARE_IDCREATE(WelfareLvrewardDesc);
};

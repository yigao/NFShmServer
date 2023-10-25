#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_INVESTREWARD_NUM 64

class WelfareInvestrewardDesc : public NFIDescStore
{
public:
	WelfareInvestrewardDesc();
	virtual ~WelfareInvestrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareInvestreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareInvestreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareInvestreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareInvestreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareInvestrewardDesc, proto_ff_s::E_WelfareInvestreward_s, E_WelfareInvestreward, MAX_WELFARE_INVESTREWARD_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareInvestrewardDesc);
};

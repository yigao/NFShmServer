#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_GOALTASK_NUM 16

class WelfareGoaltaskDesc : public NFIDescStore
{
public:
	WelfareGoaltaskDesc();
	virtual ~WelfareGoaltaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareGoaltask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareGoaltask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareGoaltask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareGoaltask_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareGoaltaskDesc, proto_ff_s::E_WelfareGoaltask_s, E_WelfareGoaltask, MAX_WELFARE_GOALTASK_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareGoaltaskDesc);
};

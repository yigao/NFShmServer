#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_YTTLGIFT_NUM 4

class WelfareYttlgiftDesc : public NFIDescStore
{
public:
	WelfareYttlgiftDesc();
	virtual ~WelfareYttlgiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareYttlgift_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareYttlgift_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareYttlgift_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareYttlgift_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareYttlgiftDesc, proto_ff_s::E_WelfareYttlgift_s, E_WelfareYttlgift, MAX_WELFARE_YTTLGIFT_NUM);
DECLARE_IDCREATE(WelfareYttlgiftDesc);
};

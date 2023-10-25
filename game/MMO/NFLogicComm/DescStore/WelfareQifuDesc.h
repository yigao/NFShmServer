#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_QIFU_NUM 16

class WelfareQifuDesc : public NFIDescStore
{
public:
	WelfareQifuDesc();
	virtual ~WelfareQifuDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareQifu_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareQifu_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareQifu_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareQifu_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareQifuDesc, proto_ff_s::E_WelfareQifu_s, E_WelfareQifu, MAX_WELFARE_QIFU_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareQifuDesc);
};

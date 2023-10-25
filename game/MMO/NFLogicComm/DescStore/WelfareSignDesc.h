#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_SIGN_NUM 128

class WelfareSignDesc : public NFIDescStore
{
public:
	WelfareSignDesc();
	virtual ~WelfareSignDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareSign_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareSign_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareSign_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareSign_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareSignDesc, proto_ff_s::E_WelfareSign_s, E_WelfareSign, MAX_WELFARE_SIGN_NUM);
DECLARE_IDCREATE_GLOBAL(WelfareSignDesc);
};

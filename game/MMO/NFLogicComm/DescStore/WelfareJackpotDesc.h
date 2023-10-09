#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_JACKPOT_NUM 64

class WelfareJackpotDesc : public NFIDescStore
{
public:
	WelfareJackpotDesc();
	virtual ~WelfareJackpotDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareJackpot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareJackpot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareJackpot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareJackpot_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareJackpotDesc, proto_ff_s::E_WelfareJackpot_s, E_WelfareJackpot, MAX_WELFARE_JACKPOT_NUM);
DECLARE_IDCREATE(WelfareJackpotDesc);
};

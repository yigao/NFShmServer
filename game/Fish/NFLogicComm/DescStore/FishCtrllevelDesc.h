#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Fish_s.h"

#define MAX_FISH_CTRLLEVEL_NUM 16

class FishCtrllevelDesc : public NFIDescStore
{
public:
	FishCtrllevelDesc();
	virtual ~FishCtrllevelDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FishCtrllevel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FishCtrllevel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FishCtrllevel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FishCtrllevel_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FishCtrllevelDesc, proto_ff_s::E_FishCtrllevel_s, E_FishCtrllevel, MAX_FISH_CTRLLEVEL_NUM);
DECLARE_IDCREATE(FishCtrllevelDesc);
};

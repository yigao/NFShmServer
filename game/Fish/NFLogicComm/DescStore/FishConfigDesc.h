#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fish_s.h"

#define MAX_FISH_CONFIG_NUM 64

class FishConfigDesc : public NFIDescStore
{
public:
	FishConfigDesc();
	virtual ~FishConfigDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FishConfig_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FishConfig_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FishConfig_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FishConfig_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FishConfigDesc, proto_ff_s::E_FishConfig_s, E_FishConfig, MAX_FISH_CONFIG_NUM);
DECLARE_IDCREATE(FishConfigDesc);
};

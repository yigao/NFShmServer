#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Escort_s.h"

#define MAX_ESCORT_CHANCE_NUM 4

class EscortChanceDesc : public NFIDescStore
{
public:
	EscortChanceDesc();
	virtual ~EscortChanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EscortChance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EscortChance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EscortChance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EscortChance_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EscortChanceDesc, proto_ff_s::E_EscortChance_s, E_EscortChance, MAX_ESCORT_CHANCE_NUM);
DECLARE_IDCREATE(EscortChanceDesc);
};

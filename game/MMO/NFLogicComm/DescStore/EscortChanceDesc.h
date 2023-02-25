#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/escort_s.h"

#define MAX_ESCORT_CHANCE_NUM 20

class EscortChanceDesc : public NFIDescStore
{
public:
	EscortChanceDesc();
	virtual ~EscortChanceDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EscortChance_s* GetDesc(int id) const;
	proto_ff_s::E_EscortChance_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EscortChance_s, E_EscortChance, MAX_ESCORT_CHANCE_NUM);
DECLARE_IDCREATE(EscortChanceDesc);
};
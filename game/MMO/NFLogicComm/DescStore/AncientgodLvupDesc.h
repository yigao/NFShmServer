#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_LVUP_NUM 2048

class AncientgodLvupDesc : public NFIDescStore
{
public:
	AncientgodLvupDesc();
	virtual ~AncientgodLvupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodLvup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodLvup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodLvup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodLvup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodLvupDesc, proto_ff_s::E_AncientgodLvup_s, E_AncientgodLvup, MAX_ANCIENTGOD_LVUP_NUM);
DECLARE_IDCREATE(AncientgodLvupDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ANCIENTGOD_NUM 16

class AncientgodAncientgodDesc : public NFIDescStore
{
public:
	AncientgodAncientgodDesc();
	virtual ~AncientgodAncientgodDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodAncientgod_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodAncientgod_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodAncientgod_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodAncientgod_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodAncientgodDesc, proto_ff_s::E_AncientgodAncientgod_s, E_AncientgodAncientgod, MAX_ANCIENTGOD_ANCIENTGOD_NUM);
DECLARE_IDCREATE(AncientgodAncientgodDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_BLESS_NUM 128

class AncientgodBlessDesc : public NFIDescStore
{
public:
	AncientgodBlessDesc();
	virtual ~AncientgodBlessDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodBless_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodBless_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodBless_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodBless_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodBlessDesc, proto_ff_s::E_AncientgodBless_s, E_AncientgodBless, MAX_ANCIENTGOD_BLESS_NUM);
DECLARE_IDCREATE(AncientgodBlessDesc);
};

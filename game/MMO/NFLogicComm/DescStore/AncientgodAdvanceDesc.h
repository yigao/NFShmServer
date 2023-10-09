#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_ADVANCE_NUM 128

class AncientgodAdvanceDesc : public NFIDescStore
{
public:
	AncientgodAdvanceDesc();
	virtual ~AncientgodAdvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodAdvance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodAdvance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodAdvance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodAdvance_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodAdvanceDesc, proto_ff_s::E_AncientgodAdvance_s, E_AncientgodAdvance, MAX_ANCIENTGOD_ADVANCE_NUM);
DECLARE_IDCREATE(AncientgodAdvanceDesc);
};

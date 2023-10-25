#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ancientgod_s.h"

#define MAX_ANCIENTGOD_STARCOLLECT_NUM 1024

class AncientgodStarcollectDesc : public NFIDescStore
{
public:
	AncientgodStarcollectDesc();
	virtual ~AncientgodStarcollectDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AncientgodStarcollect_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AncientgodStarcollect_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AncientgodStarcollect_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AncientgodStarcollect_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AncientgodStarcollectDesc, proto_ff_s::E_AncientgodStarcollect_s, E_AncientgodStarcollect, MAX_ANCIENTGOD_STARCOLLECT_NUM);
DECLARE_IDCREATE_GLOBAL(AncientgodStarcollectDesc);
};

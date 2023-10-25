#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_SJ_NUM 64

class ConflateJewelry_sjDesc : public NFIDescStore
{
public:
	ConflateJewelry_sjDesc();
	virtual ~ConflateJewelry_sjDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateJewelry_sj_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateJewelry_sj_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateJewelry_sj_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateJewelry_sj_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateJewelry_sjDesc, proto_ff_s::E_ConflateJewelry_sj_s, E_ConflateJewelry_sj, MAX_CONFLATE_JEWELRY_SJ_NUM);
DECLARE_IDCREATE_GLOBAL(ConflateJewelry_sjDesc);
};

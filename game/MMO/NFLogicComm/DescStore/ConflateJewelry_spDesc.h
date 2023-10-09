#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_SP_NUM 32

class ConflateJewelry_spDesc : public NFIDescStore
{
public:
	ConflateJewelry_spDesc();
	virtual ~ConflateJewelry_spDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateJewelry_sp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateJewelry_sp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateJewelry_sp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateJewelry_sp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateJewelry_spDesc, proto_ff_s::E_ConflateJewelry_sp_s, E_ConflateJewelry_sp, MAX_CONFLATE_JEWELRY_SP_NUM);
DECLARE_IDCREATE(ConflateJewelry_spDesc);
};

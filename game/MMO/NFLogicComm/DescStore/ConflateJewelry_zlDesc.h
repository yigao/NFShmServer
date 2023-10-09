#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_JEWELRY_ZL_NUM 64

class ConflateJewelry_zlDesc : public NFIDescStore
{
public:
	ConflateJewelry_zlDesc();
	virtual ~ConflateJewelry_zlDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateJewelry_zl_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateJewelry_zl_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateJewelry_zl_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateJewelry_zl_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateJewelry_zlDesc, proto_ff_s::E_ConflateJewelry_zl_s, E_ConflateJewelry_zl, MAX_CONFLATE_JEWELRY_ZL_NUM);
DECLARE_IDCREATE(ConflateJewelry_zlDesc);
};

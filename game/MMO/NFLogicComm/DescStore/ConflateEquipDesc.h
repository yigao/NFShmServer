#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_EQUIP_NUM 2048

class ConflateEquipDesc : public NFIDescStore
{
public:
	ConflateEquipDesc();
	virtual ~ConflateEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateEquip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateEquip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateEquip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateEquip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateEquipDesc, proto_ff_s::E_ConflateEquip_s, E_ConflateEquip, MAX_CONFLATE_EQUIP_NUM);
DECLARE_IDCREATE(ConflateEquipDesc);
};

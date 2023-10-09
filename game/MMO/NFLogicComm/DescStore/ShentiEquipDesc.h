#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_EQUIP_NUM 1024

class ShentiEquipDesc : public NFIDescStore
{
public:
	ShentiEquipDesc();
	virtual ~ShentiEquipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiEquip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiEquip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiEquip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiEquip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiEquipDesc, proto_ff_s::E_ShentiEquip_s, E_ShentiEquip, MAX_SHENTI_EQUIP_NUM);
DECLARE_IDCREATE(ShentiEquipDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_ATTRIBUTE_NUM 16384

class EquipAttributeDesc : public NFIDescStore
{
public:
	EquipAttributeDesc();
	virtual ~EquipAttributeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipAttribute_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipAttribute_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipAttribute_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipAttribute_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipAttributeDesc, proto_ff_s::E_EquipAttribute_s, E_EquipAttribute, MAX_EQUIP_ATTRIBUTE_NUM);
DECLARE_IDCREATE(EquipAttributeDesc);
};

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_ATTRIBUTE_NUM 11000

class EquipAttributeDesc : public NFIDescStore
{
public:
	EquipAttributeDesc();
	virtual ~EquipAttributeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipAttribute_s* GetDesc(int id) const;
	proto_ff_s::E_EquipAttribute_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipAttribute_s, E_EquipAttribute, MAX_EQUIP_ATTRIBUTE_NUM);
DECLARE_IDCREATE(EquipAttributeDesc);
};

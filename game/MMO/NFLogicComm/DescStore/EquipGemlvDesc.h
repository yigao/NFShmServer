#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_GEMLV_NUM 300

class EquipGemlvDesc : public NFIDescStore
{
public:
	EquipGemlvDesc();
	virtual ~EquipGemlvDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipGemlv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipGemlv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipGemlv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipGemlv_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipGemlv_s, E_EquipGemlv, MAX_EQUIP_GEMLV_NUM);
DECLARE_IDCREATE(EquipGemlvDesc);
};

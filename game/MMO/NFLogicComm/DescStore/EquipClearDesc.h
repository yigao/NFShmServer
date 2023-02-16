#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_CLEAR_NUM 20

class EquipClearDesc : public NFIDescStore
{
public:
	EquipClearDesc();
	virtual ~EquipClearDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipClear_s* GetDesc(int id) const;
	proto_ff_s::E_EquipClear_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipClear_s, E_EquipClear, MAX_EQUIP_CLEAR_NUM);
DECLARE_IDCREATE(EquipClearDesc);
};

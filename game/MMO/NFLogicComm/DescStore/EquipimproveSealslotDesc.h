#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEALSLOT_NUM 64

class EquipimproveSealslotDesc : public NFIDescStore
{
public:
	EquipimproveSealslotDesc();
	virtual ~EquipimproveSealslotDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipimproveSealslot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipimproveSealslot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipimproveSealslot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipimproveSealslot_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipimproveSealslotDesc, proto_ff_s::E_EquipimproveSealslot_s, E_EquipimproveSealslot, MAX_EQUIPIMPROVE_SEALSLOT_NUM);
DECLARE_IDCREATE_GLOBAL(EquipimproveSealslotDesc);
};

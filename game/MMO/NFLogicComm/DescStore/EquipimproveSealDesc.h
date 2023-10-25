#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equipimprove_s.h"

#define MAX_EQUIPIMPROVE_SEAL_NUM 16

class EquipimproveSealDesc : public NFIDescStore
{
public:
	EquipimproveSealDesc();
	virtual ~EquipimproveSealDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipimproveSeal_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipimproveSeal_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipimproveSeal_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipimproveSeal_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipimproveSealDesc, proto_ff_s::E_EquipimproveSeal_s, E_EquipimproveSeal, MAX_EQUIPIMPROVE_SEAL_NUM);
DECLARE_IDCREATE_GLOBAL(EquipimproveSealDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_SUIT_NUM 64

class EquipSuitDesc : public NFIDescStore
{
public:
	EquipSuitDesc();
	virtual ~EquipSuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipSuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipSuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipSuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipSuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipSuitDesc, proto_ff_s::E_EquipSuit_s, E_EquipSuit, MAX_EQUIP_SUIT_NUM);
DECLARE_IDCREATE(EquipSuitDesc);
};

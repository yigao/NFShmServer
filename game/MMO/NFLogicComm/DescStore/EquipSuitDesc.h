#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_SUIT_NUM 80

class EquipSuitDesc : public NFIDescStore
{
public:
	EquipSuitDesc();
	virtual ~EquipSuitDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipSuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipSuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipSuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipSuit_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EquipSuitDesc, proto_ff_s::E_EquipSuit_s, E_EquipSuit, MAX_EQUIP_SUIT_NUM);
DECLARE_IDCREATE(EquipSuitDesc);
};

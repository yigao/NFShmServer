#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_BREAK_NUM 32

class EquipBreakDesc : public NFIDescStore
{
public:
	EquipBreakDesc();
	virtual ~EquipBreakDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipBreak_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipBreak_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipBreak_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipBreak_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipBreakDesc, proto_ff_s::E_EquipBreak_s, E_EquipBreak, MAX_EQUIP_BREAK_NUM);
DECLARE_IDCREATE(EquipBreakDesc);
};

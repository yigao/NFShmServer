#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_BREAK_NUM 60

class EquipBreakDesc : public NFIDescStore
{
public:
	EquipBreakDesc();
	virtual ~EquipBreakDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipBreak_s* GetDesc(int id) const;
	proto_ff_s::E_EquipBreak_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_EquipBreak_s, E_EquipBreak, MAX_EQUIP_BREAK_NUM);
DECLARE_IDCREATE(EquipBreakDesc);
};
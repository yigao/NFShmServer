#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/equip_s.h"

#define MAX_EQUIP_STRONG_NUM 500

class EquipStrongDesc : public NFIDescStore
{
public:
	EquipStrongDesc();
	virtual ~EquipStrongDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_EquipStrong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStrong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStrong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStrong_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(EquipStrongDesc, proto_ff_s::E_EquipStrong_s, E_EquipStrong, MAX_EQUIP_STRONG_NUM);
DECLARE_IDCREATE(EquipStrongDesc);
};

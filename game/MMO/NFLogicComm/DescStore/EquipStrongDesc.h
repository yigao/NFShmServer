#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Equip_s.h"

#define MAX_EQUIP_STRONG_NUM 512

class EquipStrongDesc : public NFIDescStore
{
public:
	EquipStrongDesc();
	virtual ~EquipStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_EquipStrong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_EquipStrong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_EquipStrong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_EquipStrong_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(EquipStrongDesc, proto_ff_s::E_EquipStrong_s, E_EquipStrong, MAX_EQUIP_STRONG_NUM);
DECLARE_IDCREATE_GLOBAL(EquipStrongDesc);
};

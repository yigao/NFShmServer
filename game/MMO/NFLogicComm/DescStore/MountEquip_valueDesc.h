#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIP_VALUE_NUM 4096

class MountEquip_valueDesc : public NFIDescStore
{
public:
	MountEquip_valueDesc();
	virtual ~MountEquip_valueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEquip_value_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEquip_value_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEquip_value_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEquip_value_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEquip_valueDesc, proto_ff_s::E_MountEquip_value_s, E_MountEquip_value, MAX_MOUNT_EQUIP_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(MountEquip_valueDesc);
};

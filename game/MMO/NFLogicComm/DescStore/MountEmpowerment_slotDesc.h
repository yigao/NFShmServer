#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EMPOWERMENT_SLOT_NUM 16

class MountEmpowerment_slotDesc : public NFIDescStore
{
public:
	MountEmpowerment_slotDesc();
	virtual ~MountEmpowerment_slotDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEmpowerment_slot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEmpowerment_slot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEmpowerment_slot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEmpowerment_slot_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEmpowerment_slotDesc, proto_ff_s::E_MountEmpowerment_slot_s, E_MountEmpowerment_slot, MAX_MOUNT_EMPOWERMENT_SLOT_NUM);
DECLARE_IDCREATE_GLOBAL(MountEmpowerment_slotDesc);
};

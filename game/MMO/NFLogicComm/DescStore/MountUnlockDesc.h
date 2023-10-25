#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_UNLOCK_NUM 8

class MountUnlockDesc : public NFIDescStore
{
public:
	MountUnlockDesc();
	virtual ~MountUnlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountUnlock_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountUnlock_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountUnlock_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountUnlock_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountUnlockDesc, proto_ff_s::E_MountUnlock_s, E_MountUnlock, MAX_MOUNT_UNLOCK_NUM);
DECLARE_IDCREATE_GLOBAL(MountUnlockDesc);
};

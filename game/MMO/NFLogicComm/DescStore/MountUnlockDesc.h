#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_UNLOCK_NUM 20

class MountUnlockDesc : public NFIDescStore
{
public:
	MountUnlockDesc();
	virtual ~MountUnlockDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountUnlock_s* GetDesc(int id) const;
	proto_ff_s::E_MountUnlock_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountUnlock_s, E_MountUnlock, MAX_MOUNT_UNLOCK_NUM);
DECLARE_IDCREATE(MountUnlockDesc);
};
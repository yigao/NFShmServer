#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_BLOOD_NUM 300

class MountBloodDesc : public NFIDescStore
{
public:
	MountBloodDesc();
	virtual ~MountBloodDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountBlood_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountBlood_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountBlood_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountBlood_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MountBloodDesc, proto_ff_s::E_MountBlood_s, E_MountBlood, MAX_MOUNT_BLOOD_NUM);
DECLARE_IDCREATE(MountBloodDesc);
};

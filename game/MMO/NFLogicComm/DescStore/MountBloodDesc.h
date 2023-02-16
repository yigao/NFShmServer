#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_MountBlood_s* GetDesc(int id) const;
	proto_ff_s::E_MountBlood_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountBlood_s, E_MountBlood, MAX_MOUNT_BLOOD_NUM);
DECLARE_IDCREATE(MountBloodDesc);
};

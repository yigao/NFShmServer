#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_VALUE_NUM 300

class MountValueDesc : public NFIDescStore
{
public:
	MountValueDesc();
	virtual ~MountValueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountValue_s* GetDesc(int id) const;
	proto_ff_s::E_MountValue_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountValue_s, E_MountValue, MAX_MOUNT_VALUE_NUM);
DECLARE_IDCREATE(MountValueDesc);
};

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_DISPLAY_NUM 20

class MountDisplayDesc : public NFIDescStore
{
public:
	MountDisplayDesc();
	virtual ~MountDisplayDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountDisplay_s* GetDesc(int id) const;
	proto_ff_s::E_MountDisplay_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountDisplay_s, E_MountDisplay, MAX_MOUNT_DISPLAY_NUM);
DECLARE_IDCREATE(MountDisplayDesc);
};

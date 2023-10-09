#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
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
	const proto_ff_s::E_MountDisplay_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountDisplay_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountDisplay_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountDisplay_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MountDisplayDesc, proto_ff_s::E_MountDisplay_s, E_MountDisplay, MAX_MOUNT_DISPLAY_NUM);
DECLARE_IDCREATE(MountDisplayDesc);
};

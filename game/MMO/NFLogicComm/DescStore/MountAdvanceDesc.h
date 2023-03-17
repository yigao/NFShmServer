#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_ADVANCE_NUM 20

class MountAdvanceDesc : public NFIDescStore
{
public:
	MountAdvanceDesc();
	virtual ~MountAdvanceDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountAdvance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountAdvance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountAdvance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountAdvance_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MountAdvanceDesc, proto_ff_s::E_MountAdvance_s, E_MountAdvance, MAX_MOUNT_ADVANCE_NUM);
DECLARE_IDCREATE(MountAdvanceDesc);
};

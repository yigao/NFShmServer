#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_ADVANCE_NUM 64

class MountAdvanceDesc : public NFIDescStore
{
public:
	MountAdvanceDesc();
	virtual ~MountAdvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountAdvance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountAdvance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountAdvance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountAdvance_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountAdvanceDesc, proto_ff_s::E_MountAdvance_s, E_MountAdvance, MAX_MOUNT_ADVANCE_NUM);
DECLARE_IDCREATE(MountAdvanceDesc);
};

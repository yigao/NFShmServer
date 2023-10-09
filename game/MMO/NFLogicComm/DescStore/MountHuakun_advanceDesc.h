#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_ADVANCE_NUM 128

class MountHuakun_advanceDesc : public NFIDescStore
{
public:
	MountHuakun_advanceDesc();
	virtual ~MountHuakun_advanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountHuakun_advance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_advance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_advance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_advance_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountHuakun_advanceDesc, proto_ff_s::E_MountHuakun_advance_s, E_MountHuakun_advance, MAX_MOUNT_HUAKUN_ADVANCE_NUM);
DECLARE_IDCREATE(MountHuakun_advanceDesc);
};

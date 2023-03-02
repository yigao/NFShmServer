#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM 20

class MountHuakun_advancevalueDesc : public NFIDescStore
{
public:
	MountHuakun_advancevalueDesc();
	virtual ~MountHuakun_advancevalueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountHuakun_advancevalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_advancevalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_advancevalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_advancevalue_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountHuakun_advancevalue_s, E_MountHuakun_advancevalue, MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM);
DECLARE_IDCREATE(MountHuakun_advancevalueDesc);
};

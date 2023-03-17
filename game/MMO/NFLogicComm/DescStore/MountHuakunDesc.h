#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_HUAKUN_NUM 20

class MountHuakunDesc : public NFIDescStore
{
public:
	MountHuakunDesc();
	virtual ~MountHuakunDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountHuakun_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MountHuakunDesc, proto_ff_s::E_MountHuakun_s, E_MountHuakun, MAX_MOUNT_HUAKUN_NUM);
DECLARE_IDCREATE(MountHuakunDesc);
};

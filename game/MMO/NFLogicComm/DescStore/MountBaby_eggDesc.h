#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mount_s.h"

#define MAX_MOUNT_BABY_EGG_NUM 20

class MountBaby_eggDesc : public NFIDescStore
{
public:
	MountBaby_eggDesc();
	virtual ~MountBaby_eggDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MountBaby_egg_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountBaby_egg_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountBaby_egg_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountBaby_egg_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_MountBaby_egg_s, E_MountBaby_egg, MAX_MOUNT_BABY_EGG_NUM);
DECLARE_IDCREATE(MountBaby_eggDesc);
};

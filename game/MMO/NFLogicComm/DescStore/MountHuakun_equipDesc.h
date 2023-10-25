#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_EQUIP_NUM 64

class MountHuakun_equipDesc : public NFIDescStore
{
public:
	MountHuakun_equipDesc();
	virtual ~MountHuakun_equipDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountHuakun_equip_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_equip_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_equip_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_equip_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountHuakun_equipDesc, proto_ff_s::E_MountHuakun_equip_s, E_MountHuakun_equip, MAX_MOUNT_HUAKUN_EQUIP_NUM);
DECLARE_IDCREATE_GLOBAL(MountHuakun_equipDesc);
};

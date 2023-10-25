#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_VALUE_NUM 512

class MountHuakun_valueDesc : public NFIDescStore
{
public:
	MountHuakun_valueDesc();
	virtual ~MountHuakun_valueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountHuakun_value_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_value_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_value_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_value_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountHuakun_valueDesc, proto_ff_s::E_MountHuakun_value_s, E_MountHuakun_value, MAX_MOUNT_HUAKUN_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(MountHuakun_valueDesc);
};

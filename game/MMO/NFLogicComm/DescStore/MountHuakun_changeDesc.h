#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_CHANGE_NUM 8

class MountHuakun_changeDesc : public NFIDescStore
{
public:
	MountHuakun_changeDesc();
	virtual ~MountHuakun_changeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountHuakun_change_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_change_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_change_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_change_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountHuakun_changeDesc, proto_ff_s::E_MountHuakun_change_s, E_MountHuakun_change, MAX_MOUNT_HUAKUN_CHANGE_NUM);
DECLARE_IDCREATE(MountHuakun_changeDesc);
};
#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPSUIT_NUM 32

class MountEquipsuitDesc : public NFIDescStore
{
public:
	MountEquipsuitDesc();
	virtual ~MountEquipsuitDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEquipsuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEquipsuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEquipsuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEquipsuit_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEquipsuitDesc, proto_ff_s::E_MountEquipsuit_s, E_MountEquipsuit, MAX_MOUNT_EQUIPSUIT_NUM);
DECLARE_IDCREATE(MountEquipsuitDesc);
};

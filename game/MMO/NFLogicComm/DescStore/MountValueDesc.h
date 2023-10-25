#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_VALUE_NUM 2048

class MountValueDesc : public NFIDescStore
{
public:
	MountValueDesc();
	virtual ~MountValueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountValue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountValue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountValue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountValue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountValueDesc, proto_ff_s::E_MountValue_s, E_MountValue, MAX_MOUNT_VALUE_NUM);
DECLARE_IDCREATE_GLOBAL(MountValueDesc);
};

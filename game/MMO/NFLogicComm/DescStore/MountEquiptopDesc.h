#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_EQUIPTOP_NUM 16

class MountEquiptopDesc : public NFIDescStore
{
public:
	MountEquiptopDesc();
	virtual ~MountEquiptopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountEquiptop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountEquiptop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountEquiptop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountEquiptop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountEquiptopDesc, proto_ff_s::E_MountEquiptop_s, E_MountEquiptop, MAX_MOUNT_EQUIPTOP_NUM);
DECLARE_IDCREATE_GLOBAL(MountEquiptopDesc);
};

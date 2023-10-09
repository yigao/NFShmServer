#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mount_s.h"

#define MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM 128

class MountHuakun_advancevalueDesc : public NFIDescStore
{
public:
	MountHuakun_advancevalueDesc();
	virtual ~MountHuakun_advancevalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MountHuakun_advancevalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MountHuakun_advancevalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MountHuakun_advancevalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MountHuakun_advancevalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MountHuakun_advancevalueDesc, proto_ff_s::E_MountHuakun_advancevalue_s, E_MountHuakun_advancevalue, MAX_MOUNT_HUAKUN_ADVANCEVALUE_NUM);
DECLARE_IDCREATE(MountHuakun_advancevalueDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_POSITIONUNLOCK_NUM 16

class GodevilPositionunlockDesc : public NFIDescStore
{
public:
	GodevilPositionunlockDesc();
	virtual ~GodevilPositionunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilPositionunlock_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilPositionunlock_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilPositionunlock_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilPositionunlock_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilPositionunlockDesc, proto_ff_s::E_GodevilPositionunlock_s, E_GodevilPositionunlock, MAX_GODEVIL_POSITIONUNLOCK_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilPositionunlockDesc);
};

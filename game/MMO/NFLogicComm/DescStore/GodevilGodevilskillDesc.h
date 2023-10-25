#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILSKILL_NUM 2

class GodevilGodevilskillDesc : public NFIDescStore
{
public:
	GodevilGodevilskillDesc();
	virtual ~GodevilGodevilskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilGodevilskill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilGodevilskill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilGodevilskill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilGodevilskill_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilGodevilskillDesc, proto_ff_s::E_GodevilGodevilskill_s, E_GodevilGodevilskill, MAX_GODEVIL_GODEVILSKILL_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilGodevilskillDesc);
};

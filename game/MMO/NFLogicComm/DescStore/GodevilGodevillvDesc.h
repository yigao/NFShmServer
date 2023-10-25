#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILLV_NUM 2048

class GodevilGodevillvDesc : public NFIDescStore
{
public:
	GodevilGodevillvDesc();
	virtual ~GodevilGodevillvDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilGodevillv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilGodevillv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilGodevillv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilGodevillv_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilGodevillvDesc, proto_ff_s::E_GodevilGodevillv_s, E_GodevilGodevillv, MAX_GODEVIL_GODEVILLV_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilGodevillvDesc);
};

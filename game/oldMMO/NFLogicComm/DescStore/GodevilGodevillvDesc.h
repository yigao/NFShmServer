#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godevil_s.h"

#define MAX_GODEVIL_GODEVILLV_NUM 40

class GodevilGodevillvDesc : public NFIDescStore
{
public:
	GodevilGodevillvDesc();
	virtual ~GodevilGodevillvDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodevilGodevillv_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilGodevillv_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilGodevillv_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilGodevillv_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodevilGodevillvDesc, proto_ff_s::E_GodevilGodevillv_s, E_GodevilGodevillv, MAX_GODEVIL_GODEVILLV_NUM);
DECLARE_IDCREATE(GodevilGodevillvDesc);
};

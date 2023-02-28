#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_GodevilGodevillv_s* GetDesc(int id) const;
	proto_ff_s::E_GodevilGodevillv_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GodevilGodevillv_s, E_GodevilGodevillv, MAX_GODEVIL_GODEVILLV_NUM);
DECLARE_IDCREATE(GodevilGodevillvDesc);
};

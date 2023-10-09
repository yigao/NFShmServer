#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/godevil_s.h"

#define MAX_GODEVIL_PREPOSETASK_NUM 20

class GodevilPreposetaskDesc : public NFIDescStore
{
public:
	GodevilPreposetaskDesc();
	virtual ~GodevilPreposetaskDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GodevilPreposetask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilPreposetask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilPreposetask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilPreposetask_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GodevilPreposetaskDesc, proto_ff_s::E_GodevilPreposetask_s, E_GodevilPreposetask, MAX_GODEVIL_PREPOSETASK_NUM);
DECLARE_IDCREATE(GodevilPreposetaskDesc);
};

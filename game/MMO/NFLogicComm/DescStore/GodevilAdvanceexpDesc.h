#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_ADVANCEEXP_NUM 32

class GodevilAdvanceexpDesc : public NFIDescStore
{
public:
	GodevilAdvanceexpDesc();
	virtual ~GodevilAdvanceexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilAdvanceexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilAdvanceexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilAdvanceexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilAdvanceexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilAdvanceexpDesc, proto_ff_s::E_GodevilAdvanceexp_s, E_GodevilAdvanceexp, MAX_GODEVIL_ADVANCEEXP_NUM);
DECLARE_IDCREATE(GodevilAdvanceexpDesc);
};

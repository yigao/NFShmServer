#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_STRONGEXP_NUM 8

class GodevilStrongexpDesc : public NFIDescStore
{
public:
	GodevilStrongexpDesc();
	virtual ~GodevilStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilStrongexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilStrongexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilStrongexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilStrongexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilStrongexpDesc, proto_ff_s::E_GodevilStrongexp_s, E_GodevilStrongexp, MAX_GODEVIL_STRONGEXP_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilStrongexpDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_STRONG_NUM 1024

class GodevilStrongDesc : public NFIDescStore
{
public:
	GodevilStrongDesc();
	virtual ~GodevilStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilStrong_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilStrong_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilStrong_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilStrong_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilStrongDesc, proto_ff_s::E_GodevilStrong_s, E_GodevilStrong, MAX_GODEVIL_STRONG_NUM);
DECLARE_IDCREATE_GLOBAL(GodevilStrongDesc);
};

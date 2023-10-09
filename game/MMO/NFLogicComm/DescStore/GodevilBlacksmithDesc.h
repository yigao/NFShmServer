#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_BLACKSMITH_NUM 32

class GodevilBlacksmithDesc : public NFIDescStore
{
public:
	GodevilBlacksmithDesc();
	virtual ~GodevilBlacksmithDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GodevilBlacksmith_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GodevilBlacksmith_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GodevilBlacksmith_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GodevilBlacksmith_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GodevilBlacksmithDesc, proto_ff_s::E_GodevilBlacksmith_s, E_GodevilBlacksmith, MAX_GODEVIL_BLACKSMITH_NUM);
DECLARE_IDCREATE(GodevilBlacksmithDesc);
};

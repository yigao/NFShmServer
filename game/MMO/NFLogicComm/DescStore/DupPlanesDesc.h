#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Dup_s.h"

#define MAX_DUP_PLANES_NUM 64

class DupPlanesDesc : public NFIDescStore
{
public:
	DupPlanesDesc();
	virtual ~DupPlanesDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DupPlanes_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DupPlanes_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DupPlanes_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DupPlanes_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DupPlanesDesc, proto_ff_s::E_DupPlanes_s, E_DupPlanes, MAX_DUP_PLANES_NUM);
DECLARE_IDCREATE_GLOBAL(DupPlanesDesc);
};

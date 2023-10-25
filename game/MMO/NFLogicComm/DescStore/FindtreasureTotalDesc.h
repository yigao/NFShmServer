#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_TOTAL_NUM 64

class FindtreasureTotalDesc : public NFIDescStore
{
public:
	FindtreasureTotalDesc();
	virtual ~FindtreasureTotalDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureTotal_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureTotal_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureTotal_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureTotal_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureTotalDesc, proto_ff_s::E_FindtreasureTotal_s, E_FindtreasureTotal, MAX_FINDTREASURE_TOTAL_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureTotalDesc);
};

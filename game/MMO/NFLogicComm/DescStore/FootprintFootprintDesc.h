#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Footprint_s.h"

#define MAX_FOOTPRINT_FOOTPRINT_NUM 8

class FootprintFootprintDesc : public NFIDescStore
{
public:
	FootprintFootprintDesc();
	virtual ~FootprintFootprintDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FootprintFootprint_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FootprintFootprint_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FootprintFootprint_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FootprintFootprint_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FootprintFootprintDesc, proto_ff_s::E_FootprintFootprint_s, E_FootprintFootprint, MAX_FOOTPRINT_FOOTPRINT_NUM);
DECLARE_IDCREATE(FootprintFootprintDesc);
};

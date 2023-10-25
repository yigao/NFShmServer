#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Findtreasure_s.h"

#define MAX_FINDTREASURE_CONSTANT_NUM 2

class FindtreasureConstantDesc : public NFIDescStore
{
public:
	FindtreasureConstantDesc();
	virtual ~FindtreasureConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FindtreasureConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FindtreasureConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FindtreasureConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FindtreasureConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FindtreasureConstantDesc, proto_ff_s::E_FindtreasureConstant_s, E_FindtreasureConstant, MAX_FINDTREASURE_CONSTANT_NUM);
DECLARE_IDCREATE_GLOBAL(FindtreasureConstantDesc);
};

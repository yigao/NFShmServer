#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CONSTANT_NUM 2

class MarryConstantDesc : public NFIDescStore
{
public:
	MarryConstantDesc();
	virtual ~MarryConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryConstantDesc, proto_ff_s::E_MarryConstant_s, E_MarryConstant, MAX_MARRY_CONSTANT_NUM);
DECLARE_IDCREATE_GLOBAL(MarryConstantDesc);
};

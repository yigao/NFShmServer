#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Marry_s.h"

#define MAX_MARRY_CHILDVALUE_NUM 128

class MarryChildvalueDesc : public NFIDescStore
{
public:
	MarryChildvalueDesc();
	virtual ~MarryChildvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MarryChildvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MarryChildvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MarryChildvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MarryChildvalue_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MarryChildvalueDesc, proto_ff_s::E_MarryChildvalue_s, E_MarryChildvalue, MAX_MARRY_CHILDVALUE_NUM);
DECLARE_IDCREATE(MarryChildvalueDesc);
};

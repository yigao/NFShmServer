#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_SUBTYPE_NUM 128

class ConflateSubtypeDesc : public NFIDescStore
{
public:
	ConflateSubtypeDesc();
	virtual ~ConflateSubtypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateSubtype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateSubtype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateSubtype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateSubtype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateSubtypeDesc, proto_ff_s::E_ConflateSubtype_s, E_ConflateSubtype, MAX_CONFLATE_SUBTYPE_NUM);
DECLARE_IDCREATE_GLOBAL(ConflateSubtypeDesc);
};

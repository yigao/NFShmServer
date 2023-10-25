#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Conflate_s.h"

#define MAX_CONFLATE_GROUPTYPE_NUM 64

class ConflateGrouptypeDesc : public NFIDescStore
{
public:
	ConflateGrouptypeDesc();
	virtual ~ConflateGrouptypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ConflateGrouptype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ConflateGrouptype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ConflateGrouptype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ConflateGrouptype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ConflateGrouptypeDesc, proto_ff_s::E_ConflateGrouptype_s, E_ConflateGrouptype, MAX_CONFLATE_GROUPTYPE_NUM);
DECLARE_IDCREATE_GLOBAL(ConflateGrouptypeDesc);
};

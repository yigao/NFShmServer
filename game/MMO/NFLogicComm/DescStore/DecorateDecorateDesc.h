#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Decorate_s.h"

#define MAX_DECORATE_DECORATE_NUM 64

class DecorateDecorateDesc : public NFIDescStore
{
public:
	DecorateDecorateDesc();
	virtual ~DecorateDecorateDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_DecorateDecorate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DecorateDecorate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DecorateDecorate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DecorateDecorate_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(DecorateDecorateDesc, proto_ff_s::E_DecorateDecorate_s, E_DecorateDecorate, MAX_DECORATE_DECORATE_NUM);
DECLARE_IDCREATE_GLOBAL(DecorateDecorateDesc);
};

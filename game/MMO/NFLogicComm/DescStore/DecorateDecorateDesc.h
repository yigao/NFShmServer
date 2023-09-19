#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/decorate_s.h"

#define MAX_DECORATE_DECORATE_NUM 40

class DecorateDecorateDesc : public NFIDescStore
{
public:
	DecorateDecorateDesc();
	virtual ~DecorateDecorateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DecorateDecorate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DecorateDecorate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DecorateDecorate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DecorateDecorate_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DecorateDecorateDesc, proto_ff_s::E_DecorateDecorate_s, E_DecorateDecorate, MAX_DECORATE_DECORATE_NUM);
DECLARE_IDCREATE(DecorateDecorateDesc);
};

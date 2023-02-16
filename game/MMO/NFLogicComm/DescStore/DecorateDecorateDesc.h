#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_DecorateDecorate_s* GetDesc(int id) const;
	proto_ff_s::E_DecorateDecorate_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_DecorateDecorate_s, decoratedecorate, MAX_DECORATE_DECORATE_NUM);
DECLARE_IDCREATE(DecorateDecorateDesc);
};

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/fashion_s.h"

#define MAX_FASHION_FASHION_NUM 20

class FashionFashionDesc : public NFIDescStore
{
public:
	FashionFashionDesc();
	virtual ~FashionFashionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FashionFashion_s* GetDesc(int id) const;
	proto_ff_s::E_FashionFashion_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_FashionFashion_s, E_FashionFashion, MAX_FASHION_FASHION_NUM);
DECLARE_IDCREATE(FashionFashionDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fashion_s.h"

#define MAX_FASHION_FASHION_NUM 64

class FashionFashionDesc : public NFIDescStore
{
public:
	FashionFashionDesc();
	virtual ~FashionFashionDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_FashionFashion_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FashionFashion_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FashionFashion_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FashionFashion_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(FashionFashionDesc, proto_ff_s::E_FashionFashion_s, E_FashionFashion, MAX_FASHION_FASHION_NUM);
DECLARE_IDCREATE(FashionFashionDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALLTYPE_NUM 16

class MallMalltypeDesc : public NFIDescStore
{
public:
	MallMalltypeDesc();
	virtual ~MallMalltypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MallMalltype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MallMalltype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MallMalltype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MallMalltype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MallMalltypeDesc, proto_ff_s::E_MallMalltype_s, E_MallMalltype, MAX_MALL_MALLTYPE_NUM);
DECLARE_IDCREATE(MallMalltypeDesc);
};

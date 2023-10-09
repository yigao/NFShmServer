#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Mall_s.h"

#define MAX_MALL_MALL_NUM 512

class MallMallDesc : public NFIDescStore
{
public:
	MallMallDesc();
	virtual ~MallMallDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_MallMall_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MallMall_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MallMall_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MallMall_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(MallMallDesc, proto_ff_s::E_MallMall_s, E_MallMall, MAX_MALL_MALL_NUM);
DECLARE_IDCREATE(MallMallDesc);
};

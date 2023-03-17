#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/mall_s.h"

#define MAX_MALL_MALL_NUM 60

class MallMallDesc : public NFIDescStore
{
public:
	MallMallDesc();
	virtual ~MallMallDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_MallMall_s* GetDesc(int64_t id) const;
	proto_ff_s::E_MallMall_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_MallMall_s* GetDescByIndex(int index) const;
	proto_ff_s::E_MallMall_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(MallMallDesc, proto_ff_s::E_MallMall_s, E_MallMall, MAX_MALL_MALL_NUM);
DECLARE_IDCREATE(MallMallDesc);
};

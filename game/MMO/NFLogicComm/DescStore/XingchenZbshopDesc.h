#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_ZBSHOP_NUM 16

class XingchenZbshopDesc : public NFIDescStore
{
public:
	XingchenZbshopDesc();
	virtual ~XingchenZbshopDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenZbshop_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenZbshop_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenZbshop_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenZbshop_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenZbshopDesc, proto_ff_s::E_XingchenZbshop_s, E_XingchenZbshop, MAX_XINGCHEN_ZBSHOP_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenZbshopDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJCW_NUM 4

class XingchenXjcwDesc : public NFIDescStore
{
public:
	XingchenXjcwDesc();
	virtual ~XingchenXjcwDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXjcw_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXjcw_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXjcw_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXjcw_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXjcwDesc, proto_ff_s::E_XingchenXjcw_s, E_XingchenXjcw, MAX_XINGCHEN_XJCW_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXjcwDesc);
};

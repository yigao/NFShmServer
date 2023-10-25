#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJATT_NUM 32

class XingchenXjattDesc : public NFIDescStore
{
public:
	XingchenXjattDesc();
	virtual ~XingchenXjattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXjatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXjatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXjatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXjatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXjattDesc, proto_ff_s::E_XingchenXjatt_s, E_XingchenXjatt, MAX_XINGCHEN_XJATT_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXjattDesc);
};

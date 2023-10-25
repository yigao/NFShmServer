#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCLVATT_NUM 64

class XingchenXclvattDesc : public NFIDescStore
{
public:
	XingchenXclvattDesc();
	virtual ~XingchenXclvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXclvatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXclvatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXclvatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXclvatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXclvattDesc, proto_ff_s::E_XingchenXclvatt_s, E_XingchenXclvatt, MAX_XINGCHEN_XCLVATT_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXclvattDesc);
};

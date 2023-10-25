#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMAGATT_NUM 16

class XingchenXcmagattDesc : public NFIDescStore
{
public:
	XingchenXcmagattDesc();
	virtual ~XingchenXcmagattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcmagatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcmagatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcmagatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcmagatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcmagattDesc, proto_ff_s::E_XingchenXcmagatt_s, E_XingchenXcmagatt, MAX_XINGCHEN_XCMAGATT_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXcmagattDesc);
};

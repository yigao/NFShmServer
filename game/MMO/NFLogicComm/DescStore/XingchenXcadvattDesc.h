#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCADVATT_NUM 4

class XingchenXcadvattDesc : public NFIDescStore
{
public:
	XingchenXcadvattDesc();
	virtual ~XingchenXcadvattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcadvatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcadvatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcadvatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcadvatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcadvattDesc, proto_ff_s::E_XingchenXcadvatt_s, E_XingchenXcadvatt, MAX_XINGCHEN_XCADVATT_NUM);
DECLARE_IDCREATE(XingchenXcadvattDesc);
};

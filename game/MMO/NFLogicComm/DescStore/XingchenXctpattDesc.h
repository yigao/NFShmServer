#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPATT_NUM 16

class XingchenXctpattDesc : public NFIDescStore
{
public:
	XingchenXctpattDesc();
	virtual ~XingchenXctpattDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXctpatt_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXctpatt_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXctpatt_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXctpatt_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXctpattDesc, proto_ff_s::E_XingchenXctpatt_s, E_XingchenXctpatt, MAX_XINGCHEN_XCTPATT_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXctpattDesc);
};

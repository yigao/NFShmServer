#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPEXP_NUM 32

class XingchenXctpexpDesc : public NFIDescStore
{
public:
	XingchenXctpexpDesc();
	virtual ~XingchenXctpexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXctpexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXctpexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXctpexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXctpexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXctpexpDesc, proto_ff_s::E_XingchenXctpexp_s, E_XingchenXctpexp, MAX_XINGCHEN_XCTPEXP_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXctpexpDesc);
};

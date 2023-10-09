#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XJLVEXP_NUM 32

class XingchenXjlvexpDesc : public NFIDescStore
{
public:
	XingchenXjlvexpDesc();
	virtual ~XingchenXjlvexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXjlvexp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXjlvexp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXjlvexp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXjlvexp_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXjlvexpDesc, proto_ff_s::E_XingchenXjlvexp_s, E_XingchenXjlvexp, MAX_XINGCHEN_XJLVEXP_NUM);
DECLARE_IDCREATE(XingchenXjlvexpDesc);
};

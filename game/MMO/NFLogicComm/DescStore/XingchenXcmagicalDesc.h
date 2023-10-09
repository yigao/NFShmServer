#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMAGICAL_NUM 32

class XingchenXcmagicalDesc : public NFIDescStore
{
public:
	XingchenXcmagicalDesc();
	virtual ~XingchenXcmagicalDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcmagical_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcmagical_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcmagical_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcmagical_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcmagicalDesc, proto_ff_s::E_XingchenXcmagical_s, E_XingchenXcmagical, MAX_XINGCHEN_XCMAGICAL_NUM);
DECLARE_IDCREATE(XingchenXcmagicalDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCSTAR_NUM 16

class XingchenXcstarDesc : public NFIDescStore
{
public:
	XingchenXcstarDesc();
	virtual ~XingchenXcstarDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcstar_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcstar_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcstar_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcstar_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcstarDesc, proto_ff_s::E_XingchenXcstar_s, E_XingchenXcstar, MAX_XINGCHEN_XCSTAR_NUM);
DECLARE_IDCREATE(XingchenXcstarDesc);
};

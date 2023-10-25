#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCSETUP_NUM 32

class XingchenXcsetupDesc : public NFIDescStore
{
public:
	XingchenXcsetupDesc();
	virtual ~XingchenXcsetupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcsetup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcsetup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcsetup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcsetup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcsetupDesc, proto_ff_s::E_XingchenXcsetup_s, E_XingchenXcsetup, MAX_XINGCHEN_XCSETUP_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXcsetupDesc);
};

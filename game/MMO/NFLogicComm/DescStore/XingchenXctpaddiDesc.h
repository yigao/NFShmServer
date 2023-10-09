#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCTPADDI_NUM 128

class XingchenXctpaddiDesc : public NFIDescStore
{
public:
	XingchenXctpaddiDesc();
	virtual ~XingchenXctpaddiDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXctpaddi_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXctpaddi_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXctpaddi_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXctpaddi_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXctpaddiDesc, proto_ff_s::E_XingchenXctpaddi_s, E_XingchenXctpaddi, MAX_XINGCHEN_XCTPADDI_NUM);
DECLARE_IDCREATE(XingchenXctpaddiDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XINCHEN_NUM 64

class XingchenXinchenDesc : public NFIDescStore
{
public:
	XingchenXinchenDesc();
	virtual ~XingchenXinchenDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXinchen_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXinchen_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXinchen_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXinchen_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXinchenDesc, proto_ff_s::E_XingchenXinchen_s, E_XingchenXinchen, MAX_XINGCHEN_XINCHEN_NUM);
DECLARE_IDCREATE(XingchenXinchenDesc);
};

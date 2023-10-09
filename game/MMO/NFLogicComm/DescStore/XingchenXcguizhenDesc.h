#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCGUIZHEN_NUM 32

class XingchenXcguizhenDesc : public NFIDescStore
{
public:
	XingchenXcguizhenDesc();
	virtual ~XingchenXcguizhenDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcguizhen_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcguizhen_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcguizhen_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcguizhen_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcguizhenDesc, proto_ff_s::E_XingchenXcguizhen_s, E_XingchenXcguizhen, MAX_XINGCHEN_XCGUIZHEN_NUM);
DECLARE_IDCREATE(XingchenXcguizhenDesc);
};

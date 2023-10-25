#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XINGJUN_NUM 8

class XingchenXingjunDesc : public NFIDescStore
{
public:
	XingchenXingjunDesc();
	virtual ~XingchenXingjunDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXingjun_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXingjun_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXingjun_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXingjun_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXingjunDesc, proto_ff_s::E_XingchenXingjun_s, E_XingchenXingjun, MAX_XINGCHEN_XINGJUN_NUM);
DECLARE_IDCREATE_GLOBAL(XingchenXingjunDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_CLASSIFY_NUM 16

class XiuzhenroadClassifyDesc : public NFIDescStore
{
public:
	XiuzhenroadClassifyDesc();
	virtual ~XiuzhenroadClassifyDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenroadClassify_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenroadClassify_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenroadClassify_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenroadClassify_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenroadClassifyDesc, proto_ff_s::E_XiuzhenroadClassify_s, E_XiuzhenroadClassify, MAX_XIUZHENROAD_CLASSIFY_NUM);
DECLARE_IDCREATE(XiuzhenroadClassifyDesc);
};

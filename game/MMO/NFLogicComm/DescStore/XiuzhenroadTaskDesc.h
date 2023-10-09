#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_TASK_NUM 128

class XiuzhenroadTaskDesc : public NFIDescStore
{
public:
	XiuzhenroadTaskDesc();
	virtual ~XiuzhenroadTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XiuzhenroadTask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XiuzhenroadTask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XiuzhenroadTask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XiuzhenroadTask_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XiuzhenroadTaskDesc, proto_ff_s::E_XiuzhenroadTask_s, E_XiuzhenroadTask, MAX_XIUZHENROAD_TASK_NUM);
DECLARE_IDCREATE(XiuzhenroadTaskDesc);
};

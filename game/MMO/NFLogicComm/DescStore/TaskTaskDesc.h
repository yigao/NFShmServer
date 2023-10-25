#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Task_s.h"

#define MAX_TASK_TASK_NUM 512

class TaskTaskDesc : public NFIDescStore
{
public:
	TaskTaskDesc();
	virtual ~TaskTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TaskTask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskTask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskTask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskTask_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TaskTaskDesc, proto_ff_s::E_TaskTask_s, E_TaskTask, MAX_TASK_TASK_NUM);
DECLARE_IDCREATE_GLOBAL(TaskTaskDesc);
};

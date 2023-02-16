#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/task_s.h"

#define MAX_TASK_TASK_NUM 200

class TaskTaskDesc : public NFIDescStore
{
public:
	TaskTaskDesc();
	virtual ~TaskTaskDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskTask_s* GetDesc(int id) const;
	proto_ff_s::E_TaskTask_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskTask_s, E_TaskTask, MAX_TASK_TASK_NUM);
DECLARE_IDCREATE(TaskTaskDesc);
};

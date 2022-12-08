#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/tasktracker_s.h"

#define MAX_TASKTRACKER_TASKTRACKER_NUM 60

class TasktrackerTasktrackerDesc : public NFIDescStore
{
public:
	TasktrackerTasktrackerDesc();
	virtual ~TasktrackerTasktrackerDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::tasktrackertasktracker_s* GetDesc(int id) const;
	proto_ff_s::tasktrackertasktracker_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::tasktrackertasktracker_s, tasktrackertasktracker, MAX_TASKTRACKER_TASKTRACKER_NUM);
DECLARE_IDCREATE(TasktrackerTasktrackerDesc);
};

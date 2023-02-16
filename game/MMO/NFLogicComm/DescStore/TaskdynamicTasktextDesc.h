#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKTEXT_NUM 20

class TaskdynamicTasktextDesc : public NFIDescStore
{
public:
	TaskdynamicTasktextDesc();
	virtual ~TaskdynamicTasktextDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskdynamicTasktext_s* GetDesc(int id) const;
	proto_ff_s::E_TaskdynamicTasktext_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskdynamicTasktext_s, taskdynamictasktext, MAX_TASKDYNAMIC_TASKTEXT_NUM);
DECLARE_IDCREATE(TaskdynamicTasktextDesc);
};

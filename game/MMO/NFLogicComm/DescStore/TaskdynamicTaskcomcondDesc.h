#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKCOMCOND_NUM 20

class TaskdynamicTaskcomcondDesc : public NFIDescStore
{
public:
	TaskdynamicTaskcomcondDesc();
	virtual ~TaskdynamicTaskcomcondDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskdynamicTaskcomcond_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskdynamicTaskcomcond_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskdynamicTaskcomcond_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskdynamicTaskcomcond_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(TaskdynamicTaskcomcondDesc, proto_ff_s::E_TaskdynamicTaskcomcond_s, E_TaskdynamicTaskcomcond, MAX_TASKDYNAMIC_TASKCOMCOND_NUM);
DECLARE_IDCREATE(TaskdynamicTaskcomcondDesc);
};

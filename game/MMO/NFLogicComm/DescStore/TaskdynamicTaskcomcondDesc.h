#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::taskdynamictaskcomcond_s* GetDesc(int id) const;
	proto_ff_s::taskdynamictaskcomcond_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskdynamictaskcomcond_s, taskdynamictaskcomcond, MAX_TASKDYNAMIC_TASKCOMCOND_NUM);
DECLARE_IDCREATE(TaskdynamicTaskcomcondDesc);
};

#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKDYNAMIC_NUM 20

class TaskdynamicTaskdynamicDesc : public NFIDescStore
{
public:
	TaskdynamicTaskdynamicDesc();
	virtual ~TaskdynamicTaskdynamicDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::taskdynamictaskdynamic_s* GetDesc(int id) const;
	proto_ff_s::taskdynamictaskdynamic_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::taskdynamictaskdynamic_s, taskdynamictaskdynamic, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM);
DECLARE_IDCREATE(TaskdynamicTaskdynamicDesc);
};

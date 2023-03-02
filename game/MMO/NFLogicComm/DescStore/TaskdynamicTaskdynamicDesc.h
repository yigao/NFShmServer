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
	const proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskdynamicTaskdynamic_s, E_TaskdynamicTaskdynamic, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM);
DECLARE_IDCREATE(TaskdynamicTaskdynamicDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKDYNAMIC_NUM 32

class TaskdynamicTaskdynamicDesc : public NFIDescStore
{
public:
	TaskdynamicTaskdynamicDesc();
	virtual ~TaskdynamicTaskdynamicDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskdynamicTaskdynamic_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TaskdynamicTaskdynamicDesc, proto_ff_s::E_TaskdynamicTaskdynamic_s, E_TaskdynamicTaskdynamic, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM);
DECLARE_IDCREATE_GLOBAL(TaskdynamicTaskdynamicDesc);
};

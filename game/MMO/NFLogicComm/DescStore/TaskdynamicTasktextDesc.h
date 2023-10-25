#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKTEXT_NUM 32

class TaskdynamicTasktextDesc : public NFIDescStore
{
public:
	TaskdynamicTasktextDesc();
	virtual ~TaskdynamicTasktextDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TaskdynamicTasktext_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskdynamicTasktext_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskdynamicTasktext_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskdynamicTasktext_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TaskdynamicTasktextDesc, proto_ff_s::E_TaskdynamicTasktext_s, E_TaskdynamicTasktext, MAX_TASKDYNAMIC_TASKTEXT_NUM);
DECLARE_IDCREATE_GLOBAL(TaskdynamicTasktextDesc);
};

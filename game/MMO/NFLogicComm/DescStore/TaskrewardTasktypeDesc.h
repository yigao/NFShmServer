#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskreward_s.h"

#define MAX_TASKREWARD_TASKTYPE_NUM 4

class TaskrewardTasktypeDesc : public NFIDescStore
{
public:
	TaskrewardTasktypeDesc();
	virtual ~TaskrewardTasktypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_TaskrewardTasktype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskrewardTasktype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskrewardTasktype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskrewardTasktype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(TaskrewardTasktypeDesc, proto_ff_s::E_TaskrewardTasktype_s, E_TaskrewardTasktype, MAX_TASKREWARD_TASKTYPE_NUM);
DECLARE_IDCREATE(TaskrewardTasktypeDesc);
};

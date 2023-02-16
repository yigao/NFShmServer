#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskreward_s.h"

#define MAX_TASKREWARD_TASKTYPE_NUM 20

class TaskrewardTasktypeDesc : public NFIDescStore
{
public:
	TaskrewardTasktypeDesc();
	virtual ~TaskrewardTasktypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskrewardTasktype_s* GetDesc(int id) const;
	proto_ff_s::E_TaskrewardTasktype_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskrewardTasktype_s, E_TaskrewardTasktype, MAX_TASKREWARD_TASKTYPE_NUM);
DECLARE_IDCREATE(TaskrewardTasktypeDesc);
};

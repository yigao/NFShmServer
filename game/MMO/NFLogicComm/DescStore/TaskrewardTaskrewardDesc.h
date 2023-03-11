#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskreward_s.h"

#define MAX_TASKREWARD_TASKREWARD_NUM 5000

class TaskrewardTaskrewardDesc : public NFIDescStore
{
public:
	TaskrewardTaskrewardDesc();
	virtual ~TaskrewardTaskrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_TaskrewardTaskreward_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskrewardTaskreward_s, E_TaskrewardTaskreward, MAX_TASKREWARD_TASKREWARD_NUM);
DECLARE_IDCREATE(TaskrewardTaskrewardDesc);
};

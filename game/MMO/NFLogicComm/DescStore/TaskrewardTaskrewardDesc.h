#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/taskreward_s.h"

#define MAX_TASKREWARD_TASKREWARD_NUM 200

class TaskrewardTaskrewardDesc : public NFIDescStore
{
public:
	TaskrewardTaskrewardDesc();
	virtual ~TaskrewardTaskrewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int id) const;
	proto_ff_s::E_TaskrewardTaskreward_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_TaskrewardTaskreward_s, taskrewardtaskreward, MAX_TASKREWARD_TASKREWARD_NUM);
DECLARE_IDCREATE(TaskrewardTaskrewardDesc);
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskreward_s.h"

#define MAX_TASKREWARD_TASKTYPE_NUM 4

class TaskrewardTasktypeDesc : public NFIDescTemplate<TaskrewardTasktypeDesc, proto_ff_s::E_TaskrewardTasktype_s, EOT_CONST_TASKREWARD_TASKTYPE_DESC_ID, MAX_TASKREWARD_TASKTYPE_NUM>
{
public:
	TaskrewardTasktypeDesc();
	virtual ~TaskrewardTasktypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

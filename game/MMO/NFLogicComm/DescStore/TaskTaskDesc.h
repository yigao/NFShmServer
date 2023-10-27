#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Task_s.h"

#define MAX_TASK_TASK_NUM 512

class TaskTaskDesc : public NFIDescTemplate<TaskTaskDesc, proto_ff_s::E_TaskTask_s, EOT_CONST_TASK_TASK_DESC_ID, MAX_TASK_TASK_NUM>
{
public:
	TaskTaskDesc();
	virtual ~TaskTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

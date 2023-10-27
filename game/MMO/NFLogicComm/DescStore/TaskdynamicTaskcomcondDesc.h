#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKCOMCOND_NUM 128

class TaskdynamicTaskcomcondDesc : public NFIDescTemplate<TaskdynamicTaskcomcondDesc, proto_ff_s::E_TaskdynamicTaskcomcond_s, EOT_CONST_TASKDYNAMIC_TASKCOMCOND_DESC_ID, MAX_TASKDYNAMIC_TASKCOMCOND_NUM>
{
public:
	TaskdynamicTaskcomcondDesc();
	virtual ~TaskdynamicTaskcomcondDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

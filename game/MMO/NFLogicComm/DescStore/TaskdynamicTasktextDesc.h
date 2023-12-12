#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKTEXT_NUM 32

class TaskdynamicTasktextDesc : public NFIDescTemplate<TaskdynamicTasktextDesc, proto_ff_s::E_TaskdynamicTasktext_s, EOT_CONST_TASKDYNAMIC_TASKTEXT_DESC_ID, MAX_TASKDYNAMIC_TASKTEXT_NUM>
{
public:
	TaskdynamicTasktextDesc();
	virtual ~TaskdynamicTasktextDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

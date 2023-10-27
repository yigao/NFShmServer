#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Taskdynamic_s.h"

#define MAX_TASKDYNAMIC_TASKDYNAMIC_NUM 32

class TaskdynamicTaskdynamicDesc : public NFIDescTemplate<TaskdynamicTaskdynamicDesc, proto_ff_s::E_TaskdynamicTaskdynamic_s, EOT_CONST_TASKDYNAMIC_TASKDYNAMIC_DESC_ID, MAX_TASKDYNAMIC_TASKDYNAMIC_NUM>
{
public:
	TaskdynamicTaskdynamicDesc();
	virtual ~TaskdynamicTaskdynamicDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

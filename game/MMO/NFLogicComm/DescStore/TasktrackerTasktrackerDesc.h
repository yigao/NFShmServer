#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Tasktracker_s.h"

#define MAX_TASKTRACKER_TASKTRACKER_NUM 64

class TasktrackerTasktrackerDesc : public NFIDescTemplate<TasktrackerTasktrackerDesc, proto_ff_s::E_TasktrackerTasktracker_s, EOT_CONST_TASKTRACKER_TASKTRACKER_DESC_ID, MAX_TASKTRACKER_TASKTRACKER_NUM>
{
public:
	TasktrackerTasktrackerDesc();
	virtual ~TasktrackerTasktrackerDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

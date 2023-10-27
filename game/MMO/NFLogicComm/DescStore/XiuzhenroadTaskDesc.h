#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_TASK_NUM 128

class XiuzhenroadTaskDesc : public NFIDescTemplate<XiuzhenroadTaskDesc, proto_ff_s::E_XiuzhenroadTask_s, EOT_CONST_XIUZHENROAD_TASK_DESC_ID, MAX_XIUZHENROAD_TASK_NUM>
{
public:
	XiuzhenroadTaskDesc();
	virtual ~XiuzhenroadTaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_TASK_NUM 16

class FestivalMuban_love_taskDesc : public NFIDescTemplate<FestivalMuban_love_taskDesc, proto_ff_s::E_FestivalMuban_love_task_s, EOT_CONST_FESTIVAL_MUBAN_LOVE_TASK_DESC_ID, MAX_FESTIVAL_MUBAN_LOVE_TASK_NUM>
{
public:
	FestivalMuban_love_taskDesc();
	virtual ~FestivalMuban_love_taskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

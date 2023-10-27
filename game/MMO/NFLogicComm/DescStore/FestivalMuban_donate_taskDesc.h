#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_TASK_NUM 8

class FestivalMuban_donate_taskDesc : public NFIDescTemplate<FestivalMuban_donate_taskDesc, proto_ff_s::E_FestivalMuban_donate_task_s, EOT_CONST_FESTIVAL_MUBAN_DONATE_TASK_DESC_ID, MAX_FESTIVAL_MUBAN_DONATE_TASK_NUM>
{
public:
	FestivalMuban_donate_taskDesc();
	virtual ~FestivalMuban_donate_taskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

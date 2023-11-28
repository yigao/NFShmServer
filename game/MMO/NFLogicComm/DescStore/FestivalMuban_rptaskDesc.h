#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RPTASK_NUM 32

class FestivalMuban_rptaskDesc : public NFIDescTemplate<FestivalMuban_rptaskDesc, proto_ff_s::E_FestivalMuban_rptask_s, EOT_CONST_FESTIVAL_MUBAN_RPTASK_DESC_ID, MAX_FESTIVAL_MUBAN_RPTASK_NUM>
{
public:
	FestivalMuban_rptaskDesc();
	virtual ~FestivalMuban_rptaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

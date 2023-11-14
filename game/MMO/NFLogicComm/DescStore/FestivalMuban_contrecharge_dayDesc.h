#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_CONTRECHARGE_DAY_NUM 64

class FestivalMuban_contrecharge_dayDesc : public NFIDescTemplate<FestivalMuban_contrecharge_dayDesc, proto_ff_s::E_FestivalMuban_contrecharge_day_s, EOT_CONST_FESTIVAL_MUBAN_CONTRECHARGE_DAY_DESC_ID, MAX_FESTIVAL_MUBAN_CONTRECHARGE_DAY_NUM>
{
public:
	FestivalMuban_contrecharge_dayDesc();
	virtual ~FestivalMuban_contrecharge_dayDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

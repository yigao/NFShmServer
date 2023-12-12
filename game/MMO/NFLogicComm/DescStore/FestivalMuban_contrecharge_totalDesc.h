#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_CONTRECHARGE_TOTAL_NUM 8

class FestivalMuban_contrecharge_totalDesc : public NFIDescTemplate<FestivalMuban_contrecharge_totalDesc, proto_ff_s::E_FestivalMuban_contrecharge_total_s, EOT_CONST_FESTIVAL_MUBAN_CONTRECHARGE_TOTAL_DESC_ID, MAX_FESTIVAL_MUBAN_CONTRECHARGE_TOTAL_NUM>
{
public:
	FestivalMuban_contrecharge_totalDesc();
	virtual ~FestivalMuban_contrecharge_totalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DAILYTOTALRECHARGE_NUM 8

class FestivalMuban_dailytotalrechargeDesc : public NFIDescTemplate<FestivalMuban_dailytotalrechargeDesc, proto_ff_s::E_FestivalMuban_dailytotalrecharge_s, EOT_CONST_FESTIVAL_MUBAN_DAILYTOTALRECHARGE_DESC_ID, MAX_FESTIVAL_MUBAN_DAILYTOTALRECHARGE_NUM>
{
public:
	FestivalMuban_dailytotalrechargeDesc();
	virtual ~FestivalMuban_dailytotalrechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

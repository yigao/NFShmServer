#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_CONTRECHARGE_NUM 2

class FestivalMuban_contrechargeDesc : public NFIDescTemplate<FestivalMuban_contrechargeDesc, proto_ff_s::E_FestivalMuban_contrecharge_s, EOT_CONST_FESTIVAL_MUBAN_CONTRECHARGE_DESC_ID, MAX_FESTIVAL_MUBAN_CONTRECHARGE_NUM>
{
public:
	FestivalMuban_contrechargeDesc();
	virtual ~FestivalMuban_contrechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

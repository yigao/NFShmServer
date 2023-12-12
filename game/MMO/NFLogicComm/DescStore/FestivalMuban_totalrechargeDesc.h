#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_TOTALRECHARGE_NUM 16

class FestivalMuban_totalrechargeDesc : public NFIDescTemplate<FestivalMuban_totalrechargeDesc, proto_ff_s::E_FestivalMuban_totalrecharge_s, EOT_CONST_FESTIVAL_MUBAN_TOTALRECHARGE_DESC_ID, MAX_FESTIVAL_MUBAN_TOTALRECHARGE_NUM>
{
public:
	FestivalMuban_totalrechargeDesc();
	virtual ~FestivalMuban_totalrechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

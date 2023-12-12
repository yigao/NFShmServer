#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_RATIO_NUM 64

class FestivalMuban_rturntable_recharge_ratioDesc : public NFIDescTemplate<FestivalMuban_rturntable_recharge_ratioDesc, proto_ff_s::E_FestivalMuban_rturntable_recharge_ratio_s, EOT_CONST_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_RATIO_DESC_ID, MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_RATIO_NUM>
{
public:
	FestivalMuban_rturntable_recharge_ratioDesc();
	virtual ~FestivalMuban_rturntable_recharge_ratioDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

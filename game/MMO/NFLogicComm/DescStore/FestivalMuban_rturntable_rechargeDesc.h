#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_NUM 16

class FestivalMuban_rturntable_rechargeDesc : public NFIDescTemplate<FestivalMuban_rturntable_rechargeDesc, proto_ff_s::E_FestivalMuban_rturntable_recharge_s, EOT_CONST_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_DESC_ID, MAX_FESTIVAL_MUBAN_RTURNTABLE_RECHARGE_NUM>
{
public:
	FestivalMuban_rturntable_rechargeDesc();
	virtual ~FestivalMuban_rturntable_rechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

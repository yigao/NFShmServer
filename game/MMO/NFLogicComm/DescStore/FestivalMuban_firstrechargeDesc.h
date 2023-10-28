#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_FIRSTRECHARGE_NUM 16

class FestivalMuban_firstrechargeDesc : public NFIDescTemplate<FestivalMuban_firstrechargeDesc, proto_ff_s::E_FestivalMuban_firstrecharge_s, EOT_CONST_FESTIVAL_MUBAN_FIRSTRECHARGE_DESC_ID, MAX_FESTIVAL_MUBAN_FIRSTRECHARGE_NUM>
{
public:
	FestivalMuban_firstrechargeDesc();
	virtual ~FestivalMuban_firstrechargeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

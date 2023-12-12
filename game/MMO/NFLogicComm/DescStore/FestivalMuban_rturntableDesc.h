#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RTURNTABLE_NUM 2

class FestivalMuban_rturntableDesc : public NFIDescTemplate<FestivalMuban_rturntableDesc, proto_ff_s::E_FestivalMuban_rturntable_s, EOT_CONST_FESTIVAL_MUBAN_RTURNTABLE_DESC_ID, MAX_FESTIVAL_MUBAN_RTURNTABLE_NUM>
{
public:
	FestivalMuban_rturntableDesc();
	virtual ~FestivalMuban_rturntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

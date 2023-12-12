#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_TURNTABLE_NUM 2

class FestivalMuban_turntableDesc : public NFIDescTemplate<FestivalMuban_turntableDesc, proto_ff_s::E_FestivalMuban_turntable_s, EOT_CONST_FESTIVAL_MUBAN_TURNTABLE_DESC_ID, MAX_FESTIVAL_MUBAN_TURNTABLE_NUM>
{
public:
	FestivalMuban_turntableDesc();
	virtual ~FestivalMuban_turntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

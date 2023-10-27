#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_TURNTABLE_POOL_NUM 16

class FestivalMuban_turntable_poolDesc : public NFIDescTemplate<FestivalMuban_turntable_poolDesc, proto_ff_s::E_FestivalMuban_turntable_pool_s, EOT_CONST_FESTIVAL_MUBAN_TURNTABLE_POOL_DESC_ID, MAX_FESTIVAL_MUBAN_TURNTABLE_POOL_NUM>
{
public:
	FestivalMuban_turntable_poolDesc();
	virtual ~FestivalMuban_turntable_poolDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

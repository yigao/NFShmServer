#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_EGGSDRAW_POOL_NUM 16

class FestivalMuban_eggsdraw_poolDesc : public NFIDescTemplate<FestivalMuban_eggsdraw_poolDesc, proto_ff_s::E_FestivalMuban_eggsdraw_pool_s, EOT_CONST_FESTIVAL_MUBAN_EGGSDRAW_POOL_DESC_ID, MAX_FESTIVAL_MUBAN_EGGSDRAW_POOL_NUM>
{
public:
	FestivalMuban_eggsdraw_poolDesc();
	virtual ~FestivalMuban_eggsdraw_poolDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

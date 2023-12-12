#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_POOL_NUM 64

class FestivalMuban_drawpize_poolDesc : public NFIDescTemplate<FestivalMuban_drawpize_poolDesc, proto_ff_s::E_FestivalMuban_drawpize_pool_s, EOT_CONST_FESTIVAL_MUBAN_DRAWPIZE_POOL_DESC_ID, MAX_FESTIVAL_MUBAN_DRAWPIZE_POOL_NUM>
{
public:
	FestivalMuban_drawpize_poolDesc();
	virtual ~FestivalMuban_drawpize_poolDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

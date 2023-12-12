#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_TOTAL_NUM 64

class FestivalMuban_drawpize_totalDesc : public NFIDescTemplate<FestivalMuban_drawpize_totalDesc, proto_ff_s::E_FestivalMuban_drawpize_total_s, EOT_CONST_FESTIVAL_MUBAN_DRAWPIZE_TOTAL_DESC_ID, MAX_FESTIVAL_MUBAN_DRAWPIZE_TOTAL_NUM>
{
public:
	FestivalMuban_drawpize_totalDesc();
	virtual ~FestivalMuban_drawpize_totalDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

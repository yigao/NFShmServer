#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DRAWPIZE_NUM 4

class FestivalMuban_drawpizeDesc : public NFIDescTemplate<FestivalMuban_drawpizeDesc, proto_ff_s::E_FestivalMuban_drawpize_s, EOT_CONST_FESTIVAL_MUBAN_DRAWPIZE_DESC_ID, MAX_FESTIVAL_MUBAN_DRAWPIZE_NUM>
{
public:
	FestivalMuban_drawpizeDesc();
	virtual ~FestivalMuban_drawpizeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

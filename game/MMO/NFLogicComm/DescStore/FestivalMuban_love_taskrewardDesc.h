#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_TASKREWARD_NUM 8

class FestivalMuban_love_taskrewardDesc : public NFIDescTemplate<FestivalMuban_love_taskrewardDesc, proto_ff_s::E_FestivalMuban_love_taskreward_s, EOT_CONST_FESTIVAL_MUBAN_LOVE_TASKREWARD_DESC_ID, MAX_FESTIVAL_MUBAN_LOVE_TASKREWARD_NUM>
{
public:
	FestivalMuban_love_taskrewardDesc();
	virtual ~FestivalMuban_love_taskrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

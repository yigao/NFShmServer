#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_RANK_NUM 2

class FestivalMuban_love_rankDesc : public NFIDescTemplate<FestivalMuban_love_rankDesc, proto_ff_s::E_FestivalMuban_love_rank_s, EOT_CONST_FESTIVAL_MUBAN_LOVE_RANK_DESC_ID, MAX_FESTIVAL_MUBAN_LOVE_RANK_NUM>
{
public:
	FestivalMuban_love_rankDesc();
	virtual ~FestivalMuban_love_rankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

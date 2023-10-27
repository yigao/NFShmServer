#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_PLAY_NUM 2

class FestivalMuban_playDesc : public NFIDescTemplate<FestivalMuban_playDesc, proto_ff_s::E_FestivalMuban_play_s, EOT_CONST_FESTIVAL_MUBAN_PLAY_DESC_ID, MAX_FESTIVAL_MUBAN_PLAY_NUM>
{
public:
	FestivalMuban_playDesc();
	virtual ~FestivalMuban_playDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_CHALLENGE_NUM 2

class FestivalMuban_challengeDesc : public NFIDescTemplate<FestivalMuban_challengeDesc, proto_ff_s::E_FestivalMuban_challenge_s, EOT_CONST_FESTIVAL_MUBAN_CHALLENGE_DESC_ID, MAX_FESTIVAL_MUBAN_CHALLENGE_NUM>
{
public:
	FestivalMuban_challengeDesc();
	virtual ~FestivalMuban_challengeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

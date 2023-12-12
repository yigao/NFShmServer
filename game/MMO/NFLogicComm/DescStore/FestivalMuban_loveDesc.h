#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_NUM 8

class FestivalMuban_loveDesc : public NFIDescTemplate<FestivalMuban_loveDesc, proto_ff_s::E_FestivalMuban_love_s, EOT_CONST_FESTIVAL_MUBAN_LOVE_DESC_ID, MAX_FESTIVAL_MUBAN_LOVE_NUM>
{
public:
	FestivalMuban_loveDesc();
	virtual ~FestivalMuban_loveDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

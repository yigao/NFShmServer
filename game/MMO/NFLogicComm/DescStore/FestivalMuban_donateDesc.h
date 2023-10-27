#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_NUM 2

class FestivalMuban_donateDesc : public NFIDescTemplate<FestivalMuban_donateDesc, proto_ff_s::E_FestivalMuban_donate_s, EOT_CONST_FESTIVAL_MUBAN_DONATE_DESC_ID, MAX_FESTIVAL_MUBAN_DONATE_NUM>
{
public:
	FestivalMuban_donateDesc();
	virtual ~FestivalMuban_donateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

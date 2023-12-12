#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_SINGLE_NUM 8

class FestivalMuban_donate_singleDesc : public NFIDescTemplate<FestivalMuban_donate_singleDesc, proto_ff_s::E_FestivalMuban_donate_single_s, EOT_CONST_FESTIVAL_MUBAN_DONATE_SINGLE_DESC_ID, MAX_FESTIVAL_MUBAN_DONATE_SINGLE_NUM>
{
public:
	FestivalMuban_donate_singleDesc();
	virtual ~FestivalMuban_donate_singleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

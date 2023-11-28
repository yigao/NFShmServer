#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_FTREWARD_NUM 2

class FestivalMuban_ftrewardDesc : public NFIDescTemplate<FestivalMuban_ftrewardDesc, proto_ff_s::E_FestivalMuban_ftreward_s, EOT_CONST_FESTIVAL_MUBAN_FTREWARD_DESC_ID, MAX_FESTIVAL_MUBAN_FTREWARD_NUM>
{
public:
	FestivalMuban_ftrewardDesc();
	virtual ~FestivalMuban_ftrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

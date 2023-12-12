#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DOUBLEBOX_NUM 32

class FestivalMuban_doubleboxDesc : public NFIDescTemplate<FestivalMuban_doubleboxDesc, proto_ff_s::E_FestivalMuban_doublebox_s, EOT_CONST_FESTIVAL_MUBAN_DOUBLEBOX_DESC_ID, MAX_FESTIVAL_MUBAN_DOUBLEBOX_NUM>
{
public:
	FestivalMuban_doubleboxDesc();
	virtual ~FestivalMuban_doubleboxDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

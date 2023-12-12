#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_BOSSFRISTKILL_NUM 64

class FestivalMuban_bossfristkillDesc : public NFIDescTemplate<FestivalMuban_bossfristkillDesc, proto_ff_s::E_FestivalMuban_bossfristkill_s, EOT_CONST_FESTIVAL_MUBAN_BOSSFRISTKILL_DESC_ID, MAX_FESTIVAL_MUBAN_BOSSFRISTKILL_NUM>
{
public:
	FestivalMuban_bossfristkillDesc();
	virtual ~FestivalMuban_bossfristkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

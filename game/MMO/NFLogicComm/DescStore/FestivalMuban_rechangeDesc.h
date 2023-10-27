#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RECHANGE_NUM 16

class FestivalMuban_rechangeDesc : public NFIDescTemplate<FestivalMuban_rechangeDesc, proto_ff_s::E_FestivalMuban_rechange_s, EOT_CONST_FESTIVAL_MUBAN_RECHANGE_DESC_ID, MAX_FESTIVAL_MUBAN_RECHANGE_NUM>
{
public:
	FestivalMuban_rechangeDesc();
	virtual ~FestivalMuban_rechangeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

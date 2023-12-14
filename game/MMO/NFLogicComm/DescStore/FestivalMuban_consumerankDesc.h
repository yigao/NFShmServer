#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_CONSUMERANK_NUM 128

class FestivalMuban_consumerankDesc : public NFIDescTemplate<FestivalMuban_consumerankDesc, proto_ff_s::E_FestivalMuban_consumerank_s, EOT_CONST_FESTIVAL_MUBAN_CONSUMERANK_DESC_ID, MAX_FESTIVAL_MUBAN_CONSUMERANK_NUM>
{
public:
	FestivalMuban_consumerankDesc();
	virtual ~FestivalMuban_consumerankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
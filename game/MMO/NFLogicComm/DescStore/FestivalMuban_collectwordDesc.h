#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_COLLECTWORD_NUM 16

class FestivalMuban_collectwordDesc : public NFIDescTemplate<FestivalMuban_collectwordDesc, proto_ff_s::E_FestivalMuban_collectword_s, EOT_CONST_FESTIVAL_MUBAN_COLLECTWORD_DESC_ID, MAX_FESTIVAL_MUBAN_COLLECTWORD_NUM>
{
public:
	FestivalMuban_collectwordDesc();
	virtual ~FestivalMuban_collectwordDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

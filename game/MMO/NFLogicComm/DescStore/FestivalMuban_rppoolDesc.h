#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_RPPOOL_NUM 16

class FestivalMuban_rppoolDesc : public NFIDescTemplate<FestivalMuban_rppoolDesc, proto_ff_s::E_FestivalMuban_rppool_s, EOT_CONST_FESTIVAL_MUBAN_RPPOOL_DESC_ID, MAX_FESTIVAL_MUBAN_RPPOOL_NUM>
{
public:
	FestivalMuban_rppoolDesc();
	virtual ~FestivalMuban_rppoolDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_ZADAN_NUM 16

class FestivalMuban_zadanDesc : public NFIDescTemplate<FestivalMuban_zadanDesc, proto_ff_s::E_FestivalMuban_zadan_s, EOT_CONST_FESTIVAL_MUBAN_ZADAN_DESC_ID, MAX_FESTIVAL_MUBAN_ZADAN_NUM>
{
public:
	FestivalMuban_zadanDesc();
	virtual ~FestivalMuban_zadanDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LEIJI_NUM 16

class FestivalMuban_leijiDesc : public NFIDescTemplate<FestivalMuban_leijiDesc, proto_ff_s::E_FestivalMuban_leiji_s, EOT_CONST_FESTIVAL_MUBAN_LEIJI_DESC_ID, MAX_FESTIVAL_MUBAN_LEIJI_NUM>
{
public:
	FestivalMuban_leijiDesc();
	virtual ~FestivalMuban_leijiDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

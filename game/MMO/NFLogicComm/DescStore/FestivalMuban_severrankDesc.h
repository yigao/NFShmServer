#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SEVERRANK_NUM 128

class FestivalMuban_severrankDesc : public NFIDescTemplate<FestivalMuban_severrankDesc, proto_ff_s::E_FestivalMuban_severrank_s, EOT_CONST_FESTIVAL_MUBAN_SEVERRANK_DESC_ID, MAX_FESTIVAL_MUBAN_SEVERRANK_NUM>
{
public:
	FestivalMuban_severrankDesc();
	virtual ~FestivalMuban_severrankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

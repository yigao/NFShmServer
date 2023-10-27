#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_ONLINE_NUM 4

class FestivalMuban_onlineDesc : public NFIDescTemplate<FestivalMuban_onlineDesc, proto_ff_s::E_FestivalMuban_online_s, EOT_CONST_FESTIVAL_MUBAN_ONLINE_DESC_ID, MAX_FESTIVAL_MUBAN_ONLINE_NUM>
{
public:
	FestivalMuban_onlineDesc();
	virtual ~FestivalMuban_onlineDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

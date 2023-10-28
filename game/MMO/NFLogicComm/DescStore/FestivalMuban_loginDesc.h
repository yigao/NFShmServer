#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOGIN_NUM 8

class FestivalMuban_loginDesc : public NFIDescTemplate<FestivalMuban_loginDesc, proto_ff_s::E_FestivalMuban_login_s, EOT_CONST_FESTIVAL_MUBAN_LOGIN_DESC_ID, MAX_FESTIVAL_MUBAN_LOGIN_NUM>
{
public:
	FestivalMuban_loginDesc();
	virtual ~FestivalMuban_loginDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_SIGN_NUM 2

class FestivalMuban_signDesc : public NFIDescTemplate<FestivalMuban_signDesc, proto_ff_s::E_FestivalMuban_sign_s, EOT_CONST_FESTIVAL_MUBAN_SIGN_DESC_ID, MAX_FESTIVAL_MUBAN_SIGN_NUM>
{
public:
	FestivalMuban_signDesc();
	virtual ~FestivalMuban_signDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

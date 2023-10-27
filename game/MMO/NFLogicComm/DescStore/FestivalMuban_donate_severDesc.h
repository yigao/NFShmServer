#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_DONATE_SEVER_NUM 64

class FestivalMuban_donate_severDesc : public NFIDescTemplate<FestivalMuban_donate_severDesc, proto_ff_s::E_FestivalMuban_donate_sever_s, EOT_CONST_FESTIVAL_MUBAN_DONATE_SEVER_DESC_ID, MAX_FESTIVAL_MUBAN_DONATE_SEVER_NUM>
{
public:
	FestivalMuban_donate_severDesc();
	virtual ~FestivalMuban_donate_severDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

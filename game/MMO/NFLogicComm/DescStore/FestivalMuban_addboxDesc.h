#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_ADDBOX_NUM 32

class FestivalMuban_addboxDesc : public NFIDescTemplate<FestivalMuban_addboxDesc, proto_ff_s::E_FestivalMuban_addbox_s, EOT_CONST_FESTIVAL_MUBAN_ADDBOX_DESC_ID, MAX_FESTIVAL_MUBAN_ADDBOX_NUM>
{
public:
	FestivalMuban_addboxDesc();
	virtual ~FestivalMuban_addboxDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_REBATESTORE_NUM 2

class FestivalMuban_rebatestoreDesc : public NFIDescTemplate<FestivalMuban_rebatestoreDesc, proto_ff_s::E_FestivalMuban_rebatestore_s, EOT_CONST_FESTIVAL_MUBAN_REBATESTORE_DESC_ID, MAX_FESTIVAL_MUBAN_REBATESTORE_NUM>
{
public:
	FestivalMuban_rebatestoreDesc();
	virtual ~FestivalMuban_rebatestoreDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

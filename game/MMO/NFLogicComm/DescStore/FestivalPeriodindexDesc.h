#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_PERIODINDEX_NUM 64

class FestivalPeriodindexDesc : public NFIDescTemplate<FestivalPeriodindexDesc, proto_ff_s::E_FestivalPeriodindex_s, EOT_CONST_FESTIVAL_PERIODINDEX_DESC_ID, MAX_FESTIVAL_PERIODINDEX_NUM>
{
public:
	FestivalPeriodindexDesc();
	virtual ~FestivalPeriodindexDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

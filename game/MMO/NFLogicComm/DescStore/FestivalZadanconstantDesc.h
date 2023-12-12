#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_ZADANCONSTANT_NUM 32

class FestivalZadanconstantDesc : public NFIDescTemplate<FestivalZadanconstantDesc, proto_ff_s::E_FestivalZadanconstant_s, EOT_CONST_FESTIVAL_ZADANCONSTANT_DESC_ID, MAX_FESTIVAL_ZADANCONSTANT_NUM>
{
public:
	FestivalZadanconstantDesc();
	virtual ~FestivalZadanconstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_LOVE_RANK_DATA_NUM 8

class FestivalMuban_love_rank_dataDesc : public NFIDescTemplate<FestivalMuban_love_rank_dataDesc, proto_ff_s::E_FestivalMuban_love_rank_data_s, EOT_CONST_FESTIVAL_MUBAN_LOVE_RANK_DATA_DESC_ID, MAX_FESTIVAL_MUBAN_LOVE_RANK_DATA_NUM>
{
public:
	FestivalMuban_love_rank_dataDesc();
	virtual ~FestivalMuban_love_rank_dataDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

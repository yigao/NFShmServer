#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_STAR_NUM 256

class WaremblemStarDesc : public NFIDescTemplate<WaremblemStarDesc, proto_ff_s::E_WaremblemStar_s, EOT_CONST_WAREMBLEM_STAR_DESC_ID, MAX_WAREMBLEM_STAR_NUM>
{
public:
	WaremblemStarDesc();
	virtual ~WaremblemStarDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

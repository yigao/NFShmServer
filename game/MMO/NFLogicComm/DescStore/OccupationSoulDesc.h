#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Occupation_s.h"

#define MAX_OCCUPATION_SOUL_NUM 64

class OccupationSoulDesc : public NFIDescTemplate<OccupationSoulDesc, proto_ff_s::E_OccupationSoul_s, EOT_CONST_OCCUPATION_SOUL_DESC_ID, MAX_OCCUPATION_SOUL_NUM>
{
public:
	OccupationSoulDesc();
	virtual ~OccupationSoulDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godrelics_s.h"

#define MAX_GODRELICS_GODRELICS_NUM 16

class GodrelicsGodrelicsDesc : public NFIDescTemplate<GodrelicsGodrelicsDesc, proto_ff_s::E_GodrelicsGodrelics_s, EOT_CONST_GODRELICS_GODRELICS_DESC_ID, MAX_GODRELICS_GODRELICS_NUM>
{
public:
	GodrelicsGodrelicsDesc();
	virtual ~GodrelicsGodrelicsDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

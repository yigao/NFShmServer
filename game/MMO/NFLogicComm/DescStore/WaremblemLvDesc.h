#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_LV_NUM 512

class WaremblemLvDesc : public NFIDescTemplate<WaremblemLvDesc, proto_ff_s::E_WaremblemLv_s, EOT_CONST_WAREMBLEM_LV_DESC_ID, MAX_WAREMBLEM_LV_NUM>
{
public:
	WaremblemLvDesc();
	virtual ~WaremblemLvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

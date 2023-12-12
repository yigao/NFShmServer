#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Waremblem_s.h"

#define MAX_WAREMBLEM_WAREMBLEM_NUM 64

class WaremblemWaremblemDesc : public NFIDescTemplate<WaremblemWaremblemDesc, proto_ff_s::E_WaremblemWaremblem_s, EOT_CONST_WAREMBLEM_WAREMBLEM_DESC_ID, MAX_WAREMBLEM_WAREMBLEM_NUM>
{
public:
	WaremblemWaremblemDesc();
	virtual ~WaremblemWaremblemDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

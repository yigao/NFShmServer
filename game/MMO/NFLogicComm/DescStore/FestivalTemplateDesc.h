#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_TEMPLATE_NUM 64

class FestivalTemplateDesc : public NFIDescTemplate<FestivalTemplateDesc, proto_ff_s::E_FestivalTemplate_s, EOT_CONST_FESTIVAL_TEMPLATE_DESC_ID, MAX_FESTIVAL_TEMPLATE_NUM>
{
public:
	FestivalTemplateDesc();
	virtual ~FestivalTemplateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

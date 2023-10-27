#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LVREWARD_NUM 64

class WelfareLvrewardDesc : public NFIDescTemplate<WelfareLvrewardDesc, proto_ff_s::E_WelfareLvreward_s, EOT_CONST_WELFARE_LVREWARD_DESC_ID, MAX_WELFARE_LVREWARD_NUM>
{
public:
	WelfareLvrewardDesc();
	virtual ~WelfareLvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

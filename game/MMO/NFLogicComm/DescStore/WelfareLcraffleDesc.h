#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCRAFFLE_NUM 8

class WelfareLcraffleDesc : public NFIDescTemplate<WelfareLcraffleDesc, proto_ff_s::E_WelfareLcraffle_s, EOT_CONST_WELFARE_LCRAFFLE_DESC_ID, MAX_WELFARE_LCRAFFLE_NUM>
{
public:
	WelfareLcraffleDesc();
	virtual ~WelfareLcraffleDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

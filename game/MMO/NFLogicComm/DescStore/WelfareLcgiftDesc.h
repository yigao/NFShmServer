#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCGIFT_NUM 32

class WelfareLcgiftDesc : public NFIDescTemplate<WelfareLcgiftDesc, proto_ff_s::E_WelfareLcgift_s, EOT_CONST_WELFARE_LCGIFT_DESC_ID, MAX_WELFARE_LCGIFT_NUM>
{
public:
	WelfareLcgiftDesc();
	virtual ~WelfareLcgiftDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

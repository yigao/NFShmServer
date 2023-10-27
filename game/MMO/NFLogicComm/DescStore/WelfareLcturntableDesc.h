#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LCTURNTABLE_NUM 4

class WelfareLcturntableDesc : public NFIDescTemplate<WelfareLcturntableDesc, proto_ff_s::E_WelfareLcturntable_s, EOT_CONST_WELFARE_LCTURNTABLE_DESC_ID, MAX_WELFARE_LCTURNTABLE_NUM>
{
public:
	WelfareLcturntableDesc();
	virtual ~WelfareLcturntableDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

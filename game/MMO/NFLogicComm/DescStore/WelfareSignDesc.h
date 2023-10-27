#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_SIGN_NUM 128

class WelfareSignDesc : public NFIDescTemplate<WelfareSignDesc, proto_ff_s::E_WelfareSign_s, EOT_CONST_WELFARE_SIGN_DESC_ID, MAX_WELFARE_SIGN_NUM>
{
public:
	WelfareSignDesc();
	virtual ~WelfareSignDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

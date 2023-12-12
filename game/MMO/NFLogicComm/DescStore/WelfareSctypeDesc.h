#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_SCTYPE_NUM 8

class WelfareSctypeDesc : public NFIDescTemplate<WelfareSctypeDesc, proto_ff_s::E_WelfareSctype_s, EOT_CONST_WELFARE_SCTYPE_DESC_ID, MAX_WELFARE_SCTYPE_NUM>
{
public:
	WelfareSctypeDesc();
	virtual ~WelfareSctypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_LOGON_NUM 16

class WelfareLogonDesc : public NFIDescTemplate<WelfareLogonDesc, proto_ff_s::E_WelfareLogon_s, EOT_CONST_WELFARE_LOGON_DESC_ID, MAX_WELFARE_LOGON_NUM>
{
public:
	WelfareLogonDesc();
	virtual ~WelfareLogonDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

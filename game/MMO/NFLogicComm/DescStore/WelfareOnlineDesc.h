#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_ONLINE_NUM 8

class WelfareOnlineDesc : public NFIDescTemplate<WelfareOnlineDesc, proto_ff_s::E_WelfareOnline_s, EOT_CONST_WELFARE_ONLINE_DESC_ID, MAX_WELFARE_ONLINE_NUM>
{
public:
	WelfareOnlineDesc();
	virtual ~WelfareOnlineDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_ACCRUEREWARD_NUM 16

class WelfareAccruerewardDesc : public NFIDescTemplate<WelfareAccruerewardDesc, proto_ff_s::E_WelfareAccruereward_s, EOT_CONST_WELFARE_ACCRUEREWARD_DESC_ID, MAX_WELFARE_ACCRUEREWARD_NUM>
{
public:
	WelfareAccruerewardDesc();
	virtual ~WelfareAccruerewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

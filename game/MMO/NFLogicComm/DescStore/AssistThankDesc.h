#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_THANK_NUM 16

class AssistThankDesc : public NFIDescTemplate<AssistThankDesc, proto_ff_s::E_AssistThank_s, EOT_CONST_ASSIST_THANK_DESC_ID, MAX_ASSIST_THANK_NUM>
{
public:
	AssistThankDesc();
	virtual ~AssistThankDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

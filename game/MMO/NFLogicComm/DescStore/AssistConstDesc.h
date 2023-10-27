#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_CONST_NUM 2

class AssistConstDesc : public NFIDescTemplate<AssistConstDesc, proto_ff_s::E_AssistConst_s, EOT_CONST_ASSIST_CONST_DESC_ID, MAX_ASSIST_CONST_NUM>
{
public:
	AssistConstDesc();
	virtual ~AssistConstDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

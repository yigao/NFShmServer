#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Ai_s.h"

#define MAX_AI_AI_NUM 16

class AiAiDesc : public NFIDescTemplate<AiAiDesc, proto_ff_s::E_AiAi_s, EOT_CONST_AI_AI_DESC_ID, MAX_AI_AI_NUM>
{
public:
	AiAiDesc();
	virtual ~AiAiDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

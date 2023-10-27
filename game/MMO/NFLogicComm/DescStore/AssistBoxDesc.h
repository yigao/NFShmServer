#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Assist_s.h"

#define MAX_ASSIST_BOX_NUM 8

class AssistBoxDesc : public NFIDescTemplate<AssistBoxDesc, proto_ff_s::E_AssistBox_s, EOT_CONST_ASSIST_BOX_DESC_ID, MAX_ASSIST_BOX_NUM>
{
public:
	AssistBoxDesc();
	virtual ~AssistBoxDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

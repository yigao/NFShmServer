#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Intimacy_s.h"

#define MAX_INTIMACY_INTIMACY_NUM 16

class IntimacyIntimacyDesc : public NFIDescTemplate<IntimacyIntimacyDesc, proto_ff_s::E_IntimacyIntimacy_s, EOT_CONST_INTIMACY_INTIMACY_DESC_ID, MAX_INTIMACY_INTIMACY_NUM>
{
public:
	IntimacyIntimacyDesc();
	virtual ~IntimacyIntimacyDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

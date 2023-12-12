#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_ADVANCEEXP_NUM 32

class GodevilAdvanceexpDesc : public NFIDescTemplate<GodevilAdvanceexpDesc, proto_ff_s::E_GodevilAdvanceexp_s, EOT_CONST_GODEVIL_ADVANCEEXP_DESC_ID, MAX_GODEVIL_ADVANCEEXP_NUM>
{
public:
	GodevilAdvanceexpDesc();
	virtual ~GodevilAdvanceexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

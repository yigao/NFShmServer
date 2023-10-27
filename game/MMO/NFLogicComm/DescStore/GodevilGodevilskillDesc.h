#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILSKILL_NUM 2

class GodevilGodevilskillDesc : public NFIDescTemplate<GodevilGodevilskillDesc, proto_ff_s::E_GodevilGodevilskill_s, EOT_CONST_GODEVIL_GODEVILSKILL_DESC_ID, MAX_GODEVIL_GODEVILSKILL_NUM>
{
public:
	GodevilGodevilskillDesc();
	virtual ~GodevilGodevilskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

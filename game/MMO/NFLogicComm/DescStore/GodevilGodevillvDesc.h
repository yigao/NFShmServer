#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILLV_NUM 2048

class GodevilGodevillvDesc : public NFIDescTemplate<GodevilGodevillvDesc, proto_ff_s::E_GodevilGodevillv_s, EOT_CONST_GODEVIL_GODEVILLV_DESC_ID, MAX_GODEVIL_GODEVILLV_NUM>
{
public:
	GodevilGodevillvDesc();
	virtual ~GodevilGodevillvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

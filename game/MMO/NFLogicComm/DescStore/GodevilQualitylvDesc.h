#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_QUALITYLV_NUM 16

class GodevilQualitylvDesc : public NFIDescTemplate<GodevilQualitylvDesc, proto_ff_s::E_GodevilQualitylv_s, EOT_CONST_GODEVIL_QUALITYLV_DESC_ID, MAX_GODEVIL_QUALITYLV_NUM>
{
public:
	GodevilQualitylvDesc();
	virtual ~GodevilQualitylvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

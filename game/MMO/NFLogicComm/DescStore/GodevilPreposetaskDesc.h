#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_PREPOSETASK_NUM 16

class GodevilPreposetaskDesc : public NFIDescTemplate<GodevilPreposetaskDesc, proto_ff_s::E_GodevilPreposetask_s, EOT_CONST_GODEVIL_PREPOSETASK_DESC_ID, MAX_GODEVIL_PREPOSETASK_NUM>
{
public:
	GodevilPreposetaskDesc();
	virtual ~GodevilPreposetaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

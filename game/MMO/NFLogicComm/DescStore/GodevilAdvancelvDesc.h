#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_ADVANCELV_NUM 16

class GodevilAdvancelvDesc : public NFIDescTemplate<GodevilAdvancelvDesc, proto_ff_s::E_GodevilAdvancelv_s, EOT_CONST_GODEVIL_ADVANCELV_DESC_ID, MAX_GODEVIL_ADVANCELV_NUM>
{
public:
	GodevilAdvancelvDesc();
	virtual ~GodevilAdvancelvDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

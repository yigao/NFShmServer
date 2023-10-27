#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_STRONGEXP_NUM 8

class GodevilStrongexpDesc : public NFIDescTemplate<GodevilStrongexpDesc, proto_ff_s::E_GodevilStrongexp_s, EOT_CONST_GODEVIL_STRONGEXP_DESC_ID, MAX_GODEVIL_STRONGEXP_NUM>
{
public:
	GodevilStrongexpDesc();
	virtual ~GodevilStrongexpDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_STRONG_NUM 1024

class GodevilStrongDesc : public NFIDescTemplate<GodevilStrongDesc, proto_ff_s::E_GodevilStrong_s, EOT_CONST_GODEVIL_STRONG_DESC_ID, MAX_GODEVIL_STRONG_NUM>
{
public:
	GodevilStrongDesc();
	virtual ~GodevilStrongDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

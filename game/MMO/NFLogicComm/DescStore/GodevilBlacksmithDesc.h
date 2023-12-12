#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_BLACKSMITH_NUM 32

class GodevilBlacksmithDesc : public NFIDescTemplate<GodevilBlacksmithDesc, proto_ff_s::E_GodevilBlacksmith_s, EOT_CONST_GODEVIL_BLACKSMITH_DESC_ID, MAX_GODEVIL_BLACKSMITH_NUM>
{
public:
	GodevilBlacksmithDesc();
	virtual ~GodevilBlacksmithDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

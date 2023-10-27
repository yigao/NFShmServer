#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_GODEVILPRIVILEGE_NUM 32

class GodevilGodevilprivilegeDesc : public NFIDescTemplate<GodevilGodevilprivilegeDesc, proto_ff_s::E_GodevilGodevilprivilege_s, EOT_CONST_GODEVIL_GODEVILPRIVILEGE_DESC_ID, MAX_GODEVIL_GODEVILPRIVILEGE_NUM>
{
public:
	GodevilGodevilprivilegeDesc();
	virtual ~GodevilGodevilprivilegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

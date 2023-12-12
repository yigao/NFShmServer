#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Godevil_s.h"

#define MAX_GODEVIL_POSITIONUNLOCK_NUM 16

class GodevilPositionunlockDesc : public NFIDescTemplate<GodevilPositionunlockDesc, proto_ff_s::E_GodevilPositionunlock_s, EOT_CONST_GODEVIL_POSITIONUNLOCK_DESC_ID, MAX_GODEVIL_POSITIONUNLOCK_NUM>
{
public:
	GodevilPositionunlockDesc();
	virtual ~GodevilPositionunlockDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};

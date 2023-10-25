#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class TeamDescEx : public NFIDescStoreEx
{
public:
	TeamDescEx();
	virtual ~TeamDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(TeamDescEx)
DECLARE_IDCREATE_GLOBAL(TeamDescEx)
};

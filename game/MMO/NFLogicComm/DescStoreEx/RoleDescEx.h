#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class RoleDescEx : public NFIDescStoreEx
{
public:
	RoleDescEx();
	virtual ~RoleDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(RoleDescEx)
DECLARE_IDCREATE(RoleDescEx)
};

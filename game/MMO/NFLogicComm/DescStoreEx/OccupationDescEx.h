#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class OccupationDescEx : public NFIDescStoreEx
{
public:
	OccupationDescEx();
	virtual ~OccupationDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(OccupationDescEx)
DECLARE_IDCREATE(OccupationDescEx)
};

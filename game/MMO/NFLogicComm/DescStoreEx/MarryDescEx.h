#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class MarryDescEx : public NFIDescStoreEx
{
public:
	MarryDescEx();
	virtual ~MarryDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(MarryDescEx)
DECLARE_IDCREATE(MarryDescEx)
};

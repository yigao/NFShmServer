#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class EscortDescEx : public NFIDescStoreEx
{
public:
	EscortDescEx();
	virtual ~EscortDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(EscortDescEx)
DECLARE_IDCREATE_GLOBAL(EscortDescEx)
};
